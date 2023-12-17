#include<stdio.h>
#include<stdlib.h>

#define cap 5

void bft(int ajdMat[][cap],int visited[],int s)
{
    int q[cap],f=-1,r=-1;
  for(int i=0;i<cap;i++)
  {
    visited[i]=0;
  }
    ++r;
    ++f;
    q[r]=s;
    visited[s]=1;

    while (r>=f)
    {
        s=q[f++];
        printf("%c ",s+65);
        for(int i=0;i<cap;i++)
        {
            if(ajdMat[s][i]==1 && visited[i]==0)
            {
                q[++r]=i;
                visited[i]=1;
            }
        }
    }
     
}
void dft(int ajdMat[][cap],int visited[],int s)
{
    int st[cap],t=-1;
  for(int i=0;i<cap;i++)
  {
    visited[i]=0;
  }
    st[++t]=s;
    visited[s]=1;

    while (t!=-1)
    {
        s=st[t--];
        printf("%c ",s+65);
        for(int i=0;i<cap;i++)
        {
            if(ajdMat[s][i]==1 && visited[i]==0)
            {
                st[++t]=i;
                visited[i]=1;
            }
        }
    }
    

}


int main()

{
    int m,n;
    int v[cap]={0};
    int adjMat[cap][cap];
    int choice;

    printf("\nEnter the values in adjacency matrix :\n");
    for(int i=0;i<cap;i++)
    {
        for(int j=0;j<cap;j++)
        {
            scanf("%d" ,&adjMat[i][j]);
        }
    }
while (1)
{
   printf("\nGraph Treversals\n");
   printf("1.bfs\n");
   printf("2.dfs\n");
   printf("3.Exit\n");

printf("\nEnter the Choice :\n");
scanf("%d", &choice);

    switch (choice)
    {
    case 1:
    
    printf("\nEnter the starting node :\n");
    scanf("%d",&m);

        bft(adjMat,v,m);
        break;

    case 2:
       
    printf("\nEnter the starting node :\n");
    scanf("%d",&n);
    dft(adjMat,v,n);
        break;

    case 3:
       exit(0);
       break;

    default:
      printf("\nPlease Enter Correct Choice !!!\n");
        break;
    }


}







    return 0;
}