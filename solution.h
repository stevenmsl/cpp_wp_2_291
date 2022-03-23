#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <string>

using namespace std;
namespace sol291
{
  class Solution
  {
  private:
    static bool _match(
        string pattern, int p, string str, int r, unordered_map<char, string> &m);

  public:
    static bool match(string pattern, string str);
  };
}
#endif