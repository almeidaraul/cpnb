// Merge/Disjoint Union-Find
/* latex
\vspace{4pt}
\noindent
\begin{tabular}{lll}
  \hline
  \textbf{Time} & \textbf{Space} & \textbf{Usage} \\ \hline
  $\bigO(A\times n)$ & $\bigO(n)$ & \texttt{muf(n)} \\
  \hline
\end{tabular}
*/
struct MUF {
	int n;
	vi par, rk, sz;

	MUF(int n) : n(n), par(n), rk(n, 0), sz(n, 1) {
    rep(i,0,n)
      par[i] = i;
	}

	int find(int i) {
		return par[i] == i ? i : (par[i] = find(par[i]));
	}
	
	int merge(int a, int b) {
    a = find(a); b = find(b);
    if (a != b)
      sz[a] = sz[b] = (sz[x] + sz[y]);
		if (rk[a] < rk[b])
      swap(a, b);
    par[b] = a;
    rk[a] += rk[a] == rk[b];
		return sz[x];
	}

	bool same(int i, int j) {
		return find(i) == find(j);
	}
};
