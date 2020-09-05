#include <iostream>

using namespace std;


class Base
{
public:
	static Base& getInstance()
	{
		static Base instance;
		return instance;
	}
protected:
	Base() { }
	Base(const Base&);
	Base& operator=(const Base&);
};


int main() {

	Base& b1 = Base::getInstance();
	Base& b2 = Base::getInstance();
	// prints 1
	std::cout << (&b1 == &b2);

	system("pause");
	return 0;
}