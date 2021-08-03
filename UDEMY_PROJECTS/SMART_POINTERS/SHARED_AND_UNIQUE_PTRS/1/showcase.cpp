#include <iostream>
#include <memory>
#include <string>
#include <vector>


class Account{
std::string name;
double balance;

//Private Getters:
	std::string get_name(){return name;}
	double get_balance(){return balance;}
public:
	//Default constructor:
	Account(std::string name_val="NULL", double bank_bal=0){
		name=name_val;
		balance=bank_bal;
	}

	//Public Printer Methods
	void print_name(){ std::cout << "Name: " << get_name() << std::endl;}
	
	void print_balance(){std::cout << "Balance: $" << get_balance() << std::endl;}

	void print_details(){
		print_name();
		print_balance();
	}

	//Deposit method:
	void deposit(double amount){
		std::cout << "Depositing $" << amount << " into your account." << std::endl;
		balance += amount;
		print_balance();
	}

	//Withdraw Method:
	void withdraw(double amount){
		if (balance - amount >=0){
			std::cout << "Withdrawing $" << amount << " from your account." << std::endl;
			balance -= amount;
			print_balance();		
		}

		else{
			std::cout << "Can't withdraw $" << amount << "from your account. You have insufficient funds" << std::endl;
		}
	}

};


int main(){
	//Establishing and Initializing Unique Pointer:
	std::unique_ptr<Account> u_a1 = std::make_unique<Account>("Brogan", 42000);

	u_a1->print_details();

	//Establishing and Initializing Unique Pointers to Account Objects to collect in a Vector:
	auto u_a2 = std::make_unique<Account>("Lorcan", 12234);
	auto u_a3 = std::make_unique<Account>("Sinead", 23455);

	std::vector<std::unique_ptr<Account>> vec;

	//Need to use std::move to append unique pointers to the Vector. This is because
	//We can only have one unique pointer owning the addressed object on the heap
	//std::move transfers ownership to the vector we are apending to.

	vec.push_back(std::move(u_a2));
	vec.push_back(std::move(u_a3));

	std::cout << "\nMember access via a for loop operating on a unique_ptr vector" << std::endl;
	for (auto& i: vec){
		i->print_details();	
	}


	//Establishing and initializing a Shared Pointer
	std::shared_ptr<Account> s_a1 = std::make_shared<Account>("Jill", 123324);
	
	std::cout << std::endl;
	s_a1->print_details();



	//Establishing and Initializing Shared Pointers, pointing to the same heap address as the s_a1 object
	auto s_a2 {s_a1};
	auto s_a3 {s_a1};


	std::cout << "\nUse count of s_a1: " << s_a1.use_count() << std::endl;


	//Creating vector which holds shared pointers to the same Account object on the heap 
	std::vector<std::shared_ptr<Account>> vec2;

	//We don't need to use std::move to append shared pointers to a vector, as we are allowed multiple
	//shared pointers pointing to the same Address Object on the heap
	vec2.push_back(s_a1);
	vec2.push_back(s_a2);
	vec2.push_back(s_a3);

	std::cout << std::endl;

	for (auto& i: vec2){
		i->print_details();
		i->withdraw(10000);
		i->deposit(10000);
	}


	std::cout << "\nUse count of s_a1 after multiple copies made: " << s_a1.use_count() << std::endl;


	return 0;
}//Both the Shared Pointers and Unique Pointers will be destroyed once no longer in use(Unique Pointers) or the use case == 0 (shared pointers)
