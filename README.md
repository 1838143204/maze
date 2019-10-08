# 随机产生迷宫并找出通路

<font size=5> 算法分析与设计</font>

<font size=4>概念:</font>

> 可行方向:从当前位置出发,如果向相邻的位置行走,不会撞墙,且保证不会越界,则称该方向为当前节点的可行方向

> 可行节点:入口或者中间节点(经过该节点有到达入口和出口的通路),可行节点有两个不同的可行方向,且沿可行方向到达的下一个节点是可行节点

> 可行路径:从入口到出口的通路,连接所有可行节点

<font size=4>算法:</font>

> 利用递归的思想,从入口出发,如果该节点可行方向上的下一个节点是可行节点,则该节点是可行节点.
即可以定义递归函数,使其返回值为该节点的可行状态(是否为可行节点),并递归调用该函数,使该节点记录其他方向(除来时的方向)下一节点的可行状态,
并使该节点的可行状态改变为其余方向可行状态的并(即:当前节点可行状态=左边节点可行状态∪右边节点可行状态∪上方节点可行状态∪下方节点可行状态)

<font size=5>数据结构设计</font>

```C++
class node{
    public:
    bool state;//记录节点的状态(墙或通路)
    bool flag;//记录该节点是否是可行节点
    bool up;//向上是否可以出去
    bool down;//向下是否可以出去
    bool left;//向左是否可以出去
    bool right;//向右是否可以出去
    private:
    node();//构造函数
    bool GetState(){return state};//查看该位置是否可行走
    void ChangeState(bool new_taste){state=new_state};//改变该位置的状态,用于生成迷宫
    void ChangeFlag(bool new_flag){flag=new_flag};//改变该位置的可行状态,用于找寻通路
}
```