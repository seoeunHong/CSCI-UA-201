//Implement a C function called ex2 such that it achieves 
//the same functionality as the machine code of objs/ex2_sol.o
//Note: you need to figure out ex2()'s function signature yourself; 
//the signature is not void ex2()
  
#include <assert.h>


int ex2(int *arr,long limit){
    int sum = 0;
    for(int i = 0; i < limit; i++){
        int element = arr[i];
        if(element < 0){
            continue;
        }
        sum += element;
    }
    return sum;
}