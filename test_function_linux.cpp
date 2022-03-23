#include <iostream>
#include <cstdio>

#include "mock.h"

using namespace std;
int foo(int a) {
    printf("I am foo\n");
    return 0;
}

int foo_mock(int a) {
    cout<<"I am foo_mock " << a <<endl;
    return 0;
}
int main(int argc, char const *argv[])
{
    mock((void*)foo, (void*)foo_mock);

    foo(1);

    return 0;
}
