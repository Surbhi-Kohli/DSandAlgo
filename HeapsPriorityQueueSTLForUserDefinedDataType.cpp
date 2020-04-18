/*
Suppose u have a network of cars at diffrent coordinates.We have to print cars in order of max dist cars first.




*/
// program in c++ to use priority_queue with class 

/*STL priority_queue is the implementation of Heap Data-structure.. By default, 
it’s a max heap and we can easily use it for primitive datatypes

Prerequisite: Prioirty_queue Basics

In this article, we will see how can we use priority_queue for custom datatypes like class or structure.
suppose we have a class name Car which consist of three variables x,y and id
and we want to store that that in priority_queue then a simple method won’t work here.
1.We can use operator overloading like overload '<' to specify what kind of comparison would we want
2.Or we can use functor which will have () overloaded and define the comparison that we want.
*/


#include <iostream> 
#include <queue> 
#include<vector>
using namespace std; 

class Car { 
    public:
    int x;
    int y;
    int id;
    Car(int id,int x,int y)
    {
        this->id=id;
        this->x=x;
        this->y=y;
    }
    
int dist()
{
    return x*x+y*y;
}
void print(){
    cout<<"ID"<<id<<" ";
    cout<<"Location"<<x<<","<<y<<endl;
}
};
class CarCompare{  //using functor
    public:
    bool operator()(Car a,Car b)
    {
        return a.dist()<b.dist();
    }
};

//we are doing operator overloading through this 
bool operator<(Car c1,Car c2) 
 { 
      //returns true if c1.dist()<c2.dist() and stl priority_queue would be a max heap..ie the top
    //      would have element with max distance     
    //if u want to build min heap,overload > operator which will return c1.dist()>c2.dist()
 	return c1.dist() < c2.dist(); 
 } 

int main() 
{ 
CarCompare cc;
	priority_queue<Car,vector<Car>,CarCompare> Q; //use with functor
	 priority_queue<Car> Q2;//use of < operator overloaded 

	int x[10]={5,6,17,18,9,11,0,3};
	int y[10]={1,-2,8,9,10,91,1,2};

	for (int i = 0; i < 8; ++i) { 
      Car c(i,x[i],y[i]);
		Q.push(c); 

		// insert an object in priority_queue by using 
		// the Person class constructor 
	} 

	while (!Q.empty()) { 

		Car c1 = Q.top(); 
            c1.print();
		Q.pop(); 

	
	} 
  //ID5 Location11,91
  //ID3 Location18,9          output
  //ID2 Location17,8
  //ID4 Location9,10
  //ID1 Location6,-2
  //ID0 Location5,1
  //ID7 Location3,2
  //ID6 Location0,1

	cout<<endl<<"************************";
	for(int i=0;i<8;i++)
	{
	    Car c2(i,x[i],y[i]);
	    Q2.push(c2);
	}
	while(!Q2.empty())
	{
	    Car c3=Q2.top();
	    c3.print();
	    Q2.pop();
	}
	return 0; 
} 
