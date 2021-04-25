#pragma once
#ifndef __GRAPH__
#define __GRAPH__
#define SIZE 10
using namespace std;
#include <string>

class Graph
{
public:
    Graph();
    // добавление вершины
    void addVertex(int vnumber);
    // добавление ребра
    void addEdge(int v1, int v2, int weight);

    //поиск путей
    int findMinWayDFS(int from, int to);
    void findMinWayDFSInner(int from, int to, bool visited[], int& minPathLen, int& currentPathLen);
    int getVertex();
    // вывод имени
    void printnames(int a, int b);
    // ввод имени
    void addnames(int a, string b);

private:
    bool edgeExists(int v1, int v2);
    bool vertexExists(int v);
    void depthInner(int current, bool visited[]);

    int matrix[SIZE][SIZE]; // матрица смежности
    int vertexes[SIZE]; // хранилище вершин
    string names[SIZE]; // хранилище имен
    int vertexCount; // количество добавленных вершин
};

int backint(string a);   // Перевод текста в int (отсекаем неправильный выбор в меню)
#endif
