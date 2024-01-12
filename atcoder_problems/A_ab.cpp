#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int main(void) {
  int N;
  string s;
  bool key=false;
  cin >> N;
  cin >> s;
  rep(i,N) {
    if(i!=N-1&&s[i]=='a'&&s[i+1]=='b') {
      key=true;
    } else if(i!=N-1&&s[i]=='b'&&s[i+1]=='a') {
      key=true;
    }
  }
  if(key) cout << "Yes" << endl;
  else cout << "No" << endl;
}