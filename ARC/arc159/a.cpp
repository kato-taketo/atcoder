#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int main(void) {
  int n,k;
  cin >> n >> k;
  vector<vector<int> > a(n+1,vector<int>(n+1));
  rep2(i,1,n+1) {
    rep2(j,1,n+1) cin >> a[i][j];
  }
  int q;
  cin >> q;
  vector<ll> s(q),t(q);
  rep(i,q) cin >> s[i] >> t[i];

  // make a graph
  vector<vector<int> > graph(n+1);
  rep2(i,1,n+1) {
    rep2(j,1,n+1) if(a[i][j]==1) graph[i].push_back(j);
  }

  // search
  rep(i,q) {
    ll start=s[i]%n, goal=t[i]%n;
    if(start==0) start=n;
    if(goal==0) goal=n;
    // bfs
    vector<int> dist(n+1,-1);
    queue<int> que;
    int cnt=0;
    dist[start]=0;
    que.push(start);
    while(!que.empty()) {
      int v=que.front();
      que.pop();
      if(v==start&&cnt==0) dist[v]=-1,cnt++; // startへ戻る可能性あり
      for(auto nv:graph[v]) {
        if(dist[nv]!=-1) continue;
        if(v==start&&cnt==1) dist[nv]=1; // startから
        else dist[nv]=dist[v]+1;
        que.push(nv);
      }
    }
    cout << dist[goal] << endl;
    dist.clear();
    //que.clear();
  }

}