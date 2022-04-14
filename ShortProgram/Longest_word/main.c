#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE *input_file;
	char word[128], long_word[128],short_word[128];
	int line=0,l_line=0,s_line=0,word_size=0,shortest=0,longest=0;
    if((input_file=fopen("HarryPotter.txt","r"))==NULL)
	{
		 printf("Error while opening file\n");
		 exit(1);
	}
	while (!feof(input_file))
	 {
            fscanf(input_file,"%s",word);
            word_size=strlen(word);
            shortest=word_size;
            if(shortest>word_size)
            {
                    shortest=word_size;
                    strcpy(short_word,word);
                    s_line=line;
            }
            if(longest<word_size)
            {
                    longest=word_size;
                    strcpy(long_word,word);
                    l_line=line;
            }
            line++;
    }
	fclose(input_file);
    printf("Longest word: %s Line: %d\n",long_word,l_line);
    printf("Shortest word: %s Line: %d\n",short_word,s_line);
	return 0;
}




