#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct FriendList
{
    char name[50];
    int id;
    struct FriendList * next;
};



struct UserList
{
	char name[50];
	char password [50];
	int id;
	struct UserList * nextvertex;
	struct FriendList * nextedge;	
};


struct FriendList* head2 = NULL;
struct UserList* head = NULL;
int counter = 1;



void SignUp( char name[] , char password[])
{
	struct UserList* temp1 = (struct UserList*)malloc(sizeof(struct UserList));
	struct UserList* temp2 = head;
	strcpy(temp1->name,name);
	strcpy(temp1->password,password);
	temp1->nextedge = NULL;
	temp1->nextvertex = NULL;
	temp1->id = counter;
	counter++;
	if (head == NULL)
	{
		head = temp1;
	}
	else
	{
		while(temp2->nextvertex != NULL)
		{
			temp2 = temp2->nextvertex;
		}
		temp2->nextvertex = temp1;
		
	}
	printf("\n\nNow you are a member of Connecting People.");
	printf("\nYour Connecting People ID is : %d\n\n",temp1->id);
}

int SignIn(long id , char password[])
{
	struct UserList* temp;
	temp= head;
	
	while (temp != NULL)
	{
		if (temp->id == id && strcmp(temp->password,password)==0)
		{
			printf ("\nYou Are Signed In.\n");
			printf("\n \n\t \t \t~~~~~ Welcome %s ~~~~~\t \t \t \t \n \n ",&temp->name);
			return 1;
		}
		temp = temp->nextvertex;
	}
	return 0;
}

void Displayfriends(int g)
{
	struct FriendList* temp = head2 ;
	struct UserList* temp1 = head;
	
	while(temp1 != NULL)
	{
		if(temp1->id == g)
		{

			if(temp1->nextedge != NULL)
			{
				temp=temp1->nextedge;
				
				while(temp != NULL)
				{
					printf("  ->  ");
					printf("%s",temp->name);
					temp = temp->next;

				}
				return;
			}
			else
			{
			printf("\n\n No Friends. :( \n\n");
			}
			
		}
		temp1 = temp1->nextvertex;	
	}	
}



int SearchFriend(char name[])
{
	struct UserList* temp1;
	temp1 = head;
	
	while (temp1 != NULL)
	{
		if(strcmp(temp1->name,name)==0)
		{
//			printf("\nSearch Done.\n");
			return 1;
		}
		temp1 = temp1->nextvertex;
	}
}




void AddFriend(char name[], int g)
{
	int tempid;
	struct FriendList* NewFriend = (struct FriendList*)malloc(sizeof(struct FriendList)); 
	struct FriendList* temp2 = head2;
	strcpy(NewFriend->name,name);
	NewFriend->next = NULL;
	
	struct UserList* temp = head;
	
	while(temp != NULL)
	{
		if (strcmp(temp->name,name)==0)
		{
			tempid = temp->id;
			printf("\n%d\n",temp->id);
			break;
		}
		temp = temp->nextvertex;
	}
	
	NewFriend->id = tempid;
	
	struct UserList* temp1 = head;
	
	while (temp1 != NULL)
	{
		if(temp1->id == g)
		{
			if(head2 == NULL)
			{
				head2 = NewFriend;
				
			}
			else
			{

				NewFriend->next = head2;
				head2 = NewFriend;
			
			}
			
			temp1->nextedge = NewFriend;
		
			return;
			
		}
		temp1 = temp1->nextvertex;
	}
	
}



void Add_Friend(char name [] , int g)
{
	int tempid;
	struct FriendList* NewFriend = (struct FriendList*)malloc(sizeof(struct FriendList)); 
	struct FriendList* temp2 = head2;
	NewFriend->id = g;
	NewFriend->next = NULL;
	
	struct UserList* temp = head;
	
	while(temp != NULL)
	{
		if(temp->id == g)
		{
			strcpy(NewFriend->name,temp->name);
			break;
		}
		if(strcmp(temp->name,name)==0)
		{
			tempid = temp->id;
			break;
		}
	}
	
	struct UserList* temp1 = head;
	
	while (temp1 != NULL)
	{
		if(temp1->id == tempid)
		{
			if(head2 == NULL)
			{
				head2 = NewFriend;
				
			}
			else
			{

				NewFriend->next = head2;
				head2 = NewFriend;
			
			}
			
			temp1->nextedge = NewFriend;
		
			return;
			
		}
		temp1 = temp1->nextvertex;
	}
	
	
}



void UnFriend(int g , char name[])
{
	int tempid;
	struct UserList* temp = head;
	struct FriendList* temp2 = head2;
	struct FriendList* temp3 = temp2->next;
	struct FriendList* temp4 = head2;
	
	while(temp != NULL)
	{
		if (strcmp(temp->name,name)==0)
		{
			tempid = temp->id;
			printf("%d",temp->id);
			break;
		}
		temp = temp->nextvertex;
	}
	
		struct UserList* temp1 = head;
	
	while (temp1 != NULL)
	{
		if(temp1->id == g)
		{
			if(temp1->nextedge != NULL)
			{
				temp2=temp1->nextedge;
				if(temp2->id == tempid)
				{
					free(temp2);
					temp1->nextedge = temp3;
					printf("\n\nDeleted.\n\n");
					return;
				}
				
				while(temp2 != NULL)
				{
					if(temp3->id == tempid)
					{
						temp2->next = temp3->next;
						free(temp3);
						printf("\n\nDeleted.\n\n");
						return;
					}
					temp2 = temp2->next;
					temp3 = temp3->next;
				}
		}
			temp1 = temp1->nextvertex;
	}
}
}




void Un_Friend(int g , char name[])
{
	int tempid;
	struct UserList* temp = head;
	struct FriendList* temp2 = head2;
	struct FriendList* temp3 = temp2->next;
	struct FriendList* temp4 = head2;
	
	while(temp != NULL)
	{
		if (strcmp(temp->name,name)==0)
		{
			tempid = temp->id;
			printf("%d",temp->id);
			break;
		}
		temp = temp->nextvertex;
	}
	
		struct UserList* temp1 = head;
	
	while (temp1 != NULL)
	{
		if(temp1->id == tempid)
		{
			if(temp1->nextedge != NULL)
			{
				temp2=temp1->nextedge;
				if(temp2->id == g)
				{
					free(temp2);
					temp1->nextedge = temp3;
					printf("\n\nDeleted.\n\n");
					return;
				}
				
				while(temp2 != NULL)
				{
					if(temp3->id == g)
					{
						temp2->next = temp3->next;
						free(temp3);
						printf("\n\nDeleted.\n\n");
						return;
					}
					temp2 = temp2->next;
					temp3 = temp3->next;
				}
		}
			temp1 = temp1->nextvertex;
	}
}
}



void Suggestion(int g)
{
	int tempid;
	struct UserList* temp = head;
	struct UserList* temp2 = head;
	struct FriendList* temp1 = head2;
		while(temp != NULL)
	{
		if(temp->id == g)
		{
				if(temp->nextedge != NULL)
			{
				temp1=temp->nextedge;
				
				while(temp1 != NULL)
				{
					tempid = temp1->id;
					while(temp2 != NULL)
					{	
						if(temp2->id != tempid && temp2->id != g)
						{
							
							printf("  %s\n",temp2->name);
							
							
						}
						temp2 = temp2->nextvertex;
				}
					temp1 = temp1->next;
				}
			}
			else 
			{
				while(temp2 != NULL)
				{
					if(temp2->id != g)
					{
						printf("  %s\n",temp2->name);
					}
					temp2 = temp2->nextvertex;
				}
			}
		temp = temp->nextvertex;	
		return;
		}
	
}
return;
}



int CheckFriend(char name[],int g)
{
	struct FriendList* temp = head2 ;
	struct UserList* temp1 = head;
	
	while(temp1 != NULL)
	{
		if(temp1->id == g)
		{
			if(temp1->nextedge != NULL)
			{
				temp=temp1->nextedge;
				
				while(temp != NULL)
				{
					if (strcmp(temp->name,name)==0)
					{

						return 1;
					}
					
					temp = temp->next;
				}
				
			}
			
		}
		temp1 = temp1->nextvertex;	
	}
	
}

void Deactivate(char password[])
{						
	struct UserList* temp1=head;
	struct UserList* temp2=temp1->nextvertex;
	
	if(strcmp(password, temp1->password)==0)
	
		{
			head=temp1->nextvertex;
			free(temp1);
			temp1->nextedge=NULL;
			printf("\nDeleted Sucessfully.\n\n");
			return;	
		}
		
	else 
			{
				while(temp1->nextvertex != NULL)
				{
          		    if(strcmp(password, temp2->password)==0)
		   				{
		   					temp1->nextvertex=temp2->nextvertex;
							free(temp2);
							temp2->nextedge=NULL;
							printf("\nDeleted Sucessfully.\n\n");
							return;
		  	   		    }
		  	 		else
		   				{
		   					temp1=temp1->nextvertex;
							temp2=temp2->nextvertex;
						
		   				}
           		 }
			}		
}

void displayUserList()
{
	struct UserList* temp;
	temp = head;
	
	if(temp != NULL)
	{
		while( temp!= NULL)
		{
			printf("\nYour name is : %s\n", temp->name);
			temp = temp->nextvertex;
		}
	}
	else
	{
		printf("\nList is empty.\n");
	}
}



int main()
{
		SignUp("hira","hira");
		SignUp("maaz","maaz");
		
		bool b=true;
		bool c=true;
		bool e=true;
		bool f=true;
	do{
		 int choice;
		 printf("\n \n\t\t \t Welcome To Connecting People\t \t \t \t \n \n ");
		 
		 printf("\n \n \t \t \t \t LOGIN \t \t \t \t \n \n");
		 
		 printf("\n1. SignIn - If you are a member of Connecting People.\n");
		 printf("\n2. SignUp - If you are not a member of Connecting People.\n");
		 printf("\n3. Exit.\n\n");
		 scanf("%d",&choice);
		 switch(choice)
		 {
		 	
		 	case 1:
		 	{
				int id;
				char password[50];
				int g;
		 		printf("\nEnter Your Conneting People ID : \n");
		 		scanf("%d",&id);
		 		g = id;
		 		printf("\nEnter Your Password : \n");
		 		scanf("%s",&password);
		 		

				if (SignIn(id,password))
				{
					do
					{
					
					int ch;					
					printf("\n1.Account Features.\n2.Account Settings.\n");
					scanf("%d",&ch);
					switch(ch)
					{
		case 1:	
		{
								
					do
					{
					int choose;
					printf("\n1.Friendlist.\n2.Friend Suggestion.\n3.Search User.\n4.Display User List.\n5.Exit.\n");
					scanf("%d",&choose);
					switch(choose)
					{
						case 1:
							{
								Displayfriends(g);
								break;
							}
						case 2:
							{
								printf("\n\nSuggestions\n\n");
								Suggestion(g);
								break;
							}
						case 3:
							{
								char name[50];
								int chosen;
								printf("\nEnter Username:\n");
								scanf("%s",&name);
								if (SearchFriend(name))
								{
								printf("\n1.AddFriend\n2.Unfriend.\n");
								scanf("%d",&chosen);
								switch(chosen)
								{
									case 1:
										{
											if(CheckFriend(name,g))
											{
												printf("\nAlready Your Friend.\n");
											}
											else
											{
												AddFriend(name,g);
												Add_Friend(name,g);
												printf("\n%s is your new friend.\n",name);
											}
											break;
										}
									case 2:
										{
											if(CheckFriend(name,g))
											{
												UnFriend(g,name);
												Un_Friend(g,name);
												printf("\n%s is no more your friend.\n",name);
											}
											else
											{
												printf("\nAlready Not A Friend.\n");
											}
											break;
										}
									
								}
								}
								else
								{
									printf("\nUser Not Found.\n");
								}
								break;
							}
							
							case 4:
								{
				
									displayUserList();
									break;
								}
							
							case 5:
								{
									c = false;
								}
								
							
					}
				}while (c == true);
				break;
			}
				case 2:
					{
						do
								{
								
								int choice1;
								printf("\n1.Deactivate.\n2.Logout.\n");
								scanf("%d",&choice1);
								switch(choice1)
								{
									case 1:
										{
											char pwd[50];
											printf("\nEnter your password to deactivate account:\n");
											scanf("%s",&pwd);
											Deactivate(pwd);
												e = false;
												f = false;
												c = false;
							
											break;
										}
									case 2:
										{
											e = false;
											f = false;
											break;
										}
								}
								} while(e == true);
								
								break;
					}
				}
			}while(f==true);
		}
				else
				{
					printf("\nIncorrect Password or ID.\n");
				}
				break;
		 	}
		 	
		 	case 2:
		 	{
			char name[50]; char password[50];
		 		
				printf("\nEnter your name: \n");
		 		scanf ("%s",&name);
		 		
				printf("\nEnter Password: \n");
				scanf("%s",&password);
				
				SignUp(name , password);
				printf("\n\t\tThankyou For Registering on Connecting People.\t\t\n");
				
				printf("\t\t\t\t   Please SignIn.\n\n");
				int id;
				int g;
		 		printf("\nEnter Your Conneting People ID : \n");
		 		scanf("%d",&id);
		 		g = id;
		 		printf("\nEnter Your Password : \n");
		 		scanf("%s",&password);
		 		

					if (SignIn(id,password))
				{
					do
					{
					
					int ch;					
					printf("\n1.Account Features.\n2.Account Settings.\n");
					scanf("%d",&ch);
					switch(ch)
					{
		case 1:	
		{
								
					do
					{
					int choose;
					printf("\n1.Friendlist.\n2.Friend Suggestion.\n3.Search User.\n4.Display User List.\n5.Exit.\n");
					scanf("%d",&choose);
					switch(choose)
					{
						case 1:
							{
								Displayfriends(g);
								break;
							}
						case 2:
							{
								printf("\n\nSuggestions.\n\n");
								Suggestion(g);
								break;
							}
						case 3:
							{
								char name[50];
								int chosen;
								printf("\nEnter Username:\n");
								scanf("%s",&name);
								if (SearchFriend(name))
								{
								printf("\n1.AddFriend\n2.Unfriend.\n");
								scanf("%d",&chosen);
								switch(chosen)
								{
									case 1:
										{
											if(CheckFriend(name,g))
											{
												printf("\nAlready Your Friend.\n");
											}
											else
											{
												AddFriend(name,g);
												Add_Friend(name,g);
												printf("\n%s is your new friend.\n",name);
											}
											break;
										}
									case 2:
										{
											if(CheckFriend(name,g))
											{
												UnFriend(g,name);
												Un_Friend(g,name);
												printf("\n%s is no more your friend.\n",name);
											}
											else
											{
												printf("\nAlready Not A Friend.\n");
											}
											break;
										}
									
								}
								}
								else
								{
									printf("\nUser Not Found.\n");
								}
								break;
							}
							
							case 4:
								{
				
									displayUserList();
									break;
								}
							
							case 5:
								{
									c = false;
								}
								
							
					}
				}while (c == true);
				break;
			}
				case 2:
					{
						do
								{
								
								int choice1;
								printf("\n1.Deactivate.\n2.Logout.\n");
								scanf("%d",&choice1);
								switch(choice1)
								{
									case 1:
										{
											char pwd[50];
											printf("\nEnter your password to deactivate account:\n");
											scanf("%s",&pwd);
											Deactivate(pwd);
												e=false;
												c=false;
												f=false;
							
											break;
										}
									case 2:
										{
											e=false;
											c=false;
											f=false;
											break;
										}
								}
								} while(e == true);
								
								break;
					}
				}
			}while(f==true);
		}
				else
				{
					printf("\nIncorrect Password or ID.\n");
				}
				break;
		 	}
		 	
			
			case 3:
			{
			
				b = false;
				break;
			}
		 }
		 
	}while(b == true);

}
