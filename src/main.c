#include "C_algorithm.h"
//inplace_merge
//nth element
//stablwe partition
//partialSort
//stalbe sort
int main() {
	char a[]="123459xxxx";
	bool test(int n,char*a ,char*b) {
		return *a<*b;
	}
	char* move(int n,char* a,char* b) {
		*b=*a;
	}
	char output[10];
	heapify(sizeof(char),a,a+5,$AP(test),$AF(move));
	push_heap(1,a,a+6,$AP(test),$AF(move));
	pop_heap(1,a,a+6,$AP(test),$AF(move));
	printf("%s\n",a);
	return EXIT_SUCCESS;
}
