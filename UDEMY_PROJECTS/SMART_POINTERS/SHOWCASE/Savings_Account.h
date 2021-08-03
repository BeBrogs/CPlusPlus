#ifndef _SAVINGS_ACCOUNT_H_
#define _SAVINGS_ACCOUNT_H_


class Savings_Account: public Account{
std::string name;
double balance;
double interest_rate;

//Private Getters:
	std::string get_name(){return name;}
	double get_balance(){return balance;}
	double get_interest_rate(){return interest_rate;}

public:
	//Delegating Constructor:
	Savings_Account(std::string name_val="Null", double bal_val=0, double interest_val=1.0)
		: name{name_val}, balance{bal_val}, interest_rate{interest_val}{
			
		std::cout << "[Savings_Account] Object Constructed (" << get_name() << ": $" << get_balance() 
		<< ": "<< get_interest_rate() << ")" << std::endl;}	

	//Function for Setting/Updating Interest Rate:
	void set_interest_rate(double rate){interest_rate = rate;}


	//OVERRIDEN VIRTUAL CONSTRUCTORS:
	//As we have inherited from an interface class (A class featuring only pure virtual functions),
        //We need to make use of every function inherited.


	//Overriden Print Methods:
	virtual void print_name() override{std::cout << "Name: "<< get_name() << std::endl;}
	virtual void print_balance() override{std::cout << "Balance: $" <<get_balance() << std::endl;}


	//Original virtual function - does not appear in I_Account or Account Classes
	//No need to declare override
	virtual void print_interest_rate(){std::cout << "Interest Rate: " << get_interest_rate() << std::endl;}

	
	//Back to overriding inherited functions
	virtual void print_details() override{
		print_name(); print_balance(); print_interest_rate();}


	//Overriding Deposit Method:
	virtual void deposit(double amount) override{
		std::cout << "Depositing: $" << amount << " into your account." << std::endl;
		balance += (amount*interest_rate);
		print_balance();}


	//Overriding Withdraw Method:
	virtual void withdraw(double amount) override{
		if (balance - amount > 0){
			std::cout << "Withdrawing $" << amount << " from your account." << std::endl;
			balance -= amount;
			print_balance();}
		else{
			std::cout << "Unable to Withdraw $" << amount << " from your account. You have Insufficient funds\n"
			<< std::endl;
			 print_balance();}}

	//Virtual Destructor:
	~Savings_Account(){};
};

#endif
