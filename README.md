# Practice

My practice code here.

******

+ PurpleBook：算法竞赛入门(紫色)的练习题和读书笔记。

+ 1DataStructure：是数据结构学习过程中的code。

+ day xx ：是学习过程中的练习题code。

+ 希望杯：第一次参加的学校组织的编程比赛的code。

*****

day01

> 1. 打印100~200 之间的素数 
> 2. 输出乘法口诀表 
> 3. 判断1000年---2000年之间的闰年

day02

> 1. 给定两个整形变量的值，将两个值的内容进行交换。 
>
> 2. 不允许创建临时变量，交换两个数的内容（附加题） 
> 3. 求10 个整数中最大值。 
> 4. 将三个数按从大到小输出。 
>
> 5. 求两个数的最大公约数。 

day03

> 1. 将数组A中的内容和数组B中的内容进行交换。（数组一样大） 
>
> 2. 计算1/1-1/2+1/3-1/4+1/5 …… + 1/99 - 1/100 的值。 
> 3. 编写程序数一下 1到 100 的所有整数中出现多少次数字9。 

day04

> 1. 输出菱形。
> 2. 求出0～999之间的所有“水仙花数”并输出。
> 3. 求Sn=a+aa+aaa+aaaa+aaaaa的前5项之和，其中a是一个数字，例如：2+22+222+2222+22222 
> 4. 编写一个程序，它从标准输入读取C源代码，并验证所有的花括号都正确的成对出现。

day05

> 1. 完成猜数字游戏。 
>
> 2. 写代码可以在整型有序数组中查找想要的数字，找到了返回下标，找不到返回-1.（折半查找） 
>
> 3. 编写代码模拟三次密码输入的场景。 
>    最多能输入三次密码，密码正确，提示“登录成功”,密码错误，可以重新输入，最多输入三次。三次均错，则提示退出程序。 
>
> 4. 编写一个程序，可以一直接收键盘字符，如果是小写字符就输出对应的大写字符，如果接收的是大写字符，就输出对应的小写字符，如果是数字不输出。

day06

> 1. 递归和非递归分别实现求第n个斐波那契数。 
>
> 2. 编写一个函数实现n^k，使用递归实现 
>
> 3. 写一个递归函数DigitSum(n)，输入一个非负整数，返回组成它的数字之和，例如，调用DigitSum(1729)，则应该返回1+7+2+9，它的和是19 
>
> 4. 编写一个函数reverse_string(char * string)（递归实现） 
>    实现：将参数字符串中的字符反向排列。 
>    要求：不能使用C函数库中 
>    的字符串操作函数。 
>
> 5. 递归和非递归分别实现strlen 
> 6. 递归和非递归分别实现求n的阶乘 
> 7. 递归方式实现打印一个整数的每一位 

day07

> 1. 实现一个函数，打印乘法口诀表，口诀表的行数和列数自己指定， 
>    输入9，输出9*9口诀表，输出12，输出12*12的乘法口诀表。 
>
> 2. 使用函数实现两个数的交换。 
>
> 3. 实现一个函数判断year是不是润年。 
>
> 4. 创建一个数组， 
>    实现函数init（）初始化数组、 
>    实现empty（）清空数组、 
>    实现reverse（）函数完成数组元素的逆置。 
>    要求：自己设计函数的参数，返回值。 
>
> 5. 实现一个函数，判断一个数是不是素数。

day08

> 扫雷游戏**MyMineClearanceGame**
>
> 1. 第一次下子，不炸死。 
> 2. 坐标周围没雷，可以实现展开。 
>
> ![gif](https://wx2.sinaimg.cn/mw690/006wR0dcly1fwjain95mug308w06ogr9.gif)

day09

> 三子棋游戏**MySanZiChessGame**
>
> 增加了行列扫描，如果玩家一行或者一列即将胜利，下一步堵住他。
>
> ![git](https://wx1.sinaimg.cn/mw690/006wR0dcly1fwjam76g21g308w06ojwp.gif)

day10

> 1. 写一个函数返回参数二进制中 1 的个数 
>    比如： 15 0000 1111 4 个 1 
>    程序原型： 
>    int count_one_bits(unsigned int value) 
>    { 
>    // 返回 1的位数 
>    } 
>
> 2. 获取一个数二进制序列中所有的偶数位和奇数位， 
>    分别输出二进制序列。 
>
> 3. 输出一个整数的每一位。 
>
> 4. 编程实现： 
>    两个int（32位）整数m和n的二进制表达中，有多少个位(bit)不同？ 
>    输入例子: 
>    1999 2299 
>    输出例子:7	

day11

> 1. 5位运动员参加了10米台跳水比赛，有人让他们预测比赛结果 
>    A选手说：B第二，我第三； 
>    B选手说：我第二，E第四； 
>    C选手说：我第一，D第二； 
>    D选手说：C最后，我第三； 
>    E选手说：我第四，A第一； 
>    比赛结束后，每位选手都说对了一半，请编程确定比赛的名次。 
>
> 2. 日本某地发生了一件谋杀案，警察通过排查确定杀人凶手必为4个 
>    嫌疑犯的一个。以下为4个嫌疑犯的供词。 
>    A说：不是我。 
>    B说：是C。 
>    C说：是D。 
>    D说：C在胡说 
>    已知3个人说了真话，1个人说的是假话。 
>    现在请根据这些信息，写一个程序来确定到底谁是凶手。 
>
> 3. 在屏幕上打印杨辉三角(5行)。 

day12

> 1. 编写函数： 
>    unsigned int reverse_bit(unsigned int value); 
>    这个函数的返回值value的二进制位模式从左到右翻转后的值。 
>
>    如： 
>    在32位机器上25这个值包含下列各位： 
>    00000000000000000000000000011001 
>    翻转后：（2550136832） 
>    10011000000000000000000000000000 
>    程序结果返回： 
>    2550136832 
>
> 2. 不使用（a+b）/2这种方式，求两个数的平均值。 
>
> 3. 编程实现： 
>    一组数据中只有一个数字出现了一次。其他所有数字都是成对出现的。 
>    请找出这个数字。（使用位运算） 
>
> 4. 有一个字符数组的内容为:"student a am i", 
>    请你将数组的内容改为"i am a student". 
>    要求： 
>    不能使用库函数。 
>    只能开辟有限个空间（空间个数和字符串的长度无关）。 

day13

> 1. 调整数组使奇数全部都位于偶数前面。 
>
>    题目： 
>
>    输入一个整数数组，实现一个函数， 
>    来调整该数组中数字的顺序使得数组中所有的奇数位于数组的前半部分， 
>    所有偶数位于数组的后半部分。 
>
> 2. 
>    杨氏矩阵 
>    有一个二维数组. 
>    数组的每行从左到右是递增的，每列从上到下是递增的. 
>    在这样的数组中查找一个数字是否存在。 
>    时间复杂度小于O(N)
>
>    数组： 
>    1 2 3 
>    2 3 4 
>    3 4 5 
>
>    1 3 4 
>    2 4 5 
>    4 5 6 
>
>    1 2 3 
>    4 5 6 
>    7 8 9 