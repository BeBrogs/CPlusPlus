#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

#include <string>
#include <iostream>
#include "I_Account.h"

class Account: public I_Account{
std::string name;
double balance;

//Private Getters:
        std::string get_name(){return name;}
        double get_balance(){return balance;}

public:
        //DELEGATING CONSTRUCTOR:
        Account(std::string name_val = "NULL", double bal_val=0)
                : name{name_val}, balance{bal_val}{

                        std::cout << "Account Created: (" << name << ": $" << balance << ")" << std::endl;
        }

        //OVERRIDDEN VIRTUAL FUNCTIONS:
        //As we have inherited from an interface class (A class featuring only pure virtual functions),
        //We need to make use of every function inherited.

        //OVERRIDEN PRINT METHODS
        virtual void print_name() override{std::cout << "Name: " << get_name() << std::endl;}
        virtual void print_balance() override{std::cout << "Balance: $" << get_balance() << std::endl;}
        virtual void print_details() override{print_name(); print_balance(); std::cout << std::endl;}


        //Deposit Method:
        virtual void deposit(double amount) override {
                std::cout << "Depositing: $" << amount << " into your bank account." << std::endl;
                balance += amount;
                print_balance();
        }

        ///Withdraw Method:
        virtual void withdraw(double amount) override{
                if (balance - amount >=0){
                        std::cout << "Withdrawing: $" << amount << " from your account." << std::endl;
                        balance -= amount;
                        print_balance();
                }

                else{
                        std::cout << "Unable to Withdraw $" << amount << "from your account. Insufficient funds" << std::endl;
                        print_balance();
                }

        }

        //Virtual Destructor
        virtual ~Account(){std::cout << "Account Object Destroyed." << std::endl;}
}; 
#endif

