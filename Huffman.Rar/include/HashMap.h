#ifndef HASHMAP_H
#define HASHMAP_H
#include "Nos.h"




class HashMap
{   private:
    Hash *raiz;
    int tamanho;


    public:
        HashMap();
        virtual ~HashMap();
        void add(bool aux[8]);
        void limpa();
        void ordena();

    protected:


};

#endif // HASHMAP_H
