// Convex Hull (Monotone)
vector<pt> convex_hull(vector<pt>& ps, bool col = false) {
  int k = 0, n = ps.size(); vector<pt> ans (2*n);
  sort(ps.begin(), ps.end(), [](pt a, pt b) {
    return make_pair(a.px, a.py) < make_pair(b.px, b.py);
  });
  for (int i = 0; i < n; i++) {
    while (k >= 2 && !ccw( /* lower hull */
        ans[k-2], ans[k-1], ps[i], col)) { k--; }
    ans[k++] = ps[i];
  }
  if (k == n) { ans.resize(n); return ans; }
  for (int i = n-2, t = k+1; i >= 0; i--) {
    while (k >= t && !ccw( /* upper hull */
        ans[k-2], ans[k-1], ps[i], col)) { k--; }
    ans[k++] = ps[i];
  }
  ans.resize(k-1); return ans;
}

// with answer as idx of points
using pti = pair<pt, int>;
#define fi first
#define se second
vector<int> convex_hull(vector<pti>& ps, bool col = false) {
  int k = 0, n = ps.size(); vector<int> ans (2*n);
  sort(ps.begin(), ps.end(), [](pti a, pti b) {
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
