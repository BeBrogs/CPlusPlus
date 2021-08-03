#include <iostream>
#include <memory>
#include <vector>
#include <string>


class Account{
double balance;
std::string name;

//Private getters
	std::string get_name(){ return name;}
	double get_balance() {return balance;}


public:
	//Default Constructor
	Account(std::string name_val="Null", double bank_bal=0){
		name = name_val;
		balance = bank_bal;
	}

	//Print methods
	void print_name(){
		std::cout << "Name: "<< get_name() << std::endl;}
	
	void print_balance(){
		std::cout << "Balance: $"<<get_balance() << std::endl;}


	//Deposit Method
	void deposit(double amount){
		balance += amount;
		print_balance();
	}

	//Withdraw Method
	void withdraw(double amount){
		if (balance - amount >=0){
			std::cout << "Withdrawing $" << amount << " from your account" << std::endl;
			balance -= amount;
			print_balance();

		}
		else
			std::cout << "Cannot withdraw $" << amount << " from your account.\nYou have insufficient funds." << std::endl;			 

	}

};


int main(){
	//Establishing and Initializing shared pointers
	std::shared_ptr<Account> p1 = std::make_shared<Account>("Brogan", 1234);
	
	p1->print_balance();
	p1->print_name();
	p1->withdraw(1234);
	p1->withdraw(1);
	p1->deposit(5555);

	//Establishing and Initializing shared pointers to append to a vector:
	auto p2 = std::make_shared<Account>("Larry", 223);
	auto p3 = std::make_shared<Account>("John", 2345);
	auto p4 = std::make_shared<Account>("Harry", 432432);

	std::cout << "\n" << std::endl;
	
	std::vector<std::shared_ptr<Account>> vec;
	vec.push_back(p2);
	vec.push_back(p3);
	vec.push_back(p4);


	for (auto& i: vec){
		i->print_balance();
		i->print_name();
		i->withdraw(10);
		i->deposit(1000);
		std::cout << std::endl;
	}


	return 0;
}


