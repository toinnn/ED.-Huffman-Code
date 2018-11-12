#include "HuffmanTree.h"

HuffmanTree::HuffmanTree()
{
    //ctor

}

HuffmanTree::~HuffmanTree()
{
    //dtor
}

void HuffmanTree::add(HashMap Lista)
{
    Hash *novo;
    HashMap aux;

    for(int i=0;i<Lista.size()-1;i++)
    {
        novo=(Hash*)malloc(sizeof(Hash));
        novo->ant=Lista.getRaiz();
        novo->prox=Lista.getRaiz()->prox;
        novo->freq=novo->ant->freq + novo->prox->freq;



    }



}


