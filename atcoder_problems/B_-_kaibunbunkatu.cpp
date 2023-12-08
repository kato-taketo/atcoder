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
  vector<int> abc(26,0);
  int odd=0,even=0;
  priority_queue<int,vector<int>,greater<int> > pq;
  rep(i,S.length()) {
    abc[S[i]-'a']++;
  }
  rep(i,26) {
    if(abc[i]%2!=0) odd++;
  }
  even = S.size() - odd;
  even /= 2; // even is num of +2
  if(odd==0) {
    cout << S.size() << endl;
  } else {
    int r,d;
    r = even / odd;
    d = even % odd;
    cout << 1 + r * 2 << endl;
  }
}