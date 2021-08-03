/*
----------------------Section Challenge----------------------
Program Description:
1. Create a Basic Account Class
2. Create a IlllegalBalanceException class, derived from std::exception, to throw an error in the Account Constructor
   when the user provides a negative valuen for the balance parameter using the what() virtual function
3.Create a PinInvalidException class, derived from std::exception. Throw an error when entered pin is invalid

4. Create a InsufficientFundsException class, derived from std::exception, to provide an exception message when the
   user attempts to withdraw an amount that would leave their balance in the negative range.

Use c++ 17
Here we go.
*/


#include <iostream>
#include <string>
#include <memory>





class IllegalBalanceException: public std::exception{
public:
	//Default Constructor
	IllegalBalanceException()=default;

	//Default Destructor
	~IllegalBalanceException()=default;

	//Virtual Function "what()"
	//Will be accessed by catch statement
	//Won't change (const 1), won't change anything (const 2)
	//Won't throw an exception, which the noexcept keyword tells the compiler
	virtual const char* what() const noexcept{
		return "Insufficient Balance Provided";
	}

};



class InsufficientFundsException: public std::exception{
public:
	//Default Constructor
	InsufficientFundsException()=default;

	//Default Destructor:
	~InsufficientFundsException()=default;

	//Virtual Function "what()"
        //Will be accessed by catch statement
        //Won't change (const 1), won't change anything (const 2)
        //Won't throw an exception, which the noexcept keyword tells the compiler
	virtual const char* what() const noexcept{
		return "Insufficient Funds to Perform Transaction";
	}

};



class PinInvalidException: public std::exception{
public:
	PinInvalidException()=default;

	~PinInvalidException()=default;

	virtual const char* what() const noexcept{

		return "Pin Validation failed.\nExiting Program...";
	}
};


class Account{
//Private Attributes
std::string name;
double balance;
int pin;


//Private Methods:
//Getters:
std::string get_name(){return name;}
double get_balance(){return balance;}
int get_pin(){return pin;}


//Validate_pin - used to ask for and compare pins to complete actions
bool validate_pin(){
	int test_pin;
	std::cout << "\nEnter your pin to complete request: ";
	std::cin >> test_pin;


	if (get_pin() == test_pin){
		std::cout << "Pin Valid\n" << std::endl;
		return true;
	}
	return false;
}


//Setters:
void set_name(std::string name_val){name=name_val;}

void set_balance(double bal){balance=bal;}

void set_pin(int pin_val){pin=pin_val;}

public:
	//Default Value Delegating Constructor:
	Account(std::string name_val="NULL", double bal_val=0, int pin_val=0000)
		:name{name_val}, balance{bal_val}, pin{pin_val}{
		
			if (balance < 0){
				std::cout << "\n[" << get_name() << ", $" << get_balance() << "] ";
				throw IllegalBalanceException();
			}
			std::cout << "\nAccount Object Created: [" << get_name() << ", $" << get_balance() << "]" << std::endl;	
	}


	//Withdraw Method
	void withdraw(double amount){
		if(validate_pin() == true){
			std::cout << "Attemtping to withdraw $" << amount << " from $" << get_balance() << std::endl;				
			if(get_balance() - amount <0){
				throw InsufficientFundsException();
			}
			set_balance(get_balance()-amount);
			std::cout << "Success! Updated Balance: $" << get_balance() << std::endl;
		}
		else{
			throw PinInvalidException();		
		}
	}


	//Deposit Method
	void deposit(double amount){
		if (validate_pin() == true){
			std::cout << "Attempting to deposit " << amount << " into your account..." << std::endl;
			set_balance(get_balance()+amount);
			std::cout << "Success! Updated Balance: $" << get_balance() << std::endl;
		}
		else{
			throw PinInvalidException();
		}
	}


	~Account(){
		std::cout << "Destroying Account Object: [" << get_name() << ", $" << get_balance() << "]\n"<< std::endl;
	}


};


int main(){
        try{
                std::unique_ptr u1 = std::make_unique<Account>("Brogan", -42, 1234);

		try{
			u1->deposit(8);
			u1->withdraw(50);	
			u1->withdraw(2);
		

		}catch(const InsufficientFundsException &ex){
			std::cerr << ex.what() << std::endl;
		}

		catch(const PinInvalidException &ex){
			std::cerr << ex.what() << std::endl;
		}

        }catch(const IllegalBalanceException &ex){
                std::cerr << ex.what() << std::endl;
        }


        return 0;
}
