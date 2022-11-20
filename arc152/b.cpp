// 数学的な根拠ないがAC

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007
#define inf 5e9

int main(void) {
  int N, L;
  cin >> N >> L;
  vector<int> a(N);
  rep(i,N) cin >> a[i];

  ll res = inf;
  rep(i,N) {
    // a[i]をstartに起用する
    ll crush;
    crush = 2*L - (a[i]+L);
    // 二分探索でcrushに最も近いa[i]を探す
    ll index, point, add;
    index = lower_bound(a.begin(), a.end(), crush)-a.begin();
    if(index==a.size()) index=a.size()-1;
    point = a[index];
    add = abs(crush-point);
    if(index!=0 && add>abs(crush-a[index-1])) add=abs(crush-a[index-1]);
    res = min(res, add*2+2*L);
  }
  cout << res << endl;
}