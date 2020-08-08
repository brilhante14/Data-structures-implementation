#include <new>
#include <iostream>

using std::cout;
using std::nothrow;


template <typename T> struct Pilha
{
    struct Noh{
        T e; Noh *p;
    };
    Noh *topo;
    void inicializar(){
        topo = nullptr;
    }

    bool vazia(){return(topo==nullptr);}

    T consultar_topo(){return (*topo).e;}

    bool empilhar(T elem){
        Noh *n = new(nothrow) Noh;
        if(n == nullptr) return true;
        (*n).e = elem; (*n).p = topo;
        topo = n;
        return false;
    }

    T desempilhar(){
        Noh *n = topo;
        topo = (*n).p;
        T elem = (*n).e;
        delete[] n;
        return elem;
    }

    void terminar(){
        while (!vazia())
        {
            desempilhar();
        }
        
    }
};

int main(){
    Pilha<double> t;
    t.inicializar();
    t.empilhar(3);
    t.empilhar(31);
    t.empilhar(56);
    t.empilhar(2);
    t.empilhar(5);
    cout << t.consultar_topo() << '\n';
    t.desempilhar();
    cout << t.consultar_topo() << '\n';
    t.desempilhar();
    cout << t.consultar_topo() << '\n';
    t.desempilhar();
    cout << t.consultar_topo() << '\n';
    t.desempilhar();
    cout << t.consultar_topo() << '\n';
    t.desempilhar();
    t.terminar();
}
 