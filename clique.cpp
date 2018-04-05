#include <iostream>
#include <vector>

#define DEBUG 1

using namespace std;

//#define testInput "7\n1 2\n1 3\n1 7\n2 3\n2 7\n3 4\n3 5\n3 6\n4 5\n4 6\n5 6\n6 7\n"

#define Graph vector<vector<int> >
#define CliqueList vector<vector<int> >
#define insertEdge(a,b) G[a-1].push_back(b-1);G[b-1].push_back(a-1)
#define NODE_NOT_YET_OPENED -5
#define NODE_IS_OPEN -10
#define NODE_IS_CLOSED -15

Graph get_test_graph(){
    vector<int> empty;
    Graph G(7, empty);
    insertEdge(1,2);
    insertEdge(1,3);
    insertEdge(1,7);
    insertEdge(2,3);
    insertEdge(2,7);
    insertEdge(3,4);
    insertEdge(3,5);
    insertEdge(3,6);
    insertEdge(4,5);
    insertEdge(4,6);
    insertEdge(5,6);
    insertEdge(6,7);
    return G;
}


// void extendCliqueList(CliqueList& a, CliqueList& b){
//     a.reserve( a.size() + distance(b.begin(), b.end()));
//     a.insert(a.end(), b.begin(), b.end());
//     return;
// }

// CliqueList get_3cliques(int a, int b, int c, vector<int>& levels, Graph& G){
// #if DEBUG
//     cout<<a<<" "<<b<<" "<<c<<endl;
// #endif
//     CliqueList cliqueList, temporaryList;
//     if(a>=0) levels[a] = NODE_IS_OPEN;

//     int adj_size = G[c].size();
//     for(int i=0;i<adj_size;i++){
//         int d = G[c][i];
//         if(d == a){
//             int sorted[3];
//             sorted[(a > b) + (a > c)] = a;
//             sorted[(b >= a) + (b > c)] = b;
//             sorted[(c >= a) + (c >= b)] = c;
//             cliqueList.push_back({sorted[0], sorted[1], sorted[2]});
//         }
//         if(d == b){
//             continue;
//         }
//         else{
//             if(levels[b] == NODE_NOT_YET_OPENED){
//                 temporaryList = get_3cliques(-1, -1, i, levels, G);
//                 extendCliqueList(cliqueList, temporaryList);
//             }
//         }
//     }

//     if(a>=0) levels[a]= NODE_IS_CLOSED;
//     return cliqueList;
// }

// CliqueList get_3cliques(Graph G){
//     int n = G.size();
//     vector<int> levels(n, NODE_NOT_YET_OPENED);
//     CliqueList cliqueList, temporaryList;

//     for(int i=0;i<n;i++){
//         if(levels[i]==NODE_NOT_YET_OPENED){
//             temporaryList = get_3cliques(-1, -1, i, levels, G);
//             extendCliqueList(cliqueList, temporaryList);
//         }
//     }

//     return cliqueList;
// }

// Exaustive 3 cycle search
CliqueList get_3cliques(Graph& G){
    int n = G.size();
    CliqueList CL;
    for(int i=0;i<n;i++){
        int a=i;
        int a_adj_len = G[a].size();
        for(int j=0;j<a_adj_len;j++){
            int b=G[a][j];
            if(b<a) continue;
            int b_adj_len = G[b].size();
            for(int k=0;k<b_adj_len;k++){
                int c = G[b][k];
                if(c<b) continue;
#if DEBUG
                    cout<<a+1<<" "<<b+1<<" "<<c+1<<endl;
#endif
                int c_adj_len = G[c].size();
                for(int l=0;l<c_adj_len;l++){
                    if(a == G[c][l]){
                        CL.push_back({a,b,c});
                    }
                }
            }
        }
    }
    return CL;
}

int main(int argc, char* argv[]){

    Graph G = get_test_graph();
    
    CliqueList CL = get_3cliques(G);

#if DEBUG
    cout<<"the 3 cliques are:\n";
    for(int i=0;i<CL.size();i++){
        for(int j=0;j<CL[i].size();j++){
            cout<<CL[i][j]+1<<" ";
        }
        cout<<endl;
    }
    cout<<"end of 3 cliques\n";
#endif
    
    return 0;
}