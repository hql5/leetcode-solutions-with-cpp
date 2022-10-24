#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int partitionDisjoint(vector<int>& num) {
        for (int i=0; i < num.size(); i++)
        {
            int idx = num.max_size();
        }
        

        for (int i : num) {
            cout << i << "\t";
        }
        return 100;
    }
};

int main() {
    int tnum;
    vector<int> num;

    Solution slu;
    slu.partitionDisjoint(num);

    return 0;
}