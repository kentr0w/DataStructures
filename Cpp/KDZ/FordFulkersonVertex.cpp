//
// Created by Denis Kumar on 2019-04-03.
//

#include "FordFulkersonVertex.h"
#include <queue>


using namespace std;

int FordFulkersonVertex::solve( std::vector<Vertex> &vertex, Vertex* source, Vertex* sink) {
    vector<Vertex> S;
    vector<int> vec;
    int path=0;
    Vertex* obj_1 =source;// &vertex[source->number_of_vertex];
    Vertex* obj_2 = sink;// &vertex[sink->number_of_vertex];

    vector<bool> used(vertex.size(), false);

    S  = vertex;

    while (dfs(vertex, used, obj_1, obj_2)) {

        S = vertex;

        int minim = INT32_MAX;
        Vertex *temp = &vertex[obj_2->number_of_vertex];
        Vertex *obj;

        do {
            obj = temp->from;

            for (int j = 0; j < obj->neighbors.size(); ++j) {
                if (obj->neighbors[j] == temp)
                    if (obj->stream[j] < minim && obj->stream[j] > 0) {
                        minim = obj->stream[j];
                    }
            }
            temp = obj;

        } while (temp->number_of_vertex != obj_1->number_of_vertex);

        temp = &vertex[obj_2->number_of_vertex];

        do {
            obj = temp->from;

            int a;
            for (int j = 0; j < temp->neighbors.size(); ++j)
                if (temp->neighbors[j] == obj) {
                    a = j;
                    break;
                }
            temp->stream[a] += minim;
            for (int j = 0; j < obj->neighbors.size(); ++j)
                if (obj->neighbors[j] == temp) {
                    a = j;
                    break;
                }
            obj->stream[a] -= minim;
            temp = obj;
        } while (temp->number_of_vertex != obj_1->number_of_vertex);

        for(int i=0; i<vertex.size(); ++i)
            used[i] = false;

        path+=minim;
    }

    return path;
}

Vertex* FordFulkersonVertex::dfs(std::vector<Vertex> &vertex, std::vector<bool>& used, Vertex *obj, Vertex *stok){
    if(obj->number_of_vertex == stok->number_of_vertex)
        return stok;
    used[obj->number_of_vertex]  = true;
    for(int i=0; i<obj->neighbors.size(); ++i){
        if(!used[obj->neighbors[i]->number_of_vertex] && obj->stream[i] > 0) {
            Vertex *object = dfs(vertex, used, obj->neighbors[i], stok);
            if (object) {
                object->from = obj;
                return obj;
            }
        }
    }
    return nullptr;
}