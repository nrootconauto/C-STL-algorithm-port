#ifndef C_STL_ALGO_PORT
#define C_STL_ALGO_PORT
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdarg.h>
#include <malloc.h>
typedef bool(*algo_predicate)(int numArgs,...);
typedef void (*algo_function)(int numArgs,...); 
#define $AP(predicate) (algo_predicate)(predicate)
#define $AF(func) (algo_function)(func)
#define $AA(argument) (char*)(argument)
typedef algo_function algo_move_func;
typedef algo_function algo_replace_func;
typedef algo_function algo_copy_func;
typedef algo_function algo_destroy_func;
void __algo_partial_sort(size_t size,char *start,char *middle,char *last,algo_predicate pred,algo_function move);
bool __algo_prev_permutation(size_t size,char *first,char *last,algo_predicate pred,algo_move_func move);
bool __algo_next_permutation(size_t size,char *first,char *last,algo_predicate pred,algo_move_func move);
bool __algo_lexicographical_compare(size_t size,char *first1,char *last1,char *first2,char *last2,algo_predicate pred);
struct algo_pair __algo_minmax_element(size_t size,char *start,char *end,algo_predicate pred);
char *__algo_max_element(size_t size,char *first,char *last,algo_predicate pred);
char *__algo_min_element(size_t size,char *first,char *end,algo_predicate pred);
char *__algo_sorted_set_symmetric_difference(size_t size,char *start1,char *end1,char *start2,char *end2,char *result,algo_predicate pred,algo_copy_func copy);
char *__algo_sorted_set_difference(size_t size,char *first1,char *last1,char *first2,char *last2,char *result,algo_predicate pred,algo_copy_func copy);
char *__algo_sorted_set_intersection(size_t size,char *first1,char *last1,char *first2,char *last2,char *dest,algo_predicate pred,algo_copy_func copy);
char *__algo_sorted_set_union(size_t size,char *first1,char *last1,char *first2,char *last2,char *dest,algo_predicate pred,algo_copy_func copy);
bool __algo_sorted_includes(size_t size,char *first1,char *last1,char *first2,char *last2,algo_predicate pred);
char *__algo_sorted_merge(size_t size,char *first1,char *last1,char *first2,char *last2,char *dest,algo_predicate pred,algo_copy_func copy);
bool __algo_sorted_binary_search(size_t size,char *first,char *last,char *val,algo_predicate pred);
struct algo_pair __algo_sorted_equal_range(size_t size,char *first,char *last,char *val,algo_predicate pred);
char *__algo_sorted_upper_bound(size_t size,char *first,char *last,char *val,algo_predicate pred);
char *__algo_sorted_lower_bound(size_t size,char *first,char *last,char *val,algo_predicate pred);
char *__algo_is_sorted_until(size_t size,char *first,char *last,algo_predicate pred);
bool __algo_is_sorted(size_t size,char *first,char *last,algo_predicate pred);
void __algo_sort(size_t size,char *start,char *end,algo_predicate pred,algo_move_func move);
char *__algo_partition_point(size_t size,char *start,char *end,algo_predicate pred);
struct algo_pair __algo_partition_copy(size_t size,char *first,char *last,char *destTrue,char *destFalse,algo_predicate pred,algo_copy_func copy);
char *__algo_partition(size_t size,char *first,char *last,algo_predicate pred,algo_move_func move);
bool __algo_is_partitioned(size_t size,char *first,char *last,algo_predicate pred);
void __algo_random_shuffle(size_t size,char *first,char *last,algo_move_func move);
char *__algo_rotate_copy(size_t size,char *first,char *middle,char *last,char *dest,algo_copy_func copyFunc);
void __algo_rotate(size_t size,char *first,char *middle,char *last,algo_replace_func replace);
char *__algo_reverse_copy(size_t size,char *first,char *last,char *dest,algo_function copyFunc);
void __algo_reverse(size_t size,char *first,char *last,algo_move_func move);
char *__algo_unique_copy(size_t size,char *first,char *last,char *dest,algo_predicate pred,algo_copy_func copy);
char *__algo_unique(size_t size,char *first,char *last,algo_predicate pred,algo_replace_func replacer);
char *__algo_remove_copy_if(size_t size,char *first,char *last,char *dest,algo_predicate pred,algo_copy_func copyFunc);
char *__algo_remove_if(size_t size,char *first,char *last,algo_predicate pred,algo_replace_func replacer);
void __algo_generate_n(size_t size,char *first,int n,algo_function gen);
void __algo_generate(size_t size,char *first,char *last,algo_function generator);
char *__algo_fill_n(size_t size,char *first,int howMany,char *value,algo_copy_func copy);
void __algo_fill(size_t size,char *first,char *last,char *value,algo_copy_func copy);
char *__algo_replace_if(size_t size,char *first,char *last,algo_predicate pred,char *newValue,algo_replace_func replacer);
void __algo_replace_copy_if(size_t size,char *first,char *last,char *dest,algo_predicate pred,char *newValue,algo_replace_func replacer);
char *__algo_transform(size_t size,char *first1,char *last1,char *dest,algo_function mutator);
char *__algo_swap_ranges(size_t size,char *first1,char *last1,char *first2,algo_move_func mover);
void __algo_swap(size_t size,char *a,char *b,algo_move_func mover);
char *__algo_move_backward(size_t size,char *first,char *last,char *dest,algo_move_func moveFunc);
char *__algo_move(size_t size,char *first,char *last,char *result,algo_move_func moveFunc);
char *__algo_copy_backward(size_t size,char *first,char *last,char *dest,algo_copy_func copyFunc);
char *__algo_copy_if(size_t size,char *first,char *last,char *dest,algo_predicate pred,algo_copy_func copyFunc);
char *__algo_copy_n(size_t size,char *first,int howMany,char *out,algo_copy_func copyFunc);
char *__algo_copy(size_t size,char *first,char *last,char *dest,algo_copy_func copyFunc);
char *__algo_search_n(size_t size,char *first,char *last,int n,char *val,algo_predicate pred);
char *__algo_search(size_t size,char *first1,char *last1,char *first2,char *last2,algo_predicate pred);
bool __algo_is_permutation(size_t size,char *first1,char *last1,char *first2,algo_predicate pred);
bool __algo_equal(size_t size,char *first1,char *last1,char *first2,algo_predicate pred);
struct algo_pair __algo_mismatch(size_t size,char *first1,char *last1,char *first2,algo_predicate pred);
int __algo_count_if(size_t size,char *first,char *last,algo_predicate pred);
char *__algo_adjacent_find(size_t size,char *first,char *last,algo_predicate pred);
char *__algo_find_first_of(size_t size,char *first1,char *last1,char *selectionStart,char *selectionEnd,algo_predicate pred);
char *__algo_find_end(size_t size,char *first1,char *last1,char *first2,char *last2,algo_predicate pred);
char *__algo_find_if_not(size_t size,char *first,char *last,algo_predicate pred);
char *__algo_find_if(size_t size,char *first,char *last,algo_predicate pred);
void __algo_for_each(size_t size,char *first,char *end,algo_function func);
bool __algo_none_of(size_t size,char *first,char *end,algo_predicate pred);
bool __algo_any_of(size_t size,char *first,char *last,algo_predicate pred);
bool __algo_all_of(size_t size,char *first,char *last,algo_predicate pred);
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
//tested
#define algo_make_heap(type,start1,end1,comp,move) __algo_make_heap(sizeof(type),$AA(start1),$AA(end1),$AP(comp),$AF(move))
//tested
#define algo_push_heap(type,start,end,comp,move) __algo_push_heap(sizeof(type),$AA(start),$AA(end),$AP(comp),$AF(move))
//tested
#define algo_pop_heap(type,start,end,comp,move) __algo_pop_heap(sizeof(type),$AA(start),$AA(end),$AP(comp),$AF(move))
//tested
#define algo_sort_heap(type,start,end,comp,move) __algo_sort_heap(sizeof(type),$AA(start),$AA(end),$AP(comp),$AF(move))
//tested
#define algo_partial_sort(type,start,middle,end,comp,move) __algo_partial_sort(sizeof(type),$AA(start),$AA(middle),$AA(end),$AP(comp),$AF(move))

#endif
