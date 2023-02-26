#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

ll N,M;
ll A[100009],B[100009],C[100009];
ll pre[100009];
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
        pre[to]=pos;
      }
    }
  }
}
int main(void) {
  cin >> N >> M;
  rep(i,M) {
    int a,b,c;
    cin >> a >> b >> c;
    G[a].push_back(make_pair(b,c));
    G[b].push_back(make_pair(a,c));
  }
  dijkstra(1);
  int x=N;
  vector<int> res;
  res.push_back(N);
  while(x!=1) {
    res.push_back(pre[x]);
    x=pre[x];
  }
  reverse(res.begin(), res.end());
  rep(i,res.size()) {
    if(i==res.size()-1) cout << res[i] << endl;
    else cout << res[i] << " ";
  }
}