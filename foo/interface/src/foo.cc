#include <dlfcn.h>

#include <foo.h>
#include <foo-dl.h>

#define xstr(a) str(a)
#define str(a) #a

std::shared_ptr<Foo> Foo::create()
{
	auto handle = ::dlopen(xstr(FOO_LIB), RTLD_NOW);
	// todo error handling

	auto fn = reinterpret_cast<decltype(&SYM_CREATE_FOO)>(::dlsym(handle, xstr(SYM_CREATE_FOO)));
	// todo error handling

	return std::shared_ptr<Foo>{fn()};
}

Foo::~Foo() = default;
