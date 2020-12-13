finding gray code
int g (int n) {
    return n ^ (n >> 1);
}
