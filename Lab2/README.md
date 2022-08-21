# Lab 2 (clab-part2): Basic C Programming

Continue learning some basic C programming by writing a few C functions manipulating strings, and a hash table which can be used to lookup keys in O(1) time.

## Description

`str.c`

- **string_len**: Return the length of the string pointed to by "s".
- **string_cmp**: Compare strings "s1" and "s2" and Return less than, equal to or great than zero. (if "s1" is found to be less than, match, or larger than "s2" alphabetically)
- **int_to_hex**: Convert integer x into hex format and store the resulting hex string to "str".

`list.c`

- **list_init**: Set its head pointer to NULL.
- **list_insert_with_accum**: Insert a key value pair into the linked list while maintaining sorted order and Return true if the key does not already exists; false otherwise.
- **list_find**: Find if a given key string exists in the sorted linked list. Return the value associated with the key if key is found. Otherwise, return -1.
- **list_get_all_tuples**: Traverse the linked list starting from node pointed to by "headp" and store all the encountered key-value tuples in the array "tuples".

`htable.c`

- **htable_create**: Create and initializes a new htable. Return a pointer to the newly created htable struct (htable_t).
- **hashcode**: Function that is used internally by the hash table to calculate the hashcode for a string with n characters, s[0...n-1]
- **htable_put**: Insert a key value pair to the hash table. If the key already exists, accumulate the new value into the existing value using the given function pointer "accum".
- **htable_get**: Find "key" in the hash table and returns the pointer to its associated value.
- **htable_get_all_tuples**: Traverse the hash table pointed to by "ht" and store all the key-value tuples encountered in the hash table in the array "tuples".

## Test

Type `$ make` and `./clab2_test` in to your terminal.
if all test are passed, you can see this result:

> $ make <br/>
> $ ./clab2_test <br/>
> ---Start testing str.c <br/>
> string_len...passed <br/>
> string_cmp...passed <br/>
> int_to_hex...passed <br/>
> ---Test str.c Passed
> ...
