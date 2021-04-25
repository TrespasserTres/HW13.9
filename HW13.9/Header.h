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
    // ���������� �������
    void addVertex(int vnumber);
    // ���������� �����
    void addEdge(int v1, int v2, int weight);

    //����� �����
    int findMinWayDFS(int from, int to);
    void findMinWayDFSInner(int from, int to, bool visited[], int& minPathLen, int& currentPathLen);
    int getVertex();
    // ����� �����
    void printnames(int a, int b);
    // ���� �����
    void addnames(int a, string b);

private:
    bool edgeExists(int v1, int v2);
    bool vertexExists(int v);
    void depthInner(int current, bool visited[]);

    int matrix[SIZE][SIZE]; // ������� ���������
    int vertexes[SIZE]; // ��������� ������
    string names[SIZE]; // ��������� ����
    int vertexCount; // ���������� ����������� ������
};

int backint(string a);   // ������� ������ � int (�������� ������������ ����� � ����)
#endif