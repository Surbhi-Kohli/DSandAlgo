/*
There is one meeting room in a firm. There are N meetings in the form of (S[i], F[i]) where S[i] is start time of meeting i and F[i] is finish time of meeting i.

What is the maximum number of meetings that can be accommodated in the meeting room?

Input:
The first line of input consists number of the test cases. The description of T test cases is as follows:
The first line consists of the size of the array, second line has the array containing the starting time of all the meetings each separated by a space, i.e., S [ i ]. And the third line has the array containing the finishing time of all the meetings each separated by a space, i.e., F [ i ].

Output:
In each separate line print the order in which the meetings take place separated by a space.

Constraints:
1 ≤ T ≤ 70
1 ≤ N ≤ 100
1 ≤ S[ i ], F[ i ] ≤ 100000

Example:
Input:
2
6
1 3 0 5 8 5
2 4 6 7 9 9
8
75250 50074 43659 8931 11273 27545 50879 77924
112960 114515 81825 93424 54316 35533 73383 160252  

Output:
1 2 4 5
6 7 1

Explanation:
Testcase 1: Four meetings can held with given start and end timings,which are 1st,2nd,4th and 5th meetings.
 

*/
#include <iostream>
#include <algorithm>
using namespace std;
class meeting{
    
   
    public:
     int start,end,index;
     meeting(){
         this->start=0;
         this->end=0;
         this->index=0;
     }
    meeting(int start,int end,int index)
    {
        this->start=start;
        this->end=end;
        this->index=index;
    }
   
  
   
};
bool compare(meeting m1,meeting m2)
{
    return m1.end<m2.end;
}
int main() {
	//code
	int t;
	cin>>t;
	long long int n;
	while(t--)
	{
	    cin>>n;
	    meeting mtng[n];
	    
	    for(int i=0;i<n;i++)
	    {
	        long long int start;
	        cin>>start;
	     //  mtng[i]=new meeting();
	      mtng[i].start=start;
	      mtng[i].index=i;
	    }
	      
	    for(int i=0;i<n;i++)
	    {
	     long long int end;
	     cin>>end;
	     mtng[i].end=end;
	    }
	    sort(mtng,mtng+n,compare);
	  
	    int currEnd=mtng[0].end;
	 
	    cout<<mtng[0].index+1<<" ";
	    for(int i=1;i<n;i++)
	    {   
	        if(mtng[i].start>=currEnd)
	        { 
	           // count++;
	           cout<<mtng[i].index+1<<" ";
	            currEnd=mtng[i].end;
	        }
	    }
	    cout<<endl;
	    
	}
	return 0;
}
