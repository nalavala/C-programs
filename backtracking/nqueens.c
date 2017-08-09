#include<stdio.h>
#include<stdlib.h>
void queen();
int place(int);
void print();
int n,x[10],count;
int main()
{
 printf("enter no of queens\n");
 scanf("%d",&n);
 if(n<=3)
   exit(0);
 queen();
}
void queen()
{
  
  int i=1;
  x[i]++;
  while(i!=0)
    {
      x[i]++;
      while(x[i]<=n&&!place(i))
        {
          x[i]++;
        }
      if(x[i]<=n)
        {
          if(i==n)
             {
               count++;
               print();
             }
           else
             i++,x[i]=0;
        }
      else
        i--;
    }
}
int place(int i)
{
  int k;
  for(k=1;k<i;k++)
    if(x[k]==x[i]||k-x[k]==i-x[i]||k+x[k]==i+x[i])
        return 0;
  return 1;
}
void print()
{
  int k,j; 
  printf("solution no:%d\n",count);
  for(k=1;k<=n;k++)
     printf("%d",x[k]);
  printf("\n");
  for(k=1;k<=n;k++)
    {
     for(j=1;j<=n;j++)
       {
         if(x[k]==j)
           printf("q%d",k);
         else 
           printf("--");
       }
     printf("\n");
   }
}

