/*
Consider an array for which on day i, ith element is the price of a given stock.
we are permitted at most only one transaction(i.e buy one and sell one share of stock).Find the maximum profit.

Note:Buying a stock is mandatory before selling.

Input Format
First line contains integer n as size of array. Next n lines contains n integer as element of array.

Constraints
None

Output Format
Print the maximum profit.

Sample Input
6
7
1
5 
3 
6 
4
Sample Output
5
Explanation
None


*/
#include <iostream>
#include <stack>
#include <climits>
using namespace std;
int buyAndSellStock(int arr[],int n)
{
stack<int> st;
st.push(arr[0]);
int profit=INT_MIN;
  for(int i=1;i<n;i++)
  {
      if(arr[i]<st.top())
     {
        st.push(arr[i]);         
     }
     else{
         profit=max(profit,arr[i]-st.top());
     }
  }
  
  return profit;  
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<buyAndSellStock(arr,n);
	return 0;
}
