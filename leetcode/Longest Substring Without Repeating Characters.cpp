class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        
        if(s.size() == 0){
            return 0;
        }
        if(s.size() == 1){
            return 1;
        }
        int windows_size = 2;
        bool b = true;
        vector<char> l;
        string tmp_s;
        for(int i = 0; i<s.size(); ++i){
            b = true;
            if(i+windows_size > s.size()){
                break;
            }
            while(b){
                tmp_s.clear();
                //substr(a,b);   a是string index, 
                //b是指这个index后面多少个数，b不是index而是数量
                tmp_s = s.substr(i,windows_size);
                
                int before_size = tmp_s.size();
                
                vector<char> tmp_s_v(tmp_s.begin(), tmp_s.end());
                sort( tmp_s_v.begin(), tmp_s_v.end() );
                tmp_s_v.erase(unique( tmp_s_v.begin(), tmp_s_v.end() ), tmp_s_v.end() );
                int after_size = tmp_s_v.size();
                
                if (before_size != after_size){
                    b = false;
                } else{
                    windows_size++;
                }
                
                if(i+windows_size > s.size()){
                    break;
                }
                
                    
            }
            
        }
        
        return (windows_size-1);
    }
};