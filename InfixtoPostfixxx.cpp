#define SIZE 50            
#include <ctype.h>
#include<stdio.h>
#include<conio.h>
char s[SIZE];
int top=-1;       
 
push(char x)
{                       
    s[++top]=x;
}
 
char pop()
{                      
    return(s[top--]);
}
 
int preferrence(char x)
{                 
    switch(x)
    {
    case '#': return 0;
    case '(': return 1;
    case '+': return 2;
    case '-': return 2;
    case '*': return 3;
    case '/': return 3;
    }
}
 
main()
{                         
    char infx[50],pofx[50],ch,elem;
    int i=0,k=0;
    printf("\n\nEnter the Infix Expression ? ");
    scanf("%s",infx);
    push('#');
    while( (ch=infx[i++]) != '\0')
    {
        if( ch == '(') push(ch);
        else
            if(isalnum(ch)) pofx[k++]=ch;
            else
                if( ch == ')')
                {
                    while( s[top] != '(')
					{
                        pofx[k++]=pop();
                 	}
                    elem=pop(); 
                }
                else
                {       
                    while( preferrence(s[top]) >= preferrence(ch) )
                    {
                        pofx[k++]=pop();
                    }
                    push(ch);
                }
    }
    while( s[top] != '#')  
    {
	    pofx[k++]=pop();
	}
	pofx[k]='\0';          
    printf("\n\nGiven Infix Expn: %s  Postfix Expn: %s\n",infx,pofx);
}
