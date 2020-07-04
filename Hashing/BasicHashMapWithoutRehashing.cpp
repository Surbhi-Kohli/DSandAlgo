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
    
    ~Node(){
        if(next!=NULL)
        {
            delete next;
        }
    }
};
template<typename T>
class HashTable{
    Node <T>** table;
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
    
    void insert(string key,T value)
    {   
        int idx=hashFn(key);
       // cout<<value<<endl;
        Node<T> *n=new Node<T>(key,value);
    
        n->next=table[idx];
        table[idx]=n;
        
        curr_size++;
    }
    void print(){
        for(int i=0;i<table_size;i++)
        {
            cout<<"Bucket"<<i<<" ->";
            Node<T> *temp=table[i]; 
            
            while(temp!=NULL)
            {  
                cout<<temp->key<<","<<temp->value<<" -> ";
                temp=temp->next;
            }
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
            {  // cout<<"key found with value = "<<temp->value<<endl;
                return &temp->value;
                
            }
            temp=temp->next;
        }
        
        return NULL;
    }
    
    
};
int main() {
	// your code goes here
	HashTable <int> price_menu;
	price_menu.insert("Burger",120);
	price_menu.insert("BurgerPizza",150);
	price_menu.insert("Pepsi",20);
	price_menu.insert("Noodles",25);
	price_menu.insert("Pizza",150);
	price_menu.insert("Coke",40);
	price_menu.print();
	
  /*
  output of the above print function:
Bucket0 ->
Bucket1 ->
Bucket2 ->Pizza,150 -> Noodles,25 -> 
Bucket3 ->Burger,120 -> 
Bucket4 ->Coke,40 -> Pepsi,20 -> 
Bucket5 ->BurgerPizza,150 -> 
Bucket6 ->
  
  
  
  */
  
  
	int* price=price_menu.search("Coke");
	if(price!=NULL)
	{
	    cout<<*price<<endl;//40
	}
	else
	cout<<"Item not found";
	
	return 0;
}
