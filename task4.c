#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <stdlib.h>


int main( int argc, char* argv[] ){
if (argc<=2){
printf("Ошибка : проверьте аргументы\n");
return 1;
}
int letter;
FILE * fo;
fo=fopen(argv[1],"r");
if (fo==NULL){
printf("Указанный файл не существует");
return 1;
}
int i=1;
int N=atoi(argv[2]);
while ((letter=getc(fo)) != EOF ) {
putc(letter,stdout);
if (letter== 10){
i=i+1;
}
if (N==0){
i=-1;
}
if (i>N){
while (mygetch()== EOF ){;}
i=1;
}
}
fclose(fo);
return 0;
}

int mygetch(){
struct termios oldt,
newt;
int ch;
tcgetattr( STDIN_FILENO, &oldt);
newt=oldt;
newt.c_lflag &= ~ ( ICANON | ECHO );
tcsetattr( STDIN_FILENO, TCSANOW, &newt );
ch=getc(stdin);
tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
return ch;
}
