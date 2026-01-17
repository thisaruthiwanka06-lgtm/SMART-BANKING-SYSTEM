#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>


struct newUserAcc{
			char name[50];
			char NIC[15];
			char email[30];
			char username[50];
			char password[50];
			char C_password[50];
			int accnumber;
	};

void maininterface(int choice);
void createNewAcc(int choice);
void newSavingacc(struct newUserAcc *newuser);
int findDuplicate(char *searchstr);

   
    int firstchoice;
    int Create_acc_choice;
    struct newUserAcc newuser;

int main()
{
     

        maininterface(firstchoice);
        
return 0;
}

void maininterface(int choice)
{

        printf("\n\n");
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
            createNewAcc(Create_acc_choice);
            break;
            case 2:
            printf("user login");
            break;
            case 3:
            printf("Admin login");
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

void createNewAcc(int choice)
{
    printf("\n\n");
    printf("\t\t==========================================\n");
    printf("\t\t       CREATE NEW ACCOUNT - TYPE          \n");
    printf("\t\t==========================================\n");
    printf("\t\tSelect Account Type:\n\n");
    printf("\t\t1. Savings Account (Interest: 5%%)\n");
    printf("\t\t2. Current Account (No Interest)\n");
    printf("\t\t3. Back to Main Menu\n");
    printf("\t\t==========================================\n");
    printf("\t\tEnter your choice: ");
    scanf("%d",&Create_acc_choice);

    while(getchar()!='\n');

    switch(Create_acc_choice){

        case 1:
        newSavingacc(&newuser);
        break;
        case 2:
        break;
        case 3:
        maininterface(firstchoice);
        break;
        default:
        printf("\n\t\t\tInvalid choice! Please enter 1-3.!!!\n");
        createNewAcc(Create_acc_choice);
    }

}

void newSavingacc(struct newUserAcc *newuser)
	{
		
		FILE *fpr;
		fpr=fopen("accDetails.txt","a");
			
		if(fpr==NULL)
		{
			printf("file cannot created!!");
		}
		
		srand(time(NULL));
		
		newuser->accnumber=(rand()%900000)+100000;

    printf("\n\n");
    printf("\t\t------------------------------------------\n");
    printf("\t\t        USER REGISTRATION FORM\n");
    printf("\t\t------------------------------------------\n");

   
    printf("\t\tEnter Your Name      : ");
    fgets(newuser->name,50,stdin);
	
	newuser->name[strcspn(newuser->name,"\n")]=0;
    
	do{
		 printf("\n\t\tEnter Your NIC       : ");
		scanf("%s",newuser->NIC);
		if(strlen(newuser->NIC)!=12 && strlen(newuser->NIC)!=10)
			{
				printf("\n\t\tError: NIC do not match. Please try again.\n");
			}
		else if(findDuplicate(newuser->NIC))
			{
					printf("\t\tError: NIC already exists!\n");
					newuser->NIC[0] = '\0'; 
			}
			
			
		}while(strlen(newuser->NIC)!=12 && strlen(newuser->NIC)!=10);
	
   
		
		
    printf("\n\t\tEnter Your Email     : ");
    scanf("%s",newuser->email);
    printf("\n\t\tEnter Your Username  : ");
    scanf("%s",newuser->username);
	
	do{
		printf("\n\t\tEnter Your Password  : ");
		scanf("%s",newuser->password);
		printf("\n\t\tConfirm Your Password  : ");
		scanf("%s",newuser->C_password);
		
		if(strcmp(newuser->password,newuser->C_password)!=0)
		{
			printf("\n\t\tError: Passwords do not match. Please try again.\n");
		}
		
		
	}while(strcmp(newuser->password,newuser->C_password)!=0);
    
	
	
		printf("\n\t\t------------------------------------------\n");
		printf("\t\t        Thank You for Joining!\n");
		printf("\t\t------------------------------------------\n");


		

		printf("\n\n\n");
		printf("\t\t==========================================\n");
		printf("\t\t         THIS IS YOUR ACCOUNT DETAILS\n");
		printf("\t\t==========================================\n");

		printf("\t\tThis is YOUR Account Number: %d\n",newuser->accnumber);
		printf("\t\t==========================================\n");
		printf("\t\tName      : %s\n",newuser->name);
		printf("\t\tNIC       : %s\n",newuser->NIC);
		printf("\t\tEmail     : %s\n",newuser->email);
		printf("\t\tUsername  : %s\n",newuser->username);
		printf("\t\tPassword  : %s\n",newuser->password);

		printf("\t\t==========================================\n");
		printf("\t\t      Account Registered Successfully!\n");
		printf("\t\t==========================================\n");	
	
	
		fseek(fpr,0,SEEK_END);
		if(ftell(fpr)==0)
		{
			fprintf(fpr, "%-15s %-15s %-15s %-25s %-15s\n", 
        "ACCOUNT_NO", "Username", "Password", "ACCOUNT_Name", "NIC");
		}
		
		fprintf(fpr,"%-15d %-15s %-15s %-25s %-15s\n"
        ,newuser->accnumber,newuser->username,newuser->password,newuser->name,newuser->NIC);

        fclose(fpr);
        maininterface(firstchoice);
	}
	
		int findDuplicate(char *searchstr)
		{
			FILE *fpr=fopen("accDetails.txt","r");
			
			if(fpr==NULL)
			{
				printf("flie cannot open!!!");
			}
			
			char temp[100];
			
			while(fscanf(fpr,"%s",temp)!=EOF)
			{
				if(strcmp(temp,searchstr)==0)
				{
					fclose(fpr);
				return 1;
				}
			}
			fclose(fpr);
			return 0;
		}

