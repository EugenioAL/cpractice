#include <cstring>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <list>
#include "aloca.h"
using namespace std;

int main(int argc,char*argv[]){
    string line;
    ifstream myfile;
    string delimiter = " ";//decidi usar este delimitador porque foi o que mais achei unico na divisão dos campos;
    string filename = argv[1];
    myfile.open(argv[1], ios::out);
    list<Data> dados;
    Data aux(0,NULL);
    char* var = NULL;
    list<Data>::iterator listPos;
    string token;
    meualoc *alocaEnt = NULL;
    size_t pos;
    char buff[10];
    int i = 0, tamAloca,contFalha =0,polMem,contCampo,flagMeualoc = 0, flagAloca = 0, flagFree = 0;
     while ( getline (myfile,line))
    {   
        pos = 0;
        contCampo = 0;
        while ((pos = line.find(delimiter)) != string::npos) {
        token = line.substr(0, pos);
        string_to_vet_char(token,buff,10);
        line.erase(0, pos + delimiter.length());
        if(i > 1){
            if(contCampo == 0){
                if(token == "A"){
                    flagAloca = 1;
                }
                else{
                    flagFree = 1;
                }
            }
            else{
                aux.id = atoi(buff);
            }
        }
        else if(i == 0){
            if(contCampo == 0){
                tamAloca = atoi(buff);
                flagMeualoc = 1;
            }
        }
        contCampo++;
        }
        string_to_vet_char(line,buff,10);
        if(i>1 && flagAloca == 1){
            var = alocaEnt->aloca(atoi(buff));
            if(var){
                aux.pont = var;
                dados.push_front(aux);
            }
            else{
                contFalha++;
            }
        }

        else if(i > 1 && flagFree == 1){
            listPos = dados.begin();
            while (listPos != dados.end())
            {
                if(listPos->id == aux.id){
                    aux.pont = listPos->pont;
                    dados.erase(listPos);
                    listPos = dados.end();
                    alocaEnt->libera(aux.pont);
                }
                else{
                    listPos++;
                }
            }
            
        }
        else if(i == 0 && flagMeualoc == 1){
            string_to_vet_char(line,buff,10);
            polMem = atoi(buff);
            alocaEnt = new meualoc(tamAloca,polMem);
        }
        else if(i == 1){
        }
        flagAloca = 0;
        flagFree = 0;
        cout << alocaEnt->tamListaVazios() <<"\t" << alocaEnt->mediaTamBlocos() <<"\t" << alocaEnt->tamLivres() << endl;
        i++;
        cout << endl;
    }
    cout << "Falha\t" << contFalha << endl;
}