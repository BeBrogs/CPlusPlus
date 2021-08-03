#include <iostream>
#include <memory>
#include <vector>
#include <string>

//Showcase of Unique Pointers and Shared Pointers, as well as some explination


class Account{
std::string name;
double balance;

//Private Getters:
	std::string get_name(){return name;}
	double get_bal(){return balance;}

public:
	Account(std::string name_val, double bal_val){
		name = name_val;	
		balance = bal_val;
	}

	//Public Print Methods:

	void print_name(){
		std::cout << "Name: " << get_name() << std::endl;
	}
	
	void print_balance(){
		std::cout << "Balance: $" << get_bal() << std::endl;
	}	

	void print_details(){
		print_name();
		print_balance();

	}

	//Deposit method:
	void deposit(double amount){
		std::cout << "Depositing $" << amount << " into your account" << std::endl;
		balance += amount;
	}

	//Withdraw Method:
	void withdraw(double amount){
		if(balance - amount >=0){
			std::cout << "Withdrawing $" << amount << " from your account." << std::endl; 
			balance -= amount;
			print_balance();
		}
		
		else{
			std::cout << "Cannot withdraw $" << amount << " from your account." << std::endl;
			print_balance();
		}
	}
};


int main(){
	//Some info about Unique Pointers:
	//Cannot be copied, cannot be assigned. 
	//Are unique, no other unique pointer can point to the same object on the heap
	//Deleted automatically once no longer in use/ we go out of scope	


	//Creating a Unique Pointer to an account object:
	//1st method of establishing and initializing a unique pointer:
	//Using std::unique_ptr and std::make_unique
	std::unique_ptr<Account> u1 = std::make_unique<Account>("Brogan", 1234);

	
	//2nd method: Using auto and std::make_unique
	auto u2 = std::make_unique<Account>("YungBrogs", 12345);

	
	//Some Useful Methods for Unique Pointers
	std::cout << "Address belonging to u1: " <<u1.get() << std::endl; //Prints Address belonging to Pointr	

	
	u1.reset(); //Will nullify pointer

	
	//Accessing Member Methods belonging to Unique Pointers
	u2->print_details();
	u2->deposit(2344);
	u2->withdraw(12000);

	
	std::cout << std::endl;
	//More unique pointers to append to the vector:
	auto u3 = std::make_unique<Account>("Sean", 21323);
	auto u4 = std::make_unique<Account>("Star", 2321);

	
	//Creation of vector:
	std::vector<std::unique_ptr<Account>> vec;

	
	//We can only append unique pointers to the vector by using the std::move
	//As this will transfer the ownership of the address object from the unique pointer
	//to the vector
	vec.push_back(std::move(u2));
	vec.push_back(std::move(u3));
	vec.push_back(std::move(u4));

	
	//Creating for loop to automate some member access
	for(auto& i: vec){
		i->print_details();
		std::cout << std::endl;	
	} 


	//========================Onto some Shared Pointers========================
	//Some info on Shared Pointers:
	//You can establish and initialize shared pointers to the same object on the heap
	//Can be assigned, copied and moved
	//Are deleted automatically when the use_count reaches 0


	//There are 2 methods of establishing and initializing shared pointers:
	//1. Using std::shared_ptr and std::make_shared
	std::shared_ptr<Account> s1 = std::make_shared<Account>("Bimbo", 223);

	//2. Using auto and std::make_shared
	auto s2 = std::make_shared<Account>("Bilbo", 213213);


	//Assigning a shared pointer to the same address object as s2
	//Method One:
	auto s3 = s1;

	//Method Two:
	std::shared_ptr<Account> s4;
	s4 = s1;


	std::cout << std::endl;	
	//Useful methods for shared pointers:
	std::cout << "S1 Use Count: "<< s1.use_count() << std::endl; //Will print the use case of s1
	std::cout << "S2 Use Count: " << s2.use_count() << "\n"<< std::endl;


	//You can also nullify shared pointers by using reset:
	//s1.reset()

	
	//Creation of vector in order to create a collectio of shared pointers:
	std::vector<std::shared_ptr<Account>> vec2;

	
	//To append shared pointers to the vector, we don't need to use std::move
	vec2.push_back(s1);
	vec2.push_back(s2);
	vec2.push_back(s3);
	vec2.push_back(s4);
	

	//For loop for automated member access
	for (auto& i: vec2){
		i->print_details();
		std::cout << std::endl;
	}

	
	std::cout << "s1's use count: " << s1.use_count() << std::endl;
	


	return 0;
}

