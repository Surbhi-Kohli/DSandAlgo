#include<iostream>
#include <vector> 
#include <algorithm> 
using namespace std;
void countSort(vector <long long>& arr) 
{ 
    long long max = *max_element(arr.begin(), arr.end()); 
    long long min = *min_element(arr.begin(), arr.end()); 
    long long range = max - min + 1; 
      
    vector<long long> count(range), output(arr.size()); 
    for(long long i = 0; i < arr.size(); i++) 
        count[arr[i]-min]++; 
          
    for(long long i = 1; i < count.size(); i++) 
           count[i] += count[i-1]; 
    
    for(long long i = arr.size()-1; i >= 0; i--) 
    {  
         output[ count[arr[i]-min] -1 ] = arr[i];  
              count[arr[i]-min]--;  
    } 
      
    for(long long i=0; i < arr.size(); i++) 
            arr[i] = output[i]; 
} 
  
void printArray(vector <long long> & arr)  
{  
    for (long long i=0; i < arr.size(); i++)  
        cout << arr[i] << " ";  
   
} 
int main() {
    vector<long long> arr;
    long long n;
    cin>>n;
    for(long long i=0;i<n;i++)
  {  int ans;
  cin>>ans;
      arr.push_back(ans);
  }
  countSort (arr); 
    printArray (arr);
	return 0;
}

