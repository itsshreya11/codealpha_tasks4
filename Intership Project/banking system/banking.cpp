#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Bank{
    
  public:
    string accountNo;
    string name;
    float balance;
void CreateAccount(){
    cout<<"Enter account number:"<<endl;
    cin>>accountNo;
    cout<<"Enter account name:"<<endl;
    cin>>name;
    cout<<"Enter initial balance:"<<endl;
    cin>>balance;

    ofstream file(accountNo + ".txt");
    if (file.is_open()){
        file <<accountNo <<endl;
        file <<name <<endl;
        file <<balance <<endl;
        file.close();
        cout<<"Account created successfully!\n";

    }
    else{
       cout<<"Error Creating account.\n";
    }
} 
bool loadAccount(string accountNo){
    ifstream file(accountNo + ".txt");
    if(file.is_open()){
        getline(file,accountNo);
        getline(file,name);
        file >> balance;
        file.close();
        return true;
    }
    else{
        return false;
    }
}
void deposite(){
    float amount;
   cout<<"Enter amount to deposite:"<<endl;
   cin>>amount;
   balance += amount;
   updateAccount();
   cout<<"Amount deposite successfully.\n";
}
void withdraw(){
    float amount;
    cout<<" Enter amount  to withdraw:";
    cin>>amount;
    if (amount > balance){
        cout<<"insufficient balance!\n";
    }
    else{
        balance -= amount;
        updateAccount();
        cout<<"Amount withdraw successfully.\n";
    }
}
void checkBalance(){
    cout<<"Account Number:"<<accountNo<<endl;
    cout<<"name:"<<name<<endl;
    cout<<"balance: $"<<balance<<endl;
    
}
void updateAccount(){
    ofstream file(accountNo + ".txt");
    if(file.is_open()){
    file << accountNo <<endl;
    file << name <<endl;
    file << balance <<endl;
    file.close();
    }
}
};

int main(){
    int choice;
    Bank acc;
    string accountN;

    while(true){
        cout << "\n===== BANK SYSTEM =======\n";
        cout<<"1. Create Account"<<endl;
        cout<<"2. deposite"<<endl;
        cout<<"3. withdraw"<<endl;
        cout<<"4. check balance"<<endl;
        cout<<"5. exit"<<endl;
        cout<<"Enter your choice";
        cin>> choice;

    switch (choice){
        case 1:
          acc.CreateAccount();
          break;
        case 2:
           cout<<"enter account number:" ;
           cin >> accountN;
           if(acc.loadAccount(accountN))
           acc.deposite();
           else
           cout << "Account not found .";
           break;
           case 3:
           cout<<"Enter account number:";
           cin>>accountN;
           if(acc.loadAccount(accountN))
           acc.withdraw();
           else
             cout<<"account not found.\n";
           break;
           case 4:
           cout <<"Enter account number:";
           cin>>accountN;
           if(acc.loadAccount(accountN))
           acc.checkBalance();
           else
           cout << "Account not found.\n";
           break;
           cout<<"Exiting.....\n";
           return 0;
           default:
           cout<<"invalid choice.\n";


    }
    }

}