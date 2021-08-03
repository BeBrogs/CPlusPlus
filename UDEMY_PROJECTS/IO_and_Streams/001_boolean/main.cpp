/*
----------------------Program Description----------------------
Demonstration of manipulating the ostream when handling
boolean values, using methods and member methods.

*/


#include <iostream>
#include <iomanip> //Used for manipulation

int main(){
	std::cout << "\nDefault OStream when handling boolean values: " << std::endl;
	std::cout << "(10 == 10) = " << (10==10) << std::endl;
	std::cout << "(10 != 10) = " << (10!=10) << std::endl;




	std::cout << "\nEnabling boolalpha method." << std::endl;
	std::cout << std::boolalpha;
	//All boolean prints will follow the boolalpha format until we change this
	std::cout << "(12 < 13) = " << (12<13) << std::endl;
	std::cout << "(1 >= 0) = " << (1 >= 0) << std::endl; 

	std::cout << "\nEnabling noboolalpha method." << std::endl;
	std::cout << std::noboolalpha;
        //All boolean prints will follow the boolalpha format until we change this
	std::cout << "(1 <= 2) = " << (1 <= 2) << std::endl;
	std::cout << "(0 != 0) = " << (0 != 0) << std::endl;



	//Manipulating OStream using std::cout method '.setf()' included in package: iomanip
	std::cout << "\nBack to boolalpha using .setf method on cout operator" << std::endl;
	std::cout.setf(std::ios::boolalpha);
	std::cout << "(333 == 888) = " << (333==888) << std::endl;
	std::cout << "(12 != 13) = " << (12 != 13) << std::endl	;	

	std::cout << "\nBack to boolalpha using .setf method on cout operator" << std::endl;
	std::cout << std::resetiosflags(std::ios::boolalpha);
        std::cout << "(333 == 888) = " << (333==888) << std::endl;
        std::cout << "(12 != 13) = " << (12 != 13) <<  "\n" << std::endl ;	



return 0;
}
