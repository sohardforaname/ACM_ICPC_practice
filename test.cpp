#include <algorithm>
#include <cstdio>
#include <string>

void FindShortestSeparator(
    std::string* start,
    const std::string& limit)
{
    // Find length of common prefix
    size_t min_length = std::min(start->size(), limit.size());
    size_t diff_index = 0;

    //查找start和limit的相同的字符
    while ((diff_index < min_length) && ((*start)[diff_index] == limit[diff_index])) {
        diff_index++;
    }

    //如果一个另一个的前缀的话，则无需改变
    if (diff_index >= min_length) {
        // Do not shorten if one string is a prefix of the other
    } else {
        //改变start值，作为结果返回
        uint8_t diff_byte = static_cast<uint8_t>((*start)[diff_index]);
        if (diff_byte < static_cast<uint8_t>(0xff) && diff_byte + 1 < static_cast<uint8_t>(limit[diff_index])) {
            (*start)[diff_index]++;
            start->resize(diff_index + 1);
        }
    }
    printf("%s %s", start->c_str(), limit.c_str());
}

int main()
{
    auto str1 = std::string("aaabde");
    auto str2 = std::string("aaacde");
    FindShortestSeparator(&str1, str2);
    return 0;
}