#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007
using P = pair<ll,int>;

int main(void) {
  int N,M;
  cin >> N >> M;
  vector<int> A(N);
  rep(i,N) cin >> A[i];
  vector<int> U(M),V(M);
  rep(i,M) cin >> U[i] >> V[i];

  // make graph
  vector<vector<int> > graph(N);
  vector<ll> costs(N,0);  //cost[i] := 頂点iから辺を辿ってかかるコスト
  rep(i,M) {
    U[i]--, V[i]--;
    graph[U[i]].push_back(V[i]);
    graph[V[i]].push_back(U[i]);
    costs[U[i]] += A[V[i]];
    costs[V[i]] += A[U[i]];
  }

  // 貪欲砲
  int cnt=0;
  vector<bool> looked(N,false);
  priority_queue<P,vector<P>,greater<P> > que;  //cost, node
  rep(i,N) que.push(P(costs[i],i));
  ll res=-1;
  while(1) {
    // 頂点削除回数
    ll cost; int node;
    cost = que.top().first;
    node = que.top().second;
    que.pop();
    if(looked[node]) continue;
    else looked[node]=true, cnt++;
    res = max(res, cost);

    // 他の頂点コストの更新
    for(auto nv: graph[node]) {
      costs[nv] -= A[node];
      que.push(P(costs[nv], nv));
    }

    if(cnt==N) break;
  }
  cout << res << endl;


}