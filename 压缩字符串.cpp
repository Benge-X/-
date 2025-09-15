#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
//累啊累
using namespace std;
class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int write = 0; // 写指针
        int read = 0;  // 读指针

        while (read < n) {
            char current = chars[read];
            int count = 0;

            // 统计连续相同字符的个数
            while (read < n && chars[read] == current) {
                count++;
                read++;
            }

            // 写入字符
            chars[write++] = current;

            // 写入次数（如果大于 1）
            if (count > 1) {
                //哈机密纳梅鲁多
                int start = write;
                while (count > 0) {
                    chars[write++] = '0' + count % 10;
                    count /= 10;
                }
                // 数字是倒序写的，这里翻转过来
                reverse(chars.begin() + start, chars.begin() + write);
            }
        }

        return write;
    }
};

int main() {
    Solution solution;
    string input;
    cout << "请输入字符序列（不带空格，比如 aabbbcccc）: ";
    cin >> input;

    // 转换为字符数组
    vector<char> chars(input.begin(), input.end());

    // 压缩
    int newLength = solution.compress(chars);

    // 输出压缩后的结果
    cout << "压缩后长度: " << newLength << endl;
    cout << "压缩后的数组: [";
    for (int i = 0; i < newLength; i++) {
        cout << "\"" << chars[i] << "\"";
        if (i < newLength - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
