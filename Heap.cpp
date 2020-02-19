template <typename T>
struct Heap
{
    T *v; 
    int n; 
    int tam_v;
    void inicializar(T *vetor, int tam)
    {
        tam_v = tam; n = 0; v = vetor;
    }
    
    void inserir(T e)
    {
        v[n] = e;
        subir(n);
        ++n;
    }

    int pai(int i)
    {
        return (i-1)/2;
    }

    int fesq(int i)
    {
        return 2*i + 1;
    }

    int fdir(int i)
    {
        return 2*i + 2;
    }

    void subir(int i)
    {
        if(i==0) return;
        int p = pai(i);
        if(v[p]<v[i])
        {
            T copia_pai = v[p];
            v[p] = v[i];
            v[i] = copia_pai;
            subir[p];
        }
    }

    bool vazio(){return n==0;}
    bool cheio(){return n==tam_v;}

    T consultar_max(){return v[0];}

    T remover_max()
    {
        T e = v[0];
        --n;
        v[0] = v[n];
        if(n != 0) descer(0);
        return e;
    }
  
    void descer(int i)
    {   
        int fmax = fesq(i);
        if(n <= fmax) return;
        if(fmax+1 < n && v[fmax+1] > v[fmax]) ++fmax; 
        if(v[i] >= fmax) return;
        T copia_pai = v[i];
        v[i] = v[fmax];
        v[fmax] = copia_pai;
        descer(fmax);
    }


};
