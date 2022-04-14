#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[])
{
    if(argc>=2) {
        printf("Argument supplied is %s, %s, %s, %s, %s, %s\n",argv[1],argv[2],argv[3],argv[4],argv[5],argv[6]);
        if(strcmp("-i",argv[1])==0) {
            FILE *input_file;
            FILE *output_file;
            char line[128]="",text[100];
            int count=0;
            if((input_file=fopen(argv[2],"r"))==NULL){
                 printf("There is no input file named %s",argv[2]);
            }
            else if((output_file=fopen(argv[4],"a"))==NULL)
            {
                 printf("Error: Could not open output file.");
            }
            else{
                //while(fgets(line,255,input_file) != NULL)
                while(fscanf(input_file,"%s",line)!=EOF)
                {
                    if(strncmp(line,argv[6],1)==0){
                    fputs(line,output_file);
                    fputs("\n",output_file);
                    fclose(output_file);
                    printf("%s\n",line);
                    }
                }
            }
        }
    }
    else if(argc<2) {
        printf("No arguments were passed");
    }
    else if(argc > 6){
        printf("Too many arguments supplied.\n");
    }
    else printf("Wrong value of argument");
    return 0;
}
