/*
Take as input S, a string. Write a function that does basic string compression. Print the value returned. E.g. for input “aaabbccds” print out a3b2c2d1s1.

Input Format
A single String S

Constraints
1 < = length of String < = 100

Output Format
The compressed String.

Sample Input
aaabbccds
Sample Output
a3b2c2d1s1
Explanation
In the given sample test case 'a' is repeated 3 times consecutively, 'b' is repeated twice, 'c' is repeated twice and 'd and 's' occurred only once.

*/
#include<iostream>
using namespace std;
int main() {
    string s;
    cin>>s;
    int freq[26]={0};
    int l=s.length();
    char ch=s[0];
    freq[s[0]-'a']++;
    for(int i=1;i<l;i++)
    {   if(s[i]!=ch)
       {
           cout<<ch<<freq[ch-'a'];
           freq[ch-'a']=0;
          ch=s[i];
       }
        freq[s[i]-'a']++;
    }
    cout<<s[l-1]<<freq[s[l-1]-'a'];
  
	return 0;
}
