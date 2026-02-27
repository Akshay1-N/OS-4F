#include<stdio.h>

int main(){
    int n;
    printf("enter the size of the array:");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }
    int min=arr[0];
    int j;
    int position=0;
    for(j=0;j<n;j++){
        if(min>arr[j]){
            min=arr[j];
            position=j;
        }
    }
    printf("The smallest number is:%d\n", min);
    printf("the position of the smallest number is:%d\n",position);
}
