#include <memory>
#include <iostream>



int main(){
	std::shared_ptr<int> s1 = std::make_shared<int>(123);
	std::cout << "S1 Use Count: " << s1.use_count() << std::endl;

	std::weak_ptr<int> w1;
	w1 = s1;
	std::cout << "S1 Use Count after weak ptr assigned to s1" << std::endl;

		


	return 0;
}
