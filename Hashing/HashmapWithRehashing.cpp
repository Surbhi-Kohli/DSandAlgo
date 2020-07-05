/*
Bucket 0->
Bucket 1->
Bucket 2->Noodles,25 -> Pizza,150 -> 
Bucket 3->Burger,120 -> 
Bucket 4->Coke,40 -> 
Bucket 5->BurgerPizza,150 -> 
Bucket 6->
Bucket 7->
Bucket 8->
Bucket 9->
Bucket 10->
Bucket 11->Pepsi,20 -> 
Bucket 12->
Bucket 13->

***********************
Price of the searched item is 25

**********After Deleting a node*************
Bucket 0->
Bucket 1->
Bucket 2->Pizza,150 -> 
Bucket 3->Burger,120 -> 
Bucket 4->Coke,40 -> 
Bucket 5->BurgerPizza,150 -> 
Bucket 6->
Bucket 7->
Bucket 8->
Bucket 9->
Bucket 10->
Bucket 11->Pepsi,20 -> 
Bucket 12->
Bucket 13->


*/


#include <iostream>
using namespace std;
template <typename T>
class Node{
    public :
    string key;
    T value;
    Node<T> *next;
    
    Node(string key,T val)
    {
        this->key=key;
        this->value=val;
        next=NULL;
    }
    
    // ~Node(){ //this caused a problem as when we are erasing a particular node in a list,its next nodes were also being deleted
    //     if(next!=NULL)   //so commented the distructor
    //     {
    //         delete next;
    //     }
     // }
};
template<typename T>
class HashTable{
    Node <T> **table;
    int curr_size;
    int table_size;
    
    int hashFn(string key)
    {
        int idx=0;
        int p=1;
        for(int j=0;j<key.length();j++)
        {
            idx=idx+(key[j]*p)%table_size;
            idx=idx%table_size;
            p=(p*27)%table_size;
        }
        return idx;
    }
    void rehash(){
        
        Node<T> **oldTable=table;
         int oldSize=table_size;
         table_size=2*table_size;
         table=new Node<T>* [table_size];
         for(int i=0;i<table_size;i++)
         { 
          table[i]=NULL;
         }
         curr_size=0;
          for(int i=0;i<oldSize;i++)
          {
           Node<T>* n=oldTable[i];
           Node<T>* prev=oldTable[i];
           while(n!=NULL)
           { 
               insert(n->key,n->value);
                n=n->next;

           }
        
           
         
          }
          
    delete [] oldTable;
         
         
    }
    public:
    HashTable(int ts=7)
    {
        table_size =ts;
        table=new Node<T> *[table_size];
        curr_size=0;
        for(int i=0;i<table_size;i++)
        {
            table[i]=NULL;
        }
        
    }
    ~HashTable(){ //will be called when we do delete [] oldTable
        for(int i=0;i<table_size;i++)
        {
            Node<T>* head=table[i];
            while(head)
            {
                Node<T> *temp=head->next;
                delete head;
                head=temp;
            }
        }
    }
    
    void insert(string key,T value)
    {   
        int idx=hashFn(key);
      
        Node<T> *n=new Node<T>(key,value);
        n->next=table[idx];
        table[idx]=n;
        curr_size++;
        
        //Rehashing
        float load_factor=curr_size/(1.0*table_size);
        if(load_factor>0.7)
        rehash();
        
    }
    void print(){
        for(int i=0;i<table_size;i++)
        {  
            
            Node<T> *temp=table[i]; 
            cout<<"Bucket "<<i<<"->";
           
            while(temp!=NULL)
            {  
              
                cout<<temp->key<<","<<temp->value<<" -> ";
                temp=temp->next;
            }
          //  cout<<"out of while"<<endl;
            cout<<endl;
        }
    }
    T* search(string key)
    {
        int idx=hashFn(key);
        Node<T> *temp=table[idx];
        while(temp!=NULL)
        {
            if(temp->key==key)
            {
                return &temp->value;   
            }
            temp=temp->next;
        }
        
        return NULL;
    }
    void erase(string key)
    {
        int idx=hashFn(key);
        Node<T> *head=table[idx];
        Node<T> *temp=head;
        
        Node<T> *prev=NULL;
        while(temp)
        {
            if(temp->key==key)
            {
                if(temp==head)
                {
                  
                     table[idx]=temp->next;
                    
                }
                else{
                     prev->next=temp->next;
                    }
                delete temp;
                break;
            }
            prev=temp;
            temp=temp->next;
          
        }
       
    }
    
    
};
int main() {
	// your code goes here
	HashTable <int> price_menu;
	price_menu.insert("Burger",120);
		price_menu.insert("Pepsi",20);
	price_menu.insert("BurgerPizza",150);

	price_menu.insert("Noodles",25);
	price_menu.insert("Pizza",150);
	price_menu.insert("Coke",40);
	price_menu.print();
	
  /*
  output of the above print function:
Bucket 0->
Bucket 1->
Bucket 2->Noodles,25 -> Pizza,150 -> 
Bucket 3->Burger,120 -> 
Bucket 4->Coke,40 -> 
Bucket 5->BurgerPizza,150 -> 
Bucket 6->
Bucket 7->
Bucket 8->
Bucket 9->
Bucket 10->
Bucket 11->Pepsi,20 -> 
Bucket 12->
Bucket 13->
  
  */
  cout<<endl<<"***********************"<<endl;
	int* price=price_menu.search("Noodles");
	if(price!=NULL)
	{
	    cout<<"Price of the searched item is "<<*price<<endl; //25
	}
	else
	cout<<"Item not found";
	cout<<endl<<"**********After Deleting a node*************"<<endl;
	
	price_menu.erase("Noodles");
 	price_menu.print();
 	
 	/*

Bucket 0->
Bucket 1->
Bucket 2->Pizza,150 -> 
Bucket 3->Burger,120 -> 
Bucket 4->Coke,40 -> 
Bucket 5->BurgerPizza,150 -> 
Bucket 6->
Bucket 7->
Bucket 8->
Bucket 9->
Bucket 10->
Bucket 11->Pepsi,20 -> 
Bucket 12->
Bucket 13->

 	*/
	
	return 0;
}
