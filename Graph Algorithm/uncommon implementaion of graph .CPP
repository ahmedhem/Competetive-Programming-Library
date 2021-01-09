cont int MAXNodes=1e5;
ll weight[MAX],head[MAX],to[MAX],nxt[MAX],e=0;

void add_edge(ll i, ll j, ll cost) {
    weight[e] = cost;
    to[e] = j;
    nxt[e] = head[i];
    head[i] = e++;
}
void traverse_over_children(int node){

for(int e=head[node];~e;e=nxt[e]){

}

}
