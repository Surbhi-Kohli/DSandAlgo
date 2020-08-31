/*
Given a 2D array of dimension r*c where each cell in the array can have values 0, 1 or 2 which has the following meaning: 0 : Empty cell 1 : Cells 
have fresh oranges 2 : Cells have rotten oranges

So, we have to determine what is the minimum time required to rot all oranges. A rotten orange at index [i,j] can rot other fresh orange at 
indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1] (up, down, left and right) in unit time. If it is impossible to rot every orange then simply return -1.

Input Format
The first line of input contains an integer T denoting the number of test cases.
Each test case contains two integers r and c, where r is the number of rows and c is the number of columns in the array arr and take r*c more inputs in an array arr.

Constraints
1 <= T <= 100
1 <= r <= 100
1 <= c <= 100
0 <= a[i] <= 2

Output Format
Print an integer which denotes the minimum time taken to rot all the oranges (-1 if it is impossible).
Important test cases
Example 1:
Sample Input
1
3 5
2 1 0 2 1 
1 0 1 2 1 
1 0 0 2 1
Sample Output
2

Example 2:
Input: 
3 3
2 1 1 
0 1 1
1 0 1
Output: -1
Explanation:  The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.

Example 3:
Input:
1 2
0 2
Output: 0
Explanation:  Since there are already no fresh oranges at minute 0, the answer is just 0.

Time/Space Complexity Analysis:

Time Complexity: O( R *C).
Each element of the matrix can be inserted into the queue only once so the upperbound of iteration is O(R*C), i.e. the number of elements.
So time complexity is O(R *C).
Space Complexity: O(R*C).
To store the elements in a queue O(R*C) space is needed.
*/
#include <iostream>
#include <queue>
using namespace std;
int rottenOranges(int **arr,int r,int c)
{
    queue<pair<int,int>> q;
    int count=0;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(arr[i][j]==2)
            {  
                q.push(make_pair(i,j));
                
            }
        }
    }
  
    q.push(make_pair(-1,-1));
    queue<pair<int,int>> q2=q;
   q.empty())
    {
        pair<int,int> p=q.front();
        q.pop();
        int i=p.first;
        int j=p.second;
     
        if(i==-1 && j==-1)
        { 
           
              if(q.empty())
              {  
                   break;
              }
             
              else
              {  
                  count++;
                 q.push(make_pair(-1,-1));
                 continue;
              }
             
        }
        else
        {   //cout<<"didnt reach delimiter"<<endl;
             int nbr1=-1,nbr2=-1,nbr3=-1,nbr4=-1;
        if(i-1>=0)
        nbr1=arr[i-1][j];
        if(i+1<r)
        {
            nbr2=arr[i+1][j];
        }
        if(j+1<c)
        {
            nbr3=arr[i][j+1];
        }
        if(j-1>=0)
        {
           nbr4=arr[i][j-1]; 
        }
        if(nbr1==1)
        {
            arr[i-1][j]=2;
            q.push(make_pair(i-1,j));
        }
        if(nbr2==1)
        { 
            arr[i+1][j]=2;
            q.push(make_pair(i+1,j));
         
        }
        if(nbr3==1)
        {
            arr[i][j+1]=2;
            q.push(make_pair(i,j+1));
        
        }
        if(nbr4==1)
        {
            arr[i][j-1]=2;
            q.push(make_pair(i,j-1));
              
        }
       }
      
       
    }
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(arr[i][j]==1)
            return -1;
        }
    }
    return count;
}
int main() {
   int t,r,c;
   cin>>t;
   while(t--)
   {
      cin>>r>>c;
      int **arr=new int*[r];
      for(int i=0;i<r;i++)
      {
          arr[i]=new int[c];
      }
      for(int i=0;i<r;i++)
      {
          for(int j=0;j<c;j++)
          {
              cin>>arr[i][j];
          }
      }
   
      
      cout<<rottenOranges(arr,r,c)<<endl;
   }
	return 0;
}
