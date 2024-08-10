class Solution {
public:
int tree[400000] = {}, lazy[400000] = {};
int build(vector<int> &arr, int n, int a, int b)
{
    if (a == b)
        return tree[n] = arr[a];
    return tree[n] = build(arr, 2 * n, a, (a + b) / 2) + 
		build(arr, 2 * n + 1, (a + b) / 2 + 1, b);
}
int update_tree(int n, int a, int b, int i, int j)
{   
    if (b < i || a > j) // outside
        return lazy[n] ? b - a + 1 - tree[n] : tree[n];
    if (lazy[n]) {
        tree[n] = b - a + 1 - tree[n];
        if (a != b) {
            lazy[n * 2] = !lazy[n * 2];
            lazy[n * 2 + 1] = !lazy[n * 2 + 1];
        }
        lazy[n] = 0;
    }
    if (a >= i && b <= j) { // inside
        if (a != b) {
            lazy[n * 2] = !lazy[n * 2];
            lazy[n * 2 + 1] = !lazy[n * 2 + 1];
        }
        return tree[n] = b - a + 1 - tree[n];
    }
    return tree[n] = update_tree(n * 2, a, (a + b) / 2, i, j) +
        update_tree(n * 2 + 1, (a + b) / 2 + 1, b, i, j);
}  
vector<long long> handleQuery(vector<int>& n1, vector<int>& n2, vector<vector<int>>& queries) {
    long long sum = accumulate(begin(n2), end(n2), 0LL), sz = n1.size();
    build(n1, 1, 0, sz - 1);
    vector<long long> res;
    for (auto &q : queries) {
        if (q[0] == 1)
            update_tree(1, 0, sz - 1, q[1], q[2]);
        else if (q[0] == 2)
            sum += (long long)tree[1] * q[1];
        else
            res.push_back(sum);
    }
    return res;
}
};