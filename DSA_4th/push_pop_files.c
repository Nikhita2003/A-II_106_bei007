#include<stdio.h>
#include<stdlib.h>
#define MAX 12
int top=-1;//pointer
int stack[MAX];
FILE* fp;
FILE* file;
void push()
{
    int elem;
   fscanf(fp,"%d",&elem);
    stack[++top]=elem;
}
void pop()
{
    printf("%d is poped\n",stack[top]);
    fprintf(file,"%d\n",2*stack[top]);
    top--;
}
void pushback()
{
   int elem;
   fscanf(file,"%d",&elem);
   if(elem==0)
   {
       rewind(file);
   }
   printf("THE ELEMENT IS %d\n",elem);
    stack[++top]=elem;

}
void display()
{
    for (int i=0;i<=top;i++)
    {
        printf("%d ",stack[i]);
    }
    printf("\n");
}
int main()
{

fp=fopen("read.txt","w");
file = fopen( "write.txt" , "rb+");
    printf("THESE ARE STACK BASIC OPERATIONS\n");
    int oper;
while(1)
{
        printf("ENTER YOUR CHOICE\n1:PUSH\n2:POP\n3:DISPLAY\n4EXIT\n5PUSHBACK");
        scanf("%d",&oper);
        switch(oper)
        {

        case 1 :
            push();
            break;
        case 2 :
            pop();
            break;

        case 3 :
            display();
            break;
        case 4 :
            exit(0);
            break;
        case 5 :
            pushback();
            break;
        default:
            printf("ENTER THE VALID CHOICE\n");
        }
}
}
