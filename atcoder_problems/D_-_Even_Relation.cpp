#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int main(void) {
  int n;
  cin >> n;
  vector<ll> u(n),v(n),w(n);
  rep2(i,1,n) cin >> u[i] >> v[i] >> w[i];

  vector<vector<pair<int,ll> > > graph(n+1);
  queue<int> que;
  vector<int> node(n+1,-1);
  rep2(i,1,n) {
    graph[u[i]].push_back(make_pair(v[i],w[i]));
    graph[v[i]].push_back(make_pair(u[i],w[i]));
  }

  que.push(1);
  node[1]=0;
  while(!que.empty()) {
    int v = que.front();
    que.pop();
    for(auto nv: graph[v]) {
      if(node[nv.first]!=-1) continue;
      if(node[v]%2==0) {
        if(nv.second%2==0) node[nv.first]=0;
        else node[nv.first]=1;
      } else {
        if(nv.second%2==0) node[nv.first]=1;
        else node[nv.first]=0;
      }
      que.push(nv.first);
    }
  }

  rep2(i,1,n+1) cout << node[i] << endl;
}