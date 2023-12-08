#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int main(void) {
  int N;
  cin >> N;
  vector<pair<int,int> > ab(N);
  rep(i,N) cin >> ab[i].first;
  rep(i,N) cin >> ab[i].second;

  sort(ab.begin(),ab.end());
  vector<int> B(N);
  rep(i,N) B[i]=ab[i].second;
  vector<int> dp;
  rep(i,N) {
    auto iter = lower_bound(dp.begin(),dp.end(),B[i])-dp.begin();
    if(iter>=dp.size()) {
      dp.push_back(B[i]);
    } else {
      dp[iter]=B[i];
    }
  }
  cout << N + dp.size() << endl;
}