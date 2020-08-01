#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using std::cin;
using std::sort;
using std::string;
using std::swap;

struct node
{
    string str;
    int cnt;
    node() : str(string()), cnt(0) {}
    node(const string &_str, int _cnt) : str(_str), cnt(_cnt) {}
    bool operator<(const node &a) const
    {
        return str < a.str;
    }
    node &operator=(const node &a)
    {
        this->cnt = a.cnt;
        this->str = a.str;
        return *this;
    }
    node(const node &a)
    {
        str = a.str;
        cnt = a.cnt;
    }
};

template <typename T>
struct vector
{
    T *buffer;
    size_t size;
    size_t capacity;
    vector() : buffer(nullptr), size(0), capacity(0) {}
    vector(const vector &vec)
    {
        buffer = new T[vec.capacity];
        size = vec.size;
        capacity = vec.capacity;
        for (int i = 0; i < size; ++i)
            buffer[i] = vec[i];
    }
    void reserve(size_t _size)
    {
        T *newBuffer = new T[_size];
        for (int i = 0; i < size; ++i)
            newBuffer[i] = buffer[i];
        delete[] buffer;
        buffer = newBuffer;
        capacity = _size;
    }
    void push_back(const T &_elem)
    {
        if (size == capacity)
            reserve((size << 1) + 1);
        buffer[size++] = _elem;
    }
    T &operator[](size_t _pos)
    {
        if (_pos < 0 || _pos >= size)
            exit(-1);
        return buffer[_pos];
    }
    void pop_back()
    {
        if (!size)
            exit(-1);
        --size;
    }
    ~vector()
    {
        delete[] buffer;
    }
};

vector<node> strvec[2];
void Insert(int _pos, string str)
{
    str.append(":");
    for (int i = 0; i < strvec[_pos].size; ++i)
        if (strvec[_pos][i].str == str)
        {
            ++strvec[_pos][i].cnt;
            return;
        }
    strvec[_pos].push_back({str, 1});
}
#include <cassert>

void calculate()
{
    printf("%-20s%-20s%s\n", "Unique", "Word Count", "Similarity");
    printf("%-20s%-10s%-10s%s\n", "Words", "Text-1", "Text-2", "Index (0 to 1)");
    int i = 0, j = 0;
    while (i < strvec[0].size && j < strvec[1].size)
    {
        if (strvec[0][i] < strvec[1][j])
        {
            printf("%-20s%-10d%-10d%-10d\n", strvec[0][i].str.c_str(),
                   strvec[0][i].cnt, 0, 0);
            ++i;
        }
        else if (strvec[1][j] < strvec[0][i])
        {
            printf("%-20s%-10d%-10d%-10d\n", strvec[1][j].str.c_str(),
                   0, strvec[1][j].cnt, 0);
            ++j;
        }
        else if (i < strvec[0].size && j < strvec[1].size)
        {
            printf("%-20s%-10d%-10d", strvec[0][i].str.c_str(),
                   strvec[0][i].cnt, strvec[1][j].cnt);
            int cnta = strvec[0][i].cnt, cntb = strvec[1][j].cnt;
            if (cnta > cntb)
                swap(cnta, cntb);
            printf("%.6f\n", 1.0 * cnta / cntb);
            ++i, ++j;
        }
    }
    while (i < strvec[0].size)
    {
        printf("%-20s%-10d%-10d%-10d\n", strvec[0][i].str.c_str(),
               strvec[0][i].cnt, 0, 0);
        ++i;
    }
    while (j < strvec[1].size)
    {
        printf("%-20s%-10d%-10d%-10d\n", strvec[1][j].str.c_str(),
               0, strvec[1][j].cnt, 0);
        ++j;
    }
    printf("\n\n");
}
void unique()
{
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < strvec[i].size; ++j)
            strvec[i][j].cnt = 1;
}

/*
one two two three three four four four four
zero one two three four five five five five five
*/

#include <sstream>
using std::stringstream;

int main()
{
    string a, b, tmp;
    printf("依次输入第一个字符串，回车，输入第二个字符串，回车\n");
    getline(cin, a);
    getline(cin, b);
    stringstream ss;
    ss << a;
    while (ss >> tmp)
        Insert(0, tmp);
    ss.clear();
    ss << b;
    while (ss >> tmp)
        Insert(1, tmp);

    sort(strvec[0].buffer, strvec[0].buffer + strvec[0].size);
    sort(strvec[1].buffer, strvec[1].buffer + strvec[1].size);

    calculate();
    unique();
    calculate();
    system("pause");
    return 0;
}