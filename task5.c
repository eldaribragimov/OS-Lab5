#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

int main( int argc, char* argv[] ){
if (argc!=3){
printf("Ошибка : проверьте аргументы\n");
return 1;
}
int letter;
FILE * f1;
FILE * f2;
struct stat buf;
f1=fopen(argv[1],"r");
if (f1 == NULL){
printf("Файла %s не существует\n",argv[1]);
return 1;
}
f2=fopen(argv[2],"w");
while ((letter=getc(f1)) != EOF ) {
putc(letter,f2);
}
stat(argv[1],&buf);
fclose(f2);
fclose(f1);
printf("Файл успешно скопирован\n");
if (chmod(argv[2],buf.st_mode)==0){
printf("Права доступа успешно записаны\n");
}
else{
printf("Произошла ошибка, права доступа не удалось записать\n");
}

return 0;
}
