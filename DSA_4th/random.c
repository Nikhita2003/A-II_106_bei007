#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    int num;
    int l=250,u=350;
    FILE*fp;
    fp=fopen("Gen.txt","w");
    {
        srand(time(NULL));
        num=(rand()%(u-l+1))+l; // To get num from 0-__ divide by that number,to get between some range than initialize the range
        fprintf(fp,"%d\n",num);
    }
    fclose(fp);

}

