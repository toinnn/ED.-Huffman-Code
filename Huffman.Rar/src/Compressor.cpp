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

int Compressor::comprimir(int k)
{
    string Linha ;

    HashMap ListFreq ;
    HuffmanTree Arvore ;
    HashSimb *ListaSimbolos ;

    ifstream abertura("red-eyes-black-charizard-59b472f0d1afc-estampa-301-680x969.jpg",ios_base::binary);
    ofstream Memoria("Salvado.Salvo",ios_base::binary);

    while(getline(abertura,Linha))
    {
        for(int i =0;i<Linha.size();i++)
        {
            ListFreq.add(Linha.at(i));
            cout<<"Adicionado o char "<<Linha.at(i)<<endl;
        }
    }

    ListFreq.ordena();
    //Arvore.add(ListFreq);


    return 0;
}

void Compressor::comprimir(string path)
{
    ///Classes mais básicas :
    string novoNome="Onibus",novoNomeDici=novoNome+".dicionario";///Do arquivo ;
    string data,codAux,buffer,nvLinha ;///Dados de cada linha dos binares
    //int j,OverFlou,oucupado;
    ///Classes mais complexas :
    //bitset<16> Byte ;///O sentido Crescente do bitset é o inverso do da string,Isso possui 16 bits por conta do C++ trabalhar
    HashMap HashFreq ;
    HuffmanTree Groot ;
    HashSimb *Dicionario ;
    novoNome+=".comprimido";
    ifstream Original(path.c_str(),ios_base::binary);///Abre o arquivo que se pretende Comprimir
    ofstream NovoArquivo(novoNome.c_str() ,ios_base::binary|ios_base::trunc);///Cria o arquivo Resultado da Compressão
    ofstream NovoArquivoDicio(novoNomeDici.c_str() ,ios_base::binary|ios_base::trunc);


    while(getline(Original,data) )///Monta o Hash de Frequencias
    {
        for(int i=0;i<data.size();i++)
        {
            HashFreq.add(data.at(i));
        }
    }
    HashFreq.ordena();///O adicionar esta com defeito
    cout<<"Pre add"<<endl;
    Groot.addT(HashFreq);///Monta a arvore a partir do Hash Organizado
    cout<<"A altura e de "<<Groot.altura();
    cout<<"Pre dicionario "<<endl;

    Dicionario=Groot.TabSimb();///Extrai uma tabela de simbolos
    cout<<"Passo do dicionario"<<endl;

    ///jeito preguiçoso :
    Original.close();
    Original.open(path.c_str(),ios_base::binary);

    while(getline(Original,data))///RE-escreve os binarios Diacordo com a Tabela de Simbolos
    {   cout<<"Entro no while "<<endl;
        nvLinha="";
        for(int i=0;i<data.size();i++)
        {
            cout<<"Passo do for"<<endl;
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
        cout<<"Chegou no chegador "<<endl;
        bitset<16> Byte(buffer);
        nvLinha.push_back(Byte.to_ulong());
        NovoArquivo<<nvLinha<<endl;
        cout<<"Passou do passador"<<endl;
        delete &Byte ;
    }

}



