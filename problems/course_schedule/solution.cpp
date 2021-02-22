class Solution {
    bool detectCycle(vector<vector<int>>& dep, vector<int>& visited, int curr){
        //cout<<curr;
        //cout<<visited[curr];
        
        if(visited[curr] == 1) return true;
        visited[curr]=1;
        // DFS, check all the subject dependencies recursively
        for(int i=0; i<dep[curr].size(); i++) 
            if(visited[dep[curr][i]]!=2)  // If Not already in processed state
                if(detectCycle(dep, visited, dep[curr][i]))
                    return true;
        
        // Mark the subject as processed
        visited[curr]=2;
        return false;
    }
public:        
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        vector<vector<int>> dep(numCourses);
        for(int i=0; i<pre.size(); i++){
            dep[pre[i][0]].push_back(pre[i][1]);
        }
        vector<int> visited(numCourses, 0);
        for(int i=0; i<numCourses; i++)
            if(visited[i]==0)       
                if(detectCycle(dep, visited, i))    
                    return false;
        return true;
    }
};
    
