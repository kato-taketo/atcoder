#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

bool check(int hh[2], int mm[2]) {
  bool key=true;
  int nhh[2],nmm[2];
  nhh[0]=hh[0]; nhh[1]=mm[0];
  nmm[0]=hh[1]; nmm[1]=mm[1];
  if((nhh[0]==2 && nhh[1]>3) || nhh[0]>=3) key=false;
  if(nmm[0]>=6) key=false;
  return key;
}
int main(void) {
  int h,m;
  cin >> h >> m;

  int hh[2], mm[2];
  if(h<10) hh[0]=0,hh[1]=h;
  else hh[0]=h/10, hh[1]=h%10;
  if(m<10) mm[0]=0,mm[1]=m;
  else mm[0]=m/10, mm[1]=m%10;

  while(1) {
    if(h<10) hh[0]=0,hh[1]=h;
    else hh[0]=h/10, hh[1]=h%10;
    if(m<10) mm[0]=0,mm[1]=m;
    else mm[0]=m/10, mm[1]=m%10;
    if(check(hh, mm)) {
      printf("%d %d\n", h,m); return 0;
    }
    m++;
    if(m>=60) h++, m=0;
    if(h>=24) h=0;
    //printf("%d %d\n", h,m);
  }

}