#include <stdio.h>
#include <termios.h>
#include <unistd.h>



int main( int argc, char* argv[] ){
if (argc<=1){
printf("Ошибка, проверьте аргументы\n");
return 1 ;
}
printf("Введите символы, чтобы закончить нажмите комбинацию ctrl-f\n");
int letter;
FILE * fo;
fo=fopen(argv[1],"w");
if (fo==NULL){
printf("Ошибка работы с файлом");
return 1;
}
while ( letter != 6) {
letter=mygetch();
if ( ( letter != 6 ))
putc(letter,fo);
putc(letter,stdout);
}
fclose(fo);
printf("\n");
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
