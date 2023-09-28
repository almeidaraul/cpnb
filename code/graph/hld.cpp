// Heavy-Light Decomposition
/* latex
\vspace{4pt}
\noindent
\begin{tabular}{lll}
  \hline
  \textbf{Query} & \textbf{Setup} & \textbf{Update} \\ \hline
  $\bigO(\log^2n)$ & define \texttt{oper(a,b)} for query  & \texttt{rmq.upd(pos[x],v)} \\
  \hline
\end{tabular}
Queries on edges: assign values of edges to child node, then change \texttt{pos[x]} to \texttt{pos[x]+1} in query (see \texttt{!!!})
*/
vi g[MAXN];
int wg[MAXN],par[MAXN],h[MAXN]; // subtree size,father,height
void dfs1(int x){
	wg[x]=1;
	for(int y:g[x])if(y!=par[x]){
		par[y]=x;h[y]=h[x]+1;dfs1(y);
		wg[x]+=wg[y];
	}
}
int curpos,pos[MAXN],head[MAXN]; // head = representante
void hld(int x, int c){
	if(c<0)c=x;
	pos[x]=curpos++;head[x]=c;
	int mx=-1;
	for(int y:g[x])if(y!=par[x]&&(mx<0||wg[mx]<wg[y]))mx=y;
	if(mx>=0)hld(mx,c);
	for(int y:g[x])if(y!=mx&&y!=par[x])hld(y,-1);
}
void hld_init(){par[0]=-1;h[0]=0;dfs1(0);curpos=0;hld(0,-1);}
int query(int x, int y, stree& rmq){
	int r=NEUT;
	while(head[x]!=head[y]){
		if(h[head[x]]>h[head[y]])swap(x,y);
		r=oper(r,rmq.query(pos[head[y]],pos[y]+1));
		y=par[head[y]];
	}
	if(h[x]>h[y])swap(x,y); // now x is lca
	r=oper(r,rmq.query(pos[x],pos[y]+1)); // !!!
	return r;
}
