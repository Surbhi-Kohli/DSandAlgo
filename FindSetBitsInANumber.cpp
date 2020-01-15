Given a number n,find the number of set bits (Set Bits=No. of 1s in binary representation of a number)//Solve using bitwise operator

EX  9 =001001(in binary) so no. of set bits=2


#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int n;
	cin>>n;
	int ans=0;
	while(n>0)
	{
	 ans=ans+(n&1);
	 n=n>>1;
	}

	cout<<ans<<endl;
	return 0;
}
