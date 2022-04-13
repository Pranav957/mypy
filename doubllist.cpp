#include <bits/stdc++.h>
using namespace std;
class node
{
   public:
    node* prev;
    int data;
    node* next;
    node() {}
    node(int val)
    {
      data=val;
      prev=NULL;
      next=NULL;
    }
};
node* Insert_at_begining(node **head)
{
    node* curr=*head;
    int val;
    cout<<"enter value for node to be inserted";
    cin>>val;
    node*Temp=new node(val);
    if(!Temp)
    {
        cout<<"memory error!";
        return *head;
    }
    if(*head==NULL)
    {
        *head=Temp;
        return *head;
    }
    Temp->next=*head;
    (*head)->prev=Temp;
    *head=Temp;
    return *head;
}
void Display_List_elements(node*  root)//value is passed by value
{
   node *p;
   if(root==NULL){
       cout<<"list is empty\n";
   }
   p=root; //no of pointers can point to same location
   //cout<<p->data;
   while(p!=NULL){
     cout<<p->data<<"->";
     p=p->next;
   }
   printf("\n");
}
node * insert_at_End(node**head,int data)
{
   node * cur=*head;
   node* temp=new node(data);
   if(!temp)
   {
       cout<<"memory error";
       exit(0);
   }
   if(*head==NULL)
    {
        *head=temp;
        exit(0);
    }
    while(cur->next!=NULL)
        cur=cur->next;
     cur->next=temp;
     temp->prev=cur;
     return *head;
}
int insert_at_givenpos( node **head,int data,int pos)
{
    int k=1;
    node *temp,*new_node;
    new_node=new node(data);
    if(pos==1)
    {
        new_node->next=*head;
        if(*head)
        (*head)->prev=new_node;
        *head=new_node;
        return;
    }
    temp=*head;
    while(k<pos && temp->next!=NULL)
    {
        temp=temp->next;
        k++;
    }
    if(k<pos)
    {
        cout<<"Desired pos does not exist";
        return;
    }
    new_node->next=temp->next;
    new_node->prev=temp;
    if(temp->next)
        temp->next->prev=new_node;//right opeartionsare performed first
    temp->next=new_node;
    return;    
}
node* ADD_after(node *start,int data,int item)
{
    node* temp,*p;
    temp=new node(data);
    p=start;
    while(p!=NULL)
    {
        if(p->data==item)
        {
            temp->prev=p;
            temp->next=p->next;
            if(p->next!=NULL)
                  p->next->prev=temp;
            p->next=temp;
            return start;      
        }
        p=p->next;
    }
    cout<<"item not present in the list";
    return start;
}
node* Add_before(node* start,int data ,int item)
{
    node* temp,*q;
    if(start==NULL)
    {
        cout<<"list is empty\n";
        return start;
    }
    if(start->data==item)
    {
        temp=new node(data);
        temp->next=start;
        start->prev=temp;
        start=temp;
        return start;
    }
    q=start;
    while(q!=NULL)
    {
        if(q->data==item)
        {
            temp=new node(data);
            temp->prev=q->prev;
            temp->next=q;
            q->prev->next=temp;
            q->prev=temp;
            return start;
        }
        q=q->next;
    }
    cout<<"item not present in the list";
    return start;
}
int delete_first(node** head)
{
    node* temp=*head;
    if(*head==NULL)
    {
        cout<<"list is empty";   //head=head->next
        return;                  // free(head->prev) 
    }                            // head->prev=NULL  
    *head=(*head)->next;
    (*head)->prev=NULL;
    free(temp);
    return ;

}
node * delete_single_node(node *start)
{
    node* temp=start;
    start=NULL; 
    free(temp);
    return start;  //start=start->NULL;
}
int Delete_last(node **head)
{
    node* temp=*head,*cur=*head;
    if(*head==NULL)
    {
        cout<<"lIst is empty";
        return;
    }
    while(cur->next!=NULL)   // if temp is node to be deleted
    {                        // temp->prev->next=NULL;
        cur=cur->next;
    }
    temp=cur->prev;
    temp->next=cur->next;  // NULL
    delete cur;
    return;
}
int DElete_intermediate(node** head,int pos)
{
    node* temp2,*temp=*head;
    int k=1;
    if(*head==NULL)
    {
        cout<<"list is empty";
        return ;
    }
    if(pos==1)
    {
        *head=(*head)->next;
        if(*head)
          (*head)->prev=NULL;
          free(temp);
          return;
    }
    while(k<pos && temp->next!=NULL)
    {
        temp=temp->next;
    }
    if(k<pos-1)
    {
       cout<<"DESired position DEos not Exist";
    }
    temp2=temp->prev;
    temp2->next=temp->next;      // temp->prev->next=temp->next
    if(temp->next)              // temo->next->prev=temp->prev  
      temp->next->prev=temp2;
      free(temp);
      return;
}
node *del(node* start,int data)
{
    node* temp;
    if(start==NULL)
    {
        cout<<"list is empty";
        return start;
    }
    if(start->next==NULL) {
       if(start->data==data)
       {
           temp=start;
           start=NULL;
           free(temp);
           return start;
       }
       else{
           cout<<"element not found";
           return start;
       }
    }
    if(start->data==data)
   {
       temp=start;
       start=start->next;
       start->prev=NULL;
       free(temp);
       return start;
   }
   temp=start->next;
   while(temp->next!=NULL)
   {
       if(temp->data==data)
       {
          temp->prev->next=temp->next;
          temp->next->prev=temp->prev;
          free(temp);   
       }
       temp=temp->next;
   if(temp->data==data)
   {
       temp->prev->next=NULL;
       free(temp);
       return start;
   }

}
int main() {
// solution comes here
node *root=NULL;
Insert_at_begining(&root);
root=insert_at_End(&root,25);
Display_List_elements(root);

}