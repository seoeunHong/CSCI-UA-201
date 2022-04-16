// This file gives you a starting point to implement malloc using implicit list
// Each chunk has a header (of type header_t) and does *not* include a footer
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

#include "mm-common.h"
#include "mm-implicit.h"
#include "memlib.h"

// turn "debug" on while you are debugging correctness. 
// Turn it off when you want to measure performance
static bool debug = true; 

size_t hdr_size = sizeof(header_t);

void 
init_chunk(header_t *p, size_t csz, bool allocated)
{
	p->size = csz;
	p->allocated = allocated;
}

// Helper function next_chunk returns a pointer to the header of 
// next chunk after the current chunk h.
// It returns NULL if h is the last chunk on the heap.
// If h is NULL, next_chunk returns the first chunk if heap is non-empty, and NULL otherwise.
header_t *
next_chunk(header_t *h)
{
	//check if the heap is empty or not
	if(mem_heap_hi() > mem_heap_lo()){
		if(h == NULL){
			return mem_heap_lo();
		}else if((header_t *)((char *)h + h -> size) >= (header_t *)mem_heap_hi()){
			return NULL;
		}else{
			return (header_t *)((char *)h + h -> size);
		}
	}
	return NULL;
}


/* 
 * mm_init initializes the malloc package.
 */
int mm_init(void)
{
	//double check that hdr_size should be 16-byte aligned
	assert(hdr_size == align(hdr_size));
	// start with an empty heap. 
	// no additional initialization code is necessary for implicit list.
	return 0;
}


// helper function first_fit traverses the entire heap chunk by chunk from the begining. 
// It returns the first free chunk encountered whose size is bigger or equal to "csz".  
// It returns NULL if no large enough free chunk is found.
// Please use helper function next_chunk when traversing the heap
header_t *
first_fit(size_t csz)
{
	header_t *chunk = NULL;
	chunk = next_chunk(chunk);
	while(chunk){
		if(chunk -> size >= csz && (bool)chunk -> allocated == false){
			return chunk;
		}
		chunk = next_chunk(chunk);
	}
	return NULL;
}

// helper function split cuts the chunk into two chunks. The first chunk is of size "csz", 
// the second chunk contains the remaining bytes. 
// You must check that the size of the original chunk is big enough to enable such a cut.
void
split(header_t *original, size_t csz)
{
	if(original -> size > csz){
		size_t temp = original -> size;
		original -> size = csz;
		header_t *newChunk = (header_t *)((char *)original + csz);
		init_chunk(newChunk, temp - csz, false);

	}
}

// helper function ask_os_for_chunk invokes the mem_sbrk function to ask for a chunk of 
// memory (of size csz) from the "operating system". It initializes the new chunk 
// using helper function init_chunk and returns the initialized chunk.
header_t *
ask_os_for_chunk(size_t csz)
{
	header_t *newChunk = mem_sbrk(csz);
	init_chunk(newChunk, csz, false);
	return newChunk;
}

/* 
 * mm_malloc allocates a memory block of size bytes
 */
void *
mm_malloc(size_t size)
{
	//make requested payload size aligned
	size = align(size);
	//chunk size is aligned because both payload and header sizes
	//are aligned
	size_t csz = hdr_size + align(size);

	header_t *p = NULL;

	//Your code here 
	//to obtain a free chunk p to satisfy this request.
	//
	//The code logic should be:
	//Try to find a free chunk using helper function first_fit
	//    If found, split the chunk (using helper function split).
	//    If not found, ask OS for new memory using helper ask_os_for_chunk
	//Set the chunk's status to be allocated
	p = first_fit(csz);
	if(p == NULL){
		p = ask_os_for_chunk(csz);
	}else{
		split(p, csz);
	}

	p -> allocated = true;
	p = (header_t *)((char *)p + hdr_size);


	//After finishing obtaining free chunk p, 
	//check heap correctness to catch bugs
	if (debug) {
		mm_checkheap(true);
	}
	return (void *)p;
}

// Helper function payload_to_header returns a pointer to the 
// chunk header given a pointer to the payload of the chunk 
header_t *
payload2header(void *p)
{
	return (header_t *)((char *)p - hdr_size);
}

// Helper function coalesce merges free chunk h with subsequent 
// consecutive free chunks to become one large free chunk.
// You should use next_chunk when implementing this function
void
coalesce(header_t *h)
{
	header_t *nextChunk = next_chunk(h);
	while(nextChunk){
		if((bool)(nextChunk -> allocated) == false){
			(h -> size) += (nextChunk -> size);
		}else{
			break;
		}
		nextChunk = next_chunk(nextChunk);
	}
}

/*
 * mm_free frees the previously allocated memory block
 */
void 
mm_free(void *p)
{
	// Your code here
	// 
	// The code logic should be:
	// Obtain pointer to current chunk using helper payload_to_header 
	// Set current chunk status to "free"
	// Call coalesce() to merge current chunk with subsequent free chunks
	header_t *currChunkPointer = payload2header(p);
	currChunkPointer -> allocated = false;
	coalesce(currChunkPointer);
	
	  
	  
	// After freeing the chunk, check heap correctness to catch bugs
	if (debug) {
		mm_checkheap(true);
	}
}	

/*
 * mm_realloc changes the size of the memory block pointed to by ptr to size bytes.  
 * The contents will be unchanged in the range from the start of the region up to the minimum of   
 * the  old  and  new sizes.  If the new size is larger than the old size, the added memory will   
 * not be initialized.  If ptr is NULL, then the call is equivalent  to  malloc(size).
 * if size is equal to zero, and ptr is not NULL, then the call is equivalent to free(ptr).
 */

void *
mm_realloc(void *ptr, size_t size)
{
	// Your code here
	if(ptr == NULL){
		return mm_malloc(size);
	}else if(size == 0){
		mm_free(ptr);
		return NULL;
	}
	size_t oldSize = payload2header(ptr) -> size;
	size_t newSize = align(size) + hdr_size;
	header_t *head = payload2header(ptr);

	if(oldSize < newSize){
		header_t *next = next_chunk(head);
		while((next != NULL) && (next -> allocated == 0)){
			int remain = (head -> size + next -> size) - newSize;
			head -> size += next -> size;
			if(remain >= 0){
				split(head, newSize);
				return ptr;
			}
			next = next_chunk(head);
		}
		head -> size = oldSize;


		void *newMalloc = mm_malloc(size);
		if (newMalloc == NULL){
			return NULL;
		}
		memcpy(newMalloc, ptr, oldSize - hdr_size);
		mm_free(ptr);
		return newMalloc;
	}else{
		return ptr;
	}

	// Check heap correctness after realloc to catch bugs
	if (debug) {
		mm_checkheap(true);
	}
	return NULL;
}

/*
 * mm_checkheap checks the integrity of the heap and returns a struct containing 
 * basic statistics about the heap. Please use helper function next_chunk when 
 * traversing the heap
 */
heap_info_t 
mm_checkheap(bool verbose) 
{
	// traverse the heap to fill in the fields of info
	heap_info_t info;
	header_t *chunk = NULL;
	chunk = next_chunk(chunk);
	info.num_allocated_chunks = 0; 
	info.num_free_chunks = 0; 
	info.allocated_size = 0; 
	info.free_size = 0;
	if(chunk == NULL){
		info.free_size = 0;
	}
	while(chunk){
		if((bool)chunk -> allocated){
			info.num_allocated_chunks += 1;
			info.allocated_size += (chunk -> size);
		}else{
			info.num_free_chunks += 1;
			info.free_size += (chunk -> size);
		}
		chunk = next_chunk(chunk);
	}
	// correctness of implicit heap amounts to the following assertion.
	assert(mem_heapsize() == (info.allocated_size + info.free_size));
	return info;
}