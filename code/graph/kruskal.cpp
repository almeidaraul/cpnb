// Kruskal MST
/* latex
\vspace{4pt}
\noindent
\begin{tabular}{ll}
  \hline
  \textbf{Time} & \textbf{Space} \\ \hline
  $\bigO(E\log V)$ & $\bigO(V+E)$ \\
  \hline
\end{tabular}
*/
vector<edg> edges; // peso, u, v
UnionFind muf;

pair<ll, vector<edg>> kruskal(int n) { // n = #vertices
  vector<edg> mst;
	ll cost = 0; sort(all(edg));
  for (auto [w, u, v] : edges)
		if (!muf.isSameSet(u, v)) {
      mst.emplace_back(w, u, v);
			cost += w;
			muf.unionSet(u, v);
		}
	return {cost, mst};
}
