#include "Poller.h"
#include "EPollPoller.h"
#include <stdlib.h>

// EventLoop 可以通过该接口获取默认的 IO 复用的具体实现
Poller *Poller::newDefaultPoller(EventLoop *loop)
{
    if (::getenv("MUDUO_USE_POLL"))
    {
        return nullptr;  // 生成 poll 实例
    }
    else
    {
        return new EPollPoller(loop);  // 生成 epoll 实例
    }
}