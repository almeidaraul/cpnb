// Bottom-Up Segment Tree
/* latex
\vspace{4pt}
\noindent
\begin{tabular}{llll}
  \hline
  \textbf{Build} & \textbf{Query} & \textbf{Update} & \textbf{Usage} \\ \hline
  $\bigO(n)$ & $\bigO(\log n)$ & $\bigO(\log n)$ & \texttt{seg(n)} \\
  \hline
\end{tabular}

Uses less space than top-down $4n$ segtree ($2n$ here)
*/
struct seg {
  int n;
  vi t;

  seg(vi v) : n(v.size()), t(2*n) {
    for (int i = 0; i < n; ++i)
      upd(i, v[i]);
  }
  seg(int sz) : n(sz), t(2*n) {}

  int query(int a, int b) {
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
