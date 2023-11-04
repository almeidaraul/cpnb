// Sparse Table
/* latex
\vspace{4pt}
\noindent
\begin{tabular}{ll}
  \hline
  \textbf{Build} & \textbf{Query} \\ \hline
  $\bigO(n\log n)$ & $\bigO(\log n)$ RSQ, $\bigO(1)$ RMQ \\
  \hline
\end{tabular}

Min in $\bigO(1)$, others in $\bigO(\log)$
*/
const int L = lg2_floor(maxn)+1;
vector<vi> st(L, vi(maxn));

void build(vector<int>& v) {
  copy(all(v), st[0].begin());
  rep(i,0,L-1)
    rep(j,0,n) {
      st[i+1][j] = st[i][j];
      if (j+(1<<i) < n)
        st[i+1][j] = min(st[i+1][j], st[i][j+(1<<i)]);
    }
}

int rmq(int l, int r) {  // rmq [l, r]
  int lg = lg2_floor(r-l+1);
  return min(st[lg][l], st[lg][r-(1<<lg)+1]);
}
