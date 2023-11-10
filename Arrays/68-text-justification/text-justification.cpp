class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();
        vector<vector<string>> lines;
        vector<int> spaces;

        vector<string> temp = {words[0]};
        int i = 1, prevLen = words[0].length();
        while(i<n){
            int curWordLength = words[i].length();
            int prevLineSpaces = temp.size();
            if(prevLen + prevLineSpaces + curWordLength > maxWidth){
                //if cannot add current word to prev line

                //adding prev line to ansvector
                lines.push_back(temp);
                spaces.push_back(maxWidth - prevLen);

                //creating new line
                prevLen = curWordLength;
                temp.clear();
                temp.push_back(words[i]);
            }
            else{
                //adding word to current line
                prevLen += curWordLength;
                temp.push_back(words[i]);
            }
            i++;
        }
        //adding last line
        lines.push_back(temp);
        spaces.push_back(maxWidth-prevLen);

        vector<string> ans;
        int sz = lines.size();
        //generating line string
        for(int j = 0;j<sz;++j){
            int numberOfWords = lines[j].size();
            int sp = spaces[j];
            string cur;
            //if last line or contains a single character
            if(j == sz-1 || numberOfWords==1){
                //left only justified
                for(int l = 0;l<numberOfWords;++l){
                    string s = lines[j][l];
                    cur += s;
                    //not to add space after last character if no extra space is there
                    if(sp){
                        cur += ' ';
                        sp--;
                    }
                }
                //padding extra space after last word
                if(sp) while(sp--) cur+=' ';
            }
            else{
                //left & right justified
                //extra space to be added after first word
                int spExtra = sp%(numberOfWords-1);
                sp = sp/(numberOfWords-1);
                for(int l = 0;l<numberOfWords;++l){
                    string s = lines[j][l];
                    cur += s;
                    //adding even space
                    if(l!=numberOfWords-1) for(int k=0;k<sp;++k) cur+=' ';
                    //adding extra space after first word only
                    if(spExtra){
                        cur += ' ';
                        spExtra--;
                    }
                }
            }
            ans.push_back(cur);
        }
        return ans;
    }
};