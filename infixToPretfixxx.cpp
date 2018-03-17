#define SIZE 50           
#include<string.h>
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
    case ')': return 1;
    case '+': return 1;
    case '-': return 2;
    case '*': return 2;
    case '/': return 3;
    }
}
 
main()
{                         
    char infx[50],prfx[50],ch,elem;
    int i=0,k=0;
    printf("\n\nEnter the Infix Expression ? ");
    scanf("%s",infx);
    push('#');
    strrev(infx);
    while( (ch=infx[i++]) != '\0')
    {
        if( ch == ')') push(ch);
        else
            if(isalnum(ch)) prfx[k++]=ch;
            else
                if( ch == '(')
                {
                    while( s[top] != ')')
                        prfx[k++]=pop();
                    elem=pop(); 
                }
                else
                {       
                    while( preferrence(s[top]) >= preferrence(ch) )
                        prfx[k++]=pop();
                    push(ch);
                }
    }
    while( s[top] != '#')    
        prfx[k++]=pop();
    prfx[k]='\0';          
    strrev(prfx);
    strrev(infx);
    printf("\n\nGiven Infix Expn: %s  Prefix Expn: %s\n",infx,prfx);
}
