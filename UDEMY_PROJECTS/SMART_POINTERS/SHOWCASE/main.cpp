#include <iostream>
#include <memory> //Lib holds smart pointers
#include <vector>
#include <string>

#include "Account.h"
#include "Savings_Account.h"

void my_deleter(Account *ptr){
        std::cout << "[my_deleter] Custom Deleter Reached" << std::endl;
        delete ptr;
}


int main(){
	//With general pointers, we are able to assign an Account object
	//To any object that inherits the Account Class

	std::shared_ptr<Account> s1 {new Account("Brogan", 1234), my_deleter};
	std::cout << std::endl;
	std::shared_ptr<Account> s2 {new Savings_Account("Brogan Saving", 12321, 4.2), my_deleter};

	std::cout << "You can access the address of a pointer using the get() method: "
	<< s1.get() << std::endl;


	std::cout << "\nAccessing s1's print_details method:" << std::endl;
	s1->print_details();
	std::cout << "Accessing s2's print_details method: " << std::endl;
	s2->print_details();
		
	std::cout << "\nShared Pointers are capable of pointing to the same address object in Memory\n";
	s2 = s1;
        std::cout << "\nAccessing s2's print_details method after reassignment: " << std::endl;
        s2->print_details();


	std::cout << "You can find the reference count of a managed/shared object using the" 
	<< " use_count method" << std::endl;
	std::cout << "s1 use count: " << s1.use_count() << "\n" <<std::endl;


	//You are able to create a vector of shared pointers easily, however,
	//Adding Unique Pointer Objects to a vector requires a work around using std::move
	//We need this to give the ownership of the pointer's Address Object to the vector and 
	//Nullify the Unique Pointer

	std::vector<std::unique_ptr<Account>> vec;
		
	auto p1 = std::make_unique<Account>("Hermes", 121212);
	auto p2 = std::make_unique<Account>("Athena", 213213);
	auto p3 = std::make_unique<Savings_Account>("Johnny Bravo", 3121, 1.4);

	std::cout << std::endl;

	//Adding the pointers to the vector of unique pointers pointing to address objects:
	vec.push_back(std::move(p1));
	vec.push_back(std::move(p2));

	//We are able to add a savings account object to the vector of Account objects as Savings_Account
	//Inherits the Account class
	vec.push_back(std::move(p3));

	//Accessing member methods using a for loop on the vector
	std::cout << std::endl;
	for (auto& i: vec){
		i->print_details();
		i->deposit(100);
		i->withdraw(10000);
		std::cout << std::endl;
	}


	return 0;
} //All pointers that weren't passed the my_deleter custom deleter will be destroyed here
