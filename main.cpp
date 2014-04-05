//
//  main.cpp
//  std2
//
//  Created by Jonas Vanthornhout on 05/04/14.
//  Copyright (c) 2014 Jonas Vanthornhout. All rights reserved.
//

#include "include/chrono"
#include "include/foreach"
#include "include/exception"

#include <iostream>
#include <thread>
#include <map>

void chronoExample() {
    auto start = std2::chrono::now();
    std::chrono::milliseconds duration{10};
    std::this_thread::sleep_for(duration);
    auto stop = std2::chrono::now();
    
    std::cout << std2::chrono::diff(start, stop) << std::endl;
    std::cout << std2::chrono::diff<std::chrono::nanoseconds>(start, stop) << std::endl;
}

void foreachExample(){
    std::map<int, double> m = {{1, 0.5}, {2, 1}, {3, {1.5}}};
    foreach(m, key, &value, {
        value += 0.3;
    });
    
    foreach(m, key, const &value, {
        std::cout << key << " -> " << value << std::endl;
    });
}

void exceptionExample() {
    try {
        throwException("This is an example exception");
    } catch(const std2::exception& e) {
        std::cout << "Exception from " << e.origin << " with message: '" << e.msg << "'" << std::endl;
    }
}

int main(int argc, const char * argv[]) {
    chronoExample();
    foreachExample();
    exceptionExample();
}

