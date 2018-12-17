#ifndef COMPRESSOR_H
#define COMPRESSOR_H
#include "HuffmanTree.h"
#include <windows.h>
#include <fstream>
#include <bitset>
#include "HashMap.h"

class Compressor
{   private:

    //IFileDialog
    //OPENFILENAME ofn ;
    string Fatia(string linha,int i ,int j);
    public:
        Compressor();
        virtual ~Compressor();
        void comprimir(string path);
        int comprimir(int k);
        //ofn.



    protected:


};

#endif // COMPRESSOR_H
