#include <malloc.h>
#include <iostream>

using namespace std ;

struct Hash
{
    char Byte;//Fake Byte que não necessariamente tem 8 bits ;
    int freq;
    Hash *prox,*ant;
};
 /*int toBin(int i)
 {

 }*/
struct HashSimb
{
    char Byte ;
    string cod;
    HashSimb *prox,*ant;
};




/*struct Byte
{
    unsigned int bit :8;
};
*/


