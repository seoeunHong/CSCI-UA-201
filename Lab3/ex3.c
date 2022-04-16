//Implement a C function called ex3 such that it achieves 
//the same functionality as the machine code of objs/ex3_sol.o
//Note: you need to figure out ex3()'s function signature yourself; 
//the signature is not void ex3()
  
#include <assert.h>

int ex3(char *string1, char *string2,long limit) {
  int i = 0;
  while(string1[i]){
    i++;
  }
  int j = 0;
  for(; j <limit; j++){
    char str2Char = string2[j];
    if(str2Char==0){
      break;
    }
    long newIndx = i + j;
    string1[newIndx] = str2Char;
  }
  j+=i;
  string1[j] = 0;
  return j;
}
