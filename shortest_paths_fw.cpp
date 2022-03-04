#include "shortest_paths_fw.hpp"
#include <cmath>

std::vector<std::vector<hop_t>> floyd_warshall(const Graph &graph)
{
    const auto V = static_cast<int>(graph.size());

    auto DP =
        std::vector<std::vector<hop_t>>(V, std::vector<hop_t>(V, {inf, -1}));

    for (int u = 0; u < V; ++u) {
        for (int v = 0; v < V; ++v) {
            auto d = (u == v) ? 0 : graph[u][v];
            DP[u][v].weight = d;
            DP[u][v].vertex = std::isfinite(d) ? u : -1;
        }
    }

    for (int r = 0; r < V; ++r) {
        for (int u = 0; u < V; ++u) {
            for (int v = 0; v < V; ++v) {
                auto duv = DP[u][v].weight;
                auto dur = DP[u][r].weight;
                auto drv = DP[r][v].weight;
                if (dur + drv < duv) {
                    DP[u][v].weight = dur + drv;
                    DP[u][v].vertex = DP[r][v].vertex;
                }
            }
        }
    }

    return DP;
}
