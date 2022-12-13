/*
 * @Author: lhq
 * @Date: 2022-12-13 14:52:09
 * @LastEditTime: 2022-12-13 15:01:06
 * @LastEditors: lhq
 * @Description: 判断句子是否包含所有字符
 * @FilePath: \leetcode-solutions-with-cpp\check_if_the_sentence_is_pangram.cc
 */
#include <iostream>
#include <string>
using namespace std;
 
class Solution {
public:
    bool checkIfPangram(string sentence) {
        int n = sentence.size();
        if (n < 26) return false;
        int tmp = 67108863, ret = 0;
        for (int i = 0; i < n; i++) {
            int mv = sentence[i] - 'a';
            ret |= 1 << mv;
        }
        if ((tmp ^ ret) == 0) 
            return true;
        else 
            return false;
    }
};

int main() {
    Solution slu;
    string s = "jwtucoucmdfwxxqnxzkaxoglszmfrcvjoiunqqausaxxaaijyqdqgvdnqcaihwilqkpivenpnekioyqujrdrovqrlxovcucjqzjsxmllfgndfprctxvxwlzjtciqxgsxfwhmuzqvlksyuztoetyjugmswfjtawwaqmwyxmvo";
    cout << slu.checkIfPangram(s);
    
    return 0;
}