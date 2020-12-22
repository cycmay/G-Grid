//
// Created by bicycle on 2020/11/27.
//

#ifndef _G_GRID_INDEX_H
#define _G_GRID_INDEX_H

#include "GraphGrid.h"
#include "MessageList.h"
#include "ObjectTable.h"
#include <vector>

class Index {
private:
    int timeout;

public:
    ObjectTable objectTable;
public:
    void updateMessage(const Message&, GraphGrid&);
//    获取顶点o所在OT表的cellID
    int getCellFromOT(int);
//  更新OT表
    void setOT(int, LatestLocation);
//    消息处理
    void messageClean(std::vector<MessageList>);
//    设置过期时间
    void setTimeout(int);
    int getTimeout(void);
};


#endif //_G_GRID_INDEX_H
