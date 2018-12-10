#ifndef HASHMAP_H
#define HASHMAP_H
#include "Nos.h"


///APARENTEMENTE CONSEGUI TRANSFORMAR PARA HASH DE STRING...PERIODO DE OBSERVA��O..

class HashMap
{   private:
    void limpa(Hash *aux);
    Hash *raiz;
    int tamanho;

    protected:



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
        ///M�todos de uso da Huffman Tree :
        void addAux(HashMap Lista);
        void auxAct(Hash *novo);
        void setRaiz(Hash *novo)
        {
            raiz=novo;
        }






};

#endif // HASHMAP_H
