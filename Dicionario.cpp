#include <new>
#include <iostream>

using std::cout;
using std::nothrow;

template <typename X, typename Y> struct Par
{
    X x; Y y;
};

template <typename TC, typename TD> struct Dicionario
{
    Par<TC, TD> *v; int ult, tam_v;

    bool inicializar(){
        v = new(nothrow) Par<TC, TD>[1]; 
        if(v==nullptr) return true;
        ult = -1; tam_v = 1;
        return false;
    }

    Par<bool, TD> procurar(TC c){
        Par<bool, TD> p;
        for(int i=0;i<=ult;++i){
            if(v[i].x == c){ 
                p.x = true;
                p.y = v[i].y;
                return p;
            }
        }
        p.x = false; return p;
    }

    bool redimensionar(int tam_w){
        Par<TC, TD> *w = new(nothrow) Par<TC, TD>[tam_w];
        if(w==nullptr) return true;
        for(int i=0; i<= ult; ++i) w[i] = v[i];
        delete[] v;
        v = w;
        tam_v = tam_w;
        return false;
    }

    Par<bool, bool> inserir(TC c, TD d){
        Par<bool, bool> r;
        if(procurar(c).x){
            r.x = true; return r;
        }
        r.x = false;
        Par<TC, TD> *p = new(nothrow) Par<TC, TD>;
        if(p==nullptr){
            r.y = true; return r;
        }
        if(ult+1 == tam_v) if(redimensionar(tam_v * 2)) {
            r.y = true;
            return r;
        }
        r.y = false;
        ++ult;
        (*p).x = c; (*p).y = d;
        v[ult] = *p;
        return r;
    }

    

    Par<bool, bool> remover(TC c){
        Par<bool, bool> r;
        for(int i=0;i<=ult;++i){
            if(v[i].x == c){
                v[i] = v[ult];
                --ult;
                r.x = false;
                if(tam_v/4 == ult+1){
                    if(redimensionar(tam_v/2)){
                        r.y = true;
                        return r;
                    }
                }            
                r.y = false;
                return r;
            }
        }
        r.x = true; return r;
    }
    void terminar(){
        delete[] v;
    }
};

int main(){
  Dicionario<char, int> d;
  d.inicializar();
  d.inserir('A', 8);
  d.inserir('B', 3);
  d.inserir('C', 5);
  d.inserir('D', 9);
  d.inserir('E', 9);
  cout << d.tam_v;
  d.remover('B');
  d.remover('C');
  d.remover('A');
  cout << d.tam_v;
  Par<bool,int> x = d.procurar('D');
  if(x.x) cout << x.y;
  else cout << "N\n";
  d.terminar();

  return 0;
}