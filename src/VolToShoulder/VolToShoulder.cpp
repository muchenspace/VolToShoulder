#include "VolToShoulder.h"
#include <fcntl.h>
#include <unistd.h>
#include <iostream>
#include <linux/input.h>

VolToShoulder::VolToShoulder(const int& x, const int& y,const std::string& path)
{
    this->x = x;
    this->y = y;
    this->fd = this->fd = open(path.c_str(), O_RDWR);
}

void VolToShoulder::start()
{
    ioctl(this->fd, EVIOCGRAB, 0x1);//独占输入,只有此进程才能接收到事件 --
    this->ReadEventAndTouchThread = std::thread(&VolToShoulder::ReadEventAndTouch, this);
}


void VolToShoulder::ReadEventAndTouch()
{
    input_event ie{};
    while (1)
    {
        read(this->fd, &ie, sizeof(ie));
        if (ie.type == EV_KEY && ie.code == KEY_VOLUMEUP && ie.value == 1 ||
            ie.type == EV_KEY && ie.code == KEY_VOLUMEDOWN && ie.value == 1)
        {
            touchTest.touch_down(110, {x, y});
        }
        if (ie.type == EV_KEY && ie.code == KEY_VOLUMEUP && ie.value != 1 ||
            ie.type == EV_KEY && ie.code == KEY_VOLUMEDOWN && ie.value != 1)
        {
            touchTest.touch_up(110);
        }
    }
}

VolToShoulder::~VolToShoulder()
{
    close(this->fd);
    ReadEventAndTouchThread.detach();
}