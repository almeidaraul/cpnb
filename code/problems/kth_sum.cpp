// Kth smallest sum
/* latex
Given an array $A$, sum at least one element, may use the
same element multiple times. Find K-th smallest possible
sum

$1 \leq N \leq 10, 1 \leq K \leq 2\times 10^5, 1 \leq A_i \leq 10^9$
*/
int n, k;
cin >> n >> k;
vector<int> a(n);
priority_queue<int, vector<int>, greater<int>> pq;
set<int> seen;
for (int &x : a) {
  cin >> x;
  if (seen.find(x) == seen.end()) {
    pq.push(x);
    seen.insert(x);
  }
}
int cnt = 0;
while (pq.size()) {
  int t = pq.top(); pq.pop();
  if (++cnt == k) {
    cout << t << '\n';
    break;
  }
  for (int x : a)
    if (seen.find(t+x) == seen.end()) {
      pq.push(t + x);
      seen.insert(t+x);
    }
}
