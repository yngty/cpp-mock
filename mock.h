#ifndef _MOCK_H_
#define _MOCK_H_

enum InstructLength: int {
    kJump = 5,
};

int mock(void *oldFunc, void *newFunc);

#endif