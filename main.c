#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
void design(char purpose[40]);
void showContacts(void);
void addContact(void);
void menu_choice(void);
void authenticate(void);
void searchContact(void);
int i, j, value = 57;
char u[50], p[20], ch, user[] = "amit@gmail.com", pwd[] = "Hello";
char fname[25], sname[25], email[60], contact[50], address[100];
bool auth = false;

void design(char purpose[40])
{
    system("cls");
    system("color B");
    printf("\n \n \n \n");
    i = strlen(purpose);
    for (j = 0; j <= 36; j++)
    {
        Sleep(10);
        printf("\xDB");
    }
    for (j = 0; j <= i; j++)
    {
        Sleep(50);
        printf(" %c", purpose[j]);
    }
    for (j = 0; j <= 36; j++)
    {
        Sleep(10);
        printf("\xDB");
    }
    printf("\n");
}
void showContacts(void)
{
    design("Saved Contacts");
    FILE *fp = fopen("contacts.txt", "r");
    if (fp == NULL)
    {
        printf("failed to open contacts file");
    }
    else
    {
        while (fscanf(fp, "%s %s %s %s %s", fname, sname, email, contact, address) != EOF)
        {
            printf("-------------------------------------------------------------------------------------------------------\n");
            printf("First Name : %s\nLast Name : %s\n Email : %s\nContact : %s\nAddress : %s\n", fname, sname, email, contact, address);
            printf("-------------------------------------------------------------------------------------------------------\n");
        }
    }
    fclose(fp);
    Sleep(1000);
A:
    printf("Press y to Main Menu or n to Quit : ");
    switch (getch())
    {
    case 'y':
        menu_choice();
        break;
    case 'n':
        exit(0);
        break;
    default:
        printf("\nInvalid choice !\n");
        goto A;
        break;
    }
}
void addContact(void)
{
    FILE *fp = fopen("contacts.txt", "ab+");

    if (fp == NULL)
    {
        printf("Failed to open contacts file ");
    }
    else
    {
        design("Add New Contact");
        printf("Enter First Name :");
        scanf("%s", &fname);
        printf("Enter Last Name :");
        scanf("%s", &sname);
        printf("Enter Email :");
        scanf("%s", &email);
        printf("Enter Contact :");
        scanf("%s", &contact);
        printf("Enter Address :");
        scanf("%s", &address);
        fprintf(fp, "%s %s %s %s %s \n", fname, sname, email, contact, address);
        printf("\n\n Contact Saved Successfully !\n");
    }
    fclose(fp);
    Sleep(1000);
A:
    printf("Press y to Main Menu or n to Quit : ");
    switch (getch())
    {
    case 'y':
        menu_choice();
        break;
    case 'n':
        exit(0);
        break;
    default:
        printf("\nInvalid choice !\n");
        goto A;
        break;
    }
}
void searchContact(){
 design("Searching a Contact");
    int line=0;
    char fn[25], sn[25], c;
    printf("\n Enter First Name : ");
    scanf("%s", &fn);
    printf("\n Enter Last Name : ");
    scanf("%s", &sn);
    FILE *fp=fopen("contacts.txt", "r");
    i=0;
    if (fp == NULL)
    {
        printf("\n Error in file opening");
    }
    else
    {
        while (fscanf(fp, "%s %s %s %s %s", fname, sname, email, contact, address) != EOF)
        {
            i++;
            if (!strcmp(fn, fname) && !strcmp(sn, sname))
            {
            printf("-------------------------------------------------------------------------------------------------------\n");
            printf("First Name : %s\nLast Name : %s\nEmail : %s\nContact : %s\nAddress : %s\n", fname, sname, email, contact, address);
            printf("-------------------------------------------------------------------------------------------------------\n");
                line=i;
                break;
                
            }
        }
    }
    fclose(fp);
    if(line==0){
        printf("\n%s %s's Contact Does not Exist !\n",fn,sn);
    }
        Sleep(1000);
    A:
        printf("Press x to Search Again or y to Main Menu or q to Quit : ");
        switch (getch())
        {
        case 'x':
            searchContact();
            break;
        case 'y':
            menu_choice();
            break;
        case 'q':
            exit(0);
            break;
        default:
            printf("\nInvalid choice !\n");
            goto A;
            break;
        }
}
void deleteContact(void)
{
    int line=0;
    char fn[25], sn[25], c;
    design("Deleting a Contact");
    printf("\n Enter First Name : ");
    scanf("%s", &fn);
    printf("\n Enter Last Name : ");
    scanf("%s", &sn);
    FILE *fp, *copy;
    fp = fopen("contacts.txt", "r");
    i = 0;
    if (fp == NULL)
    {
        printf("\n Error in file opening");
    }
    else
    {
        while (fscanf(fp, "%s %s %s %s %s", fname, sname, email, contact, address) != EOF)
        {
            i++;
            if (!strcmp(fn, fname) && !strcmp(sn, sname))
            {
                line=i;
                break;
            }
        }
    }
    fclose(fp);
    if (line!=0)
    {
        // printf("\n %d\n", line);
        fp = fopen("contacts.txt", "r");
        rewind(fp);
        copy = fopen("temp.txt", "w");
        j = 0;
        c = fgetc(fp);
        while (c != EOF)
        {
            if (c == '\n')
            {
                j++;
            }
            if (j != line)
            {
                fputc(c, copy);
            }
            c = fgetc(fp);
        }
        fclose(copy);

        fclose(fp);
        remove("contacts.txt");
        rename("temp.txt", "contacts.txt");
        printf("\n%s %s's Contact Deleted Successfully\n",fn,sn);
    }
    else{
        printf("\n%s %s's Contact does not Exist!\n",fn,sn);
    }
        Sleep(1000);
    A:
        printf("Press y to Main Menu or q to Quit : ");
        switch (getch())
        {
        case 'y':
            menu_choice();
            break;
        case 'q':
            exit(0);
            break;
        default:
            printf("\nInvalid choice !\n");
            goto A;
            break;
        }
    }
    
    void menu_choice(void)
    {
        char choice;
        design("Main Menu");
        while (1)
        {
            printf("What do you want to do \n For Show Saved Contacts press 1\n For Add New Contacts press 2\n For Search A Contact Number Press 3\n For Delete Contact press 4\n  For Exit press 7 : ");
            scanf("%s", &choice);
            switch (choice)
            {
            case '1':
                showContacts();
                break;
            case '2':
                addContact();
                break;
            case '3':
                searchContact();
                break;
            case '4':
                deleteContact();
                break;
            case '7':
                exit(0);
                break;
            default:
                design("Main Menu");
                printf("Invalid choice Please enter Again\n");
                break;
            }
        }
    }
    void authenticate(void)
    {
        char purpose[] = "Authorised Person only";
        design(purpose);
        switch (value)
        {
        case 1:
            printf("\nPlease Enter a valid Username !\n");
            break;
        case 2:
            printf("\nPlease Enter a valid Password !\n");
            break;
        default:
            printf("");
            break;
        }
        if (!auth)
        {

            printf("\n\t\t\t\t UserName : ");
            scanf("%s", &u);
            printf("\n\t\t\t\t Password : ");
            for (i = 0; i < 20; i++)
            {
                ch = getch();
                if (ch != 13)
                {
                    p[i] = ch;
                    ch = '*';
                    printf("%c", ch);
                }

                else
                {
                    for (j = i; j < 20; j++)
                    {
                        p[j] = '\0';
                    }

                    break;
                }
            }
            value = strcmp(u, user);
            if (value == 0)
            {
                value = strcmp(p, pwd);
                if (value == 0)
                {
                    printf("\n \n Authentication Success");
                    Sleep(1000);
                    auth = true;
                    menu_choice();
                }
                else
                {
                    value = 2;
                    authenticate();
                }
            }
            else
            {
                value = 1;
                authenticate();
            }
        }
    }

    int main(void)
    {
        authenticate();
        // menu_choice();

        return 0;
    }