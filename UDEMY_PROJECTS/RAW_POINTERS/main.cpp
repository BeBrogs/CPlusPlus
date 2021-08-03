/*
Write a C++ Function named apply_all that expects two arrays of integers and their sizes and
dynamically allocates a new arrange of integers whose size is the product of the 2 array sizes

apply_all wil loop through array2 and multiply each element across each element of array1
and store the product in the newl created array.


apply_all should return a pointer to a newly allocated array.

Another function will be written to print all elements of the array
*/


#include <iostream>


//Function Prototypes:
void print(int array[], size_t size);
int* apply_all (int array1[], size_t array1_size, int array2[], size_t array2_size); 



int main(){
	//Initializing arrays
	int array1[] = {1,2,3};
	int array2[]= {3,6,9};

	//Initializing sizes of arrays
	size_t array1_size = sizeof(array1)/ sizeof(array1[0]);
	size_t array2_size = sizeof(array2)/sizeof(array2[0]);

	//Calling Print methods
	std::cout << "First Array's Elements: ";
	print(array1, array1_size);
	std::cout << "\nSecond Array's Elements: ";
	print(array2, array2_size);
	

	int *results = apply_all(array1, array1_size, array2, array2_size);	
	
	std::cout << "\nFirst Array * Second Array Elements: ";
	print(results, (array1_size * array2_size)); 

}


void print(int array[], size_t size){
	std::cout << "[";
	for(size_t i {0}; i < size; ++i){

		if (i != (size-1))
			std::cout << array[i] << ", ";
		else if (i == (size-1))
			std::cout << array[i];

	}
	std::cout << "]" << std::endl;	
}

int* apply_all (int array1[], size_t array1_size, int array2[], size_t array2_size){
	int *final_arr = new int[array1_size * array2_size];
	
	int final_arr_size = array1_size * array2_size;

	int index {0};

	while (index < final_arr_size){

		for(int i {0}; i < array1_size; ++i){
			for (int j{0}; j < array2_size; ++j){
				//std::cout << array1[i] * array2[j] << std::endl;
				//final_arr.push_back((array1[i]*array2[j]));
				final_arr[index] = array1[i] * array2[j];
				index += 1;
			}
		}
		
	}
	return final_arr;	
}
