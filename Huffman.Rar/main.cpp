#include <iostream>
#include <fstream>
#include "HashMap.h"
#include <string>

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

int main()
{
    ///OBS : NÃO REMOVER O ARQUIVO SALVO DA FICHEIRA DO EXECUTÁVEL , O PATH USADO E DO TIPO RELATIVO
    string dataN,StrAux,test1,tes2;
    HashMap HashInicial ;

    fstream dado("Marunae.data",ios_base::in|ios_base::out|ios_base::binary|ios_base::trunc);
    ifstream data("C:\\Users\\limaa\\OneDrive\\Imagens\\red-eyes-black-charizard-59b472f0d1afc-estampa-301-680x969.jpg",ios_base::binary);
    ofstream buffer("joge.jpg",ios_base::trunc|ios_base::binary);

    ///ios_base::in     => O dado sai do arquivo e entra no run do executavel...
    ///ios_base::out    -> O dado sai do executavel e entra no arquivo ...
    ///ios_base::binary -> O dado vai ser escrito de forma binaria no arquivo ...
    ///ios_base::trunc  -> Dados anteriores a execução atual serão apagados ..



    while(getline(data,dataN))
    {
        //buffer<<dataN<<endl;
        //cout<<dataN<<endl;
        //cout<<"A linha anterior tem "<<dataN.size()<<" caracteres "<<endl;
        //tes2+=dataN;

        int i;
        for(i=0;i+7<dataN.size();i=i+8 )/// acho que ta certo , não TOU mais ESTRANHANDO O PRINT DAS FATIAS...
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

        }

        buffer<<test1<<endl;
        cout<<test1<<endl;
        test1="";

    }
    cout<<"Ordenando..."<<endl;
    HashInicial.ordena();
    cout<<"Limpando..."<<endl;
    HashInicial.limpa();


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





    return 0;
}
