#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int main(void) {
  double A,B;
  cin >> A >> B;

  ll left=-1,right=A+1;
  while(right-left>1) {
    ll middle = left + (right-left)/2;
    double res=0;
    res += A / sqrt(1.0+(double)middle);
    res -= A / sqrt(2.0+(double)middle);
    if(res >= B) left=middle;
    else right=middle;
    //printf("left = %lld, right = %lld\n", left,right);
  }
  double res=0;
  res += (ll)B * (left+1);
  res += A / sqrt(double(left+2));
  printf("%.7lf\n", res);
}