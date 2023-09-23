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

  vector<vector<int> > graph(n);
  rep(i,m) {
    int a,b;
    cin >> a >> b;
    a--; b--;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  int num=-1;
  rep(i,n) num = max(num, (int)graph[i].size());
  rep(i,n) if(graph[i].size()==num) {cout << i+1 << endl; return 0; }
}