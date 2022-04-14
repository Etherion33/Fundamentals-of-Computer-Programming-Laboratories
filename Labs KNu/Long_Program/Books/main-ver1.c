#include "stack.h"
#include <string.h>

typedef struct Genre{
    char genre_name[50];
    struct Genre *next_genre;
    struct Author *author;
} node_g;

typedef struct Author{
    char author_name[50]; //zamiast char title[50] u¿yæ buffera o dowolnej wielkosci
    char title_of_book[50];
    struct Author *next_author;
};

struct Author* Insert_Author(struct Author* nHead, char nAuthor[50],char nTitle[50])
{
    printf("Inside Insert: %s %s \n\n",nAuthor,nTitle);
    struct Author* temp = (struct Author*)malloc(sizeof(struct Author));
    strcpy(temp->author_name,nAuthor);
    strcpy(temp->title_of_book,nTitle);
    temp->next_author=NULL;
    if(nHead!=NULL) temp->next_author=nHead;
    nHead=temp;
    return nHead;
}

void Print_Authors(struct Author* nHead)
{
    printf("List of authors stored: \n");
    while(nHead!=NULL)
    {
        printf("Author: %s \n",nHead->author_name);
        printf("Title: %s \n",nHead->title_of_book);
        nHead=nHead->next_author;
    }
    printf("\n");
}

int main(int argc,const char *argv[])
{
    char * buffer = malloc(sizeof(char)*128);
    if(argc==5) {
        FILE *input_file;
        FILE *output_file;
        char line[128];
        char input_file_name[255], output_file_name[255];
        int i,j=0;
        for(i=1;i<argc;i++)
            {
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
        else
        {
                struct Author * head_a=NULL;
                struct Genre * head_g=NULL;

                char c,author[50],title[50],genre[50];
                int letters=0,semicolons=0,commas=0;
                while((c=fgetc(input_file))!=EOF)
                {
                    if(c==';') //check if character is semicolon
                    {
                        if(semicolons==0)author[letters]='\0'; //if c is semicolon for the first time, the word is author
                        if(semicolons==1)title[letters]='\0'; //if c is semicolon second time, the word is title of the book
                        semicolons++;
                        letters=0; //reset the letter counter
                    }
                    else if(semicolons==0)
                    {
                        author[letters]=c;
                        letters++;
                    }
                    else if(semicolons==1)
                    {
                        title[letters]=c;
                        letters++;
                    }
                    else if(c==',')
                    {
                        if(commas==0) genre[letters]='\0';
                        commas++;
                        letters=0;
                    }
                    else if(commas==0)
                    {
                        genre[letters]=c;
                        letters++;
                    }
                    else
                    {
                        if(c=='\n')
                        {
                            head_a = Insert_Author(head_a,author, title);
                            printf("%s ",author);
                            printf("%s ",title);
                            printf("%s ",genre);
                            printf("\n");
                            semicolons=0;
                            letters=0;
                            commas=0;

                        }
                    }
                    //printf("%c",c);
                }
                Print_Authors(head_a);
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
    else if(argc > 5){
        print_error(-5);
    }
    else if(argc < 4 && argc > 2){
        print_error(-6);
    }
    else
    {
        print_error(-7);
    }
    return 0;
}


void show_help(){
            printf("\nLists the books in the library and copy them to output file.\n");
            printf("\nusage: Library -i <filename.txt> -o <filename.txt>\n");
            printf("\n  -i\t\t Name of the input file with .txt.\n");
            printf("\n  -o\t\t Name of the output file with .txt.If it exists already, overwrite it.\n");
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

//strtok method

            /*node_a *head_a=NULL;
            node_a *current_a=NULL;*/
            /*
            int i=0;
            char * schowek[256];
            while(fgets(buffer,128,input_file)!=NULL)
            {
                char *last = strchr(buffer,',');
                schowek[i] = strtok(buffer,";,");
                printf("%s \n",schowek[i]);
                insert_genre(schowek[i]);
                while(schowek[i]!=NULL)
                {
                    printf("%s \n",schowek[i]);
                    if(last!=NULL){
                    printf("Last token: %s \n",last+1);
                    }
                    schowek[i]=strtok(NULL,";,");
                    //insert_genre(schowek[i]);
                }
                i++;

            }*/
            //print_all_genre(head_g);
            //print_all_authors(head_a);
