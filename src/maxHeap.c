//inspired by https://github.com/ccampo133/maxheap/blob/master/maxheap.py
//max heap
#ifndef C_ALGO_MAX_HEAP
#define C_ALGO_MAX_HEAP
#include <stddef.h>
#include "C_algorithm.h"
void __sift_down(size_t size,char* start,char* end,size_t node,size_t len,algo_predicate comp,algo_function move) {
	size_t child=2*node+1;
	if(child>len-1)
		return;
	if(child+1<=len-1)
		if(comp(2,start+child*size,start+size*(child+1)))
			child+=1;
	if(comp(2,start+size*node,start+child*size)) {
		__algo_swap(size,start+size*node,start+child*size,move);
		__sift_down(size,start,end,child,len,comp,move);
	}
}
void __sift_up(size_t size,char* start,char* end,size_t node,size_t len,algo_predicate comp,algo_function move) {
	size_t parent=(node-1)/2;
	if(comp(2,start+size*parent,start+size*node))
		__algo_swap(size,start+size*parent,start+size*node,move);
	if(parent<=0)
		return;
	__sift_up(size,start,end,parent,len,comp,move);
}
void heapify(size_t size,char* start,char* end,algo_predicate comp,algo_function move)  {
	size_t len=(end-start)/size;
	printf("%i\n",len);
	for(size_t i=len/2;i!=-1;i--)
		__sift_down(size,start,end,i,len,comp,move);
}
void push_heap(size_t size,char* start,char* end,algo_predicate pred,algo_function move) {
	size_t len=(end-start)/size;
	__sift_up(size,start,end,len-1,len,pred,move);
}
void pop_heap(size_t size,char* start,char* end,algo_predicate comp,algo_function move) {
	size_t len=(end-start)/size;
	__algo_swap(size,start,start+(len-1)*size,move);
	end-=size;
	__sift_down(size,start,end,0,len-1,comp,move);
}
#endif
