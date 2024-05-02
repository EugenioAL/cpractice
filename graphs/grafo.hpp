#ifndef grafo
#define grafo

#include <iostream>
#include <vector>

using namespace std;

class Vertice{
    int id;
};


class ListaNo{
    public:
    int dist;

    ListaNo(){
        dist = 0;
    }

    ListaNo(int num){
        dist = num;
    }
};


void hello();

void hi();


#endif