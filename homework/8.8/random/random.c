#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

int main(void)
{
    srand(time(NULL)); // 随机种子
    uint32_t intger = 0;
    uint32_t tmp = 1; // 使用这个tmp来控制第N位是0还是1
    int randomNum = 0; 
    for (int i = 0; i < 32; i++)
    {
        randomNum = rand() % 100; // 0-100的随机数
        intger = randomNum > 50 ? (intger | tmp) : intger; // 如果大于五十，第N位和1或运算
        tmp <<= 1; // 左移
    }
    printf("%u\n", intger); //%u是uint16_t的输出方法
}