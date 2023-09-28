// Articulations and Bridges
/* latex
\vspace{4pt}
\noindent
\begin{tabular}{ll}
  \hline
  \textbf{Time/Space} & \textbf{Usage} \\ \hline
  $\bigO(V+E)$ & \texttt{dfs(src, -1)} \\
  \hline
\end{tabular}
*/

int tk = 0;
vi tin(M, -1);
vector<vi> adj(M);

void dfs(int v, int p) {
	tin[v] = low[v] = tk++;
	int children = 0;
	for (auto u: adj[v]) {
		if (u == p) continue;
		else if	(tin[u] == -1) {
			++children;
			dfs(u, v);
			if (low[u] >= tin[v] && p != v)
				; //articulation point
			if (low[u] > tin[v])
				; //bridge u-v
			low[v] = min(low[v], low[u]);
		} else {
			low[v] = min(low[v], tin[u]);
		}
	}
}
