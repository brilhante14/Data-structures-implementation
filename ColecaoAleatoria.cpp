#include <new>

using std::nothrow;

struct ColecaoAleatoria
{
    int *v, ult;
};

bool inicializar(ColecaoAleatoria &C, int n){
    C.v = new(nothrow) int[n];
    if(C.v == nullptr) return true;
    C.ult = -1;
    return false;
}

void inserir(ColecaoAleatoria &C, int i){
    ++C.ult; C.v[C.ult] = i; 
}

int remover_elemento(ColecaoAleatoria &C){
    if(C.ult ==0){
        int a= C.v[C.ult];
        C.ult -=1;
        return a;
    }
    int a = rand() % C.ult;
    int x = C.v[a];
    C.v[a] = C.v[C.ult];
    C.ult -=1;
    return x;
}
void print(ColecaoAleatoria &C){
    cout << "Coleção:\n";
    for(int i=0;i<=C.ult;i+=1){
        cout << C.v[i] << "|";
    }cout <<"\n";
}
