//
//  PrettyPrint.cpp
//  CodePathPrework
//
//  Created by Sudipta Bhowmik on 7/10/17.
//  Copyright © 2017 Sudipta Bhowmik. All rights reserved.
//

#include "PrettyPrint.hpp"

#include <stdio.h>
#include <vector>
using namespace std;

vector<vector<int> > prettyPrint(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int size =  2 * A - 1;
    vector<vector<int>> out(size, vector<int>(size));
    //int arr[7][7];
    
    
    
    for (int i = 0; i <= size/2; i++) {
        for (int j = i; j < size - i; j++) {
            
            out[i][j] = out[j][i] = A - i;
            
            out[size - i - 1][j] = out[j][size - i - 1] = A - i;
        }
    }
    
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout <<out.at(i).at(j)<<" ";
        }
        cout<<endl;
    }
    
    return out;
    
}