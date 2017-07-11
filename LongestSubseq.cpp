//
//  LongestSubseq.cpp
//  CodePathPrework
//
//  Created by Sudipta Bhowmik on 7/10/17.
//  Copyright © 2017 Sudipta Bhowmik. All rights reserved.
//

#include "LongestSubseq.hpp"

#include <unordered_map>

int longestConsecutive(const vector<int> &A) {
    unordered_map <int, bool> map;
    
    for (int i = 0; i < A.size(); i++) {
        map[A.at(i)] = true;
    }
    
    int curr_max = 0;
    int max = 0;
    for (int i = 0; i < A.size(); i++) {
        
        int num = A.at(i);
        curr_max  = 1;
        
        
        //Remove current number from map
        map.erase(A.at(i));
        
        //Search for consequtive numbers greater than current num
        while (map.find(num + 1)!= map.end()){
            curr_max++;
            map.erase(num + 1);
            num++;
        }
        
        //Search for consequtive numbers less than current num
        num = A.at(i);
        while (map.find(num-1) != map.end()){
            curr_max++;
            map.erase(num - 1);
            num--;
        }
        
        if (curr_max > max) {
            max = curr_max;
        }
        
        
    }
    
    return max;
    
}