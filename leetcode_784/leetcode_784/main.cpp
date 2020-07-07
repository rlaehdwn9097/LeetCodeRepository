//
//  main.cpp
//  leetcode_784
//
//  Created by Dongju Kim on 2020/07/07.
//  Copyright © 2020 Dongju Kim. All rights reserved.
//
class Solution {
public:
    //using for return value
    vector<string> v;
    
public:
    vector<string> letterCasePermutation(string S) {
        //'int index' is used in iterator for string S and condition for ending
        int index = 0;
        //backtracking function starts
        backtracking(S, index);
        
        //if backtracking function finishes return vector
        return v;
    }
    
    //function for checking conditions
    bool promising(string S, int index){
        if(index < S.length()){
            return true;
        }
        return false;
    }
    
    
    void backtracking(string S, int index){
    //1. check condition using 'bool promising()'
    if(promising(S, index)){
        //2. 'int c' is used in <switch-case> and <backtracking>
        //switch 'c' character to ascii number
        //we will check conditions in ascii number
        int c = (int)S[index];
        //3. check conditions 'c' in ascii number
        switch (c) {
            //if 48 <= c <= 57      for numbers '0~9'
            case 48 ... 57:
                backtracking(S, index+1);
                break;
            //if 65 <= c <= 90      for upper case 'A~Z'
            case 65 ... 90:
                //next step for original
                backtracking(S, index+1);
                //next step for tolower
                S[index] = (char)(c+32);
                backtracking(S, index+1);
                break;
            //if 97 <= c <= 122     for lower case 'a~z'
            case 97 ... 122:
                backtracking(S, index+1);
                S[index] = (char)(c-32);
                backtracking(S, index+1);
                break;
        }
        //backtracking
        S[index] = (char)c;
    }
    
    else {
        //if index == S.length()
        //pushback 'S' into 'vector<string> v'
        v.push_back(S);
    }
}
    
};
