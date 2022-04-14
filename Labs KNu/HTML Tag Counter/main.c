/*********************************
* This program counts all tags from a HTML document.
* No rights reserved.
* Author : QDot
*/

#include <stdio.h>
#include <string.h>

#define MAXLEN 10     //maximum length for a tag

int get(FILE*,char*);                   //get tag from HTML file
struct node *add(struct node*,char*);   //returns & of a node or increments the count of existing
struct node *mknode();                  //make tree node : alocate memory for a node
char *mkdata(char*);                    //make data : allocate memory for data
void ptree(struct node*,FILE * output_file);               //prints a tree
int len(char*);                         //returns string length without '\0'

struct node                                        //tree node
{
  char *data;                                      //tag
  int count;                                       //tag count
  struct node *left,*right;                        //pointers to the left and right node
};

int main(int argc,char **argv)                     //main
{
  FILE *fp;                                       //file pointer
  FILE *output_file;
  char *buff=(char*)malloc(MAXLEN*sizeof(char));  //universal buffer
  int c;                                          //control integer
  struct node *root=NULL;                         //the root of a tree

  if(argc<3)                                      //check for arguments
  {
    printf("usage : %s <filename>",*argv);        //print usage
    exit(1);                                      //exit
  }

  fp=fopen(*(argv+1),"r");    //open a HTML document
  output_file=fopen(*(argv+2),"w");

  do                          //do
  {
    c=get(fp,buff);           //get tag
    if(c==1)                  //is a begining tag?
    {
      root=add(root,buff);    //add to tree
    }                         //else it is end tag (</tag>)
  }                           //do nothing
  while(c!=-1);               //while not end of file

  ptree(root,output_file);                //print a tree

  return 0;                   //return 0 : everything ok
}

int get(FILE *fp,char *buff)  //get tag from HTML file
{
  char ch;                    //control char
  int i=0;                    //just another integer for counting purposes :)

  while((ch=getc(fp))!='<'&&(ch!=EOF))  //skip chars untill it is '<' or end of file
  ;                                     //blank body : do nothing
    if((int)ch==-1)                     //if end of file
    {
      return -1;                        //exit with code -1 (EOF)
    }
  if((ch=buff[i]=getc(fp))=='/')        //if found '<' and next char is '/'
  ;                                     //blank body : do nothing
  else                                  //it is not a '/'
  {
    i++;                                //increment i : one char is already in buffer
    while((ch=buff[i++]=getc(fp))!='>'&&ch!=' ')  //fill the buffer while char is not '>' or ' ' : we don't need attributes
    ;                                             //blank body : do nothing,everything done inside of while()
    buff[i-1]='\0';                               //terminate string on i-1 position : exchange '>' and '\0'
    return 1;                                     //exit with code 1 (tag found)
  }
  return 0;                                       //not a tag,not EOF : exit with code 0(end tag found)
}

struct node *mknode()                             //alocate mem for node
{
  return (struct node*)malloc(sizeof(struct node));
}

char *mkdata(char *data)                          //alocate mem for data : returns a pointer to created data
{
  int i=0;
  char *tmp=(char*)malloc(len(data)*sizeof(char));  //pointer to data on a secret location
  for(;i<(len(data)+1);i++)                         //for i = 1 to length of data string
  tmp[i]=data[i];                                   //copy data to a secret location
  return tmp;                                       //return pointer to a secret location
}

struct node *add(struct node *tree,char *data)    //add node in tree
{
  if(tree==NULL)            //tree exists?
  {
    tree=mknode();          //no,so make a root
    tree->data=mkdata(data);//make data for a node
    tree->count=1;          //set count of a tag to 1
    tree->left=NULL;        //set pointer to left node to NULL
    tree->right=NULL;       //set pointer to right node to NULL
  }
  else                            //yes,tree already exists
    if(strcmp(tree->data,data)==0)//compare tags
      tree->count++;              //if equal,increment count
    else
      if(strcmp(tree->data,data)>0)           //compare tags : if the new tag is less than existing
        tree->left=add(tree->left,data);      //put it in a left subtree
      else
        tree->right=add(tree->right,data);    //else,it is greater,put it in a right subtree

  return tree;                                //return pointer to a created node
}

void ptree(struct node *tree, FILE* output_file)     //print tree
{
  if(tree!=NULL)                  //if tree exists
  {
    printf("%s %d \n",tree->data,tree->count);    //print a parent node
    fprintf(output_file,"%s %d \n",tree->data,tree->count);    //print a parent node
    ptree(tree->left,output_file);                            //print a left subtree
    ptree(tree->right,output_file);                           //print a right subtree
  }
}

int len(char *str)    //returns the length of string without '\0'
{
  int rv=0;
  while(*(str++)!='\0')
    rv++;
  return rv;
}
