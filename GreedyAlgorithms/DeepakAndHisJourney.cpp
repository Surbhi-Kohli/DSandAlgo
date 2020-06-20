/* 
Deepak loves to travel but he wants to minimize the total travel expenditure. His journey will be through N 
checkpoints.
Checkpoints are numbered from 0 to N−1. At the start of his journey he is present at the checkpoint 0.
Also checkpoint N−1 will lead to his final destination.

Each checkpoint has a petrol pump which can be used to fill petrol in the car. Now cost of petrol per litre
at different checkpoints is given by array C which has 0-based indexing where C[i] is the cost per litre of
petrol at the ith checkpoint. Note that there is an infinite amount of supply at each checkpoint and car 
tank is also of infinite capacity. Now another array L is given which has 0-based indexing where L[i] denotes
the amount of petrol in litres required to reach the (i+1)th checkpoint from the ith checkpoint. Note that the
extra petrol remaining in the tank does not vanishes after reaching a checkpoint. Also, Deepak should have 
atleast L[i] litres of petrol at each checkpoint in order to reach the next checkpoint.

Help Deepak to estimate the minimum cost required in order complete the journey.

Input Format
First line of the input contains test cases denoted by T.

For each of the test cases, first line contains a single integers N denoting the number of checkpoints.

The next line contains N-space separated integers representing the array C which has 0-based indexing
where the integer denotes the cost per litre of petrol at ith checkpoint.

The last line contains array L, which has 0-based indexing, consisting of N space separated integers where 
the ith integer denotes the required amount of petrol needed to reach the (i+1)th checkpoint from the ith checkpoint.

Constraints
1 ≤ T ≤ 5
1 ≤ N ≤ 105
1 ≤ C[i], L[i] ≤ 105

Output Format
For each of the test cases, output the required answer in a separate line.

Sample Input
1
2
5 1 
1 2
Sample Output
7

*/

#include<iostream>
using namespace std;
int main() {
	long long int t,n,expenditure;
	cin>>t;
	while(t--)
	{ 
	 expenditure=0;
          cin>>n;
	long long int cost[n];
	long long int petrolQuantity[n];
	for(long long int i=0;i<n;i++)
	{
		cin>>cost[i];
	}
	for(long long int i=0;i<n;i++)
	{
		cin>>petrolQuantity[i];
	}
	  expenditure=cost[0]*petrolQuantity[0];
	long long int minCost=cost[0];
	for(long long int i=1;i<n;i++)
	{
         minCost=min(minCost,cost[i]);
	 expenditure+=minCost*petrolQuantity[i];

	}
	cout<<expenditure<<endl;
	}
	return 0;
}

