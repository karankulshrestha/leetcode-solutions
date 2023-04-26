class Solution {
public:
    int addDigits(int num) {
        int sum = 0;
        if(num == 0) {
            return 0;
        } else if(to_string(num).length() == 1) {
            return num;
        } else {
            int n = num;
            while(n != 0) {
                sum += n % 10;
                n = n / 10;
            }
        }
        return addDigits(sum);;
    }
};