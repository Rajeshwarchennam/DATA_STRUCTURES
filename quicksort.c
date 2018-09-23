#include<stdio.h>
void swap(int *a,int *b)
{
  int t=*a;
  *a=*b;
  *b=t;
}
int partition (int a[],int start, int end)
{
  int pivot =a[end];
  int p_index=start;
  for (int i=start;i<=(end-1);i++)
  { if (a[i]<=pivot)
    {
      swap(&a[i],&a[p_index]);
      p_index++;
    }

  }
  swap(&a[p_index],&a[end]);
  return p_index;
}
void quicksort(int a[],int start ,int end)
{
  if (start<end)
  {
    int p_index=partition(a,start,end);
    quicksort(a,start,p_index-1);
    quicksort(a,p_index+1,end);

  }
}
void print_array(int a[],int n )
{
  for (int i=0;i<n;i++)
  {
    printf("%d \t",a[i]);
  }
}
int main()
{
  int a[10]={2,34,43,534,23342,23,34,54,23,354};
  quicksort(a,0,9);
  print_array(a,10);
  return 0;
}
