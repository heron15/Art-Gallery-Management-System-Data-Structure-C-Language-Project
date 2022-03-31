#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define s1 50
typedef struct resgisArstist artist;

struct resgisArstist
{
    char paintName[s1];
    double paintPrice;
    int paintYear;
    int paintIndexNo;
    artist *adress;
};

artist *head;

char artistName[s1];
char artistHomeland[s1];
int artistAge;
int artistBrithYear;
char artistArtType[s1];
char artistUsername[s1]=" ";
char artistPassword[s1]=" ";

char exhiName[s1];
int exhiAge;
char exhiUsername[s1]=" ";
char exhiPassword[s1]=" ";

void insert(char *paintName, double paintPrice, int paintYear, int paintIndexNo)
{
    artist *temp = (artist *)malloc(sizeof(artist));

    strcpy(temp->paintName, paintName);
    temp->paintPrice=paintPrice;
    temp->paintYear=paintYear;
    temp->paintIndexNo=paintIndexNo;

    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        temp->adress=head;
        head=temp;
    }
}

void display()
{
    artist *temp = head;

    printf("\n-----------------Painting------------------\n\n");

    while(temp!=NULL)
    {
        printf("\nPainting name: %s\n", temp->paintName);
        printf("Painting price: %.2lf\n", temp->paintPrice);
        printf("Painting year: %d\n", temp->paintYear);
        printf("Painting code: %d\n", temp->paintIndexNo);
        printf("\n");
        temp=temp->adress;
    }

    printf("\n--------------------------------------------\n");
}


void order()
{
    int a[10][2];
    int n, i=0,j=0;

    do
    {
        printf("\nPlease enter the Painting code NUMBER:\n");

        for(i=0; i<2; i++)
        {
            scanf("%d", &a[j][i]);
        }
        j++;
        printf("\nYou want more item?\n\n===========\n| 1. Yes. |\n| 2. No.  |\n===========\n");
        printf("\nChose a option: ");
        scanf("%d", &n);
    }
    while(n==1);

    getchar();
    double total_amount=0.0;
    char name[s1];
    char date[s1];
    printf("\nEnter name: ");
    gets(name);
    printf("Enter Date: ");
    gets(date);

    printf("----------------------| BILL |---------------------");

    printf("\n  Name: %s\n", name);
    printf("  Date: %s\n", date);

    int k=0;
    for(k=0; k<j; k++)
    {
        artist *temp = head;
        while(temp->paintIndexNo!=a[k][0])
        {
            temp=temp->adress;
        }
        printf("\n  %d--------%s--------%d-------%.2lf\n", temp->paintIndexNo, temp->paintName, a[k][1], (a[k][1]*(temp->paintPrice)));
        total_amount+=(a[k][1]*(temp->paintPrice));
    }

    printf("\n___________________________________________________\n\n");
    printf("  Total payable amount is:------------%.2lf\n", total_amount);
    printf("\n---------------------------------------------------\n");

}


int main()
{
    int n;

    char paintName[s1];
    double paintPrice;
    int paintYear;
    int paintIndexNo;

    do
    {
        printf("\n------------------");
        printf("\n| 1. Registered. |\n| 2. Login.      |\n| 3. Exit.       |\n");
        printf("------------------\n");
        printf("\nChose a option: ");
        scanf("%d", &n);

        switch(n)
        {
        case 1:
            printf(" ");
            int n1;

            printf("\n------------------------------");
            printf("\n| 1. Register as a Artist.   | \n| 2. Register as a Exhibitor |\n");
            printf("------------------------------\n");
            printf("\nChose a Option: ");
            scanf("%d", &n1);

            switch(n1)
            {

            case 1:
                printf(" ");

                printf("\nEnter your Name: ");
                getchar();
                gets(artistName);

                printf("Enter Homeland: ");
                getchar();
                gets(artistHomeland);

                printf("Enter age: ");
                scanf("%d", &artistAge);

                printf("Enter Birth Year: ");
                scanf("%d", &artistBrithYear);

                printf("Enter Art Category: ");
                getchar();
                gets(artistArtType);

                printf("Enter Username: ");
                getchar();
                gets(artistUsername);

                printf("Enter Password: ");
                getchar();
                gets(artistPassword);

                printf("\nRegistration Successful!! :)\n\nNow ready to login. :)\n");

                break;

            case 2:
                printf(" ");

                printf("\nEnter your Name: ");
                getchar();
                gets(exhiName);

                printf("Enter age: ");
                scanf("%d", &exhiAge);
                getchar();

                printf("Enter Username: ");
                gets(exhiUsername);

                printf("Enter Password: ");
                getchar();
                gets(exhiPassword);

                printf("\nRegistration Successful!! :)\n\nNow ready to login. :)\n");

                break;

            default:
                printf("\nWrong option selected!!\n");
                break;
            }
            break;

        case 2:
            printf(" ");

            int nx;

            printf("\n---------------------------");
            printf("\n| 1. Login as a artist.   |\n| 2. Login as a Exhibitor |\n");
            printf("---------------------------\n");
            printf("\nChose a option: ");
            scanf("%d", &nx);

            switch(nx)
            {

            case 1:
                printf(" ");
                char aPassword[s1];
                char aUsername[s1];
                int nart;
                int nss;

                printf("\nEnter Your Username: ");
                getchar();
                gets(aUsername);

                printf("Enter Your Password: ");
                getchar();
                gets(aPassword);

                if((strcmp(aUsername, artistUsername) && strcmp(aPassword, artistPassword))==0)
                {
                    do
                    {
                        printf("\n----------Welcome Artist Dashbord----------\n");
                        printf("\n---------------------------");
                        printf("\n| 1. Add painting Details |\n| 2. View All Painting    |\n| 3. Update your profile  |\n| 4. View Profile Details |\n");
                        printf("---------------------------\n");
                        printf("\nChose a option: ");
                        scanf("%d", &nart);

                        switch(nart)
                        {

                        case 1:
                            printf(" ");

                            int mm;

                            do
                            {
                                printf("\nEnter painting name: ");
                                getchar();
                                gets(paintName);

                                printf("Enter painting price: ");
                                scanf("%lf", &paintPrice);

                                printf("Enter painting year: ");
                                scanf("%d", &paintYear);

                                printf("Enter paint code: ");
                                scanf("%d", &paintIndexNo);

                                insert(paintName, paintPrice, paintYear, paintIndexNo);

                                printf("\nDo you add more paintig?\n1. Yes\n2. No\n");
                                printf("\nChose a option: ");
                                scanf("%d", &mm);

                            }
                            while(mm==1);
                            break;

                        case 2:
                            display();
                            break;

                        case 3:
                            printf("\nUpdate Your Profile.\n");

                            printf("\nEnter your Name: ");
                            getchar();
                            gets(artistName);

                            printf("Enter Homeland: ");
                            getchar();
                            gets(artistHomeland);

                            printf("Enter age: ");
                            scanf("%d", &artistAge);

                            printf("Enter Birth Year: ");
                            scanf("%d", &artistBrithYear);

                            printf("Enter Art Category: ");
                            getchar();
                            gets(artistArtType);

                            break;

                        case 4:
                            printf("\n------Your Profile-------\n");

                            printf("\nName: %s\n", artistName);
                            printf("Homeland: %s\n", artistHomeland);
                            printf("Age: %d\n", artistAge);
                            printf("Year: %d\n", artistBrithYear);
                            printf("Art Category: %s\n", artistArtType);
                            break;

                        default:
                            printf("\nWrong option choses.\n");
                            break;
                        }

                        printf("\n1. Artist Dashbord\n2. Main Menu\n");
                        printf("\nChose a option: ");
                        scanf("%d", &nss);

                    }
                    while(nss==1);
                }
                else
                {
                    printf("\nWrong Username and Password!! :(\n");
                }

                break;

            case 2:
                printf(" ");
                
                int nff;

                char ePassword[s1];
                char eUsername[s1];

                printf("\nEnter Your Username: ");
                getchar();
                gets(eUsername);

                printf("Enter Your Password: ");
                getchar();
                gets(ePassword);

                if((strcmp(eUsername, exhiUsername) && strcmp(ePassword, exhiPassword))==0)
                {
                    do
                    {
                        printf("\n1. View All Painting\n2. Buy Painting\n3. View your profile\n");
                        printf("\nChose a option: ");
                        scanf("%d", &nff);

                        switch(nff)
                        {

                        case 1:
                            printf(" ");
                            if(head==NULL)
                            {
                                printf("\nStock Empty.\n");
                            }
                            else
                            {
                                display();
                            }
                            break;

                        case 2:
                            if(head==NULL)

                            {
                                printf("\nStock Empty\n");
                            }
                            else
                            {
                                order();
                            }
                            break;

                        case 3:
                            printf("\n------Your Profile-------\n");

                            printf("\nName: %s\n", exhiName);
                            printf("Age: %d\n", exhiAge);
                            break;

                        default:
                            printf("\nWrong option choses.\n");
                            break;
                        }

                        printf("\n1. Exhibitor Dashbord\n2. Main Menu\n");
                        printf("\nChose a option: ");
                        scanf("%d", &nss);

                    }
                    while(nss==1);
                }
                else
                {
                    printf("\nWrong Username and Password!! :(\n");
                }
                break;

            default:
                printf("\nWrong option selected!!\n");
                break;
            }

            break;

        case 3:
            break;

        default:
            printf("\nWrong Option choses!!\n");
            break;
        }

    }
    while(n!=3);

    return 0;
}
