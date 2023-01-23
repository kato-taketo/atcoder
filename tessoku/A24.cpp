#include <iostream>
#include <algorithm>
using namespace std;

int N, A[100009], dp[100009];
int LEN=0, L[100009];

int main() {
  cin >> N;
  for(int i=1; i<=N; i++) cin >> A[i];

  for(int i=1; i<=N; i++) {
    int pos = lower_bound(L+1, L+LEN+1, A[i]) - L;
    printf("pos : %d\n", pos);
    dp[i] = pos;

    L[dp[i]] = A[i];
    if (dp[i] > LEN) LEN += 1;
  }

  cout << LEN << endl;
}