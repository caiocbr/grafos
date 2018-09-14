#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

const int N = 10000;
const int INF = 99999999;

int A[N][N] , distancia[N] , vis[N] , n; //   n =  numero de nos

priority_queue< pii , vector<pii> , greater<pii> > D;

void Prim(int x){

  for(int i = 1 ; i <= n ; i++)  distancia[i] = INF;
  distancia[x] = 0;

  D.push(make_pair(0,x));
  
  while(!D.empty()){
    
    pii a = D.top();
    D.pop();

    if(vis[a.second] == 1) continue;
    vis[a.second] = 1;

    for(int i = 1 ; i <= n ; i++){

      if(distancia[i] > A[i][a.second]){
        distancia[i] = A[i][a.second];
        D.push(make_pair(distancia[i],i));
      }
    }
  }
}

int main(){
 
  int q;
  cin >> n >> q;

  for(int i = 0 ; i < N ; i++)
    for(int j = 0 ; j < N ; j++) A[i][j] = INF;

  for(int i = 0 ; i < q ; i++){
   
    int x , y , z;
    cin >> x >> y >> z;

    A[x][y] = z;
    A[y][x] = z;
    
  }

  Prim(1);

  for(int i = 1 ; i <= n ; i++) cout << distancia[i] << " ";

  return 0;

}
