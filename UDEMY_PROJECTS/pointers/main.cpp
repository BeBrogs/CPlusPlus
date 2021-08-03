#include <iostream>


void print_elements(int *array, int arr_size);
int *multiplied_array(int *array1, int arr1_size, int *array2, int arr2_size);


int main(){
	int array1[] {1,2,3,4,5};
	int ar1_size {sizeof(array1)/sizeof(array1[0])};

	int array2[] {10, 20, 30};
	int ar2_size {sizeof(array2)/sizeof(array2[0])};

	std::cout << "ARRAY1: ";
	print_elements(array1, ar1_size);
	std::cout << "ARRAY2: ";
	print_elements(array2, ar2_size);

	
	int *empty_arr = multiplied_array(array1, ar1_size, array2, ar2_size);
	print_elements(empty_arr, (ar1_size * ar2_size));

	return 0;
}

void print_elements(int *array, int arr_size){
	std::cout << "[";	

	for(int i {0}; i < arr_size; ++i){
		if (i != arr_size-1){
			std::cout << array[i] << ", ";
			
		}
		else{
			std::cout << array[i];
		}
	}
		
	std::cout << "]\n" << std::endl;
} 

int *multiplied_array(int *array1, int arr1_size, int *array2, int arr2_size){
	int multiplied_size {arr1_size * arr2_size};
	int *returned = new int[multiplied_size]{};

	int returned_index {0}; 
	for (int ar1 {0}; ar1 < arr1_size; ++ar1){
		for (int ar2 {0}; ar2<arr2_size; ++ar2){
			returned[returned_index] = array1[ar1] * array2[ar2];
			++returned_index;
		}
	}




	
	return returned;
}
