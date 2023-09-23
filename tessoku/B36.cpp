#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int main(void) {
  int n,k;
  cin >> n >> k;
  string s;
  cin >> s;

  int num=0;
  rep(i,s.length()) if(s[i]=='1') num++;
  if((k-num)%2==0) cout << "Yes" << endl;
  else cout << "No" << endl;
}