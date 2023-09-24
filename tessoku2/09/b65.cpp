/*
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int N,T;
vector<int> a,b;
vector<vector<int> > relation;
vector<bool> used;  // 一度通った点はtrueにする
vector<vector<int> > graph;
int main(void) {
  cin >> N >> T;
  a.resize(N-1), b.resize(N-1);
  rep(i,N-1) cin >> a[i] >> b[i];

  // 方針：社長Tから近い順にグラフを作成して葉っぱの部分から階級を計算する
  // dfsで帰りがけにその深さを書き込んでいく
  relation.resize(N+1);
  used.resize(N+1,false);
  rep(i,N-1) relation[a[i]].push_back(b[i]), relation[b[i]].push_back(a[i]);
  graph.resize(N+1);
  queue<int> que;
  que.push(T);
  used[T] = true;
  while(!que.empty()) {
    int v = que.front();
    que.pop();
    for (auto nv : relation[v]) {
      if(used[nv]) continue;
      used[nv] = true;

    }

  }
}
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int N,T;
vector<int> a,b;
vector<vector<int> > graph;
//vector<int> value;
vector<bool> visited;
vector<int> Answer;

/*
  dfsは、boolのvecを置いて、巡回したかを判断する。
  for文の中には、boolで判断して、bfsを展開させて、変数を制御する
*/
int dfs(int pos) {
  visited[pos] = true;
  Answer[pos] = 0;
  int tmp = 0;
  for (auto nv :  graph[pos]) {
    if(visited[nv] == false) {
      int ret = dfs(nv);
      Answer[pos] = max(Answer[pos], ret+1);
    }
  }
  return Answer[pos];
}
int main(void) {
  cin >> N >> T;
  a.resize(N-1),b.resize(N-1);
  rep(i,N-1) cin >> a[i] >> b[i];
  graph.resize(N+1);
  //value.resize(N+1,-1);
  visited.resize(N+1, false);
  Answer.resize(N+1);
  rep(i,N-1) {
    graph[a[i]].push_back(b[i]);
    graph[b[i]].push_back(a[i]);
  }
  // 深さ優先探索
  dfs(T);
  for (int i=1; i<=N; i++) {
    if(i==N) cout << Answer[i] << endl;
    else cout << Answer[i] << " ";
  }
}