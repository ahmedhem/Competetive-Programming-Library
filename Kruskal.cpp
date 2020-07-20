
const int MAX = 1e4 + 5;

struct DSU {
    int parent[MAX];
    int groupSize[MAX];
    int rank[MAX];
    int CC;

    DSU() {
        CC = MAX;
        for (int i = 0; i < MAX; ++i) {
            parent[i] = i;
            groupSize[i] = 1;
        }
    }

    int findLeader(int node) {
        if (parent[node] == node)return node;
        return parent[node] = findLeader(parent[node]);
    }

    int sameGroup(int i, int j) {
        return findLeader(i) == findLeader(j);
    }

    int mergeGroup(int i, int j) {
        int leader1 = findLeader(i);
        int leader2 = findLeader(j);
        if (leader1 == leader2)return 0;
        CC--;
        if (groupSize[leader1] > groupSize[leader2]) {
            parent[leader2] = leader1;
            groupSize[leader1] += groupSize[leader2];
        } else {
            parent[leader1] = leader2;
            groupSize[leader2] += groupSize[leader1];

        }
        return 1;
    }

    void mergeGroupByRank(int i, int j) {
        int leader1 = findLeader(i);
        int leader2 = findLeader(j);
        if (leader1 == leader2)return;
        if (rank[leader1] < rank[leader2])swap(leader1, leader2);
        parent[leader2] = leader1;
        if (rank[leader1] == rank[leader2])rank[leader1]++;
        CC--;


    }

    int getCC() {
        return CC;
    }

    int getSize(int node) {
        return groupSize[findLeader(node)];
    }
};

struct edge {
    int w, from, to;

    bool operator<(const edge &e) const {
        return e.w < w;
    }
};

vector<edge> edgList;
int n, m;
vector<edge> edges;

int kruskal() {
    DSU d;
    int total = 0;
    priority_queue<edge> q;
    for (int i = 0; i < edgList.size(); ++i) {

        q.push(edgList[i]);
    }
    while (!q.empty()) {
        edge e = q.top();
        q.pop();
        if (d.mergeGroup(e.from, e.to)) {
            total += e.w;
            edges.push_back(e);
        }
    }

    if (edges.size() != n - 1)return 1e9;
    return total;
}
