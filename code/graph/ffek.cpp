// FFEK MaxFlow
/* latex
\vspace{4pt}
\noindent
\begin{tabular}{ll}
  \hline
  \textbf{Time} & \textbf{Space} \\ \hline
  $\bigO(VE^2)$ & $\bigO(V+E)$ \\
  \hline
\end{tabular}
*/

vector<vi> capacity(M, vi(M, 0)), adj(M);
vector<ii> mc; //mincut edges

int bfs(int s, int t, vi &par) {
	fill(all(par), -1);
	par[s] = -2;
	queue<ii> q; q.push({s, inf});
	while (!q.empty()) {
		int v = q.front().first,
				flow = q.front().second;
		q.pop();
		for (auto u: adj[v])
			if (par[u] == -1 && capacity[v][u]) {
				par[u] = v;
				int new_flow = min(flow, capacity[v][u]);
				if (u == t) return new_flow;
				q.push({u, new_flow});
			}
	}
	return 0;
}

int maxflow(int s, int t) {
	int flow = 0;
	vi par(M);
	int new_flow;
	while ((new_flow = bfs(s, t, par))) {
		flow += new_flow;
		int v = t;
		while (v != s) {
			int p = par[v];
			capacity[p][v] -= new_flow;
			capacity[v][p] += new_flow;
			v = p;
		}
	}
	return flow;
}

void mincut(int s, int t) {
	maxflow(s, t);
	stack<int> st;
	vector<bool> visited(n, false);
	vector<ii> ans;
	st.push(s); // changed from 0 to s
	while (!st.empty()) {
		int v = st.top(); st.pop();
		if (visited[v]) continue;
		visited[v] = true;
		for (auto u: adj[v])
			if (capacity[v][u] > 0)
				st.push(u);
			else
				ans.push_back({v, u});
	}
	mc.clear();
	for (auto &[v, u] : ans)
		if (!visited[u])
			mc.push_back({v, u});
}
