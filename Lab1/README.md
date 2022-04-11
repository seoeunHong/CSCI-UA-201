# Lab 1 (clab-part1): Basic C Programming

Learning some basic C programming by writing down simple C functions and debugging.

## Description

`bitfloat.c`

- **get_bit_at_pos**: Return the bit value (0 or 1) at position pos of unsigned int n
- **set_bit_at_pos**: Set the bit value to 1 at position pos of unsigned int n, while leaving other bits unchanged.
  Return the changed integer.
- **get_most_significant_byte**: Return the most significant byte of unsigned int n.
- **sum_overflowed**: Return true if n1+n2 causes overflow, return false otherwise.
- **get_exponent_field**: Extract the 8-bit exponent field of single precision floating point number f and return it as an unsigned byte.

`ptr.c`

- **set_to_five**: Assign the value of 5 to the integer variable pointed to by ptr.
- **initialize_ptr**: Assign NULL value to the pointer variable pointed to by dp.
  Since dp points to a pointer variable, its type is a double pointer indicated by two stars \*\* in the type name.
- **swap_int**:Swap the values of two int variables, pointed to by x and y, respectively.

`array.c`

- **array_sum**: Return the sum of all elements in the given array.
  The array "arr" has "n" elements. We must explicitly pass in the array size because C array does not contain size information.
- **array_cpy**: Copy the first n elements of array "src" into array "dst".
  We assume caller has already allocated an array of at least n elements as "dst".
- **bubble_sort**: bubble_sort implements the bubble sort algorithm.
  It is given an integer array "arr" of "n" elements.
  Upon return, the integer array should contain the sorted numbers in increasing order.
- **big_to_little_endian**: arr is a 4 byte array containing an integer in big endian format.
  Convert the integer to little endian and return the converted int.

## Test

Type `$ ./clab_test` in to your terminal
if all test are passed, you can see this result:

> $ ./clab_test <br/>
> ---Start testing bitfloat.c <br/>
> get_bit_at_pos...passed <br/>
> set_bit_at_pos...passed <br/>
> get_most_significant_byte...passed <br/>
> sum_overflowed...passed <br/>
> get_exponent_field...passed <br/>
> ---Test bitfloat.c Passed <br/>
> ---Start testing ptr.c <br/>
> set_to_five...passed <br/>
> initialize_ptr...passed <br/>
> swap_int...passed <br/>
> ---Test ptr.c Passed <br/>
> ---Start testing array.c <br/>
> array_sum...passed <br/>
> array_cpy...passed <br/>
> bubble_sort...passed <br/>
> big_to_little_endian...passed <br/>
> ---Test array.c Passed <br/>
