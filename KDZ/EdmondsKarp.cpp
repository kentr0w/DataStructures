//
// Created by denis on 11.04.19.
//

#include "EdmondsKarp.h"
#include <queue>
#include <cstdint>


/// Метод решения - проверяет, есть ли путь, проходит от стока к истоку, уменьшает/прибавляет минимальный поток в этом пути
///
///
/// \param array наша матрица
/// \param source Исток
/// \param sink   Сток
/// \return
int EdmondsKarp::solve(vector<vector<int>> &array, int source, int sink) {

    vector<int> parent(array.size(), - 1);
    int max_stream=0;
    while (FindPath(array, source, sink, parent))
    {
        int path = INT16_MAX;
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
    }
    return max_stream;
}




/// Данный метод - БФС тоже служит для нахождения пути
///
///
/// \param array наша матрица
/// \param source Исток
/// \param sink   Сток
/// \param parent Вектор родителей
/// \return

bool EdmondsKarp::FindPath(vector<vector<int>> &array, int source, int sink, vector<int>& parent) {
    bool used[array.size()];
    for(int i=0; i<array.size(); ++i)
        used[i] = false;
    queue<int> Q;
    int temp;
    Q.push(source);
    do{
        temp = Q.front();
        Q.pop();
        for (int j = 0; j < array[temp].size(); ++j)
            if (!used[j] && array[temp][j] > 0) {
                Q.push(j);
                parent[j] = temp;
                used[j] = true;

            }
    }while (!Q.empty());
    return (used[sink]);
}