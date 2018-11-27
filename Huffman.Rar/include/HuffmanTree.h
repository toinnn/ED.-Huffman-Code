#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H
#include "HashMap.h"


class HuffmanTree:public HashMap
{   private:

    HashSimb *TabSimbol ;

    public:
        HuffmanTree();
        void add(HashMap Lista);
        virtual ~HuffmanTree();
        HashSimb* TabSimb();
        void TabSimb(Hash *aux,string cod);
        void addSimb(Hash *aux,string cod );

    protected:




};

#endif // HUFFMANTREE_H
