#include <stdio.h>
#include <assert.h>

#include "string.h"


// Return the length of the string pointed to by "s".
//
// Note: C standard library function strlen accomplishes
// exactly the same functionality as string_len. In this exercise,
// please do not use strlen. In subsequent exercises (list.c, htable.c), 
// it is recommended that you use strlen instead of string_len
int string_len(char *s)
{
  unsigned int len = 0;
  while (*s!='\0') {
   len++;
   s++;
  }
  return len;

}

// Compare strings "s1" and "s2". It returns less than, equal to or great than zero 
// if "s1" is found to be less than, match, or larger than "s2" alphabetically.
// For example, string_cmp("aa", "aaa") should return a negative number
// and string_cmp("aa", "a0") should return a positive number
// Note that we use the ASCII values of characters as basis for comparison.
// As the ascii value of 'a' is greater than the ascii value of '0', 
// "aa" is considered to be greater than "a0".
//
// Note: C standard library function strcmp accomplishes
// exactly the same functionality as string_cmp. In this exercise,
// please do not use strcmp. In subsequent exercises (list.c, htable.c), 
// it is recommended that you use strcmp instead of string_cmp.
int string_cmp(char *s1, char *s2)
{
  while( ( *s1 != '\0' && *s2 != '\0' ) && *s1 == *s2 ){
    s1++;
    s2++;
  }

  if(*s1 == *s2){
    return 0; 
  }else{
    return *s1 - *s2;
  }

}

// Convert integer x into hex format and store the resulting hex string to "str",
// e.g., if x=16, then str should be "00000010".
// If x=26, then str should be "0000001a";
// The resulting hex string should always have exactly 8 hex characters 
// followed by the null character.
// We assume the caller has allocated an array of at least 9 characters for "str", 
// Note: please do not use formatted output, such as sprintf
void int_to_hex(unsigned int x, char *str)
{
  char hex [8];
  int i = 0, check;
  while(x != 0){
    check = x % 16;
    if(check < 10){
      hex[i] = check + 48;
      i++;
    }else{
      hex[i] = check + 87;
      i++;
    }
    x /= 16;
  }

  int k = i;
  for (int j = i-1; j >= 0 ; j--)
  {
    str[8-k] = hex[j];
    k--;
  }

  for(k = 0; k < 8 - i; k++)
    str[k] = '0';
  
}