// Permutation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>    // std::swap

// Recursive start: e.g. Permutation of 5 chars "ABCDE"
// initially i(0) n(4) pass to first recursion
// i(0) != n(4) -> else
//	 for j(0) -> 
//	 swap a[i] a[j] (swap a[0] a[0]: no swap happens)	=>> enter 2nd level recursion (pass i+1, n)
//		i+1(1) != n(4) -> else
//		for j(1) -> 
//		swap a[i] a[j] (swap a[1] a[1]: no swap happens)	=>>  enter 3rd level recursion (pass i+1, n)
//			i+1(2) != n(4) -> else	
//			for j(2) -> 
//			swap a[i] a[j] (swap a[2] a[2]: no swap happens)	=>>  enter 4th level recursion (pass i+1, n) 
//				i+1(3) != n(4) -> else
//				for j(3) -> 
//				swap a[i] a[j] (swap a[3] a[3]: no swap happens)	=>>  enter 5th level recursion (pass i+1, n) 
//					i+1(4) == n(4) ->  OUTPUT a[] (ABCDE),  <<=  return to 4rd level recursion
//				swap BACK a[i] a[j] (swap a[3] a[3]: no swap happens)
//
//				j++ (j=4)
//				for j(4) -> 
//				swap a[i] a[j] (swap a[3] a[4]: ABCED swap happens) =>>  enter 5th level recursion (pass i+1, n) 
//					i+1(4) == n(4) ->  OUTPUT a[] (ABCED),  <<=  return to 4rd level recursion
//				swap BACK a[i] a[j] (swap a[3] a[4]: ABCDE swap back)
//				j++ (j=5) -> exit for loop   <<== return to 3rd level  recursion
//			swap BACK a[i] a[j] (swap a[2] a[2]: no swap happens)
//			
//			j++ (3)
//			for j(3) -> 
//			swap a[i] a[j] (swap a[2] a[3]: ABDCE swap happens)	=>>  enter 4th level recursion (pass i+1, n) 
//				i+1(3) != n(4) -> else
//				for j(3) -> 
//				swap a[i] a[j] (swap a[3] a[3]: no swap happens)	=>>  enter 5th level recursion (pass i+1, n) 
//					i+1(4) == n(4) ->  OUTPUT a[] (ABDCE),  <<=  return to 4rd level recursion
//				swap BACK a[i] a[j] (swap a[3] a[3]: no swap happens)
//
//				j++ (j=4)
//				for j(4) -> 
//				swap a[i] a[j] (swap a[3] a[4]: ABDEC swap happens) =>>  enter 5th level recursion (pass i+1, n) 
//					i+1(4) == n(4) ->  OUTPUT a[] (ABDEC),  <<=  return to 4rd level recursion
//				swap BACK a[i] a[j] (swap a[3] a[4]: ABDCE swap back)
//				j++ (j=5) -> exit for loop   <<== return to 3rd level  recursion
//			swap BACK a[i] a[j] (swap a[2] a[3]: ABCDE swap back)		
//
//			j++(4)
//			for j(4) -> 
//			swap a[i] a[j] (swap a[2] a[4]: ABEDC swap happens)	=>>  enter 4th level recursion (pass i+1, n) 
//				i+1(3) != n(4) -> else
//				for j(3) -> 
//				swap a[i] a[j] (swap a[3] a[3]: no swap happens)	=>>  enter 5th level recursion (pass i+1, n) 
//					i+1(4) == n(4) ->  OUTPUT a[] (ABEDC),  <<=  return to 4rd level recursion
//				swap BACK a[i] a[j] (swap a[3] a[3]: no swap happens)
//
//				j++ (j=4)
//				for j(4) -> 
//				swap a[i] a[j] (swap a[3] a[4]: ABECD swap happens) =>>  enter 5th level recursion (pass i+1, n) 
//					i+1(4) == n(4) ->  OUTPUT a[] (ABECD),  <<=  return to 4rd level recursion
//				swap BACK a[i] a[j] (swap a[3] a[4]: ABEDC swap back)
//				j++ (j=5) -> exit for loop   <<== return to 3rd level  recursion
//			swap BACK a[i] a[j] (swap a[2] a[4]: ABCDE swap back)	
//			
//			j++(j=5)  -> exit for loop   <<== return to 2nd level  recursion
//		swap BACK a[i] a[j] (swap a[1] a[1]: no swap happens)	
//
//		j++(2)
//		for j(2) -> 
//		swap a[i] a[j] (swap a[1] a[2]: ACBDE swap happens)	=>>  enter 3rd level recursion (pass i+1, n)
//		... ...
//		... ...

void permute(char a[], int i, int n, int* count)
{
	int j;

	if (i == n) {
		std::cout << a << std::endl;
		(*count)++;	//debug purpose
	}
	else
	{
		for (j = i; j <= n; j++)
		{
			std::swap(a[i], a[j]);
			permute(a, i + 1, n, count);
			std::swap(a[i], a[j]);
		}
	}
}

int main()
{
	char a[] = "ABCDE";
	int counts = 0;
	permute(a, 0, 4, &counts);
	printf("total Permute count is : %d\n", counts);
	getchar();
	return 0;
}
