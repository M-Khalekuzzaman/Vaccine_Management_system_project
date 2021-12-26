#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
struct personInfo
{

    char name[25];
    int idNo,age,bp,tem,phoneNumber,password;
    char userName[10];
    char gender[10];
    char profession[20];
    char peraddress[20];
    char vacName[20];
    int n;

};
int Gender(int x)
{
    switch(x)
    {
    case 1 :
        return "Male";
        break;
    case 2 :
        return "Female";
        break;
    default :
        return "Others";

    }
}
mainMenu()
{
    printf("\n\t\t\t\t ****** VACCINE MANAGEMENT SYSTEM ******\t\t\t\n");
    printf("\t\t\t\t       ---------------------------\n");
    printf("\n\t\t\t\t\t\t\t\t\t\t\tPowered By :- @KhaleKuzzaman\n");
    printf(" 1. Vaccine Registration\n");
    printf(" 2. View Vaccine Data\n");
    printf(" 3. Vaccine Login\n");
    printf(" 4. Search\n");
    printf(" 5. Exit\n");
}
int no_of_person;
registrationPage()
{
    FILE *file;
    file = fopen("dataStoreFile.txt","w");
    if(file == NULL)
    {
        printf("Your file does not create successfully\n");
    }
    else
    {
        printf("\n\t\t\t\t ****** VACCINE MANAGEMENT SYSTEM ******\t\t\t\n");
        printf("\t\t\t\t       ---------------------------\n");
        printf("\n\t\t\t\t\t\t\t\t\t\t\tPowered By :- @KhaleKuzzaman\n");
        printf("\n\t\t\t\t  ******* WELCOME TO REGISTRATION PAGE *******\n");
        printf("\n\n\t\t\t      ---------------------------------------------------");
        printf("\n\t\t\t\t        Enter The Person Details\n");
        printf("\t\t\t     ----------------------------------------------------");

        printf("\n\n Enter number of student vaccine registration : ");
        scanf("%d",&no_of_person);
        struct personInfo person[no_of_person];
        for(int i = 0 ; i< no_of_person ; i++)
        {
            printf("\nEnter your name :- ");
            fflush(stdin);
            gets(person[i].name);
            printf("Enter your user name :- ");
            scanf("%s",&person[i].userName);
            printf("Enter your citizenship no :- ");
            scanf("%d",&person[i].idNo);
            printf("Enter your Password :-");
            scanf("%d",&person[i].password);
            printf("Enter your gender (Press 1 -> For Male, Press 2 -> For Female , Press 3 -> For Others) :- ");
            scanf("%d",&person[i].n);
            printf("Enter your age :- ");
            scanf("%d",&person[i].age);
            printf("Enter your profession :- ");
            scanf("%s",&person[i].profession);
            printf("Enter your B.P :- ");
            scanf("%d",&person[i].bp);
            printf("Enter your Body temperature :- ");
            scanf("%d",&person[i].tem);
            printf("Enter your permanent address :- ");
            scanf("%s",&person[i].peraddress);
            printf("Enter your Mobile number : - ");
            scanf("%d",&person[i].phoneNumber);
            printf("Enter the vaccine injected :- ");
            scanf("%s",&person[i].vacName);
            fwrite(&person[i],sizeof(person[i]),1,file);

        }
        fclose(file);
        printf("\nPress any key to continue......................\n");
        getch();
        system("CLS");
        mainMenu();
        printf("\nEnter your choice option is : ");
    }

}
loginPage()
{
    FILE *file;
    file = fopen("dataStoreFile.txt","r");
    if(file == NULL)
    {
        printf("Your file does not create successfully\n");
    }
    else
    {
        printf("\n\t\t\t\t ****** VACCINE MANAGEMENT SYSTEM ******\t\t\t\n");
        printf("\t\t\t\t       ---------------------------\n");
        printf("\n\t\t\t\t\t\t\t\t\t\t\tPowered By :- @KhaleKuzzaman\n");
        printf("\n\t\t\t\t  ******* WELCOME TO LOGIN PAGE *******\n");
        printf("\n\n\t\t\t ----------------------------------------------------");
        printf("\n\t\t\t\t     Enter User name and Password\n");
        printf("\t\t\t ----------------------------------------------------\n");

        char username[10];
        int pass;
        printf("\n User name :- ");
        scanf("%s",&username);
        printf(" Password :- ");
        scanf("%d",&pass);

        struct personInfo person;
        while(fread(&person,sizeof(person),1,file))
        {
            if(strcmp(username,person.userName) == 0 && pass == person.password)
            {
                printf("Congratulation ........!!!! Your Login system");
                system("CLS");
                vaccineData();
                break;
            }
            else
            {
                printf("\n\n\t\t\t Please !!!!!.......... Enter your correct User-name and Password ");
                break;
            }

        }

    }
    fclose(file);


}
vaccineData()
{
    FILE *file;
    file = fopen("dataStoreFile.txt","r");
    char ch;
    if(file == NULL)
    {
        printf("Your file does not create successfully\n");
    }
    else
    {
        printf("\n\t\t\t\t ****** VACCINE MANAGEMENT SYSTEM ******\t\t\t\n");
        printf("\t\t\t\t       ---------------------------\n");
        printf("\n\t\t\t\t\t\t\t\t\t\t\tPowered By :- @KhaleKuzzaman\n");
        printf("\n\t\t\t\t  ******* Your Vaccinated Data Details *******\n\n\n");

        struct personInfo person;
        while(fread(&person,sizeof(person),1,file))
        {
            printf("Name : %s\n",person.name);
            printf("Citizenship No : %d\n",person.idNo);
            printf("Gender : %s\n",Gender(person.n));
            printf("Age : %d\n",person.age);
            printf("Profession : %s\n",person.profession);
            printf("B.P : %d\n",person.bp);
            printf("Body Temperature : %d\n",person.tem);
            printf("Permanante  Address : %s\n",person.peraddress);
            printf("Phone-Number : %d\n",person.phoneNumber);
            printf("Vaccine-Name : %s\n",person.vacName);
            fread(&person,sizeof(person),1,file);
        }

    }
    fclose(file);
}



search()
{
    return 0;
}
int opt;
int main()
{

    printf("\n\t\t\t\t ****** VACCINE MANAGEMENT SYSTEM ******\t\t\t\n");
    printf("\t\t\t\t       ---------------------------\n");
    printf("\n\t\t\t\t\t\t\t\t\tPowered By :- @KhaleKuzzaman");
    printf("\n\n Press any key to continue ......................\n");
    getch();
    system("CLS");
    mainMenu();

    printf("\nEnter your choice option is : ");
    scanf("%d",&opt);
    switch(opt)
    {
    case 1 :
        system("CLS");
        registrationPage();
        break;
    case 2 :
        system("CLS");
        vaccineData();
        break;
    case 3 :
        system("CLS");
        loginPage();
        break;
    case 4 :
        system("CLS");
        search();
        break;
    default :
        system("ClS");
        printf("\n\n    Sorry ...!! Your choose option is not correct,Please try again\n");
        printf("\n\n\n\n\n\n \t\t\t\t\t\t\t  Thanks.......!!!!\n");
        break;
    }

    getch();
}

