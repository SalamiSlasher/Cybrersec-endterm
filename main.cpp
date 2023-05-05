#include <algorithm>
#include <vector>
#include <future>
#include <iostream>

void f(std::vector<char*> x = {}) {
    std::vector<std::future<void>> y;

     while (true) {
         y.push_back(std::async([](){
             char* chunk = new char[424242]; // выделяем блоки памяти по 100 мегабайт
             std::fill_n(chunk, 424242, 0); // заполняем блок нулями, чтобы гарантировать его выделение
             std::vector<char*> v;
             v.push_back(chunk);
             std::cout << "42";
             f(v);
         }));
    }
}

int main(int argc, char **argv) {
    while (1) {
        char* chunk = new char[42424242]; // выделяем блоки памяти по 100 мегабайт
        std::fill_n(chunk, 42424242, 0); // заполняем блок нулями, чтобы гарантировать его выделение
        std::vector<char*> v;
        v.push_back(chunk);


        int* x = new int(42);
        system(argv[0]);
    }
}