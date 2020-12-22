//
// Created by bicycle on 2020/11/27.
//

#include "Index.h"
#include <cuda_runtime.h>
#include <chrono>

void Index::updateMessage(const Message& m, GraphGrid& G) {
// input : a message m and the G-Grid
// output: updated G-Grid
    int c = G.getCell(m.edge);
    G.cells[c].messageList.append(m);
    if(c != getCellFromOT(m.object)){
        int c_ = getCellFromOT(m.object);
        G.cells[c_].messageList.append(Message(m.object, Edge(), 0.0, m.t));
    }
    setOT(m.object, LatestLocation(c, m.edge, m.dist));

}

int Index::getCellFromOT(int o) {
    return objectTable.table[o].cid;
}

void Index::setOT(int o, LatestLocation l) {
    objectTable.table[o] = l;
}

void Index::messageClean(std::vector<MessageList> ML) {
// input : a set of message lists L
// output: up-to-date object locations R
    for(auto & itr : ML){
        // append a new bucket ζ to the tail of L; point p l to ζ
        itr.pl = itr.addBucket();
        // clean out-time bucket
        for(auto bkt=itr.ph->next, bktPrior=itr.ph;;){
            if(bkt!= nullptr){
                if((std::chrono::high_resolution_clock::now()-bkt->t).count()>timeout){
                    bktPrior->next=bkt->next;
                    itr.deleteBkt(bkt);
                    bkt=bktPrior->next;
                }
                else {
                    bktPrior = bkt;
                    bkt = bkt->next;
                }
            }
            else{
                break;
            }
        }
        // create a size L.n array L.A on the GPU
        
        cudaMalloc((void))
        // copy buckets before p l for all L ∈ L into L.A
    }
}

void Index::setTimeout(int t) {
    timeout=t;
}

int Index::getTimeout(void) {
    return timeout;
}
