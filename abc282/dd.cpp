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

  ll res = 0;
  bool nibu=true;
  vector<int> color(n,-1);
  queue<int> que;
  vector<ll> vec;
  //if(root!=-1) que.push(root),color[root]=0;
  for(int i=0; i<n; i++) {
    if(graph[i].size()==0 || color[i]!=-1) continue;
    else {
      ll edge=0, even=0, odd=0;
      //vector<bool> used(n,false);
      que.push(i), color[i]=0, even++;
      while(!que.empty()) {
        int v = que.front();
        que.pop();
        for(auto nv: graph[v]) {
          //if(color[nv]!=-1) continue;
          edge++;
          if(color[nv]!=-1) {
            if(color[nv]==color[v]) nibu=false;
            continue;
          } 
          color[nv] = (color[v]+1)%2;
          if(color[nv]==0) even++; else odd++;
          que.push(nv);
        }
      }
      edge /= 2;
      res += even * odd - edge;  // even and odd make 
      //res += (n-even-odd)*(even+odd);  // 
      vec.push_back(even+odd);
      //printf("edge = %d\n", edge);
    }
  }
  
  if(nibu==false) {
    cout << 0 << endl; return 0;
  }
  // add vec
  ll tmp=0;
  rep(i,vec.size()) {
    res += vec[i]*(n-vec[i]-tmp);
    tmp += vec[i];
  }
  // add only other
  ll other=0;
  rep(i,n) if(color[i]==-1) other++;
  if(other>=2) res += other * (other-1)/2;
  //ll odd=0, even=0, other=0;
  //rep(i,n) {
  //  if(color[i]==0) even++;
  //  else if(color[i]==1) odd++;
  //  else other++;
  //}
  //ll res=0;
  //res += odd*even-m;
  //res += other*(even+odd);
  //if(other>=2) res += other*(other-1)/2;
  cout << res << endl;
}