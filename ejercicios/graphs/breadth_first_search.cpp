#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>
#include <queue>

using namespace std;

using Graph = unordered_map<string, vector<string>>;

//
void bread_first_search(string start, Graph& friends)
{
    set<string> visited;
    queue<string> to_do;

    to_do.push(start);
    visited.insert(start);

    while (!to_do.empty()){
        string current = to_do.front();
        to_do.pop();
        cout << current << " ";
        for (string f: friends[current]){
            if(!visited.count(f)){
                to_do.push(f);
                visited.insert(f);
            }
        }
    }
}

int main()
{
    Graph friends {
      {"Mateo",    {"Marcos","Maria","Lucas"}},
      {"Marcos",   {"Juan"}},
      {"Lucas",    {"Marcos"}},
      {"Juan",     {"Lucas","Mateo"}},
      {"Maria",    {"Marcos", "Lucas","Priscila"}},
      {"Priscila", {"Marcos"}}
    };


    bread_first_search("Marcos",friends);
    cout << endl;
}