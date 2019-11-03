/*
We define the distance between two array values as the number of indices between the two values. Given , find the minimum distance between any pair of equal elements in the array. If no such value exists, print -1 .

For example, if a=[3,2,1,2,3] , there are two matching pairs of values:3 and 2 . The indices of the 3's are i=0 and j=4, so their distance is d(i,j)=|j-i|=4 . The indices of the 2's are 1 and 3, so their distance is d(i,j)=|j-i|=2 .

Function Description

Complete the minimumDistances function in the editor below. It should return the minimum distance between any two matching elements.
minimumDistances has the following parameter(s):
a: an array of integers
Input Format
The first line contains an integer n, the size of array a .
The second line contains n space-separated integers a[i].

COnstraints
1<=n<=10^3, 1<=a[i]<=10^5
Output Format
Print a single integer denoting the minimum  in . If no such value exists, print .

Sample Input
6
7 1 3 4 1 7
Sample Output
3*/
int minimumDistances(vector<int> a) {
 map<int, int> p;
        int min = 1000000000;

        for(int i=0; i<a.size(); i++){
                if((p[a[i]] != 0)&&(i + 1 - p[a[i]] < min)){
                        min = i + 1 - p[a[i]];
                }
                p[a[i]] = i+1;
        }

        if (min == 1000000000)
            return -1;

        return min;

}
