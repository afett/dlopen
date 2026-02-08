#pragma once

#define SYM_CREATE_FOO create_foo

extern "C" {

struct Foo;

Foo *SYM_CREATE_FOO();

}
