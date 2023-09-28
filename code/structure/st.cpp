// Segment Tree
/* latex
\vspace{4pt}
\noindent
\begin{tabular}{llll}
  \hline
  \textbf{Build} & \textbf{Query} & \textbf{Modify} & \textbf{Usage} \\ \hline
  $\bigO(n\log n)$ & $\bigO(\log n)$ & $\bigO(\log n)$ & \texttt{stree(n)} \\
  \hline
\end{tabular}
*/
struct stree {
	int n;
	vi st, v;
	
	stree(vi v): n(v.size()), st(4*n), v(v) {
    build(1, 0, n-1); }
	}

	int left(int i) { return i<<1; }
	int right(int i) { return (i<<1)+1; }

	void build(int p, int pl, int pr) {
    if (pl == pr) {
      st[p] = v[pl];
      return;
    }
    int m = (pl+pr)/2;
    build(left(p), pl, m);
    build(right(p), m+1, pr);
    st[p] = min(st[left(p)], st[right(p)]);
	}

	int query(int p, int pl, int pr, int ql, int qr) {
    // same params as update, except [ql..qr] is the query range
    if (qr < pl || ql > pr) return inf;
    if (ql <= pl && pr <= qr) return st[p];
    int m = (pl+pr)/2;
    int query_left = query(left(p), pl, m, ql, qr);
    int query_right = query(right(p), m+1, pr, ql, qr);
    return min(query_left, query_right);
  }

	int query(int ql, int qr) { return query(1, 0, n-1, ql, qr); }

	void update(int p, int pl, int pr, int i, int x) {
    // p = st idx, corresponds to range [pl..pr]
    if (i < pl || i > pr) return;
    if (pl == pr) {
      st[p] = x;
      return;
    }
    int m = (pl+pr)/2;
    update(left(p), pl, m, i, x);
    update(right(p), m+1, pr, i, x);
    st[p] = min(st[left(p)], st[right(p)]);
	}

	void update(int i, int x) { update(1, 0, n-1, i, x); }
};
