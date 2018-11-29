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

HashMap::HashMap(int i)
{
    cout<<"Nao fasso nada "<<endl;
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
void HashMap::limpa(Hash *aux)
{
    if(aux->ant!=NULL)
    {
        limpa(aux->ant);
    }
    if(aux->prox!=NULL)
    {
        limpa(aux->prox);
    }
    if(aux->ant==NULL && aux->prox==NULL)
    {
        free(aux);
    }

}
void HashMap::limpa()///Vai ter que ser auterado com a lógica de if(aux->prox->ant==aux)...Ja foi alterado
{
    Hash *aux=raiz;
    if(aux!=NULL)
    {
        if(aux->prox==NULL)
        {
            free(raiz);
        }else
        {
            if(aux->prox->ant!=aux)
            {
                limpa(raiz);
            }

            while(aux->prox!=NULL)
            {
                aux=aux->prox;
                free(aux->ant);
                tamanho--;
            }
            free(aux);
            tamanho--;
            raiz=NULL;
        }


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

void HashMap::addAux(HashMap Lista)///AUX PARA CONSTRUÇÃO DE UMA ARVORE BINARIA,Adicionar Lista ja ordenada
{   ///Ps: Não está otimizado para receber possíveis entradas nulas
    limpa();
    int nHash=sizeof(Hash);
    raiz=(Hash*)malloc(nHash);
    raiz->ant=Lista.getRaiz();
    raiz->freq=raiz->ant->freq;

    Hash *novo,*aux=raiz,*auxL=Lista.getRaiz();

    for(int i=0;i<Lista.size()-1;i++)
    {
        aux->prox=(Hash*)malloc(nHash);
        aux->prox->ant=auxL->prox;
        aux->prox->freq=auxL->prox->freq;
        aux=aux->prox;
        auxL=auxL->prox;
    }
    aux->prox=NULL;

}

Hash HashMap::auxAct(Hash *novo)///AINDA EM CONSTRUÇÃO...
{
    Hash *B=raiz->prox,*aux=raiz,retorno;
    bool tk=1;
    raiz->freq+=raiz->prox->freq;

    while(tk)///Reorganizando para a nova frequência..
    {
        if(aux->prox==NULL)
        {
            tk=0;
        }else if(raiz->freq>aux->prox->freq)
        {
            aux=aux->prox;
        }else
        {
            tk=0;
        }
    }



    raiz->prox=aux->prox;
    aux->prox=raiz;
    raiz->ant=novo;
    retorno.ant=aux;
    retorno.prox=aux->prox->prox;

    raiz=B->prox;
    ///free(B); NAO SEI AINDA OQ FAZER..

    return retorno;
}


