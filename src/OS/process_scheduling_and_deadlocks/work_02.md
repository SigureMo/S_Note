# 作业 2

-  一台计算机有 **6** 台磁带机，由 **n** 个进程竞争使用，每个进程可能需要 **2** 台磁带机，那么 **n** 是多少时，系统才没有死锁的危险？

   每个都差一个，当 n=5 时仍然不会发生死锁，即 $n \leq 5$

-  一台计算机有 **m** 台磁带机，由 **10** 个进程竞争使用，每个进程可能需要 **3** 台磁带机，那么 **m** 是多少时，系统才没有死锁的危险？

   仍然是每个都差一个，也就是 20 个资源时是可能发生死锁的，这时候只需要增加一个就可以解除死锁状态，即 $m = 21$