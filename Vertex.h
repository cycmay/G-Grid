//
// Created by bicycle on 2020/11/27.
//

#ifndef _G_GRID_VERTEX_H
#define _G_GRID_VERTEX_H

#include "Edge.h"

#include <vector>

// vertex capacity.
#define sizeAe 10

class Vertex {
public:
    // the vertex ID
    int id;
    // v.A e is a size-δ v array that stores the edges having v as the destination vertex
    std::vector<Edge> edges[sizeAe];
    // v.n is the number of edges stored in v.A e.
    int n;
};


#endif //_G_GRID_VERTEX_H
