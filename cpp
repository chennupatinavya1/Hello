#include<iostream>
using namespace std;
class bank
{
	private:
		char name[20];
		string ac_no;
		float balance;
	public:
		void get()
		{
			cout<<"enter name:";
			cin>>name;
			cout<<"enter account name";
				cin>>ac_no;
			balance=234567.98;
		}
		void show()
		{
			cout<<"NAME:"<<name<<endl<<"ACCOUNT NO:"<<ac_no<<endl;
			cout<<"ACCOUNT BALANCE: RS."<<balance;
		}
		void op()
		{
			int t;
			float m,n;
			cout<<"select 1.withdraw "<<endl<<"2.deposit"<<endl;
			cin>>t;
			if(t==1)
			{
				cout<<"enter money to withdraw:";
				cin>>m;
				cout<<"after withdraw remaining money= "<<balance-m<<endl;
			}
			else if(t==2)
			{
				cout<<"enter money to deposit:";
				cin>>n;
				cout<<"after deposit remaining money= "<<balance+n<<endl;
			}
			else
			{
				cout<<"enetered wrong option";
			}
		}
		
};
int main()
{
	bank b;
	b.get();
	b.show();
	b.op();
	return 0;
}





#include<iostream>
#include<string.h>
using namespace std;
class bankAcc {
	int accNo;
	char cname[100], accType[100];
	double balance;
	public:
		bankAcc(int acno, char *name, char *atype, double bal) {
			accNo = acno;
			strcpy(cname, name);
			strcpy(accType, atype);
			balance = bal;
		}
		void deposit();
		void withdraw();
		void display();
};

void bankAcc::deposit() {
	double depAmt;
	cout<<"Enter amount to deposit: ";
	cin>>depAmt;
	balance = balance + depAmt;
}
void bankAcc::withdraw() {
	double amt;
	char reply;
	cout<<"Enter amount to withdraw: ";
	cin>>amt;
	
	if(amt < balance) {
		balance = balance - amt;
		cout<<"amount withdrawn"<<amt<<endl;
		cout<<"Do you like to display balance?(Y/N): ";
		cin>>reply;
		if(reply == 'Y'|| reply == 'y') {
			cout<<"Balance Amount is: "<<balance<<endl;
		}
	}
	else {
		cout<<"Insufficient Balance, Withdrawl cannot be processed!"<<endl;
	}
}
void bankAcc::display() {
	cout<<"Account details:"<<endl;
	cout<<"Account holder name: "<<cname<<endl;
	cout<<"Account number: "<<accNo<<endl;
	cout<<"Type of account: "<<accType<<endl;
	cout<<"Balance amount: "<<balance<<endl;
}
int main(void) {
	int acno, ch;
	char name[100], atype[100], rep;
	double bal;
	cout<<"Enter your details: "<<endl;
	cout<<"Enter Account holder name: ";
	cin>>name;
	cout<<"Enter account number: ";
	cin>>acno;
	cout<<"Enter type of account: ";
	cin>>atype;
	cout<<"Enter amount: ";
	cin>>bal;
	bankAcc ba(acno, name, atype, bal);
	cout<<endl;
	do {
		cout<<"Main menu"<<endl;
		cout<<"1.Deposit amount"<<endl<<"2.Withdraw amount"<<endl<<"3.Display"<<endl<<"4.Exit"<<endl;
		cout<<"Enter your choice(1/2/3/4): ";
		cin>>ch;
		switch(ch) {
			case 1: {
				ba.deposit();
				break;
			}
			case 2: {
				ba.withdraw();
				break;
			}
			case 3: {
				ba.display();
				break;
			}
			case 4: {
				exit(0);
			}
			default:
				exit(0);
		}
		cout<<"Do you like to continue(Y/n): ";
		cin>>rep;
	}while(rep != 'N' || rep != 'n');
}
