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
        HashMap(int i);
        virtual ~HashMap();
        void add(char aux);
        void limpa();
        void ordena();
        void apresFreq();
        int  size()
        {
            return tamanho;
        }
        void escrever();
        Hash* getRaiz()
        {
            return raiz;
        }
        void addAux(HashMap Lista);
        void auxAct();



    protected:



};

#endif // HASHMAP_H
