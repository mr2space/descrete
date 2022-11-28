#include <stdio.h>

int inputSet(int *arr);
int dublicateCheck(int arr[], int len, int ele);
int display(int arr[], int len);
int unionOp(int arr1[], int len1, int arr2[], int len2, int *result);
int intersectionOp(int arr1[], int len1, int arr2[], int len2, int *result);
int subtraction(int arr1[], int len1, int arr2[], int len2, int *result);
int setMultiplication(int arr1[], int len1, int arr2[], int len2);
int *BinaryConverter(int binary[], int size, int number);
int power(int base, int exponent);
int powerSet(int arr[], int len);

int main()
{
    int set1[100], set2[100], result[300];
    // taking value in two set
    int num1 = inputSet(set1);
    int num2 = inputSet(set2);
    int out[num1];
    // displaying value of set
    printf("first set \n");
    display(set1, num1);
    printf("\n");
    printf("second set \n");
    display(set2, num2);
    printf("\n");
    unionOp(set1,num1,set2,num2,result);
    intersectionOp(set1,num1,set2,num2,result);
    subtraction(set1,num1,set2,num2,result);
    printf("subtraction B - A \n");
    subtraction(set2, num2,set1, num1, result);
    setMultiplication(set1, num1, set2, num2);
    powerSet(set1, num1);
    return 0;
}
int display(int arr[], int len)
{
    for (int i = 0; i < len; ++i)
    {
        printf("%3d", *(arr + i));
    }
    return 0;
}

int dublicateCheck(int arr[], int len, int ele)
{
    for (int i = 0; i < len; ++i)
    {
        if (arr[i] == ele)
            return 0;
    }
    return 1;
}

int inputSet(int *arr)
{
    int ele, num;
    printf("enter number of element: ");
    scanf("%d", &num);
    for (int i = 0; i < num; i)
    {
        printf("enter element: ");
        scanf("%d", &ele);
        if (dublicateCheck(arr, num, ele) == 0)
            continue;
        *(arr + i) = ele;
        ++i;
    }
    return num;
}

int unionOp(int arr1[], int len1, int arr2[], int len2, int *result)
{
    int counter;
    for (int i = 0; i < len1; ++i)
    {
        *(result + i) = arr1[i];
    }
    counter = len1;
    int pos = 0, i;
    for (pos = 0; pos < len2; pos++)
    {
        if (dublicateCheck(result, counter, arr2[pos]) == 0)
            continue;
        *(result + counter) = arr2[pos];
        counter++;
    }
    printf("union operation \n");
    display(result, counter);
    printf("\n");
}

int intersectionOp(int arr1[], int len1, int arr2[], int len2, int *result)
{
    int pos = 0, i = 0;
    for (pos = 0; pos < len2; pos++)
    {
        if (dublicateCheck(arr1, len1, arr2[pos]) == 0)
        {
            *(result + i) = arr2[pos];
            ++i;
            continue;
        }
    }
    printf("intersection operation \n");
    display(result, i);
    printf("\n");
}

int subtraction(int arr1[], int len1, int arr2[], int len2, int *result)
{
    int pos = 0, i = 0;
    for (pos = 0; pos < len2; pos++)
    {
        if (dublicateCheck(arr2, len2, arr1[pos]) == 0)
        {
            continue;
        }
        *(result + i) = arr1[pos];
        ++i;
    }
    if (pos <= len1)
    {
        for (pos; pos <= len2; pos++)
        {
            *(result + i) = arr1[pos];
            ++i;
        }
    }
    printf("subtraction operation \n");
    display(result, i);
    printf("\n");
}

int setMultiplication(int arr1[], int len1, int arr2[], int len2)
{
    int result[300][2];
    int i, j, pos = 0;
    for (i = 0; i < len1; i++)
    {
        for (j = 0; j < len2; j++)
        {
            result[pos][0] = *(arr1 + i);
            result[pos][1] = *(arr2 + j);
            pos++;
        }
    }
    printf("cardinality of set A and B \n");
    for (i = 0; i < pos; i++)
    {
        printf(" (%d, %d)", result[i][0], result[i][1]);
    }
    printf("\n");
    return pos;
}

struct powerset
{
    int size;
    int arr[100];
};

int *BinaryConverter(int binary[], int size, int number)
{
    int pos = size - 1;
    int i;
    for (i = 0; i < size; i++)
    {
        binary[i] = 0;
    }

    while (number > 0)
    {
        // printf("run count \n");
        binary[pos] = number % 2;
        number = number / 2;
        pos--;
    }
    return binary;
}

int power(int base, int exponent)
{
    int number = 1;
    while (exponent > 0)
    {
        number = number * base;
        exponent--;
    }
    return number;
}

int sizeCounter(int arr[], int len)
{
    int counter = 0;
    int i;
    for (i = 0; i < len; i++)
    {
        if (*(arr + i) == 1)
        {
            counter++;
        }
    }
    return counter;
}



int powerSet(int arr[], int len)
{   int l,j;
    int loop_time = power(2, len);
    struct powerset result[loop_time];
    int loop = 0, pos;
    int binary[len];
    while (loop < loop_time)
    {
        pos = 0;
        BinaryConverter(binary, len, loop);
        result[loop].size = sizeCounter(binary, len);
        for (pos = 0; pos < len; pos++)
        {
            if (*(binary + pos) == 1)
            {
                printf("%3d ", *(arr + pos));
                result[loop].arr[pos] = arr[pos];
            }
        }
        printf("\n");
        loop++;
    }
    for (int i = 0; i < loop_time;i++){
        j = 0;
    while (j < result[l].size)
    {
        printf("%3d ", result[l].arr[j], l, j);
        j++;
            }
        printf("\n");
    }
}
