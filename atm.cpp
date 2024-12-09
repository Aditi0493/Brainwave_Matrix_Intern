#include<iostream>
using namespace std;
class ATM{
    private:
        int balance;
        int pinCode;
        int Success;
        int pin;
    public:
        ATM(int bal){
            balance = bal;
            pinCode = pin;
        }
        int getBalance(){
            return balance;
        }
        int withdraw(int amount, int pin){
            if(pin !=pinCode){
                return false;
            }
            if(amount > balance){
                return false;
            }
            balance = balance - amount;
            return true;
        }
        void deposit(int amount ){
            balance = balance + amount;
        }
        int transfer(int amount, ATM receiver, int pin){
            if(pin!= pinCode){
                return false;
            }
            Success = withdraw(amount, pin);
            if(Success){
                receiver.deposit(amount);
                return true;
            }
            else{
                return false;
            }

        }
};
main(){
    ATM atm(1000);
    int choice,amount,success,pin;
    char op;
    do{
        system("cls");
        cout<<"1. View Balance"<<endl;
        cout<<"2. Cash Withdraw "<<endl;
        cout<<"3. Cash Deposit"<<endl;
        cout<<"4. Cash Transfer"<<endl;
        cout<<"5. Exit"<<endl;
        cout<<"Enter Your Choice:";
        cin>>choice;
        switch(choice){
        case 1: 
            cout<<"Your Balance : "<<atm.getBalance();
            break;
        case 2: 
            cout<<"Your Available Balance : "<<atm.getBalance()<<endl;
            cout<<"Enter the Amount to Withdraw:";
            cin>>amount;
            success = atm.withdraw(amount, 1234);
            if(success){
                cout<<"Withdraw Successfull..."<<endl;
            }
            else{
                cout<<"Insufficient Balance..."<<endl;
            }
            break;
        case 3:
                cout<<"Enter the Amount to Deposit: ";
                cin>>amount;
                atm.deposit(amount);
                cout<<"Deposit Successfull..."<<endl;
                break;
        case 4: 
                cout<<"Your Available Balance : "<<atm.getBalance()<<endl;
                cout<<"Enter the Amount to Transfer :";
                cin>>amount;
                cout<<"Enter PinCode:";
                cin>>pin;
                success = atm.transfer(amount,atm,pin);
                if(success){
                    cout<<"Transfer Successfully..."<<endl;
                }
                else{
                    cout<<"Invalid pin or Insufficient  Balance"<<endl;
                }
                break;
        case 5:
                cout<<"Thanks for using ATM"<<endl;
                exit(1);
                break;
        default:
                cout<<"Invalid Choice"<<endl;
    //cout<<"Your Balance : "<<atm.getBalance();
    
        
    }
    cout<<" \nDo You Want to Try Another Transaction [Yes / No] :";
    cin>>op;
    }
    while(op == 'y' || 'Y');

    
}