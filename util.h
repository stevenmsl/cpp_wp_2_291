#ifndef UTIL_H
#define UTIL_H

#include <vector>
#include <queue>
#include <set>
#include <string>
using namespace std;
namespace sol291
{
    class Util
    {
    public:
        static string toString(vector<string> input);
        static string toString(vector<int> input);
        static string toString(vector<vector<int>> input);
    };
}
#endif