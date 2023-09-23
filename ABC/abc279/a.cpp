#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int main(void) {
  string S;
  cin >> S;
  int cnt=0;
  rep(i, S.length()) {
    if(S[i]=='v') cnt++;
    else if(S[i]=='w') cnt+=2;
  }
  cout << cnt << endl;
}