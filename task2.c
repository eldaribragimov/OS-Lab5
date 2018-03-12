#include <stdio.h>

int main( int argc, char* argv[] ){
int i = 1;
while (i < argc){ 
printf(argv[i]);
printf(" ");
i=i+1;
}
printf("\n");
return 0;
} 
