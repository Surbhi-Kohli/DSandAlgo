#include <bits/stdc++.h>
using namespace std;

int main() {
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
    cout<<s1<<endl;
    cout<<s2<<endl;
//     if(s1.length()!=s2.length())
//   {
//       cout<<"Not Permutations ";
//       return 0;
       
//   }
    int freq[26]={0};
    for(int i=0;i<s1.length();i++)
    {   if(s1[i]>='a'&& s1[i]<='z')
        freq[s1[i]-'a']++;
    }
    for(int j=0;j<s2.length();j++)
    {
        if(s2[j]>='a'&& s2[j]<='z')
        freq[s2[j]-'a']--;
    }
    for(int i=0;i<26;i++)
    {
        if(freq[i]!=0)
        {
            cout<<"Not Permutations ";
            return 0;
        }
    }
    cout<<"Permutations"<<endl;

	return 0;
}
