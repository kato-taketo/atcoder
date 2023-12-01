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
  ll N,M,K;
  cin >> N >> M >> K;
  vector<ll> u(M),v(M),w(M);
  rep(i,M) cin >> u[i] >> v[i] >> w[i];

  vector<int> vec;
  rep(i,N-1) vec.push_back(1);
  rep(i,M-(N-1)) vec.push_back(0);

  sort(vec.begin(), vec.end());
  UnionFind uf;
  ll cost=K, cost_tmp=0;
  bool key=true;
  uf.init(N);
  do {
    cost_tmp=0;
    key=true;
    rep(i,N) uf.par[i]=-1;
    rep(i,M) {
      if(vec[i]==1) {
        cost_tmp += w[i];
        cost_tmp %= K;
        uf.unite(u[i]-1,v[i]-1);
      }
    }
    //cout << "cost: " << cost_tmp << endl;
    rep(i,N) {
      if(uf.same(0, i)==false) key=false;
    }
    //cout << "key: " << key << endl;
    if(key) cost = min(cost, cost_tmp);
  } while(next_permutation(vec.begin(), vec.end()));
  cout << cost << endl;
}