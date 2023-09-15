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
vector<int> d(MAXN, oo);

void dijkstra(int s) {
	priority_queue<wv, vector<wv>, greater<wv>> pq;
  pq.emplace(d[s] = 0, s);
  add(s, 0);
	while (!pq.empty()) {
    auto [w, v] = pq.top(); pq.pop();
		if (w > dist[v]) continue;
    for (auto [x, u] : g[v])
      if (w+x < d[u])
        pq.emplace(d[u]=w+x, u);
	}
}
