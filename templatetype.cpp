#include <bits/stdc++.h>
using namespace std;
class node;
//temp is pointer always used to point node to be inserted and node to be deleted
node* Create_list(node* start);
class node
{
  public:  
    int data;
    node* next;
    node() {}
    node(int v)
    {
        data=v;
        next=NULL;
    }
    void Display()
    {
        node * cur=this;
        for(cur=this;cur!=NULL;cur=cur->next)
        {
             cout<<cur->data<<" ";
        }
    }
    
};
node* Insert_at_end(node* head,int value)// this is pass by value so value of root copied in head head needs to be returned bcoz in 
 {                                         // in first condition head is changed / either we need to pass head as refference then no 
     node* temp=new node(value);         // need to return root gets updated automatically  
     node* p=head;
     if(head==NULL)
     {
         head=temp;
     }
     else{
         while(p->next!=NULL){ //to get last node pointed by p
             p=p->next;
         }
         p->next=temp;
     }
    return head;
 }
int get_len(node* &start)//pass by refference
{
    node *cur=start;
    int count=0;
    for(cur=start;cur!=NULL;cur=cur->next)
        {
             count+=1;
        }
        return count;
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
void search(node * start,int item)
 {
     node* p=start;
     int pos=1;
     while(p!=NULL)//at the end p grts updated as null
     {
         if(p->data==item)
         {
            cout<< p->data<<" found at position "<<pos;
            return;
         }
         p=p->next;  
         pos++; 
     }
     cout<<" is not present in list";
 }
 node * Add_at_Begining(node* head,int value)
 {
     node*temp=new node(value);
     temp->next=head;
     head=temp;
     return head;
 }
 void Insert_at_givenpos(node *&start,int pos,node* &New)
 {
     int b;
  cout<<"Enter value for new node to be inserted: ";
  cin>>b;
  New->data=b;
  New->next=NULL;
  if(pos<=1)
  {
      New->next=start;
      start=New;
  } 
  node* pred=start;
  while(--pos && pred!=NULL) // for(i=1;i<pos-1 && p!=NULL;i++)
  {
      pred=pred->next;
  }
  if(pred==NULL)
  {
      cout<<"there are less than "<<pos<<"elements";
  }
  else{
      New->next=pred->next; //right to left
      pred->next=New;
  }

 }
 void add_after(node* & head,int item)
 {int val;
 cout<<"Enter val for new node?: ";
 cin>>val;
     node *temp=new node(val);
     node *p=head;
     int flag=1;
     while(p!=NULL)
     {
         if(p->data==item)
         {
             temp->next=p->next;
             p->next=temp;
             flag=2;
             exit(0);
         }
       p=p->next;  
     }
     if(flag==1)
       cout<<item<<" node not present in list";
 }
 node* Addbefore(node*head,int item )
 {
    int val;
    cout<<"Enter val for new node?: ";
    cin>>val; 
    node *temp=new node(val);
    if(head==NULL)
    {
        cout<<"List is empty:";
        return head;
    }
    if(item==head->data)
    {
        temp->next=head;
        head=temp;
        return head;
    }
    node *p=head;
   while(p->next!=NULL) //stops when p points to last node
   {
       if(p->next->data==item)//second last node is checked at end
       {
           temp->next=p->next;
           p->next=temp;
           return head;
       }
       p=p->next;
   } 
   cout<<"item not present in list";
   return head;
 }
 node*  delete_first(node** head)//head contains address of start
{
  node *temp;
  if(*head==NULL)//value of strart
    return *head;
  temp=*head;           //temp=start;  
  *head=(*head)->next; //start=start->next;
  free(temp);
  return *head;  
}
void  Delete_at_last(node** head)
{   
    node *temp=NULL;
    node *cur=*head;
    if(*head==NULL)
        exit(0);
     //to delete first & last node
    if((*head)->next==NULL) {
        temp=*head;
         *head=NULL;
         delete temp;
         exit(0); }    
    while(cur->next!=NULL)
    {
        temp=cur;
        cur=cur->next;
    } 
    temp->next=NULL;
    delete cur;
}
node * delete_node(node* start,int data)
{
    node *temp,*p;
    if(start==NULL)
    {
        cout<<"list is Empty";
        return start;
    }
    if(start->data==data)
    {
        temp=start;  //temp stores address of noe to be deleteed first it is logically deleted and then it is deleted
        start=start->next;//using free()/delete
        delete start;
        return start;
    }
    p=start;
    // to get the previous node of node to be deleted
    while(p->next!=NULL)
    {
       if(p->next->data==data)  
       {
         temp=p->next;
         p->next=temp->next;
         free(temp);
         return start;
       }
       p=p->next;
    }
    cout<<"element "<<data<<" not found in list";
    return start;
}

int main() {
// solution comes here
node* root=new node;
int a;
  do
  {
      /* code */
      cout<<"1 to get_len \n";
      cout<<"2 to Display_List_elements \n";
     cout<<"3 search ................\n";
     cout<<"4 Add_at_Begining\n";
     cout<<"5 Insert_at_end\n";
     cout<<"6 Insert_at_givenpos\n";
     cout<<"7 add_after\n";
     cout<<"8  Addbefore\n";
     cout<<"10 Delete_at_last\n";
     cout<<"9 delete_first\n";
     cout<<" 11 delete_node\n";
     cout<<"12 Create_list\n";
     cout<<"Enter ur choice else 0 to exit\n";
     cin>>a;
     switch(a)
     {
         case 1:{int a=get_len(root);
               cout<<"lenth of list is:"<<a<<endl;
         break;}
         case 2:{
              Display_List_elements( root);
              break;
         }
         case 3:{
               int item;
               cout<<"enter element to be searched in linked list: ";
               cin>>item;
               search(root, item); break;
         }
         case 4:{
              int value;
               cout<<"enter element to be searched in linked list: ";
               cin>>value;
               root= Add_at_Begining( root, value);break; }
         case 5:{
             int value;
               cout<<"enter element to be inserted in linked list: ";
               cin>>value;
             root=Insert_at_end(root, value);break;}
         case 6:{
             int pos,value;
             node *New;
             cout<<"enter node value to be inserted and position: ";
             cin>>value>>pos;
             New=new node(value);
             Insert_at_givenpos(root, pos,New);break;
         }   
         case 7:{int item;
               cout<<"enter element to be inserted after in linked list: ";
               cin>>item;
             add_after(root, item);break;
         } 
         case 8:{
             int item;
               cout<<"enter element to be inserted after in linked list: ";
               cin>>item;
            root= Addbefore(root, item );break;
         }
         case 9:{
              Delete_at_last(&root);
              break;
         }
         case 10:{
             root=delete_first(&root);break;
         }
         case 11:{
             int item;
               cout<<"enter element to be deleted in linked list: ";
               cin>>item;
             root=delete_node(root,item);
         }
         case 12:root=Create_list(root);
          default:
            exit(0);
     }
     cout<<"\n";
  } while (a);
  
}
node* Create_list(node* start)
{
    int i,n,data;
    cout<<"ener no of nodes"<<endl;
    cin>>n;
    start=NULL;
    if(n==0)
    return start;
    cout<<"Enter element to be inserted";
    cin>>data;
    start=Add_at_Begining(start,data);
    for(i=2;i<=n;i++)
    {
        cout<<"Enter element to be inserted";
        cin>>data;
    start=Insert_at_end(start,data);
    }
    return start;
}
void Delete_List(node** head)
{
    node * auxillary ,*iterator;
    iterator=*head;
    while(iterator)
    {
        auxillary=iterator->next;
        delete iterator;
        iterator=auxillary;

    }
    *head=NULL;
}
node *reverse_list(node * start)
{
    node * prev, *ptr,*next;
    prev=NULL;
    while(ptr!=NULL)
    {
      next=ptr->next;
      ptr->next=prev;
      prev=ptr;
      ptr=next;
    }
    start=prev;
    return start;
}
void reverselistwith_data(node *head)
{
    int i,j,len,k,temp;
    node *p,*q;
    len=get_len(head);
    i=0;j=len-1;
    p=q=head;
    while(i<j)
    {
        k=0;
        while(k<j)
        {
            q=q->next;
            k++;
        }
        temp=p->data;
        p->data=q->data;
        q->data=temp;
        i++;j--;
        p=p->next;
        q=head;
    }
}
node * Delete__node(node **head,int position)
{
    int k=1;
    node *p,*q;
    if(*head==NULL)
  { 
     cout<<"list is empty";
     return *head;
  }
  p=*head;
  if(position==1)
  {
      *head=(*head)->next;
      free(p);
      return *head;
  }
  else{
      while(p!=NULL && k<position)
      {
          k++;
          q=p;
          p=p->next;
      }
      if(p==NULL)
      {
          cout<<"position does not exist";
          return *head;
      }
      else
      {
          q->next=p->next;
          free(p);
      }
      return *head;
  }
}
/*
  header node is dummy node that represent the begining of list and link part stores the addressof actual first node
  the info part of this node may contain empty or count of elements currently present in the list
  head pints to this dummy node iin emty list head->link=NULL
  since list is never empty first node is always there  we can avoid some spacial cases of empty list or insertion and deletion at begining
   p->link!=NULL link part of node to which p points does not contain null
   _____________________________________________________________________________________________________________________

   to Maintain a sorted linked list element has to be entered at proper palace
   in Function search we need to stop where we found element with valuw larger than element to be inserted
*/
//Insertion in sorted list
node* insert_s(node* start,int data)
{
    node* p,*temp;
    temp=new node(data);
    if(start==NULL && data<start->data)
    {
        temp->next=start;
        start=temp;
        return start;
    }
    else{
        p=start;
        while(p->next!=NULL &&p->next->data<data)
        {
             p=p->next;
        }
        temp->next=p->next;
        p->next=temp;
    }
}
void search(node* start,int data)
{
    node* p;
    int pos;
    if(start==NULL|| data < start->data)
    {
        cout<<"not found in list";
        return;
    }
    p=start;
    pos=1;
    while(p!=NULL && p->data<=data)
    {
        if(p->data==data)
        {
            cout<<"found at position"<<pos;
            return;
        }
        p=p->next;
        pos++;
    }
    cout<<"not found at leist";
}