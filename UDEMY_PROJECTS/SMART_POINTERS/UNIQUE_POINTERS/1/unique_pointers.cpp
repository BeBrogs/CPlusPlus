#include <iostream>
#include <memory>
#include <vector>
#include <string>


class Account{
std::string name;
double balance;

        std::string get_name(){
                return name;
        }

	double get_bal(){
		return balance;
	}

public:
	//Name_val necessary, bal_val has default parameter
	Account(std::string name_val, double bal_val=0){
		//std::cout << "[Account] Constructor Triggered" << std::endl;
		name = name_val;
		balance = bal_val;
	}

	void print_name(){
		std::cout << get_name() << std::endl;
	}

	void print_balance(){
		std::cout << get_bal() << std::endl;
	}

	void deposit(double amount){
		std::cout << "Depositing " << amount << " into your account" << std::endl;
	}	

	void withdraw(double amount){
		std::cout << "Withdrawing " << amount << " from your account" << std::endl;
	}
};


int main(){
	//There are two methods of initializing unique pointers:
	//1. Using std::unique_ptr<type> p_name = std::make_unique<type>(data);
	std::unique_ptr<int> p1 = std::make_unique<int>(123);


	//2. Using auto p_name = std::make_unique<type>(data)
	auto p2 = std::make_unique<int>(369);


	std::cout << "\nDerefernecing of p1 and p2 to print data" << std::endl;
	//Dereferencing the pointers to follow the data it holds in its designated
	//address from memory
	std::cout << *p1 << std::endl;
	std::cout << *p2 << std::endl;
	

	std::cout << "\nPrinting the heap address assigned to p1 and p2:" << std::endl;
        //Some accessible methods associated with smart pointers
        //.get() in order to get the address from the heap associated with pointer
        std::cout << p1.get() << std::endl;
	std::cout << p2.get() << std::endl;


	//You may also nullify a pointer by typing:
	//p1.reset(); or
	//p2.reset()

	
	//Creating a collection of smart pointers using vectors. This would be 
	//useful for user-defined objects, where you want to trigger class methods	
	std::vector<std::unique_ptr<Account>>unique_ptr_vec;
	

	//Creating unique pointers to Account Objects:
	auto a1 = std::make_unique<Account>("Nala", 12345);	
	auto a2 = std::make_unique<Account>("Sky", 1600);
	auto a3 = std::make_unique<Account>("Star", 13455);


	//Appending account unique pointers to vector. We can only push_back
	//smart pointers/ unique pointers to a vector using std::move as this transfers
	//ownership of the heap address belonging to a pointer to the vector, and nullifies appended pointers
	unique_ptr_vec.push_back(std::move(a1));
	unique_ptr_vec.push_back(std::move(a2));
	unique_ptr_vec.push_back(std::move(a3));

	std::cout << std::endl;
	for (auto& i: unique_ptr_vec){
		std::cout << "Name: ";
		i->print_name();
		std::cout << "Balance: ";
		i->print_balance();
	}	


	return 0;
}
