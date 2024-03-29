class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> hast_s;
        unordered_map<char,int> hast_t;
        if(s.length()<t.length()) return "";

        for(int i=0;i<t.length();i++){
            hast_t[t[i]]++;
        }
        
         int count=0, start=0,start_ind=-1,min_length=INT_MAX;
        for(int i=0;i<s.length();i++){
            hast_s[s[i]]++;
            if(hast_s[s[i]] <= hast_t[s[i]])count++;

            if(count==t.length()){
                while(hast_s[s[start]]>hast_t[s[start]]){
                    hast_s[s[start]]--;
                    start++;  
                }
                if(min_length>i-start+1){
                   min_length= i-start+1;
                   start_ind=start;
                }
            }
        }
        if(start_ind == -1)return "";
        else return s.substr(start_ind , min_length);
    }
};
