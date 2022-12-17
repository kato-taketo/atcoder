#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int main(void) {
  ll n,m;
  cin >> n >> m;
  vector<ll> u(m), v(m);
  rep(i,m) cin >> u[i] >> v[i];

  vector<vector<ll> > graph(n);
  int root=-1;
  rep(i,m) {
    u[i]--; v[i]--;
    if(i==0) root=u[i];
    graph[u[i]].push_back(v[i]);
    graph[v[i]].push_back(u[i]);
  }

  bool nibu=true;
  vector<int> color(n,-1);
  queue<int> que;
  if(root!=-1) que.push(root),color[root]=0;
  while(!que.empty()) {
    int v = que.front();
    que.pop();
    for(auto nv: graph[v]) {
      //if(color[nv]!=-1) continue;
      if(color[nv]!=-1) {
        if(color[nv]==color[v]) nibu=false;
        continue;
      } 
      color[nv] = (color[v]+1)%2;
      que.push(nv);
    }
  }

  if(nibu==false) {
    cout << 0 << endl; return 0;
  }
  ll odd=0, even=0, other=0;
  rep(i,n) {
    if(color[i]==0) even++;
    else if(color[i]==1) odd++;
    else other++;
  }
  ll res=0;
  res += odd*even-m;
  //res += other*(even+odd);
  //if(other>=2) res += other*(other-1)/2;

  ll tmp=0;
    for(ll weven=0; weven<=other; weven++) {
    ll wodd = other-weven;
    tmp = max(tmp, even*wodd + odd*weven + weven*wodd);
    }
  res += tmp;
  cout << res << endl;
}