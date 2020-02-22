/*
Sanket has a string consisting of only 'a' and 'b' as the characters. Sanket describes perfectness of a string as the maximum length substring of equal characters. Sanket is given a number k which denotes the maximum number of characters he can change. Find the maximum perfectness he can generate by changing no more than k characters.

Input Format
The first line contains an integer denoting the value of K. The next line contains a string having only ‘a’ and ‘b’ as the characters.

Constraints
2 ≤ N ≤ 10^5

Output Format
A single integer denoting the maximum perfectness achievable.

Sample Input
2
abba
Sample Output
4
*/
#include<bits/stdc++.h>
using namespace std;
int findLen(string str,int n,int k,char ch){
	int maxlen=1,cnt=0,l=0,r=0;
	while(r<n)
	{
		if(str[r]!=ch)
		++cnt;

		while(cnt>k)
		{
			if(str[l]!=ch)
			--cnt;
			l++;
		}
		maxlen=max(maxlen,r-l+1);
		++r;
	}
	return maxlen;

}
int answer(string a,int n,int k)
{
	int maxlen=1;
	for(int i=0;i<2;i++)
    {
		maxlen=max(maxlen,findLen(a,n,k,i+'a'));
	}
	return maxlen;
}
int main() {
	int k;
	cin>>k;
	string str;
	cin>>str;
	int n=str.length();
	cout<<answer(str,n,k);
	return 0;
}
