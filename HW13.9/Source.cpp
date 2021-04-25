#include "Header.h"
#include<iostream>
#include <string>
#define VERYBIGINT 1000000000 // очень большое число
using namespace std;

Graph::Graph()
{
    for (int i = 0;i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            matrix[i][j] = 0;
    vertexCount = 0;
    names[0] = "Alex";
    names[1] = "Bobby";
    names[2] = "Megan";
    names[3] = "Josh";
    names[4] = "Adam";
    names[5] = "Anna";
    names[6] = "Katty";
    names[7] = "Ben";
    names[8] = "Emma";
    names[9] = "Sofy";
}

// добавление вершины
void Graph::addVertex(int vnumber)
{
    vertexes[vertexCount] = vnumber;
    vertexCount++;
}

// вернуть количество вершины
int Graph::getVertex()
{
    return vertexCount;
}

// добавление ребра
void Graph::addEdge(int v1, int v2, int weight)
{
    matrix[v1][v2] = weight;
    matrix[v2][v1] = weight;
}

// проверка существования ребра
bool Graph::edgeExists(int v1, int v2)
{
    return matrix[v1][v2] > 0;
}

// проверка существования вершины
bool Graph::vertexExists(int v)
{
    for (int i = 0;i < vertexCount;i++)
        if (vertexes[i] == v)
            return true;
    return false;
}


// ввод имени
void Graph::addnames(int a, string b)
{
    names[a] = b;
}

// вывод имени
void Graph::printnames(int a, int b)
{
    cout << names[a] << " and " << names[b] << endl;
}


int Graph::findMinWayDFS(int from, int to)
{
    bool visited[SIZE];
    for (int i = 0; i < SIZE; ++i)
        visited[i] = false;
    int minPathLen = VERYBIGINT;
    int currentPathLen = 0;
    findMinWayDFSInner(from, to, visited, minPathLen, currentPathLen);
    return minPathLen;
}

void Graph::findMinWayDFSInner(int from, int to, bool visited[], int& minPathLen, int& currentPathLen)
{
    if (from == to)
    {
        if ((minPathLen > currentPathLen))
        {
            minPathLen = currentPathLen;
        }
        return;
    }
    visited[from] = true;

    for (int i = 0; i < SIZE; ++i)
    {
        if (edgeExists(from, i) && !visited[i])
        {
            int newPathLen = currentPathLen + matrix[from][i];
            findMinWayDFSInner(i, to, visited, minPathLen, newPathLen);
        }

    }
    visited[from] = false;
}

int backint(string a)                        // // Перевод текста в int (отсекаем неправильный выбор в меню)
{
        int b;
        if (a == "0")
        {
            b = 0;
        }
        else if (a == "1")
        {
            b = 1;
        }
        else if (a == "2")
        {
            b = 2;
        }
        else if (a == "3")
        {
            b = 3;
        }
        else if (a == "4")
        {
            b = 4;
        }
        else if (a == "5")
        {
            b = 5;
        }
        else if (a == "6")
        {
            b = 6;
        }
        else if (a == "7")
        {
            b = 7;
        }
        else if (a == "8")
        {
            b = 8;
        }
        else if (a == "9")
        {
            b = 9;
        }
        else b = 9;
        return b;
}
