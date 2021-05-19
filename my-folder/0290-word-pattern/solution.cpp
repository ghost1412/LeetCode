class Solution {
public:
    bool wordPattern(string pattern, string s) {
       vector<string>st(26," ");
        int j=0;
        string temp="";
        vector<string>v;
        for(int i=0;i<s.length();i++){
            if(s[i]==' '){
                v.push_back(temp);
                temp="";
            }
            else{
                temp+=s[i];
            }
        }
        v.push_back(temp);
        temp="";
        if(pattern.length()!=v.size()){
            return false;
        }
        
        vector<string>visited(26," ");
        set<string>see;
        for(int i=0;i<pattern.length();i++){
            if(st[pattern[i]-'a']!=" "){
                if(st[pattern[i]-'a']!=v[i]){
                    return false;
                }
                
            }
            else{
                if(see.find(v[i])!=see.end()){
                    return false;
                }
                st[pattern[i]-'a']=v[i];
                see.insert(v[i]);
            }
        }
       return true; 
        
    }
};
