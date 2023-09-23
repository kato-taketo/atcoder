#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int main(void) {
  int n;
  cin >> n;
  vector<string> s(n);
  rep(i,n) cin >> s[i];
  int cnt=0;
  rep(i,n) if(s[i]=="For") cnt++;
  if(cnt > n/2) cout << "Yes" << endl;
  else cout << "No" << endl;
}