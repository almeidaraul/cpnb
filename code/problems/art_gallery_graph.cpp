// Art Gallery on Graph
/* latex
Given graph with $N \leq 2\times 10^5$ vertices, $M \leq 2\times 10^5$ edges.

$K \leq N$ security guards are on some vertices, each with a different stamina $h_i$.

Vertex $v$ is guarded if there is a guard $i$ with distance $\leq h_i$

List all guarded vertices
*/
priority_queue<pair<int, int>> pq;
vector<int> dist(n, -1);

for (int i = 0; i < k; ++i) {
  int p, h;
  cin >> p >> h;
  --p;
  pq.emplace(dist[p] = h, p);
}

while (pq.size()) {
  auto [h, p] = pq.top(); pq.pop();
  if (h != dist[p])
    continue;
  for (int &q : g[p])
    if (h-1 > dist[q])
      pq.emplace(dist[q] = h-1, q);
}

vector<int> ans;
for (int i = 0; i < n; ++i)
  if (dist[i] >= 0)
    ans.push_back(i+1);
