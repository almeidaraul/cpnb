// Dijkstra SSSP
/* latex
\vspace{4pt}
\noindent
\begin{tabular}{ll}
  \hline
  \textbf{Time} & \textbf{Space} \\ \hline
  $\bigO((V+E)\log V)$ & $\bigO(V^2)$ \\
  \hline
\end{tabular}
*/

using ii = pair<int, int>;
const int inf = 0x3f3f3f3f;
vector<vector<ii>> adj(M);
vector<int> dist(M, inf), par(M, -1);

void dijkstra(int s) {
	dist[s] = 0;
	priority_queue<ii, vector<ii>, greater<pair<int, int>>> pq;
	pq.push(make_pair(0, s));
	while (!pq.empty()) {
		int w = pq.top().first;
		int v = pq.top().second;
		pq.pop();
		if (w > dist[v]) continue;
		for (auto &[d, u]: adj[v])
			if (dist[v] != inf && dist[v]+d < dist[u]) {
				par[u] = v;
				dist[u] = dist[v]+d;
				pq.push(make_pair(dist[u], u));
			}
	}
}
