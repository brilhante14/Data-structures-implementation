#include <iostream>
#include <new>

using std::cout; using std::cin; using std::nothrow;

template <typename T>
struct Pilha
{
  T *v; int ult, tam_v;
  bool inicializar()
  {
    v = new(nothrow) T[1];
    if(v==nullptr) return true;
    ult = -1; tam_v = 1;
    return false;
  }

  void terminar()
  {
    delete[] v;
  }

  bool vazia()
  {
    return (ult == -1);
  }

  bool redimensionar(int tam_w)
  {
    T *w = new(nothrow) T[tam_w];
    if(w==nullptr) return true;
    for(int i=0;i<=ult;++i) w[i]=v[i];
    delete[] v;
    v = w; tam_v = tam_w;
    return false;
  }

  bool empilhar(T e)
  {
    if(ult==tam_v-1){
      if(redimensionar(tam_v*2)) return true;
    }
    ++ult;
    v[ult] = e;
    return false;
  }

  T topo() 
  {
    return v[ult];
  }

  bool desempilhar()
  {
    --ult;
    if(!vazia() && (ult+1)==(tam_v/4)){
      if(redimensionar(tam_v/2)) return true;
    }
    return false;
  }
};

int main()
{
  Pilha<double> P;
  if(P.inicializar()) return 1;
  for(;;){
    cout << "Número para empilhar (negativo para terminar): ";
    double num;
    cin >> num;
    if(num<0) break;
    if(P.empilhar(num)) return 2;
  }
  cout << "Números digitados: ";
  while(!P.vazia()){
    cout << ' ' << P.topo();
    if(P.desempilhar()) return 3;
  }
  P.terminar();
  return 0;
}