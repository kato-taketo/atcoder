#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int main(void) {
  int M,D;
  int y,m,d;
  cin >> M >> D >> y >> m >> d;
  if(d+1>D) {
    m++; d=1;
  } else {
    d++;
  }
  if(m>M) {
    y++; m=1;
  } else {
    //m++;
  }
  cout << y << " " <<  m << " " << d << endl; 
}