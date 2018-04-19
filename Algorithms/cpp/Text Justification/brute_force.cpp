class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<vector<int>> layers;
        vector<int> temp(2, 1);
        string str;
        
        temp[0] = words[0].length();
        for (int i = 1; i < words.size(); ++i) {
            str = words[i];
            if (temp[0] + str.length() < maxWidth) {
                temp[0] += (str.length() + 1);
                ++temp[1];
            }
            else {
                layers.push_back(temp);
                temp[0] = str.length();
                temp[1] = 1;
            }
        }
        layers.push_back(temp);
        
        int rows = layers.size();
        vector<string> res(rows);
        int space, left, count = 0;
        for (int i = 0; i < rows-1; ++i) {
            temp = layers[i];
            str = "";
            if (temp[1] != 1) {
                space = 1 + (maxWidth - temp[0]) / (temp[1] - 1);
                left = (maxWidth - temp[0]) % (temp[1] - 1);
            }
            else {
                left = maxWidth - temp[0];
            }
            while (--temp[1]) {
                str.append(words[count++]);
                str.append(space + (left-- > 0 ? 1 : 0), ' ');
            }
            str.append(words[count++]);
            if (left > 0)
                str.append(left, ' ');          
            res[i] = str;
        }
        
        str = words[count++];
        while (count < words.size()) {
            str.append(" ");
            str.append(words[count++]);
        }
        str.append(maxWidth - layers[rows-1][0], ' ');
        res[rows-1] = str;
        
        return res;
    }
};

// "This    is    an",
// "example of text justification.             "
// "This    is    an",
// "example  of text","justification.  "
