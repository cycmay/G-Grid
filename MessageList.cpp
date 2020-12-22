//
// Created by bicycle on 2020/11/27.
//

#include "MessageList.h"

void MessageList::append(Message m) {
//    The message list puts every δ b messages into a bucket and use a linked list to index the created buckets.
//    Here, δ b represents the maximum number of messages allowed in a bucket, i.e., the bucket capacity.
    // 判断bucket 尾插法
    if(pt == nullptr){
        // 没有bucket则创建一个bucket
        pt = addBucket();
    }else{
        // 存在bucket插入message
        // 判断bucket是否满
        if(pt->n >= bktCapacity){
            // bucket装满message创建一个新的bucket
            pt = addBucket();
        }
    }
    // bucket装入message
    pt->messages.push_back(m);
    pt->n++;
    pt->t=m.t;
}

MessageList::MessageList() {
    ph = new Bucket();
    ph->next=nullptr;
    pt = ph->next;
    pl = ph;
//    define capacity of bucket = 10
    bktCapacity = 10;
}

Bucket* MessageList::addBucket() {
    /*
     * We create a new empty bucket ζ newand append it to the tail of L.
     * */
    auto * s = new Bucket();
    s->next= nullptr;
    pt->next = s;
    pt = s;
    // message length add 1;
    n_buckets++;
    return s;
}

void MessageList::deleteBkt(Bucket *s) {
    // message length delete 1;
    n_buckets--;
    free(s);
}


Bucket::Bucket() {
    n = 0;
    t = std::chrono::high_resolution_clock::now();
    next = nullptr;
}
