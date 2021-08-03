#ifndef I_ACCOUNT_H_
#define I_ACCOUNT_H_

#include <iostream>

class I_Account{
//I_Account is an interface class (An abstract class featuring only pure virtual functions)
//And will be inherited by future Account classes, where they will use all functionality.
public:
        //Pure Virtual Functions:

        //Print Methods
        virtual void print_name()=0;
        virtual void print_balance()=0;
        virtual void print_details()=0;


        //Deposit Method:
        virtual void deposit(double amount)=0;

        //Withdraw Method
        virtual void withdraw(double amount)=0;


        //Virtual Destructor:
        virtual ~I_Account(){};

};
#endif
