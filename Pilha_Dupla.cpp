#include <iostream>
#include <new>
using namespace std;

struct DuasPilhas
{
    double *v; 
    int n, prim, ult;

    void inicializar(double *w, int m){
        v = w; n = m;
        prim = -1; ult = n;
    }

    bool vazia1(){return(prim<0);}

    bool vazia2(){return(ult == n);}

    bool cheia(){return(prim == ult-1);}

    void empilhar1(double d)
    {
        ++prim;
        v[prim] = d;  
    }

    void empilhar2(double d)
    {
        --ult;
        v[ult] = d;
        
    }

    double consultar_topo1(){return(v[prim]);}

    double consultar_topo2(){return(v[ult]);}

    void desempilhar1()
    {
        if(!cheia())--prim;
    }

    void desempilhar2()
    {
        if(!cheia()) ++ult;
    }

    double *terminar(){return v;}

    void print_vetor(){
        cout << "Pilha 1:\n";
        for(int i=0;i<=prim;++i){
            cout << v[i] << " | ";
        }
        cout << "\nPilha 2:\n";
        for(int j=n;j>=ult;--j){
            cout << v[j] << " | ";
        }
    }
};


int main()
{
    int n = 6;
    double *v = new(nothrow) double[n];
    DuasPilhas g;
    g.inicializar(v, n);
    g.empilhar1(2);
    g.empilhar1(9);
    g.empilhar2(5);
    g.empilhar2(3);
    g.empilhar2(8);
    g.desempilhar1();
    g.desempilhar2();
    g.print_vetor();
    g.terminar();
    delete[] v;
    return 0;
}