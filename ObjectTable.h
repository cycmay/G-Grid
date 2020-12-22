//
// Created by bicycle on 2020/11/27.
//

#ifndef _G_GRID_OBJECTTABLE_H
#define _G_GRID_OBJECTTABLE_H

#include <unordered_map>

class LatestLocation{
public:
    // cell Id
    int cid;
    // the edge e that contains the latest location of o
    int eid;
    // d is the distance from the source vertex of e to o
    double dist;
public:
    LatestLocation(int c, int e, double d):cid(c),eid(e), dist(d){};
};

class ObjectTable {
public:
    std::unordered_map<int, LatestLocation> table;
};


#endif //_G_GRID_OBJECTTABLE_H
