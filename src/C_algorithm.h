/* This file was automatically generated.  Do not edit! */
#undef INTERFACE
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
