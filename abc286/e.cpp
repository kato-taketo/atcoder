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
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  vector<string> str(n);
  rep(i,n) cin >> str[i];

  vector<vector<pair<int,ll> > > vec(n, vector<pair<int,ll> >(n));  // vec[i][j] := i->j,本数,宗和
  rep(i,n) rep(j,n) {
    vec[i][j] = make_pair(2e8, -1);
  }
  vector<vector<int> > graph(n);
  rep(i,n) {
    // str[i] search
    rep(j,n) {
      if(str[i][j]=='Y') graph[i].push_back(j), vec[i][j]=make_pair(1,a[i]+a[j]);
    }
  }

  rep(i,n) {
    // start node is i
    vector<int> dist(n,-1);
    vector<ll> cost(n,-1);
    queue<int> que;
    que.push(i);
    dist[i]=0; cost[i]=a[i];
    while(!que.empty()) {
      int v = que.front();
      que.pop();
      for(auto nv: graph[v]) {
        if(dist[nv]!=-1) continue;
        dist[nv]=dist[v]+1;
        cost[nv]=cost[v]+a[nv];
        que.push(nv);
        if(vec[v][nv].first>dist[nv]) vec[v][nv] = make_pair(dist[nv],cost[nv]);
        else if(vec[v][nv].first==dist[nv]&&vec[v][nv].second<cost[nv]) 
        
      }
    }
  }

  int q;
  cin >> q;
  rep(i,q) {
    int u,v;
    cin >> u >> v;
    u--, v--;
    if(vec[u][v].first==2e8) cout << "Impossible" << endl;
    else cout << vec[u][v].first <<" " << vec[u][v].second <<  endl;
  }
}