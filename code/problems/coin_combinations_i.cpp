// Coin Combinations I
/* latex
Given money system of $n$ coins $c_i > 0$.
How many ways to produce sum $x$ using these coins?
(use each one as many time as you want,
order matters i.e. $2+2+5 \neq 2+5+2$)
*/
int n, x;
cin >> n >> x;
vector<int> c(n);
for (auto &i : c)
  cin >> i;
const int M = int(1e9)+7;
vector<int> ans(x+1);
ans[0] = 1;
for (int i = 1; i <= x; ++i)
  for (int ci : c)
    if (ci <= i)
      ans[i] = (ans[i] + ans[i-ci]) % M;
cout << ans[x] << '\n';
