class Solution {
public:
    bool isPalindrome(string s) {
        string sentence="";

        for(char ch:s){
            if(isalnum(ch)){
                sentence +=tolower(ch);
            }
        }
        int i=0,j=sentence.size()-1;
        while(i<j){
            if(sentence[i]!=sentence[j]){
                return false;
            }
             i++;
             j--;
        }
        return true;
    }
};
