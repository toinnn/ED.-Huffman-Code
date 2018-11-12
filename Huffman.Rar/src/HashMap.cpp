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
    limpa();
}
/*
recebeBool(Hash *aux,bool aux2[8])///GAMBIARRA PRO BOOL FUNCIONAR DIREITO
{
    for(int i=0;i<8;i++)
    {
        aux->Byte[i]=aux2[i];
    }
}
*/

void HashMap::add(char aux)
        {


            if(raiz->freq==0)///Caso a raiz esteja vazia
            {
                raiz->Byte=aux;   ///recebeBool(raiz,aux);///<--Ó A GAMBIARRA SENDO UZADA AKI<--
                raiz->freq=1;
                tamanho++;
            }else{///Caso a raiz nao esteja vazia

            Hash *aux2=raiz,*novo;
            bool tk=1;
            //cout<<"Ta entrando aki "<<endl;
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
                    novo->Byte=aux;   ///recebeBool(novo,aux);///<--Ó A GAMBIARRA SENDO UZADA AKI<--
                    novo->freq=1;
                    aux2->prox=novo;
                    tamanho++;
                }else///Modo Padrão de busca na Lista
                {
                    aux2=aux2->prox;
                }

            }




            }
        }

void HashMap::limpa()
{
    Hash *aux=raiz;
    if(aux!=NULL)
    {
        while(aux->prox!=NULL)
        {
            aux=aux->prox;
            free(aux->ant);
            tamanho--;
        }
        free(aux);
        tamanho--;

    }

}

void HashMap::ordena()
{
    Hash *aux,*aux2,*novaRaiz=NULL;
    for(int i=0;i<tamanho;i++)
    {   aux=raiz;
        aux2=raiz;


        ///vComparando todos os itens EM BUSCA de quem tem a MAIOR FREQUÊNCIA v...
        while(aux->prox!=NULL)
        {
            aux=aux->prox;
            if(aux2->freq>aux->freq)
            {
                aux2=aux;
            }

        }

        ///^Comparando todos os itens EM BUSCA de quem tem a MAIOR FREQUÊNCIA ^...

        if(novaRaiz==NULL)
        {
            novaRaiz=aux2;
            aux=NULL;//Só pra funcionar com o aux2 lá de baixo
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

void HashMap::apresFreq()
{
    Hash *aux=raiz;
    int i=0,j=0;
    while(aux->prox!=NULL)
    {
        j=aux->Byte - '0';
        cout<<aux->freq<<" do charactere :"<<j <<endl;
        i+=aux->freq;
        aux=aux->prox;
    }
    j=aux->Byte - '0';
    i+=aux->freq;
    cout<<aux->freq<<" do charactere :"<<j <<endl;
    cout<<"O total de itens e de "<<i<<endl;

}

void HashMap::escrever()
{
    Hash *aux=raiz;

    while(aux->prox!=NULL)
    {
        cout<<aux->Byte;
        aux=aux->prox;
    }
    cout<<aux->Byte;
}

