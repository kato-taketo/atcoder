#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int main(void) {
  //vector<int> a(5),b(5),c(5);
  int a[] = {30,15,27,20,40};
  int b[] = {25, 10, 23, 18, 27};
  int c[] = {20, 15, 11, 25, 5};
  vector<int> num(5);
  int teika[]={3600, 3000, 2600, 2000, 3600};
  int sale_num[]={20, 3, 5, 7, 8};
  vector<int> uriage(5);
  int genka[]={1600, 1500, 1000, 1200, 2000};
  vector<int> rieki(5);


  rep(i,5) num[i] = a[i]+c[i]-b[i];
  rep(i,5) {
    if(i==0) cout << num[i];
    else cout << " " << num[i];
  }
  cout << endl;

  rep(i,5) uriage[i]=teika[i]*(num[i]-sale_num[i])+teika[i]*sale_num[i]/2;
  rep(i,5) {
    if(i==0) cout << uriage[i];
    else cout << " " << uriage[i];
  }
  cout << endl;

  rep(i,5) rieki[i]=uriage[i]-num[i]*genka[i];
  rep(i,5) {
    if(i==0) cout << rieki[i];
    else cout << " " << rieki[i];
  }
  cout << endl;
}