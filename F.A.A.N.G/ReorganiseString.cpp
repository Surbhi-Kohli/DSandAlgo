/*
Consider a string S, the task is to find if the letters can be rearranged so that two characters that are adjacent to each other are not the same.
If not possible, return the empty string else return the output string.

Input Format
A single line contains the string.

Constraints
Note: The String will consist of lowercase letters and have length in range [1, 500].

Output Format
Print the Output string if possible else print empty string

Sample Input
S = "aab"
Sample Output
aba

*/
#include<iostream>
#include <queue>
using namespace std;
int main() {
	string s;
	cin>>s;
	int freq[26]={0};
for(int i=0;i<s.length();i++)
{
	freq[(int)(s[i]-'a')]++;
}
  priority_queue<pair<int,char>> pq;
 for(int i=0;i<26;i++)
 {
	 if(freq[i]!=0)
	 {
		 pq.push(make_pair(freq[i],(char)(i+'a')));
	 }
 }
 string ans="";
 while(!pq.empty())
 {
	 if(pq.size()>=2)
	 {
	 pair<int,char> p1;
	 pair<int,char> p2;
	 p1=pq.top();
	 pq.pop();
	 p2=pq.top();
	 pq.pop();
	 ans+=p1.second;
	 ans+=p2.second;
	 p1.first--;
	 p2.first--;
	 if(p1.first>0)
	 pq.push(make_pair(p1.first,p1.second));

	 if(p2.first>0)
	 pq.push(make_pair(p2.first,p2.second));
 }
 else if(pq.size()==1)
 {
	 if(pq.top().first>1)
	 ans="";
	 else
	 ans+=pq.top().second;
	
	 pq.pop();
 }
 }
cout<<ans;
	return 0;
}
