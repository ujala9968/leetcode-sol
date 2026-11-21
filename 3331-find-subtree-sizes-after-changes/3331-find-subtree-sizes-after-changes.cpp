
class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {

        int n = parent.size();

        // Step 1: Build original tree
        vector<vector<int>> adj(n);

        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        // Step 2: Find new parents
        vector<int> newParent(n, -1);

        vector<int> last(26, -1);

        // {node, isExit, characterIndex, oldValue}
        struct Event {
            int node, isExit, ch, old;
        };

        vector<Event> st;
        st.push_back({0, 0, -1, -1});

        while (!st.empty()) {

            Event e = st.back();
            st.pop_back();

            int u = e.node;

            // Exit event: restore previous character position
            if (e.isExit) {
                last[e.ch] = e.old;
                continue;
            }

            int ch = s[u] - 'a';

            int old = last[ch];

            // Find closest ancestor with same character
            if (u != 0) {
                if (old != -1)
                    newParent[u] = old;
                else
                    newParent[u] = parent[u];
            }

            // Current node becomes latest for this character
            last[ch] = u;

            // Restore when DFS comes back
            st.push_back({u, 1, ch, old});

            // Visit original children
            for (int i = adj[u].size() - 1; i >= 0; i--) {
                st.push_back({adj[u][i], 0, -1, -1});
            }
        }

        // Step 3: Build modified tree
        vector<vector<int>> tree(n);

        for (int i = 1; i < n; i++) {
            tree[newParent[i]].push_back(i);
        }

        // Step 4: Calculate subtree sizes
        vector<int> ans(n, 1);
        vector<int> order;
        vector<int> stk = {0};

        while (!stk.empty()) {
            int u = stk.back();
            stk.pop_back();

            order.push_back(u);

            for (int v : tree[u]) {
                stk.push_back(v);
            }
        }

        // Process children before parents
        for (int i = order.size() - 1; i >= 0; i--) {
            int u = order[i];

            for (int v : tree[u]) {
                ans[u] += ans[v];
            }
        }

        return ans;
    }
};
