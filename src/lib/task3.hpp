// 3. Написать функцию,
//  которая принимает любое число аргументов разных типов и выводит их в stdout.
//  Предполагается использование вариативного шаблона.

#pragma once
// task3
#include <iostream>
#include <bitset>

template<typename... T>
void print(const T&... args)
{
    std::bitset<1> unused[] = {(std::cout << args << " ", 0)... };
    static_cast<void>(unused);
    std::cout << std::endl;
}
