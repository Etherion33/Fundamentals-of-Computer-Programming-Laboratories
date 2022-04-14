// Diff.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "string.h"
#include "stdlib.h"
#pragma warning(disable:4996)
struct input
{
	char *word;
	int diffrence;
	int endl = 0;
	int word_in_the_line;
	input *next;
};




input *read_input_1(FILE *input5)
{
	char c,tempc,tempchar;
	int char_i = 0, word_id = 1, line = 1, wordinline = 1, counter1 = 0,counter2=0;
	input *head=NULL;
			c = getc(input5);
			while (c != EOF)
			{
				char buff[255];
				buff[char_i] = c;
				
				if (c== ' ' &&tempc == '\n')
				{	
					c = '\n';
					
				}
				if (c == ' ' &&tempc == ' ')
				{
					for (int i = 0; i < counter1+1; i++)
					{
						c = getc(input5);						
					}
					counter1 = 0;
					
				}
				else if (c == '\n' &&tempc == '\n')
				{
			
					for (int i = 0; i < counter2 + 1; i++)
					{
						c = getc(input5);						
					}
					counter2 = 0;

				}
				else if (c == ' ')
				{	
			
						char *wordin = strtok(buff, " ");
						input *new_word = (input*)malloc(sizeof(input));
						new_word->word = (char*)malloc(strlen(wordin) + 1);
						new_word->next = NULL;
						strcpy(new_word->word, wordin);
						new_word->endl = line;
						new_word->word_in_the_line = wordinline;
						wordinline++;
					if (!head)
					{
						head = new_word;
					}
					else {
						input* current = head;
						while (current->next) {
							current = current->next;
						}
						current->next = new_word;
					}
					if (c == '\n')
					{
						new_word->endl = line;
						line++;
						wordinline = 1;			

					}
						for (int i = 0; i < 255; i++) {
							buff[i] = 'd';

						}
					char_i = -1;
				}


				else if (c == '\n')
				{
					char *wordin = strtok(buff, "\n");
					input *new_word = (input*)malloc(sizeof(input));
					new_word->word = (char*)malloc(strlen(wordin) + 1);
					new_word->next = NULL;
					strcpy(new_word->word, wordin);
					new_word->endl = line;
					new_word->word_in_the_line = wordinline;
					wordinline++;
					if (!head)
					{
						head = new_word;
					}
					else {
						input* current = head;
						while (current->next) {
							current = current->next;
						}
						current->next = new_word;
					}
					
					
						new_word->endl = line;
						line++;
						wordinline = 1;		
						
					
					for (int i = 0; i < 255; i++) {
						buff[i] = 'd';

					}
					char_i = -1;
				
				}
				
					char_i++;
					c = getc(input5);
					if (c == ' ') {
						tempc = getc(input5);
						if (tempc != ' ')
							ungetc(tempc, input5);
						else 
						{
							while (tempc == ' ')
							{
								tempc = getc(input5);
								counter1++;
							}
							ungetc(tempc, input5);
						}
					
					}
					if (c == '\n') {
						
						tempc = getc(input5);
						if (tempc != '\n')
							ungetc(tempc, input5);
						else
						{
							while (tempc == '\n')
							{
								tempc = getc(input5);
								counter1++;
							}
							ungetc(tempc, input5);
						}
					}
				
			}
	fclose(input5);
			return head;
}
void printhead(input *head)
{
	input *current = head;
	while (current)
	{
		printf("%s ", current->word);
		current = current->next;
	}

}

void diff(input *head1, input *head2)
{
	input *current1 = head1;
	input *current2 = head2;
	
		while (current1 && current2)
		{
			if (strcmp(current1->word, current2->word) != 0)
			{
				current1->diffrence = 1;
				current2->diffrence = 1;
			}
			else
			{
				current1->diffrence = 0;
				current2->diffrence = 0;
			}
			current1 = current1->next;
			current2 = current2->next;
		}
	
}

void printdiff(input *current1, input *current2)
{
	diff(current1, current2);
	while (current1 || current2)
	{
		
		if (current1&&current1->diffrence)
		{
			printf("the diffrence begins from the word nr: %d\n", current1->word_in_the_line);
			printf("in the line nr: %d\n", current1->endl);
			while (current1&&current1->diffrence )
			{	
				printf("%s ", current1->word);
				current1 = current1->next;
				
			}
			printf("           and           ");
			while (current2&&current2->diffrence)
			{
				printf("%s ",current2->word);
				current2 = current2->next;
				
			}
			if (!current1)
				break;
			if (!current2)
				break;
			printf("\n");
		}
		current1 = current1->next;
		current2 = current2->next;
	}

}

int main(int argc,char**args)
{
	if (argc < 3) {
		printf("wrong input");
		return 0;
	}

		char *path1=args[1];
		char *path2 = args[2];

		printf("%s", path1);
		printf("%s", path2);

	input *head1=NULL;
	input *current1 = head1;
	input *head2 = NULL;
	input *current2 = head2;
	FILE *input1;
	fopen_s(&input1, path1, "r");
	head1 = read_input_1(input1);
	if (head1 == NULL)
	{
		printf("\n\nempty input\n");
		system("PAUSE");
		return 0;
	}
	FILE *input2;
	fopen_s(&input2, path2, "r");
	head2=read_input_1(input2);
	if (head2 == NULL)
	{
		printf("\n\nempty input\n");
		system("PAUSE");
		return 0;
	}
	current1 = head1;
	current2 = head2;
	printf("input 1: \n");
	printhead(current1);
	printf("\n\nInput 2: ");
	printhead(current2);
	
	for (int i = 0; i < 5; i++)
	{
		printf("\n");
	}

	printdiff(current1, current2);
	system("PAUSE");
	return 0;
}