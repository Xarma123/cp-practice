
#include <ctype.h>
#include <stdio.h>
#define SIZE 100 

char s[SIZE];
int top = -1; 

/* Function to remove spaces from given string */
void RemoveSpaces(char* source) {
 char* i = source;
 char* j = source;
 while(*j != 0) {
 *i = *j++;
 if(*i != ' ')
 i++;
 }
 *i = 0;
}

// Function for PUSH operation 
void push(char elem) { 
 s[++top] = elem;
}

//  Function for POP operation 
char pop() 
{ 
 return (s[top--]);
}

//  Function for precedence 
int pr(char elem) 
{ 
 switch (elem) {
 case '#':
    return 0;
 case '(':
    return 1;
 case '+':
    case '-':
        return 2;
 case '*':
    case '/':
        return 3;
 }
 return 0;
}


//  Function to convert from infix to postfix expression

void infix_to_postfix(char *infix, char *postfix) {
 char ch, elem;
 int i = 0, k = 0;
 
 RemoveSpaces(infix);
 push('#');
 
 while ((ch = infix[i++]) != '\n') 
 {
 if (ch == '(')
 push(ch);
 else if (isalnum(ch))
 postfix[k++] = ch;
 else if (ch == ')') 
 {
 while (s[top] != '(')
 postfix[k++] = pop();
 elem = pop();
 } 
 else 
 { 
    while (pr(s[top]) >= pr(ch))
    postfix[k++] = pop();
    push(ch);
 }
 }
 
 while (s[top] != '#') 
 postfix[k++] = pop();
 
 postfix[k] = '\0';
}


// Function to evaluate a postfix expression

int eval_postfix(char *postfix) 
{
 char ch;
 int i = 0, op1, op2;
 while((ch = postfix[i++]) != 0) 
 {
 if(isdigit(ch)) 
 push(ch-'0'); 
 else { 
 op2 = pop();
 op1 = pop();
 switch(ch) 
 {
 case '+' : 
 push(op1+op2); 
 break;
 case '-' : 
 push(op1-op2); 
 break;
 case '*' : 
 push(op1*op2);
 break;
 case '/' : 
 push(op1/op2);
 break;
 }
 }
 }
 return s[top];
}

int main() 
{ 
 
 char infx[50], pofx[50];
 printf("\nEnter the infix expression: ");
 fgets(infx, 50, stdin);
 
 infix_to_postfix(infx, pofx);

 printf("\nThe Postfix Expression after conversion from infix looks like this : %s", pofx);
 top = -1;
 printf("\nResult of evaluation of postfix expression : %d", eval_postfix(pofx));
}