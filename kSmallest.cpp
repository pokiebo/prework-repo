//
//  kSmallest.cpp
//  CodePathPrework
//
//  Created by Sudipta Bhowmik on 7/10/17.
//  Copyright © 2017 Sudipta Bhowmik. All rights reserved.
//

#include "kSmallest.hpp"


int Partition(int Arr[], int start, int end) {
    
    
    
    int pivot = Arr[end];
    int left = start;
    int pIndex = start;
    
    for (left = start; left <= end - 1; left++) {
        if (Arr[left] <= pivot) {
            
            swap(Arr[left], Arr[pIndex]);
            pIndex++;
        }
    }
    swap(Arr[end], Arr[pIndex]);
    return pIndex;
    
}

int QuickSelect(int Arr[], int start, int end, int k) {
    
    
    int pIndex = Partition(Arr, start, end);
    
    if (pIndex - start == k - 1) {//Found the kth smallest element
        return Arr[pIndex];
    }
    
    if (k - 1 < pIndex - start) {//Search in left partition
        return QuickSelect(Arr, start, pIndex - 1, k);
    }
    
    if (k - 1 > pIndex - start) {//Search in right partition
        return QuickSelect(Arr, pIndex + 1, end, k - pIndex + start - 1);
    }
    
    return INT_MAX;
}

int kthsmallest(const vector<int> &A, int k) {
    int Arr[A.size()];
    for (int i = 0; i < A.size(); i++) {
        Arr[i] = A.at(i);
    }
    int ans = QuickSelect(Arr, 0, A.size() - 1, k);
    
    for (int i = 0; i < 5; i++) {
        cout << Arr[i]<<endl;
    }
    
    return ans;
}