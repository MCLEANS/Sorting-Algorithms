#include <stdio.h>

void xsort (int *input, int count){
    int i,j,temp;
    for(i=1;i<=count-1;i++){
        temp=input[i];
        j=i-1;
        while((temp<input[j])&&(j>=0)){
            input[j+1]=input[j];
            j=j-1;
        }
        input[j+1]=temp;
    }
}


int main(int argc, char* argv[]){

    int array[] = {2,34,65,7900,63,235,723,908,5789,25437,1356,46987,234,35921,17453};

    xsort(array,sizeof(array)/sizeof(int));

    for(int i = 0; i < (sizeof(array)/sizeof(int));i++){
        printf("%d ",array[i]);
    }

    printf("\n");


    return 0;
}