#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using ll = long long int;
int main() {
  int N;
  ll K;
  cin >> N >> K;
  vector<ll> A(N);
  priority_queue<ll,vector<ll>,greater<ll> > pq;
  for(int i=0; i<N; i++) {
    cin >> A[i];
    pq.push(A[i]);
  }
  ll loop = 0;
  for(int i=N; ; --i) {
    ll nextLoop = pq.top() - loop;
    pq.pop();
    if (nextLoop * i > K) nextLoop = K / i;
    K -= nextLoop * i;
    loop += nextLoop;
    if (K < i) break;
  }
  for (long a : A) {
    ll ans = max(0LL, a-loop);
    if(a > loop && K-- > 0LL) --ans;
    cout << ans << endl;
  }
  return 0;
}