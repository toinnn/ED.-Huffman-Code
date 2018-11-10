#include "HashMap.h"

HashMap::HashMap()
{
    //ctor
    raiz=(Hash*)malloc(sizeof(Hash));
    raiz->ant=NULL;
    raiz->prox=NULL;
    raiz->freq=0;
    tamanho=0;
}

HashMap::~HashMap()
{
    //dtor
}

recebeBool(Hash *aux,bool aux2[8])///GAMBIARRA PRO BOOL FUNCIONAR DIREITO
{
    for(int i=0;i<8;i++)
    {
        aux->Byte[i]=aux2[i];
    }
}


void HashMap::add(bool aux[8])
        {
            if(raiz->freq==0)///Caso a raiz esteja vazia
            {
                recebeBool(raiz,aux);///<--� A GAMBIARRA SENDO UZADA AKI<--
                raiz->freq=raiz->freq+1;
                tamanho++;
            }else{///Caso a raiz nao esteja vazia

            Hash *aux2=raiz,*novo;
            bool tk=1;

            while(tk)
            {
                if(aux2->Byte==aux)///Se j� existir o Byte analisado
                {
                    tk=0;
                    aux2->freq=aux2->freq+1;

                }else if(aux2->prox==NULL)///O Byte analisado n�o esta listado...Listando..
                {
                    tk=0;
                    novo=(Hash*)malloc(sizeof(Hash));
                    novo->ant=aux2;
                    novo->prox=NULL;
                    recebeBool(novo,aux);///<--� A GAMBIARRA SENDO UZADA AKI<--
                    novo->freq=1;
                    aux2->prox=novo;
                    tamanho++;
                }else///Modo Padr�o de busca na Lista
                {
                    aux2=aux2->prox;
                }

            }




            }
        }

void HashMap::limpa()
{

}

void HashMap::ordena()
{
    Hash *aux,*aux2,*novaRaiz=NULL;
    for(int i=0;i<tamanho;i++)
    {   aux=raiz;
        aux2=raiz;


        ///vComparando todos os itens EM BUSCA de quem tem a MAIOR FREQU�NCIA v...
        while(aux->prox!=NULL)
        {
            aux=aux->prox;
            if(aux2->freq<aux->freq)
            {
                aux2=aux;
            }

        }

        ///^Comparando todos os itens EM BUSCA de quem tem a MAIOR FREQU�NCIA ^...

        if(novaRaiz==NULL)
        {
            novaRaiz=aux2;
            aux=NULL;//S� pra funcionar com o aux2 l� de baixo
        }else{
        aux=novaRaiz;///RE-UTILIZANDO O AUX PARA buscas

        while(aux->prox!=NULL)
        {
            aux=aux->prox;
        }
        aux->prox=aux2;

        }


        ///Re-Organiza a lista Original
        if(aux2->prox!=NULL)
        {
            aux2->prox->ant=aux2->ant;
        }
        if(aux2->ant!=NULL)
        {
            aux2->ant->prox=aux2->prox;
        }else{
            raiz=raiz->prox;
        }
        aux2->ant=aux;
        aux2->prox=NULL;

    }
    raiz=novaRaiz;
}

