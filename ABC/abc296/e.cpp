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
  int n;
  cin >> n;
  vector<int> a(n+1);
  for(int i=1; i<=n; i++) cin >> a[i];

  //UnionFind uf;
  //uf.init(n+1);
  vector<vector<int> > graph(n+1);
  vector<bool> used(n+1,false);
  for(int i=1; i<=n; i++) {
    if(used[i]) continue;
    int pre=i, next=a[i], cnt=0;
    while(1) {
      if(pre==next) {
        graph[pre].push_back(next);
        graph[next].push_back(pre);
      }
      if(used[pre]) break;
      graph[pre].push_back(next);
      graph[next].push_back(pre);
      used[pre]=true;
      used[next]=true;
      
      pre=next, next=a[next];
    }
  }

  int cnt=0;
  vector<bool> cnts(n+1,false);
  for(int i=1; i<=n; i++) {
    if(graph[i].size()>1) cnts[a[i]]=true;
  }
  for(int i=1; i<=n; i++) if(cnts[i]) cnt++;
  cout << cnt << endl;
}