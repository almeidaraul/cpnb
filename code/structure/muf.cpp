// Merge/Disjoint Union-Find
// Usage: muf(N);
// Status: tested (UVA11503)
// O(Ackermann * N) time, O(N) space

struct muf {
	int N;
	vector<int> par, rk, count;

	muf(int N) : N(N), par(N), rk(N, 0), count(N, 1) {
    for (int i = 0; i < N; ++i)
      par[i] = i;
	}

	int findSet(int i) {
		return par[i] == i ? i : (par[i] = findSet(par[i]));
	}
	
	int unionSet(int a, int b) {
		int x = findSet(a), y = findSet(b);
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

	bool isSameSet(int i, int j) {
		return findSet(i) == findSet(j);
	}
};
