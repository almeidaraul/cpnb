// Convex Hull (Monotone)
/* latex
$\bigO(n\log n)$, ans is vector of point indexes
*/
using pti = pair<pt, int>;
#define fi first
#define se second
vi convex_hull(vector<pti>& ps, bool col = false) {
  int k = 0, n = ps.size(); vi ans (2*n);
  sort(all(ps), [](pti a, pti b) {
    return make_pair(a.fi.px, a.fi.py) < make_pair(b.fi.px, b.fi.py);
  });
  for (int i = 0; i < n; i++) {
    while (k >= 2 && !ccw( /* lower hull */
        ps[ans[k-2]].fi, ps[ans[k-1]].fi, ps[i].fi, col)) { k--; }
    ans[k++] = i;
  }
  if (k == n) {
    ans.resize(n);
    for (auto &i : ans) i = ps[i].second;
    return ans; }
  for (int i = n-2, t = k+1; i >= 0; i--) {
    while (k >= t && !ccw( /* upper hull */
        ps[ans[k-2]].fi, ps[ans[k-1]].fi, ps[i].fi, col)) { k--; }
    ans[k++] = i;
  }
  ans.resize(k-1);
  for (auto &i : ans) i = ps[i].second;
  return ans;
}
