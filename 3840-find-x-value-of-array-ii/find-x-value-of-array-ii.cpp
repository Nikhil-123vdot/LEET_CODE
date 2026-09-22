class Solution {
public:
    struct Node {
        int prod;
        int cnt[5];

        Node() {
            prod = 1;
            for (int i = 0; i < 5; i++)
                cnt[i] = 0;
        }
    };

    int n, k;
    vector<Node> seg;

    Node mergeNode(const Node& L, const Node& R) {
        Node res;

        res.prod = (L.prod * R.prod) % k;

        // Prefix completely inside LEFT
        for (int r = 0; r < k; r++) {
            res.cnt[r] += L.cnt[r];
        }

        // Prefix that enters RIGHT
        for (int r = 0; r < k; r++) {
            int nr = (L.prod * r) % k;
            res.cnt[nr] += R.cnt[r];
        }

        return res;
    }

    void build(int p, int l, int r, vector<int>& nums) {
        if (l == r) {
            int rem = nums[l] % k;

            seg[p].prod = rem;
            seg[p].cnt[rem] = 1;

            return;
        }

        int mid = (l + r) >> 1;

        build(p << 1, l, mid, nums);
        build(p << 1 | 1, mid + 1, r, nums);

        seg[p] = mergeNode(seg[p << 1],
                           seg[p << 1 | 1]);
    }

    void update(int p, int l, int r, int idx, int val) {
        if (l == r) {
            int rem = val % k;

            seg[p] = Node();
            seg[p].prod = rem;
            seg[p].cnt[rem] = 1;

            return;
        }

        int mid = (l + r) >> 1;

        if (idx <= mid)
            update(p << 1, l, mid, idx, val);
        else
            update(p << 1 | 1, mid + 1, r, idx, val);

        seg[p] = mergeNode(seg[p << 1],
                           seg[p << 1 | 1]);
    }

    Node query(int p, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr)
            return seg[p];

        int mid = (l + r) >> 1;

        if (qr <= mid)
            return query(p << 1, l, mid, ql, qr);

        if (ql > mid)
            return query(p << 1 | 1, mid + 1, r, ql, qr);

        Node L = query(p << 1, l, mid, ql, qr);
        Node R = query(p << 1 | 1, mid + 1, r, ql, qr);

        return mergeNode(L, R);
    }

    vector<int> resultArray(
        vector<int>& nums,
        int k,
        vector<vector<int>>& queries
    ) {
        this->n = nums.size();
        this->k = k;

        seg.resize(4 * n);

        build(1, 0, n - 1, nums);

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto& q : queries) {

            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            // Update
            update(1, 0, n - 1, index, value);

            // Query [start, n-1]
            Node res = query(
                1, 0, n - 1,
                start, n - 1
            );

            ans.push_back(res.cnt[x]);
        }

        return ans;
    }
};