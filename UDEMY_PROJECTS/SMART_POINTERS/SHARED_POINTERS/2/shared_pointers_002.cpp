#include <iostream>
#include <memory>
#include <vector>

class Account{
public:
	void deposit(double amount){
		std::cout << "Withdrawing " << amount << " from your account" << std::endl;
	}

};


int main(){
	//initializing smart pointers
	std::shared_ptr<Account> p1 {new Account{}};
	
	std::cout << "P1 use count: " << p1.use_count() << std::endl;

	std::shared_ptr<Account> p2 {p1};
	
	std::cout << "\nP1 use count: " << p1.use_count() << std::endl;
	std::cout << "P2 use count: " << p2.use_count() << std::endl;

	std::vector<std::shared_ptr<Account>> vec;
	vec.push_back(p1);
	vec.push_back(p2);
	
	std::cout << "\nP1 use count: " << p1.use_count() << std::endl;
	std::cout << "P2 use count: " << p2.use_count() << std::endl;

	return 0;
}

