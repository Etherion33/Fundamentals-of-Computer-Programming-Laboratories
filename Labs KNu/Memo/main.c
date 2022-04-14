#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct date_of_birth{
    int day;
    int month;
    int year;
};

struct Person{
    char firstname[128];
    char lastname[128];
    struct date_of_birth birthday;
};

void show_entries(struct Person people[],int number_of_entry)
{
    int i;
    for(i=0;i<number_of_entry;i++)
    {
                        printf("\nFirst name: ");
                        printf("%s",people[i].firstname);
                        printf("\nLast name: ");
                        printf("%s",people[i].lastname);
                        printf("\nDay of birth: ");
                        printf("%d",people[i].birthday.day);
                        printf("\nMonth of birth: ");
                        printf("%d",people[i].birthday.month);
                        printf("\nYear of birth: ");
                        printf("%d",people[i].birthday.year);
    }
}

void add_entry(struct Person people[],int number_of_entry)
{
                    printf("Add new entry ?\n");
                    printf("\nFirst name: ");
                    scanf("%s",people[number_of_entry].firstname);
                    printf("\nLast name: ");
                    scanf("%s",people[number_of_entry].lastname);
                    printf("\nDay of birth: ");
                    scanf("%d",&people[number_of_entry].birthday.day);
                    fflush(stdin);
                    printf("\nMonth of birth: ");
                    scanf("%d",&people[number_of_entry].birthday.month);
                    printf("\nYear of birth: ");
                    scanf("%d",&people[number_of_entry].birthday.year);
}

void delete_entry(struct Person people[],int number_of_entry)
{
    int entry_wanted;
    printf("\nWhich entry you want to delete ?");
    scanf("%d",&entry_wanted);
    if(entry_wanted>number_of_entry)
    {
        printf("\nThe entry you want to delete not exists");
    }
    else{
        strcpy(people[entry_wanted].firstname,"-");
        strcpy(people[entry_wanted].lastname,"-");
        people[entry_wanted].birthday.day=0;
        people[entry_wanted].birthday.month=0;
        people[entry_wanted].birthday.year=0;
    }

}

void edit_entry(struct Person people[],int number_of_entry)
{
    int entry_wanted;
    printf("\nWhich entry you want to edit ?");
    scanf("%d",&entry_wanted);
    if(entry_wanted>number_of_entry)
    {
        printf("The entry you want to edit not exists");
    }
    else{
        printf("\nFirst name: ");
        scanf("%s",people[entry_wanted].firstname);
        printf("\nLast name: ");
        scanf("%s",people[entry_wanted].lastname);
        printf("\nDay of birth: ");
        scanf("%d",&people[entry_wanted].birthday.day);
        printf("\nMonth of birth: ");
        scanf("%d",&people[entry_wanted].birthday.month);
        printf("\nYear of birth: ");
        scanf("%d",&people[entry_wanted].birthday.year);
    }

}
int main()
{
    struct Person people[10];
    int option,i;
    int number_of_entry=0;
    while(option != 0){
    printf("\nMEMO program\n");
    printf("1.Add new entry\n");
    printf("2.Print entries\n");
    printf("3.Edit entries\n");
    printf("4.Delete entries\n");
    printf("0.Quit program\n");
    printf("\nYour choice: ");
    scanf("%d", &option);
    system("CLS");
            switch(option)
            {
            case 1:
                {
                    add_entry(people,number_of_entry);
                    number_of_entry++;
                    break;
                }
            case 2:
                {
                    show_entries(people,number_of_entry);
                    break;
                }
            case 3:
                {
                    edit_entry(people,number_of_entry);
                    break;
                }
            case 4:
                {
                    delete_entry(people,number_of_entry);
                    break;
                }
            }

    }
    return 0;
}

//Write a MEMO program
//1.Add new entry
//2.Print entries
//3.Edit
//4.Delete
