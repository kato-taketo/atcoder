#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

bool check(ll x) {
  int s1,s2,s5,s6,s7,s9;
  s1 = (x%1000000000) / 100000000;
  s2 = (x%100000000) / 10000000;
  s5 = (x%100000) / 10000;
  s6 = (x%10000) / 1000;
  s7 = (x%1000) / 100;
  s9 = (x%10) / 1;
  if(s1==s2&&s5==s6&&s7==s9) return true;
  else return false;
}
int main(void) {
  int n;
  cin >> n;
  ll num=100000000;
  while(1) {
    if(check(num)) n--;
    if(n==0) {
      cout << num << endl; return 0;
    }
    num++;
  }
} 