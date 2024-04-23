# C++ 文件和流

`iostream` 提供了 `cin` 和 `cout` 方法分别用于从标准输入读取流和向标准输出写入流。
`fstream` 提供了 `ifstream` 和 `ofstream` 方法分别用于从文件读取流和向文件写入流。

| 数据类型 | 描述                                                                                                                         |
| -------- | ---------------------------------------------------------------------------------------------------------------------------- |
| ofstream | 该数据类型表示输出文件流，用于创建文件并向文件写入信息。                                                                     |
| ifstream | 该数据类型表示输入文件流，用于从文件读取信息。                                                                               |
| fstream  | 该数据类型通常表示文件流，且同时具有 ofstream 和 ifstream 两种功能，这意味着它可以创建文件，向文件写入信息，从文件读取信息。 |

要在 C++ 中进行文件处理，必须在 C++ 源代码文件中包含头文件 `iostream` 和 `fstream` 。

## 打开文件

在从文件读取信息或者向文件写入信息之前，必须先打开文件。 `ofstream` 和 `fstream` 对象都可以用来打开文件进行写操作，如果只需要打开文件进行读操作，则使用 `ifstream` 对象。

下面是用于打开文件的基本语法：

```cpp
void open(const char *filename, ios::openmode mode);
```

在这里，`open()` 成员函数的第一个参数指定要打开的文件的名称和位置，第二个参数定义文件被打开的模式。

| 模式标志   | 描述                                                                   |
| ---------- | ---------------------------------------------------------------------- |
| ios::app   | 追加模式。所有写入都追加到文件末尾。                                   |
| ios::ate   | 文件打开后定位到文件末尾。                                             |
| ios::in    | 打开文件用于读取。                                                     |
| ios::out   | 打开文件用于写入。                                                     |
| ios::trunc | 如果该文件已经存在，其内容将在打开文件之前被截断，即把文件长度设为 0。 |

您可以组合这些值，例如 `ios::in | ios::out` 将文件同时用于读写。

```cpp
ifstream  afile;
afile.open("file.dat", ios::out | ios::in );
```

## 关闭文件

当 C++ 程序终止时，它会自动关闭刷新所有流并关闭所有打开的文件。但程序员应该养成一个好习惯，在程序终止前关闭所有打开的文件。

下面是关闭文件的基本语法：

```cpp
void close();
```

## 写入文件

下面是向文件写入内容的最简单的方法：

```cpp
#include <fstream>
using namespace std;

int main()
{
    ofstream outfile;
    outfile.open("afile.dat");
    outfile << "This is a line.\n";
    outfile.close();
    return 0;
}
```

下面的实例来自[C++ 文件 I/O](https://www.runoob.com/cplusplus/cpp-files-streams.html)：

```cpp
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    char data[100];

    // 以写模式打开文件
    ofstream outfile;
    outfile.open("afile.dat");

    cout << "Writing to the file" << endl;
    cout << "Enter your name: ";
    cin.getline(data, 100);

    // 向文件写入用户输入的数据
    outfile << data << endl;

    cout << "Enter your age: ";
    cin >> data;
    cin.ignore();

    // 再次向文件写入用户输入的数据
    outfile << data << endl;

    // 关闭打开的文件
    outfile.close();

    // 以读模式打开文件
    ifstream infile;
    infile.open("afile.dat");

    cout << "Reading from the file" << endl;
    infile >> data;

    // 在屏幕上写入数据
    cout << data << endl;

    // 再次从文件读取数据，并显示它
    infile >> data;
    cout << data << endl;

    // 关闭打开的文件
    infile.close();

    return 0;
}
```
