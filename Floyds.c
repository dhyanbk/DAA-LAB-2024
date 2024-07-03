#include<stdio.h>
#include<omp.h>
#include<time.h>
int min(int,int);
void floyd(int[][10],int);
int main()
{
	int a[10][10],n,i,j;
	clock_t start,end;
	printf("\nEnter the number of vertices\n");
	scanf("%d",&n);
	printf("Enter the cost matrix\n");
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	start = clock();
	floyd(a,n);
	end = clock();
	printf("Shortest path matrix is \n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			printf("%d\t",a[i][j]);
			printf("\n");
	}
	printf("Time taken is %lf\n",(double)(end-start));
	return 0;
}
int min(int a,int b)
{
	return (a<b?a:b);
}
void floyd(int w[10][10], int n){
int i,j,k;
for(k=1;k<=n;k++)
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			w[i][j] = min(w[i][j],w[i][k]+w[k][j]);
}

