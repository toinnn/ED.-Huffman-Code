#include <malloc.h>

struct Hash
{
    bool Byte[8];
    int freq;
    Hash *prox,*ant;
};
