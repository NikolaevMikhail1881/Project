#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

std::vector<std::vector<int>> graph;

bool isLoop(std::vector<int> path) {
    int n = path.size();
    if(n < 2)
    {
        return false;
    }
    if(path[0] != path[n-1]) return false;
    for(int i = 0; i < n-1; i++) {
        if(!graph[path[i]][path[i+1]])
        {
            return false;
        }
    }
    return true;
}

void generateGraph(int n) {
    srand(time(0)); // Инициализирует генератор случайных чисел.

    graph.resize(n, std::vector<int>(n, 0)); // Изменяет размер графа на n x n (матрица смежности) и инициализирует его нулями.

    // Создает цикл в графе, соединяя каждую вершину i с вершиной i+1
    for(int i = 0; i < n-1; i++) {
        graph[i][i+1] = graph[i+1][i] = 1;
    }
    // Замыкает цикл, соединяя последнюю вершину с первой
    graph[0][n-1] = graph[n-1][0] = 1;

    // Добавляет случайные ребра в граф. Эти ребра могут или не могут соединять вершины, в зависимости от случайного числа (0 или 1).
    // Пропускаем i=0 и j=n-1, чтобы не перезаписывать ребро, которое было создано выше, чтобы замкнуть цикл.
    for(int i = 0; i < n; i++) {
        for(int j = i+2; j < n; j++) {
            if(i != 0 || j != n-1) {
                graph[i][j] = graph[j][i] = rand() % 2;
            }
        }
    }
}


void printGraph() {
    // Цикл перебирает все строки в графе, которые соответствуют вершинам графа.
    for(const auto &row : graph) {
        // Цикл перебирает все элементы в каждой строке, которые соответствуют ребрам, соединяющим вершины графа.
        for(const auto &elem : row) {
            // Выводит значение каждого элемента (ребра)
            std::cout << elem << ' ';
        }
        // Создаёт отдельную строку вывода для каждой вершины в графе.
        std::cout << '\n';
    }
}


int main() {
    int n;
    std::cout << "Введите количество вершин: ";
    std::cin >> n;
    generateGraph(n);
    std::cout << "Сгенерированный граф:\n";
    printGraph();
    std::vector<int> path;
    int vertex;
    std::cout << "Введите вершины (закончите ввод -1): ";
    while(true) {
        std::cin >> vertex;
        if(vertex == -1) break;
        path.push_back(vertex);
    }
    if(isLoop(path)) {
        std::cout << "Данный цикл есть в графе.\n";
    } else {
        std::cout << "Данного цикла нет в графе.\n";
    }
    return 0;
}
