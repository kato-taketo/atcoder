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
  if(n<1000) cout << n << endl;
  else if(n<10000) cout << (n/10)*10 << endl;
  else if(n<100000) cout << (n/100)*100 << endl;
  else if(n<1000000) cout << (n/1000)*1000 << endl;
  else if(n<10000000) cout << (n/10000)*10000 << endl;
  else if(n<100000000) cout << (n/100000)*100000 << endl;
  else if(n<1000000000) cout << (n/1000000)*1000000 << endl;
}