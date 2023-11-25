// Bottom-Up Segment Tree
/* latex
\vspace{4pt}
\noindent
\begin{tabular}{llll}
  \hline
  \textbf{Build} & \textbf{Query} & \textbf{Update} & \textbf{Usage} \\ \hline
  $\bigO(n)$ & $\bigO(\log n)$ & $\bigO(\log n)$ & \texttt{Seg(n)} \\
  \hline
\end{tabular}

Uses less space than top-down $4n$ Segtree ($2n$ here)
*/
struct Seg {
  int n;
  vi t;

  Seg(vi v) : n(v.size()), t(2*n+2) {
    for (int i = 0; i < n; ++i)
      t[i+n+1] = v[i];
    for (int i = n; i; --i)
      t[i] = t[i<<1]+t[(i<<1)+1];
  }
  Seg(int sz) : n(sz), t(2*n+2) {}

  int qry(int a, int b) {
    int ans = 0;
    for (a += n, b += n; a <= b; ++a /= 2, --b /= 2) {
      if (a%2 == 1) ans += t[a];
      if (b%2 == 0) ans += t[b];
    }
    return ans;
  }

  void upd(int p, int x) {
    t[p += n] = x;
    while (p /= 2) t[p] = t[p<<1] + t[(p<<1)+1];
  }
};
