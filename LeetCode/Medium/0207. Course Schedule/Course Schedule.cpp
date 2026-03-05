            parent[x] = y;
            rank[y]++;
        }
        return true;
    }
};

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        UnionFind uf(numCourses);
        for (const auto& p : prerequisites)
        {
            int pre = p[1];
            int next = p[0];
            if (uf.find(pre) == next)
                return false;
            uf.unite(next, pre);
        }
        return true;
    }
};
