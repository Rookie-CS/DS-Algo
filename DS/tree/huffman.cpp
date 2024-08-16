#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode {
    int Weight;
    int value;
    TreeNode *Left, *Right;

    // 默认构造函数
    TreeNode() : Weight(0), value(0), Left(nullptr), Right(nullptr) {}
    TreeNode(int w, int v) : Weight(w), value(v), Left(nullptr), Right(nullptr) {}

    // 重载 > 运算符用于优先队列排序
    bool operator>(const TreeNode& other) const {
        return this->Weight > other.Weight;
    }

    // 重载 < 运算符
    bool operator<(const TreeNode& other) const {
        return this->Weight < other.Weight;
    }

    // 重载 == 运算符
    bool operator==(const TreeNode& other) const {
        return this->Weight == other.Weight;
    }

    // 重载 + 运算符用于合并两个节点的权重
    TreeNode operator+(const TreeNode& other) const {
        TreeNode node;
        node.Weight = this->Weight + other.Weight;
        node.value = 0;  // 默认初始化或自定义逻辑
        node.Left = nullptr;
        node.Right = nullptr;
        return node;
    }
};

int main() {
    priority_queue<TreeNode, vector<TreeNode>, greater<TreeNode>> min_heap;

    // 插入一些节点
    min_heap.push(TreeNode(10, 1));
    min_heap.push(TreeNode(5, 2));
    min_heap.push(TreeNode(20, 3));
    min_heap.push(TreeNode(1, 4));

    // 输出堆顶元素
    while (!min_heap.empty()) {
        TreeNode top = min_heap.top();
        cout << "Weight: " << top.Weight << ", value: " << top.value << endl;
        min_heap.pop();
    }

    return 0;
}
