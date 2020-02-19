#ifndef FILA_HPP
#define FILA_HPP

// #include <new>
// #include <iostream>

using std::nothrow;

template <typename T> struct Fila_Encadeada
{
    struct Noh
    {
        T elem; Noh *p;
    };
    Noh *prim, *ult;
    void inicializar(){
        prim = nullptr;
        ult = nullptr;
    }

    bool vazia(){return(prim==nullptr);}

    bool enfilar(T e){
        Noh *n = new(nothrow) Noh;
        if(n==nullptr) return true;
        (*n).p = nullptr; (*n).elem = e;
        if(vazia()) prim = n;
        else (*ult).p = n;
        ult = n;
        return false;
    }

    T desenfilar(){
        T e = (*prim).elem;
        Noh *n = prim;
        prim = (*n).p;
        delete n;
        return e;
    }

    T primeiro(){return (*prim).elem}

    void terminar(){
        while (!vazia())
        {
            desenfilar()
        }
    }
};




#endif