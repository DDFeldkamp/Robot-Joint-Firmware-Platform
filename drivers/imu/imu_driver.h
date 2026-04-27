#pragma once
struct ImuSample { float ax; float ay; float az; float gx; float gy; float gz; };
class ImuDriver { public: void init(); ImuSample read(); };
