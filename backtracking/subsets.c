#include<stdio.h>
#include<string.h>
void subset(int,int);
void display();
int x[10],count;
char str[10];
int main()
{
  int n;
  printf("enter string \n");
  scanf("%s",str);
  n=strlen(str);
  subset(0,n-1);
  printf("%d",count);
  return 0;
}
void subset(int k,int n)
{
  if(k==n)
   {
     x[k]=1;
    display(n);
     count++; //printf("%c",str[k]);
    x[k]=0;
     display(n);
      count++;
     //printf("\n%d\n",count++);
     return;
   }
  
// else
 //  {
    x[k]=1;
    
    subset(k+1,n);
    
    x[k]=0;
    subset(k+1,n);
  // }
  return;
}

void display(int n)
{
  int i;
  //count++;
  for(i=0;i<=n;i++)
   {
     if(x[i]==1)
        printf("%c",str[i]);
   }
  printf("\n");
}
