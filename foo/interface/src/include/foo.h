#pragma once

#include <memory>

class Foo {
public:
	static std::shared_ptr<Foo> create();

	struct Version {
		int major = 0;
		int minor = 0;
	};

	virtual Version get_version() const = 0;

	virtual ~Foo();
};
