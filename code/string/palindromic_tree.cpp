// Palindromic Tree
/* latex
árvore de palíndromos + cada letra tem um custo e vc quer maximizar
(pra tirar o custo só remover \texttt{sigmac} e \texttt{cost})

Construção $\bigO(|S|\log\Sigma)$, $S=$ sua string. Cada índice é
um nó, e cada nó representa um palíndromo diferente.

\texttt{to[i][c]} é o vértice do palíndromo $c\texttt{i}c$

\texttt{link[i]} é o vértice do maior sufixo palindrômico de $i$

\texttt{len[i]} é o tamanho do palíndromo $i$

\texttt{s[i]} é o primeiro caractere no palíndromo $i$ (isso é
altamente duvidável)
*/
int sigmac[26];

const int maxn = 5e5, sigma = 26;

int s[maxn], len[maxn], link[maxn], to[maxn][sigma], cost[maxn];

int n, last, sz;

void init()
{
    s[n++] = -1;
    link[0] = 1;
    len[1] = -1;
    cost[0] = 0;
    sz = 2;
}

int get_link(int v)
{
    while(s[n - len[v] - 2] != s[n - 1]) v = link[v];
    return v;
}

void add_letter(int c)
{
    s[n++] = c;
    last = get_link(last);
    if(!to[last][c])
    {
        int _c = len[last] == -1 ? sigmac[c] : (sigmac[c]*2);
        cost[sz] = cost[last] + _c;
        len [sz] = len[last] + 2;
        link[sz] = to[get_link(link[last])][c];
        to[last][c] = sz++;
    }
    last = to[last][c];
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  for (int i = 0; i < 26; ++i)
    cin >> sigmac[i];
  string _s;
  cin >> _s;
  init();
  for (char c : _s)
    add_letter(c-'a');
  int ans = -1e18;
  for (int i = 0; i < maxn; ++i)
    if (len[i] > 0)
      ans = max(ans, cost[i]);
  cout << ans << '\n';
}
