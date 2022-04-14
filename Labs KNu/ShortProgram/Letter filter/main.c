#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc,const char *argv[])
{
    if(argc==7) {
        FILE *input_file;
        FILE *output_file;
        char input_file_name[255], output_file_name[255],word[128];
        char letter;
        int i;
        for(i=1;i<argc;i++)
            {
                printf("%s \n",argv[i]);
                if(argv[i][0]=='-')
                    switch(argv[i][1])
                    {
                        case 'i':
                            {
                                strcpy(input_file_name,argv[i+1]);
                                break;
                            }
                        case 'o':
                            {
                                strcpy(output_file_name,argv[i+1]);
                                break;
                            }
                        case 'f':
                            {
                                letter =argv[i+1][0];
                                break;
                            }
                    }
        }
        if((input_file=fopen(input_file_name,"r"))==NULL)
        {
            print_error(-1);
        }
        else if((output_file=fopen(output_file_name,"w"))==NULL)
        {
            print_error(-2);
        }
        else if(isalpha(letter)==0)
        {
            print_error(-3);
        }
        else
        {
                while(fscanf(input_file,"%s",word)!=EOF){
                    if(word[0] == letter)
                    {
                        fprintf(output_file,"%s \n", word);
                    }
                }
                fclose(input_file);
                fclose(output_file);
        }

    }
    else if(argc==2) {
        if((strcmp(argv[1],"-h"))==0)
        {
            show_help();

        }
    }
    else if(argc > 7){
        print_error(-5);
    }
    else if(argc < 7 && argc > 2){
        print_error(-6);
    }
    else
    {
        print_error(-7);
    }
    return 0;
}


void show_help(){
            printf("\nFilters the words starting with a given letter and copy them to output file.\n");
            printf("\nusage: LETTER_FILTER -i <filename.txt> -o <filename.txt> -f <letter>\n");
            printf("\n  -i\t\t Name of the input file with .txt.\n");
            printf("\n  -o\t\t Name of the output file with .txt.If it exists already, overwrite it.\n");
            printf("\n  -f\t\t The letter of the word you want to filter.\n");
}


void print_error(int code_of_error)
{
    switch(code_of_error)
    {
    case -1:
        {
            printf("Error: There is no input file with that name. Check the name of the file you want to read and try again.");
            break;
        }
    case -2:
        {
            printf("Error: Could not create output file. Maybe you don't have privileges?");
            break;
        }
    case -3:
        {
            printf("Error: The filter must be a letter!");
            break;
        }
    case -4:
        {
            printf("Error: There is no input file with that name. Check the name of the file you want to read and try again.");
            break;
        }
    case -5:
        {
            printf("Error: Too many arguments supplied.\n");
            break;
        }
    case -6:
        {
            printf("Error: Too few arguments supplied.\n");
            break;
        }
    case -7:
        {
            printf("Error: No parameters passed. Try letter_filter -h for help.");
            break;
        }
    }
}
