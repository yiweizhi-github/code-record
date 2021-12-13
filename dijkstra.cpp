int findShortestPath(int n, int m, vector<vector<int> >& graph) {
	vector<vector<int> > g(n, vector<int>(n, INT_MAX));
	vector<int> dis(n, INT_MAX);
	vector<bool> visit(n, false);
	for(int i=0;i<m;++i){
		if(g[graph[i][0]-1][graph[i][1]-1]==INT_MAX)
		    g[graph[i][0]-1][graph[i][1]-1] = graph[i][2];
		else
		    g[graph[i][0]-1][graph[i][1]-1] = std::min(g[graph[i][0]-1][graph[i][1]-1], graph[i][2]);
	}
	dis[0] = 0;
	visit[0] = true;
	for(int i=1;i<n;++i)
		dis[i] = g[0][i];
	for(int i=1;i<n;++i){
		int index = -1, min = INT_MAX;
		for(int j=0;j<n;++j){
		    if(!visit[j]&&dis[j]<min){
		        min = dis[j];
		        index = j;
		    }
		}
		if(index==-1)
			break;
		visit[index] = true;
		for(int j=0;j<n;++j)
		    if(!visit[j]&&g[index][j]!=INT_MAX)//加一个g[index][j]!=INT_MAX条件判断，因为如果g[index][j]为INT_MAX直接相加会溢出
		        dis[j] = dis[j]<dis[index]+g[index][j]?dis[j]:dis[index]+g[index][j];
	}
	return dis[n-1]==INT_MAX?-1:dis[n-1];
}
