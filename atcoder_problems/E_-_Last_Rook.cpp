// WA

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int main(void) {
  int N;
  cin >> N;
  
  int a,b,c,d;
  a=1,b=N/2,c=1,d=N;
  int tmp=0;
  while(1) {
    printf("? %d %d %d %d\n", a,b,c,d);
    int t;
    cin >> t;
    if(t==0) break;
    if(t==b-a+1) {
      a=b+1, b=b+1+(b-a+1)/2;
      tmp += t;
    } else {
      a=a, b=a-1+(b-a+1)/2;
      tmp = tmp + ((N-1)-tmp-(b-a));
    }
    if(tmp==N-1) break;
  }
  d=N/2;
  tmp=0;
  while(1) {
    printf("? %d %d %d %d\n", a,b,c,d);
    int t;
    cin >> t;
    if(t==0) break;
    if(t==d-c+1) {
      c=d+1, d=d+1+(d-c+1)/2;
      tmp += t;
    } else {
      c=c, d=c-1+(d-c+1)/2;
      tmp = tmp + ((N-1)-tmp-(d-c));
    }
    if(tmp==N-1) break;
  }
  printf("! %d %d\n", a,c);
}