#include <bits/stdc++.h>
using namespace std;
struct Edge{
    int idx;
    char outTop,inTop;
    int dir;
    Edge(char _outTop,char _inTop,int _dir,int _idx){
        inTop=_inTop,outTop=_outTop;
        dir=_dir;
        idx=_idx;
    }
    bool operator<(const Edge &e1) const {return idx<e1.idx;}
};
struct Node{
    int acc=0;
    vector<pair<Edge,int>>edges;
};
struct StackAutomata{
    vector<Node>Nodes;
    StackAutomata(int n){
        Nodes.resize(n+1);
    }
    void addEdge(int u,int v,char outTop,char inTop,int dir){
        Edge e=Edge(outTop,inTop,dir,Nodes[u].edges.size()+1);
        Nodes[u].edges.push_back({e,v});
    }
    void addAcc(int u){
        Nodes[u].acc=1;
    }
    bool isOn(int i,int u,string stack1){
        cout<<stack1<<" "<<i<<" "<<u<<endl;
        if(Nodes[u].acc) return 1;
        if(stack1.empty())return 0;
        bool res=0;
        for(auto adj:Nodes[u].edges){
            if(adj.first.outTop==stack1[i]){
                stack1[i]=adj.first.inTop; 
               res|=isOn(i+adj.first.dir,adj.second,stack1);
            }
        }
        return res;
    }
};
int main(){
    freopen("input.txt","r",stdin);
    int n,edges;cin>>n>>edges;
    StackAutomata sa=StackAutomata(n);
    for(int i=0;i<edges;i++){
        int u,v,dir;;
        char outTop,inTop;
        cin>>u>>v>>outTop>>inTop>>dir;
        sa.addEdge(u,v,outTop,inTop,dir);
    }
    for(int i=0;i<n;i++){
        int acc;cin>>acc;
        if(acc)sa.addAcc(i);
    }
    string s;cin>>s;
    s=s+"$";
    bool isOn=sa.isOn(0,0,s);
    cout<<"Estara en el automata? "<<isOn<<endl;   
}