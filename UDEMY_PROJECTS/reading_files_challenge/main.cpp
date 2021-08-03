#include <iostream>
#include <string>
#include <fstream>
#include <vector>


int main(){
	std::ifstream results;
	results.open("results.txt");

	if (!results){
		std::cout << "Error: File is unable to be opened" << std::endl;
		return 1;
	}




	std::cout << "Student" << std::setw(15) << "Score" << std::endl;
	std::cout << std::setfill('=') << std::setw(23) << "\n" << std::endl;



	std::string line;
	std::string name;
	std::string results_key;
	
	std::string student_results;

	std::vector<char> correct_results {};
	std::vector<char> individual_student_results {};
	std::vector<std::string> student_names{};

	
	int line_number {1};

	while (!results.eof()){
		if(line_number == 1){
			std::getline(results, results_key);
			for (int i {0}; i <=4; ++i){
				correct_results.push_back(results_key[i]);
			}	
		}	
		else{
			if (line_number%2 == 1){

				std::getline(results, student_results);
				for (int i {0}; i <= 4; ++i){
					individual_student_results.push_back(student_results[i]);	

				}

			}
			else{
				std::getline(results, name);
				//std::cout << "GRADE: " << name << std::endl;
				student_names.push_back(name);
								
			}

		}

		++line_number;
	}





	results.close();


	return 0;
