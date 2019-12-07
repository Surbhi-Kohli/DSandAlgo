#include <bits/stdc++.h>

using namespace std;
int gcd(int a, int b) 
{ 
    if (b == 0) 
        return a; 
  
    else
        return gcd(b, a % b); 
} 
  
vector<string> split_string(string s);


void leftRotate(vector<int> arr, int d, int n) 
{ 
    int g_c_d = gcd(d, n); 
    for (int i = 0; i < g_c_d; i++) { 
        /* move i-th values of blocks */
        int temp = arr[i]; 
        int j = i; 
  
        while (1) { 
            int k = j + d; 
            if (k >= n) 
                k = k - n; 
  
            if (k == i) 
                break; 
  
            arr[j] = arr[k]; 
            j = k; 
        } 
        arr[j] = temp; 
    }
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    } 
} 
int main(){
int n,d;
vector<int> arr(n);
cin>>n>>d;
for(int i=0;i<n;i++){
cin>>arr[i];
leftRotate(arr,d,n);
return 0;
}

}
