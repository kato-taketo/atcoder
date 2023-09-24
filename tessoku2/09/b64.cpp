#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007
ll N,M;
ll A[100009],B[100009],C[100009];
//グラフ、最短距離
ll dist[100009],dist1[100009],distn[100009];
vector<pair<int,ll> > G[100009];
void dijkstra(int stt) {
  priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > > Q;
  for(int i=1;i<=N;i++) dist[i]=(1LL<<60);
  dist[stt]=0;
  Q.push(make_pair(0,stt));
  while(!(Q.empty())) {
    int pos=Q.top().second; Q.pop();
    rep(i,G[pos].size()) {
      int to = G[pos][i].first;
      ll cost = G[pos][i].second;
      if(dist[to]>dist[pos]+cost) {
        dist[to]=dist[pos]+cost;
        Q.push(make_pair(dist[to],to));
      }
    }
  }
}
vector<int> a,b,c;
int main(void) {
  cin >> N >> M;
  a.resize(M); b.resize(M), c.resize(M);
  rep(i,M) cin >> a[i] >> b[i] >> c[i];
  rep(i,M) {
    G[a[i]].push_back(make_pair(b[i],c[i]));
    G[b[i]].push_back(make_pair(a[i],c[i]));
  }
  dijkstra(1);
  vector<int> ans;
  int pos = N;
  while(pos != 1) {
    ans.push_back(pos);
    for (auto nv : G[pos]) {
      if(dist[pos] - dist[nv.first] == nv.second) {
        pos = nv.first;
      }
    }
  }
  ans.push_back(1);
  reverse(ans.begin(), ans.end());
  rep(i,ans.size()) {
    if(i==ans.size()-1) cout << ans[i] << endl;
    else cout << ans[i] << " ";
  }
}