node* merge(node *a,node *b)
{
    if(a==NULL)
    return b;
    
    if(b==NULL)
    return a;
    
    //take a head pointer
    node *c;
    if(a->data<b->data)
    {
        c=a;
        c->next=merge(a->next,b);
    }
    else{
        c=b;
        c->next=merge(a,b->next);
        
    }
    return c;
}
