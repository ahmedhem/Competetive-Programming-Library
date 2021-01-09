const int y[] = {0 , 0,  1 ,-1};// 8 shifts to neighbors
const int x[] = {1, -1 , 0 , 0};// used in functions
const int MAX = 1e2 + 5;
  int dist[MAX];
  vector<vector<pi>> adj(MAX);
  int vis[MAX][MAX], arr[MAX][MAX], n, m;
  bool valid(int i,int j){
      return i>=0&&j>=0&&i<n&&j<m;
  }

  int dijkstra(int src, int t,int e) {
      fill(dist, dist + MAX, INT_MAX - 10000);
      priority_queue<pi, vector<pi>, greater<pi> > pq;
      pq.push({0, src});
      dist[src] = 0;
      while (!pq.empty()) {
          int d = pq.top().first;
          int node = pq.top().second;
              if (node == e) {
                  return d;
          }
          pq.pop();
          if (d > dist[node])continue;
          for (int i = 0; i < adj[node].size(); ++i) {
              pi v=adj[node][i];
              if(dist[v.first]>dist[node]+v.second){
                  dist[v.first]=dist[node]+v.second;
                  pq.push({dist[node]+v.second,v.first});
              }
          }
      }

      return 0;
  }
