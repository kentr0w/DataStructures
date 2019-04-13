//
// Created by Denis Kumar on 2019-04-11.
//

#include "Diniz.h"
#include <queue>


using namespace std;

/// Сначала проверяется наличие пути, потом строиться сам путь, изменяя потоки
///
///
/// \param array - наша матрца
/// \param source  - Исток
/// \param sink  Сток
/// \return

int Diniz::Solve(vector<vector<int>>& array, int source, int sink) {
    int max_stream = 0;
    vector<int> level(array.size(), -1);
    vector<vector<int>> real_stream(array.size(), vector<int>(array.size(), 0));
    do {
        if (!FindPath(array,real_stream, source, sink, level))
            break;
        int path = CreatePath (array , source ,sink, INT16_MAX, level, real_stream);
        while (path!=0) {
            max_stream += path;
            path = CreatePath (array , source ,sink, INT16_MAX, level, real_stream);
        }
        for(int i=0; i<level.size(); ++i)
            level[i] = -1;
    }while(true);
    return max_stream;
}


///   Использую ДФС, данный метод "прокладывает" путь от истока к стоку и заполняет матрицу  реальных потоков
///
///
/// \param array  наша матрица
/// \param temp   вершина в которой мы находимся
/// \param sink   Сток
/// \param min_path  минимальный путь
/// \param level   вектор уровней
/// \param real_stream  вектор потоков, которые реально проходят
/// \return
int Diniz::CreatePath(vector<vector<int>>& array, int temp, int sink, int min_path, vector<int>& level, vector<vector<int>>& real_stream){
    if (!min_path)  return 0;
    if (temp == sink)  return min_path;
    for (int to=0; to<array.size(); ++to) {
        if (level[to] != level[temp] + 1)
            continue;
        int path = CreatePath (array, to, sink, min (min_path, array[temp][to] - real_stream[temp][to]), level, real_stream);
        if (path) {
            real_stream[temp][to] += path;
            real_stream[to][temp] -= path;
            return path;
        }
    }
    return 0;
}


/// Данный метод, БФС, нужен для проверки наличия пути
///
///
/// \param array  - наша матрицв
/// \param real_stream  - матрица реальных потоков
/// \param source  - Исток
/// \param sink  - Сток
/// \param level  - вектор уровней
/// \return
bool Diniz::FindPath(vector<vector<int>>& array, vector<vector<int>>& real_stream, int source, int sink, vector<int>& level){
    queue<int> Q;
    Q.push(source);
    int temp;
    level[source] = 0;
    while(!Q.empty()){
        temp = Q.front();
        Q.pop();
        for(int i=0; i<array[temp].size(); ++i){
            if(real_stream[temp][i]< array[temp][i] && level[i]==-1){
                level[i] = level[temp]+1;
                Q.push(i);
            }
        }
    }
    return level[sink]!=-1;
}