#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct NODE
{
    int data;
    struct NODE *next;
};
typedef struct NODE *node;
node head=NULL,temp,temp2;
node insert(FILE *fp,int n)
{
    int d;
    for(int i=0;i<n;i++)
    {
        fscanf(fp,"%d",&d);
        node newnode=(node)malloc(sizeof(struct NODE));
        newnode->data=d;
        newnode->next=NULL;
        if(head==NULL)
        {
            head=newnode;
        }
        else
        {
            temp=head;
            head=newnode;
            head->next=temp;
        }
    }
}
void sort()
{
    int x;
    temp2=head;
    while(temp2->next!=NULL)
    {
        temp=head;
        while(temp->next!=NULL)
        {
            if(temp->data > temp->next->data)
            {
                 x=temp->data;
                temp->data=temp->next->data;
                temp->next->data=x;
            }
            temp=temp->next;
        }
        temp2=temp2->next;
    }
}
void rad(FILE *fp,int n)
{
    for(int i=0;i<n;i++)
    {
        fprintf(fp,"%d\t",rand()%100);
    }
}
void display(node head,FILE *fp)
{
    temp=head;
    while(temp!=NULL)
    {
        fprintf(fp,"%d ",temp->data);
        temp=temp->next;
    }
}
void main()
{
    int n;
    FILE *fp;
    double start,stop;
    printf("Enter the range: ");
    scanf("%d",&n);
    fp=fopen("array.txt","w");
    rad(fp,n);
    fclose(fp);
    fopen("array.txt","r");
    insert(fp,n);
    start=clock();
    sort();
    stop=clock();
    fclose(fp);
    fp=fopen("array1.txt","w");
    display(head,fp);
    fprintf(fp,"\nTime taken: %lf",(stop-start)/CLOCKS_PER_SEC);
    fclose(fp);
}
