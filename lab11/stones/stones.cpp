#include "stones.h"
#include <queue>
#include <algorithm>
#include <cstdlib>
using namespace std;

int lastStoneWeight(vector<int>& stones) {
 	//Add Implementation Here
    priority_queue<int> pq;
    for (unsigned int i = 0 ; i < stones.size(); i++){
        pq.add(stones[i]);
    }
    while ( pq.size()>=2){
        int x = pq.top()
        pq.pop();
        int y = pq.top();
        pq.pop();
        if ( x != y){
            int z = abs(x-y);
            pq.add(z);
        }
        
    }
    if ( pq.size()==1){
        int x = pq.top;
        pq.pop;
        return x;
    }
    else ( pq.empty() == 0){
        return 0;
    }
    
 }
