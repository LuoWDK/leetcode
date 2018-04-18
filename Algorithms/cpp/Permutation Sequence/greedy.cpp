
class Solution {
public:
    string getPermutation(int n, int k) {
		string str = "";
		if (1 == n)
		{
			str = "1";
			return str;
		}

        unsigned int nums = 1;
		vector<int> left(n);
		left[0] = 1;
		for (int i = 2; i <= n; ++i)
		{
			nums *= i;
			left[i-1] = i;
		}
        nums /= n;

		int length = n, index;
		while (length != 1 && k > 0)
		{
			index = (k-1) / nums;
			str += ('0' + left[index]);
            for (int i = index; i < length-1; ++i)
            {
                left[i] = left[i+1];
            }
			left.pop_back();
			k -= (nums * index);
			--length;
            nums /= length;
		}
		for(int i = 0; i < left.size(); ++i)
		{
			str += (left[i] + '0');
		}

		return str;
    }
};
