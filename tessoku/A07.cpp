#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int main(void) {
  int d,n;
  cin >> d >> n;
  vector<int> l(n),r(n);
  rep(i,n) cin >> l[i] >> r[i];

  vector<int> days(d+2,0);
  rep(i,n) {
    days[l[i]]++;
    days[r[i]+1]--;
  }
  rep(i,d+1) days[i+1] += days[i];
  rep2(i,1,d+1) cout << days[i] << endl;

}