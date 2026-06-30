class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // Build heap in O(n)
        priority_queue<int> maxHeap(stones.begin(), stones.end());

        while (maxHeap.size() > 1) {
            int a = maxHeap.top(); maxHeap.pop();
            int b = maxHeap.top(); maxHeap.pop();

            int diff = a - b;
            if (diff > 0) {
                maxHeap.push(diff);
            }
        }

        return maxHeap.empty() ? 0 : maxHeap.top();
    }
};