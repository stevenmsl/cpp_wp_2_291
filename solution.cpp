#include "solution.h"
#include "util.h"
#include <unordered_map>
#include <algorithm>
#include <string>
#include <queue>
#include <sstream>
#include <functional>
#include <math.h>
using namespace sol291;
using namespace std;

/*takeaways
  - you build each pattern starting with only one char in the str
    - you then discard it and look for longer substring from str
      as the next candidate if the current shorter one is not working

  - use pattern=abab str=redblueredblue as an example
  - m[a] ="r" (p=0,r=0), assume a="r"
    - m[b]="e" (p=1,r=1,i=1), assume b="e"
      - the next pattern is 'a' (p=2,r=2), so we are looking for "r"!
        - t="d" (p=2,r=2,i=2) (x) not a match (we could just stop here)
        - t="db" (p=2,r=2,i=3) (x) not a match
        ...
        - t="dblueredblue" (x)
      - so we know m[b]="e" won't work, remove it
    - m[b]="ed", (p=1,r=1,i=2), assume b="ed"
      - the next pattern is 'a' (p=2,r=3), so we are still looking for "r"!
        - t="b" (p=2,r=3,i=3) (x)
        - ... (x)
      - again we know m[b]="ed" won't work, remove it
    - ...
    - m[b]="edblue", (p=1,r=1,i=6)
      - the next pattern is 'a' (p=2,r=7), so we are still looking for "r"!
        - t="r" (p=2,r=7,i=7) (v) this is a match
          - moving on to next pattern 'b' (p=3,r=8), we are looking for "edblue"
          - t="e" (p=3,r=8,i=8) (x) not a match
          ...
          - t="edblue" (p=3,r=8,i=13) (v), a match
          - we are running out of pattern and the chars in str so we are good here
*/

bool Solution::match(string pattern, string str)
{
  auto m = unordered_map<char, string>();
  return _match(pattern, 0, str, 0, m);
}

bool Solution::_match(
    string pattern, int p, string str, int r, unordered_map<char, string> &m)
{
  /* both pattern and str are running out at the same time
     - we definitely found a match here
  */
  if (p == pattern.size() && r == str.size())
    return true;
  /* either one ran out fisrt means there is no match */
  if (p == pattern.size() || r == str.size())
    return false;
  auto c = pattern[p];
  for (auto i = r; i < str.size(); i++)
  {
    auto t = str.substr(r, i - r + 1);
    /* if the string match what I have recorded for
       the pattern c, then we can proceed to
       check the next pattern and the next char
       in the str
    */
    if (m.count(c) && m[c] == t)
    {
      if (_match(pattern, p + 1, str, i + 1, m))
        return true;
    }
    else if (!m.count(c))
    {
      auto newPattern = true;
      /* make sure that the existing patterns are
         not the same as the t that we are looking
         at right now
      */
      for (auto p : m)
        if (p.second == t)
          newPattern = false;
      if (newPattern)
      {
        /*record the pattern, and move on to the next char in pattern and str */
        m[c] = t;
        if (_match(pattern, p + 1, str, i + 1, m))
          return true;
        /* this (pattern(c), substring(t)) pair is no good, discard it
         */
        m.erase(c);
      }
    }
    /* move on to the next longer substring */
  }

  return false;
}
