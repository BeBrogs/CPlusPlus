#include <iostream>
#include <memory>


//DEMONSTRATION OF SHARED POINTERS
//Shared pointers point to the same object on the heap, meaning they are not unique.
//Multiple shared pointers can point to the same object on the heap
//Shared pointers can be copied, assigned and moved
//Shared pointers have a use count, meaning that we delete each use count once we run out of scope

int main(){
	//Beginners establishment and initialization of a shared_ptr object
	//std::shared_ptr<type> name {new type{data}};
	
	//EG 1:
	std::shared_ptr<int> p1 {new int {13}};


	std::cout << "p1 holds: ";	
	//Dereference to find what is stored in heap address
	std::cout << *p1 << std::endl;


	std::cout << "Use count of p1: ";
	//The use_count() method is able to show us the use count of heap object assigned to shared pointers
	std::cout << p1.use_count() << std::endl;


	//Establishing and Initializing p2, a pointer that is assigned the same heap object as p1
	std::shared_ptr<int> p2 {p1};

	//finding use count of p1
	std::cout << "Use count of p1: " << p1.use_count() << std::endl;

	//Finding use count of p2:
	std::cout << "Use count of p2: " << p2.use_count() << std::endl;


	//Nullifying p1
	p1.reset();

	std::cout << "P1 use count after nullification: " << p1.use_count() << std::endl;
	std::cout << "P2 use count after p1's nullification: " << p2.use_count() << std::endl;



	return 0;
}//All shared pointers are deleted once we run out of scope/dont use the pointers anymore
