// MUF with distance to root
/* latex
\texttt{par[i].se} tem a distancia,
nesse caso só precisa da paridade
então usamos xor. Se quiser dist toda,
usa soma (\texttt{!!!})

\texttt{merge} retorna 1 se o componente
for bipartido
*/
struct MUF {
	int n;
  vector<ii> par;
	vi rk, bip; // bipartite check

	MUF(int n) : n(n), par(n), rk(n, 0), bip(n, 1) {
    rep(i,0,n)
      par[i] = {i,0};
	}

	ii find(int i) {
    if (par[i].fi != i) {
      int p = par[i].se;
      par[i] = find(par[i].fi);
      par[i].se ^= p; // !!!
    }
    return par[i];
	}
	
	int merge(int a, int b) {
    int x, y;
    tie(a, x) = find(a);
    tie(b, y) = find(b);
    if (a == b)
      bip[a] &= x != y;
		if (rk[a] < rk[b])
      swap(a, b);
    par[b] = {a, x^y^1}; // !!!
    bip[a] &= bip[b];
    rk[a] += rk[a] == rk[b];
		return bip[a];
	}

	bool same(int i, int j) {
		return find(i) == find(j);
	}
};
