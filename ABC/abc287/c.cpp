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
  vector<int> u(m),v(m);
  rep(i,m) cin >> u[i] >> v[i];

  // bfsで全探索できる。
  vector<vector<int> > G(n);
  rep(i,m) {
    G[u[i]-1].push_back(v[i]-1);
    G[v[i]-1].push_back(u[i]-1);
  }
  vector<int> dist(n,-1);
  queue<int> que;
  que.push(0);
  dist[0]=0;
  while(!que.empty()) {
    int v=que.front();
    que.pop();
    for (auto nv : G[v]) {
      if(dist[nv]!=-1) continue;
      dist[nv] = dist[v]+1;
      que.push(nv);
    }
  }
  rep(i,n) if(dist[i]==-1) {
    cout << "No" << endl; return 0;
  }

  vector<int> cnt(n,0);
  rep(i,m) {
    u[i]--; v[i]--;
    cnt[u[i]]++; cnt[v[i]]++;
  }
  int cnt_1=0, cnt_2=0;
  rep(i,n) {
    if(cnt[i]>2 || cnt[i]==0) {
      cout << "No" << endl; return 0;
    } else if(cnt[i]==1) cnt_1++;
    else if(cnt[i]==2) cnt_2++;
  }
  if(cnt_1==2&&cnt_2==n-2) {
    cout << "Yes" << endl; return 0;
  } else {
    cout << "No" << endl; 
  }
}