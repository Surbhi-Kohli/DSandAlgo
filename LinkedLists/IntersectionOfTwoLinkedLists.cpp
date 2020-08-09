/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int n=0,m=0,count=0;
        ListNode* temp1=headA;
        ListNode* temp2=headB;
        while(temp1!=NULL)
        {
            n++;
            temp1=temp1->next;
        }
        while(temp2!=NULL)
        {
            m++;
            temp2=temp2->next;
        }
        temp1=headA;
        temp2=headB;
        int diff=m>n?m-n:n-m;
     
        if(m>n)
        { 
         
            while(count!=diff)
            {
                temp2=temp2->next;
                count++;
            }
        }
        else{
          
            while(count!=diff)
            {
                temp1=temp1->next;
                
                count++;
            }
        }
      
        while(temp1!=NULL && temp2!=NULL)
        {             if(temp1==temp2)
            {
                return temp1;
            }
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return NULL;
    }
};
