/*
The Stock Span Problem
Last Updated: 10-06-2020
The stock span problem is a financial problem where we have a series of n daily price quotes for a stock and 
we need to calculate span of stock’s price for all n days.
The span Si of the stock’s price on a given day i is defined as the maximum number of consecutive days just before 
the given day, for which the price of the stock on the current day is less than or equal to its price on the given day.
For example, if an array of 7 days prices is given as {100, 80, 60, 70, 60, 75, 85}, then the span values for corresponding 7 days are {1, 1, 1, 2, 1, 4, 6}

Time Complexity: O(n). It seems more than O(n) at first look. If we take a closer look, we can observe that every element of the array
is added and removed from the stack at most once. So there are total 2n operations at most. Assuming that a stack operation takes O(1) 
time, we can say that the time complexity is O(n).

Auxiliary Space: O(n) in worst case when all elements are sorted in decreasing order.

*/

#include <iostream>
#include <stack>
using namespace std;
void stockSpanProblem(int arr[],int n,int S[])
{
    stack<int> st;
    st.push(0);
    S[0]=1;
    for(int i=1;i<n;i++)
    {
        
        while(!st.empty() && arr[st.top()]<=arr[i])
        {
            st.pop();
        }
       S[i]=st.empty()?(i+1):i-st.top();
       st.push(i);
    }
     for(int i=0;i<n;i++)
     {
         cout<<S[i]<<" ";
     }
     cout<<"END";
    
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
    int S[n];
    stockSpanProblem(arr,n,S);
	return 0;
}
