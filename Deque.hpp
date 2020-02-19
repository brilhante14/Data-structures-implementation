#include <new>
#include <iostream>

using std::cout;
using std::nothrow;

template <typename T>
struct Deque
{
    T *v; int tam_v, esq, dir, num_elementos; 
    
    bool inicializar (Deque<T> &D){
        v = new(nothrow) T[1];
        if(v==nullptr) return true;
        esq = 1; dir = 0; tam_v = 1; num_elementos = 0;
        return false;
    }

    bool vazio (Deque<T> &D){
        return (esq>dir);
    }

    bool redimensionar (int tam_w){
        T *w = new(nothrow) T[tam_w];
        if(w==nullptr) return true;
        int old_esq = esq;
        esq = tam_v-(num_elementos/2);
        dir = esq + num_elementos;
        for(int i = esq; i<=dir;++i){
            w[i] = v[old_esq];
            ++old_esq;
        }
        delete[] v;
        v=w;
        tam_v = tam_w;
        return false;
    }

    bool inserir_esq (Deque<T> &D, T e){
        --esq;
        if(esq<0){
            if(redimensionar((tam_v*2))) return true;
        }
        v[esq] = e;
        ++num_elementos;
        return false;
    }

    bool inserir_dir (Deque<T> &D, T e){       
        ++dir;
        if(dir>=tam_v){
            if(redimensionar((tam_v*2))) return true;
        }
        v[dir] = e;
        ++num_elementos;
        return false;
    }

    void print_deque(Deque<T> &D){
        cout << "\n E \n";
        for(int i=esq; i<=dir; ++i){
            cout << v[i] <<" | ";
        }
    }

    
    T remover_esq (Deque<T> &D){
        ++esq;
        --num_elementos;
        if(num_elementos<(tam_v/4)){
            if(redimensionar((tam_v/2))) return T(NULL);
        }
        return v[esq-1];
    }

    T remover_dir (Deque<T> &D){
        --dir;
        --num_elementos;
        if(num_elementos<(tam_v/4)){
            if(redimensionar((tam_v/2))) return T(NULL);
        }
        return v[dir+1];
    }

    void terminar (Deque<T> &D){
        delete[] v;
    }

};