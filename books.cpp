//need to work
#include <bits/stdc++.h>
#include<string>
using namespace std;
class Books
{  
    private:
    string author;
    string title;
    float Price;
    string publisher;
    int position;
   public:
   Books(){}
   Books(string author,string title,float price,string publisher,int position);
   friend  void Search_Book(string title,string author,Books b[],int n);
   friend int check(string author,string title,Books b[],int n);
   friend float total_cost(int n,Books b);
};
void Search_Book(string title,string author,Books b[],int n)
   {
       for(int i=0;i<n;i++)
       {
           if(b[i].author==author && b[i].title==title)
           {
               int no,copies;
               cout<<b[i].title<<" Book is availabele: "<<endl;
               cout<<"Price= "<<b[i].Price<<"  "<<"Publisher="<<b[i].publisher;
               cout<<"Enter how many copies do u want? "<<endl;
               cin>>no;
              copies=check(author,title,b,no);
              if(copies==no)
              {
                 float cost=total_cost(no,b[i]);
                 cout<<"Total cost of all books is: "<<cost;
              }
              else{
                  cout<<"Required copies not in stock!"<<endl;
              }
           }
       }
   }
   int check(string author,string title,Books b[],int n)
   {
       int count=0;
    for(int i=0;i<n;i++)
    {
       if(b[i].author==author && b[i].title==title)
       {
         count++;
       }
       return count;
    }
   }
   float total_cost(int n,Books b)
   { 
       float total_cost;
       for(int i=0;i<n;i++)
       {
           total_cost=total_cost+b.Price;
       }
       return total_cost;
   }
 Books::Books(string author,string title,float price,string publisher,int position)
 {
     author=author;
     title=title;
     price=price;
     publisher=publisher;
     position=position;
 }
 int size=100;
int main() {
// solution comes here
int n;
cout<<"enter no of books in a system: ";
cin>>n;
Books b[n];
//char author[size];
string author;
string title;
float Price;
string publisher;
int position;
for(int i=0;i<n;i++)
{
    cout<<"enter name author of book to be stored: ";
    getline(cin,author);
    cout<<"enter title of this book: "<<endl;
    getline(cin,title);
    cout<<"enter price of this book: "<<endl;
    cin>>Price;
    cout<<"enter the name of publisher of this book:  "<<endl;
    getline(cin,publisher);
    cout<<"Enter the position to keep this book on: "<<endl;
    cin>>position;
    b[i]=Books(author,title,Price,publisher,position);
}
    int option;
    cout<<"Enter 1 if u want to buy a book and 0 to exit: "<<endl;
    cin>>option;
    if(option==1)
    { string TT,AT;
        cout<<"Enter title and name of book u want to purchase: "<<endl;
        cin>>TT>>AT;
        Search_Book(TT,AT,b,n);
    }
    else
     exit(0);

}
