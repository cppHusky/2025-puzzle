# CountLightsOff

本题是 LightsOff 游戏的加强版。

在 LightsOff 中，你可以看到每个格子中的灯是开是关；但是在 CountLightsOff 中，你只能知道当前有多少灯是开着的。

棋盘大小为 $6\times6$.

## 交互方法

（如果可能的话，第一回合开始之前输出一个 `count_on`）

输入 `i` 和 `j` 表示要点击的位置， `i` 和 `j` 的取值范围都是 1-6 之内的整数。

输出 `count_on` 表示本次点击操作之后，现在开着的灯的数量。

通关条件：`count_on==0`
