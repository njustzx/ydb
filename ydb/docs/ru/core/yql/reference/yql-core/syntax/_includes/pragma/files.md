
{% if feature_mapreduce %}

## Работа с файлами

### File

| Тип значения | По умолчанию | Статическая /<br/>динамическая |
| --- | --- | --- |
| Два строковых аргумента — алиас и URL | — | Статическая |

Приложить файл к запросу по URL. Использовать приложенные файлы можно с помощью встроенных функций [FilePath и FileContent](../../../builtins/basic.md#filecontent). Данная `PRAGMA` является универсальной альтернативой прикладыванию файлов с использованием встроенных механизмов [веб-](../../../interfaces/web.md#attach) или [консольного](../../../interfaces/cli.md#attach) клиентов.

Сервис YQL оставляет за собой право кешировать находящиеся за URL файлы на неопределенный срок, по-этому при значимом изменении находящегося за ней содержимого настоятельно рекомендуется модифицировать URL за счет добавления/изменения незначащих параметров.

### Folder

| Тип значения | По умолчанию | Статическая /<br/>динамическая |
| --- | --- | --- |
| Два строковых аргумента — префикс и URL | — | Статическая |

Приложить набор файлов к запросу по URL. Работает аналогично добавлению множества файлов через `PRAGMA File`](#file) по прямым ссылкам на файлы с алиасами, полученными объединением префикса с именем файла через `/`.

### Library

| Тип значения | По умолчанию | Статическая /<br/>динамическая |
| --- | --- | --- |
| Один или два аргумента - имя файла и опциональный URL | — | Статическая |

Интерпретировать указанный приложенный файл как библиотеку, из которой можно делать [IMPORT](../../export_import.md). Тип синтаксиса библиотеки определяется по расширению файла:
* `.sql` для YQL диалекта SQL <span style="color: green;">(рекомендуется)</span>;
* `.yql` для [s-expressions](/docs/s_expressions).

Пример с приложенным файлом к запросу:

``` yql
PRAGMA library("a.sql");
IMPORT a SYMBOLS $x;
SELECT $x;
```

В случае указания URL библиотека скачивается с него, а не с предварительного приложенного файла, как в следующем примере:

``` yql
PRAGMA library("a.sql","https://paste.yandex-team.ru/5618566/text");
IMPORT a SYMBOLS $x;
SELECT $x;
```

При этом можно использовать подстановку текстовых параметров в URL:

``` yql
DECLARE $_ver AS STRING; -- "5618566"
PRAGMA library("a.sql","https://paste.yandex-team.ru/{$_ver}/text");
IMPORT a SYMBOLS $x;
SELECT $x;
```

{% endif %}