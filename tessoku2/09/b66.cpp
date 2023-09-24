// 17:44 ~ 
// union findを利用して、同じ範囲を設定する
// union findは、削除ができない？？
/*
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int N,M;
vector<int> A,B;
int Q;
vector<int> Query;
int main(void) {
  cin >> N >> M;
  A.resize(M), B.resize(M);
  rep(i,M) cin >> A[i] >> B[i];
  cin >> Q;
  rep(i,Q) {
    int key;
    cin >> key;
    if(key == 1) {
      int x;
      cin >> x;
    } else if(key == 2) {
      int u,v;
      cin >> u >> v;
    }
  }
}
*/


#include <iostream>
#include <vector>
using namespace std;

class UnionFind {
  public:
  vector<int> par;

  void init(int sz) {
    par.resize(sz,-1);
  }
  int root(int pos) {
    if(par[pos]==-1) return pos;
    par[pos] = root(par[pos]);
    return par[pos];
  }
  void unite(int u, int v) {
    u = root(u); v = root(v);
    if(u == v) return;
    par[u]=v;
  }
  bool same(int u, int v) {
    if (root(u) == root(v)) return true;
    return false;
  }
};
int N,M,A[100009], B[100009];
int Q, QueryType[100009], x[100009], u[100009], v[100009];
string Answer[100009];

UnionFind UF;
bool cancelled[100009];
int main() {
  cin >> N >> M;
  for (int i=1 ; i<=M; i++) cin >> A[i] >> B[i];
  cin >> Q;
  for (int i=1; i<=Q; i++) {
    cin >> QueryType[i];
    if (QueryType[i]==1) cin >> x[i];
    else if(QueryType[i]==2) cin >> u[i] >> v[i];
  }
  for (int i=1; i<=M; i++) cancelled[i] = false;
  for (int i=1; i<=Q; i++) {
    if(QueryType[i]==1) cancelled[x[i]] = true;
  }
  UF.init(N+1);
  for (int i=1; i<=M; i++) {
    if (cancelled[i]==false && UF.same(A[i],B[i]) == false) {
      UF.unite(A[i], B[i]);
    }
  }
  for (int i=Q; i>=1; i--) {
    if (QueryType[i] == 1) {
      if(UF.same(A[x[i]],B[x[i]])==false) UF.unite(A[x[i]],B[x[i]]);
    }
    else if(QueryType[i] == 2) {
      if (UF.same(u[i], v[i]) == true) Answer[i] = "Yes";
      else Answer[i] = "No";
    }
  }
  for (int i=1; i<=Q; i++) {
    if (QueryType[i] == 2) cout << Answer[i] << endl;
  }
}