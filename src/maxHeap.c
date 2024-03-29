//inspired by https://github.com/ccampo133/maxheap/blob/master/maxheap.py
//max heap
#ifndef C_ALGO_MAX_HEAP
#define C_ALGO_MAX_HEAP
#include <stddef.h>
#include "../headers/C_algorithm.h"
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
void __algo_make_heap(size_t size,char* start,char* end,algo_predicate comp,algo_function move)  {
	size_t len=(end-start)/size;
	printf("%i\n",len);
	for(size_t i=len/2;i!=-1;i--)
		__sift_down(size,start,end,i,len,comp,move);
}
void __algo_push_heap(size_t size,char* start,char* end,algo_predicate pred,algo_function move) {
	size_t len=(end-start)/size;
	__sift_up(size,start,end,len-1,len,pred,move);
}
void __algo_pop_heap(size_t size,char* start,char* end,algo_predicate comp,algo_function move) {
	size_t len=(end-start)/size;
	__algo_swap(size,start,start+(len-1)*size,move);
	end-=size;
	__sift_down(size,start,end,0,len-1,comp,move);
}
void __algo_sort_heap(size_t size,char* start,char* end,algo_predicate comp,algo_function move) {
	size_t len=(end-start)/size;
	for(size_t i=len;i>1;) {
		__algo_swap(size,start+(i-1)*size,start,move);
		end-=size;
		i--;
		__sift_down(size,start,end,0,i,comp,move);
	}
}
bool __algo_is_heap(size_t size,char* start,char* end,algo_predicate comp,algo_function move) {
	size_t len=(size_t)(end-start)/size;
	for(size_t i=(len-2)/2;i>-1;--i) {
		size_t j=2*i+1;
		if(j<len-1)
			if(comp(2,start+size*i,start+size*(j+1)))
				j++;
		if(comp(2,start+size*i,size*size*j))
			return false;
	}
	return true;
}
#endif
