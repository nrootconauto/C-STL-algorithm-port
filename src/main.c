#include "../headers/C_algorithm.h"
//inplace_merge
//nth element
//stablwe partition
//partialSort
//stalbe sort
int main() {
	char a[]="abcdefghijklmnopqrtuvwxyz";
	bool test(int n,char*a ,char*b) {
		return *a>*b;
	}
	char* move(int n,char* a,char* b) {
		*b=*a;
	}
	char output[sizeof(a)];
	output[sizeof(a)-1]=0;
	algo_partial_sort(char,a,a+5,a+25,test,move);
	//algo_make_heap(sizeof(char),a,a+5,$AP(test),$AF(move));
	//algo_push_heap(1,a,a+6,$AP(test),$AF(move));
	//pop_heap(1,a,a+6,$AP(test),$AF(move));
	//algo_sort_heap(1,a,a+6,$AP(test),$AF(move));
	printf("%s\n",a);
	return EXIT_SUCCESS;
}
