//
// Created by bicycle on 2020/11/27.
//

#ifndef _G_GRID_MESSAGELIST_H
#define _G_GRID_MESSAGELIST_H

#include <vector>
#include <chrono>

#include "Edge.h"

class Message{
public:
    // m.o denotes the object that sends the message,
    int object{};
    // m.e denotes the edge on which m.o locates
    Edge edge;
    // d denotes the distance from the source vertex of m.e to m.o
    double dist{};
    // denotes the update time.
    std::chrono::high_resolution_clock::time_point t{std::chrono::high_resolution_clock::now()};
public:
    Message(int o, Edge e, double d, std::chrono::high_resolution_clock::time_point t):object(o), edge(e), dist(d), t(t){};
};

class Bucket{
public:
    //where ζ .A is a size-δ b array for storing messages,
    std::vector<Message> messages;
    // is the number of messages stored in ζ .A m
    int n;
    // is the time of the latest message in ζ
    std::chrono::high_resolution_clock::time_point t;
    // is a pointer that points to the next bucket
    Bucket * next;
public:
    Bucket();
};

class MessageList {
public:
    // Pointers ph and pt point to the head and the tail buckets
    Bucket *ph;
    Bucket *pt;
    // Pointer pl points to a bucket ζ i
    Bucket *pl;

    // the length of buckets
    int n_buckets;

    // bucket capacity
    int bktCapacity;

public:
    MessageList();
    void append(Message);
    Bucket* addBucket();
    void deleteBkt(Bucket *);
};



#endif //_G_GRID_MESSAGELIST_H
