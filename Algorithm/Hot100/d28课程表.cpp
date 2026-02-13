#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        // 1. 初始化入度数组和邻接表
        vector<int> inDegree(numCourses, 0);
        // 使用 vector<vector<int>> 比 unordered_map 在这种连续索引场景下效率更高
        vector<vector<int>> adj(numCourses);

        for (const auto &pre : prerequisites)
        {
            int course = pre[0];    // 被锁定的课
            int preCourse = pre[1]; // 解锁条件
            inDegree[course]++;     // 入度++
            adj[preCourse].push_back(course); // 放到解锁队列中
        }

        // 2. 将所有入度为 0 的课程放入队列
        queue<int> q;
        for (int i = 0; i < numCourses; ++i)
        {
            if (inDegree[i] == 0)
            {
                q.push(i);
            }
        }

        // 3. 开始 BFS 拓扑排序
        int count = 0;
        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            count++;

            // 遍历当前课程的所有后续课程
            for (int nextCourse : adj[curr])
            {
                inDegree[nextCourse]--; // 移除当前依赖
                if (inDegree[nextCourse] == 0)
                {
                    q.push(nextCourse);
                }
            }
        }

        // 4. 如果计数等于课程总数，说明没有环
        return count == numCourses;
    }
};