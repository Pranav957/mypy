#include <bits/stdc++.h>
using namespace std;
class Bank_Account;
Bank_Account createAccount();
class Bank_Account
{
    string name_of_depositor="pranav";
    int Acc_no=3105;
    string Type_Of_Acc="saving";
    float Balance_Amount=200;
  public:
   Bank_Account(){};
   Bank_Account(string nod,int aNo,string TA,float Bal_Am);
   void Deposite_Amount(float amount);
   void Withdraw_Ammount(float amount);
   float Check_Bal()
   {
       return Balance_Amount;
   }
   void Display_NB();
};
 Bank_Account::Bank_Account(string nod,int aNo,string TA,float Bal_Am)
    {
        name_of_depositor=nod;
        Acc_no=aNo;
        Type_Of_Acc=TA;
        Balance_Amount=Bal_Am;
    }
   void Bank_Account::Deposite_Amount(float Amount)
    {
      Balance_Amount=Balance_Amount+Amount;
      cout<<"Your amount after deposition: "<<Check_Bal()<<endl;

    }
    void Bank_Account::Withdraw_Ammount(float amount)
    {
        int am=Check_Bal();
       // cout<<am<<endl;
        if(am<amount){
          cout<<"You have low Balance amount";
          cout<<"your balance amount is: "<<am<<endl;
          exit(0);
        }
        else{
          Balance_Amount=Balance_Amount-amount;
          cout<<"your balance now: "<<Check_Bal()<<endl;
          cout<<"Your Transaction completed"<<endl;
          cout<<"Thanks for visiting: "<<endl;
        }
        
    }
    void Bank_Account::Display_NB()
    {
        cout<<"Your Bank Details are: "<<endl;
        cout<<"name of Depositor: "<<name_of_depositor<<"  Balance amount: " <<Balance_Amount<<endl;
        cout<<"account np: "<<Acc_no<<" type of account: "<<Type_Of_Acc<<endl;

    }
    int main()
  {
     
     int a;
     int amt;
     Bank_Account b=createAccount();
     while(a){
     cout<<"1 for deposition\n ";
     cout<<"2 for withdraw\n ";
     cout<<"3 for check balance\n ";
     cout<<"4 for display\n ";
     cout<<"enter your choice\n";
     cout<<"enter 0 to exit";
     cin>>a;
     switch(a)
     {
       case 1:{
        cout<<"Enter amount to be deposited: "<<endl;
         cin>>amt;
          b.Deposite_Amount(amt);
          break;
         }
       case 2:
        {
         cout<<"emter amount to be withdrawn: ";
         cin>>amt;
         b.Withdraw_Ammount(amt);
         break;
        }
        case 3:
        {
            amt=b.Check_Bal();
            cout<<"Balance amount=: "<<amt<<endl;
            break;
        }
        case 4:
           b.Display_NB();
           break;
        default:{
           if(a==0)
           exit(0);
           else
             cout<<"wrong Input";
        }
        
     
     }
     }
  }
  Bank_Account createAccount()
  {
   string name_of_depositor;
    int Acc_no;
    string Type_Of_Acc;
    float Balance_Amount=100;
    cout<<"Enter Name of Depositor: "<<endl;
    cin>>name_of_depositor;
    cout<<"Enter Account no: "<<endl;
    cin>>Acc_no;
    cout<<"Enter type of Account: ";
    cin>>Type_Of_Acc;
    
 Bank_Account b1;
 b1=Bank_Account(name_of_depositor,Acc_no,Type_Of_Acc,Balance_Amount);
 return b1;
  }
    
/*int main() {
// solution comes here
    string name_of_depositor;
    int Acc_no;
    string Type_Of_Acc;
    float Balance_Amount=100;
    cout<<"Enter Name of Depositor: "<<endl;
    cin>>name_of_depositor;
    cout<<"Enter Account no: "<<endl;
    cin>>Acc_no;
    cout<<"Enter type of Account: ";
    cin>>Type_Of_Acc;
    
 Bank_Account b1;
 b1=Bank_Account(name_of_depositor,Acc_no,Type_Of_Acc,Balance_Amount);
 int amt;
 cout<<"Enter amount to be deposited: "<<endl;
 cin>>amt;
 b1.Deposite_Amount(amt);
 cout<<"emter amount to be withdrawn: ";
 cin>>amt;
 b1.Withdraw_Ammount(amt);
 b1.Display_NB();
}*/