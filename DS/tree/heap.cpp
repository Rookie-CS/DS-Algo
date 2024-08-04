#pragma once
#include <iostream>
#include <vector>

using namespace std;

/*最大堆的实现*/
class MaxHeap
{
private:
    vector<int> Elements;
    int Size;

public:
    /// 创建
    MaxHeap();
    /// 大小
    int size();
    /// []重载
    int& operator[](int index);
    /// 插入
    void InSert(int x);
    /// 最大元素
    int Max();
    /// 判断空堆
    bool IsEmpty();
    /// 删除最大元素
    int DeleteMax();

};

/// @brief 创建
MaxHeap::MaxHeap()
{
    this->Elements.push_back(INT32_MAX);
    this->Size = 0;
}

/// @brief 大小
/// @return 
int MaxHeap::size()
{
    return this->Size;
}

/// @brief [] 重载
/// @param index 下标
/// @return 
int& MaxHeap::operator[](int index) {
    if(index > Size || index < 0){
        std::cout << "访问越界[max index:" << Size  << "]" << std::endl;
        index = 0;
    }   

    return this->Elements[index];  
}

/// @brief 插入
/// @param x 插入元素
void MaxHeap::InSert(int x)
{
    int idx = ++this->Size;
    this->Elements.push_back(x);
    for( ; this->Elements[idx/2] < x; idx /= 2)
        this->Elements[idx] = this->Elements[idx/2];
    this->Elements[idx] = x;
}

/// @brief 判断是否是空堆
/// @return 
bool MaxHeap::IsEmpty()
{
    return !this->Size;
}

/// @brief 堆的最大值
/// @return 
int MaxHeap::Max()
{
    if(this->Size)
        return this->Elements[1];
    else{
        std::cout << "空堆, 无最大值" << std::endl;
        return this->Elements[0];
    }
}

/// @brief 删除最大元素
/// @return 最大元素
int MaxHeap::DeleteMax()
{
    if(this->IsEmpty())
    {
        std::cout << "空栈, 无法删除" << std::endl;
        return this->Elements[0];
    }
    int Parent, Child;
    int MaxItem = this->Max();
    int temp = this->Elements[this->Size--];
    this->Elements.pop_back();

    for( Parent = 1; Parent*2 <= this->Size; Parent=Child )
    {
        Child = Parent * 2;
        if( Child != this->Size && this->Elements[Child] < this->Elements[Child+1])
            Child++;
        if( temp >= this->Elements[Child] )
            break;
        else
            this->Elements[Parent] = this->Elements[Child];
    }
    this->Elements[Parent] = temp;

    return MaxItem;
}


template<typename T>
void Print(const T& vec, int start = 0, int end = 0)
{
    int length = vec.size();
    if(end <= 0) end = length + end;
    if(end <= 0 || end > length)
    {
        cout << "END越界[end=" << end << "]" << endl;
        return;
    }
    if(start < 0) start = length - start;
    if(start < 0 || start >= length)
    {
        cout << "START越界[start=" << start << "]" << endl;
        return;
    }
    for(int i = start; i < end; i++)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}