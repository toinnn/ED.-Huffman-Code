#ifndef HASHMAP_H
#define HASHMAP_H
#include "Nos.h"


///APARENTEMENTE CONSEGUI TRANSFORMAR PARA HASH DE STRING...PERIODO DE OBSERVAÇÃO..

class HashMap
{   private:
    void limpa(Hash *aux);

    protected:
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
        ///Métodos de uso da Huffman Tree :
        void addAux(HashMap Lista);
        Hash auxAct(Hash *raiz);
        void setRaiz(Hash *novo)
        {
            raiz=novo;
        }






};

#endif // HASHMAP_H
