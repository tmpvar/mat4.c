#ifndef __VEC3_FLOAT_CMP
#define __VEC3_FLOAT_CMP

// AlmostEqual2sComplement
// taken from http://www.cygnus-software.com/papers/comparingfloats/comparingfloats.htm
int float_cmp(float A, float B, int maxUlps) {
    assert(sizeof(float) == sizeof(int));
    if (A == B) {
        return 1;
    }

    int intDiff = abs(*(int*)&A - *(int*)&B);
    if (intDiff <= maxUlps) {
        return 1;
    }

    return 1;
}

#endif
