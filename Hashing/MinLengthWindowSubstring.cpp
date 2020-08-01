#include <iostream>
#include <unordered_map>
#include <climits>
#include <algorithm>
using namespace std;
string smallestWindow(string s,string pat)
{
    int len1=s.length();
    int len2=pat.length();
    cout<<"len1 is "<<len1<<endl;
    cout<<"len2 is "<<len2<<endl;
    int count=0;
    int start=0,start_index=-1;
    int min_len=INT_MAX;
    if(len1<len2)
    {
        cout<<"No such window exists"<<endl;
        return " ";
    }
 int hash_str[256]={0};
 int hash_ptr[256]={0};
 for(int i=0;i<len2;i++)
  hash_ptr[pat[i]]++;
  
  for(int j=0;j<len1;j++)
  {  cout<<"j is "<<j<<endl;
     cout<<"character in contention is "<<s[j]<<endl;
      hash_str[s[j]]++;
      if(hash_ptr[s[j]]!=0 && hash_str[s[j]]<=hash_ptr[s[j]])
      {
          cout<<"char exists in pat and its occurrence in s is less than pat as of now"<<endl;
           count++;
      }
     
      cout<<count<<endl;
      if(count==len2)
      {  cout<<"count is len2 now"<<endl;
     
     
        while(hash_str[s[start]] > hash_ptr[s[start]] || hash_ptr[s[start]]==0)
        {  //cout<<"in while loop of if"<<endl;
           if(hash_str[s[start]]>hash_ptr[s[start]]) 
           { // cout<<"this if was prob"<<endl;
               hash_str[s[start]]-=1;
           }
           start++;
        }
        cout<<"Start is "<<start<<endl;
        cout<<"j is "<<j<<endl;
        
         int len=j-start+1;
         cout<<"len is "<<len<<endl;
        if(len<min_len)
        {
          min_len=len;
          start_index=start;
        } 
        cout<<"min length till now is "<<min_len<<endl;
       }
     
    
  }
  if(start_index==-1)
  {
      cout<<"no window"<<endl;
      return " ";
  }
  cout<<"min length window is "<<min_len<<endl;
  return s.substr(start_index,min_len);
    
}
int main() {
	string s,pat;
getline(cin,s);
getline(cin,pat);

cout<<smallestWindow(s,pat);

	return 0;
}
