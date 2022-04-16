# Lab 3: Binary Mystery

Deduce the function based on their x86-64 assembly code and write the corresponding C function that accomplishes the same thing for each of functions.

## Description

There are five object files ex1_sol.o, ex2_sol.o, ..., ex5-sol.o in objs file.
Disassemble those file with this commemd

```sh
$ objdump -d ex1_sol.o
$ objdump -d ex2_sol.o
$ ...
```

Then it will show x86-64 assembly code on your commend line

```sh
0000000000000000 <ex1>:
       0: 48 01 f7                      addq    %rsi, %rdi
       3: 48 39 d7                      cmpq    %rdx, %rdi
       6: 0f 94 c0                      sete    %al
       9: c3                            retq

0000000000000000 <ex2>:
       0: ba 00 00 00 00                movl    $0, %edx
       5: b8 00 00 00 00                movl    $0, %eax
       a: eb 11                         jmp     0x1d <ex2+0x1d>
       c: 8b 0c 97                      movl    (%rdi,%rdx,4), %ecx
       f: 85 c9                         testl   %ecx, %ecx
      11: 7e 06                         jle     0x19 <ex2+0x19>
      13: 48 63 c9                      movslq  %ecx, %rcx
      16: 48 01 c8                      addq    %rcx, %rax
      19: 48 83 c2 01                   addq    $1, %rdx
      1d: 48 39 f2                      cmpq    %rsi, %rdx
      20: 7c ea                         jl      0xc <ex2+0xc>
      22: f3 c3                         rep             retq
```

My code for each function are based on their x86-64 assembly code

## Test

Type `$ make` and `./tester` in to your terminal.
if all test are passed, you can see this result:

> $ make <br/>
> $ ./tester <br/>
> Testing ex1... <br/>
> ex1 passed <br/>
> Testing ex2... <br/>
> ex2 passed <br/>
> Testing ex3... <br/>
> ex3 passed <br/>
> Testing ex4... <br/>
> ex4 passed <br/>
> Testing ex5... <br/>
> ex5 passed <br/>
