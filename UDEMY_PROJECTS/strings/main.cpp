//Substitution/Caesar Cipher
//Write a program that asks a user to enter a secret message.

//Encrypt this message using the caesar cipher.
//Also ask the user for the caesar shift value.


#include <iostream>
#include <string> //C++ String LIB
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	std::vector<char> alphabet{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l','m', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'}; 	

	//Asking user for original string
	std::string original_string;
	std::cout << "Enter your original string: ";
	std::cin >> original_string;


	//Transforming all letters in original_string to lowercase
	std::cout << "Transforming string to become lowercase in order to perform shift: ";
	transform(original_string.begin(), original_string.end(), original_string.begin(), ::tolower);
	std::cout << original_string << std::endl;


	//Asking user for their desired shift value 
	int cipher;
	std::cout << "\n\nEnter the number of times you would like to shift your message\n(i.e. 5 will move f values to b (n-5)): ";
	std::cin >> cipher;

	
	//Empty string to hold ciphered message after shift
	std::string ciphered_message;


	//Nested loop.
	//Parent loop runs through each letter of original_string	
	for (int i {0}; i < original_string.length(); ++i){
		
		//Child string runs through each letter belonging to alphabet vector
		for (int j {0}; j < alphabet.size(); ++j){
			
			//If our parent loops's character matches the child loops charecter, enter if statement
			if (original_string[i] == alphabet[j]){
				//Initializing new index dependant upon the user's input for the cipher
				int index = j - cipher;

                            	//If our index value is more than or equal to 0, we have nohing to worrry about, we're still in range.
				if (index >=0){
					//String concatenation
					ciphered_message += alphabet[index];
				}
				
				else{
                			//If we enter a negative index, we still need to provide the appropriate letter
                			//i.e. -1 = z

					//We will add 25 to the minus value index so that we are at the end of the alphabet vector.
	
					int sub_index = 25 + index;
					
					//String concatenation
					ciphered_message += alphabet[sub_index];

				}
			}

		}


	}


	std::cout << "Original String: " << original_string << std::endl;
	std::cout << "\nCiphered String after an index shift of "<< cipher << " :\n" << ciphered_message << std::endl;



	return 0;
}
