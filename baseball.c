#include<stdio.h>
int n,cost[10][10],dist[10];
void readmatrix(int);
int min(int,int);
void shortest_path(int,int);
int main()
   {
      int i,s;
      printf("Enter the number of vertices:\n");
      scanf("%d",&n);
      printf("Enter the cost adjacency matrix(999 for infinite ):\n");
      readmatrix(n);
      printf("Enter the source vertex:\n");
      scanf("%d",&s);
      shortest_path(n,s);
      for(i=1;i<=n;i++)
         printf("The shortest path between the vertex %d to %d is %d. \n",s,i,dist[i]);
      return 0;
   }
int min(int a,int b)
   {
      return a>b?b:a;
   }
void readmatrix(int n)
   {
      int i,j;
      for(i=1;i<=n;i++)
         for(j=1;j<=n;j++)
            {
               printf("(%d,%d):",i,j);
               scanf("%d",&cost[i][j]);
               if(cost[i][j]==0)
                  cost[i][j]=999;
            }
   }
void shortest_path(int n,int s)
   {
      int vis[10],c,u,i,k;
      for(i=1;i<=n;i++)
         {
            vis[i]=0;
            dist[i]=cost[s][i];
         }
            dist[s]=0;
            vis[s]=1;
            for(k=1;k<=n;k++)
               {
                  c=999;
                  for(i=1;i<=n;i++)
                     if(vis[i]==0)
                        {
                           if(dist[i]<=c)
                              {
                                 c=dist[i];
                                 u=i;
                              }
                        }
                  vis[u]=1;
                  for(i=1;i<=n;i++)
                     dist[i]=min(dist[i],dist[u]+cost[u][i]);
               }
   }

                    
