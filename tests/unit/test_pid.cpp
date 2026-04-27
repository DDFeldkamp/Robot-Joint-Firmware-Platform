#include "pid.h"
#include <cassert>

int main() {
    PID pid(1.0f, 0.0f, 0.0f, -1.0f, 1.0f);
    assert(pid.update(1.0f, 0.0f, 0.001f) == 1.0f);
    return 0;
}
