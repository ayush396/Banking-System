#include<iostream>
#include<fstream> 
#include<string.h>
#include<windows.h>
#include<conio.h>
#define min_bal 500

using namespace std;
class account{
	public:
		int balance;
		char first_name[50];
		char last_name[50];
		 long acc_var;
		long account_number;
		int deposit_status=0;
		int withdrawl_status=0;
		
	void accept1()
	{
		acc_var=1500153400;
		cout<<"\t\t\tEnter First Name: ";
		cin>>first_name;
		cout<<"\t\t\tEnter Last Name: ";
		cin>>last_name;
		acc_var++;
		account_number=acc_var;
		cout<<"\t\t\tEnter the initial balance: ";
		cin>>balance;
		}
		void accept2(int x,int bal)
	    {
		cout<<"\t\t\tEnter First Name: ";
		cin>>first_name;
		cout<<"\t\t\tEnter Last Name: ";
		cin>>last_name;
		acc_var=x;
		acc_var++;
		account_number=acc_var;
		balance=bal;
	}
	void accept(int x)
	{
		cout<<"\t\t\tEnter First Name: ";
		cin>>first_name;
		cout<<"\t\t\tEnter Last Name: ";
		cin>>last_name;
		acc_var=x;
		acc_var++;
		account_number=acc_var;
		cout<<"\t\t\tEnter the initial balance: ";
		cin>>balance;
	}
	void display()
	{
		cout<<"\t\t\tName of the Account Holder: "<<strcat(first_name,last_name)<<endl;
		cout<<"\t\t\tAccount Number is: "<<account_number<<endl;
		cout<<"\t\t\tAmount :"<<balance<<endl;
		
	}
};
account obj;
void add()
{
	cout<<"\t\t\tPress 0. If Database is Empty"<<endl;
	cout<<"\t\t\t Otherwise, Press 1. to Proceed "<<endl;
	int choice;
	cout<<"\t\t\tEnter your choice: ";
	cin>>choice;
	switch(choice)
	{
		case 0:
			{
			    obj.accept1();
	   			fstream wr;
				wr.open("e:\\project\\account.txt",ios::app);
				wr.write((char *)&obj,sizeof(obj));
				cout<<"\t\t\tGreetings!!! Account Created"<<endl;
				break;	
			}
			case 1:
		{
			long x;
			fstream rd;
			rd.open("e:\\project\\account.txt",ios::in);
			rd.seekg(0,ios::end);
			int size=rd.tellg()/sizeof(obj);
			rd.seekg(0,ios::beg);
			for(int i=1;i<=size;i++)
			{
				rd.read((char *)&obj,sizeof(obj));
				if(i==size)
				{
					x=obj.account_number;
				}
			}
			obj.accept(x);
	
			fstream wr;
			wr.open("e:\\project\\account.txt",ios::app);
			wr.write((char *)&obj,sizeof(obj));
			cout<<"\t\t\tGreetings!!! Account Created"<<endl;
			break;
		}
	}
}
	void Delete()
	{
		int n;
		cout<<"\t\t\tEnter the account number: ";
		cin>>n;
		fstream rd,wr;
		rd.open("e:\\project\\account.txt",ios::in);
	
		wr.open("e:\\project\\temp.txt",ios::out);
		rd.seekg(0,ios::end);
		int size=rd.tellg()/sizeof(obj);
		rd.seekg(0,ios::beg);
		for(int i=1;i<=size;i++)
		{
			rd.read((char *)&obj,sizeof(obj));
			if(obj.account_number==n)
			{
				obj.display();
				cout<<endl;
				cout<<"\t\t\tAccount has been closed Permanently"<<endl;
			}
			else
			{
				wr.write((char *)&obj,sizeof(obj));	
			}
					
		}
		wr.close();
		rd.close();
		remove("e:\\project\\account.txt");
		rename("e:\\project\\temp.txt","e:\\project\\account.txt");
	}
void search()
{
	int search_no;
	cout<<"\t\t\tEnter the Account Number: ";
	cin>>search_no;
	fstream rd;
	rd.open("e:\\project\\account.txt");
	rd.seekg(0,ios::end);
	int size=rd.tellg()/sizeof(obj);
	rd.seekg(0,ios::beg);
	for(int i=1;i<=size;i++)
	{
		rd.read((char *)&obj,sizeof(obj));
		if(obj.account_number==search_no)
		{
			cout<<"\t\t\tAccount Searched Successfully!"<<endl;
			obj.display();
		}
	}
	
	rd.close();
	 
}	
void update()
{
	int search_no;
	cout<<"\t\t\tLet's Fetch through Account Number :";
	cin>>search_no;
	fstream rd,wr;
	rd.open("e:\\project\\account.txt",ios::in);
	wr.open("e:\\project\\temp.txt",ios::out);
	rd.seekg(0,ios::end);
	int size=rd.tellg()/sizeof(obj);
	rd.seekg(0,ios::beg);
	for(int i=1;i<=size;i++)
	{
		rd.read((char *)&obj,sizeof(obj));
		if(obj.account_number==search_no)
		{
			obj.accept2(obj.account_number,obj.balance);
			obj.account_number=obj.account_number-1;
			cout<<endl;
			cout<<"\t\t\tAccount Details Updated Successfully! ";
		}
		wr.write((char *)&obj,sizeof(obj));
	}
	wr.close();
	rd.close();
	remove("e:\\project\\account.txt");
	rename("e:\\project\\temp.txt","e:\\project\\account.txt");
}
void showall()
{
	fstream rd;
	rd.open("e:\\project\\account.txt",ios::in);
	rd.seekg(0,ios::end);
	int size=rd.tellg()/sizeof(obj);
	rd.seekg(0,ios::beg);
	for(int i=1;i<=size;i++)
	{
		rd.read((char *)&obj,sizeof(obj));
		obj.display();
	}
}
void transfer()
{
	int search_no1,search_no2,n;
	cout<<"\t\t\tEnter Account Number to be DEBITED: ";
	cin>>search_no1;
	cout<<"\t\t\tEnter the PAYABLE Amount: ";
	cin>>n;
	fstream rd,wr;
	rd.open("e:\\project\\account.txt",ios::in);
	wr.open("e:\\project\\temp.txt",ios::out);
	rd.seekg(0,ios::end);
	int size=rd.tellg()/sizeof(obj);
	rd.seekg(0,ios::beg);
	int x;
	for(int i=1;i<=size;i++)
	{
		rd.read((char *)&obj,sizeof(obj));
		if(obj.account_number==search_no1)
		{
			obj.balance=obj.balance-n;
			x=obj.account_number;
			
		}
		wr.write((char *)&obj,sizeof(obj));
	}
	wr.close();
	rd.close();
	remove("e:\\project\\account.txt");
	rename("e:\\project\\temp.txt","e:\\project\\account.txt");
	cout<<endl;
	cout<<"\t\t\tEnter Account Numer to be CREDITED: ";
	cin>>search_no2;
	
	fstream rd1,wr1;
	rd1.open("e:\\project\\account.txt",ios::in);
	wr1.open("e:\\project\\temp.txt",ios::out);
	rd1.seekg(0,ios::end);
	int new_size=rd1.tellg()/sizeof(obj);
	rd1.seekg(0,ios::beg);
	
	for(int i=1;i<=new_size;i++)
	{
		rd1.read((char *)&obj,sizeof(obj));
		if(obj.account_number==search_no2)
		{
			obj.balance=obj.balance+n;
			cout<<"\t\t\tAmount: "<<n<<" from ACC/NO: "<<x<<" has been credited to "<<obj.account_number<<" successfully!!!";
		}
		wr1.write((char *)&obj,sizeof(obj));		
	}
	wr1.close();
	rd1.close();	
	remove("e:\\project\\account.txt");
	rename("e:\\project\\temp.txt","e:\\project\\account.txt");
}
class transaction{
	public:
	long account_number;
	int balance;
	string type;
	int deposit_status;
	int withdrawl_status;	
	int amount;
	int str(string a)
{
	int length;
    for(int i=0;a[i]!='\0';i++)
	{
		length++;
	}
	return length;	
}
	void display(int p,string q)
	{
		cout<<endl<<"\t\t\t"<<p<<"\t\t";
		cout<<q;
		for(int i=0;i<25-str(type);i++)
			{
				cout<<" ";
			}
    		cout<<amount;
	}
};
transaction obj2;

void deposit()
{
	int search_no;
	cout<<"\t\t\tEnter your Account Number: ";
	cin>>search_no;
	cout<<endl;
	int dep_amount;
	cout<<"\t\t\tEnter Amount to Deposit: ";
	cin>>dep_amount;
	fstream rd,wr;
	rd.open("e:\\project\\account.txt",ios::in);
	wr.open("e:\\project\\temp.txt",ios::out);
	rd.seekg(0,ios::end);
	int size=rd.tellg()/sizeof(obj);
	rd.seekg(0,ios::beg);
	int y,z,x;
	for(int i=1;i<=size;i++)
	{
		rd.read((char *)&obj,sizeof(obj));
		{
			if(obj.account_number==search_no)
			{
			
				y=obj.account_number;
				obj.balance=obj.balance+dep_amount;
				obj.deposit_status=1;
				z=obj.balance;
				x=obj.deposit_status;
				cout<<"\t\t\tAmount deposited Successfully!!!";
			}
			wr.write((char *)&obj,sizeof(obj));
		}
	}
	rd.close();
	wr.close();
	remove("e:\\project\\account.txt");
	rename("e:\\project\\temp.txt","e:\\project\\account.txt");
	fstream wr2,rd2;
	rd2.open("e:\\project\\account.txt",ios::in);
	rd2.seekg(0,ios::end);
	int size1=rd2.tellg()/sizeof(obj);
	rd2.seekg(0,ios::beg);
	wr2.open("e:\\project\\transaction.txt",ios::app);
	for(int i=1;i<=size1;i++)
	{
		if(y==search_no)
		{
			obj2.account_number=y;
			obj2.balance=z;
			
			obj2.amount=dep_amount;
			if(x==1)
			{
			     obj2.type="CREDIT";
			}
		
	
		}
			wr2.write((char *)&obj2,sizeof(obj2));
		wr2.close();
		rd2.close();
	}
	
	
	
	
}
void withdrawl()
{
	int search_no;
	cout<<"\t\t\tEnter your Account Number: ";
	cin>>search_no;
	cout<<endl;
	int with_amount;
	cout<<"\t\t\tEnter Amount to Withdraw: ";
	cin>>with_amount;
	fstream rd,wr;
	rd.open("e:\\project\\account.txt",ios::in);
	wr.open("e:\\project\\temp.txt",ios::out);
	rd.seekg(0,ios::end);
	int size=rd.tellg()/sizeof(obj);
	rd.seekg(0,ios::beg);
	int z,y,x;
	for(int i=1;i<=size;i++)
	{
		rd.read((char *)&obj,sizeof(obj));
		{
			if(obj.account_number==search_no)
			{
				y=obj.account_number;
				obj.withdrawl_status=1;
				x=obj.withdrawl_status;
				obj.balance=obj.balance-with_amount;
				z=obj.balance;
				cout<<"\t\t\tAmount Withdrawl done!!!";
			}
			wr.write((char *)&obj,sizeof(obj));
		}
	}
	rd.close();
	wr.close();
	remove("e:\\project\\account.txt");
	rename("e:\\project\\temp.txt","e:\\project\\account.txt");
	
	fstream wr2,rd2;
	rd2.open("e:\\project\\account.txt",ios::in);
	wr2.open("e:\\project\\transaction.txt",ios::app);
	rd2.seekg(0,ios::end);
	int size1=rd2.tellg()/sizeof(obj);
	rd2.seekg(0,ios::beg);

	for(int i=1;i<=size1;i++)
	{
	    rd2.read((char *)&obj,sizeof(obj));	
		if(y==search_no)
		{
			obj2.account_number=y;
		    obj2.balance=z;
		    
			obj2.amount=with_amount;
			if(x==1)
			{
				obj2.withdrawl_status=x;
				obj2.type="DEBIT";
			}
					
			
		}
		wr2.write((char *)&obj2,sizeof(obj2));
		wr2.close();
		rd2.close();
	}
}

void display_statement()
{
	cout<<endl<<endl<<endl;
	cout<<endl<<"\t\t\t***************************************************";
    cout<<endl<<"\t\t\t\t\tWelcome to BANKING SYSTEM";
    cout<<endl<<"\t\t\t***************************************************";
        int n;
        cout<<endl;
		cout<<"\t\t\tEnter Account Number: ";
        cin>>n;
    cout<<endl<<endl;
    fstream rd;
    rd.open("e:\\project\\transaction.txt",ios::in);
   
    cout<<endl<<endl<<"\t\t\t***************************************************";
    cout<<endl<<"\t\t\tTransaction No    TYPE(D/C)             Amount";
    cout<<endl<<"\t\t\t***************************************************";
    float total=0;                                            
    int count=0;
   
    rd.seekg(0,ios::end);
    int size=rd.tellg()/sizeof(obj2);
    rd.seekg(0,ios::beg);
    for(int i=1;i<=size;i++)
    {
    	rd.read((char *)&obj2,sizeof(obj2));
    	if(obj2.account_number==n )
    	{
    		if(obj2.type=="CREDIT")
    		{
    			count++;
    		total=obj2.balance;
			obj2.display(count,obj2.type);
			}
    		if(obj2.type=="DEBIT")
    		{
    		count++;
    		total=obj2.balance;
			obj2.display(count,obj2.type);
			}
		}
	
	}
	cout<<endl<<"\t\t\t***************************************************";
    cout<<endl<<"\t\t\t\t\t\t\t    Total "<<total;
    cout<<endl<<"\t\t\t***************************************************";
}

int main()
{  
    int exit=1;
	while(exit!=0)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE |
														   
                                                            BACKGROUND_RED|
															BACKGROUND_GREEN|
															BACKGROUND_INTENSITY);
		system("cls");
	cout<<endl<<"\t\t\t****************************************";
    cout<<endl<<"\t\t\t\tBANKING MANAGEMENT SYSTEM";
    cout<<endl<<"\t\t\t****************************************";
    cout<<endl<<endl;
	cout<<"\t\t\tPress 1. to OPEN new account !"<<endl;
	cout<<"\t\t\tPress 2. to CLOSE a existing account !"<<endl;
	cout<<"\t\t\tPress 3. to SEARCH for an account !"<<endl;
	cout<<"\t\t\tPress 4. to UPDATE the account details !"<<endl;
	cout<<"\t\t\tPress 5. to DEPOSIT the amount!"<<endl;
	cout<<"\t\t\tPress 6. to WITHDRAW the amount!"<<endl;
	cout<<"\t\t\tPress 7. to TRANSFER the amount! "<<endl;
	cout<<"\t\t\tPress 8. for MINI-STATEMENT !"<<endl;
	cout<<"\t\t\tPress 9. to show all accounts in the database !"<<endl;
	cout<<"\t\t\tPress any key to exit !!!"<<endl;
	int choice;
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),4<<2|10);
	cout<<"\t\t\tEnter your choice: ";
	cin>>choice;
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE |
														   
                                                            BACKGROUND_GREEN|
															BACKGROUND_BLUE|
															BACKGROUND_INTENSITY);
	switch(choice)
	{
		case 1:
			{
				add();
				break;
			}
		case 2:
			{
				Delete();
				break;
			}
		case 3:
			{
				search();
				break;
			}
		case 4:
			{
			
				update();
				break;
			}
	
		case 5:
			{
			 deposit();
				break;
			}
		case 6:
		    {
		        withdrawl();
		        break;	
			}
		case 7:
			{
				transfer();
				break;
			}
				
		case 8:
				{
				   display_statement();
					break;
				}
		case 9:
			{
				showall();
				break;
			}
			default:
				{
					exit=0;
					break;
				}
        }
        getch();
        SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE |
														   
                                                            BACKGROUND_RED|
															BACKGROUND_BLUE|
															BACKGROUND_INTENSITY);
	}
	return 0;
}
