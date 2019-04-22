#ifndef VERTEXINTERFACE_H
#define VERTEXINTERFACE_H

class VertexInterface
{

public:
    virtual ~VertexInterface();
    virtual bool checkEdge(VertexInterface *x) = 0; //Check if there is an edge
    virtual bool checkEdge(const VertexInterface &x) = 0; //Check if there is an edge
};

class GraphInterface
{

public:

};

#endif // VERTEXINTERFACE_H
