
// https://leetcode.com/problems/bitwise-ors-of-subarrays/description/
//re-write by using C++ (for recalling c++ knowledge)
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        if(A.size() < 2)
            return A.size();
        
        if(A.size() == 2){
            vector<int> s;
            s.push_back( A[0] );
            s.push_back(A[1]);
            s.push_back(A[0]|A[1]);
            
            sort( s.begin(), s.end() );
            s.erase(unique(s.begin(), s.end()), s.end());
            return s.size();
        }
        vector<vector<int>> s;
        vector<int> one = {A.back()};
        vector<int> two = {A[A.size()-2]|A.back(), A[A.size()-2]};
        s.push_back(one);
        s.push_back(two);
        
        vector<int> testint;
        for(int idx = A.size()-3; idx >= 0; --idx){
            testint.clear();
            for(auto &element : s.back()){
                testint.push_back(A[idx] | element);
            }
            testint.push_back(A[idx]);
            s.push_back(testint);
        }
        vector<int> result;
        for(auto &temp : s){
            copy(temp.begin(), temp.end(), back_inserter(result));

        }
        
        sort( result.begin(), result.end() );
        result.erase(unique(result.begin(), result.end()), result.end());
        return result.size();
        
    }
};