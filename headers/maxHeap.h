#include "../src/C_algorithm.h"
void __sift_down(size_t size,char* start,char* end,size_t node,size_t len,algo_predicate comp,algo_function move);
void __sift_up(size_t size,char* start,char* end,size_t node,size_t len,algo_predicate comp,algo_function move);
void __algo_make_heap(size_t size,char* start,char* end,algo_predicate comp,algo_function move);
void __algo_push_heap(size_t size,char* start,char* end,algo_predicate pred,algo_function move);
void __algo_pop_heap(size_t size,char* start,char* end,algo_predicate comp,algo_function move);
void __algo_sort_heap(size_t size,char* start,char* end,algo_predicate comp,algo_function move);
