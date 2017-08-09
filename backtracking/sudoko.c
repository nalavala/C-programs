#include<stdio.h>
void display();
int checkrow(int row,int num);
int checkcol(int col,int num);
void navigate(int row,int col);
void solve(int row,int col);
int sud[20][20],n;
int main()
{
 int i,j;
 printf("enter order\n");
 scanf("%d",&n);
 for(i=0;i<n;i++)
   for(j=0;j<n;j++)
      scanf("%d",&sud[i][j]);
 solve(0,0);
}

void solve(int row,int col)
{
  int cr;
  if(row>n-1)
    display();
  if(sud[row][col]!=0)
    navigate(row,col);
   else 
   {
     for(cr=1;cr<=n;cr++)
      {  
     if(checkrow(row,cr)==1&&checkcol(col,cr)==1)
       {
         sud[row][col]=cr;
         navigate(row,col);
       }
      }
    sud[row][col]=0;
  
 }
}

void navigate(int row,int col)
{
  if(col<n-1)
    solve(row,col+1);
  else
    solve(row+1,0);
} 
int checkrow(int row,int num)
{  
  int i;
  for(i=0;i<n;i++)
      if(sud[row][i]==num)
         return 0;
  return 1;
}
int checkcol(int col,int num)
{
  int i;
  for(i=0;i<n;i++)
     if(sud[i][col]==num)
           return 0;
  return 1;
} 
void display()
{
  int i,j;
  for(i=0;i<n;i++)
      {
         for(j=0;j<n;j++)
          {
             printf("%d\t",sud[i][j]);
           }
        printf("\n");
      }
}
