#include <iostream>
#include <vector>
#include <tuple>
#include <string>

void vector_debug(std::vector<std::tuple<int, int, std::string>> edges);

int main()
{
    int n = 0, start = 1, end = 1;
    std::string company_name;
    std::vector<std::tuple<int, int, std::string>> edges;

    std::cin >> n;

    while (true)
    {
        std::cin >> start >> end;

        if (start == 0 and end == 0) break;

        std::cin >> company_name;

        edges.push_back(make_tuple(start - 1, end - 1, company_name));
    }

    vector_debug(edges);
}

void vector_debug(std::vector<std::tuple<int, int, std::string>> vector)
{
    for (int i = 0; i < vector.size(); i++)
    {
        std::cout << std::get<0>(vector[i]) << " " <<
                     std::get<1>(vector[i]) << " " <<
                     std::get<2>(vector[i]) << std::endl;
    }
}