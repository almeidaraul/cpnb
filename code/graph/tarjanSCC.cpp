// Tarjan Strongly Connected Component
/* latex
\vspace{4pt}
\noindent
\begin{tabular}{ll}
  \hline
  \textbf{Time/Space} & \textbf{Usage} \\ \hline
  $\bigO(V+E)$ & \texttt{Tarjan(n, adj)} \\
  \hline
\end{tabular}
*/

vector<int> tin(M, -1), low(M, -1);
vector<bool> vis(M);
vector<vector<int> adj(M);
stack<int> S;
int tk = 0;

void dfs(int v) {
	low[v] = tin[v] = tk++;
	S.push(v);
	vis[v] = true;
	for (auto u: adj[v]) {
		if (tin[u] == -1)
			dfs(u);
		if (vis[u])
			low[v] = min(low[v], low[u]);
	}
	if (low[v] == tin[v])
		while (true) {
			int u = S.top(); S.pop(); vis[u] = false;
			if (u == v) break;
		}
}
