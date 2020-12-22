//
// Created by bicycle on 2020/11/27.
//

#ifndef _G_GRID_CELL_H
#define _G_GRID_CELL_H

#include <vector>
#include "Vertex.h"
#include "MessageList.h"

class Cell {
public:
    // c.A vis a size-δ array storing all the vertices in c
    std::vector<Vertex> vertices;
    // is the number of vertices in c.A v
    int nv;
    // the number of edges of which the source vertices are in c
    int ne;

    // messageList
    MessageList messageList;
};


#endif //_G_GRID_CELL_H
