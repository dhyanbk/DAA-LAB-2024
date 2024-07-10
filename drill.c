#include<stdio.h>
int a[10][10] , visited[10] , n , cost = 0;
int least(int c);
void mincost(int city)
{
	int i , ncity;
	visited[city] = 1;
	printf("%d-->",city);
	ncity = least(city);
	if(ncity == 999)
	{
		ncity = 1;
		printf("%d" , ncity);
		cost += a[city][ncity];
		return;
	}
	mincost(ncity);
}
int least(int c)
{
	int i,nc = 999;
	int min = 999,kmin;
	for(i = 1;i <= n;i++)
	{
		if((a[c][i] != 0) && (visited[i] == 0))
			if(a[c][i] < min)
			{
				min = a[i][1] + a[c][1];
			    	kmin = a[c][i];
				nc = i;
			}
	}
	if(min != 999)
		cost += kmin;
		return nc;
}
void main()
{
	int i,j;
	printf("Enter No. of cities:\n");
	scanf("%d",&n);
	printf("Enter the cost matrix:\n");
	for(i = 1;i <=n;i++)
	{
		printf("Enter elements of row:%d\n",i);
		for(j=1;j<=n;j++)
		scanf("%d",&a[i][j]);
		visited[i]=0;
	}
	printf("The cost list is \n");
	for(i=1;i<=n;i++)
	{
		printf("\n\n");
		for(j = 1;j <= n;j++)
		printf("\t%d",a[i][j]);
	}
	printf("\n\n The path is:\n");
	mincost(1);
	printf("\n\n minimun cost:");
	printf("%d \n",cost);
}
		
	
	
