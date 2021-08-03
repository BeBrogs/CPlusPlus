#include <iostream>

//Write a program that asks the user to enter the following:
//An integer representing the number of pennies

//The program should then display how to provide that change to the user.

//1 pound = 100p
//50 pence = 50p
//20 pence = 20p
//10 pence = 10p
//5 pence = 5p
//2 pence = 2p
//1 pence = 1p


//Example Run:
//Enter an amount in pennies: 92

//1 x 50 pence
//2 x 20 pence
//1 x 2 pence


int main(){
	int pennies;
	std::cout << "Enter an amount in pennies: ";
	std::cin >> pennies;

	int pounds, twenties, tens, fives, twos, ones;
	int fifties;
	

	while (pennies > 0){
	if (pennies >= 100 && pennies / 100 > 0){
		pounds = pennies / 100;
		pennies %= 100;
	}


	else if (pennies >=50 && pennies / 50 > 0){
		fifties = pennies / 50;
		pennies %= 50;
	}
		


	else if (pennies >= 20 && pennies / 20 > 0){
		twenties = pennies / 20;
		pennies %= 20;
	}


                
	else if (pennies >= 10 && pennies / 10 > 0){
		tens = pennies / 10;
		pennies %=10;
	}

                
	else if (pennies >= 5 && pennies / 5 > 0){
		fives = pennies / 5;
		pennies %= 5;
	}
                

	else if (pennies >= 2 && pennies / 2 > 0){
		twos = pennies / 2;
		pennies %=2;
	}
                

	else if (pennies >= 1 && pennies / 1 > 0){

		ones = pennies /1;
		pennies %= 1;
	}


}

	


	std::cout <<"====================================" << std::endl;
	std::cout << "Pound Coins: " << pounds << std::endl;
	std::cout << "50p Coins: " << fifties << std::endl;
	std::cout << "20p Coins: " << twenties << std::endl;
	std::cout << "10p Coins: " << tens << std::endl;
	std::cout << "5p Coins: " << fives << std::endl;
	std::cout << "2p Coins: " << twos << std::endl;
	std::cout << "1p Coins: " << ones << std::endl;
        std::cout << "====================================" << std::endl;
	

	return 0;


}
