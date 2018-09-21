#include <bits/stdc++.h>
#define N 10000
#define Na 20
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
         
    for(int i = Na - 1 ; i >=0 ; i--){
                   
      if(nv[x] - (1 << i) >= nv[y]){
                                 
        x = a[x][i];
                                             
      }
                           
    }
             
  if(x == y) return x;
                 
  for(int i = Na - 1; i >= 0; i--)
    
    if(a[x][i] != -1 && a[x][i] != a[y][i]){
                                         
      x = a[x][i];                                               
      y = a[y][i];

    }

  return a[x][0];
                         
}

int main(){
  
  int n;
  cin >>  n;

  memset(a,-1,sizeof(a));
  memset(pai,-1,sizeof(pai));
  memset(nv,-1,sizeof(nv));

  for(int i = 1 ; i < n ; i++){
    
    int x , y;
    cin >> x >> y;
    
    tab[x].push_back(y);
    tab[y].push_back(x);
    
  }
  
  int t , w;
  cin >> t >> w;
  
  nv[1] = 0;

  DFS(1);

  for(int i = 1 ; i <= n ; i++) a[i][0] = pai[i];

  for(int i = 1 ; i < Na ; i++)
    for(int j = 1 ; j <= n ;j++)
      a[j][i] = a[a[j][i-1]][i-1];
  
  cout << LCA(t,w) << "\n";

  return 0;
  
}  
