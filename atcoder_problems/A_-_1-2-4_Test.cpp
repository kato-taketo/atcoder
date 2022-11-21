// AC

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int main(void) {
  int a,b;
  cin >> a >> b;
  vector<int> vec1(3,0), vec2(3,0), num(3);
  num[0]=4, num[1]=2, num[2]=1;
  rep(i,3) {
    if(a>=num[i]) vec1[i]=1,a-=num[i];
    if(b>=num[i]) vec2[i]=1,b-=num[i];
  }
  int res=0;
  rep(i,3) {
    if(vec1[i]!=1 && vec2[i]!=1) continue;
    else res += num[i];
  }
  cout << res << endl;
}