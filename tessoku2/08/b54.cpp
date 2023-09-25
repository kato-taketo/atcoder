// 17:45 ~ 53

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int N;
vector<int> A;
map<int,ll> mp;
set<int> used;
ll ans=0;
int main(void) {
  cin >> N;  
  A.resize(N);
  rep(i,N) cin >> A[i];

  rep(i,N) {
    int num = used.size();
    used.insert(A[i]);
    if(num != used.size()) {
      mp[A[i]] = 1;
    } else {
      mp[A[i]]++;
    }
  }
  for (auto iter=mp.begin(); iter != mp.end(); iter++) {
    ans += iter->second * (iter->second - 1) / 2;
  }
  cout << ans << endl;
}