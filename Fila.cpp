#include <new>
#include <iostream>

using std::cout;
using std::nothrow;

template <typename T>
struct Fila{
    T *v; int tam_v, prim, ult;

    bool inicializar()
    {
        v = new(nothrow) T[1];
        if(v==nullptr) return true;
        ult = -1; prim = 0; tam_v = 1;
        return false;
    }

    bool vazia(){ return(ult<prim); }

    T primeiro(){ return v[prim]; }

    T ultimo(){ return v[ult]; }

    bool redimensionar(int tam_w)
    {
        T *w = new(nothrow) T[tam_w];
        if(w==nullptr) return true;
        int aux = prim, n = ult-prim;
        for(int i=0;i<=n;++i){ 
            w[i] = v[aux];
            ++aux;
        }
        prim = 0; ult = n;
        delete[] v; v = w; tam_v = tam_w;
        return false;
    }

    bool enfilar(T e)
    {
        if(ult==tam_v){ if(redimensionar(tam_v*2)) return true;}
        ++ult; v[ult] = e;
        return false;
    }

    bool desenfilar()
    {
        if(vazia()) return true;
        ++prim;
        if(tam_v/4==(ult-prim)){ if(redimensionar(tam_v/2)) return true; }
        return false;
    }

    bool print()
    {
        if(vazia()) return true;
        cout << "Fila:\n";
        for(int i=prim;i<=ult;++i) cout << v[i] << "|";
        return false;
    }

    void terminar(){ delete[] v; }
};

int main()
{
  Fila<double> f;
  f.inicializar();
  for(int i=1; i<20; i++) f.enfilar(i);
  cout << f.tam_v <<'\n';
  for(int i=1; i<15; i++) f.desenfilar();
  cout << '\n' << f.tam_v <<'\n';
  f.print();
  f.terminar();
  return 0;
}