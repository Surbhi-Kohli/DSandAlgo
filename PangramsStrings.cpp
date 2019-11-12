/*
Roy wanted to increase his typing speed for programming contests. His friend suggested that 
he type the sentence "The quick brown fox jumps over the lazy dog" repeatedly. This sentence is known as a pangram because it contains every letter of the alphabet.

After typing the sentence several times, Roy became bored with it so he started to look for other pangrams.

Given a sentence, determine whether it is a pangram. Ignore case.

Function Description

Complete the function pangrams in the editor below. It should return the string pangram if the input string is a pangram. Otherwise, it should return not pangram.

pangrams has the following parameter(s):

s: a string to test
Input Format

Input consists of a string s.
Constraints
0<|s|<10^3

Each character of s,s[i]E{A-Z,a-z,space} 

Output Format

Output a line containing pangram if s is a pangram, otherwise output not pangram.

Sample Input 0
We promptly judged antique ivory buckles for the next prize

Sample Output 0
pangram

Sample Explanation 0
All of the letters of the alphabet are present in the string.

Sample Input 1

We promptly judged antique ivory buckles for the prize

Sample Output 1
not pangram

Sample Explanation 0
The string lacks an x.

*/
string pangrams(string s) {
int lower[26]={0};
int upper[26]={0};
int n=s.length();
int flag=0;
for(int i=0;i<n;i++)
{ //cout<<s[i]<<endl;
    if(s[i]>='a' && s[i]<='z')
    {
          lower[s[i]-'a']++;
          
    }
    
    else if(s[i]>='A' && s[i]<='Z')
    {
        upper[s[i]-'A']++;
       
    }
    
}

for(int i=0;i<26;i++)
{ 
    if(lower[i]==0 && upper[i]==0)
    {
        flag=1;
        break;
    }
}

if(flag==1)
return "not pangram";
return "pangram";
}
