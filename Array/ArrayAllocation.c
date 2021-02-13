// Static vs Dynamic Array Allocation in C

#include <stdio.h>
#include <stdlib.h>

int main(){

    int A[5]={1,2,3,4,5}; // Static Allocation
    int *p;
    p = (int*)malloc(5*sizeof(int)); // Dynamic Allocation
    p[0]=5;
    p[1]=3;
    p[2]=2;
    p[3]=9;
    p[4]=7;

    printf("Static Allocation: ");
    for (int i=0;i<5;i++){
        printf("%d",A[i]);
    }
    printf("\n");
    printf("Dynamic: ");

    for (int j=0;j<5;j++){
        printf("%d",p[j]);
    }
    free(p);
}
