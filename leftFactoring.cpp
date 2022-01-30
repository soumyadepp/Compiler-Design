#include <bits/stdc++.h>
using namespace std;

int main()
{
    string input;
    getline(cin,input,'\n');
    vector<string>prods;
    string temp = "";
    for(int i = 0 ; i < input.size(); i++){
      if(input[i] == ' '){
        prods.push_back(temp);
        temp = "";
      }
      temp += input[i];
    }
    if(temp.size() > 0) prods.push_back(temp);
    vector<string> prodleft,prodright;
    for(auto i : prods){
      string chk = i;
      string left = "";
      string right = "";
      bool flag = false;
      for(int j = 0 ; j < chk.size(); j++){
        if(j < chk.size() - 1 && chk[j] == '-' && chl[j + 1] == '>'){
          flag = true;
          continue;
        }
        if(flag == false){
          leftString += chk[j];
        }
        else{
          rightString += chk[j];
        }
      }
      prodleft.push_back(leftString);
      prodright.push_back(rightString);
    }
    int p = prodleft.size();
    int j;  
    int e=1;
    for(i=0;i<p;++i) {
        for(j=i+1;j<p;++j) {
            if(prodleft[j]==prodleft[i]) {
                int k=0;
                string com="";
                while(k<prodright[i].length()&&k<prodright[j].length()&&prodright[i][k]==prodright[j][k]) {
                    com+=prodright[i][k];
                    ++k;
                }
                if(k==0)
                    continue;
                char* buffer;
                string comleft=prodleft[i];
                if(k==prodright[i].length()) {
                    prodleft[i]+=to_string(e);
                    prodleft[j]+=to_string(e);
                    prodright[i]="^";
                    prodright[j]=prodright[j].substr(k,prodright[j].length()-k);
                }
                else if(k==prodright[j].length()) {
                    prodleft[i]+=to_string(e);
                    prodleft[j]+=to_string(e);
                    prodright[j]="^";
                    prodright[i]=prodright[i].substr(k,prodright[i].length()-k);
                }
                else {
                    prodleft[i]+=to_string(e);
                    prodleft[j]+=to_string(e);
                    prodright[j]=prodright[j].substr(k,prodright[j].length()-k);
                    prodright[i]=prodright[i].substr(k,prodright[i].length()-k);
                }
                int l;
                for(l=j+1;l<p;++l) {
                    if(comleft==prodleft[l]&&com==prodright[l].substr(0,fmin(k,prodright[l].length()))) {
                        prodleft[l]+=to_string(e);
                        prodright[l]=prodright[l].substr(k,prodright[l].length()-k);
                    }
                }
                prodleft.push_back(comleft);
                prodright.push_back(com+prodleft[i]);
                ++p;
                ++e;
            }
        }
    }
    cout<<"\n\nNew productions";
    for(i=0;i<p;++i) {
        cout<<"\n"<<prodleft[i]<<"->"<<prodright[i];
    }
    return 0;
}
