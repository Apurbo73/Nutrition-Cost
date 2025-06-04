#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, C;
        cin >> N >> C;
        vector<int> A(N), B(N);
        for (int i = 0; i < N; ++i) cin >> A[i];
        for (int i = 0; i < N; ++i) cin >> B[i];

        unordered_map<int, int> minCost;
        for (int i = 0; i < N; ++i) {
            if (minCost.find(A[i]) == minCost.end() || B[i] < minCost[A[i]])
                minCost[A[i]] = B[i];
        }

        vector<int> costs;
        for (auto& [vitamin, cost] : minCost)
            costs.push_back(cost);

        sort(costs.begin(), costs.end());
        int Y = 0, maxVal = 0;
        for (int i = 0; i < costs.size(); ++i) {
            Y += costs[i];
            int value = C * (i + 1) - Y;
            if (value > maxVal) maxVal = value;
        }

        cout << maxVal << endl;
    }
    return 0;
}