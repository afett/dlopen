#include <iostream>

#include <foo.h>

int main()
{
	auto f = Foo::create();
	auto v = f->get_version();

	std::cout << "Version is: " << v.major << "." << v.minor << "\n";
	return 0;
}
