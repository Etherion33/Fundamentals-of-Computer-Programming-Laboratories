#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main(int argc, char *argv[])
{
    if(argc==7) {
        FILE *input_file;
        FILE *output_file;
        char input_file_name[255], output_file_name[255],line[128];
        char letter;
        if(((strcmp(argv[1],"-i"))==0)&&((strcmp(argv[3],"-o"))==0)&&((strcmp(argv[5],"-f"))==0))
        {
            strcpy(input_file_name,argv[2]);
            strcpy(output_file_name,argv[4]);
            letter=argv[6][0];
        }
        else if(((strcmp(argv[1],"-i"))==0)&&((strcmp(argv[3],"-f"))==0)&&((strcmp(argv[5],"-o"))==0))
        {
            strcpy(input_file_name,argv[2]);
            strcpy(output_file_name,argv[6]);
            letter=argv[4][0];
        }
        else if(((strcmp(argv[1],"-o"))==0)&&((strcmp(argv[3],"-i"))==0)&&((strcmp(argv[5],"-f"))==0))
        {
            strcpy(input_file_name,argv[4]);
            strcpy(output_file_name,argv[2]);
            letter=argv[6][0];
        }
        else if(((strcmp(argv[1],"-o"))==0)&&((strcmp(argv[3],"-f"))==0)&&((strcmp(argv[5],"-i"))==0))
        {
            strcpy(input_file_name,argv[6]);
            strcpy(output_file_name,argv[2]);
            letter=argv[4][0];
        }
        else if(((strcmp(argv[1],"-f"))==0)&&((strcmp(argv[3],"-o"))==0)&&((strcmp(argv[5],"-i"))==0))
        {
            strcpy(input_file_name,argv[6]);
            strcpy(output_file_name,argv[4]);
            letter=argv[2][0];
        }
        else if(((strcmp(argv[1],"-f"))==0)&&((strcmp(argv[3],"-i"))==0)&&((strcmp(argv[5],"-o"))==0))
        {
            strcpy(input_file_name,argv[4]);
            strcpy(output_file_name,argv[6]);
            letter=argv[2][0];
        }
        if((input_file=fopen(input_file_name,"r"))==NULL)
        {
                 printf("There is no file named %s to read.",input_file_name);
                 exit -1;
        }
        else if((output_file=fopen(output_file_name,"w"))==NULL)
        {
                 printf("Error: Could not open output file.");
                 exit -2;
        }
        else if(isalpha(letter)==0){
                printf("Error: The filter must be a letter!");
        }
        else
        {
                while(fscanf(input_file,"%s",line)!=EOF){
                    if(line[0] == letter)
                    {
                        fprintf(output_file,"%s \n", line);
                    }
                }
                fclose(input_file);
                fclose(output_file);
        }

    }
    else if(argc==2) {
        if((strcmp(argv[1],"-h"))==0)
        {
            printf("\nFilters the words starting with a given letter and copy them to output file.\n");
            printf("\nusage: LETTER_FILTER -i <filename.txt> -o <filename.txt> -f <letter>\n");
            printf("\n  -i\t\t Name of the input file with .txt.\n");
            printf("\n  -o\t\t Name of the output file with .txt.If it exists already, overwrite it.\n");
            printf("\n  -f\t\t The letter of the word you want to filter.");

        }
    }
    else if(argc > 7){
        printf("Too many arguments supplied.\n");
    }
    else if(argc < 7 && argc > 2){
        printf("Too few arguments supplied.\n");
    }
    else printf("No parameters passed");
    return 0;
}
