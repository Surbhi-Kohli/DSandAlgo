/*
Binary Heaps
Properties: 1.It is a Complete Binary Tree(CBT)  2.Has a heap order property(min heap or max heap)
 *The min-heap property: the value of each node is greater than or equal to the value of its parent, with 
                          the minimum-value element at the root.
 *The max-heap property: the value of each node is less than or equal to the value of its parent, with
                           the maximum-value element at the root.

What is a Complete Binary Tree(CBT)? -> It is a binary tree in which all levels are completely filled except the last level
which can either be partially or completely filled (and filling is in the order from left to right). 
  


In a heap the highest (or lowest) priority element is always stored at the root, hence the name "heap". A heap is not a sorted structure and can be regarded as partially ordered. As you see from the picture, there is no particular relationship among nodes on any given level, even among the siblings.

Since a heap is a complete binary tree, it has a smallest possible height - a heap with N nodes always has O(log N) height.

A heap is useful data structure when you need to remove the object with the highest (or lowest) priority. A common use of a heap is to implement a priority queue.

IMPLEMENTATION
Array Implementation
A complete binary tree can be uniquely represented by storing its level order traversal in an array.
The root is the second item in the array. We skip the index zero cell of the array for the convenience of implementation and give it a value of -1. Consider k-th element of the array, the

its left child is located at 2*k index
its right child is located at 2*k+1. index
its parent is located at k/2 index

So the information represented by the Binary tree can be represented by array for a complete binary tree.We use array
notation b'coz if we want to

1.Insert an element-We add it at last index of array and then heapify the array to maintain the heap property (O(logN)):

The new element is initially appended to the end of the heap (as the last element of the array). The heap property
is repaired by comparing the added element with its parent and moving the added element up 
a level (swapping positions with the parent). This process is called "percolation up". 
The comparison is repeated until the parent is larger than or equal to the percolating element.
The worst-case runtime of the algorithm is O(log n), since we need at most one swap on each
level of a heap on the path from the inserted node to the root (As no of levels =log n)

2.Get least value or max value element,We get it by retrieving the 2nd element of array O(N).

3.DeleteMin/DeleteMax
The minimum element can be found at the root, which is the first element of the array. We remove the root and
replace it with the last element of the heap and then restore the heap property by 
percolating down. Similar to insertion, the worst-case runtime is O{log n).

*/
#include <iostream>
#include<vector>
using namespace std;
class Heap{
    vector<int> v;
    bool minHeap;
    public:
    Heap(bool type=true)
    {
        minHeap=type;
        v.push_back(-1);
    }
    bool compare(int a,int b)
    {
        if(minHeap)
        {
            return a<b;
        }
        else 
        return a>b;
    }
    void push(int n)
    {
        v.push_back(n);
        int index=v.size()-1;
        int parentIndex=(index)/2;
        while(index>1 && compare(v[index],v[parentIndex]))
        {
           swap(v[index],v[parentIndex]);
            index=parentIndex;
            parentIndex=parentIndex/2;
        }
    }
    int top(){
        return v[1];
    }
    bool empty(){  //to check whether heap is empty or not
        return v.size()==1;//only the 0th index  is present
    }
    vector<int> VecHeap(){
        return v;
    }
};
int main() {
	// your code goes here
	Heap h;
	h.push(5);
	h.push(6);
	h.push(1);
	h.push(2);
	h.push(3);
	h.push(7);
	h.push(4);
	cout<<h.top()<<endl;  //1
	vector<int> heapInArray=h.VecHeap();
	for(int i=1;i<heapInArray.size();i++)
	{
	    cout<<heapInArray[i]<<" | ";  //1 | 2 | 4 | 6 | 3 | 7 | 5 |
	}
	cout<<endl;
	Heap h2(false);//max Heap
	h2.push(5);
	h2.push(6);
	h2.push(1);
	h2.push(2);
	h2.push(3);
	h2.push(7);
	h2.push(4);
		cout<<h2.top()<<endl;  //7
	vector<int> heapInArray2=h2.VecHeap();
	for(int i=1;i<heapInArray2.size();i++)
	{
	    cout<<heapInArray2[i]<<" | ";   //7 | 5 | 6 | 2 | 3 | 1 | 4 | 
	}
	return 0;
}
