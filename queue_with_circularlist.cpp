#include <bits/stdc++.h>
using namespace std;
class node
{
   public: 
    int data;
    node* next;
   node(int val)
   {
     data=val;
     next=this;
   }
}*rear=NULL;
int isEmpty()
{
    if(rear==NULL)
      return 1;
   else
      return 0;
}
void Insert(int item)
{
    node* temp=new node(item);
    if(temp==NULL)
    { 
        cout<<"queue overflow";
        return;
    }
    if(isEmpty())
    {
        rear=temp;
        temp->next=rear;
    }
    else{
   temp->next=rear->next;
   rear->next=temp;
   rear=temp;
    }
}
int del()
{
    int item;
    node* temp;
    if(isEmpty())
    {
        cout<<"queue underflow";
        return 0;
    }
    if(rear->next==rear)
    {
        temp=rear;
        rear=NULL;
    }
    else{
        temp=rear->next;
        rear->next=rear->next->next;
    }
    item=temp->data;
    delete temp;
    return item;
}
int Peek()
{
    if(isEmpty())
    {
        cout<<"queue is empty";
        return 0;
    }
    return rear->next->data;
}
void Display()
{
    node* p;
    if(isEmpty())
    {
        cout<<"queue is empty";
        return;
    }
    cout<<"queue is: ";
    p=rear->next;
    do
    {
        cout<<p->data;
        p=p->next;
    }while(p!=rear->next);
    cout<<"\n";
}
int main() {
// solution comes here
}