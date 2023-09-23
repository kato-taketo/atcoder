#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int main(void) {
  int num;
  cin >> num;
  //int num=110000000;
  num--;

  int a,b,c,x,y;
  int ans=0;
  a = num / (100*10*10*10);
  num %= (100*10*10*10);
  ans += (a+1)*100000000+(a+1)*10000000;

  x = num / (10*10*10);
  num %= (10*10*10);
  ans += x*100000;

  b = num / (10*10);
  num %= (10*10);
  ans += b*10000 + b*1000;

  c = num / 10;
  num %= 10;
  ans += c*100 + c;

  y = num;
  ans += y*10;

  cout << ans << endl;
}