#include "tools.h"

class VolToShoulder
{
public:
    VolToShoulder(const int& x, const int& y,const std::string& path);//xy:音量键按下要按下的坐标,path:音量键的输入节点
    ~VolToShoulder();
    void start();
private:
    std::thread ReadEventAndTouchThread;//循环读取事件并触摸的线程
    int x{};
    int y{};
    touch touchTest{};
    int fd{};
private:
    void ReadEventAndTouch();
};