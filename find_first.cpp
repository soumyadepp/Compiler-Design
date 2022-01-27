#include <bits/stdc++.h>
#define NULLTERMINAL "#"
using namespace std;

class Grammar{
    unordered_map<char,vector<string>>rules;
    set<char>terminals;
    set<char>nonTerminals;
    public: 
    Grammar(vector<pair<string,string>>userRules){
        //extract terminals and non terminals from the grammar
        for(auto i : userRules){
            rules[i.first[0]].push_back(i.second);
            nonTerminals.insert(i.first[0]);
            for(auto j : i.second){
                if(isupper(j)){
                    nonTerminals.insert(j);
                }
                else{
                    terminals.insert(j);
                }
            }
        }
        //validate the grammar
        for(auto i : nonTerminals){
            char key = i;
            if(rules[key].size() == 0){
                cout<<"Incomplete grammar\n";
                exit(0);
            }
        }
    }
    void showGrammar(){
        for(auto i : rules){
            cout<<i.first<<" : ";
            for(auto j : i.second){
                cout<<j<<" | ";
            }
            cout<<"\n";
        }
    }
    void dfs(vector<string>mapped,vector<char>&ans,unordered_map<char,bool>&visited){
        for(auto i : mapped){
            char toBeChecked = i[0];
            if(terminals.find(toBeChecked) != terminals.end()){
                ans.push_back(toBeChecked);
            }
            else{
                if(!visited[toBeChecked]){
                    visited[toBeChecked] = true;
                    dfs(rules[toBeChecked],ans,visited);
                }
            }
        }
    }

    unordered_map<char,vector<char>> getFirst(){
        unordered_map<char,vector<char>>res;
        for(auto i : nonTerminals){
            unordered_map<char,bool>visited;
            vector<char>first;
            visited[i] = true;

            //find the first of corresponding non terminal
            dfs(rules[i],first,visited);
            res[i] = first;
        }
        return res;
    }
    void showTerminals(){
        for(auto i : terminals) if(i != NULLTERMINAL[0]) cout<< i << " ";
        cout<<"\n";
    }
    void showNonTerminals(){
        for(auto j : nonTerminals) cout << j << " ";
    }
};

int main(){
    vector<pair<string,string>>vpp = {{"S","AB"},{"S","ac"},{"A","bB"},{"B","c"},{"A",NULLTERMINAL}};
    Grammar grammar(vpp);
    grammar.showGrammar();
    cout<<"Terminals : " << endl;
    grammar.showTerminals();
    cout<<"Non terminals : "<<endl;
    grammar.showNonTerminals();
    cout<<endl;
    unordered_map<char,vector<char>>ans = grammar.getFirst();
    cout << "First of the grammar is : \n";
    for(auto i : ans){
        cout<<i.first<<" : ";
        for(auto j : i.second){
            cout<<j<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
