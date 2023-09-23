#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int N, M, A[100009], B[100009];
vector<int> G[100009];
bool visited[100009];
stack<int> Path, Answer;

void dfs(int pos) {
  if (pos == N) {
    Answer = Path; return ;
  }
  visited[pos] = true;
  for (int i=0; i<G[pos].size(); i++) {
    int nex = G[pos][i];
    if(visited[nex] == false) {
      Path.push(nex);
      dfs(nex);
      Path.pop();
    }
  }
  return ;
}
int main(void) {
  cin >> N >> M;
  for (int i=1; i<= M; i++) {
    cin >> A[i] >> B[i];
    G[A[i]].push_back(B[i]);
    G[B[i]].push_back(A[i]);
  }

  for (int i=1; i<=N; i++) visited[i] = false;
  Path.push(1);
  dfs(1);

  vector<int> Output;
  while(!Answer.empty()) {
    Output.push_back(Answer.top());
    Answer.pop();
  }
  reverse(Output.begin(), Output.end());

  for (int i=0; i<Output.size(); i++) {
    if (i >= 1) cout << " ";
    cout << Output[i];
  }
  cout << endl;
}