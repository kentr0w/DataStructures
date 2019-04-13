#include "ReadWriter.h"
#include "Vertex.h"
#include "FordFulkersonVertex.h"
#include "DinicVertex.h"
#include <queue>
#include <ctime>
#include "muTimer.cpp"
#include "EdmondsKarpVertex.h"
#include "Diniz.h"
#include "EdmondsKarp.h"
#include "FordFulkerson.h"
//string, fstream, iostream, vector, Edge.h - included in ReadWriter.h

//Можно создавать любые классы и методы для решения задачи

/// КДЗ по дисциплине Алгоритмы и структуры данных, 2018-2019 уч.год
// Кумар Денис, группа БПИ-172, дата (13.04.2019)
// с++
// Ford-Fulkerson, Edmonds-Karp, Diniz




using namespace std;

struct vert{
    int a;
    bool come_to;
    bool come_from;
};


void findSourceAndSinkVertex(vector<Vertex> &vertex, vector<Vertex*>& sources){
    for(int i=0; i<vertex.size(); ++i)
        if(!vertex[i].come_to)
            sources.push_back(&vertex[i]);
}
Vertex* dfsVertex(std::vector<Vertex> &vertex, std::vector<bool>& used, Vertex *obj){
    if(!obj->come_from)
        return obj;
    used[obj->number_of_vertex]  = true;
    for(int i=0; i<obj->neighbors.size(); ++i){
        if(!used[obj->neighbors[i]->number_of_vertex]) {
            Vertex *object = dfsVertex(vertex, used, obj->neighbors[i]);
            if (object)
                return object;
        }
    }
    return nullptr;
}

void FindSandS(vector<vert>& Vert, vector<vector<int>>& qwe){
    for(int i=0; i<qwe.size(); ++i)
        for(int j=0; j<qwe.size(); ++j)
            if(qwe[i][j]!=0){
                Vert[i].come_to = true;
                Vert[j].come_from = true;
                Vert[i].a = i;
                Vert[j].a = j;
            }
}

void findSourceAndSink(vector<vert>& Vert, vector<int> & sources){
    for(int i=0; i<Vert.size(); ++i)
        if(!Vert[i].come_from)
            sources.push_back(Vert[i].a);
}

int dfs(vector<vert>& Vert, std::vector<bool>& used, int q, vector<vector<int>>& qwe){
    if(!Vert[q].come_to)
        return q;
    used[q]  = true;
    for(int i=0; i<qwe[q].size(); ++i){
        if(!used[i] && qwe[q][i]!=0) {
            int a = dfs(Vert, used, i, qwe);
            if (a!=0)
                return a;
        }
    }
    return 0;
}

int main() {
    string names[40] = {"input_10_0.0.txt", "input_10_0.5.txt", "input_10_1.0.txt", "input_10_disco.txt",
                        "input_310_0.0.txt", "input_310_0.5.txt", "input_310_1.0.txt", "input_310_disco.txt",
                        "input_610_0.0.txt", "input_610_0.5.txt", "input_610_1.0.txt", "input_610_disco.txt",
                        "input_910_0.0.txt", "input_910_0.5.txt", "input_910_1.0.txt", "input_910_disco.txt","input_1210_0.0.txt", "input_1210_0.5.txt", "input_1210_1.0.txt", "input_1210_disco.txt",
                        "input_1510_0.0.txt", "input_1510_0.5.txt", "input_1510_1.0.txt", "input_1510_disco.txt",
                        "input_1810_0.0.txt", "input_1810_0.5.txt", "input_1810_1.0.txt", "input_1810_disco.txt",
                        "input_2110_0.0.txt", "input_2110_0.5.txt", "input_2110_1.0.txt", "input_2110_disco.txt",
                        "input_2410_0.0.txt", "input_2410_0.5.txt", "input_2410_1.0.txt", "input_2410_disco.txt",
                        "input_2710_0.0.txt", "input_2710_0.5.txt", "input_2710_1.0.txt", "input_2710_disco.txt"};


    Diniz dz;
    EdmondsKarp ek;
    FordFulkerson ff;
    int N;
    int path_3 =0;
    int path_2 =0;
    int path_1 =0;
    int path =0;

   // for(int k=16; k<40; ++k) {
        ReadWriter rw("input_10_0.0.txt");

        N = rw.readInt();

        vector<vector<int>> array = rw.newRead(N);

        vector<vert> Vert(array.size());

        FindSandS(Vert, array);

        vector<int> sources;
        vector<int> real_sources, real_sink;


        findSourceAndSink(Vert, sources);


        vector<bool> used(array.size(), false);

        do {
            int a = sources.back();
            sources.pop_back();

            int b = dfs(Vert, used, a, array);

            real_sink.push_back(b);
            real_sources.push_back(a);
        } while (!sources.empty());



        /* vector<Vertex> vertex(N);

         Vertex* source;
         Vertex* sink;


         int path_1 = 0;
         FordFulkersonVertex fordFulkersonVertex;
         DinicVertex dinicVertex;
         EdmondsKarpVertex edmondsKarpVertex;
         long count = 0;



         for (int i = 0; i < N; ++i) {
             Vertex obj;
             obj.number_of_vertex = i;
             obj.from = nullptr;
             vertex[i] = obj;
             vertex[i].level = -1;
             vertex[i].come_from = false;
             vertex[i].come_to = false;
         }

         rw.readEgdes(N, vertex);

         vector<Vertex*> sources;
         vector<Vertex*> reael_sources, real_sinks;



         vector<bool> used(N, false);


         findSourceAndSink(vertex, sources);
         do {

             source = sources.back();
             sources.pop_back();

             sink = dfs(vertex, used, source);

            reael_sources.push_back(source);
            real_sinks.push_back(sink);

         }while (!sources.empty());*/


        vector<vector<int>> array_2 = array;

        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < real_sink.size(); ++j) {
                int b = real_sources[j];
                int a = real_sink[j];
                array_2 = array;
                path_1 += dz.Solve(array_2, b, a);
            }
            //cout << "path_1 " << path_1 << endl;
            path_1 =0;
        }

        auto stop = std::chrono::high_resolution_clock::now();

        std::cout << "time Diniz =    " << std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count() / 10
                  << "ns\n";
        start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < real_sink.size(); ++j) {
                int b = real_sources[j];
                int a = real_sink[j];
                array_2 = array;
                path_2 += ek.solve(array_2, b, a);
            }
            //cout << "path_2 " << path_2 << endl;
            path_2 = 0;
        }
     stop = std::chrono::high_resolution_clock::now();
    std::cout << "time Edmonds-Karp =    " << std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count() / 10
              << "ns\n";

    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < real_sink.size(); ++j) {
            int b = real_sources[j];
            int a = real_sink[j];
            array_2 = array;
            path_3 += ff.solve(array_2, b, a);
        }
        //cout << "path_3 " << path_3 << endl;
        path = path_3;
        path_3 = 0;
    }

    stop = std::chrono::high_resolution_clock::now();

    std::cout << "time Ford-Falkerson =    " << std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count() / 10
              << "ns\n";

        cout<<endl;
        /*for(int j=0; j<10; ++j) {


            for(int j=0; j<reael_sources.size(); ++j) {

                //mt.reset();

                rw.ReadAgain(N, vertex);

                //mt.start();

                //path_1 += fordFulkerson.solve(vertex, reael_sources[j], real_sinks[j]);

               // rw.ReadAgain(N, vertex);

                path_3 += dinic.solve(vertex, reael_sources[j], real_sinks[j]);

                //rw.ReadAgain(N, vertex);

                //path_2 += edmondsKarp.solve(vertex, reael_sources[j], real_sinks[j]);


                //count += mt.stop().duration();
            }

            cout<<"DINIC = "<<path_3<<endl;
            cout<<"FORD = "<<path_1<<endl;
            cout<<"KARP = "<<path_2<<endl;

            path_2 = 0;
            path_1 = 0;
            path_3 = 0;
            cout<<endl;
        }



        //rw.Result(vertex);

        cout <<" время = "<<((stop - start)/10) << endl; /// надо умножить на 1000000

        cout<<"FordFulkerson: "<<path_1<<endl;
        cout<<"Dinitz's: "<<path_3<<endl;*/


        rw.writeValues(array, array_2, path);
        cout<<"------------------------"<<endl;
    return 0;
}

