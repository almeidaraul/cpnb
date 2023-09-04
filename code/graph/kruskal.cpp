// Kruskal MST
/* latex
\vspace{4pt}
\noindent
\begin{tabular}{lll}
  \hline
  \textbf{Time} & \textbf{Space} & \textbf{Usage} \\ \hline
  $\bigO(E\log V)$ & $\bigO(V+E)$ & \texttt{Kruskal(V, E, weighted\_edges)} \\
  \hline
\end{tabular}
*/
using iii = pair<int, pair<int, int>>; //weight, two vertices
vector<iii> edges;
UnionFind muf;

int kruskal() {
	int cost = 0;
	sort(edges.begin(), edges.end());
	for (auto a: edges) {
		int w = a.first;
		pair<int, int> e = a.second;
		if (!muf.isSameSet(e.first, e.second)) {
			cost += w;
			muf.unionSet(e.first, e.second);
		}
	}
	return cost;
}
