/*
Maximum length substring having all same characters after k changes
We have a string of length n, which consist only UPPER and LOWER CASE characters and we have a number k 
(always less than n and greater than 0). We can make at most k changes in our string such that we 
can get a sub-string of maximum length which have all same characters.

Examples:

n = length of string
k = changes you can make
Input : n = 5 k = 2
        str = ABABA
Output : maximum length = 5
which will be (AAAAA)

Input : n = 6 k = 4
       str = HHHHHH
Output : maximum length=6
which will be(HHHHHH)
We check for each character of English alphabet (both upper and lower cases one by one). We are basically looking
for maximum length of sub-string that can be formed by each character and whichever character will form the 
sub-string of maximum length then that length will be our answer.

*/
// C++ program to find maximum length equal 
// character string with k changes 
#include <iostream> 
using namespace std; 

// function to find the maximum length of 
// substring having character ch 
int findLen(string A, int n, int k, char ch) 
{ 
	int maxlen = 1; 
	int cnt = 0; 
	int l = 0, r = 0; 
	
	// traverse the whole string 
	while (r < n) { 
	
		/* if character is not same as ch 
		increase count */
		if (A[r] != ch) 
			++cnt; 

		/* While count > k traverse the string 
		again until count becomes less than k 
		and decrease the count when characters 
		are not same */
		while (cnt > k) { 
			if (A[l] != ch) 
				--cnt; 
			++l; 
		} 

		/* length of substring will be rightIndex - 
		leftIndex + 1. Compare this with the maximum 
		length and return maximum length */
		maxlen = max(maxlen, r - l + 1); 
		++r; 
	} 
	return maxlen; 
} 

// function which returns maximum length of substring 
int answer(string A, int n, int k) 
{ 
	int maxlen = 1; 
	for (int i = 0; i < 26; ++i) { 
		maxlen = max(maxlen, findLen(A, n, k, i+'A')); 
		maxlen = max(maxlen, findLen(A, n, k, i+'a')); 
	} 
	return maxlen; 
} 

// Driver code 
int main() 
{ 
	int n = 5, k = 2; 
	string A = "ABABA"; 
	cout << "Maximum length = " << answer(A, n, k) << endl; //5

	n = 6, k = 4; 
	string B = "HHHHHH"; 
	cout << "Maximum length = " << answer(B, n, k) << endl;  //6
	return 0; 
} 
