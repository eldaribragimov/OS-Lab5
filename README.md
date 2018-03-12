# OS-Lab5

2) Написать программу вывода сообщения на экран.

3) Написать программу ввода символов с клавиатуры и записи их в файл (в качестве аргумента при запуске программы вводится имя файла). Для чтения или записи файла использовать только функции посимвольного ввода-вывода getc(), putc(), fgetc(), fputc(). Предусмотреть выход после нажатия комбинации клавиш (например: ctrl-F). Предусмотреть контроль ошибок открытия/закрытия/чтения файла.

4) Написать программу вывода содержимого текстового файла на экран (в качестве аргумента при запуске программы передаётся имя файла, второй аргумент (N) устанавливает вывод по группам строк (по N строк) или сплошным текстом (N=0)). Для вывода очередной группы строк необходимо ожидать нажатия пользователем любой клавиши. Для чтения или записи файла использовать только функции посимвольного ввода-вывода getc(), putc(), fgetc(), fputc(). Предусмотреть контроль ошибок открытия/закрытия/чтения/записи файла.

5) Написать программу копирования одного файла в другой. В качестве параметров при вызове программы передаются имена первого и второго файлов. Для чтения или записи файла использовать только функции посимвольного ввода-вывода getc(), putc(), fgetc(), fputc(). Предусмотреть копирование прав доступа к файлу и контроль ошибок открытия/закрытия/чтения/записи файла.

6) Написать программу вывода на экран содержимого текущего и заданного первым параметром вызова программы каталогов. Предусмотреть контроль ошибок открытия/закрытия/чтения каталога.

7) Написать программу, находящую в заданном каталоге и всех его подкаталогах все файлы заданного размера. Имя каталога задаётся пользователем в качестве первого аргумента командной строки. Диапазон (min - max) размеров файлов задаётся пользователем в качестве второго и третьего аргументов командной строки. Программа выводит результаты поиска в файл (четвертый аргумент командной строки) в виде полный путь, имя файла, его размер. На консоль выводится общее число просмотренных файлов.