#include <malloc.h>
#include <iostream>

using namespace std ;

struct Hash
{
    string Byte;///Fake Byte que n�o necessariamente tem 8 bits ;
    int freq;
    Hash *prox,*ant;
};
