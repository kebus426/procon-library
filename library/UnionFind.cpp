#include <vector>

class UnionFind
{

private:
	std::vector<long long> par;
	std::vector<long long> rank;

public:
	UnionFind(long long n) {
		par = std::vector<long long>(n);
		rank = std::vector<long long>(n);
		for (long long i = 0; i < n; i++) {
			par[i] = i;
			rank[i] = 0;
		}
	};

	long long find(long long x) {
		if (par[x] == x) {
			return x;
		}
		else {
			return par[x] = find(par[x]);
		}
	}

	void unite(long long x, long long y) {
		x = find(x);
		y = find(y);
		if (x == y)return;

		if (rank[x] < rank[y]) {
			par[x] = y;
		}
		else {
			par[y] = x;
			if (rank[x] == rank[y])rank[x]++;
		}

	}

	bool same(long long x, long long y) {
		return find(x) == find(y);
	}

	long long count() {
		long long ret = 0;
		for (long long i = 0; i < par.size(); i++) {
			if (i == par[i])ret++;
		}
		return ret;
	}
};
