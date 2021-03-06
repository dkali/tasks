// https://leetcode.com/problems/minimum-index-sum-of-two-lists

// Suppose Andy and Doris want to choose a restaurant for dinner, and they both have a list of favorite restaurants represented by strings.

// You need to help them find out their common interest with the least list index sum. If there is a choice tie between answers, output all of them with no order requirement. You could assume there always exists an answer.

// Example 1:
// Input:
// ["Shogun", "Tapioca Express", "Burger King", "KFC"]
// ["Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"]
// Output: ["Shogun"]
// Explanation: The only restaurant they both like is "Shogun".

// Example 2:
// Input:
// ["Shogun", "Tapioca Express", "Burger King", "KFC"]
// ["KFC", "Shogun", "Burger King"]
// Output: ["Shogun"]
// Explanation: The restaurant they both like and have the least index sum is "Shogun" with index sum 1 (0+1).

// Note:
// The length of both lists will be in the range of [1, 1000].
// The length of strings in both lists will be in the range of [1, 30].
// The index is starting from 0 to the list length minus 1.
// No duplicates in both lists.

#include <iostream>
#include <vector>
#include <map>
#include <limits>
 
using namespace std;
 
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> result;
        map<string, int> *tmpTable = new map<string, int>;
        map<string, int> *common = new map<string, int>;
 
        //build tmpTable
        for (int i = 0; i < list1.size(); i++){(*tmpTable)[list1[i]] = i;}
        for (int i = 0; i < list2.size(); i++){
            if (tmpTable->find(list2[i]) != tmpTable->end()){
                (*common)[list2[i]] = tmpTable->at(list2[i]) + i;
            }
        }
        delete tmpTable;
 
        //find minimum distance
        int min = INT_MAX;
        for (auto it = common->begin(); it != common->end(); ++it){
            if (it->second == min){
                result.push_back(it->first);
            }
            if (it->second < min){
                result.clear();
                result.push_back(it->first);
                min = it->second;
            }
        }
        delete common;
 
        return result;
    }
};