// Coin Combinations II
/* latex
Given money system of $n$ coins $c_i > 0$.
How many distinct \textbf{ordered} ways to produce
sum $x$ using these coins?
(use each one as many time as you want,
order doesn't matter i.e. $2+2+5 = 2+5+2$)
*/
int n, x;
cin >> n >> x;
vector<int> c(n);

for (auto &i: c)
  cin >> i;

vector<int> dp(x+1);
const int M = 1000000007;

dp[0] = 1;
for (int k: c)
  for (int j = k; j <= x; ++j)
    dp[j] = (dp[j] + dp[j-k]) % M;

cout << dp[x] << '\n';
