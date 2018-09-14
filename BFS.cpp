#include <bits/stdc++.h>
using namespace std;

const int N = 10000;

int main(){

  int n , q; //n =  numero de nos , q =  numeros de arestas
  cin >> n >> q;

  queue<int> D;
  vector<int> A[N]; // grafo

  for(int i = 0 ; i < q ; i++){

    int x , y;
    cin >> x >> y;

    A[x].push_back(y);
    A[y].push_back(x);
   
  }

  int x; // nos pelo qual a dfs começa
  int vis[N]; // visitados 
  cin >> x;

  D.push(x);

  while(!D.empty()){

    int a = D.front();
    D.pop();

    if(vis[a] == 1) continue;
    vis[a] = 1;
    
    cout << a << "\n";

    for(int i = 0 ; i < A[a].size() ; i++)  D.push(A[a][i]);
    
  }

  return 0;

}
