class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> nextTask;

        vector<array<int, 3>> sortedTasks;
        for (int i = 0; i < tasks.size(); ++i) {
            sortedTasks.push_back({tasks[i][0], tasks[i][1], i});
        }

        sort(sortedTasks.begin(), sortedTasks.end());
        vector<int> tasksProcessingOrder;

        long long currTime = 0;
        int taskIndex = 0;

        while (taskIndex < tasks.size() || !nextTask.empty()) {
            if (nextTask.empty() && currTime < sortedTasks[taskIndex][0]) {
                currTime = sortedTasks[taskIndex][0];
            }

            while (taskIndex < sortedTasks.size() && currTime >= sortedTasks[taskIndex][0]) {
                nextTask.push({sortedTasks[taskIndex][1], sortedTasks[taskIndex][2]});
                ++taskIndex;
            }

            auto [processTime, index] = nextTask.top();
            nextTask.pop();

            currTime += processTime;
            tasksProcessingOrder.push_back(index);
        }

        return tasksProcessingOrder;
    }
};