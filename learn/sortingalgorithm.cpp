#include <iostream>
#include <algorithm>
#include <vector>

int main(){
    int nums[] = {5,4,5,66,54,55,34,32,67,22,5,3,8,1};
    int n = sizeof(nums)/sizeof(nums[0]);
    std::sort(nums, nums+n);
    std::cout<< "Sorted array: "<<std::endl;
    for(int i = 0; i < n; i++){
        std::cout<< nums[i]<< std::endl;
    }

    std::vector<int> list = {5,4,5,66,54,55,34,32,67,22,5,3,8,1};
    std::sort(list.begin(), list.end());
    std::cout<< "Sorted vector: "<<std::endl;
    for(int num:list){
        std::cout<< num << " " << std::endl;
    }

    return 0;
}