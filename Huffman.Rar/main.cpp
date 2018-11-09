#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ///OBS : NÃO REMOVER O ARQUIVO SALVO DA FICHEIRA DO EXECUTÁVEL , O PATH USADO E DO TIPO RELATIVO
    string dataN;
    const char *aux1;
    fstream dado("Marunae.data",ios_base::in|ios_base::out|ios_base::binary|ios_base::trunc);
    ifstream data("C:\\Users\\limaa\\OneDrive\\Imagens\\red-eyes-black-charizard-59b472f0d1afc-estampa-301-680x969.jpg",ios_base::binary);
    ofstream buffer("joge.jpg",ios_base::trunc|ios_base::binary);
    //buffer<<data;
    ///ios_base::in     => O dado sai do arquivo e entra no run do executavel...
    ///ios_base::out    -> O dado sai do executavel e entra no arquivo ...
    ///ios_base::binary -> O dado vai ser escrito de forma binaria no arquivo ...
    ///ios_base::trunc  -> Dados anteriores a execução atual serão apagados ..

    //data.open("Marunae.data");


    while(getline(data,dataN))
    {
        buffer<<dataN<<endl;
        cout<<dataN<<endl;

    }


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
    cout << "Hello world!" << endl;





    return 0;
}
