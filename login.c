#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

#define ESC 27
#define SPACE 32
#define TAB 9

struct system
{
    char username[20];
    char password[20];
}sys;

void delay(int);
void signup();
void login();
void gotoxy(int, int);

void main()
{ 
    char ch;
    do{
        system("cls");        
        gotoxy(60,10);
        printf("****************************************");
        gotoxy(60,11);
        printf("****************************************");
        gotoxy(65,13);
        printf("LOGIN / SIGNUP FOR YOUR ACCOUNT ");
        gotoxy(65,14);
        printf("Press SPACE For Signup");
        gotoxy(65,15);
        printf("Press TAB For Login");
        gotoxy(65,16);
        printf("Press ESC For Exit ");
        gotoxy(60,18);
        printf("****************************************");
        gotoxy(60,19);
        printf("****************************************");
        delay(1);
    
        ch = getch();
        switch(ch)
        {
            case SPACE:
                gotoxy(45, 22);
                printf("Processing..........................................................................");                
                delay(1);
                signup();
                break;
            case TAB:
                gotoxy(45, 22);
                printf("Processing..........................................................................");
                delay(1);
                login();
                delay(5);
                break;
            case ESC:
                gotoxy(45,26);
                printf("EXITING..........................................................................");
                delay(2);
                gotoxy(67,32);
                printf("EXITED SUCCESSFULLY !!!");
                delay(3);
                system("cls");
                exit(0);
                break;
        }
    }while(ch != ESC);  
    gotoxy(45, 65);
}

void signup()
{
    system("cls");
    char c;

    gotoxy(60,10);
    printf("****************************************");
    gotoxy(60,11);
    printf("****************************************");
    gotoxy(65,13);
    printf(":: ::  READY FOR SIGNUP    :: ::");
    gotoxy(65,14);
    printf(":: ::  ENTER YOUR DETAILS  :: ::");
    gotoxy(60,16);
    printf("****************************************");
    gotoxy(60,17);
    printf("****************************************");
    gotoxy(65,19);
    printf("SET  USERNAME\t  :\t");
    gets(sys.username);
    gotoxy(65,20);
    printf("SET  PASSSWORD\t  :\t");
    gets(sys.password);
    gotoxy(45,26);
    printf("********************** DETAILS SAVED SUCCESSFULLY ***********************");
    delay(3);

}

void login()
{
    system("cls");   //CLEARS THE WHOLE SCREEN
    char c = '+';              //just an initial value to c 
    int j;
    char user[20];
    char pass[20];
    int check_user;
    int check_pass;
    do{
        system("cls");
        gotoxy(60,10);
        printf("****************************************");
        gotoxy(60,11);
        printf("****************************************");
        gotoxy(65,13);
        printf(":: ::  READY FOR LOGIN     :: ::");
        gotoxy(65,14);
        printf(":: ::  ENTER YOUR DETAILS  :: ::");
        gotoxy(60,16);
        printf("****************************************");
        gotoxy(60,17);
        printf("****************************************");
    
        gotoxy(65,19);
        printf("ENTER  USERNAME\t:\t");
        gets(user);
        j = strcmp(sys.username, user);
        if(j!=0)
        {
            gotoxy(50,21);
            printf("***************************************************************");
            gotoxy(54,22);
            printf("INVALID USERNAME ! TRY AGAIN ! PRESS ANY KEY TO CONTINUE");
            gotoxy(50,23); 
            printf("***************************************************************");
            getch();           
            
        }
    }while(j!=0);
    gotoxy(65,20);
    printf("ENTER  PASSWORD\t:\t");

    int i=0;
    while(c!=13)
    {
        c = getch();
        if(c == 13)
            break;
        printf("*");
        pass[i] = c;
        i++;        
    }
    gotoxy(45,26);
    printf("Processing....................................................................");
    delay(2);

    check_user = strcmp(sys.username, user);
    check_pass = strcmp(sys.password, pass);
    system("cls");


    if(check_user != 0 && check_pass != 0)
    {
        gotoxy(60,10);
        printf("****************************************");
        gotoxy(65,12);
        printf("INVALID USERNAME AND PASSWORD");
        gotoxy(65,13);
        printf("TRY AGAIN");
        gotoxy(60,15);
        printf("****************************************");
    }

    else if(check_user == 0 && check_pass != 0)
    {
        gotoxy(60,10);
        printf("****************************************");
        gotoxy(65,12);
        printf(":: :: INVALID PASSWORD :: ::");
        gotoxy(65,13);
        printf(":: ::     TRY AGAIN    :: ::");
        gotoxy(60,15);
        printf("****************************************");       
    }
    else
    {
        gotoxy(60,10);
        printf("****************************************");
        gotoxy(65,12);
        printf(":: :: LOGGED IN SUCCESSFULLY");
        gotoxy(65,13);
        printf(":: :: WELCOME %s ", sys.username);
        gotoxy(60,15);
        printf("****************************************");       
    }
}


//FUNCTION TO DELAY THE OUTPUT MESSAGE ON SCREEN
void delay(int sec)
{
    int ms = 1000 * sec;
    clock_t start = clock();
    while(clock() < start + ms);
}

void gotoxy(int x, int y)
{
    COORD c = { x, y };  
    SetConsoleCursorPosition(  GetStdHandle(STD_OUTPUT_HANDLE) , c);
}
