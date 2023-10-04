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
	int N;
	vi par, rk, count;

	MUF(int N) : N(N), par(N), rk(N, 0), count(N, 1) {
    rep(i,0,N)
      par[i] = i;
	}

	int find(int i) {
		return par[i] == i ? i : (par[i] = find(par[i]));
	}
	
	int merge(int a, int b) {
		int x = find(a), y = find(b);
		if (x != y)
			count[x] = count[y] = (count[x]+count[y]);
		if (rk[x] < rk[y])
			par[x] = y;
		else {
			par[y] = x;
			if (rk[x] == rk[y])
				rk[x]++;
		}
		return count[x];
	}

	bool same(int i, int j) {
		return find(i) == find(j);
	}
};
