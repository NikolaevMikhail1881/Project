#include <iostream>
#include <vector>

// Граф представлен в виде матрицы смежности // Сделать генератор матрициы смежности 
std::vector<std::vector<int>> graph = {
    {0, 1, 0, 1, 0, 0},
    {1, 0, 1, 0, 0, 0},
    {0, 1, 0, 1, 0, 0},
    {1, 0, 1, 0, 1, 1},
    {0, 0, 0, 1, 0, 1},
    {0, 0, 0, 1, 1, 0} 
};

bool isLoop(std::vector<int> path) {
    int n = path.size();
    // Цикл должен иметь хотя бы одно ребро
    if(n < 2)
    {
        return false;
    }
    // Цикл должен начинаться и заканчиваться в одной и той же вершине
    if(path[0] != path[n-1]) return false;
    // Проверяем, является ли каждая пара вершин связной
    for(int i = 0; i < n-1; i++) {
        if(!graph[path[i]][path[i+1]])
        {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    std::cout << "Введите количество вершин: ";
    std::cin >> n;
    std::vector<int> path(n);
    std::cout << "Введите вершины: ";
    for(int i = 0; i < n; i++) {
        std::cin >> path[i];
    }
    if(isLoop(path)) {
        std::cout << "Данный цикл есть в графе.\n";
    } else {
        std::cout << "Данного цикла нет в графе.\n";
    }
    return 0;
}
