/*
 * Beecrowd 1738
 * Universidade Estadual do Centro Oeste
 * Disciplina Algoritmos em grafos com o Profª Mauro Mulati
 * Turma A, 2022
 */

#include <iostream>
#include <limits>
#include <tuple>
#include <vector>

// Global constants declarations
const int INF = std::numeric_limits<int>::max() / 2; // The limit is divided by two to avoid integer overflow in the floyd warshall algorithm
const int MAX_NODES = 201;
const int MAX_ALPHABET_LETTERS = 26;

// This is set as global to use heap memory and avoid complex pointer arithmetic
int matrix[MAX_NODES][MAX_NODES][MAX_ALPHABET_LETTERS];

// Function signatures
void init_adj_matrix(int qt_vertices);
void floyd_warshall(int qt_vertices);
void show_query_result(std::vector<std::tuple<int, int>> queries, int qt_vertices);

int main()
{
    int n = 1, start = 0, end = 0;
    std::vector<std::tuple<int, int>> queries;
    std::string companies = "";

    while (n > 0)
    {
        std::cin >> n;

        if (n == 0) break;
        
        init_adj_matrix(n);
        if (!queries.empty()) queries.clear();

        // Connections input
        while (true)
        {
            std::cin >> start >> end;

            if (start == 0 and end == 0) break;

            std::cin >> companies;

            for (int i = 0; i < companies.length(); i++)
                // 97 is equal to 'a' char in the ascii table
                matrix[start - 1][end - 1][int(companies[i]) - 97] = 1;
        }

        floyd_warshall(n);

        // Queries input
        while (true)
        {
            std::cin >> start >> end;

            if (start == 0 and end == 0) break;

            queries.push_back(std::make_tuple(start - 1, end - 1));
        }

        show_query_result(queries, n);
        std::cout << std::endl;
    }
}

void init_adj_matrix(int qt_vertices)
{
    for (int i = 0; i < qt_vertices; i++)
        for (int j = 0; j < qt_vertices; j++)
            for (int k = 0; k < MAX_ALPHABET_LETTERS; k++)
                matrix[i][j][k] = INF;
}

void floyd_warshall(int qt_vertices)
{
    for (int k = 0; k < qt_vertices; k++)
        for (int i = 0; i < qt_vertices; i++)
            for (int j = 0; j < qt_vertices; j++)
                for (int l = 0; l < MAX_ALPHABET_LETTERS; l++)
                    matrix[i][j][l] = std::min(matrix[i][j][l], matrix[i][k][l] + matrix[k][j][l]); 
}

void show_query_result(std::vector<std::tuple<int, int>> queries, int qt_vertices)
{
    bool noResultFound;
    for (int i = 0; i < queries.size(); i++)
        if (std::get<0>(queries[i]) <= qt_vertices - 1 && std::get<1>(queries[i]) <= qt_vertices - 1)
        {
            noResultFound = true;
            for (int j = 0; j < MAX_ALPHABET_LETTERS; j++)
                if (matrix[std::get<0>(queries[i])][std::get<1>(queries[i])][j] != INF)
                {
                    std::cout << char(j + 97);
                    noResultFound = false;
                }

            if (noResultFound) std::cout << "-";

            std::cout << std::endl;
        }
}