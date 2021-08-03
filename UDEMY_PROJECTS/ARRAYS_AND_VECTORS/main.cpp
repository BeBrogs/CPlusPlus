#include <iostream>
#include <vector>


//Challenge/Program Description:
//Declare 2 empty vectors of integers, named 'vector1' & 'vector2'
//Add 10 & 20 to vector1. Display the elements in vector1 and the vectors size

//Add 100 & 200 to vector2. Display elements and size

//Declare an empty 2D array called vector_2d
//Add vector1 and vector2 to vector_2d
//Display elements of vector_2d

//Change vector1.at(0) to 100
//Display Elements in vector_2d again
//Display elements of vector1 again


int main(){
	//Declaring empty vectors:
	std::vector<int> vector1, vector2;

	vector1.push_back(10);
	vector1.push_back(20);


	std::cout << "Vector1's Elements: [";
	for(size_t i {0}; i < vector1.size(); ++i)
		std::cout << vector1[i] << ",";

	std::cout << "]\nVector1's size: " << vector1.size() << "\n" << std::endl;	

	
	vector2.push_back(100);	
	vector2.push_back(200);

	std::cout << "Vector2's Elements:[";
	for(size_t i{0}; i < vector2.size(); ++i)
		std::cout << vector2[i] << ",";

	std::cout << "]\nVector2's size: " << vector2.size() << "\n"<<std::endl;

	std::vector<std::vector<int>> vector_2d;

	vector_2d.push_back(vector1);
	vector_2d.push_back(vector2);


	std::cout << "Vector_2d's size: " << vector_2d.size() << "\n" << std::endl;

	std::cout << "Vector_2d's first element: [" << vector_2d[0][0] << "]"  << std::endl;
	std::cout << "Vector_2d's second element: [" << vector_2d[0][1] << "]" <<std::endl;

	vector1.at(0) = 100;
	
        std::cout << "\nVector_2d's first elements: [" << vector_2d[0][0] << ", " << vector_2d[0][1] << "]" << std::endl;
        std::cout << "Vector_2d's second elements: [" << vector_2d[1][0] << ", "<<vector_2d[1][1] << "]" <<std::endl;

	std::cout << "Vector1's elements: ";
	for(size_t i{0}; i < vector1.size(); ++i)
		std::cout << vector1.at(i) << ",";
	std::cout << std::endl;


}


