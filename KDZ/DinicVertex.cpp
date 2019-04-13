//
// Created by Denis Kumar on 2019-04-05.
//

#include "DinicVertex.h"
#include <queue>

using  namespace std;

int DinicVertex::solve(std::vector<Vertex> &vertex, Vertex *source, Vertex *sink) {
    int path = 0;
    Vertex* obj_1 = source;// &vertex[source->number_of_vertex];
    Vertex* obj_2 = sink;//&vertex[sink->number_of_vertex];
    do{
        if (!FindPath(vertex, obj_1, sink))  break;
        int a = CreatePath (obj_1, INT32_MAX, vertex, obj_1, obj_2);
        while (a!=0) {
            path += a;
            a = CreatePath (obj_1, INT32_MAX, vertex, obj_1, obj_2);
        }
    }while(true);
    return path;
}

int DinicVertex::CreatePath(Vertex *obj, int flow, std::vector<Vertex> &vertex, Vertex *istok, Vertex *stok) {
    if (!flow)
        return 0;
    if (obj == stok)
        return flow;
    for (int i = 0; i< vertex.size(); ++i) {
        if (vertex[i].level != obj->level + 1) continue;
        int pushed=0;
        Vertex* qwe;
        for(int j=0; j < obj->neighbors.size(); ++j){
            if(obj->neighbors[j]->number_of_vertex == vertex[i].number_of_vertex){
                pushed = CreatePath (&vertex[i], min (flow, obj->stream[j] - obj->real_stream[j]), vertex, istok, stok);
                qwe = &vertex[i];
                break;
            }
        }
        if (pushed) {
            for(int j=0; j<obj->neighbors.size(); ++j)
                if(obj->neighbors[j]->number_of_vertex == qwe->number_of_vertex){
                    obj->real_stream[j]+=pushed;
                }
            for(int j=0; j<qwe->neighbors.size(); ++j)
                if(qwe->neighbors[j]->number_of_vertex == obj->number_of_vertex){
                    qwe->real_stream[j]-=pushed;
                }
            return pushed;
        }
    }
    return 0;
}

bool DinicVertex::FindPath(std::vector<Vertex> &vertex, Vertex *istok, Vertex *stok) {

    for(int i=0; i<vertex.size(); ++i)
        vertex[i].level = -1;

    queue<Vertex*> Q;
    Vertex* temp;
    vertex[istok->number_of_vertex].level = 0;
    Q.push(&vertex[istok->number_of_vertex]);
    while(!Q.empty()){
        temp = Q.front();
        Q.pop();
        for(int i=0; i<temp->neighbors.size(); ++i){
            if(temp->real_stream[i]< temp->stream[i] && temp->neighbors[i]->level==-1){
                temp->neighbors[i]->level = temp->level+1;
                Q.push(temp->neighbors[i]);
            }
        }
    }
    return stok->level!=-1;
}