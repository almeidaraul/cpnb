// Articulations and Bridges
// Usage: dfs(source, -1)
// Status: not tested
// O(V+E) time & space

int tk = 0;
vector<int> tin(M, -1);
vector<vector<int>> adj(M);

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
