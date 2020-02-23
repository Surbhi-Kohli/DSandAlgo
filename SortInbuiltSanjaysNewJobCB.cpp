/* Sanjay's new job-
In his new job,Sanjay gets a list of employees with their salary.The maximum salary is Rs 100.
Sanjay is supposed to arrange the list in such a manner that the list is sorted in decreasing order of salary &
if 2 employees have the same salary,they should be arranged in lexicographical manner such that the 
list contains only names of those employees having salary greater than or equal to a given number x
Help Sanjay prepare the same.
Input Format:
1st line:integer x
2nd line:integer N (no of employees)
next N lines
name salary

constraints:
1<=N<=10^5
1<=length of the name<=100
1<=x,salary<=100
Example:
Input                   Output
79                        Bob 99  
4                         Alex 86 
Eve 79                    Suzy 86
Bob 99
Alex 86 
Suzy 86

*/
#include<bits/stdc++.h>
using namespace std;
bool compare(pair <string,int> p1 ,pair <string,int> p2)
{
  if(p1.second==p2.second)
  return p1.first<p2.first;
    
    return p1.second>p2.second;//else sorted in descending order of length
    
   
}
int main() {

   int min_salary,n;
   pair<string,int> emp[100005];
   cin>>min_salary;
   cin>>n;
   string name;
   int salary;
   for(int i=0;i<n;i++)
   {
       cin>>name>>salary;
       emp[i].first=name;
       emp[i].second=salary;
       
   }
   sort(emp,emp+n,compare);
    for(int i=0;i<n;i++)
   {
      if(emp[i].second<min_salary)
      continue;
       cout<<emp[i].first<<" ";
       cout<<emp[i].second<<endl;
       
   }
	return 0;
}
