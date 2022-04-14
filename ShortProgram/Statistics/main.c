#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if(argc>=2) {
        printf("Argument supplied is %s, %s, %s, %s\n",argv[1],argv[2],argv[3],argv[4]);
        if(strcmp("-i",argv[1])==0) {
            FILE *input_file;
            char buff[255],text[100];
            input_file=fopen(argv[2],"r");
            while(fscanf(input_file,"%s",buff) != EOF)
            {
                printf("%s\n",buff);
            }
        }
    }
    if(argc<2) {
        printf("No arguments were passed");
    }
    else if(argc > 5){
        printf("Too many arguments supplied.\n");
    }
    else printf("Wrong value of argument");
    return 0;
}
