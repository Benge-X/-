#include <iostream>
#include <vector>
using namespace std;

class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;
    int count;

public:
    UnionFind(int n) {
        count = n;
        parent.resize(n + 1);
        rank.resize(n + 1, 1);
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY]) {
                swap(rootX, rootY);
            }
            parent[rootY] = rootX;
            rank[rootX] += rank[rootY];
            --count;
        }
    }

    int getCount() {
        return count;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    UnionFind uf(N);

    int day = -1;
    for (int i = 1; i <= M; ++i) {
        int a, b;
        cin >> a >> b;
        uf.unite(a, b);
        if (uf.getCount() == 1) {
            day = i;
            break;
        }
    }

    cout << day << endl;

    return 0;
}