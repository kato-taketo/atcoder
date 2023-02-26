#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, T, A[100009], B[100009];
int Answer[100009];

vector<int> G[100009];
bool visited[100009];

int dfs(int pos) {
  visited[pos]=true;
  Answer[pos]=0;

  for(int i=0; i<G[pos].size(); i++) {
    int nex=G[pos][i];
    if (visited[nex]==false) {
      int ret=dfs(nex);
      Answer[pos]=max(Answer[pos],ret+1);
    }
  }
  return Answer[pos];
}

int main() {
  cin >> N >> T;
  for (int i=1; i<=N-1; i++) {
    cin >> A[i] >> B[i];
    G[A[i]].push_back(B[i]);
    G[B[i]].push_back(A[i]);
  }
  dfs(T);

  for(int i=1; i<=N; i++) {
    if(i>=2) cout << " ";
    cout << Answer[i];
  }
  cout << endl;
  return 0;
}