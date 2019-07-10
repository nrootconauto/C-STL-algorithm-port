# C port of the C++  STL algorithm library
This is a port of the C++ standard algorithm library. I love C and the C++ STL algorithm library so i implemented (most of it at the moment)  in C. **Be sure to use the src/C_algoithm.h**

## Using it
To use an algorithm,use the name,then the args in parenthesis with the first arg as the type,then your usual arguments,but keep in mind these things

 - `char*` is used as the default pointer type for all types,**but when used with the macros(that do not start with "__")the pointer types are automatically converted,EXCEPT for *the return* values- they are still  `char*`  type**
 - Functions that **delete,copy,move,or replace** have "extra" arguments to do such things. and are put at the end of the algorithms arguments are to **take the form** `char* name(int argc,char* in,char* out)`. thr return value isnt used and *argc* is an int that tells of the number of arguments being passed,and the `in` and `out` arguments represent the object to be moved current location and the position of the object that it is be moved to... for example,to call `algo_sorted_set_symmetric_difference`: make a function MOVE: `
int MOVE(int n,char* in,char* out) {*out=*in;}; `
then use it with your algorithm like `algo_sorted_set_symmetric_difference(char,start1,send1,start2,end2,output,predicate,MOVE)`
 - algorithms that are designed to **work with sorted ranges are prefixed with `algo_sorted_` instead of the normal `algo_` prefix** to avoid confusion
- Normal algorithms from STL are prefixed with `algo_`
- This currently uses gnu C extensions
## Example code
```
int main() {
	char a[]="zyxwde";
	char b[]="abcdef";
	char output[13];
	bool test2(int argc,char*x,char*y) {
		return *x<*y;
	}
	void* copyFunc(int n,char* in,char* out) {
		*out=*in;
	}
	bool testEq(int n,char* x,char* y) {
		return *x==*y;
	}
	algo_sort(char,a,a+6,test2,copyFunc);
	algo_sort(char,b,b+6,test2,copyFunc);
	*algo_sorted_set_symmetric_difference(char,a,a+6,b,b+6,output,test2,copyFunc)=0;
	//printf("%i\n",algo_sorted_includes(char,output,output+12,b,b+6,test2));
	printf("%s\n",output);
	return EXIT_SUCCESS;
}
```
