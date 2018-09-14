#include <bits/stdc++.h>
using namespace std;

const int N = 10000;

vector<int> A[N] , DFS;

int vis[N];

void dfs(int n){

  vis[n] = 1;
  DFS.push_back(n);

  for(int i = 0 ; i < A[n].size() ; i++){
    if(vis[A[n][i]] == 0){
      dfs(A[n][i]);
      DFS.push_back(n);
    }
  }

  return;

}

int main(){

  int n , q;

  cin >> n >> q;

  for(int i = 0 ; i < q ; i++){
    
    int x , y;
    cin >> x >> y;

    A[x].push_back(y);
    A[y].push_back(x);

  }

  dfs(1);

  for(int i = 0 ; i < DFS.size() ; i++) cout << DFS[i] << "\n";

  return 0;

}
