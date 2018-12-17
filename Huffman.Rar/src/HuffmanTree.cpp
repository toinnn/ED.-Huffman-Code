#include "HuffmanTree.h"

HuffmanTree::HuffmanTree()
{
    //ctor
    TabSimbol=NULL;
    setRaiz(NULL);
}

HuffmanTree::~HuffmanTree()
{
    //dtor
}

void HuffmanTree::addT(HashMap Lista)///Pega a Hash e transforma da Arvore de Huffman
{
    Hash *novo,*auxLimp=Lista.getRaiz();
    HashMap aux;

    aux.addAux(Lista);

    while(auxLimp->prox!=NULL)
    {
        auxLimp=auxLimp->prox;
        auxLimp->ant->prox=NULL;
        auxLimp->ant=NULL;
        //cout<<auxLimp->Byte<<"Quebrado"<<endl;
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
        aux.auxAct(novo);
//        pos->ant->ant->prox=novo;
//        pos->prox->ant->ant=novo;


        //pos->prox->ant->ant->prox=novo;
        //pos->prox->ant->ant=novo;
        /*if((Lista.size()-i)>2)
        {
            raiz=raiz->prox->prox;  ///ISSO TA CLARAMENTE ERRADO /Ja na tao claramente/claramente !!!!!!!!!
        }*/
        //cout<<"Esquerda :"<<novo->ant->Byte<<"Direita : "<<novo->prox->Byte<<endl;

    }
        //Lista.setRaiz(novo);
        //raiz=novo;
        setRaiz(novo);
        cout<<"Arvore Montada "<<endl;

}


HashSimb* HuffmanTree:: TabSimb()
{
    if(getRaiz()!=NULL)
    {
        TabSimb(getRaiz() ,"");
        cout<<"Tabela de simbolos montada"<<endl;
    }

    return TabSimbol;
}

void HuffmanTree:: TabSimb(Hash *aux,string cod)///Montando a Tabela de Simbolo
{
    cout<<"Entro no Tab Simb "<<endl;
    if(aux->ant!=NULL)
    {
        cout<<"Tento entrar na esquerda "<<endl;
        TabSimb(aux->ant,cod+"0");
    }
    if(aux->prox!=NULL)
    {
        cout<<"Tento entrar na direita"<<endl;
        TabSimb(aux->prox,cod+"1");
    }
    if(aux->ant==NULL && aux->prox==NULL)
    {
        //cout<<"Crasho aki "<<endl;
        addSimb(aux,cod);
        cout<<"Simbolo adicionado com sucesso "<<endl;
    }


}


void HuffmanTree:: addSimb(Hash *aux,string cod)
{
    cout<<"Entro no addSimb "<<endl;
    if(TabSimbol!=NULL)
    {
        HashSimb *ask=TabSimbol,*novo;

        while(ask->prox!=NULL)
        {
            ask=ask->prox;
            cout<<"Andou +1 na lista"<<endl;
        }
        cout<<"O prox do item da lista e nulo "<<endl;
        novo=(HashSimb*)malloc(sizeof(HashSimb));
        cout<<"Chego aki no addSimb"<<endl;
        //novo->Byte=aux->Byte;
        novo->ant=ask   ;


        //novo->Byte=aux->Byte;
        //novo->cod=cod;
        //ask->prox=novo;
        //novo->prox=NULL;
        /*ask->prox->ant=ask;
        ask=ask->prox;

        ask->prox=NULL;

        ask->Byte=aux->Byte;

        ask->cod=cod;
        */
        cout<<"Simbolo listado com sucesso "<<endl;

    }else
    {
        TabSimbol=(HashSimb *)malloc(sizeof(HashSimb));
        TabSimbol->ant=NULL ;
        TabSimbol->prox=NULL;
        TabSimbol->Byte=aux->Byte;
        TabSimbol->cod=cod;
        cout<<"Salvo o primeiro valor no TabSimbol "<<endl;
    }


}


