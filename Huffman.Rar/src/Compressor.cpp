#include "Compressor.h"

Compressor::Compressor()
{
    //ctor
}

Compressor::~Compressor()
{
    //dtor
}

string CharToCod(char nome,HashSimb *Dicionario)
{
    HashSimb *aux=Dicionario;
    while(aux->Byte!=nome)
    {
        aux=aux->prox;
    }
    return aux->cod;
}

string Compressor::Fatia(string linha,int i ,int j)
{
    string aux="";//=linha.at(i);
    for(i;i<=j;i++)
    {
        aux+=linha.at(i);
    }
    cout<<"Corto a fatia com sucesso"<<endl;
    return aux;
}


void Compressor::comprimir(string path)
{
    ///Classes mais b�sicas :
    string novoNome="Onibus.Comprimido";///Do arquivo ;
    string data,codAux,buffer,nvLinha ;///Dados de cada linha dos binares
    int j,OverFlou,oucupado;
    ///Classes mais complexas :
    //bitset<16> Byte ;///O sentido Crescente do bitset � o inverso do da string,Isso possui 16 bits por conta do C++ trabalhar
    HashMap HashFreq ;
    HuffmanTree Groot ;
    HashSimb *Dicionario ;
    ifstream Original(path.c_str(),ios_base::binary);///Abre o arquivo que se pretende Comprimir
    ofstream NovoArquivo(novoNome.c_str() ,ios_base::binary|ios_base::trunc);///Cria o arquivo Resultado da Compress�o



    while(getline(Original,data) )///Monta o Hash de Frequencias
    {
        for(int i=0;i<data.size();i++)
        {
            HashFreq.add(data.at(i));
        }
    }
    HashFreq.ordena();///O adicionar esta com defeito
    Groot.add(HashFreq);///Monta a arvore a partir do Hash Organizado
    Dicionario=Groot.TabSimb();///Extrai uma tabela de simbolos
    cout<<"Passo do dicionario"<<endl;
    while(getline(Original,data))///RE-escreve os binarios Diacordo com a Tabela de Simbolos
    {   nvLinha="";
        for(int i=0;i<data.size();i++)
        {
            //codAux=CharToCod(data.at(i),Dicionario);
            //j=codAux.size();
            //OverFlou=8-j;
            buffer+=CharToCod(data.at(i),Dicionario);///Auto-explicativo
            //codAux;
            if(buffer.size()>7)
            {
                //Byte._M_copy_from_string(Fatia(buffer,0,7))
                //Byte = Fatia(buffer,0,7);
                bitset<16> Byte(Fatia(buffer,0,7)) ;
                buffer.erase(0,8);
                //nvLinha+=Byte.to_ulong()
                nvLinha.push_back(Byte.to_ulong());
                delete &Byte ;
            }
        }
        NovoArquivo<<nvLinha<<endl;
    }
}



