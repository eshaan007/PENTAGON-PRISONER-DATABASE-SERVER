#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void addrecord();
void viewrecord();
void searchrecord();
void deleterecord();
void login();

struct prison
{
    char id[10];
    char name[30];
    char age[6];
    char gender[10];
    char weight[20];
    char height[20];
    char crime[40];
    char convictedf[20];
    char punishment[50];
    char emergencyn[20];

} a;

int main()
{    
    login();
    
    int ch;

    while(1)
    {

    printf("                      PENTAGON PRISON DATABASE SERVER \n\n");
    printf("********************************************************************************\n\n\n\n");
    printf("\t\t              PRISONER RECORDS\n");
    printf("\n        DIRECTORIES:");

        printf("\n\n\t\tMAIN MENU:");
        printf("\n\n\tADD RECORD\t[1]");
        printf("\n\tSEARCH RECORD\t[2]");
        printf("\n\tVIEW RECORD\t[3]");
	printf("\n\tDELETE RECORD\t[4]");
        printf("\n\tEXIT\t\t[5]");
        printf("\n\n\tENTER YOUR CHOICE:");
        scanf("%d",&ch);

        switch(ch)
        {

        case 1:
            addrecord();
            break;

        case 2:
            searchrecord();
            break;

        case 3:
            viewrecord();
            break;

        case 4:
            deleterecord();
            break;
            
        case 5:
            exit(0);

        default:
            printf("\nYOU ENTERED WRONG CHOICE.");
            printf("\nPRESS ANY KEY TO TRY AGAIN");
            getchar();
            break;
        }
        system("clear");
    }
    return 0;
}

/**************** ADDING FUNCTION************************/

void addrecord( )

{
    system("clear");
    FILE *fp ;
    char another = 'Y' ,id[10];
  //  char filename[30];
    int choice;

    printf("\t\t WELCOME TO THE ADD MENU ");
    printf("\n\n\tENTER FIRST NAME OF PRISONER:\t");
    scanf(" %[^\n]s",&a.name[0]);
    fflush(stdin);
    //scanf("%[^\n]s",&filename[0]);

    fp = fopen ("filename.txt", "a+" ) ;
    while ( another == 'Y'|| another=='y' )

    {
        choice=0;
        fflush(stdin);

	printf ( "\n\tENTER PRISONER ID:\t");
        scanf(" %s",id);

		rewind(fp);

        while(fread(&a,sizeof(a),1,fp)==1)
        {
            if(strcmp(a.id,id)==0)
            {
                printf("\n\tTHE RECORD ALREADY EXISTS.\n");
                choice=1;
            }
        }
        if(choice==0)
        {

            strcpy(a.id,id);

            printf("\tENTER GENDER: ");
            getchar();
            scanf(" %s",a.gender);
            fflush(stdin);

            printf("\tENTER AGE: ");
            scanf(" %s",a.age);
            fflush(stdin);

            printf("\tENTER WEIGHT: ");
            scanf(" %s",a.weight);
            fflush(stdin);

            printf("\tENTER HEIGHT: ");
            scanf("  %s",a.height);
 	    fflush(stdin);

            printf("\tENTER CRIME: ");
            scanf(" %s",a.crime);
            fflush(stdin);

            printf("\tENTER THE PLACE WHERE THE PRISONER WAS CONVICTED: ");
            scanf(" %s",a.convictedf);
            fflush(stdin);

            printf("\tENTER CONVICTION: ");
            scanf(" %s",a.punishment);
            fflush(stdin);

            printf("\tENTER PHONE NUMBER OF EMERGENCY CONTACT: ");
            getchar();
            scanf(" %s",a.emergencyn);

            fwrite ( &a, sizeof ( a ), 1, fp ) ;
            printf("\nYOUR RECORD IS ADDED...\n");
        }
	getchar();
        printf ( "\n\tADD ANOTHER RECORD...(Y/N) \t" ) ;
        fflush ( stdin ) ;
        scanf(" %c",&another);

    }

    fclose ( fp ) ;
    printf("\n\n\tPRESS ANY KEY TO EXIT...");
    getchar();

}

/**************** SEARCHING FUNCTION************************/

void searchrecord( )

{
    system("clear");
    FILE *fp ;
    char id[16],choice;
    int ch;

    printf("\t\t\t* THE SEARCHING MENU * \n\n");
    
    do
	{

	
        printf("\n\t     ENTER THE PRISONER NAME TO BE SEARCHED:   ");
        scanf(" %[^\n]s",a.name);
        fflush(stdin);
        

        fp = fopen ( "filename.txt", "r+" ) ;
   
    	    printf("\n\t                 ENTER PRISONER ID:  ");
            scanf(" %s",id);
            system("clear");

            while ( fread ( &a, sizeof ( a ), 1, fp ) == 1 )

          
          if(strcmp(a.id,id)==0)
            { 
                printf("\nTHE WHOLE RECORD IS:");
                printf("\n");
                printf("\nPRISONER'S NAME IS:                             %s",a.name);
                printf("\nPRISONER'S ID IS:                               %s",a.id);
                printf("\nPRISONER'S GENDER IS[M/F]:                      %s",a.gender);
                printf("\nPRISONER'S AGE IS[YEARS]:                       %s",a.age);
                printf("\nPRISONER'S WEIGHT IS[KG]:                       %s",a.weight);
                printf("\nPRISONER'S HEIGHT IS[IN METRES]:                %s",a.height);
                printf("\nPRISONER'S CRIME IS:                            %s",a.crime);
                printf("\nTHE PLACE WHERE THE PRISONER WAS CONVICTED IS:  %s",a.convictedf);
                printf("\nPRISONER'S CONVICTION IS[YEARS]:                %s",a.punishment);
                printf("\nEMERGENCY CONTACT'S PHONE NUMBER IS:            %s",a.emergencyn);
                printf("\n\n\n");
                printf("Enter any character on the keyboard to exit");
            }

          
        else 
            { 
                printf("THE RECORD DOES NOT EXIST");
                printf("\n\nWOULD YOU LIKE TO CONTINUE VIEWING...(Y/N):");
                fflush(stdin);
            }
        scanf(" %c",&choice);

    }
    while(choice=='Y'||choice=='y');

    fclose ( fp) ;
	getchar();
    return ;
getchar();
}

/**************** VIEWING FUNCTION************************/

void viewrecord()

{
    system("clear");
    FILE *fp;
    struct prison a;

    printf("\t\t   * LIST OF PRISONERS *\n\n");
   
    fp=fopen("filename.txt","r+");
    rewind(fp);
    while((fread(&a,sizeof(a),1,fp))==1)
    {
    	printf("*******PRESS ENTER KEY TO LOAD OTHER RECORDS*******\n");
        printf("\nPRISONER'S NAME IS:                             %s",a.name);
        printf("\nPRISONER'S ID IS:                               %s",a.id);
        printf("\nPRISONER'S GENDER IS[M/F]:                      %s",a.gender);
        printf("\nPRISONER'S AGE IS[YEARS]:                       %s",a.age);
        printf("\nPRISONER'S WEIGHT IS[KG]:                       %s",a.weight);
        printf("\nPRISONER'S HEIGHT IS[IN METRES]:                %s",a.height);
        printf("\nPRISONER'S CRIME IS:                            %s",a.crime);
        printf("\nTHE PLACE WHERE THE PRISONER WAS CONVICTED IS:  %s",a.convictedf);
        printf("\nPRISONER'S CONVICTION IS[YEARS]:                %s",a.punishment);
        printf("\nEMERGENCY CONTACT'S PHONE NUMBER IS:            %s",a.emergencyn);
        getchar();
     printf("\n\n");

    }
    fclose(fp);
	getchar();

}

/**************** DELETING FUNCTION************************/

void deleterecord( )

{

    system("clear");
    FILE *fp,*ft ;
    struct prison file ;
    char another = 'Y' ,id[16];
    int choice,check;
    int j=0;
    char pass[10]="pass";
    char pword[10];

    printf("\t\t        WELCOME TO DELETE MENU\n\n");
    
    printf("\t\t          Enter the password:   ");
    scanf("%s",pword);
	if (strcmp(pword,"pass")==0)
	{

    printf("\n\t\t           ACCESS GRANTED\n\n");
         while ( another == 'Y' || another == 'y' )

           {

    	    printf("\n\t\tENTER THE NAME OF PRISONER TO BE DELETED:");
            scanf(" %s",&a.name[0]);
	    fflush(stdin);
            fp = fopen ("filename.txt", "r+" ) ;
            if ( fp == NULL )
                {
                    printf("\nTHE FILE DOES NOT EXIST");
                    printf("\nPRESS ANY KEY TO GO BACK.");
                    getchar();
                    return ;
		}
		
             ft=fopen("temp","w");
             if(ft==NULL)
                {
                	printf("\nSYSTEM ERROR");
                    printf("\nPRESS ANY KEY TO GO BACK");
                    getchar();
                    return ;
                }
             printf("\n\t\tENTER THE ID OF RECORD TO BE DELETED:");
             fflush(stdin);
             scanf(" %s",id);
             while(fread(&file,sizeof(file),1,fp)==1)
                {
                    if(strcmp(file.id,id)!=0)
                    fwrite(&file,sizeof(file),1,ft);
                    printf("\n\t\t               DELETED SUCCESFULLY...");
                }
           fclose(ft);
           fclose(fp);
           remove("filename.txt");
           rename("temp","filename.txt");
           getchar();

           printf("\n\t\tDO YOU LIKE TO DELETE ANOTHER RECORD.(Y/N):");
           fflush(stdin);
           scanf(" %c",&another);

    }
    getchar();
}
	else
	{
		printf("\n\t\t            Sorry!Invalid password\n");
		exit(0);
	}

}


void login()

{
        system("clear");

    printf("                                WELCOME TO   \n");
    printf("                      PENTAGON PRISONER DATABASE SERVER\n\n");
    printf("********************************************************************************\n\n\n\n");

	int a=0;
    char uname[10];
    char pword[10];
    char user[10]="user";
    char pass[10]="pass";
    do
{
    printf(" \n                           ENTER USERNAME:-");
    scanf(" %s", uname);
    printf(" \n                           ENTER PASSWORD:-");
    scanf(" %s",pword);
    system("clear");

    if(strcmp(uname,"user")==0 && strcmp(pword,"pass")==0)
	{
	getchar();
	break;
	}
	else
	{
        printf("                      PENTAGON PRISONER DATABASE SERVER\n\n");
        printf("********************************************************************************\n\n\n\n");

		printf("\n                    LOGIN IS UNSUCESSFUL!! TRY AGAIN               \n");
		a++;
		getchar();
	}
}
	while(a<=2);
	if (a>2)
	{
		printf("\n You have entered the wrong username and password for 3 times");
		getchar();
		exit(0);
		}
}
