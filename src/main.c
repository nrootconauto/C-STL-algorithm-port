#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdarg.h>
#include <malloc.h>
typedef bool(*algo_predicate)(int numArgs,...);
typedef char* (*algo_function)(int numArgs,...); 
#define $AP(predicate) (algo_predicate)(predicate)
#define $AF(func) (algo_function)(func)
#define $AA(argument) (char*)(argument)
typedef algo_function algo_move_func;
typedef algo_function algo_replace_func;
typedef algo_function algo_copy_func;
typedef algo_function algo_destroy_func;
bool algo_all_of(size_t size,char* first,char* last,algo_predicate pred) {
while(first!=last) {
	if(!pred(1,first))
		return false;
		first+=size;
	}
	return true;
}
bool algo_any_of(size_t size,char* first,char* last,algo_predicate pred) {
	while(first!=last) {
		if(pred(1,first))
			return true;
		first+=size;
	}
	return false;
}
bool algo_none_of(size_t size,char* first,char* end,algo_predicate pred) {
	return !algo_any_of(size,first,end,pred);
}
void algo_for_each(size_t size,char* first,char* end,algo_function func) {
	while(first!=end) {
		func(1,first);
		first+=size;
	}
}
char* algo_find_if(size_t size,char* first,char* last,algo_predicate pred) {
	while(first!=last) {
		if(pred(1,first))
			return first;
		first+=size;
	}
	return last;
}
char* algo_find_if_not(size_t size,char* first,char* last,algo_predicate pred) {
	while(first!=last) {
		if(!pred(1,first))
			return first;
		first+=size;
	}
	return last;
}
char* algo_find_end(size_t size,char* first1,char* last1,char* first2,char* last2,algo_predicate pred) {
	size_t elemsIn1=(size_t)(last1-first1)/size;
	size_t elemsIn2=(size_t)(last2-first2)/size;
	size_t index=0;
	while(first1!=last1) {
		//if to big quit
		if(elemsIn1>(index+elemsIn2))
			return last1;
		if(pred(2,first1,first2+index))
			index++;
		else
			index=0;
		if(index==elemsIn2)
			return first1-index;
		first1+=size;
	}
	return last1;
}
char* algo_find_first_of(size_t size,char* first1,char* last2,char* selectionStart,char* selectionEnd,algo_predicate pred) {
	size_t itemsInSelection=(size_t)(selectionEnd-selectionStart)/size;
	while(first1!=last2) {
		size_t selectionItem=0;
		while(selectionStart+selectionItem*size!=selectionEnd)
			if(pred(2,selectionStart+(selectionItem++)*size,first1))
				return selectionStart+selectionItem*size;
		first1+=size;
	}
	return last2;
}
char* algo_adjacent_find(size_t size,char* first,char* last,algo_predicate pred) {
	if(first==last)
		return last;
	//stay within bounds of function
	last-=size;
	while(first!=last) {
		if(pred(2,first,first+size))
			return first;
		first+=size;
	}
	return last;
}
int algo_count_if(size_t size,char* first,char* last,algo_predicate pred) {
	int count=0;
	while(first!=last) {
		if(pred(1,first))
			count++;
		first+=size;
	}
	return count;
}
struct algo_pair {
	char* first;
	char* second;
};
struct algo_pair algo_mismatch(size_t size,char* first1,char* last1,char* first2,algo_predicate pred) {
	size_t index=0;
	char* last2=last1-first1+first2;
	struct algo_pair make_return_value() {
		struct algo_pair retVal;
		retVal.first=first1;
		retVal.second=first2;
		return retVal;
	}
	while(first1!=last1) {
		if(first2==last2)
			return make_return_value();
		//leave if at end of
		if(!pred(2,first1,first2))
			return make_return_value();
		first1+=size;
		first2+=size;
	}
	return make_return_value();
}
bool algo_equal(size_t size,char* first1,char* last1,char* first2,char* last2,algo_predicate pred) {
	//ensure length is same
	size_t array1Size=(size_t)(last1-first1)/size;
	while(first1!=last1) {
		if(!pred(2,first1,first2))
			return false;
		first1+=size;
		first2+=size;
	}
	return true;
}
//tested
bool algo_is_permutation(size_t size,char* first1,char* last1,char* first2,algo_predicate pred) {
	char* last2=last1-first1+first2;
	size_t array1Size=(size_t)(last1-first1)/size;
	struct algo_pair temp=algo_mismatch(size,first1,last1,first2,pred);
	first1=temp.first;
	first2=temp.second;
	last2=first2;
	last2+=last1-first1;
	for(char* it=first1;it!=last1;it+=size) {
		bool uni(int n,char* a) {
			return pred(2,a,it);
		}
		if(algo_find_if(size,first1,it,$AP(uni))==it) {
			int n=algo_count_if(size,first2,last2,$AP(uni));
			if(n==0||algo_count_if(size,it,last1,$AP(uni))!=n)
				return false;
		}
	}
	return true;
}
char* algo_search(size_t size,char* first1,char* last1,char* first2,char* last2,algo_predicate pred) {
 if(first2==last2)
		return first1;
	while(first1!=last1) {
		char* it1=first1;
		char* it2=first2;
		while(pred(2,it1,it2)) {
			if(pred(2,it2,last2))
				return first1;
			if(pred(2,it1,last1))
				return last1;
			it1+=size;
			it2+=size;
		}
		first1+=size;
	}
	return last1;
}
char* algo_search_n(size_t size,char* first,char* last,int n,char* val,algo_predicate pred) {
	char* it;
	char* limit;
	int i;
	limit=last;
	limit-=size*n;
	while(first!=limit) {
		it=first;
		i=0;
		while(pred(2,it,val)) {
			it+=size;
			i++;
			if(i==n)
				return first;
		}
		first+=size;
	}
}
char* algo_copy(size_t size,char* first,char* last,char* dest,algo_copy_func copyFunc) {
	while(first!=last) {
		copyFunc(2,first,dest);
		first+=size;dest+=size;
	}
	return last;
}
char* algo_copy_n(size_t size,char* first,int howMany,char* out,algo_copy_func copyFunc) {
	int i=0;
	while(i!=howMany) {
		copyFunc(2,first+i++*size,out);
	}
	return first+i*size;
}
char* algo_copy_if(size_t size,char* first,char* last,char* dest,algo_predicate pred,algo_copy_func copyFunc) {
	while(first!=last) {
		if(pred,1,first) {
			copyFunc(2,first,dest);
			dest+=size;
		}
		first+=size;
	}
	return dest;
}
char* algo_copy_backward(size_t size,char* first,char* last,char* dest,algo_copy_func copyFunc) {
	while(last!=first) {
		last-=size;
		copyFunc(2,last,dest);
		dest-=size;
	}
	return dest;
}
void __algo_swap(size_t size,char* a,char* b,algo_move_func mover) {
	char* thing=malloc(size);
	mover(2,a,thing);
	mover(2,b,a);
	mover(2,thing,b);
	free(thing);
}
char* __algo_swap_ranges(size_t size,char* first1,char* last1,char* first2,algo_move_func mover) {
	while(first1!=last1) {
		__algo_swap(size,first1,first2,mover);
		first1+=size;
		first2+=size;
	}
	return first2;
}
char* algo_transform(size_t size,char* first1,char* last1,char* dest,algo_function mutator) {
	while(first1!=last1)	{
		mutator(2,first1,dest);
		dest+=size;
		first1+=size;
	}
	return dest;
}
void algo_replace_copy_if(size_t size,char* first,char* last,algo_predicate pred,char* newValue,algo_replace_func replacer) {
	while(first!=last) {
		if(pred(1,first)) replacer(2,first,newValue);
		first+=size;
	}
}
char* algo_replace_if(size_t size, char* first, char* last, char* dest, algo_predicate pred, char* newValue,algo_replace_func replacer){
	while(first!=last) {
		if(pred(1,first)) {
			replacer(2,dest,newValue);
			dest+=size;
		}
		first+=size;
	}
	return dest;
}
void algo_fill(size_t size,char* first,char* last,char* value,algo_copy_func copy) {
	while(first!=last) {
		copy(2,first,value);
		first+=size;
	}
}
char* algo_fill_n(size_t size,char* first,char* last,int howMany,char* value,algo_copy_func copy) {
	while(howMany>0) {
		copy(2,first,value);
		first+=size;
		--howMany;
	}
	return first;
}
void algo_generate(size_t size,char* first,char* last,algo_function generator) {
	while(first!=last) {
		generator(1,first);
		//memcpy(first,generator(0),size);
		first+=size;
	}
}
void algo_generate_n(size_t size,char* first,int n,algo_function gen) {
	while(n-- >0) {
		gen(1,first);
		first+=size;
	}
}
char* algo_remove_if(size_t size, char* first, char* last, algo_predicate pred,algo_replace_func replacer) {
	char* result=first;
	while(first!=last) {
		if(!pred(1,first)) {
			replacer(2,result,first);
			result+=size;
		}
		first+=size;
	}
	return first;
}
char* remove_copy_if(size_t size,char* first,char* last,char* dest,algo_predicate pred,algo_copy_func copyFunc) {
	while(first!=last) {
		if(!pred(1,first)) {
			algo_copy(size,first,last,dest,copyFunc);
			dest+=size;
		}
		first+=size;
	}
	return dest;
}
//removes all but one of uitms with conesecutive values
char* algo_unique(size_t size,char* first,char* last,algo_predicate pred,algo_replace_func replacer) {
	if(first==last)
		return last;
	char* result=first;
	while(first+size!=last) {
		first+=size;
		if(!pred(2,result,first)) {
			//free the entry
			result+=size;
			replacer(2,result,first);
		}
	}
	return size+result;
}
char* algo_unique_copy(size_t size, char* first, char* last,char* dest,algo_predicate pred,algo_copy_func copy) {
	if(first==last)
		return dest;
	algo_copy(size,first,first+size,dest,copy);
	while(first+size!=last) {
		first+=size;
		if(!pred(2,dest,first)) {
			dest+=size;
			algo_copy(size,first,first+size,dest,copy);
		}
	}
	return dest+size;
}
void __algo_reverse(size_t size,char* first,char* last,algo_move_func move) {
	while((first!=last)&&(first!=last-size)) {
		last-=size;
		__algo_swap(size,first,last,move);
		first+=size;
	}
}
char* __algo_reverse_copy(size_t size, char* first, char* last,char* dest,algo_function copyFunc) {
	while(first!=last) {
		last-=size;
		algo_copy(size,last,last+size,dest,copyFunc);
		dest+=size;
	}
	return dest;
}
void algo_rotate(size_t size,char* first,char* middle,char* last,algo_replace_func replace) {
	char* next=middle;
	while(first!=next) {
		__algo_swap(3,first,next,replace);
		first+=size;next+=size;
		if(next==last) next=middle;
		else if(first==middle) middle=next;
	}
}
char* algo_rotate_copy(size_t size,char* first,char* middle,char* last,char* dest,algo_copy_func copyFunc) {
	algo_copy(size,middle,last,dest,copyFunc);
	return algo_copy(size,first,middle,dest,copyFunc);
}
void algo_random_shuffle(size_t size,char* first,char* last,algo_move_func move) {
	size_t i,n;
	n=(last-first);
	for(i=n-1;i>0;i-=size)
		__algo_swap(3,first+i,first+rand(),move);
}
bool algo_is_partitioned(size_t size,char* first,char* last,algo_predicate pred) {
	while(first!=last&&pred(1,first))
		first+=size;
	while(first!=last) {
		if(pred(1,first))
			return false;
		first+=size;
	}
	return true;
}
char* algo_partition(size_t size,char* first,char* last,algo_predicate pred,algo_move_func move) {
	while(first!=last) {
		while(pred(1,first)) {
			first+=size;
			if(first==last)
				return first;
		}
		do {
			last-=size;
			if(first==last)
				return first;
		} while(!pred(1,last));
		__algo_swap(size,first,last,move);
		first+=size;
	}
	return first;
}
struct algo_pair algo_partition_copy(size_t size,char* first,char* last,char* destTrue,char* destFalse,algo_predicate pred,algo_copy_func copy) {
	while(first!=last) {
		if(pred(1,first)) {
			copy(2,first,destTrue);
			destTrue+=size;
		} else {
			copy(2,first,destFalse);
			destFalse+=size;
		}
		first+=size;
	}
	struct algo_pair retVal;
	retVal.first=destTrue;
	retVal.second=destFalse;
	return retVal;
}
char* algo_partiton_point(size_t size,char* start,char* end,algo_predicate pred) {
	size_t n=(size_t)(end-start)/size;
	while(n>0) {
		char* it=start;
		size_t step=n/2;
		it+=step*size;
		if(pred(1,it)) {
			start=it+size;
			it+=size;
			n-=(step+1)*size;
		} else
			n=step;
	}
	return start;
}
void algo_sort(size_t size,char* start,char* end,algo_predicate pred,algo_move_func move) {
	void qs(char* left,char* right) {
		if(left==right)
			return;
		char* pivot=left+(right-left)/2;
		char* partPoint=algo_partition(size,left,right,pred,move);
		qs(left,partPoint-size);
		qs(partPoint+size,right);
	}
	qs(start,end);
}
bool algo_is_sorted(size_t size,char* first,char* last,algo_predicate pred) {
	if(first==last)
		return true;
	char* next=first;
	while(next+size!=last) {
		next+=size;
		if(pred(2,next,first))
			return false;
		first+=size;
	}
	return true;
}
char* algo_is_sorted_until(size_t size,char* first,char* last,algo_predicate pred) {
	if(first==last) return first;
	char* next=first;
	while(next+size!=last) {
		next+=size;
		if(pred(2,next,first)) return next;
		first+=size;
	}
	return last;
}
char* algo_sorted_lower_bound(size_t size,char* first,char* last,char* val,algo_predicate pred) {
	char* it;
	size_t count,step;
	count=(last-first)/size;
	while(count>0) {
		it=first;
		step=count/2;
		it+=size*step;
		if(pred(2,it,val)) {
			it+=size;
			first=it;
			count-=step+1;
		} else
			count=step;
	}
	return first;
}
char* algo_sorted_upper_bound(size_t size,char* first,char* last,char* val,algo_predicate pred) {
	char* it;
	size_t count,step;
	count=(last-first)/size;
	while(count>0) {
		it=first;
		step=count/2;
		it+=step*size;
		if(!pred(2,val,it)) {
			first=it+size;
			it+=size;
			count-=step+1;
		} else
			count=step;
	}
	return first;
}
struct algo_pair algo_sorted_equal_range(size_t size,char* first,char* last,char* val,algo_predicate pred) {
	char* it=algo_sorted_lower_bound(size,first,last,val,pred);
	char* end=algo_sorted_upper_bound(size,it,last,val,pred);
	struct algo_pair retVal;
	retVal.first=it;retVal.second=end;
	return retVal;
}
bool algo_sorted_binary_search(size_t size,char* first,char* last,char* val,algo_predicate pred) {
	first=algo_sorted_lower_bound(size,first,last,val,pred);
	return (first!=last&&!(pred(2,val,first)));
}
char* algo_sorted_merge(size_t size,char* first1,char* last1,char* first2,char* last2,char* dest,algo_predicate pred,algo_copy_func copy) {
	for(;;) {
		if(first1==last1) return algo_copy(size,first2,last2,dest,copy);
		if(first2==last2) return algo_copy(size,first1,last1,dest,copy);
		bool which=pred(2,first2,first1);
		char* temp=which?first2:first1;
		if(which)
			first2+=size;
		else 
			first1+=size;
		algo_copy(size,temp,temp+size,dest,copy);
		dest+=size;
	}
}
bool aglo_sorted_includes(size_t size,char* first1,char* last1,char* first2,char* last2,algo_predicate pred) {
	while(first2,last2) {
		if((first1==last1)||(pred(2,first2,first1))) return false;
		if(!pred(2,first1,first2)) first2+=size;
		first1+=size;
	}
	return true;
}
char* algo_sorted_set_union(size_t size,char* first1,char* last1,char* first2,char* last2,char* dest,algo_predicate pred,algo_copy_func copy) {
	for(;;) {
		if(first1==last1) return algo_copy(size,first2,last2,dest,copy);
		if(first2==last2) return algo_copy(size,first1,last1,dest,copy);
		if(pred(2,first1,first2)) {
			algo_copy(size,first1,first1+size,dest,copy);
			first1+=size;
		} else if(pred(2,first2,first1)) {
			algo_copy(size,first2,first2+size,dest,copy);
			first2+=size;
		} else {
			
			first1+=size;
			first2+=size;
		}
		dest+=size;	
	}
}
char* algo_sorted_set_intersection(size_t size,char* first1,char* last1,char* first2,char* last2,char* dest,algo_predicate pred,algo_copy_func copy) {
	while(first1!=last1 && first2!=last2) {
		if(pred(2,first1,first2)) first1+=size;
		else if(pred(2,first2,first1)) first2+=size;
		else {
			copy(2,first1,dest);
			dest+=size;
			first1+=size;
			first2+=size;
		}
	}
	return dest;
}
char* algo_sorted_set_difference(size_t size,char* first1,char* last1,char* first2,char* last2,char* result,algo_predicate pred,algo_copy_func copy) {
	while(first1!=last1&&first2!=last2) {
		if(pred(2,first1,first2)) {
			copy(2,first1,result);
			result+=size;first1+=size;
		} else if(pred(2,first2,first1)) first2+=size;
		else {
			first1+=size;first2+=size;
		}
	}
	return algo_copy(size,first1,last1,result,copy);
}
char* __algo_sorted_symmetric_difference(size_t size,char* start1,char* end1,char* start2,char* end2,char* result,algo_predicate pred,algo_copy_func copy) {
	if(start1==end1) return algo_copy(size,start2,end2,result,copy);
	if(start1==end2) return algo_copy(size,start1,end1,result,copy);
	if(pred(2,start1,start2)) {
		copy(2,start1,result);
		result+=size;start1+=size;
	} else if(pred(2,start2,start1)) {
		copy(2,start2,result);
		result+=size;start2+=size;
	} else
		start1+=size,start2+=size;
}
#define algo_sorted_symmetric_difference(type,start1,end1,start2,end2,result,pred) __algo_sorted_symmetric_difference(sizeof(type),$AA(start1),$AA(end1),$AA(start2),$AA(end2),$AA(result),$AP(pred))
char* __algo_min_element(size_t size,char* first,char* end,algo_predicate pred) {
	if(first==end) return end;
	char* smallest=first;
	first+=size;
	while(first!=end)  {
		if(pred(2,first,smallest))
			smallest=first;
		first+=size;
	}
	return smallest;
} 
char* __algo_max_element(size_t size,char* first,char* last,algo_predicate pred) {
	if(first==last) return last;
	char* biggest=first;
	first+=size;
	while(first!=last)  {
		if(pred(2,biggest,first))
			biggest=first;
		first+=size;
	}
	return biggest;
}
#define algo_min_element(type,start,end,pred) __algo_min_element(sizeof(type),$AA(start),$AA(end),$AP(pred))
#define algo_max_element(type,start,end,pred) __algo_max_element(sizeof(type),$AA(start),$AA(end),$AP(pred))
struct algo_pair algo_minmax_element(size_t size,char* start,char* end,algo_predicate pred) {
	struct algo_pair retval;
	retval.first=__algo_min_element(size,start,end,pred);
	retval.second=__algo_max_element(size,start,end,pred);
	return retval;
}
bool algo_lexicographical_compare(size_t size,char* first1,char* last1,char* first2,char* last2,algo_predicate pred) {
	while(first1!=last1) {
		if(first2==last2 && pred(2,first2,first1)) return false;
		else if(pred(2,first1,first2)) return true;
		first1+=size;first2+=size;
	}
	return first2!=last2;
}
//https://www.nayuki.io/page/next-lexicographical-permutation-algorithm
bool __algo_next_permutation(size_t size,char* first,char* last,algo_predicate pred,algo_move_func move) {
	size_t length=(size_t)(last-first)/size;
	size_t i=length-1;
	while(i>0 && pred(2,first+i*size,first+(i-1)*size))
		i--;
	if(i<=0)
		return false;
	size_t j=length-1;
	while(pred(2,first+size*j,first+size*(i-1)))
		j--;
	__algo_swap(size,first+(i-1)*size,first+j*size,move);
	j=length-1;
	while(i<j) {
		__algo_swap(size,first+i*size,first+j*size,move);
		i++;j--;
	}
	return true;
}
bool __algo_prev_permutation(size_t size,char* first,char* last,algo_predicate pred,algo_move_func move) {
	size_t length=(size_t)(last-first)/size;
	size_t i=length-1;
	while(pred(2,first+size*(i-1),first+size*i))
		if(--i==0)
			return false;
	size_t j=i+1;
	while(j<length&&pred(2,first+size*j,first+size*(i-1)))
		j++;
	__algo_swap(size,first+size*(i-1),first+size*(j-1),move);
	__algo_reverse(size,first+i*size,last,move);
	return true;
}

#define algo_reverse(type,first,last,move) __algo_reverse(sizeof(type),$AA(first),$AA(last),$AF(move))
#define algo_swap(type,a,b,move) __algo_swap(sizeof(type),$AA(a),$AA(b),$AF(move))
#define algo_prev_permutation(type,first,last,pred,move) __algo_prev_permutation(sizeof(type),$AA(first),$AA(last),$AP(pred),$AF(move))
#define algo_next_permutation(type,first,last,pred,move) __algo_next_permutation(sizeof(type),$AA(first),$AA(last),$AP(pred),$AF(move))

//inplace_merge
//nth element
//stablwe partition
//partialSort
//stalbe sort
int main() {
	int list1[]={1,2,3};
	bool test(int argsNum,int* x,int* y) {
		return *x<=*y;
	}
	void* mover(int argc,int* in,int* out) {
		*out=*in;
	}
	while(algo_next_permutation(int,list1,list1+3,test,mover))
		printf("%i.%i.%i\n",list1[0],list1[1],list1[2]);
	return EXIT_SUCCESS;
}
