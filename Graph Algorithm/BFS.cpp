vector<int> BFS(int s, vector<vector<int> > & adjList) {
	vector<int> len(sz(adjList), OO);
	queue<int> q;
	q.push(s), len[s] = 0;

	int dep = 0, cur = s, sz = 1;
	for (; !q.empty(); ++dep, sz = q.size()) {
		while (sz--) {
			cur = q.front(), q.pop();
			rep(i, adjList[cur]) if (len[adjList[cur][i]] == OO)
				q.push(adjList[cur][i]), len[adjList[cur][i]] = dep+1;
		}
		}
	return len;	//cur is the furthest node from s with depth dep
}
