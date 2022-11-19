// AC

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int main(void) {
  int N,M;
  cin >> N >> M;

  vector<vector<bool> > vec(N, vector<bool>(N,false));
  rep(i,M) {
    int k;
    cin >> k;
    vector<int> x(k);
    rep(i,k) cin >> x[i], x[i]--;
    sort(x.begin(), x.end());
    rep(i,k) {
      rep2(j,i+1,x.size()) {
        vec[x[i]][x[j]]=true;
        vec[x[j]][x[i]]=true;
      }
    }
  }
  bool res=true;
  rep(i,N) {
    rep2(j,i+1,N) {
      if(vec[i][j]==false) res=false;
    }
  }
  if(res) cout <<"Yes" << endl;
  else cout << "No" << endl;
}