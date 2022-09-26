#include<stdio.h>

int inputSet(int *arr);
int dublicateCheck(int arr[],int len,int ele);
int unionOp(int arr1[],int len1,int arr2[],int len2,int *result);
int intersectionOp(int arr1[],int len1,int arr2[],int len2,int *result);
int subtraction(int arr1[],int len1,int arr2[],int len2,int *result);


int main(){
    int set1[100],set2[100],result[300];
    // taking value in two set
    int num1 = inputSet(set1);
    int num2 = inputSet(set2);

    // displaying value of set
    printf("first set \n");
    for(int i=0; i<num1;++i){
        printf("%3d",*(set1 + i));
    }
    printf("\n");
    printf("second set \n");
    for(int i=0; i<num2;++i){
        printf("%3d",*(set2 + i));
    }
    printf("\n");
    unionOp(set1,num1,set2,num2,result);
    intersectionOp(set1,num1,set2,num2,result);
    subtraction(set1,num1,set2,num2,result);

    return 0;
}


int dublicateCheck(int arr[],int len,int ele){
    for(int i=0;i<len;++i){
        if(arr[i] == ele) return 0;
    }
    return 1;
}

int inputSet(int *arr){
    int ele, num;
    printf("enter number of element: ");
    scanf("%d",&num);
    for(int i=0; i<num;i){
        printf("enter element: ");
        scanf("%d",&ele);
        if (dublicateCheck(arr,num,ele)==0) continue;
        *(arr + i) = ele;
        ++i;
    }
    return num;
}


int unionOp(int arr1[],int len1,int arr2[],int len2,int *result){
    int counter;
    for(int i =0;i<len1;++i){
        *(result + i) = arr1[i];
    }
    counter = len1;
    int pos = 0,i;
    for(pos = 0;pos < len2;pos++){
        if (dublicateCheck(result,counter,arr2[pos])==0) continue;
        *(result + counter) = arr2[pos];
        counter++;
    }
    printf("union operation \n");
    for(int m=0; m<counter;++m){
        printf("%3d",*(result + m));
    }
    printf("\n");
}


int intersectionOp(int arr1[],int len1,int arr2[],int len2,int *result){
    int pos = 0,i=0;
    for(pos = 0;pos < len2;pos++){
        if (dublicateCheck(arr1,len1,arr2[pos])==0){
            *(result + i) = arr2[pos];
            ++i;
            continue;
        }
    }
    printf("intersection operation \n");
    for(int m=0; m<i;++m){
        printf("%3d",*(result + m));
    }
    printf("\n");
}

int subtraction(int arr1[],int len1,int arr2[],int len2,int *result){
        int pos = 0,i=0;
    for(pos = 0;pos < len2;pos++){
        if (dublicateCheck(arr2,len2,arr1[pos])==0){
            continue;
        }
        *(result + i) = arr1[pos];
            ++i;
    }
    printf("subtraction operation \n");
    for(int m=0; m<i-1;++m){
        printf("%3d",*(result + m));
    }
    printf("\n");
}