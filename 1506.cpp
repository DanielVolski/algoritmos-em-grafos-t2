#include <iostream>
#include <vector>
#include <tuple>

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
            graph.push_back(std::make_tuple(u, v, w));
        }

        std::cin >> k >> p;

        for (int i = 0; i < k; i++)
        {
            std::cin >> choosen_vertex;
            objects_position.push_back(choosen_vertex);
        }

        t--;
    }

    return 0;
}