# C++ 基本控制结构

## 1. 顺序结构

顺序结构是程序中最简单的结构，它按照代码的顺序执行。例如，下面的代码片段展示了一个简单的顺序结构：

```cpp
#include <iostream>
using namespace std;

int main()
{
    cout << "Hello, World!" << endl;
    cout << "Welcome to C++ Programming!" << endl;
    return 0;
}
```

在上面的代码中，`cout` 语句按照顺序执行，依次输出 "Hello, World!" 和 "Welcome to C++ Programming!"。

## 2. 分支结构

C++ 编程语言提供了以下类型的判断语句。

| 语句                              | 描述                                                                           |
| --------------------------------- | ------------------------------------------------------------------------------ |
| [if 语句](#21-if-语句)            | 一个 `if` 语句 由一个布尔表达式后跟一个或多个语句组成。                        |
| [if...else 语句](#22-ifelse-语句) | 一个 if 语句 后可跟一个可选的 `else` 语句，`else` 语句在布尔表达式为假时执行。 |
| 嵌套 if 语句                      | 可以在一个 if 或 else if 语句内使用另一个 `if` 或 `else if` 语句。             |
| [switch 语句](#24-switch-语句)    | 一个 `switch` 语句允许测试一个变量等于多个值时的情况。                         |
| 嵌套 switch 语句                  | 可以在一个 `switch` 语句内使用另一个 `switch` 语句。                           |

### 2.1 `if` 语句

`if` 语句用于根据条件执行代码块。如果条件为真，则执行 `if` 语句块中的代码；否则，跳过 `if` 语句块。下面是一个简单的 `if` 语句示例：

```cpp
#include <iostream>
using namespace std;

int main()
{
    int x = 10;
    if (x > 5)
    {
        cout << "x 大于 5" << endl;
    }
    return 0;
}
```

### 2.2 `if...else` 语句

`if...else` 语句用于根据条件执行代码块。如果条件为真，则执行 `if` 语句块中的代码；否则，执行 `else` 语句块中的代码。下面是一个简单的 `if...else` 语句示例：

```cpp
#include <iostream>
using namespace std;

int main()
{
    int x = 10;
    if (x > 5)
    {
        cout << "x 大于 5" << endl;
    }
    else
    {
        cout << "x 小于等于 5" << endl;
    }
    return 0;
}
```

### 2.4 `switch` 语句

`switch` 语句允许测试一个变量等于多个值时的情况。下面是一个简单的 `switch` 语句示例：

```cpp
#include <iostream>
using namespace std;

int main()
{
    int x = 2;
    switch (x)
    {
    case 1:
        cout << "x 等于 1" << endl;
        break;
    case 2:
        cout << "x 等于 2" << endl;
        break;
    case 3:
        cout << "x 等于 3" << endl;
        break;
    default:
        cout << "x 不等于 1、2 或 3" << endl;
    }
    return 0;
}
```

## 3. 循环结构

C++ 编程语言提供了以下类型的循环语句。

| 语句                                | 描述                                                      |
| ----------------------------------- | --------------------------------------------------------- |
| [while 循环](#31-while-循环)        | 当条件为真时，重复执行语句或语句组。                      |
| [for 循环](#32-for-循环)            | 多次执行一个语句序列，简化管理循环变量的代码。            |
| [do...while 循环](#33-dowhile-循环) | 除了它是在循环的末尾检查条件外，其他与 `while` 语句类似。 |
| 嵌套循环                            | 可以在一个循环内使用另一个循环。                          |

### 3.1 `while` 循环

`while` 循环用于重复执行一组语句，只要条件为真。下面是一个简单的 `while` 循环示例：

```cpp
#include <iostream>
using namespace std;

int main()
{
    int x = 0;
    while (x < 5)
    {
        cout << x << endl;
        x++;
    }
    return 0;
}
```

### 3.2 `for` 循环

`for` 循环用于多次执行一个语句序列，简化管理循环变量的代码。下面是一个简单的 `for` 循环示例：

```cpp
#include <iostream>
using namespace std;

int main()
{
    for (int x = 0; x < 5; x++)
    {
        cout << x << endl;
    }
    return 0;
}
```

### 3.3 `do...while` 循环

`do...while` 循环与 `while` 循环类似，只是 `do...while` 循环会在循环的末尾检查条件。下面是一个简单的 `do...while` 循环示例：

```cpp
#include <iostream>
using namespace std;

int main()
{
    int x = 0;
    do
    {
        cout << x << endl;
        x++;
    } while (x < 5);
    return 0;
}
```

## 4. 跳转结构

C++ 编程语言提供了以下类型的跳转语句。

| 语句                               | 描述                                                                               |
| ---------------------------------- | ---------------------------------------------------------------------------------- |
| [break 语句](#41-break-语句)       | 终止 `switch` 语句或循环，并将执行流程转到紧接着 `switch` 语句或循环的下一条语句。 |
| [continue 语句](#42-continue-语句) | 跳过当前循环中的剩余语句，并继续下一次循环。                                       |
| [goto 语句](#43-goto-语句)         | 将控制转移到被标记的语句。                                                         |

### 4.1 `break` 语句

`break` 语句用于终止 `switch` 语句或循环，并将执行流程转到紧接着 `switch` 语句或循环的下一条语句。下面是一个简单的 `break` 语句示例：

```cpp
#include <iostream>
using namespace std;

int main()
{
    for (int x = 0; x < 5; x++)
    {
        if (x == 3)
        {
            break;
        }
        cout << x << endl;
    }
    return 0;
}
```

### 4.2 `continue` 语句

`continue` 语句用于跳过当前循环中的剩余语句，并继续下一次循环。下面是一个简单的 `continue` 语句示例：

```cpp
#include <iostream>
using namespace std;

int main()
{
    for (int x = 0; x < 5; x++)
    {
        if (x == 3)
        {
            continue;
        }
        cout << x << endl;
    }
    return 0;
}
```

### 4.3 `goto` 语句

`goto` 语句用于将控制转移到被标记的语句。下面是一个简单的 `goto` 语句示例：

```cpp
#include <iostream>
using namespace std;

int main()
{
    int x = 0;
    loop:
    cout << x << endl;
    x++;
    if (x < 5)
    {
        goto loop;
    }
    return 0;
}
```

## 5. 小结

本节介绍了 C++ 编程语言中的基本控制结构，包括顺序结构、分支结构、循环结构和跳转结构。这些控制结构是构建复杂程序的基础。
