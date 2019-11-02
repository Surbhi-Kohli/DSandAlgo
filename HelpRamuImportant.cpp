/*
HELP RAMU
Ramu often uses public transport. The transport in the city is of two types: cabs and rickshaws. 
The city has n rickshaws and m cabs, the rickshaws are numbered by integers from 1 to n, 
the cabs are numbered by integers from 1 to m.

Public transport is not free. There are 4 types of tickets:

A ticket for one ride on some rickshaw or cab. It costs c1 ruppees;
A ticket for an unlimited number of rides on some rickshaw or on some cab. It costs c2 ruppees;
A ticket for an unlimited number of rides on all rickshaws or all cabs. It costs c3 ruppees;
A ticket for an unlimited number of rides on all rickshaws and cabs. It costs c4 ruppees.

Ramu knows for sure the number of rides he is going to make and the transport he is going to use. 
He asked you for help to find the minimum sum of ruppees he will have to spend on the tickets.

Input Format:
Each Test case has 4 lines which are as follows:

The first line contains four integers c1, c2, c3, c4 (1 ≤ c1, c2, c3, c4 ≤ 1000) — the costs of the tickets. 
The second line contains two integers n and m (1 ≤ n, m ≤ 1000) — the number of rickshaws 
and cabs Ramu is going to use. The third line contains n integers ai (0 ≤ ai ≤ 1000) — the number of times Ramu is going to use the rickshaw number i. The fourth line contains m integers bi (0 ≤ bi ≤ 1000) — the number of times Ramu is going to use the cab number i.
Output Format
Print a single number — the minimum sum of ruppes Ramu will have to spend on the tickets.

Sample Input
2
1 3 7 19
2 3
2 5
4 4 4
4 3 2 1
1 3
798
1 2 3
Sample Output
12
1
*/
using namespace std;
#include<iostream>
int main()
{ int t;
   cin>>t;
   int c1,c2,c3,c4,n,m;
   int rick[1005],cab[1005];
   while(t--)
   {
       cin>>c1>>c2>>c3>>c4;
       cin>>n>>m;
       for(int i=0;i<n;i++)
       cin>>rick[i];
       
       for(int i=0;i<m;i++)
       cin>>cab[i];
       
       int rickCost=0;
       for(int i=0;i<n;i++)
       rickCost+=min(c1*rick[i],c2);
       rickCost=min(c3,rickCost);
       
       int cabCost=0;
       for(int i=0;i<m;i++)
       cabCost+=min(c1*cab[i],c2);
       cabCost=min(c3,cabCost);
       int finalAns=min(c4,rickCost+cabCost);
       
       cout<<finalAns<<endl;
   }
	return 0;
}
