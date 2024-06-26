# C++ 基本数据类型

C++ 作为一种静态类型语言，提供了一系列的基本数据类型，用于处理数值、字符和布尔值。了解这些基本数据类型是学习 C++ 的基础。本文将详细介绍 C++ 中的基本数据类型，包括整型、浮点型、字符型、字符串型和布尔型。

## 整型

整型用于存储整数值，可以是正数、负数或零。C++ 提供了多种整型，以支持不同大小的数值和内存优化。

- `int`：4 字节，最常用的整型，大小至少为 16 位。
- `short`：2 字节，小整型，大小至少为 16 位。
- `long`：Windows 为 4 字节，Linux 为 4 字节(32 位)，8 字节(64 位)，大整型，大小至少为 32 位。
- `long long`：8 字节，更大的整型，大小至少为 64 位。
- `unsigned`：用于表明无符号类型，用于存储非负整数。

## 浮点型

浮点型用于存储小数点数值，包括单精度和双精度浮点数。

- `float`：占用 4 字节，单精度浮点型，提供约 6-7 位十进制数的精度。
- `double`：占用 8 字节，双精度浮点型，提供约 15-16 位十进制数的精度。

**示例**

```cpp
int main() {
	float f1 = 3.1415926535f;
	cout << "float 类型占用的内存大小：" << sizeof(float) << endl;
	cout << "float 类型占用的内存大小：" << sizeof(f1) << endl;

	double d1 = 3.1415926535;
	cout << "double 类型占用的内存大小：" << sizeof(double) << endl;
	cout << "double 类型占用的内存大小：" << sizeof(d1) << endl;

	//科学计数法表示整数
	float f2 = 3e2; // 3 * 10 ^ 2
	cout << "f2 = " << f2 << endl;

	//科学计数法表示小数
	float f3 = 3e-2;  // 3 * 0.1 ^ 2
	cout << "f3 = " << f3 << endl;
	return 0;
}
```

## 字符型

在 C 和 C++ 语言中，字符型变量只占用 1 个字节。字符型变量是将对应的 ASCII 编码存放至内存，而不是字符本身。

**作用**：字符型变量可表示单个字符，如字母或数字。

**语法**：

```cpp
char ch = 'a';
```

### ASCII 码表

ASCII（美国标准信息交换码）是一种字符编码标准，用于文本文件在计算机中的表示。以下是 ASCII 码表的一个简化版本，包括控制字符、数字、大写字母和小写字母。

| 十进制 | 十六进制 | 字符 | 说明       |
| ------ | -------- | ---- | ---------- |
| 0      | 0x00     | NUL  | 空字符     |
| 1      | 0x01     | SOH  | 标题开始   |
| 2      | 0x02     | STX  | 正文开始   |
| ...    | ...      | ...  | ...        |
| 32     | 0x20     |      | 空格       |
| 33     | 0x21     | !    | 感叹号     |
| 34     | 0x22     | "    | 双引号     |
| ...    | ...      | ...  | ...        |
| 48     | 0x30     | 0    | 数字 0     |
| 49     | 0x31     | 1    | 数字 1     |
| ...    | ...      | ...  | ...        |
| 57     | 0x39     | 9    | 数字 9     |
| ...    | ...      | ...  | ...        |
| 65     | 0x41     | A    | 大写字母 A |
| 66     | 0x42     | B    | 大写字母 B |
| ...    | ...      | ...  | ...        |
| 90     | 0x5A     | Z    | 大写字母 Z |
| ...    | ...      | ...  | ...        |
| 97     | 0x61     | a    | 小写字母 a |
| 98     | 0x62     | b    | 小写字母 b |
| ...    | ...      | ...  | ...        |
| 122    | 0x7A     | z    | 小写字母 z |
| ...    | ...      | ...  | ...        |
| 127    | 0x7F     | DEL  | 删除       |

**注意 1**：这只是 ASCII 码表的一部分。完整的 ASCII 表包括从 0 到 127 的所有值。由于篇幅限制，这里只展示了部分常用字符。
**注意 2**：大写字母与对应小写字母之间的差值为 32。这个差值可以用于大小写转换：

- 将大写字母转换为小写字母：给大写字母的 ASCII 码值加上 32。
- 将小写字母转换为大写字母：从小写字母的 ASCII 码值减去 32。

```cpp
// 数据类型强制转换法：
    // 大写字母转换为小写字母
char A = 'A';
char a = char(A + 32);
cout << a;

// 字符相减法：
    // 大写字母转换为小写字母
char A = 'A';
char a = a + 'a' - 'A';
cout << a;

    // 小写字母转换为大写字母
char a = 'a';
char A = A + 'A' - 'a';
cout << A;

// 库函数法：
#include <cctype>
#include <iostream>
char lower = 'a';
char upper = 'A';

// 在C++中，tolower函数接受一个int类型的参数(ASCII)，并返回一个转换为小写的int值，
// 如果参数是大写字母的话。这个返回值是一个int类型的ASCII。
// static_cast<char>用于将int类型的返回值转换为char类型。

// 转换为大写
std::cout << toupper(lower) << std::endl;
std::cout << "大写: " << static_cast<char>(toupper(lower)) << std::endl;

// 转换为小写
std::cout << "小写: " << static_cast<char>(tolower(upper)) << std::endl;


// 如果不使用类型转换，
// 也可以直接声明一个char类型的变量来接收ASCII值

// toupper();
char a = 'a';
a = toupper(a);
std::cout << a << std::endl;
// tolower();
char A = 'A';
A = tolower(A);
std::cout << A;
```

## 转义字符

**作用**：表示一些特殊的无法直接显示的 ASCII 字符。

常用的转义字符有：`\n` `\\` `\t`

**注意 1**：C 语言中使用转义字符`\n`换行，C++中使用`endl`换行。
**注意 2**：表示水平制表符的转义符`\t`占据 8 个字符宽度。

## 字符串型

C++ 标准库中的 `std::string` 类用于存储和操作字符串。它提供了丰富的字符串处理功能。

```cpp
#include <string>

std::string greeting = "Hello, World!";
```

**注意 1**：`std::string` 类是 C++ 标准库中的一部分，因此需要包含 `<string>` 头文件。

## 布尔型

布尔型用于存储真 (`true`) 或假 (`false`) 值。

- `bool`：布尔型，可以是 `true` 或 `false`。

**注意 1**：C++的`bool`类型中，`true` 或 任意非 0 值 均代表“真”；`false` 或 0 值 代表“假”。

## `sizeof` 关键字

**作用**：`sizeof` 关键字可统计数据类型所占用的内存大小。

**语法**：`sizeof(数据类型)` 或 `sizeof(变量名)`。

**示例**：

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "short 类型占用的内存大小：" << sizeof(short) << endl;

    int num = 10;
    cout << "int 类型占用的内存大小：" << sizeof(int) << endl;
    cout << "int 类型占用的内存大小：" << sizeof(num) << endl;

    cout << "long 类型占用的内存大小：" << sizeof(long) << endl;
    cout << "long long 类型占用的内存大小：" << sizeof(long long) << endl;

    system("pause");
    return 0;
}
```

## `new` 和 `delete` 关键字

在 C++ 中，`new` 和 `delete` 关键字用于动态内存分配和释放。与传统的 C 语言中的 `malloc` 和 `free` 函数相比，`new` 和 `delete` 提供了更为安全和易用的方式来处理动态内存。

### `new` 关键字

**作用**：`new` 关键字用于在堆上分配内存。它会自动计算需要分配的内存大小，并返回指向该内存的指针。

**语法**：

```cpp
指针变量 = new 数据类型;
```

如果是分配数组类型的内存，则语法如下：

```cpp
指针变量 = new 数据类型[数组大小];
```

### `delete` 关键字

**作用**：`delete` 关键字用于释放由 `new` 关键字分配的内存。释放后，该内存区域可以被再次使用。

**语法**：

```cpp
delete 指针变量;
```

如果是释放数组类型的内存，则语法如下：

```cpp
delete[] 指针变量;
```

### 示例

```cpp
#include <iostream>
using namespace std;

int main() {
    // 使用 new 分配单个整数的内存
    int* p = new int;
    *p = 5;
    cout << "分配的整数值为：" << *p << endl;
    delete p; // 释放内存

    // 使用 new 分配整数数组的内存
    int* arr = new int[3];
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    cout << "数组第一个元素：" << arr[0] << endl;
    delete[] arr; // 释放数组内存

    return 0;
}
```

**注意 1**：使用 `new` 分配的每块内存都应该使用对应的 `delete` 或 `delete[]` 来释放，以避免内存泄漏。

## 总结

C++ 提供了丰富的基本数据类型，以满足不同的编程需求。了解和熟悉这些数据类型是进行 C++ 编程的基础。通过使用这些基本数据类型，可以构建复杂的数据结构和算法，以解决实际问题。
