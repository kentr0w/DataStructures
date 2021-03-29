//
// Created by denis on 12.04.19.
//

#include <cstdint>
#include "FordFulkerson.h"


///   Данна метод проверяет есть ли путь от истока к стоку, если есть в вектор parent заносит данные
///
///
/// \param array   наша матрица
/// \param used    вектор использованных вершин для ДФС
/// \param parent  вектор родителей, чтобы найти путь обратно
/// \param q       вершина в которй мы сейчас
/// \param sink    Сток, чтобы знать когда закончить
/// \return
bool FordFulkerson::FindPath(vector<vector<int>> &array, std::vector<bool> &used, vector<int>& parent,  int q, int sink) {
    if(q==sink)
        return true;
    used[q] = true;
    for(int i=0; i<array[q].size(); ++i){
        if(!used[i] && array[q][i] > 0) {
            if (FindPath(array, used, parent, i, sink)) {
                parent[i] = q;
                return true;
            }
        }
    }
    return false;
}

///  Данный метод - вызывает ДФС, если путь есть, он проходит от стока к истоку и вычисляет минимальный поток, который мы может пустить по этому пути и увеличивает/уменьшает на минимум
///
///
/// \param array  наша матрица
/// \param source  Исток
/// \param sink    Сток
/// \return
int FordFulkerson::solve(vector<vector<int>>& array, int source, int sink) {
    vector<int> parent(array.size(), - 1);
    vector<bool> used(array.size(), false);
    int max_stream=0;
    while (FindPath(array, used, parent, source, sink))
    {
        int path = INT32_MAX;
        int q_1, q_2;
        q_1 = sink;
        do{
            q_2 = parent[q_1];
            path = min(path, array[q_2][q_1]);
            q_1 = parent[q_1];
        }while(q_1!=source);
        q_1 = sink;
        do{
            q_2 = parent[q_1];
            array[q_2][q_1] -= path;
            array[q_1][q_2] += path;
            q_1 = parent[q_1];
        }while(q_1!=source);
        max_stream += path;
        for(int i=0; i<used.size(); ++i)
            used[i] = false;
    }
    return max_stream;
}
