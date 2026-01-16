#include<stdio.h>

void maininterface(int choice);



    int firstchoice;

int main()
{
     
   
        maininterface(firstchoice);

  
    

return 0;
}

void maininterface(int choice)
{

    
        printf("\t\t==========================================\n");
        printf("\t\t       WELCOME TO SMART BANK SYSTEM       \n");
        printf("\t\t==========================================\n");
        printf("\t\t1. Create New Account\n");
        printf("\t\t2. User Login\n");
        printf("\t\t3. Admin Login\n");
        printf("\t\t4. Exit\n");
        printf("\t\t==========================================\n");
        printf("\t\tEnter your choice: ");
        scanf("%d",&firstchoice);

        while(getchar()!='\n');

        switch(firstchoice){

            case 1:
            printf("user login");
            break;
            case 2:
            printf("Admin login");
            break;
            case 3:
            printf("Create New Account");
            break;
            case 4:
            printf("Exit");
            break;
            default:
            printf("\n\t\t\tInvalid choice! Please enter 1-4.!!!\n");
            printf("\t\t\tPress any key to continue...\n");
            maininterface(firstchoice);
            
        }
    
}


