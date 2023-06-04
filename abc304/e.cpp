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
  int N,M;
  cin >> N >> M;
  vector<int> u(M),v(M);
  rep(i,M) cin >> u[i] >> v[i];
  int K;
  cin >> K;
  vector<int> x(K),y(K);
  rep(i,K) cin >> x[i] >> y[i];
  int Q;
  cin >> Q;
  vector<int> p(Q),q(Q);
  rep(i,Q) cin >> p[i] >> q[i];

  UnionFind uf;
  uf.init(N);
  rep(i,M) {
    u[i]--; v[i]--;
    uf.unite(u[i],v[i]);
  }
  // 事前check
  bool good=true;
  map<pair<int,int>,int> mp;
  rep(i,K) {
    x[i]--; y[i]--;
    if(uf.same(x[i],y[i])) good=false;
    pair<int,int> P = make_pair(uf.root(x[i]), uf.root(y[i]));
    mp[P]=1;
  }

  rep(i,Q) {
    p[i]--; q[i]--;
    if(good==false) cout << "No" << endl;
    else {
      if(uf.same(p[i],q[i])) cout << "Yes" << endl;
      else {
        pair<int,int> P = make_pair(uf.root(p[i]), uf.root(q[i]));
        pair<int,int> P2 = make_pair(uf.root(q[i]), uf.root(p[i]));
        if(mp[P]==1) cout << "No" << endl;
        else if(mp[P2]==1) cout << "No" << endl;
        else cout << "Yes" << endl;
      }
    }
  }
}