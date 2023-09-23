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
  vector<int> a(n);
  rep(i,n) cin >> s[i] >> a[i];

  int min_index=-1, min_value=2e9;
  rep(i,n) if(min_value>a[i]) min_value=a[i], min_index=i;
  for(int i=min_index; i<n; i++) cout << s[i] << endl;
  for(int i=0; i<min_index; i++) cout << s[i] << endl;
}