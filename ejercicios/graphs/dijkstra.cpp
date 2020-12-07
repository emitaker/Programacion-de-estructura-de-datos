#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <climits>

using namespace std;

const int infinity = INT_MAX;

using StringIntPair = pair<string, int>;
using Graph = map<string, vector<StringIntPair>>;


void add_edge(Graph& g, string u, string v, int wt)
{
    g[u].push_back(StringIntPair {v, wt});
    g[v].push_back(StringIntPair {u, wt});
}

void dijkstra(Graph& g, string start)
{
    queue<string> q;
    q.push(start);

    map<string, int> distance;

    for(auto p : g){
        distance[p.first] = infinity;
    }
    distance[start] = 0;

    while(!q.empty()){
        string u = q.front();
        q.pop();

        for (StringIntPair x : g[u]){
            string v = x.first;
            int wt = x.second;
            if (distance[v] > distance [u] + wt){
                distance[v] = distance[u] + wt;
                q.push(v);
            }
        }
    }

    cout << "Distance from " << start << endl;
    for (auto p : g){
        string u = p.first;
        cout << u << ": " << distance[u] << endl;
    }
}

int main()
{
    Graph g;
    add_edge(g, "A", "B", 4);
    add_edge(g, "A", "H", 8);
    add_edge(g, "B", "C", 8);
    add_edge(g, "B", "H", 11);
    add_edge(g, "C", "D", 7);
    add_edge(g, "C", "F", 4);
    add_edge(g, "C", "I", 2);
    add_edge(g, "D", "E", 9);
    add_edge(g, "D", "F", 14);
    add_edge(g, "E", "F", 10);
    add_edge(g, "F", "G", 2);
    add_edge(g, "G", "H", 1);
    add_edge(g, "G", "I", 6);
    add_edge(g, "H", "I", 7);

    dijkstra(g, "I");


    return 0;
}
