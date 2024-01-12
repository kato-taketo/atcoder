#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int N,res;
vector<string> S;
int main(void) {
  cin >> N;
  S.resize(N);
  rep(i,N) cin >> S[i];

  rep(i,N) {
    int index=-1;
    rep(j,N) {
      if(S[i][j]=='.') index=j;
    }
    if(index==-1) continue;
    else res++;
    if(i!=N-1) {
      for(int j=index; j<N; j++) S[i+1][j]='o';
    }
  }
  cout << res << endl;
}