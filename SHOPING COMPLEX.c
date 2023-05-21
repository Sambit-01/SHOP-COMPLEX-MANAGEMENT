/*SHOP  DATABASE MANGEMENT SYSTEM*/
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h> 

//SELF REFERENTIAL STRUCTURE FOR STORING SHOP DATA IN LINK LIST.
struct node
{
    int shopNo;
    int shopPhoneNo;
    char name[100];
    char sur[100];
    char floor[100];
    char type[100];
    struct node *next;
};
struct node *head=NULL;

// FUNCTION TO DISPLAY THE LINK LIST
void displayLinkedList(struct node *root)
{
    struct node *temp = root;
    
    int count=0;
    while(temp!=NULL)
    {
    	
    	count++;
    	printf("\nShop no.:-%d\n",count);
    	printf("---------------\n");
        printf("Manager's name->%s %s\n",temp->name,temp->sur);
        printf("Shop type->%s\n",temp->type);
        printf("Floor Address->%s \n",temp->floor);
        printf("Shop number->%d\n",temp->shopNo);
        printf("Shop Phone number->%d\n",temp->shopPhoneNo);
        printf("\n");
        
        temp = temp->next;
    }
    
}
//FUCTION FOR INSERT A NODE AT BEGNING (USE FOR ADDMISION PURPOSE)
struct node* insertAtBegin(struct node *head,int shopNo,int shopPhoneNo,char *name,char *sur,char *floor,char *type)
{
    
    struct node *ptr;
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->shopNo = shopNo;
    temp->shopPhoneNo = shopPhoneNo;
    strcpy(temp->name, name);
    strcpy(temp->sur, sur);
    strcpy(temp->type, type);
    strcpy(temp->floor,floor);
    temp->next = NULL;
    
    if(head==NULL)
    {
        head = temp;    
    }
    else 
    {
        temp->next = head;
        head = temp;
    }    
    
    return head;
    
}
//FUCTION TO STORE THE DATA OF LINK LIST TO A TXT FILE IN APENDING(a)MODE
void writeLinkedList(char filename[], struct node* head){
    
    struct node* temp = head;
    
    FILE* file;
    file = fopen (filename, "a");
    if (file == NULL)
    {
        fprintf(stderr, "\nCouldn't Open File'\n");
        exit (1);
    }
    
    // writing all the nodes of the linked list to the file
    while(temp!=NULL)
    {
        fwrite(temp, sizeof(struct node), 1, file);
        temp = temp->next;
    }
    
    if(fwrite != 0)
    {
        printf("\nshop added sucessfully\n");
    }
       else
    {
           printf("Error While Writing\n");
    }
    
    fclose(file);
    
}
//FUCTION TO STORE THE DATA OF LINK LIST TO A TXT FILE IN WRITING(W)MODE

void writeLinkedList1(char filename[], struct node* head){
    
    struct node* temp = head;
    
    FILE* file;
    file = fopen (filename, "w");
    if (file == NULL)
    {
        fprintf(stderr, "\nCouldn't Open File'\n");
        exit (1);
    }
    
    // writing all the nodes of the linked list to the file
    while(temp!=NULL)
    {
        fwrite(temp, sizeof(struct node), 1, file);
        temp = temp->next;
    }
    
    if(fwrite != 0)
    {
        printf("\n Shop deleted sucessfully\n");
    }
       else
    {
           printf(" Error While Writing \n");
    }
    
    fclose(file);
    
}
//FUCTION TO RETRIVE THE DATA FROM TEXT FILE AND PRESENT IN LINK LIST
struct node* readLinkedList(char filename[]){
    
    struct node* temp = (struct node *)malloc(sizeof(struct node));;
    struct node* head; 
    struct node* last; 
    last = head = NULL;
    
    FILE* file;
    file = fopen (filename, "r");
    if (file == NULL)
    {
        fprintf(stderr, "\nCouldn't Open File'\n");
        exit (1);
    }
    
    
    while(fread(temp, sizeof(struct node), 1, file))
    {
        
        if(head==NULL)
        {
            head = last = (struct node *)malloc(sizeof(struct node));
        }
        else
        {
            last->next = (struct node *)malloc(sizeof(struct node));
            last = last->next;
        }
        last->shopNo = temp->shopNo;
        last->shopPhoneNo= temp->shopPhoneNo;
        strcpy(last->name, temp->name);
        strcpy(last->sur, temp->sur);
        strcpy(last->type,temp->type);
        strcpy(last->floor,temp->floor);
        last->next = NULL;
        
    }
    
    fclose(file);
    
    return head;
    
}
//FUCTION FOR PUT A CHARACTER REPEADTLY USING LOOP 

void printChar(char ch,int n)
{
    while(n--)
    {
        putchar(ch);
    }
}
//THIS FUCTION PRINTS THE TITTLE "Shopping Complex Database Management System"
void title()
{
    system("cls");
    system("COLOR 02");
    printf("\n\t");
    printChar('*',20);
    printf(" Shopping Complex Details Management System ");
    printChar('*',20);
    printf("\n");
}
//THIS FUCTION SEARCH A SPECIFIED SHOP BY IT'S SERIAL NUMBER
int searchbyshopNo(struct node *head) 
{  
    struct node *ptr;  
    int item,i=0,flag;  
    ptr =head;   
    if(ptr == NULL)  
    {  
        printf("\nEmpty List\n");  
    }  
    else  
    {   
        printf("\nEnter the shop number:\n");   
        scanf("%d",&item);  
        while (ptr!=NULL)  
        {  
            if(ptr->shopNo == item )  
            {  
               
                
				printf("manager name->%s %s\n",ptr->name,ptr->sur);  
				printf("shop  floor->%s \n",ptr->floor); 
				printf("shop type->%s \n",ptr->type); 
				printf("shop number->%d\n",ptr->shopNo); 
				printf("shop phone number->%d\n",ptr->shopPhoneNo); 
				return i+1;
                flag=0;  
            }   
            else  
            {  
                flag=1;  
            }  
            i++;  
            ptr = ptr -> next;  
        }  
        if(flag==1)  
        {  
           printf("\n Shop not found\n");
            
        }  
    }
}

//THIS FUCTION REMOVES A SHOP BY ITS SHOP NUMBER
struct node * deleteByValue(struct node * head, int value){
    struct node *p = head;
    struct node *q = head->next;
    while(q->shopNo!=value && q->next!= NULL)
    {
        p = p->next;
        q = q->next;
    }
    
    if(q->shopNo == value){
        p->next = q->next;
        
        free(q);
    }
    else{
    	printf("\nshop not found.\n");
	}
    return head;
}
//MAIN FUCTION

int main(){
	
	
    int choice,i,set,set2=0;
    char pass[20],userinput[20],newpass[20];
    FILE *fptr;
    
    jump://this jump statement is used for GOTO statement for logout purpose when a user wanted for logout he will redirect to this page.
        printf(" \n\n\n\n\n\t\t\t\t\t     =  =  =  =  =  =  =  =");
		printf("\n\n\t\t\t\t\t     =                    =");
		printf("\n\n\t\t\t\t\t     =       Welcome      =");
		printf("\n\n\t\t\t\t\t     =                    =");
		printf("\n\n\t\t\t\t\t     =  =  =  =  =  =  =  =");
		printf("\n\n\n\n\n\t\t\t\t\tPress any key to continue...... ");
		getch();
		system("cls");
       while(1){

         printf("\n======================WELCOME TO SHOPPING COMPLEX DATABASE MANGEMENT SYSTEM======================\n");
         printf("presss 1 for LOG IN.\n");
          printf("press 2 for change password/create a password(if you login for FIRST TIME choose option 2.)\n");
         printf("\nEnter your choice:-\t");
        scanf("%d",&choice);


         switch(choice){
	
	
	         case 1:{
		       printf("Enter the password:\t");
		       scanf("%s",&userinput);
		       fptr = fopen("password.txt","r");
               fscanf(fptr,"%s", &pass);
               int value=strcmp(pass,userinput);  
               if(value==0){
        	   printf("\n< LOG IN SUCCESSFUL!,please wait >");
		      for(i=0; i<5; i++)
              {
                printf("\t*");
                Sleep(300);
               }
               set=1;
               set2=1;
           
        	   system("cls");
   
		      }
		      else
		     {
			   printf("\npassword is incorrect");
			
		     }
		     break;
	         }
		    case 2:{
			  int udise;
			  printf("\nplease enter the shop number for authorization:(enter 9889 for UNIQUE code of shop):");
			  scanf("%d",&udise);
			  if(udise==9889){
			
			  fptr=fopen("password.txt","w");

         

             printf("Enter new pasword:\t ");
             scanf("%s",&newpass);

             fprintf(fptr,"%s",newpass);
             fclose(fptr);
             }
              else
              {
     	        printf("error");
	          }
			   break;
		      }
		     default :{
			 printf("\ninvalid choice");
			 break;
		   }

	}
	if(set==1){
		break;
	}
	
}
if(set2==1){
	

        printf(" \n\n\n\n\n\t\t\t\t     *****************************************************************************");
	    printf("\n\n\t\t\t\t     *             Welcome to Shopping Complex database mangement system            *");
	    printf("\n\n\t\t\t\t     *                        DS MINI PROJECT                                       *");
	    printf("\n\n\t\t\t\t     *     CREATED BY:-SAMBIT PRUSTY, NISHANT KUMAR MISHRA, SOHAN CHOUDHURY         *");
		printf("\n\n\t\t\t\t     *                     YASH RAJ, RAHUL DEV PATRA                                *");
		printf("\n\n\t\t\t\t     *                                                                              *");
		printf("\n\n\t\t\t\t     *******************************************************************************");
		printf("\n\n\n\t\t\t\t   PRESS ANY KEY TO CONTINUE...... ");
		getch();
		system("cls");
		
		while(1){
		int choice1;
		struct node *head=NULL;
			
		
		title();
		printf("\n");
		printf("\n\n\t\t1.PRESS 1 FOR ADD SHOP.\n");
		printf("\n\n\t\t2.PRESS 2 FOR SEE THE DETAILS OF ALL SHOP\n");
		printf("\n\n\t\t3.PRESS 3 FOR SEE THE DETAILS OF A SPECIFIED SHOP(search by shop number)\n");
		printf("\n\n\t\t4.PRESS 4 FOR REMOVE/ISSUE A SHOP\n");
		printf("\n\n\t\t6.PRESS 5 FOR LOGOUT\n");
		printf("\n\n\t\t7.PRESS 6 FOR EXIT\n");
		printf("\t=================================================================================================");
		printf("\n\t\tENTER YOUR CHOICE->");
		scanf("%d",&choice1);
		system("cls");
		switch(choice1){
			case 1:{
				int shopNo,shopPhoneNo;
				char managerfirstname[20],managerlastname[20],floor[20],type[20];
				printf("enter manager name:- ");
				scanf("%s %s",&managerfirstname,&managerlastname);
				printf("\nenter floor name:- ");
				scanf("%s",&floor);
				printf("\nenter shop number:- ");
				scanf("%d",&shopNo);
				printf("\nenter shop type:- ");
				scanf("%s",&type);
				printf("\nenter shop phone number:- ");
				scanf("%d",&shopPhoneNo);
				
				head=insertAtBegin(head,shopNo,shopPhoneNo,managerfirstname,managerlastname,floor,type);
				
				writeLinkedList("shopdetails.txt", head);
				printf("\npress any key to back to main menu\n");
				getch();
				
			
				
				
				break;
			}
			case 2:{
				int back;
				printf("details of all the SHOP:");
				
				struct node *newhead=readLinkedList("shopdetails.txt");
				displayLinkedList(newhead);
				printf("\npress any key to back to main menu\n");
				getch();
				
				break;
			}
			case 3:{
				int choice3;
				
				printf("press 1 to search by shop number:\n");
                printf("For GARMENTS shopNo/Code = 1 or 5 or 8 \n");
				printf("For RESTAURANTS shopNo/Code = 2 or 4 or 7 \n");
				printf("For ELECTRONICS shopNo/Code = 3 or 6 or 9 \n");
                printf("For GROCERIES shopNo/Code = 10 11 12 \n");
                printf("For FOOTWEAR shopNo/Code = 15 16 17 \n");
			
				printf("press 2 for go back to main menu\n");
				printf("enter your choice:\n");
				scanf("%d",&choice3);
				switch(choice3){
					case 1:{
						struct node *newhead1=readLinkedList("shopdetails.txt");
						searchbyshopNo(newhead1);
						
						break;
					}
				
					
					case 2:{
						
						
						break;
					}
					default :{
			       	printf("\ninvalid choice\n");
			    	break;
			       } 
				}
				
				printf("press any key to back to main menu....");
				getch();
				break;
			}
			
			case 4:{
				int choice4;
				printf("press 1 for remove a shop number\n");
				
				printf("press 2 for go back to main menu\n");
				printf("enter your choice:");
				scanf("%d",&choice4);
				switch(choice4){
					case 1:{
						int shopNo;
					
						struct node *del=readLinkedList("shopdetails.txt");
						printf("enter the number of the shop:");
						scanf("%d",&shopNo);
						
						struct node *del1=deleteByValue(del,shopNo);
						
						
						writeLinkedList1("shopdetails.txt", del1);
						printf("presss any character to go to main menu......\n");
						getche();
						break;
					}
				
					case 2:{
						
						break;
					}
					default :{
				    printf("\ninvalid choice\n");
				    break;
			       }
				}
				
				
				break;
			}
			
			case 5:{
				goto jump;
				
				break;
			}
			case 6:{
				exit(1);
				break;
			}
			default :{
				printf("\ninvalid choice\n");
				break;
			}

			}
		}
	
	}
}
