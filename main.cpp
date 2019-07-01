#include <algorithm>
#include <cstring>
#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <sstream>

#include "../utils/VectorUtils.hpp"
#include "../utils/TreeUtils.hpp"

#include "../utils/PrintUtils.hpp"

using namespace std;

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#if defined(WIN32)
// nothing
#else
#pragma GCC optimise ("Ofast")


// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto _no_sync_ = []() {              // NOLINT
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

#endif

class Solution {
public:
  vector<vector<int>> levelOrderBottom(TreeNode *root) {
    vector<vector<int>> v;
    if (!root)
      return v;
    queue<const TreeNode *> q;
    q.push(root);
    int nodesAtLevel = 1;
    while (!q.empty()) {
      vector<int> ch;
      while (nodesAtLevel) {
        const TreeNode *tp = q.front();
        q.pop();
        ch.push_back(tp->val);
        if (tp->left) q.push(tp->left);
        if (tp->right) q.push(tp->right);
        --nodesAtLevel;
      }
      v.push_back(ch);
      nodesAtLevel = q.size();
    }
    reverse(v.begin(), v.end());
    return v;
  }
};

void test1() {

  vector<int> v{3, 9, 20};
  auto *t1 = new TreeNode(v);
  TreeNode *t20 = findItem(t1, 20);
  t20->left = new TreeNode(15);
  t20->right = new TreeNode(7);

  cout << " ? " << Solution().levelOrderBottom(t1) << endl;
//    cout << " ? " << Solution().func() << endl;
//    cout << " ? " << Solution().func() << endl;
}

void test2() {

}

void test3() {

}