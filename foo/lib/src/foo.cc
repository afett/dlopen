#include <foo.h>
#include <foo-dl.h>

class FooImpl : public Foo {
public:
	explicit FooImpl() = default;

	Version get_version() const override;
};

Foo::Version FooImpl::get_version() const
{
	return Version{3, 5};
}

Foo *SYM_CREATE_FOO()
{
	return new FooImpl();
}
