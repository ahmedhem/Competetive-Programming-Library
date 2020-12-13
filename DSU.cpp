
const int MAX = 1e4 + 5;

struct DSU {
    int parent[MAX];
    int groupaSize[MAX];
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
    int getCC() {
        return CC;
    }

    int getSize(int node) {
        return groupSize[findLeader(node)];
    }
};
