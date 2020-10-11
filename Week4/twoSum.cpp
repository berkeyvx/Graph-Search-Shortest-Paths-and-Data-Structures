#include <iostream>
#include <vector>
#include <utility>
#include <unordered_set>

std::pair<int, int> twoSum(int targetSum, std::vector<int> arr);

int main(){
    
    std::vector<int> arr {0,5,23,4,1,3,6,7};
    int targetSum = 5;
    auto p = twoSum(targetSum, arr);
    std::cout << p.first << " " << p.second;
    return 0;
}


std::pair<int, int> twoSum(int targetSum, std::vector<int> arr){
    std::pair<int, int> p;
    std::unordered_set<int> set;
    for (auto& i: arr) {
        auto itr = set.find(targetSum - i);
        
        // Check if Target Sum - i is in hash table, if not insert i and continue
        if (itr == set.end()) {
            set.insert(i);
            continue;
        }
        
        // make pair and return pair
        else{
            p = std::make_pair((*itr), i);
            return p;
        }
    }
    
    return p;
}
