#include <cctype> // 包含toupper和tolower函数的头文件
#include <iostream>

int main()
{
    char lower = 'a';
    char upper = 'A';

    // 转换为大写
    std::cout << "大写: " << static_cast<char>(toupper(lower)) << std::endl;

    // 转换为小写
    std::cout << "小写: " << static_cast<char>(tolower(upper)) << std::endl;

    return 0;
}
