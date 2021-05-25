/*
 * The chienese reminder theorim is a theorim which able to solve system of congurance equations
 * if we can solve two equations and merge them into 1 we can solve it sequentially
 *  T = x modN  then T-x = q1N then T  = q1N + x
 *  T = y modM then T-y = q2M then T  = q2M + y
 */
int CRT(vector<int> rem, vector<int> mod) {
    int x = rem[0], N = mod[0];
    int T;


    for (int i = 1; i < rem.size(); ++i) {
        int y = rem[i], M = mod[i];
        int x1, y1, g;
        if (!find_any_solution(N, -M, y - x, x1, y1, g))return -1;
        T = x1 * N + x;
        int newMod = N / g * M;
        int newRem = (T % newMod + newMod) % newMod;
        x = newRem;
        N = newMod;
    }
    return x;
}

