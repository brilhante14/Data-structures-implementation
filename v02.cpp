struct MD{
    unsigned int m;
    void registrar_tam(unsigned int tam_tabela){
        m = tam_tabela;
    }
    unsigned int dispersao(unsigned int c ){
        return c%m;
    }
};

#include <iostream>
#include <new>
using namespace std;

template <typename TC, typename TV, typename TD>
struct DicioDisp{
    struct Noh{
      TC c; //Chave que deverá ser inserida no campo correspondente;
      TV v; //Valor que deve ser inserido na chave correspondente;
      Noh* prox; //Ponteiro para o próximo elemento;  
    };
    unsigned int n; //Número de elementos contidos no vetor;
    unsigned int m; //Tamanho da tabela;
    Noh**va;
    TD h; //Elemento para manusear o tamanho e posições para a tabela de disperção
    bool inicializar(){
        Noh**vector = new(nothrow)Noh*[1];
        if(vector == nullptr){
            return true;
        }
        m = 1; //Tamanho inicial do vetor == 1;
        n = 0; //Quantidade de elementos inicial do vetor == 0;
        vector[0] = nullptr;
        h.registrar_tam(m); //Primeiro registro do tamanho do vetor;
        va = vector; //Aponta o ponteiro do struct para o vetor;
        return false;
    }
    bool inserir(TC c, TV v){ //As chaves sempre serão novas;
        unsigned int posicao = h.dispersao(c);
        Noh* noh = new(nothrow)Noh;
        if(noh == nullptr){
            return true;
        }
        noh->c = c;
        noh->v = v;
        noh->prox = nullptr;
        insercao(posicao,noh, va);
        n+=1;
        if(n==m){
            m = 2*m;
            h.registrar_tam(m);
            if(redimensionar()){
                return true;
            }
        }
        return false;
    }
    void insercao(unsigned int p, Noh* noh, Noh** v){
        if(v[p] == nullptr){
            v[p] = noh;
            v[p]->prox = nullptr;
        }
        else{
            noh->prox = v[p];
            v[p] = noh;
        }
    }
    bool redimensionar(){
        Noh**vector_a  = new(nothrow)Noh*[m];
        if(vector_a == nullptr){
            return true;
        }
        for(int i=0;i<m;i+=1){
            vector_a[i] = nullptr;
        }
        for(int i=0; i<n; i+=1){
            if(va[i]==nullptr){
                continue;
            }
            unsigned int posicao = h.dispersao(va[i]->c); 
            Noh* j;
            j= va[i];          
            while(j->prox !=nullptr){ 
                Noh aux = j->prox;
                insercao(posicao,j,vector_a);
                j = &aux;         
                cout << j;     
            }           
            insercao(posicao,j,vector_a);
            cout << "Ass\n\n";
        }
        // for(int i=0; i<m; i+=1){
        //     if(vector_a[i] == nullptr){
        //         continue;
        //     }
        //     else if(vector_a[i]->prox !=nullptr){
        //         if(vector_a[i] == vector_a[i]->prox->prox){
        //             vector_a[i]->prox->prox = nullptr;
        //         }
        //     }
        // }
        va = vector_a;
        // terminar(vector_a);
        return false;
    }
    // void terminar(Noh** v){
    //     for(int i=0;i<m;i+=1){
    //         while(v[i]->prox != nullptr){
    //             Noh* noh = v[i];
    //             v[i] = noh->prox;
    //             delete noh;                
    //         }
    //         delete v[i];
    //     }
    //     delete[] v;
    // }
    void print(){
        for(int i =0; i<m;i+=1){
            Noh* j = va[i];
            if(j == nullptr){
                continue;
            }
            while(j->prox !=nullptr){
                cout<<j->c << i << endl;
                j = j->prox;
            }
            cout<<j->c << i << endl;
        }
    }
};
int main(){
    DicioDisp <unsigned int, char, MD> d;
    d.inicializar();
    cout << "Ola\n";
    d.inserir(8,'c');
    cout << "QQ\n";
    d.inserir(16,'d');
    //d.print();
    //cout << "\n";  
    //d.inserir(24,'e');
    //d.print();
    //cout << "\n";
    //d.inserir(32,'f');
    //d.print();
    //cout << "\n";
    //d.inserir(40,'b');
    //d.print();
}