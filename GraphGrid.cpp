//
// Created by bicycle on 2020/11/27.
//

#include "GraphGrid.h"

int GraphGrid::getCell(Edge e) {
    return invertedIndex[e.id];
}
