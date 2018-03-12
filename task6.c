#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>

int main( int argc, char* argv[], char** env ){
if (argc<=1){
printf("Ошибка : проверьте аргументы\n");
return 1;
}

DIR *dir;
struct dirent *dir1;
dir = opendir(getenv("PWD"));
if (!dir){
printf("Ошибка чтения директории\n");
return 1;
}
printf("Текущий каталог\n");
printf("\n");
while ( (dir1 = readdir(dir) ) != NULL ) {
//printf("%d - %s [%d] %d\n",dir1->d_ino,dir1->d_name,dir1->d_type,dir1->d_reclen);
printf("%s\n",dir1->d_name);
}
closedir(dir);
printf("\n");
printf("Выбранный каталог\n");
printf("\n");
DIR *dir2;
struct dirent *dir3;
dir2 = opendir(argv[1]);
if (!dir2){
printf("Ошибка чтения каталога\n");
return 1;
}
while ( (dir3 = readdir(dir2) ) != NULL ) {
//printf("%d - %s [%d] %d\n",dir3->d_ino,dir3->d_name,dir3->d_type,dir3->d_reclen);
printf("%s\n",dir3->d_name);
}
closedir(dir2);
return 0;
}
