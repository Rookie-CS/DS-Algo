#pragma once
#include <iostream>
#include <stack>

// 二叉树节点类
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    // 构造函数
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


// 二叉树类
class BinaryTree {
private:
    TreeNode* root;

    // 递归插入节点的辅助函数
    TreeNode* insertRecursive(TreeNode* current, int val) {
        if (current == nullptr) {
            return new TreeNode(val);
        }
        if (val < current->val) {
            current->left = insertRecursive(current->left, val);
        } else if (val > current->val) {
            current->right = insertRecursive(current->right, val);
        }
        return current;
    }


    /// @brief 前序遍历
    /// @param node 
    void preorderRecursive(TreeNode* node) {
        if (node != nullptr) {
            std::cout << node->val << "\t";
            preorderRecursive(node->left);
            preorderRecursive(node->right);
        }
    }
    
    /// @brief 中序遍历
    /// @param node 
    void inorderRecursive(TreeNode* node) {
        if (node != nullptr) {
            inorderRecursive(node->left);
            std::cout << node->val << "\t";
            inorderRecursive(node->right);
        }
    }

    /// @brief 后序遍历
    /// @param node 
    void postorderRecursive(TreeNode* node) {
        if (node != nullptr) {
            postorderRecursive(node->left);
            postorderRecursive(node->right);
            std::cout << node->val <<  "\t";
            
        }
    }

    /// @brief 堆栈前序遍历
    /// @param root 
    void preorderRecursiveStack(TreeNode* root) {
        TreeNode* node = root;
        std::stack<TreeNode*> stk;
        while (node || !stk.empty())
        {
            while (node)
            {
                std::cout << node->val << "\t";
                stk.push(node);
                node = node->left;
            }
            if(!stk.empty())
            {
                node = stk.top();
                stk.pop();
                node = node->right;
            }
            
            
        }
        
    }
    
    /// @brief 堆栈中序遍历
    /// @param root 
    void inorderRecursiveStack(TreeNode* root) {
        TreeNode* node = root;
        std::stack<TreeNode*> stk;
        while (node || !stk.empty())
        {
            while (node)
            {
                stk.push(node);
                node = node->left;
            }
            if(!stk.empty())
            {
                node = stk.top();
                stk.pop();
                std::cout << node->val << "\t";
                node = node->right;
            }
            
        }
    }

    /// @brief 堆栈后序遍历
    /// @param root
    void postorderRecursiveStack(TreeNode* root) {
        TreeNode* node = root;
        std::stack<TreeNode*> stk1;
        std::stack<TreeNode*> stk2;
        stk1.push(root);
        while (!stk1.empty()) 
        {
            node = stk1.top();
            stk1.pop();
            stk2.push(node);

            if (node->left) {
                stk1.push(node->left);
            }
            if (node->right) {
                stk1.push(node->right);
            }
        }
        while (!stk2.empty())
        {
            std::cout << stk2.top()->val << "\t";
            stk2.pop();
        }
        
    }

public:
    // 构造函数
    BinaryTree() : root(nullptr) {}

    /// @brief 获取根节点
    /// @return 
    TreeNode* getroot()
    {
        return root;     
    }

    // 插入节点
    void insert(int val) {
        root = insertRecursive(root, val);
    }

    /// @brief 前序遍历
    void preorderTraversal(bool isstack = false) {
        if(isstack) 
        {
            std::cout << "堆栈先序遍历" << std::endl;
            preorderRecursiveStack(root);
        }
        else
        {
            std::cout << "递归先序遍历" << std::endl;
            preorderRecursive(root);
        }
        std::cout << std::endl;
    }
    /// @brief 中序遍历
    void inorderTraversal(bool isstack = false) {
        if(isstack)
        {
            std::cout << "堆栈中序遍历" << std::endl;
            inorderRecursiveStack(root);
        }
        else 
        {
            std::cout << "递归中序遍历" << std::endl;
            inorderRecursive(root);
        }
        std::cout << std::endl;
    }
    /// @brief 后序遍历
    void postorderTraversal(bool isstack = false) {
        if(isstack)
        {
            std::cout << "堆栈后序遍历" << std::endl;
            postorderRecursiveStack(root);
        }
        else
        {
            std::cout << "递归后序遍历" << std::endl;
            postorderRecursive(root);
        }
        std::cout << std::endl;
    }



};