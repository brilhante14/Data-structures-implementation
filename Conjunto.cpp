#include <new>
#include <iostream>

using std::cout;
using std::nothrow;

template<typename T>
struct Conj{
    T *v; int ult, tam_v, i;

    bool inicializar()
    {
        v = new(nothrow) T[1];
        if(v==nullptr) return true;
        tam_v = 1; ult = -1;
        return false; 
    }

    bool pertence(T e)
    {
       for(i=0;i<=ult;++i) if(v[i] == e) return true;
       return false;
        
    }

    bool redimensionar(int tam_w)
    {
        T *w = new(nothrow) T[tam_w];
        if(w==nullptr) return true;
        for(i=0;i<ult;++i) w[i] = v[i];
        delete[] v; 
        v=w; tam_v = tam_w;
        return false;
    }

    bool inserir(T e)
    {
        if(pertence(e)){
            cout << "O número já está no conjunto.\n";
            return false;
        }
        ++ult; 
        if(ult==tam_v){
            if(redimensionar(tam_v*2)) return true;
        }
        v[ult] = e;
        return false;
    }

    bool remover(T e)
    {
        if(pertence(e)){
            v[i] = v[ult]; 
            --ult;
        }
        else cout << "Elemento não encontrado! \n";
        if(tam_v/4 == ult+1) if(redimensionar(tam_v/2)) return true;
        return false;
    }

    void print()
    {
        for(i=0;i<=ult;++i) cout << v[i] << " | ";
        cout << '\n';
    }

    void terminar(){ delete[] v; }

};

int main()
{
    Conj<int> c;
    c.inicializar();
    for(int i=1;i<11;++i){ 
        c.inserir(i);
        c.print();
    }
    c.terminar();
    return 0;
}