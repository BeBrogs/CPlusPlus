#include <iostream>
#include <memory> //PKG/LIB for Smart Pointers



class Test{
int data;

public:

	//No Arg Constructor - Delegating Constructor
	Test(): data{0}{
		std::cout << "\tTest Constructor (" << data << ")" << std::endl;
	}

	//One Arg Constructor  - Delegating Constructor
	Test(int data_val): data{data_val}{
		std::cout << "\tTest Constructor (" << data << ")" << std::endl;
	}

	//Getter
	int get_data(){return data;}


	//Destructor:
	~Test(){std::cout << "\tTest Destructor" << std::endl;}

};

//Custom Deleter Function:
void my_deleter(Test *raw_pointer){
	std::cout << "\tInside my_deleter" << std::endl;
	delete raw_pointer;
}



int main(){
	std::shared_ptr<Test> p1 = std::make_shared<Test>(1234);
	std::cout << "p1 constructed w/o triggering my_deleter\n" << std::endl;

	
	std::shared_ptr<Test>p2 {new Test{567}, my_deleter};
	std::cout << "p2 constructed w/ triggering my_deleter\n" << std::endl; 

	return 0;
}
