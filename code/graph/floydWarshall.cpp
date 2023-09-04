// Floyd Warshall APSP
/* latex
\vspace{4pt}
\noindent
\begin{tabular}{lll}
  \hline
  \textbf{Time} & \textbf{Space} & \textbf{Usage} \\ \hline
  $\bigO(V^3 + E)$ & $\bigO(V^2+E)$ & \texttt{FloydWarshall(n, edges)} \\
  \hline
\end{tabular}
*/
struct edge { int v, u, w; };
const int inf = 0x3f3f3f3f;
vector<vector<int>> weight(M, vector<int>(M, inf));
vector<edge> edges;

void floydWarshall(int n) {
	for (auto e: edges)
		weight[e.v][e.u] = e.w;
	for (int k = 0; k < n; ++k)
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (max(weight[i][k], weight[k][j]) < inf)
					weight[i][j] = min(weight[i][j], weight[i][k]+weight[k][j]);
}
