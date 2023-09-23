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
  vector<int> a(N);
  rep(i,N) cin >> a[i];

  int res=a[N-1];
  for(int i=0; i<2; i++) {
    int index = lower_bound(a.begin(), a.end(), a[N-1]/2)-a.begin();
    int s=a[index];
    if((a[N-1]+a[0])/2 > s) continue;
    //printf("s = %d\n", s);
    rep(j,N) {
      a[j]=2*s-a[j];
    }
    sort(a.begin(), a.end());
    res = min(res, a[N-1]);
  }
  cout << res << endl;
}