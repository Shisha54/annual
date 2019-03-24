#ifndef MAP_H
#define MAP_H

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

#include <QDebug>

namespace Map {

//Класс VertexG содержит информацию о внешнем виде вершины графа - положение на карте, внешний вид итд

    class VertexG
    {
        //Наладить отдельное взаимодействие экземпляра класса с отдельным классом графики в отдельном потоке "отрисовки" - те в конструкторе и деструкторе все отдельно добавляется
    };

//Класс VertexL содержит информацию о вершине графа как о элементе игровой логики

    class VertexL
    {
        //Наладить отдельное взаимодействие экземпляра класса с отдельным классом игровой логики (а мб и нет) - передвижение итд
    };
        //МБ СНЕСТИ ОПРЕДЕЛЕНИЕ ЭТИХ КЛАССОВ В ОТДЕЛЬНЫЙ ФАЙЛ ( gamelogic.h graphics.h )

//Класс Vertex содержит исчерпывающую информацию о вершине графа. Фокус на служебных функций по осуществлению контроля с точки зрения игровой логики

    class Vertex : public VertexG, public VertexL
    {
        std::vector<Vertex*> adjacent;
        //Эти графы используются для перевода армии
        //Другие связи с их длиной (Дороги)
        //Those functions apply changes only to the current object therefore private

        void addEdge(Vertex *x); //Add edge by pointer
        void addEdge(Vertex &x); //Add edge by reference
        void delEdge(Vertex *x); //Deletes edge
        void delEdge(Vertex &x); //Deletes edge

        Vertex();
        //DEBUG - enrich parameters. Vertex takes responsibily for VertexG L?
        //Vertex(std::istream) - захватывает поток со считывание до стоп символа
    public:

        bool checkEdge(Vertex *x); //Check if there is an edge
        bool checkEdge(const Vertex &x); //Check if there is an edge

        friend bool operator==(const Vertex& x, const Vertex& y);
        friend class Graph;
    };


//Класс Graph содержит множество вершин и служебные функции по взаимодействию с ними. По факту реализует загрузку с диска, сохранение на диск, добавление и уничтожение вершин

    class Graph
    {
            public:
        std::vector<Vertex> verticies;

        void addVertex(); //Enrich parameters
        void addVertex(Vertex &x); //Copies exactly with deleting all edges
        void addEdge(Vertex *x, Vertex *y); //Add edge by pointer
        void addEdge(Vertex &x, Vertex &y); //Add edge by reference
        void delEdge(Vertex *x, Vertex *y); //Deletes edge
        void delEdge(Vertex &x, Vertex &y); //Deletes edge
        void delVertex(Vertex &x);
        void delVertex(Vertex *x);

        void loadFromFile(std::string path); //Load graph from a file
    };

}

#endif // MAP_H
