#include <iostream>
#include <tuple>
#include <vector>
#include <string>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol291;

/* Example 1:
  pattern = "abab", str = "redblueredblue" should return true. (a->red, b->blue)
*/
tuple<string, string, bool>
testFixture1()
{
  return make_tuple("abab", "redblueredblue", true);
}

/* Example 2:
  pattern = "aaaa", str = "asdasdasdasd" should return true. (a->asd)
*/
tuple<string, string, bool>
testFixture2()
{
  return make_tuple("aaaa", "asdasdasdasd", true);
}

/* Example 3:
  pattern = "aabb", str = "xyzabcxzyabc" should return false
*/
tuple<string, string, bool>
testFixture3()
{
  return make_tuple("aabb", "xyzabcxzyabc", false);
}

void test1()
{
  auto f = testFixture1();
  cout << "Test 1 - exepct to see " << get<2>(f) << endl;
  auto result = Solution::match(get<0>(f), get<1>(f));
  cout << "result: " << result << endl;
}
void test2()
{
  auto f = testFixture2();
  cout << "Test 2 - exepct to see " << get<2>(f) << endl;
  auto result = Solution::match(get<0>(f), get<1>(f));
  cout << "result: " << result << endl;
}
void test3()
{
  auto f = testFixture3();
  cout << "Test 3 - exepct to see " << get<2>(f) << endl;
  auto result = Solution::match(get<0>(f), get<1>(f));
  cout << "result: " << result << endl;
}

main()
{
  // test1();
  test2();
  // test3();
  return 0;
}