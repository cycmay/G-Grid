//
// Created by bicycle on 2020/11/27.
//

#ifndef _G_GRID_GRAPHGRID_H
#define _G_GRID_GRAPHGRID_H

#include <vector>
#include <unordered_map>

#include "Cell.h"
#include "MessageList.h"


class GraphGrid {
public:
    std::vector<Cell> cells;
private:
//    maps an edge to the IDs of its source vertex and the cell where this vertex locates
    std::unordered_map<int, int> invertedIndex;

public:
// 获取边的源顶点所在cell的id
    int getCell(Edge e);

};


#endif //_G_GRID_GRAPHGRID_H
