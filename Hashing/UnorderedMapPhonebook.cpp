#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;


int main() {
	// your code goes here
	unordered_map<string,vector<string>> phonebook;
	phonebook["Rahul"].push_back("9110");
    phonebook["Rahul"].push_back("9112");
    phonebook["Rahul"].push_back("9113");
    phonebook["Kajal"].push_back("8112");
    phonebook["Kajal"].push_back("8113");

	
	//Iterate over all students
	for(auto p:phonebook)
	{
	    cout<<"Name - "<<p.first<<"->";
	    for(string s:p.second)
	    cout<<s<<" ";
	    cout<<endl;
	}
	
	string name;
	cin>>name;//Rahul
	if(phonebook.count(name)==0)
		cout<<"entry not found"<<endl;
	else{
	     for(string s:phonebook[name])
		cout<<s<<" "; //9110 9112 9113 
		cout<<endl;
	     }
		return 0;
}
