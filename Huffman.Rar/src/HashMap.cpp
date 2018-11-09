#include "HashMap.h"

HashMap::HashMap()
{
    //ctor
    raiz=(Hash*)malloc(sizeof(Hash));
    raiz->ant=NULL;
    raiz->prox=NULL;
    raiz->freq=0;
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
                recebeBool(raiz,aux);///<--Ó A GAMBIARRA SENDO UZADA AKI<--
                raiz->freq=raiz->freq+1;
            }else{///Caso a raiz nao esteja vazia

            Hash *aux2=raiz,*novo;
            bool tk=1;

            while(tk)
            {
                if(aux2->Byte==aux)///Se já existir o Byte analisado
                {
                    tk=0;
                    aux2->freq=aux2->freq+1;
                }else if(aux2->prox==NULL)///O Byte analisado não esta listado...Listando..
                {
                    tk=0;
                    novo=(Hash*)malloc(sizeof(Hash));
                    novo->ant=aux2;
                    novo->prox=NULL;
                    recebeBool(novo,aux);///<--Ó A GAMBIARRA SENDO UZADA AKI<--
                    novo->freq=0;
                    aux2->prox=novo;
                }else///Modo Padrão de busca na Lista
                {
                    aux2=aux2->prox;
                }

            }




            }
        }
