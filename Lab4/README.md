# Lab 3: Binary Mystery

Make my own version of the malloc: the dynamic storage allocator for C programs.
Explore the design space creatively and implement an allocator that is correct, efficient and fast.

## Description

`mm-implicit.c`

- **mm_init**: Be called to initialize my malloc library prior to any any **mm_malloc** and **mm_free calls**.
  Return -1 if there was a problem in performing the initialization, 0 otherwise.
- **mm_malloc**: Allocate size bytes of contigous space on the heap. Return a pointer to the allocated space. (Allocated space lie within the heap region and not overlap others)
- **mm_free**: Free the corresponding chunk whose payload is pointed by ptr. Return nothing.
- **mm_realloc**: Allocate size bytes of continuious space, with the following contraints. <br/>
  &nbsp; * if ptr is NULL, the call is equivalent to mm_malloc(size) <br/>
  &nbsp; *if size is equal to zero, the call is equivalent to mm_free(ptr)}; <br/>
  &nbsp; \* if ptr is not NULL, it must have been returned by an earlier call to mm_malloc or mm_realloc. <br/>
  &nbsp; Change the memory block pointed to by ptr (i.e.the old block) to one with size bytes and returns the address of the new block. <br/>
- **mm_checkheap**: Check consistency of my heap

## Test

Type `$ make` and `./implicit-unittest` in to your terminal.
if all test are passed, you can see this result:

> $ make <br/>
> $ ./implicit-unittest <br/>
> start test_next_chunk <br/>
> start test_mm_checkheap <br/>
> start test_ask_os_for_chunk <br/>
> start test_split <br/>
> start test_first_fit <br/>
> start test_mm_malloc <br/>
> start test_payload2header <br/>
> start test_coalesce <br/>
> start test_mm_free <br/>
> start test_mm_realloc <br/>
> all unit tests passed... <br/>

Next, run trace-based tester which is provided as implicit-mdriver.c. It will test my malloc's correctness, space utilization, and throughput.
The tester implicit-mdriver reads a set of trace files, each of which contains a sequence of allocate, reallocate, and free events corresponding to some example application workload.

It then calls your mm_malloc, mm_realloc, and mm_free routines according to the sequence of events.

To run the tester, type:

`$ ./implicit-mdriver -V`
The -V turns on verbose printing in the tester.

To run the tester on one specific tracefile instead of all of the default tracefiles, type:

`$./implicit-mdriver -V -f tracefile`
All the tracefiles can be found in the traces/ subdirectory.

You can type `$./implicit-mdriver -h` to see a full list of command line options. Here's the example output if the tester runs successfully.

> $ ./implicit-mdriver <br/>
> Using default tracefiles in ./traces/ <br/>
> Performance index = 60.0 _ util + 40.0 _ (your throughput)/(libc's throughput) <br/>
> 11 out of 11 traces passed, average performance index 48.4 (out of 100.0) <br/>
