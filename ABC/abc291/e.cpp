#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007
int n,m;
vector<int> dist; // dist[i] := A[i]の値
vector<vector<int> > graph;
void dfs(int v) {
  // 分岐の時は、最小のもののみ選択すれば良い
  vector<bool> tmp(n+1,false);
  for (auto nv: graph[v]) {
    for(auto nnv: graph[nv]) tmp[nnv]=true;
    //dist[nv]=max(dist[nv], dist[v]+1);
    //dfs(nv);
  }
  for(auto nv: graph[v]) {
    if(tmp[nv]==false) dfs(nv);
  }
}
int main(void) {
  cin >> n >> m;
  dist.resize(n+1,-1);
  vector<int> x(m),y(m);
  rep(i,m) cin >> x[i] >> y[i];

  int root,cnt=0;
  vector<bool> roots(n+1,false);
  rep(i,m) roots[x[i]]=true;
  rep(i,m) roots[y[i]]=false;
  rep(i,n+1) if(roots[i]) root=i,cnt++;
  // root isnot one
  if(cnt!=1) {
    cout << "No" << endl; return 0;
  }

  // dfs from root
  graph.resize(n+1);
  rep(i,m) {
    graph[x[i]].push_back(y[i]);
  }

  dist[root]=1;
  dfs(root);
  queue<int> que;

  // check
  vector<bool> used(n+1, false);
  for(int i=1; i<=n; i++) {
    if(dist[i]>n||dist[i]<=0) {
      cout << "No" << endl; return 0;
    }
    used[dist[i]]=true;
  }
  for(int i=1; i<=n; i++) if(used[i]==false) {
    cout << "No" << endl; return 0;
  }
  cout << "Yes" << endl;
  for(int i=1; i<=n; i++) {
    if(i==n) cout << dist[i] << endl;
    else cout << dist[i] << " ";
  }
}