#include <iostream>
#include <string>
#include <memory>

class A;
class B;

int main(){
	std::shared_ptr<A> sa = std::make_shared<A>();
	std::shared_ptr<B> sb = std::make_shared<B>();
	
	sa->set_B(sb);
	return 0;
}


class A{
	std::shared_ptr<B> b_ptr;
public:
	//Constructor
	A(){std::cout << "[A] Constructor" << std::endl;}
	//Destructor
	~A(){std::cout << "[A] Destructor" << std::endl;}

	void set_B(std::shared_ptr<B> &b){
		b_ptr=b;
	}	

};


class B{
	std::weak_ptr<A> a_ptr;
public:
	//Constructor:
	B(){std::cout << "[B] Constructor" << std::endl;}
	//Destructor
	~B(){std::cout << "[B] Destructor" << std::endl;}

	//Setter
	void set_A(std::shared_ptr<A> &a){
		a_ptr = a;
	}

};
