#include "HuffmanTree.h"

HuffmanTree::HuffmanTree()
{
    //ctor
    TabSimbol=NULL;
    raiz=NULL;
}

HuffmanTree::~HuffmanTree()
{
    //dtor
}

void HuffmanTree::add(HashMap Lista)///Pega a Hash e transforma da Arvore de Huffman
{
    Hash *novo,pos,*auxLimp=Lista.getRaiz();
    HashMap aux;

    aux.addAux(Lista);
    while(auxLimp->prox!=NULL)
    {
        auxLimp=auxLimp->prox;
        auxLimp->ant->prox=NULL;
        auxLimp->ant=NULL;
    }


    for(int i=0;i<Lista.size()-1;i++)
    {
        novo=(Hash*)malloc(sizeof(Hash));
        novo->ant=aux.getRaiz()->ant;
        novo->prox=aux.getRaiz()->prox->ant;
        //novo->ant=Lista.getRaiz();
        //novo->prox=Lista.getRaiz()->prox;
        novo->freq=novo->ant->freq + novo->prox->freq;
        ///Montado o "AB" atual ^
        pos=aux.auxAct(novo);
        /*pos->ant->ant->prox=novo;
        pos->prox->ant->ant=novo;
        */








        //pos->prox->ant->ant->prox=novo;
        //pos->prox->ant->ant=novo;
        /*if((Lista.size()-i)>2)
        {
            raiz=raiz->prox->prox;  ///ISSO TA CLARAMENTE ERRADO /Ja na tao claramente !!!!!!!!!
        }*/

    }
        Lista.setRaiz(novo);
        raiz=novo;
        cout<<"Arvore Montada "<<endl;

}


void HuffmanTree:: TabSimb(Hash *aux,string cod)///Montando a Tabela de Simbolo
{
    if(aux->ant!=NULL)
    {
        TabSimb(aux->ant,cod+"0");
    }
    if(aux->prox!=NULL)
    {
        TabSimb(aux->prox,cod+"1");
    }
    if(aux->ant==NULL && aux->prox==NULL)
    {
        addSimb(aux,cod);
    }


}


void HuffmanTree:: addSimb(Hash *aux,string cod)
{
    if(TabSimbol!=NULL)
    {
        HashSimb *ask=TabSimbol;

        while(ask->prox!=NULL)
        {
            ask=ask->prox;
        }
        ask->prox=(HashSimb*)malloc(sizeof(HashSimb));
        ask->prox->ant=ask;
        ask=ask->prox;
        ask->prox=NULL;
        ask->Byte=aux->Byte;
        ask->cod=cod;
    }else
    {
        TabSimbol=(HashSimb *)malloc(sizeof(HashSimb));
        TabSimbol->ant=NULL;
        TabSimbol->prox=NULL;
        TabSimbol->Byte=aux->Byte;
        TabSimbol->cod=cod;
    }


}

HashSimb* HuffmanTree:: TabSimb()
{
    if(raiz!=NULL)
    {
        TabSimb(raiz,"");
        cout<<"Tabela de simbolos montada"<<endl;
    }

    return TabSimbol;
}

