// Bellman-Ford SSSP
/* latex
\vspace{4pt}
\noindent
\begin{tabular}{ll}
  \hline
  \textbf{Time} & \textbf{Space} \\ \hline
  $\bigO(VE)$ & $\bigO(V+E)$ \\
  \hline
\end{tabular}
*/
const int inf = 0x3f3f3f3f;
vector<vector<ii>> adj(M);
vi dist(M, inf);

void bellmanFord(int n) {
	for (int i = 0; i < n-1; ++i)
		for (int v = 0; v < n; ++v)
			for (auto &[u, w]: adj[v])
				if (dist[v] != inf)
					dist[u] = min(dist[u], dist[v]+w);
}

//check if there are negative cycles
bool cycle(int n) {
	bool ans = false;
	for (int v = 0; v < n; ++v)
		for (auto &[u, w]: v)
			ans |= dist[v] != inf && dist[u] > dist[v]+w;
}
