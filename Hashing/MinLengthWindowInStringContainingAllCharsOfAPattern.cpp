/*
Ravi has been given two strings named string1 and string 2. He is supposed to find the minimum length substring of the string1 which 
contains all the characters of string2. Help him to find the substring

Input Format
The first line of the input contains string1. String1 can be a string containing spaces also. The second line of the input contains 
string2. String2 can be a string containing spaces also.

Constraints
Length of both the strings can be at max 10^4

Output Format
Output the substring in a single line. If no such substring exist then output "No String" without quotes

Sample Input
qwerty asdfgh qazxsw
qas
Sample Output
qazxs
Explanation
The substring "qazxs" is the shortest substring of s1 that contains all the characters of s2.

*/
#include<bits/stdc++.h> 
using namespace std;
const int no_of_chars = 256; 
  
// Function to find smallest window containing 
// all characters of 'pat' 
string findSubString(string str, string pat) 
{ 
    int len1 = str.length(); 
    int len2 = pat.length(); 
  
    // check if string's length is less than pattern's 
    // length. If yes then no such window can exist 
    if (len1 < len2) 
    { 
        cout << "No string"; 
        return ""; 
    } 
  
    int hash_pat[no_of_chars] = {0}; 
    int hash_str[no_of_chars] = {0}; 
  
    // store occurrence ofs characters of pattern 
    for (int i = 0; i < len2; i++) 
        hash_pat[pat[i]]++; 
  
    int start = 0, start_index = -1, min_len = INT_MAX; 
  
    // start traversing the string 
    int count = 0; // count of characters 
    for (int j = 0; j < len1 ; j++) 
    { 
        // count occurrence of characters of string 
        hash_str[str[j]]++; 
  
        // If string's char matches with pattern's char 
        // then increment count 
        if (hash_pat[str[j]] != 0 && 
            hash_str[str[j]] <= hash_pat[str[j]] ) 
            count++; 
  
        // if all the characters are matched 
        if (count == len2) 
        { 
            // Try to minimize the window i.e., check if any character is occurring more no. of times 
            // than its occurrence in pattern, if yes 
            // then remove it from starting and also remove 
            // the useless characters. 
            while ( hash_str[str[start]] > hash_pat[str[start]] || hash_pat[str[start]] == 0) 
            {
                if (hash_str[str[start]] > hash_pat[str[start]]) 
                    hash_str[str[start]]--; 
                start++; 
            } 
  
            // update window size 
            int len_window = j - start + 1; 
            if (min_len > len_window) 
            { 
                min_len = len_window; 
                start_index = start; 
            } 
        } 
    } 
  
    // If no window found 
    if (start_index == -1) 
    { 
    cout << "No string"; 
    return ""; 
    } 
  
    // Return substring starting from start_index 
    // and length min_len 
    return str.substr(start_index, min_len); 
} 
 
int main() {
    string str1,str2;
    getline(cin,str1);
    getline(cin,str2); 
    cout<<findSubString(str1,str2);
	return 0;
}
