/*
There are n circles arranged on x-y plane. All of them have their centers on x-axis. You have to remove some of them, 
such that no two circles are overlapping after that. Find the minimum number of circles that need to be removed.

Input Format
First line contains a single integer, n, denoting the number of circles. Next line contains two integers,
c and r each, denoting the circle with radius r and center, (c,0).

Constraints
1<=n<=10^5 |c|<=10^9 1<=r<=10^9

Output Format
Print a single integer denoting the answer.

Sample Input
4
1 1
2 1
3 1
4 1
Sample Output
2
Explanation
We can remove 1st and 3rd circle, or 2nd and 4th circle.

Approach:
Greedy strategy can be applied to solve the problem.

* Find staring and ending points of the diameter of the circles.
* Starting point would be equal to (c-r) and ending point would be equal to (c+r) where (c, 0) is
   the center of the particular circle and r is its radius.
* Sort the {start, end} pair according to the value of end point. Less the value of end point, less is its index.
* Start iterating the pairs and if the starting point of a circle is less then current end value, it means circles are intersecting        hence increment the count. Else update the current end value.

*/
#include <iostream>
#include <algorithm>
using namespace std;
bool compare(pair<int,int> p1,pair<int,int> p2)
{
	if(p1.second==p2.second)
	return p1.first<p2.first;

	return p1.second<p2.second;
}
int main() {
	int n;
	cin>>n;
 pair<int,int> p[n];
	for(int i=0;i<n;i++)
	{
		int c,r;
		cin>>c>>r;
		p[i]=make_pair(c-r,r+c);
	}
	sort(p,p+n,compare);
	
	int currEnd=p[0].second;
	int count=0;
	
for(int i=1;i<n;i++)
{
   if(p[i].first>=currEnd)
   {
     currEnd=p[i].second;
   }
   else
   {
	   count++;
   }
}
cout<<count;
	return 0;
}
