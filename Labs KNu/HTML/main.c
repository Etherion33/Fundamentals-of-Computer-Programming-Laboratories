#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_TAG_LENGTH 32 //maximum length for a tag

int get_tag(FILE*, char*,FILE*);                            //get tag from Input HTML file
struct Tag *add_tag(struct Tag*, char*);                    //return address of a node and adds the tag to the tree
struct Attribute *add_attribute(struct Attribute*, char*);  //return address of a node and adds the attribute to the tree TODO
struct Tag *create_node();                                  //make tree node
void ptree(struct Tag*,FILE * output_file);                 //prints a tree of tags
void ptree_a(struct Attribute*,FILE * output_file);         //prints a tree of attributes
void show_help();                                           //prints help with usage of the program
void print_error(int code_of_error);                        //error handling function, prints error
void insert_space(int, FILE *);                             //inserts spaces into output file
int len(char*);                                             //return string length without '\0'
int mostFrequent(struct Tag*);                              //checks the most frequent tag


struct Tag{                                                         //tree node
    char* tag_name;                                                 //tag
    int times_used;                                                 //tag count
    struct Tag* left,*right;                                        //pointers to the left and right node
};

struct Attribute{                                                   //tree node
    char* attribute_name;                                           //attribute
    int times_used;                                                 //attribute count
    struct Attribute *left,*right;                                  //pointer to the left and right node
};
int times=0;

int main(int argc,const char *argv[])
{
        if(argc==5)
        {
            FILE *input_file;                                       //input file pointer
            FILE *output_file;                                      //output file pointer
            char input_file_name[255], output_file_name[255];       //variables for input/output file names
            int i=0;
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
            if((input_file=fopen(input_file_name,"r"))==NULL)       //check if input file is correctly opened(if it exists)
            {
                print_error(-1);                                    //printing error
            }
            else if((output_file=fopen(output_file_name,"w"))==NULL) //check if output file is correctly created
            {
                print_error(-2);                                    //printing error
            }
            else
            {
                char *buff=(char*)malloc(MAX_TAG_LENGTH*sizeof(char));  //universal buffer
                struct Tag * root=NULL;                                 //the root of a tags tree
                struct Attribute * root_a=NULL;                         //the root of a attributes tree
                int c;                                                  //control integer
                int tags_found=0,attributes_found=0,most_used=0;        //counter variables
                while(!feof(input_file)){
                        while(c!=-1)
                        {
                            c=get_tag(input_file,buff,output_file);     //get tag
                            if(c==1)                                    //if tag exists
                            {
                                root=add_tag(root,buff);                //add to tree
                                tags_found++;                           //tag counter increase
                            }
                            if(c==2)                                    //if attributes exists
                            {
                                root_a=add_attribute(root_a,buff);      //add to tree of attributes
                                attributes_found++;                     //attribute count increase
                            }
                        }
                }

                printf("Tags found: %d\n",tags_found);                  //prints the amount of tags found
                printf("Tags: \n");
                ptree(root,output_file);                                //prints a tree of tags
                most_used=mostFrequent(root);
                printf("Most used tag been used: %d time(s)\n", most_used);    //prints most used tag
                printf("Attributes found: %d\n",attributes_found);      //prints the amount of attributes found
                printf("Attributes: \n");
                ptree_a(root_a,output_file);                            //prints a tree of attributes
                fclose(input_file);                                     //closing the input file
                fclose(output_file);                                    //closing the output file
            }

    }
    else if(argc==2) {                                                  //if -h is provided show help
        if((strcmp(argv[1],"-h"))==0)
        {
            show_help();

        }
    }
    else if(argc > 5){                                                  //if too many arguments
        print_error(-5);
    }
    else if(argc < 4 && argc > 2){                                      //if too few arguments
        print_error(-6);
    }
    else                                                                //no arguments provided
    {
        print_error(-7);
    }
    return 0;
}

void insert_space(int x, FILE *output){                                 //inserts desired amount of spaces in output file
    int i;
    for(i=0;i<x;i++){
        fputs(" ",output);
    }
}


int get_tag(FILE* input_file,char* buff,FILE* output_file)              //get tag from Input HTML file
{
    char ch;                                                            //control char
    int i=0;                                                            //another counter variable

    while((ch=getc(input_file))!='<'&&(ch!=EOF)){                       //skip chars until it is '<' or end of file
        fprintf(output_file,"%c",ch);                                   //prints the content of input file to output file
        if(ch=='=')                                                     //if attribute occurred
        {
            buff[i-1]='\0';
            //printf("%s",buff);
            return 2;                                                   //exit with code 2 (attribute found)
        }
        continue;
    }
    if(ch=='<')                                                         //if beginning of the tag
    {
        insert_space(4*times,output_file);
        fprintf(output_file,"%c",ch);                                   //print '<' into output file
    }
    if((int)ch==-1)                                                     //if End Of File
    {
        return -1;
    }
    if((ch=buff[i]=getc(input_file))=='/')                              //if found '<' and the next char is '/'
    {
        fprintf(output_file,"%c",ch);
        //times--;                                                        //decrease number of cuts
    }
    else{
        fprintf(output_file,"%c",ch);
        i++;                                                            //increment i: one char is already in buffer
        while((ch=buff[i++]=getc(input_file))!='>' && ch!=' ')          //fill the buffer while char is not '>'
        {
            fprintf(output_file,"%c",ch);                               //print content between < > brackets to output file
            continue;
        }
        if(ch=='>')                                                     //if found '>'
        {
            fprintf(output_file,"%c",ch);                               //print '>' into output file
            //fputs("\n",output_file);                                    //insert break line tag into output file
            //insert_space(3*times,output_file);                          //insert spaces
        }
        if(ch==' ')                                                     //if space found
        {
            fputs(" ",output_file);                                     //insert space into output file
        }
        buff[i-1]='\0';                                                 //terminate string with '\0'
        times++;
        return 1;                                                       //exit with code 1 (tag found)

    }
    times--;
    return 0;
}

char * allocate_data(char *data)
{
    int i;
    char *temp=(char*)malloc(len(data)*sizeof(char));
    for(i=0;i<(len(data)+1);i++)
    {
        temp[i]=data[i];
    }
    return temp;
}


struct Tag * add_tag(struct Tag* tree, char* data)                      //add node in tree
{
    if(tree==NULL)                                      //tree exists ?
    {
        tree=(struct Tag*)malloc((sizeof(struct Tag)));                 //allocate memory for node
        tree->tag_name=allocate_data(data);             //make data for a node
        tree->times_used=1;                             //set count of a tag to 1
        tree->left=NULL;                                //set pointer to left node to NULL
        tree->right=NULL;                               //set pointer to right node to NULL
    }
    else{                                               //if tree already exists
        if(strcmp(tree->tag_name,data)==0)              //compare tags
        {
            tree->times_used++;                         //if already used, increment count
        }
        else{
            if(strcmp(tree->tag_name,data)>0)           //compare tags: if the new tag is less than existing
            {
                tree->left=add_tag(tree->left,data);    //put it in a left subtree
            }
            else
            {
                tree->right=add_tag(tree->right,data);  //else, it is greater, put it in a right subtree
            }
        }
    }
    return tree;                                        //return pointer to a created node
}

struct Attribute * add_attribute(struct Attribute* tree, char* data)
{
    if(tree==NULL)
    {
        tree=(struct Attribute*)malloc(sizeof(struct Attribute));
        tree->attribute_name=allocate_data(data);
        tree->times_used=1;
        tree->left=NULL;
        tree->right=NULL;
    }
    else{
        if(strcmp(tree->attribute_name,data)==0)
        {
            tree->times_used++;
        }
        else{
            if(strcmp(tree->attribute_name,data)>0)
            {
                tree->left=add_attribute(tree->left,data);
            }
            else{
                tree->right=add_attribute(tree->right,data);
            }
        }
    }
    return tree;
}

void ptree(struct Tag* tree,FILE* output_file)                                  //print tree
{
    if(tree!=NULL)                                                              //if tree exists
    {
        printf("%s: %d \n",tree->tag_name,tree->times_used);                    //print the parent node
        //fprintf(output_file,"%s: %d \n",tree->tag_name,tree->times_used);     //if desired print parent node to output file
        ptree(tree->left,output_file);                                          //print a left subtree
        ptree(tree->right,output_file);                                         //print a right subtree
    }

}
void ptree_a(struct Attribute* tree,FILE* output_file)                          //print tree
{
    if(tree!=NULL)                                                              //if tree exists
    {
        printf("In %s: %d \n",tree->attribute_name,tree->times_used);           //print the parent node
        //fprintf(output_file,"In %s: %d \n",tree->attribute_name,tree->times_used);     //if desired print parent node to output file
        ptree_a(tree->left,output_file);                                        //print a left subtree
        ptree_a(tree->right,output_file);                                       //print a right subtree
    }

}

int mostFrequent(struct Tag* node)                                              //checks the most frequent tag
{
    int max=node->times_used;
    if(node->left !=NULL)
    {
        max = fmax(max,mostFrequent(node->left));
    }
    if(node->right !=NULL)
    {
        max = fmax(max,mostFrequent(node->right));
    }
    return max;                                                                 //return how many times tag was used
}

int len(char* str)                                                              //returns the length of string without '\0'
{
    int len_of_string=0;
    while(*(str++)!='\0')
        len_of_string++;
    return len_of_string;
}


void show_help(){                                                               //shows help for the program
            printf("\nAnalyses the input file and prints formatted output.\n");
            printf("\nusage: Html -i <filename.html> -o <filename.html>\n");
            printf("\n  -i\t\t Name of the input file with .html.\n");
            printf("\n  -o\t\t Name of the output file with .html. If it exists already, overwrite it.\n");
}


void print_error(int code_of_error)                                             //basic error handling function
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
            printf("Error: No parameters passed. Try html -h for help.");
            break;
        }
    }
}

