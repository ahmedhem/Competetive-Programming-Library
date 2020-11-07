ll cap[],head[],to[],nxt[],e=0;
void add_edge(ll i, ll j, ll cape) {
    cap[e] = cape;
    to[e] = j;
    nxt[e] = head[i];
    head[i] = e++;
}
