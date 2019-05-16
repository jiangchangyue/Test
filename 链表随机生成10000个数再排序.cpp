#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
void display(int array[], int len)
{
    int i;
    for(i=0; i<len;i++)
    {
        printf("%d ",array[i]);
    }
    printf("\n");
    return ;
}
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
    return ;
}
void quicksort(int array[], int len, int begin, int end)
{
    int i,j;
    if(begin < end)
    {
        i = begin + 1;
        j = end;
        while(i < j)
        {
            if(array[i] > array[begin])
            {
                swap(&array[i], &array[j]);
                j--;
            }
            else
            {
                i++;
            }
        }
        if(array[i] >= array[begin])
        {
            i--;
        }
        swap(&array[begin], &array[i]);
        quicksort(array, len, begin, i);
        quicksort(array, len, j, end);
    }
}
int srand()
{
    int x=rand();
    return x;
}
int a[10000];
int main()
{
    srand(time(NULL));
    for(int i=0;i<10000;i++)
        a[i]=rand();
    quicksort(a, 10000, 0, 9999);
    printf("排序后的数组\n");
    display(a, 10000);
}
