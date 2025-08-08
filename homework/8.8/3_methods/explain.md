# first
- 核心是使用了`memcpy()`来自`<stdstring.h>`的函数，`memcpy()`函数可以按照所给`size`把源地址的内容复制到目标地址，用法如下：
```c
float f1 = 8.4;
float f2 = 7.2;
char array[8];
memcpy(array, &f1, sizeof(float));
memcpy(array + sizeof(float), &f2, sizeof
```
这里把f1, f2的内容赋值给array的低4位和高四位
```c
(float));
float c1;
float c2;
memcpy(&c1, array, sizeof(float));
memcpy(&c2, array + sizeof(float), sizeof(float));
```

# second
- 第二种方法主要使用指针以及指针的类型强制类型转化，`array`是数组首地址，强制转换为`float *`便可以用来存放`float`
```c
    char array[8];
    float *f1 = (float *) array;
    float *f2 = (float *) (array + sizeof(float));
    *f1 = 7.2;
    *f2 = 8.4;
```

# third
- 第三种方法和第二种方法相似，不同的是，第二种方法转换数组来接值，而第三种方法转换`float`为4个`char`来给数组赋值
```c
    char array[length];
    float f1 = 8.4;
    float f2 = 7.2;
    for (int i = 0; i < 4; i++)
    {
        array[i] = ((char *) &f1)[i];
        array[i + 4] = ((char *) &f2)[i];
    }
```

