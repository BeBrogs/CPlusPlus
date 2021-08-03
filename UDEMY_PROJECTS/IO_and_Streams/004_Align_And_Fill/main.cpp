#include <iostream>
#include <iomanip>
#include <string>

int main(){
	std::string message {"Hello!"};
	int num {369};

		
	//The default we have when using std::setw is std::right
	std::cout << "Align Example One: (Use of setw)" << std::endl;
	std::cout << std::setw(10) << message << std::setw(10) << num << std::endl;


	//std::right will add padding to the left side of the output obj
	std::cout << "\n\nAlign Example Two: (Use of setw and right)" << std::endl;
	std::cout << std::setw(10) << std::right << message << std::setw(5) << std::right << num << std::endl;


	//std::left will add padding to the right side of the output obj
	std::cout << "\n\nAlign Example Three: (Use of setw and left)" << std::endl;
	std::cout << std::setw(10) << std::left << message << std::setw(10) << std::left << num << std::endl;


	//std::setfil('=') will set the given character to fill the padding of our given width
	std::cout << "\n\nAlign Example Four: (Use of std::right, std::setw and std::setfill)" << std::endl;
	std::cout <<std::setfill('=') <<std::setw(20) << std::right << message  << std::setw(10) << num << std::endl;

	std::cout << "\n\nAlign Example Four: (Use of std::right, std::left,std::setw and std::setfill)" << std::endl;
	//No need to declare setfill again, as the previous declaration of setfill will carry over until reset
	std::cout << std::setw(10) << std::right << message << std::setw(12) << std::right << num << std::endl;

	return 0;
}
