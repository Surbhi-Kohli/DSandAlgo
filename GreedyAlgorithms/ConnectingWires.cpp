/*
There are n white dots n black dots,equally spaced in line


*/
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
int n;
cin>>n;
int len=0;
int black[n];
int white[n];
for(int i=0;i<n;i++)
{
    cin>>white[i];
}

for(int i=0;i<n;i++)
{
    cin>>black[i];
}
sort(white,white+n);
sort(black,black+n);
for(int i=0;i<n;i++)
{
    len=len+white[i]-black[i];
}
cout<<len;
	return 0;
}
