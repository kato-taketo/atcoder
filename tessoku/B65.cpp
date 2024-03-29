#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007
vector<vector<int> > graph;
vector<bool> used;
vector<int> value;
void dfs(int v) {
  used[v]=true;
  value[v]=0;
  int tmp=0;
  for(int i=0; i<graph[v].size(); i++) {
    int nv=graph[v][i];
    if(used[nv]) continue;
    dfs(nv);
    tmp=max(tmp,value[nv]+1);
  }
  value[v]=tmp;
}
int main(void) {
  int n,t;
  cin >> n >> t;
  t--;

  // make graph
  graph.resize(n);
  used.resize(n,false);
  value.resize(n);
  rep(i,n-1) {
    int a,b;
    cin >> a >> b;
    a--; b--;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  // dfs
  dfs(t);
  rep(i,n) {
    if(i==0) cout << value[i];
    else cout << " " << value[i];
  }
  cout << endl;
}