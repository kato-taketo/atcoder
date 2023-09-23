#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int n,m;
vector<vector<int> > graph;
vector<bool> used;
vector<int> res;
void ans() {
  rep(i,res.size()) {
    if(i!=res.size()-1) printf("%d ", res[i]+1);
    else printf("%d\n", res[i]+1);
  }
}
void func(int pos) {
  used[pos]=true;
  if(pos==n-1) {
    ans(); return;
  }
  for (auto nv : graph[pos]) {
    if(used[nv]) continue;
    res.push_back(nv);
    func(nv);
  }
  res.pop_back();
}
int main(void) {
  
  cin >> n >> m;
  graph.resize(n);
  used.resize(n,false);
  rep(i,m) {
    int a,b;
    cin >> a >> b;
    a--; b--;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  //bfs
  int pos=0;
  
  res.push_back(0);
  func(pos);
}