#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
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
}
void quicksort(int array[], int begin, int end)
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
        quicksort(array, begin, i-1);
        quicksort(array, j, end);
    }
}
int main()
{
    int array[5];
    printf("请输入5个数\n");
    for(int i=0;i<5;i++)
        scanf("%d",&array[i]);
    int len=5;
    printf("排序前的数组\n");
    display(array, len);
    quicksort(array, 0, len-1);
    printf("排序后的数组\n");
    display(array, len);
    return 0;
}
