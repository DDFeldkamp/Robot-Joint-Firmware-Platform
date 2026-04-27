#include "low_pass.h"
#include <cassert>

int main() {
    LowPassFilter f(0.5f);
    assert(f.update(10.0f) == 10.0f);
    const float y = f.update(0.0f);
    assert(y > 0.0f && y < 10.0f);
    return 0;
}
