#include <bits/stdc++.h>
using namespace std;
class node
{ 
    public:
    int info;
    node* lchild;
    node* rchild;
    node(int val)
    {
      info=val;
      lchild=NULL;
      rchild=NULL;   
    }
};
node* Srarch(node* ptr,int key)
{
    while(ptr!=NULL)
    {
        if(key<ptr->info)
            ptr=ptr->lchild;
        if(key>ptr->info)
            ptr=ptr->rchild;
        else
           return ptr;        
    }
    return NULL;
}
node* recSearch(node* ptr,int key)
{
    if(ptr==NULL)
    {
        cout<<"key not found";
        return NULL;
    }
    else if(key<ptr->info)
        return recSearch(ptr->lchild,key);
    else if(key>ptr->info)
        return recSearch(ptr->rchild,key);
    else
        return ptr;            
}
node* min(node* ptr)
{
    if(ptr!=NULL){
        while(ptr->lchild!=NULL)
          ptr=ptr->lchild; 
    }
    return ptr;   
}
node* recmin(node* ptr)
{
    if(ptr==NULL)
        return NULL;
    else if(ptr->lchild==NULL)
        return ptr;
    else 
    return min(ptr->lchild);         
}
node* max(node* ptr)
{
    if(ptr!=NULL){
        while(ptr->rchild!=NULL)
          ptr=ptr->rchild; 
    }
    return ptr;   
}
node* recmax(node* ptr)
{
    if(ptr==NULL)
        return NULL;
    else if(ptr->rchild==NULL)
        return ptr;
    else 
    return min(ptr->rchild);         
}
node* insert(node* root,int key)
{
    node* temp,*ptr,*par;
    ptr=root;
    par=NULL;
    while(ptr!=NULL)
    {
        par=ptr;
        if(key<ptr->info)
           ptr=ptr->lchild;
        else if(key>ptr->info)
          ptr=ptr->rchild;
        else
        { 
          cout<<"duplicate tree";
          return root;  
        }   
    }
    temp=new node(key);
    if(par==NULL)
      root=temp;
    else if(key<par->info)
       par->lchild=temp;
    else
       par->rchild=temp;
     return root;       
}
node* recinsert(node* ptr,int key)
{
    if(ptr==NULL)
    {
        ptr=new node(key);
    }
    else if(key<ptr->info)
        ptr->lchild=recinsert(ptr->lchild,key);
    else if(key>ptr->info)
        ptr->rchild=recinsert(ptr->rchild,key);  
    else
     cout<<"duplicate key\n";
   return ptr;         
}
node* case_A(node* root,node* par,node* ptr)
{
    if(par==NULL)
        root=NULL;
    else if(ptr==par->lchild)
        par->lchild=NULL;
    else 
        par->rchild=NULL;
    free(ptr);
    return root;            
}
node* case_B(node* root,node*par,node* ptr)
{
    node* child;
    if(ptr->lchild!=NULL)
        child=ptr->lchild;
    else
        child=ptr->rchild;
    if(par==NULL)
        root=child;
    else if(ptr=par->lchild)
        par->lchild=child;
    else
        par->rchild=child;
        free(ptr);
        return root;                
}
node* case_C(node* root,node* par,node* ptr)
{
    node* succ,*parsucc;
    parsucc=ptr;
    succ=ptr->rchild;
    while(succ->lchild!=NULL)
    {
        parsucc=succ;
        succ=succ->lchild;
    }
    ptr->info=succ->info;
    if(succ->lchild==NULL && succ->rchild==NULL)
        root=case_A(root,parsucc,succ);
    else
        root=case_B(root,parsucc,succ);
      return root;      
}
node* Del(node* root,int key)
{
    node* par,*ptr;
    ptr=root;
    par=NULL;
    while(ptr!=NULL)
    {
        if(key==ptr->info)
          break;
        par=ptr;
        if(key<ptr->info)
           ptr=ptr->lchild;
        else
          ptr=ptr->rchild;     
    }
    if(ptr==NULL)
        cout<<"Key not present in the tree";
    else if(ptr->lchild!=NULL && ptr->rchild!=NULL)
        root=case_C(root,par,ptr);
    else if(ptr->lchild!=NULL)
         root=case_B(root,par,ptr);
    else if(ptr->rchild!=NULL)
         root=case_B(root,par,ptr);
    else
         root=case_A(root,par,ptr);
      return root;                     
}
node* Del_rec(node* root,int key)
{
    node* par,*ptr,*child,*succ,*parsucc;
    ptr=root;
    par=NULL;
    while(ptr!=NULL)
    {
        if(key==ptr->info)
           break;
        par=ptr;
        if(key<ptr->info)
          ptr=ptr->lchild;
        else
          ptr=ptr->rchild;      
    }
    if(ptr==NULL)
    {
        cout<<"key not present in the list";
        return root;
    }
    if(ptr->lchild!=NULL && ptr->rchild!=NULL)
    {
        parsucc=ptr;
        succ=ptr->rchild;
        while(succ->lchild!=NULL)
        {
            parsucc=succ;
            succ=succ->lchild;
        }
        ptr->info=succ->info;
        ptr=succ;
        par=parsucc;
    }
    if(ptr->lchild!=NULL)
         child=ptr->lchild;
    else
        child=ptr->rchild;
     if(par==NULL)
        root=child;
     else if(ptr=par->lchild)
        par->lchild=child;
    else
        par->rchild=child;
        free(ptr);
        return root;               
}
node* DEL_REC(node* ptr,int key)
{
    node* succ,*temp;
    if(ptr==NULL)
    {
        cout<<"key not found";
        return ptr;
    }
    if(key<ptr->info)
       ptr->lchild=DEL_REC(ptr->lchild,key);
    else if(key>ptr->info)
       ptr->rchild=DEL_REC(ptr->rchild,key);
    else
       //key tobe deleted found
    {
        if(ptr->lchild!=NULL && ptr->rchild!=NULL)
        {
            succ=ptr->rchild;
            while(succ->lchild)
               succ=succ->lchild;
            ptr->info=succ->info;
            ptr->rchild=DEL_REC(ptr->rchild,succ->info);   
        }
        else{
            temp=ptr;
            if(ptr->lchild!=NULL)
               ptr=ptr->lchild;
            else if(ptr->rchild!=NULL)
               ptr=ptr->rchild;
            else
               ptr=NULL;    
            free(temp);
        }
    }      
}


int main() {
// solution comes here
}