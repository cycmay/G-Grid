//
// Created by bicycle on 2020/11/27.
//

#ifndef _G_GRID_EDGE_H
#define _G_GRID_EDGE_H

#include "Vertex.h"

class Edge {
public:
    // edge ID
    int id;
    // the source vertex
    Vertex sourceV;
    int weight;
};


#endif //_G_GRID_EDGE_H
