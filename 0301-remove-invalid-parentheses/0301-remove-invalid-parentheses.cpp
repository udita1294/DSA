
class Solution {
public:
    bool isValid(string s) {
        int count = 0;

        for (char ch : s) {
            if (ch == '(') {
                count++;
            }
            else if (ch == ')') {
                count--;

                if (count < 0) {
                    return false;
                }
            }
        }

        return count == 0;
    }

    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        queue<string> q;
        unordered_set<string> visited;

        q.push(s);
        visited.insert(s);

        bool found = false;

        while (!q.empty() && !found) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                string curr = q.front();
                q.pop();

                if (isValid(curr)) {
                    ans.push_back(curr);
                    found = true;
                }

                if (found) continue;

                for (int j = 0; j < curr.size(); j++) {
                    if (curr[j] != '(' && curr[j] != ')') {
                        continue;
                    }

                    string next = curr.substr(0, j) +
                                  curr.substr(j + 1);

                    if (visited.find(next) == visited.end()) {
                        visited.insert(next);
                        q.push(next);
                    }
                }
            }
        }

        return ans;
    }
};
