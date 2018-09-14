#include <bits/stdc++.h>
#define N 10000
#define NA 20
using namespace std;
 
int pai[N] , nv[N];
 
int a[N][Na];
 
vector<int> tab[N];
 
void DFS(int n){
     
   for(int i = 0 ; i < tab[n].size() ; i++){
               
    if(nv[tab[n][i]] == -1){
                         
      pai[tab[n][i]] = n;
                                     
      nv[tab[n][i]] = nv[n] + 1;
                                                 
      DFS(tab[n][i]);
   }
                       
  }
       
}
 
int LCA(int x , int  y){
     
     
   if(nv[x] < nv[y]) swap(x , y);
         
    for(int i = Na - 1 ; >=0 ; i--){
                   
      if(nv[a[x][i]] - (1 << i) >= nv[y]){
                                 
        x = a[x][i];
                                             
      }
                           
    }
             
  if(x == y) return x;
                 
  for(int i = Na - 1; i >= 0; i--)
                           
    if(ancestral[x][i] != -1 && ancestral[x][i] != ancestral[y][i]){
                                         
      x = ancestral[x][i];                                               
      y = ancestral[y][i];
   
    }
                         
  return a[x][0];
                         
}

int main(){

  cin >>  n;
 
  for(int i = 0 ; i < N ; i++)
    for(int j = 0 ; j < M  ; j++) ancestral[i][j] = -1;

  for(int i = 1 ; i < n ; i++){
    
    int x , y;
    cin >> x >> y;
    
    tree[x].push_back(y);
    tree[y].push_back(x);
    
    cout << "oi";

  }
  
  int t , w;
  cin >> t >> w;
  
  cout << "oi";

  DFS(1);
  
  for(int i = 1 ; i <= n ; i++) cout << grau[i] << " ";

  cout << LCA(t,w) << "\n";

  return 0;
  
}  
