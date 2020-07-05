/*
Input:Grapes
Output of below code is:
Price of fruit Grapes is 50
Price of fruit searched by count function is 50
Mango and 100
Grapes and 72
Apple and 120
lichi and 60
Mango:100
Grapes:72
Apple:120
lichi:60

*/
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    
   unordered_map<string,int> um;
    string fruit;
    cin>>fruit;
    
    /**************Insertion********************/
    
    //a.
    um.insert(make_pair("Mango",100));
    
    //b.
    pair<string,int> p;
    p.first="Apple";
    p.second=120;
    um.insert(p);
    
    //c.
    um["lichi"]=60;
    um["banana"]=20;

   um[fruit]=50;
   /**********Search*********************/
   //a.
  auto it=um.find(fruit);
  if(it!=um.end())
  {
      cout<<"Price of fruit "<<fruit<<" is "<<um[fruit]<<endl;
  }
  else{
      cout<<"Fruit not found"<<endl;
  }
  
  //b.
  //count function returns 0 or 1 depending upon whether
  //the key is present or not
  if(um.count(fruit))
  {
      cout<<"Price of fruit searched by count function is "<<um[fruit]<<endl;
  }
  else{
       cout<<"Fruit not found"<<endl;
  }
  
  /***********Erase*****************/
  um.erase("banana");
  
  
  /**************Updation***********/
  um[fruit]+=22;
  
  
  /***************Iterate over all key value pairs****************/
  
  //a.
   for(auto it=um.begin();it!=um.end();it++)
   {
       cout<<it->first<<" and "<<it->second<<endl;
   }
	
  //b.
  for(auto p:um)
  {
      cout<<p.first<<":"<<p.second<<endl;
  }
	
	return 0;
}
