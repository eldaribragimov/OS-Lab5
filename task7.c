#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main( int argc, char* argv[] ){
if (argc!=5){
printf("Ошибка : проверьте аргументы\n");
return 1;
}
printf("Выбранный каталог %s\n",argv[1]);
printf("\n");
int k=0;
int N1 = atoi(argv[2]);
int N2 = atoi(argv[3]);
DIR *dir2;
struct dirent *dir3;
struct stat buf;
FILE * fo;
dir2 = opendir(argv[1]);
if (!dir2){
printf("Ошибка чтения каталога\n");
return 0;
}
fo=fopen(argv[4],"w");
while ( (dir3 = readdir(dir2) ) != NULL ){
char* name=malloc(strlen(dir3->d_name)+strlen(argv[1])+1);
strcpy(name,argv[1]);
strcat(name,"/");
strcat(name,dir3->d_name);
stat(name,&buf);
if ((buf.st_size > N1)&&(buf.st_size<N2)){
if ((S_ISDIR(buf.st_mode)!=0)&&((strcmp(dir3->d_name,".")!=0)&&(strcmp(dir3->d_name,"..")!=0))){
printf("DIR  %s\n",name);
}
else{
printf("FILE  %s\n",dir3->d_name);
}
fputs(name,fo);
fputs(" ",fo);
fputs(dir3->d_name,fo);
fputs(" ",fo);
char size[10000];
sprintf(size,"%d",buf.st_size);
fputs(size,fo);
fputs("\n",fo);
k=k+1;
}

}
printf("\n");
printf("Count = %d\n",k);
fclose(fo);
closedir(dir2);
return 0;
}
