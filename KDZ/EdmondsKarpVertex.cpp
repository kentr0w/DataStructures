//
// Created by Denis Kumar on 2019-04-03.
//

#include "EdmondsKarpVertex.h"

using namespace std;

//
// Created by Denis Kumar on 2019-04-03.
//
#include <queue>


using namespace std;

int EdmondsKarpVertex::solve(std::vector<Vertex> &vertex, Vertex* source, Vertex* sink) {
    vector<Vertex *> S;
    vector<int> vec;
    int path=0;
    Vertex* obj_1 = &vertex[source->number_of_vertex];
    Vertex* obj_2 = &vertex[sink->number_of_vertex];

    while (FindPath(vertex, obj_1, obj_2)) {

        int minim = INT32_MAX;
        Vertex *temp = &vertex[obj_2->number_of_vertex];
        Vertex *obj;

        do {
            obj = temp->from;

            for (int j = 0; j < obj->neighbors.size(); ++j) {
                if (obj->neighbors[j] == temp) {
                    if (obj->stream[j] < minim && obj->stream[j] > 0)
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
            //if(obj->stream[a] >= minim)
                obj->stream[a] -= minim;
            temp = obj;
        } while (temp->number_of_vertex != obj_1->number_of_vertex);

        path+=minim;
    }

    return path;
}

bool EdmondsKarpVertex::FindPath(std::vector<Vertex> &vertex, Vertex *istok, Vertex *stok) {
    bool used[vertex.size()];
    for(int i=0; i<vertex.size(); ++i)
        used[i] = false;

    queue<Vertex *> S;
    Vertex *max;
    S.push(&vertex[istok->number_of_vertex]);
    do{
        max = S.front();
        S.pop();

        for (int j = 0; j < max->neighbors.size(); ++j)
            if (!used[max->neighbors[j]->number_of_vertex] && max->stream[j] > 0) {
                S.push(max->neighbors[j]);
                max->neighbors[j]->from = max;
                used[max->neighbors[j]->number_of_vertex] = true;

            }
    }while (!S.empty());

    return (used[stok->number_of_vertex]);
}