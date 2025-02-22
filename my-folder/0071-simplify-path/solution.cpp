class Solution {
public:
    bool isDir(string path) {
        return (path != "/" && path != ".." && path != ".");

    }

    string simplifyPath(string path) {
        stack<string> s;
        stringstream ss(path);
        string token;
        while (getline(ss, token, '/')) {
            if (token == "." || token == "") {
                continue;
            } else if (token == "..") {
                if (!s.empty()) 
                    s.pop();
            } else {
                s.push(token);
            }
        }

        string result = "";
        while (!s.empty()) {
            result = "/" + s.top() + result;
            s.pop();
        }

        return result.empty() ? "/" : result;
    }
};
