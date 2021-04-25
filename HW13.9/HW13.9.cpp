#include<iostream>
#include <string>
#include "Header.h"
using namespace std;
#pragma runtime_checks( "", off )
#pragma warning( push )
#pragma warning( disable : 4700 )

int main()
{
    int choice;                // Переменная для меню
    string c;                  // Переменная для меню temp
    string name;               // Переменная для ввода имени
    bool y = true;             // Переменная выхода из программы
    int v1;                    // Узел
    int v2;                    // Пара узла
    int vert;
    Graph g;

    cout << "1 - Use existing graph / 2 - Create your" << endl;
    cin >> c;
    choice = backint(c);
    switch (choice)
    {
    case 1:
        for (int a = 0; a < SIZE; a++)
        {
            g.addVertex(a);
        }
        
        g.addEdge(0, 1, 1);
        g.addEdge(1, 5, 1);
        g.addEdge(2, 3, 1);
        g.addEdge(3, 7, 1);
        g.addEdge(4, 8, 1);
        g.addEdge(5, 6, 1);
        g.addEdge(6, 7, 1);
        g.addEdge(6, 9, 1);
        g.addEdge(8, 9, 1);

        for (int i = 0; i < SIZE; ++i)
            for (int j = (i + 1); j < SIZE; ++j)
            {
                if (g.findMinWayDFS(i, j) <= 3)
                    g.printnames(i, j);
            }
        break;
    case 2:
        cout << "How many People (vertex) do you want?" << endl;
        cin >> c;
        vert = backint(c);
        for (int a = 0; a < vert; a++)
        {
            g.addVertex(a);
            cout << "enter name" << endl;
            cin >> name;
            g.addnames(a, name);
        }
        while (y == true)
        {
            cout << "1 - Create a pair  / 0 - Finish" << endl;
            cin >> c;
            if (c == "0")
            {
                y = false;
            }
            else 
            {
                cout << "enter vertex" << endl;
                    cin >> c;
                    v1 = backint(c);
                cout << "enter vertex pair" << endl;
                    cin >> c;
                v2 = backint(c);
                g.addEdge(v1, v2, 1);
            }
        }
        for (int i = 0; i < SIZE; ++i)
            for (int j = (i + 1); j < SIZE; ++j)
            {
                if (g.findMinWayDFS(i, j) <= 3)
                    g.printnames(i, j);
            }
        break;
    default:
        cout << "Bad choise" << endl;
        break;
    }

    return 0;
}