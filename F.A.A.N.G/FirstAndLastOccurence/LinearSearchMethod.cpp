/*
Given a sorted array with possibly duplicate elements, the task is to find indexes of first and last occurrences of an element x in the given array.
Note:- If the x is not found in the array, print -1 -1

Input Format
The first line contains two integers n and x. The second line contains n spaced integers.

Constraints
1<n <10^8

-1< arr[i]<10^9

Output Format
Print index of the first and last occurrences of the number x with a space in between.

Sample Input
9 7
1 3 5 5 5 5 7 123 125
Sample Output
6 6

Time Complexity:O(N)
*/
#include <iostream>
using namespace std;
void firstAndLast(int arr[],int n,int x)
{
    int firstO=-1;
    int lastO=-1;
    for(int i=0;i<n;i++)
    {
       if(arr[i]==x)
       {
           if(firstO==-1)
           {
            firstO=i;
           lastO=i;
           }
           else {
               lastO=i;
           }
           
       }
       
    }
    cout<<firstO<<" "<<lastO;
}
int main() {
    int n,x;
    cin>>n>>x;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    firstAndLast(arr,n,x);
    }
