class Solution {
public:
    string minWindow(string s, string t) {

        if(t.size() > s.size()){
            return "";
        }

        unordered_map<char,int> mp;

        // Store characters required from t
        for(int i = 0; i < t.size(); i++){
            mp[t[i]]++;
        }

        int countRequired = t.size();

        int i = 0, j = 0;

        int windowSize = INT_MAX;
        int start_idx = 0;

        while(j < s.size()){

            // Add s[j] to window
            if(mp[s[j]] > 0){
                countRequired--;
            }

            mp[s[j]]--;

            // Window contains all required characters
            while(countRequired == 0){

                int currWindowSize = j - i + 1;

                if(windowSize > currWindowSize){
                    windowSize = currWindowSize;
                    start_idx = i;
                }

                // Remove s[i]
                mp[s[i]]++;

                if(mp[s[i]] > 0){
                    countRequired++;
                }

                i++;
            }

            j++;
        }

        return windowSize == INT_MAX
            ? ""
            : s.substr(start_idx, windowSize);
    }
};
