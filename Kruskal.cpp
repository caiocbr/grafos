#include <bits/stdc++.h>
using namespace std;

const int N = 10000;

struct aresta{

  int x , y; 

  int d;

};

vector<aresta> A , MST; // A =  array das arestas do grafo , MST = arvore geradora minima

int pai[N] , grau[N]; // grau e o numero de "filhos" 

int find(int x){

  if(pai[x] == x) return x;

  return pai[x] = find(pai[x]);
 
}  

void uny(int x , int y){

  x = find(x);
  y = find(y);

  if(x == y) return;

  if(grau[x] < grau[y]) swap(x,y);

  pai[y] = x;

  if(grau[x] == grau[y])  grau[x]++;

}

bool comp(aresta a , aresta b){return a.d <  b.d;}

void Kruskal(){

  sort(A.begin() , A.end() , comp);

  for(int i = 0 ; i < A.size() ; i++){
    if(find(A[i].x) != find(A[i].y)){
      uny(A[i].x , A[i].y);
      MST.push_back(A[i]);
    }
   
   }

}

int main(){

  int n , q;

  cin >> n >> q;

  for(int i = 0 ; i < N ; i++) grau[i] = 1;
  for(int i = 0 ; i < N ; i++) pai[i] = i;

  for(int i = 0 ; i < q ; i++){

    aresta a;
    cin >> a. x >> a.y >> a.d;

    A.push_back(a);

  }

  Kruskal();

  for(int i = 0 ; i < MST.size() ; i++) cout << MST[i].x << " " <<  MST[i].y << " " <<  MST[i].d << "\n";

  return 0;
 
}
