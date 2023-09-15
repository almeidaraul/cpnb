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
using edge = tuple<ll, int, int>; // peso, u, v
vector<edge> edges;
UnionFind muf;

pair<ll, vector<edge>> kruskal(int n) { // n = #vertices
  vector<edge> mst;
	ll cost = 0; sort(all(edges));
  for (auto [w, u, v] : edges)
		if (!muf.isSameSet(u, v)) {
      mst.emplace_back(w, u, v);
			cost += w;
			muf.unionSet(u, v);
		}
	return {cost, mst};
}
