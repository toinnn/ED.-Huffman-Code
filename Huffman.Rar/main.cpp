#include <iostream>
#include <fstream>
#include "HashMap.h"
#include <string>
#include "Compressor.h"


using namespace std;



string Fatia(string linha,int i ,int j)
{
    string aux;//=linha.at(i);
    for(i;i<=j;i++)
    {
        aux+=linha.at(i);
    }
    return aux;
}

void abre (string path )
{
    ifstream arquivo;
    ofstream tt;
    arquivo.open(path.c_str(),ios_base::binary);
}

int main()
{
    ///OBS : N�O REMOVER O ARQUIVO SALVO DA FICHEIRA DO EXECUT�VEL , O PATH USADO E DO TIPO RELATIVO
    /*
    string dataN,StrAux,test1,tes2;
    HashMap HashInicial ;

    fstream dado("Marunae.data",ios_base::in|ios_base::out|ios_base::binary|ios_base::trunc);
    ifstream data("C:\\Users\\limaa\\OneDrive\\Imagens\\red-eyes-black-charizard-59b472f0d1afc-estampa-301-680x969.jpg",ios_base::binary);
    ofstream buffer("joge.jpg",ios_base::trunc|ios_base::binary);

    ///ios_base::in     => O dado sai do arquivo e entra no run do executavel...
    ///ios_base::out    -> O dado sai do executavel e entra no arquivo ...
    ///ios_base::binary -> O dado vai ser escrito de forma binaria no arquivo ...
    ///ios_base::trunc  -> Dados anteriores a execu��o atual ser�o apagados ..


    while(getline(data,dataN))
    {
        //buffer<<dataN<<endl;
        //cout<<dataN<<endl;
        //cout<<"A linha anterior tem "<<dataN.size()<<" caracteres "<<endl;
        //tes2+=dataN;



        for(int i=0 ;i<dataN.size();i++)
        {
            test1+=dataN.at(i);
            HashInicial.add(dataN.at(i));
        }
        /*int i;
        for(i=0;i+7<dataN.size();i=i+8 )/// acho que ta certo , n�o TOU mais ESTRANHANDO O PRINT DAS FATIAS...
            {

                StrAux=Fatia(dataN,i,i+7);
                test1+=Fatia(dataN,i,i+7);
                HashInicial.add(StrAux);

            }

        if(dataN.size()%8!=0)
        {
            test1+=Fatia(dataN,i,dataN.size()-1);
            StrAux=Fatia(dataN,i,dataN.size()-1);
            HashInicial.add(StrAux);

        }*//*

        buffer<<test1<<endl;
        cout<<test1<<endl;
        test1="";

    }
    cout<<"Ordenando...\n\n\n\n\n\n\n\n\n\n"<<endl;
    HashInicial.ordena();
    cout<<"As frequencias sao :"<<endl;
    HashInicial.apresFreq();
    cout<<HashInicial.size()<<endl;
    //cout<<sizeof()
    //HashInicial.escrever();
    //cout<<"Limpando..."<<endl;
    HashInicial.limpa();
    cout<<HashInicial.size()<<endl;

    ///vFECHAMENTO DE ARQUIVOS...v
    if(dado.is_open())
    {
        dado.close();
        cout<<"A Marunae abriu "<<endl;
    }
    if(data.is_open())
    {
        cout<<"A foto abriu "<<endl;
        data.close();
    }
    if(buffer.is_open())
    {
        buffer.close();
        cout<<"Buffer fechado "<<endl;
    }
    ///^FECHAMENTO DE ARQUIVOS...^
    cout << "Hello world!" << endl;



    /**/
    Compressor WinRar ;

    //WinRar.comprimir("C:\\Users\\limaa\\OneDrive\\Imagens\\red-eyes-black-charizard-59b472f0d1afc-estampa-301-680x969.jpg");
    string path,novoNome ;
    char r ;
    bool tk=1;

    while(tk)
    {
        cout<<"\nDigite :\n c-Para comprimir\n d-Para decompactar um arquivo.comprimido\n s-Para sair"<<endl;
        cin>>r;
        if(r=='c'||r=='C')
        {
            cout<<"\nDigite o path completo com o nome do arquivo que deseja comprimir "<<endl;
            cout<<"\nPor exemplo : C:\\Users\\limaa\\OneDrive\\Imagens\\red-eyes-black-charizard-59b472f0d1afc-estampa-301-680x969.jpg "<<endl;
            cin>>path;
            cout<<"\nDigite um nome para o arquivo compactado"<<endl;
            cin>>novoNome;
            WinRar.comprimir(path,novoNome);


        }else if (r=='s'||r=='S')
        {
            tk=0;
        }else if(r=='d'||r=='D')
        {
            cout<<"\nDigite o path completo com o nome do arquivo que deseja decompactar "<<endl;
            cout<<"\nPor exemplo : C:\\Users\\limaa\\OneDrive\\Imagens\\red-eyes-black-charizard-59b472f0d1afc-estampa-301-680x969.jpg "<<endl;
            cin>>path;
            cout<<"\nDigite o path completo com o nome do arquivo dicionario .dicionario  para iniciar a descompressao"<<endl;
            //WinRar.descomprimir(path);
        }
    }

    //WinRar.comprimir(0);

    cout<<"Chego aki"<<endl;


    return 0;
}
