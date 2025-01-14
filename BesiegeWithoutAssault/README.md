# BesiegeWithoutAssault

在平面直角坐标系中，敌军的初始位置是 $(0,0)$，你可以选择任意一个位置，向敌军发动突袭。

突袭开始后，敌军总是朝着远离你的方向移动（这种运动过程是连续的），你也可以指定任意位置进行移动。你与敌军的速度之比为 $2:1$。

你需要做到「围而不攻」，既不能过分靠近敌军（距离 $d<=1$），又不能让敌军逃出包围圈（$x^{2}+y^{2}<=10$）的范围。

当敌军累计走过的路线长度达到 $32$ 时，你的任务完成。

## 交互方法

第一回合，需要玩家输入一组 `you_x` `you_y` 作为初始位置。

接下来的每回合，输入玩家想要移动到的位置（没有限制）。

输出 `enemy_x` `enemy_y` `route_len` 表示本轮移动之后，敌军的位置，以及敌军总共走过的路线长度。

通关条件： `route_len>=32`

## TypeScript 接口说明

### `Coordinate`

> 位于 [lib/coordinate.ts](./lib/coordinate.ts)

这个类包含两个成员 `x`, `y`，分别表示位置的坐标参量。

### `initialize`

> 位于 [lib/operate.ts](./lib/operate.ts)

参数：`(you:Coordinate,enemy:Coordinate,you_x:number,you_y:number)`。没有返回值。

用于初始化 `you` 和 `enemy` 的位置。

`you_x` `you_y` 是玩家选定的初始位置，可以是任何值。

### `move`

> 位于 [lib/operate.ts](./lib/operate.ts)

- 参数：`(you:Coordinate,enemy:Coordinate,length:number,destx:number,desty:number)` 表示移动行为开始前 `you` 和 `enemy` 的位置，行动开始前敌军已经走过的距离 `length` ，以及玩家期望移动到的位置 `(destx,desty)`。
- 返回值：`[int,Coordinate,Coordinate,number]`，其中
    - 第一个值是返回状态
    - 第二个值表示 移动结束后玩家的位置
    - 第三个值表示 移动结束后敌军的位置
    - 第四个值表示 敌军总共走过的距离
仅在状态为 `0` 时，后面的值才有意义。
    - 若状态为 `0`，表明一切正常。
    - 若状态为 `1`，表明玩家距离敌军过近，任务失败。
    - 若状态为 `2`，表明敌军逃出包围圈范围，任务失败。
