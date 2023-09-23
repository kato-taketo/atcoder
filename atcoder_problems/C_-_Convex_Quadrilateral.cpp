//wa used a lot of time
// 方針は合っている。対角線に対して異なる側にあるかの判定

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

using P = pair<int,int>;
bool check_sub(int o, int p, int q, int r, vector<P> vec, bool key) {
  int d;
  // check this is totu or not
  if(vec[o].first==vec[p].first) {
    // x = vec[o].first
    d=vec[o].first;
    if((vec[q].first-d)*(vec[r].first-d)>0) key=false; 
  } else if(vec[o].second==vec[p].second) {
    // y = vec[o].second
    d = vec[o].second;
    if((vec[q].second-d)*(vec[r].second-d)>0) key=false;
  } else {
    float left,right;
    float b2=vec[p].second, b1=vec[o].second;
    float a2=vec[p].first, a1 = vec[o].first;
    float x1=vec[q].first, y1=vec[q].second;
    float x2=vec[r].first, y2=vec[r].first;
    left = y1 - ((b2-b1)*x1 + (b1*a2-b2*a1))/(a2-a1);
    right = y2 - ((b2-b1)*x2 + (b1*a2-b2*a1))/(a2-a1);
    if(left*right>0) key=false;
  }
  return key;
}
bool check(vector<P> vec) {
  bool key=true;
  key = check_sub(0,2,1,3,vec,key);
  key = check_sub(1,3,0,2,vec,key);
  return key;
}
int main(void) {
  vector<P> vec(4);
  rep(i,4) cin >> vec[i].first >> vec[i].second;

  // make sure 
  if(check(vec)) cout << "Yes" << endl;
  else cout << "No" << endl;
}