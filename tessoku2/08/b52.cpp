// 17:36~44

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int N, X;
string A;
int main(void) {
  cin >> N >> X;
  cin >> A;

  queue<int> que;
  que.push(X-1);
  A[X-1] = '@';
  while(!que.empty()) {
    int pos = que.front();
    que.pop();
    if(pos-1 >=0 && A[pos-1]=='.') {
      A[pos-1] = '@'; que.push(pos-1);
    }
    if(pos+1 <A.size() && A[pos+1] == '.') {
      A[pos+1] = '@'; que.push(pos+1);
    }
  }
  cout << A << endl;
}