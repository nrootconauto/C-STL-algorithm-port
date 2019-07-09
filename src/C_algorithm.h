#ifndef C_STL_ALGO_PORT
#define C_STL_ALGO_PORT
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
//header for C STL algorithm port
//tested
#define algo_all_of(type,first,last,pred) __algo_all_of(sizeof(type),$AA(first),$AA(last),$AP(pred))
//tested
#define algo_any_of(type,first,last,pred) __algo_any_of(sizeof(type),$AA(first),$AA(last),$AP(pred))
//tested
#define algo_none_of(type,first,last,pred) __algo_any_of(sizeof(type),$AA(first),$AA(last),$AP(pred))
//tested
#define algo_for_each(type,first,end,func) __algo_for_each(sizeof(type),$AA(first),$AA(end),$AF(func))
//tested
#define algo_find_if(type,first,last,pred) __algo_find_if(sizeof(type),$AA(first),$AA(last),$AP(pred))
//tested
#define algo_find_if_not(type,first,last,pred) __algo_find_if_not(sizeof(type),$AA(first),$AA(last),$AP(pred))
//tested
#define algo_find_end(type,first1,last1,first2,last2,pred) __algo_find_end(sizeof(type),$AA(first1),$AA(last1),$AA(first2),$AA(last2),$AP(pred))
//tested
#define algo_find_first_of(type,first1,last1,selectionStart,selectionEnd,pred) __algo_find_first_of(sizeof(type),$AA(first1),$AA(last1),$AA(selectionStart),$AA(selectionEnd),$AP(pred))
//tested
#define algo_adjacent_find(type,first,last,pred) __algo_adjacent_find(sizeof(type),$AA(first),$AA(last),$AP(pred))
//tested
#define algo_count_if(type,first,last,pred) __algo_count_if(sizeof(type),$AA(first),$AA(last),$AP(pred))
//tested
#define algo_mismatch(type,first1,last1,first2,pred) __algo_mismatch(sizeof(type),$AA(first1),$AA(last1),$AA(first2),$AP(pred))
//tested
#define algo_equal(type,first1,last1,first2,pred) __algo_equal(sizeof(type),$AA(first1),$AA(last1),$AA(first2),$AP(pred))
//tested
#define algo_is_permutation(type,first1,last1,first2,pred) __algo_is_permutation(sizeof(type),$AA(first1),$AA(last1),$AA(first2),$AP(pred))
//tested
#define algo_search(type,first1,last1,first2,last2,pred) __algo_search(sizeof(type),$AA(first1),$AA(last1),$AA(first2),$AA(last2),$AP(pred))
//tested
#define algo_search_n(type,first,last,n,val,pred) __algo_search_n(sizeof(type),$AA(first),$AA(last),n,$AA(val),$AP(pred))
//tested
#define algo_copy(type,first,last,dest,copyFunc) __algo_copy(sizeof(type),$AA(first),$AA(last),$AA(dest),$AF(copyFunc))
//tested
#define algo_copy_n(type,first,howMany,out,copyFunc) __algo_copy_n(sizeof(type),$AA(first),howMany,$AA(out),$AF(copyFunc))
//tested
#define algo_copy_if(type,first,last,dest,pred,copyFunc) __algo_copy_if(sizeof(type),$AA(first),$AA(last),$AA(dest),$AP(pred),$AF(copyFunc))
//tested
#define algo_copy_backward(type,first,last,dest,copyFunc) __algo_copy_backward(sizeof(type),$AA(first),$AA(last),$AA(dest),$AF(copyFunc))
//tested
#define algo_move(type,first,last,dest,moveFunc) __algo_move(sizeof(type),$AA(first),$AA(last),$AA(dest),$AF(moveFunc))
//tested
#define algo_move_backward(type,first,last,dest,moveFunc) __algo_move_backward(sizeof(type),$AA(first),$AA(last),$AA(dest),$AF(moveFunc))
//tested
#define algo_swap(type,a,b,mover) __algo_swap(sizeof(type),$AA(a),$AA(b),$AF(mover))
//ranges
#define algo_swap_ranges(type,first1,last1,first2,mover) __algo_swap_ranges(sizeof(type),$AA(first1),$AA(last1),$AA(first2),$AF(mover))
//NOTE:HAS IN OUT-DOESNT DO ANYTHING WITH RETURN
//TESTED*
#define algo_transform(type,first1,last1,dest,mutator) __algo_transform(sizeof(type),$AA(first1),$AA(last1),$AA(dest),$AF(mutator))
//tested
#define algo_replace_copy_if(type,first,last,dest,pred,newValue,replacer) __algo_replace_copy_if(sizeof(type),$AA(first),$AA(last),$AA(dest),$AP(pred),$AA(newValue),$AF(replacer))
//tested
#define algo_replace_if(type,first,last,pred,newValue,replacer) __algo_replace_if(sizeof(type),$AA(first),$AA(last),$AP(pred),$AA(newValue),$AF(replacer))
//tested
#define algo_fill(type,first,last,value,copy) __algo_fill(sizeof(type),$AA(first),$AA(last),$AA(value),$AF(copy))
//tested
#define algo_fill_n(type,first,howMany,value,copy) __algo_fill_n(sizeof(type),$AA(first),howMany,$AA(value),$AF(copy))
//tested
#define algo_generate(type,first,last,generator)__algo_generate(sizeof(type),$AA(first),$AA(last),$AF(generator))
//tested
#define algo_generate_n(type,first,n,gen) __algo_generate_n(sizeof(type),$AA(first),n,$AF(gen))
//tested
#define algo_remove_if(type,first,last,pred,replacer) __algo_remove_if(sizeof(type),$AA(first),$AA(last),$AP(pred),$AF(replacer))
//tested
#define algo_remove_copy_if(type,first,last,dest,pred,copyFunc) __algo_remove_copy_if(sizeof(type),$AA(first),$AA(last),$AA(dest),$AP(pred),$AF(copyFunc))
//removes all but one of uitms with conesecutive values
//tested
#define algo_unique(type,first,last,pred,replacer) __algo_unique(sizeof(type),$AA(first),$AA(last),$AP(pred),$AF(replacer))
//tested
#define algo_unique_copy(type,first,last,dest,pred,copy) __algo_unique_copy(sizeof(type),$AA(first),$AA(last),$AA(dest),$AP(pred),$AF(copy))
//tested
#define algo_reverse_copy(type,first,last,dest,copyFunc) __algo_reverse_copy(sizeof(type),$AA(first),$AA(last),$AA(dest),$AF(copyFunc))
//tested
#define algo_rotate(type,first,middle,last,replace) __algo_rotate(sizeof(type),$AA(first),$AA(middle),$AA(last),$AF(replace))
//tested
#define algo_rotate_copy(type,first,middle,last,dest,copyFunc) __algo_rotate_copy(sizeof(type),$AA(first),$AA(middle),$AA(last),$AA(dest),$AF(copyFunc))
//tested,its random
#define algo_random_shuffle(type,first,last,move) __algo_random_shuffle(sizeof(type),$AA(first),$AA(last),$AF(move))
//tested
#define algo_is_partitioned(type,first,last,pred) __algo_is_partitioned(sizeof(type),$AA(first),$AA(last),$AP(pred))
//tested
#define algo_partition(type,first,last,pred,move) __algo_partition(sizeof(type),$AA(first),$AA(last),$AP(pred),$AF(move))
//tested
#define algo_partition_copy(type,first,last,destTrue,destFalse,pred,copy) __algo_partition_copy(sizeof(type),$AA(first),$AA(last),$AA(destTrue),$AA(destFalse),$AP(pred),$AF(copy))
//tested
#define algo_partition_point(type,start,end,pred) __algo_partition_point(sizeof(type),$AA(start),$AA(end),$AP(pred))
//tested
#define algo_sort(type,start,end,pred,move) __algo_sort(sizeof(type),$AA(start),$AA(end),$AP(pred),$AF(move))
//tested
#define algo_is_sorted(type,first,last,pred) __algo_is_sorted(sizeof(type),$AA(first),$AA(last),$AP(pred))
//tested
#define algo_is_sorted_until(type,first,last,pred)__algo_is_sorted_until(sizeof(type),$AA(first),$AA(last),$AP(pred))
//tested
#define algo_sorted_lower_bound(type,first,last,val,pred) __algo_sorted_lower_bound(sizeof(type),$AA(first),$AA(last),$AA(val),$AP(pred))
//tested
#define algo_sorted_upper_bound(type,first,last,val,pred) __algo_sorted_upper_bound(sizeof(type),$AA(first),$AA(last),$AA(val),$AP(pred))
//tested
#define algo_sorted_equal_range(type,first,last,val,pred) __algo_sorted_equal_range(sizeof(type),$AA(first),$AA(last),$AA(val),$AP(pred))
//tested
#define algo_sorted_binary_search(type,first,last,val,pred) __algo_sorted_binary_search(sizeof(type),$AA(first),$AA(last),$AA(val),$AP(pred))
//tested
#define algo_lexicographical_compare(type,first1,last1,first2,last2,pred)__algo_lexicographical_compare(sizeof(type),$AA(first1),$AA(last1),$AA(first2),$AA(last2),$AP(pred))
//tested
#define algo_next_permutation(type,first,last,pred,move) __algo_next_permutation(sizeof(type),$AA(first),$AA(last),$AP(pred),$AF(move))
//tested
#define algo_reverse(type,first,last,move) __algo_reverse(sizeof(type),$AA(first),$AA(last),$AF(move))
//tested
#define algo_prev_permutation(type,first,last,pred,move) __algo_prev_permutation(sizeof(type),$AA(first),$AA(last),$AP(pred),$AF(move))
//tested
#define algo_max_element(type,start,end,pred) __algo_max_element(sizeof(type),$AA(start),$AA(end),$AP(pred))
//tested
#define algo_min_element(type,start,end,pred) __algo_min_element(sizeof(type),$AA(start),$AA(end),$AP(pred))
//tested
#define algo_minmax_element(type,start,end,pred)__algo_minmax_element(sizeof(type),$AA(start),$AA(end),$AP(pred))
//tested
#define algo_sorted_merge(type,first1,last1,first2,last2,dest,pred,copy) __algo_sorted_merge(sizeof(type),$AA(first1),$AA(last1),$AA(first2),$AA(last2),$AA(dest),$AP(pred),$AF(copy))
//tested
#define algo_sorted_includes(type,first1,last1,first2,last2,pred) __algo_sorted_includes(sizeof(type),$AA(first1),$AA(last1),$AA(first2),$AA(last2),$AP(pred))
//tested
#define algo_sorted_set_intersection(type,first1,last1,first2,last2,dest,pred,copy)__algo_sorted_set_intersection(sizeof(type),$AA(first1),$AA(last1),$AA(first2),$AA(last2),$AA(dest),$AP(pred),$AF(copy))
//tested,output is with respect to 2
#define algo_sorted_set_difference(type,first1,last1,first2,last2,result,pred,copy)__algo_sorted_set_difference(sizeof(type),$AA(first1),$AA(last1),$AA(first2),$AA(last2),$AA(result),$AP(pred),$AF(copy))
//tested
#define algo_sorted_set_symmetric_difference(type,start1,end1,start2,end2,result,pred,copy) __algo_sorted_set_symmetric_difference(sizeof(type),$AA(start1),$AA(end1),$AA(start2),$AA(end2),$AA(result),$AP(pred),$AF(copy))
#include "../headers/maxHeap.h"
#endif
