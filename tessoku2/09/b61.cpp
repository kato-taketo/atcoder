#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int main(void) {
  int n,m;
  cin >> n >> m;
  vector<int> a(m), b(m);
  rep(i,m) cin >> a[i] >> b[i];

  vector<int> cnt(n+1,0);
  rep(i,m) cnt[a[i]]++, cnt[b[i]]++;
  int num=0, index=0;
  rep(i,n+1) {
    if(num < cnt[i]) num = cnt[i], index = i;
  }
  cout << index << endl;
}