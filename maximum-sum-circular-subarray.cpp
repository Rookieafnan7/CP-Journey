#include<iostream>
#include<vector>
#include<map>
#include<bits/stdc++.h>
using namespace std;



class AttemptSolution1 {
public:
    int findSum(vector<int>& sumArr,int start, int end){
        int sum;
        
        // if(start-1)
        if(end>=start){
            sum = sumArr[end];
            if(start-1>=0){
                sum = sum - sumArr[start-1]; 
            }
        }else{
            sum = sumArr[sumArr.size()-1];
            if(start-1>=0){
                sum = sum - sumArr[start-1];
            }
            sum += sumArr[end];
        }
        return sum;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        map<int,pair<int,int>> sumMap;
        vector<int> sumArr;
        int temp = 0;
        for(int i = 0; i < nums.size(); i++){
            temp+=nums[i];
            sumArr.push_back(temp);
        }

        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j < nums.size(); j++){
                int start = i;
                int end = (i + j)%nums.size();
                int sum = findSum(sumArr,start,end);
                // cout<< start << " "<<end<<" "<<sum<<" "<<endl;
                sumMap[sum] = make_pair(start,end);
            }
        }
        return sumMap.rbegin()->first;

    }
};