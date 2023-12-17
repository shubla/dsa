#include<stdio.h>
#include<math.h>
#include<ctype.h>
double stack[30];
int top=-1;

void push(double x)
{
    stack[++top]=x;
}

double pop()
{
    if(top==-1)
    {      
    return -1;
    }

return stack[top--];
}


int main()
{
    char exp[30];
    char *ptr;
    double x,y;
    double res=0.0;
    printf("Enter The Postfix Expression :");
    scanf("%s",exp);
    ptr=exp;
    while(*ptr!='\0')
    {
        if(isalnum(*ptr))
        {
            push((double)(*ptr-'0'));
        }

        else
        {
            x=pop();
            y=pop();
            if(*ptr=='*')
            {
                push(y*x);
            }

            else if(*ptr=='+')
            {
                push(y+x);
            }

            else if(*ptr=='-')
            {
                push(y-x);
            }

            else if(*ptr=='/')
            {
                if(y==0)
                {
                    printf("Division by zero\n");
                    return -1;
                }
                push(y/x);
            }
            else if(*ptr=='^')
            {
                push(pow(y,x));
            }
        }

        ptr++;
    }

    printf("The Evaluation Is:%lf ",pop());


    return 0;
}