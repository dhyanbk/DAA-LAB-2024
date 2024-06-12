#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void selectionSort(int arr[],int n)
{
   int i,j,minIndex,temp;
   for(i=0;i<n-1;i++)
   {
      minIndex=i;
      for(j=i+1;j<n;j++)
      {
         if(arr[j]<arr[minIndex])
         minIndex=j;
      }
      temp=arr[minIndex];
      arr[minIndex]=arr[i];
      arr[i]=temp;
      }
}
void printArray_beforesort(int arr[],int size)
{
   int i;
   for(i=0;i<size;i++)
   {
      printf("%d ",arr[i]);
   }
   printf("\n");
}
void printArray_aftersort(int arr[],int size)
{
   int i;
   for(i=0;i<size;i++)
   {
      printf("%d ",arr[i]);
   }
   printf("\n");
}
int main()
{
   int arr[10000],n,i;
   double time_taken;
   clock_t start,end;
   printf("enter the number of elements \n");
   scanf("%d",&n);
   for(i=0;i<n;i++)
      arr[i]=rand()%10000;
   printf("\nelements before sorting \n");
   printArray_beforesort(arr,n);
   start=clock();
   selectionSort(arr,n);
   end=clock();
   printf("\nelements after sorting \n");
   printArray_aftersort(arr,n);
   time_taken=((double)(end-start))/CLOCKS_PER_SEC*1000;
   printf("\ntime taken to sort elements=%lf \n",time_taken);
   return 0;
}
   
