#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int N;
int l=0, r=0;
string S,res="";
int main(void) {
  cin >> N >> S;
  res="";
  rep(i,N) {
    if(S[i]==')') {
      r++;
      res = res + ')';
      if(r>l) {
        res = '(' + res;
        r--;
      }
    } else {
      l++;
      res = res + '(';
    }
  }
  if(l-r>0) {
    rep(i,l-r) res = res + ')';
  }
  cout << res << endl;
}