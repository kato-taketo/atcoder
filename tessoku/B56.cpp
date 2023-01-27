#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N, Q, L[100009], R[100009];
string S;
string SRev;

int T[100009];
int TRev[100009];

long long mod = 2147483647;
long long Power100[100009];
long long H[100009];
long long HRev[100009];

long long GetHashLeft(int l, int r) {
  long long val = H[r] - (Power100[r-l+1]*H[l-1]%mod);
  if (val<0) val += mod;
  return val;
}

long long GetHashRight(int l, int r) {
  int true_l = N+1-r;
  int true_r = N+1-l;
  long long val = HRev[true_r]-(Power100[true_r-true_l+1]*HRev[true_l-1]%mod);
  if(val<0) val += mod;
  return val;
}

int main() {
  cin >> N >> Q;
  cin >> S;
  for (int i=1; i<=Q; i++) cin >> L[i] >> R[i];
  SRev = S;
  reverse(SRev.begin(), SRev.end());

  for (int i=1; i<=N; i++) T[i] = (int)(S[i-1]-'a') +1;
  for (int i=1; i<=N; i++) TRev[i] = (int)(SRev[i-1]-'a')+1;

  Power100[0] = 1;
  for (int i=1; i<=N; i++) Power100[i] = (100LL*Power100[i-1])%mod;

  H[0]=1;
  for (int i=1; i<=N; i++) H[i]=(100LL*H[i-1]+T[i])%mod;

  HRev[0]=1;
  for (int i=1; i<=N; i++) HRev[i]=(100LL*HRev[i-1]+TRev[i])%mod;

  for (int i=1; i<=Q; i++) {
    long long v1 = GetHashLeft(L[i],R[i]);
    long long v2 = GetHashRight(L[i],R[i]);

    if (v1==v2) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
  return 0;
}