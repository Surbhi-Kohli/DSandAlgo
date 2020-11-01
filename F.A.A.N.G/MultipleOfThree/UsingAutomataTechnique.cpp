/*


Take a binary number , if this number multiple of 3 print 1 otherwise print 0.The given number can range upto 2^100.

To finish the task , it is recommended to use one traversal of input binary String.

Input Format
The first line contains T denoting the number of testcases. Each case contains a string containing 0's and 1's.

Constraints
1<=T<=100, 1<=Length of Input String<=100

Output Format
For each test case, print 1 if string is multiple of 3, else print 0.

Sample Input
2
011
100
Sample Output
1
0
Now, when it comes to DFA (Deterministic Finite Automata), there is no concept of memory i.e.
you cannot store the string when it is provided, so the above method would not be applicable.
In simple terms, a DFA takes a string as input and process it. If it reaches final state, it is accepted, 
else rejected. As you cannot store the string, so input is taken character by character.
As, when a number is divided by 3, there are only 3 possibilities. 
The remainder can be either 0, 1 or 2. Here, state 0 represents that the remainder when the number is divided by 3 is 0.
State 1 represents that the remainder when the number is divided by 3 is 1 and similarly state 2 represents 
that the remainder when the number is divided by 3 is 2. So if a string reaches state 0 in the end, it is accepted otherwise rejected.

Time Complexity:O(n)
*/
#include<iostream>
using namespace std;
int checkIfMultipleOfThree(string c)
{
	 char state = '0';
   int size=c.length();
    for (int i = 0; i < size; i++) {
 
        // storing binary digit
        char digit = c[i];
 
        switch (state) {
 
        // when state is 0
        case '0':
            if (digit == '1')
                state = '1';
            break;
 
        // when state is 1
        case '1':
            if (digit == '0')
                state = '2';
            else
                state = '0';
            break;
 
        // when state is 2
        case '2':
            if (digit == '0')
                state = '1';
            break;
        }
    }
 
    // if final state is 0th state
	if(state=='0')
   return 1;
  
  return 0;
}
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
	cout<<checkIfMultipleOfThree(s)<<endl;
	}
	return 0;
}
