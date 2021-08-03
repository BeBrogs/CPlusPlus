/*

======================= Program Description =======================
1. Outputting a single integer using dec, hex & oct
2. Outputting a single integer in hexadecimal value, in uppercase
3. Showing whether or not an integer is positive or negative

*/


#include <iostream>
#include <iomanip> //Includes integer formatting


int main(){
	int num{255};

	std::cout << "\n" << num << " in base 10 (decimal): ";
	std::cout  << std::dec << num << std::endl;
	std::cout << num << " in base 8 (oct): "; 
	std::cout << std::oct << num << std::endl;
	std::cout << std::dec << num << " in base 16 (hexadecimal): ";
	std::cout  << std::hex << num<< std::endl;

	std::cout << "\n\nShowing the base of above numbers..." << std::endl;
	//std::showbase will show the base of our number

	std::cout << std::dec << num << " in base 10: ";
	std::cout << std::showbase << std::dec << num << std::endl;

	std::cout << std::dec << num << " in base 8: ";
	std::cout << std::showbase << std::oct << num;

	//Showing Uppercase hex val
	std::cout << "\n" << std::dec << num << " in base 16 (Hex, uppercase) ";
	std::cout  << std::showbase << std::hex << std::uppercase << num << std::endl;


	//Showing linear position of number:
	std::cout << "\nShowing linear position of positive number... "<< std::showpos << std::dec << num << std::endl;
	int num1{-225};
	std::cout << "\nShowing linear position of negative number...  "<< std::showpos << std::dec << num1 << "\n" << std::endl;

	return 0;
}
