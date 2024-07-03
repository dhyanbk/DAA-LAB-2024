#include<stdio.h>
#include<stdlib.h>
int count = 0,x[5];
void n_queen(int , int);
int place(int , int);
int main()
{
	int n;
	printf("Enter the number of queens:\n");
	scanf("%d",&n);
	n_queen(1,n);
	if(count == 0)
		printf("No solution are forund.\n");
	else
	printf("Number of selections found are:%d\n",count);
	return 0;
}
int place(int k, int i)
{
	int j;
	for(j=1;j<k;j++)
		if((x[j] == i) || ((abs(x[j]-i)) == (abs(j-k))))
			return 0;
	return 1;
}

void n_queen(int k,int n)
{
	int i,j,p;
	for(i=1;i<=n;i++)
	{
		if(place(k,i))
		{
			x[k]=i;
			if(k == n)
			{
				count ++;
				printf("Solution %d\n", count);
				for(j=1;j<=n;j++)
				{
					for(p=1;p<=n;p++)
					
						if(x[j] == p)
							printf("$ \t");
						else
							printf("0 \t");
						printf("\n");
					
				}
					printf("\n");
			}
			else
				n_queen(k+1,n);
		}
	}
}

			
						
	
	
		
