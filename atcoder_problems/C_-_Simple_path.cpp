// AC

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int main(void) {
  int N,X,Y;
  cin >> N >> X >> Y;
  vector<int> U(N-1), V(N-1);
  rep(i,N-1) cin >> U[i] >> V[i];

  // make graph
  vector<vector<int> > graph(N);
  rep(i,N-1) {
    U[i]--, V[i]--;
    graph[U[i]].push_back(V[i]);
    graph[V[i]].push_back(U[i]);
  }
  X--, Y--;
  vector<int> pre(N,-1);
  queue<int> que;
  que.push(X);
  while(!que.empty()) {
    int v = que.front();
    que.pop();
    for(auto nv: graph[v]) {
      if(pre[nv]!=-1) continue;
      else pre[nv]=v;
      que.push(nv);
    }
  }
  deque<int> deq;
  int index=Y;
  while(1) {
    deq.push_front(pre[index]);
    index = pre[index];
    if(index==X) break;
  }
  rep(i,deq.size()) {
    /*if(i!=deq.size()-1) */printf("%d ", deq[i]+1);
    //else printf("%d\n", deq[i]+1);
  }
  printf("%d\n", Y+1);
}