#include <iostream>
#include <memory>
#include <vector>

int main(){
	//ESTABLISHING AND INITIALIZATION OF SHARED POINTER
	//W/O USING auto keyword 
	std::shared_ptr<int> p1 = std::make_shared<int>(123);
	
	std::cout << "P1 holds: " << *p1 << std::endl;
	std::cout << "P1 use count: " << p1.use_count() << std::endl;

	//W/ USING AUTO KEYWORD	
	auto p2 = std::make_unique<int>(1234);
	
	std::cout << "\nP2 holds: " << *p2 << std::endl;

	//Making shared pointers to same obj on heap
	std::shared_ptr<int> p3 {p1};
	auto p4 {p1};

	std::cout << "\nP1 use count: " << p1.use_count() << std::endl;

	//Creating vector of shared pointers to ints
	std::vector<std::shared_ptr<int>> vec;
	vec.push_back(p1);
	vec.push_back(p3);


	std::cout << std::endl;
	for (auto& i: vec)
		std::cout << *i << std::endl;



	return 0;

}
