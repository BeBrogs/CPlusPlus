/*



*/


#include <iostream>
#include <iomanip>


int main(){
	double num{123.456789};
	std::cout << num << std::endl;


	std::cout << "\nSetting precision from 6 to 8 for: " << num;
	std::cout << std::setprecision(8)<< num << std::endl;


	//Fixed: Deals with numbers after decimal point
	std::cout << "\nSetting precision to 5 for after decimal point, adding zeros if needed: ";
	std::cout << std::setprecision(5) << std::fixed << num << std::endl;

	return 0;
}
