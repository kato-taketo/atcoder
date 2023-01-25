#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int main(void) {
  int x,y;
  cin >> x >> y;
  
  vector<int> xs,ys;
  xs.push_back(x); ys.push_back(y);
  while(!(xs[xs.size()-1]==1&&ys[ys.size()-1]==1)) {
    int index=xs.size()-1;
    if(xs[index]>ys[index]) {
      xs.push_back(xs[index]-ys[index]);
      ys.push_back(ys[index]);
    } else {
      xs.push_back(xs[index]);
      ys.push_back(ys[index]-xs[index]);
    }
  }
  reverse(xs.begin(),xs.end());
  reverse(ys.begin(),ys.end());
  cout << xs.size()-1 << endl;
  rep(i,xs.size()) {
    if(i==0) continue;
    cout << xs[i] << " " << ys[i] << endl;
  }


}