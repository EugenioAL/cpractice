#include "grafo.hpp"


int main(int argc, char *argv[]){
    hi();
    hello();
    vector<ListaNo> enc;
    enc.push_back(ListaNo(4));
    enc.push_back(ListaNo(6));
    enc.push_back(ListaNo(7));
    enc.push_back(ListaNo(2));

    for(int i=0;i < enc.size();i++){
        cout << enc.at(i).dist << endl;
    }
}