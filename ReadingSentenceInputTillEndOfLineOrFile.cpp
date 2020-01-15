//If u read input via cin ,it will not take whitespace as an input char
//consider the following code
/*
#include <bits/stdc++.h> 
using namespace std;

int main() {
	// your code goes here
	char ch;
		string s="";
	cin>>ch;
	while(ch!='!')
	{
	  s=s+ch;
	    cin>>ch;
	}


	cout<<s;
	return 0;
}
 //Input=hello world, CPP coding! ,     output=helloworld,CPPcoding
//hence it can be seen that cin does not read the space,so it is not a good choice to read string
cin.get()-> reads all characters -including spaces ,'\t' and '\n'
*/



#include <bits/stdc++.h> 
using namespace std;

int main() {
	// your code goes here
	char ch;
	string s="";
	ch=cin.get();
	while(ch!=EOF)
	{
	    s=s+ch;
	    ch=cin.get();
	}


	cout<<s;
	return 0;
}
//input= hi coder   output=hi coder
