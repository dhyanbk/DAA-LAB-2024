#include<stdio.h>
int v[20][20];
int max_value(int,int);
int main()
	{
	int i,j,p[20],w[20],n,max;
	printf("Enter the number of items:");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		{
		printf("Enter the weight and profit of the item %d:",i);
		scanf("%d%d",&w[i],&p[i]);
	        }
	printf("\nEnter the capacity of knapsack:\n");
	scanf("%d",&max);
	for(i=0;i<=n;i++)
		v[i][0]=0;
	for(i=0;i<=max;i++)
		v[0][i]=0;
	for(i=1;i<=n;i++)
		for(j=1;j<=max;j++)
		{
		if(w[i]>j)
			v[i][j]=v[i-1][j];
		else
			v[i][j]=max_value(v[i-1][j],v[i-1][j-w[i]]+p[i]);
		}
		printf("The table is:\n");
		for(i=0;i<=n;i++)
		{
			for(j=0;j<=max;j++)
				printf("%d\t",v[i][j]);
			printf("\n");
		}
		printf("The max profit is %d",v[n][max]);
		printf("\nThe most portable subset is:{");
		j=max;
		for(i=n;i>=1;i--)
			if(v[i][j]!=v[i-1][j])
				{
				printf("item%d:1\t",i);
				j=j-w[i];
				}
			else
				printf("item%d:0\t",i);
			printf("}\n");
			return 0;
		}
int max_value(int a,int b)
	{
	return (a>b?a:b);
	}
		
		 
