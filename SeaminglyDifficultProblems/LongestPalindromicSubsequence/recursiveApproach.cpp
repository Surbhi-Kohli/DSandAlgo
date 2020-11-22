#include <iostream>
using namespace std;
int helper(string s,int i,int j)
    {
        if(i==j) //i==j also occurs wen our palindrome is odd length
            return 1;
        
        if(i+1==j && s[i]==s[j])//occurs for the case wen our palindromic subsequence is even length
            return 2;
        
        else if(s[i]!=s[j])
        {
            return max(helper(s,i+1,j),helper(s,i,j-1));
        }
        
        return 2+helper(s,i+1,j-1);
        
    }
    int longestPalindromeSubseq(string s) {
        return helper(s,0,s.length()-1);
    }
int main() {
	string s;
	cin>>s;
	cout<<longestPalindromeSubseq(s);
	return 0;
}
