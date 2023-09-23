#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

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
int main(void) {
  int n,m;
  cin >> n >> m;

  UnionFind uf;
  uf.init(n);
  rep(i,m) {
    int u,v;
    cin >> u >> v;
    u--; v--;
    uf.unite(u,v);
  }

  set<int> sets;
  rep(i,n) sets.insert(uf.root(i));
  cout << sets.size() << endl;
}