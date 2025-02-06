class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string>ans;
        vector<string>rows={"qwertyuiop", "asdfghjkl", "zxcvbnm"};

        for(string word:words){
            string lower=word;
            for(char &c:lower) c=tolower(c);

            int row=-1,valid=1;
            for(int i=0;i<3;i++){
                if(rows[i].find(lower[0])!=string::npos){
                    row=i;
                    break;
                }
            }
            if (row == -1) continue;
            for(char c:lower){
                if(rows[row].find(c)==string::npos){
                    valid=0;
                    break;
                }
            }

            if(valid)ans.push_back(word);
        }

        return ans;

    }
};