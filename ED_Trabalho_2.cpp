#include <new>
#include <iostream>

using std::cout;
using std::nothrow;

struct SimulAloc
{
    struct Noh
    {
        int ini, tam; Noh *prox;
    };
    Noh *prim;

    bool inicializar(int ini, int tam){
        Noh *n = new(nothrow) Noh;
        if(n==nullptr) return true;
        (*n).ini = ini; (*n).tam = tam; (*n).prox = nullptr;
        prim = n;
        return false;
    }

    int alocar(int tam){
        int ini;   
        if(tam<=(*prim).tam){
            (*prim).tam -= tam;
            ini = (*prim).ini + (*prim).tam;
            if((*prim).tam == 0) prim = (*prim).prox; 
  
            return ini;
        } else {
            Noh *n = prim;
            do
            {
                n = (*n).prox;
                if(tam<=(*n).tam){
                    (*n).tam -= tam;
                    ini = (*n).ini + (*n).tam;
                    if((*n).tam == 0) delete n; 
                    return ini;
                }
            } while ((*n).prox != nullptr);
        }
        return -1;
    }

    bool desalocar(int ini, int tam){
        if((*prim).ini + (*prim).tam == ini){    
            (*prim).tam += tam;
            if((*prim).prox != nullptr){
                Noh *n = (*prim).prox;
                if((*n).ini == (*prim).ini+(*prim).tam){
                    (*prim).tam += (*n).tam; (*prim).prox = (*n).prox;
                    delete n;
                }   
            }
            return false;

        } else if((*prim).prox!=nullptr){
            Noh *p = (*prim).prox;

            if((*p).ini >= (ini+tam)) {          
                Noh *n = new(nothrow) Noh;
                if(n==nullptr) return true;
                (*n).ini = ini; (*n).tam = tam;
                (*n).prox = p; (*prim).prox = n;
            }

            p = (*prim).prox;
            if((*p).ini == (*prim).ini+(*prim).tam){
              (*prim).tam += (*p).tam; (*prim).prox = (*p).prox;
              delete p;
            }

            do {               
                if((*p).ini + (*p).tam == ini){  
                    (*p).tam += tam;
                }
                if((*p).prox != nullptr){
                    Noh *k = (*p).prox;
                                     
                    if((*k).ini == (*p).ini+(*p).tam){
                        (*p).tam += (*k).tam; (*p).prox = (*k).prox;
                        delete k;
                    }
                }
                
                p = (*p).prox;
            } while (p != nullptr);
        return false;
        }
        Noh *n = new(nothrow) Noh;
        if(n == nullptr) return true;
        (*n).ini = ini; (*n).tam = tam;
        (*n).prox = nullptr; (*prim).prox = n;
        return false;
    }

    void terminar(){
        while((*prim).prox != nullptr){
            Noh *n = (*prim).prox;
            (*prim).prox = (*n).prox;
            delete n;
        }
        delete prim;
    }
};

int main(){
  SimulAloc s;
  s.inicializar(58, 150);
  cout <<"\n----------------------------\n";
  s.alocar(45);
  cout <<"\n----------------------------\n";
  s.alocar(20);
  cout <<"\n----------------------------\n";
  s.desalocar(143, 20);
  cout <<"\n----------------------------\n";
  s.alocar(17);
  cout <<"\n----------------------------\n";
  s.desalocar(163, 45);
  cout <<"\n----------------------------\n";
  s.alocar(24);
  cout <<"\n----------------------------\n";
  s.desalocar(146, 17);
  s.terminar();
}

// INIC., Tam: 150  Ini: 58
// ALOC., Tam: 45  Ini: 163
// ALOC., Tam: 20  Ini: 143
// DESAL, Tam: 20  Ini: 143
// ALOC., Tam: 17  Ini: 146
// DESAL, Tam: 45  Ini: 163
// ALOC., Tam: 24  Ini: 122
// DESAL, Tam: 17  Ini: 146