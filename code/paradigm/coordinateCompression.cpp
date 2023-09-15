// Coordinate Compression
/* latex
Normalize vector access; can also be done with map/set but
high constant. $\bigO(n\log n)$ time
*/
vector<int> v, vals, cv; // all same size, cv = compressed v
vals = v;
sort(all(vals));
vals.erase(unique(all(vals)), vals.end());
for (int i = 0; i < n; ++i)
	cv[i] = lower_bound(all(vals), v[i]) - vals.begin();
