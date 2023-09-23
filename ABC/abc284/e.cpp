#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int main(void) {
  int n,m;
  cin >> n >> m;

  vector<vector<int> > graph(n);
  rep(i,m) {
    int u,v;
    cin >> u >> v;
    u--, v--;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
}