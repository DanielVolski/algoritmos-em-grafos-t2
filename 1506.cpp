#include <iostream>
#include <vector>
#include <tuple>
#include <limits>

int dijkstra(std::vector<std::tuple<int, int, int>> graph, int start, int end, int qt_vertexes);

int main()
{
    int t = 0, n = 0, m = 0, 
        u = 0, v = 0, w = 0,
        k = 0, p = 0;
    
    // This is an auxiliar variable used to indicate the vertices that has an object
    int choosen_vertex = 0;

    // The graph is a vector of tuples that represents the edges, std::tuple<start, end, weight> 
    std::vector<std::tuple<int, int, int>> graph;
    // This vector is going to record the vertices that has a object
    std::vector<int> objects_position;

    std::cin >> t;

    while (t != 0)
    {
        std::cin >> n >> m;

        for (int i = 0; i < m; i++)
        {
            std::cin >> u >> v >> w;
            graph.push_back(std::make_tuple(u - 1, v - 1, w));
        }

        std::cin >> k >> p;

        for (int i = 0; i < k; i++)
        {
            std::cin >> choosen_vertex;
            objects_position.push_back(choosen_vertex);
        }

        std::cout << dijkstra(graph, 0, 2, n) << std::endl;

        t--;
    }
    return 0;
}

int dijkstra(std::vector<std::tuple<int, int, int>> graph, int start, int end, int qt_vertexes)
{
    int distances[qt_vertexes];
    std::vector<std::tuple<int, int, int>> adj;

    for (int i = 0; i < qt_vertexes; i++)
        distances[i] = std::numeric_limits<int>::max();

    distances[start] = 0;

    for (int i = 0; i < qt_vertexes; i++)
    {
        adj.clear();
        // This is going to get all edges that are adjascent to i
        for (int j = 0; j < graph.size(); j++)
        {
            if (std::get<0>(graph[j]) == i || std::get<1>(graph[j]) == i)
            {
                adj.push_back(graph[j]);
                // This is just to "delete" the edges from the graph
                graph[j] = std::make_tuple(0, 0, 0);
            }
        }
        
        // This is going to relax all the adjascents to i
        for (int j = 0; j < adj.size(); j++)
        {
            if (std::get<0>(adj[j]) != i && distances[std::get<0>(adj[j])] > std::get<2>(adj[j]))
                distances[std::get<0>(adj[j])] = distances[i] + std::get<2>(adj[j]);
            else if (std::get<1>(adj[j]) != i && distances[std::get<1>(adj[j])] > std::get<2>(adj[j]))
                distances[std::get<1>(adj[j])] = distances[i] + std::get<2>(adj[j]);
        }
    }
    return distances[end];
}