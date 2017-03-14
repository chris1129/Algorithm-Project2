//
//  main.cpp
//  Alg_proj2
//
//  Created by Sheng-Yung Cheng on 2016/11/17.
//  Copyright © 2016年 Sheng-Yung Cheng. All rights reserved.
//

#include <iostream>
#include <vector>
#include<fstream>
using namespace std;
int main(int argc, const char * argv[]) {
    ifstream infile;
    infile.open ("/P2_5Cases/input2.txt");
    string input1;
    string input2;
    if(infile.is_open())
    { infile>>input1;
        infile>>input2;}
    vector<vector<int>>opt;
    vector<vector<char>>optseq;
    vector<int> init(input2.size()+1,0);
    vector<char> initseq(input2.size()+1,'-');
      for(int i=0;i<input1.size()+1;i++)
    {
        opt.push_back(init);
        optseq.push_back(initseq);
        
    }
    for(int i=1;i<input1.size()+1;i++){
        for(int j=1;j<input2.size()+1;j++){
            if(input1[i-1]==input2[j-1]){
                opt[i][j]=opt[i-1][j-1]+1;
                optseq[i][j]='@';
                
            }else if(opt[i][j-1]>=opt[i-1][j]){
            
                opt[i][j]=opt[i][j-1];
                optseq[i][j]='<';
            }else{
                opt[i][j]=opt[i-1][j];
                optseq[i][j]='^';
                
            }
        
        }
        
    }
    int i=(int)input1.size();
    int j=(int)input2.size();
    string ans;
    while(i>0&&j>0){
    
        if(optseq[i][j]=='@'){
        
            ans.push_back(input1[i-1]);
            i--;
            j--;
        }else if(optseq[i][j]=='^'){
            i--;
        }else{j--;}
    }
    reverse(ans.begin(), ans.end());
    ofstream output;
    output.open("/P2_5Cases/StudentSolution.txt");
    output<<opt[input1.size()][input2.size()]<<endl<<ans<<endl;

    return 0;
}
