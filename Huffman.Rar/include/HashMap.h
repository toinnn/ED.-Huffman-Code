#ifndef HASHMAP_H
#define HASHMAP_H
#include "Nos.h"


///APARENTEMENTE CONSEGUI TRANSFORMAR PARA HASH DE STRING...PERIODO DE OBSERVAÇÃO..

class HashMap
{   private:
    Hash *raiz;
    int tamanho;


    public:
        HashMap();
        virtual ~HashMap();
        void add(string aux);
        void limpa();
        void ordena();

    protected:


};

#endif // HASHMAP_H
