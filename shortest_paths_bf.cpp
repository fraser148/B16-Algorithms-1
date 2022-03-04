#include "shortest_paths_bf.hpp"

std::vector<hop_t> bellman_ford(const Graph &graph, const int source,
                                bool &has_negative_cycle)
{
    const int V = static_cast<int>(graph.size());
    auto DP = std::vector<hop_t>(V, {inf, -1});
    DP[source] = {0, source};

    for (int iter = 0; iter < V - 1; ++iter) {
        has_negative_cycle = false;
        for (int r = 0; r < V; ++r) {
            for (int v = 0; v < V; ++v) {
                auto duv = DP[v].weight;
                auto durv = DP[r].weight + graph[r][v];
                if (durv < duv) {
                    DP[v] = {durv, r};
                    has_negative_cycle = true;
                }
            }
        }
    }

    return DP;
}
