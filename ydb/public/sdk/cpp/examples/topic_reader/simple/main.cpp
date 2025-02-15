#include <ydb/public/sdk/cpp/client/ydb_topic/topic.h>

#include <library/cpp/getopt/last_getopt.h>

#include <util/stream/output.h>
#include <util/system/env.h>

struct TOptions {
    TString Endpoint;
    TString Database;
    TString TopicPath;
    TString ConsumerName;
    bool CommitAfterProcessing = false;
    bool DisableClusterDiscovery = false;
    bool UseSecureConnection = false;

    TOptions(int argc, const char* argv[]) {
        NLastGetopt::TOpts opts = NLastGetopt::TOpts::Default();
        opts.AddHelpOption('h');
        opts.AddLongOption('e', "endpoint", "YDB endpoint").Required().RequiredArgument("HOST:PORT")
            .StoreResult(&Endpoint);
        opts.AddLongOption('d', "database", "YDB database name").DefaultValue("/Root").RequiredArgument("PATH")
            .StoreResult(&Database);
        opts.AddLongOption('t', "topic-path", "Topic path for reading").Required().RequiredArgument("PATH")
            .StoreResult(&TopicPath);
        opts.AddLongOption('c', "consumer-name", "Consumer name").Required().RequiredArgument("CONSUMER")
            .StoreResult(&ConsumerName);
        opts.AddLongOption("commit-after-processing", "Commit data after processing")
            .SetFlag(&CommitAfterProcessing).NoArgument();
        opts.AddLongOption("secure-connection", "Use secure connection")
            .SetFlag(&UseSecureConnection).NoArgument();
        opts.SetFreeArgsNum(0);

        NLastGetopt::TOptsParseResult res(&opts, argc, argv);
    }
};

std::shared_ptr<NYdb::NTopic::IReadSession> ReadSession;

void StopHandler(int) {
    Cerr << "Stopping session" << Endl;
    if (ReadSession) {
        ReadSession->Close(TDuration::Seconds(3));
    } else {
        exit(1);
    }
}

int main(int argc, const char* argv[]) {
    signal(SIGINT, &StopHandler);
    signal(SIGTERM, &StopHandler);

    TOptions opts(argc, argv);

    // Create driver instance.
    auto driverConfig = NYdb::TDriverConfig()
        .SetNetworkThreadsNum(2)
        .SetEndpoint(opts.Endpoint)
        .SetDatabase(opts.Database)
        .SetAuthToken(GetEnv("YDB_TOKEN"))
        .SetLog(CreateLogBackend("cerr"));

    if (opts.UseSecureConnection) {
        driverConfig.UseSecureConnection();
    }

    NYdb::TDriver driver(driverConfig);

    // Create topic client.
    NYdb::NTopic::TTopicClient topicClient(driver);

    // [BEGIN Create read session]
    // Create read session.
    NYdb::NTopic::TReadSessionSettings settings;
    settings
        .ConsumerName(opts.ConsumerName)
        .AppendTopics(opts.TopicPath);

    // auto handlers = TEventHandlers::SimpleDataHandlers();

    // settings.SetEventHandlers(handlers);

    // settings.SetSimpleDataHandlers(
    settings.EventHandlers_.SimpleDataHandlers(
            [](NYdb::NTopic::TReadSessionEvent::TDataReceivedEvent& event) {
            Cerr << "Data event " << DebugString(event);
        }, opts.CommitAfterProcessing);

    ReadSession = topicClient.CreateReadSession(settings);
    // [END Create read session]

    Cerr << "Session was created" << Endl;

    // Wait SessionClosed event.
    ReadSession->GetEvent(/*block = */true);

    // Stop the driver.
    driver.Stop();
}
