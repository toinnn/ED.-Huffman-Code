#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H
#include "HashMap.h"


class HuffmanTree:public HashMap
{   private:

    HashSimb *TabSimbol ;
    void TabSimb(Hash *aux,string cod);
    int altura(Hash *aux)
        {
            int a,b;
            if(aux->ant!=NULL)
            {
                a=altura(aux->ant)+1;
            }
            if(aux->prox!=NULL)
            {
                b=altura(aux->prox)+1;
            }
            if(aux->ant==NULL && aux->prox==NULL )
            {
                return 0;
            }

            if(a>b)
            {
                return a;
            }else
            {
                return b;
            }

        }


    public:
        HuffmanTree();
        void add(HashMap Lista);///Pega o Hash Ordenado e Monta a arvore De Huffman
        virtual ~HuffmanTree();
        HashSimb* TabSimb();///Extrai a tabela de Simbolos da Arvore e associa a Variável TabSimbol
        void addSimb(Hash *aux,string cod );///Adiciona um Hash e associa um codigo a ele
        int altura()
        {
            return altura(raiz);
        }

    protected:




};

#endif // HUFFMANTREE_H
