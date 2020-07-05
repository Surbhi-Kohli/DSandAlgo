#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    map<string,int> m;
    string fruit;
    cin>>fruit;
    
    /**************Insertion********************/
    
    //a.
    m.insert(make_pair("Mango",100));
    
    //b.
    pair<string,int> p;
    p.first="Apple";
    p.second=120;
    m.insert(p);
    
    //c.
    m["lichi"]=60;
    m["banana"]=20;

   m[fruit]=50;
   /**********Search*********************/
   //a.
  auto it=m.find(fruit);
  if(it!=m.end())
  {
      cout<<"Price of fruit "<<fruit<<" is "<<m[fruit]<<endl;
  }
  else{
      cout<<"Fruit not found"<<endl;
  }
  
  //b.
  //count function returns 0 or 1 depending upon whether
  //the key is present or not
  if(m.count(fruit))
  {
      cout<<"Price of fruit searched by count function is "<<m[fruit]<<endl;
  }
  else{
       cout<<"Fruit not found"<<endl;
  }
  
  /***********Erase*****************/
  m.erase("banana");
  
  
  /**************Updation***********/
  m[fruit]+=22;
  
  
  /***************Iterate over all key value pairs****************/
  
  //a.
   for(auto it=m.begin();it!=m.end();it++)
   {
       cout<<it->first<<" and "<<it->second<<endl;
   }
	
  //b.
  for(auto p:m)
  {
      cout<<p.first<<":"<<p.second<<endl;
  }
	
	return 0;
}
