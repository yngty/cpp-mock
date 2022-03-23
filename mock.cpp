#include "mock.h"
#include <iostream>

#include <unistd.h>
#include <sys/mman.h>

#include <cstring>

using namespace std;


unsigned char instruct[InstructLength::kJump];

size_t kPAGESIZE = getpagesize();

char *pageof(char* addr)
{ 
    return (char *)((unsigned long)addr & ~(kPAGESIZE - 1));  
}

int mock(void *oldFunc, void *newFunc) {
    
    cout << "mock........" << endl;
    *(unsigned char*)instruct = 0xE9;

    int offset = ((char *)newFunc - ((char *)oldFunc + InstructLength::kJump));

    *(int *)(instruct + 1) = offset;

    if (0 == mprotect(pageof((char*)oldFunc), kPAGESIZE *2, PROT_READ | PROT_WRITE | PROT_EXEC)) {
          cout << "mprotect........" << endl;
        std::memcpy(oldFunc, instruct, InstructLength::kJump);      
    }

    return 0;
}