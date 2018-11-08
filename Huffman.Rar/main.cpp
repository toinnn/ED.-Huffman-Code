#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ///OBS : NÃO REMOVER O ARQUIVO SALVO DA FICHEIRA DO EXECUTÁVEL , O PATH USADO E DO TIPO RELATIVO
    fstream dado("Marunae.data",ios_base::in|ios_base::out|ios_base::binary|ios_base::trunc),data;
    ///ios_base::in     => O dado sai do arquivo e entra no run do executavel...
    ///ios_base::out    -> O dado sai do executavel e entra no arquivo ...
    ///ios_base::binary -> O dado vai ser escrito de forma binaria no arquivo ...
    ///ios_base::trunc  -> Dados anteriores a execução atual serão apagados ..





    if(dado.is_open())
    {
        dado.close();
    }
    if(data.is_open())
    {
        data.close();
    }
    cout << "Hello world!" << endl;





    return 0;
}
