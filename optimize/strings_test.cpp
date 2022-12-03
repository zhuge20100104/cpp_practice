#include "test_driver.h"
#include "stopwatch11.h"
#include <iostream>
#include <string>

// original, naive remove_ctrl
std::string remove_ctrl(std::string s) {
    std::string result;
    for(std::size_t i=0; i<s.length(); ++i) {
        if(s[i] >= 0x20) {
            result = result + s[i];
        }
    }
    return result;
}

// remove_ctrl() with operator replaced by mutating assignment
std::string remove_ctrl_mutating(std::string s) {
    std::string result;
    for(std::size_t i=0; i<s.length(); ++i) {
        if(s[i] >= 0x20) {
            result += s[i];
        }
    }
    return result;
}

std::string remove_ctrl_mutating_it(std::string s) {
    std::string result;
    for(auto it=s.begin(); it!=s.end(); ++it) {
        if(*it >= 0x20) {
            result += *it;
        }
    }
    return result;
}

std::string remove_ctrl_mutating_it_end(std::string s) {
    std::string result;
    for(auto it=s.begin(), end=s.end(); it!=end; ++it) {
        if(*it >= 0x20) {
            result += *it;
        }
    }
    return result;
}

std::string remove_ctrl_reserve(std::string s) {
    std::string result;
    result.reserve(s.length());

    for(std::size_t i=0; i<s.length(); ++i) {
        if(s[i] >= 0x20) {
            result += s[i];
        }
    }
    return result;
}

// TODO: add remove_ctrl_reserve_it  test


int test_strings(int test_no, unsigned long multiplier) {
    using counter_t = unsigned;
    counter_t iterations = 1000* multiplier;
    std::string s("\07Now is the time\07 for all good men\r\n to come to the aid of their country. \07");
    std::string test("Now is the time for all good men to come to the aid of their country. ");
    // Result 是 actual 字符串
    std::string result;
    // s是源字符串
    s = s + s + s;
    // Test是expectation
    test = test + test + test;

    bool rc = true;

   
    
    switch(test_no) {
        default: return -1;
        case 0: return 4;
        case 1:{
            std::cout << s.length() << " character argument to remove_ctrl()" << std::endl;
            std::cout << iterations << " iterations" << std::endl;
            result = remove_ctrl(s);
            rc &= (result.compare(test) == 0);
            result = remove_ctrl_mutating(s);
            rc &= (result.compare(test) == 0);
            result = remove_ctrl_mutating_it(s);
            rc &= (result.compare(test) == 0);
            result = remove_ctrl_mutating_it_end(s);
            rc &= (result.compare(test) == 0);
            result = remove_ctrl_reserve(s);
            rc &= (result.compare(test) == 0);
            break;
        }
        case 2: {
            StopWatch sw("remove_ctrl()");
            for(counter_t i=0; i<iterations; ++i) {
                result = remove_ctrl(s);
            }
        }
        break;

        case 3: {
            StopWatch sw("remove_ctrl_mutating()");
            for(counter_t i=0; i<iterations; ++i) {
                result = remove_ctrl_mutating(s);
            }
        }

        {
            // 迭代器跟索引比反而变慢了
            StopWatch sw("remove_ctrl_mutating_it()");
            for(counter_t i=0; i<iterations; ++i) {
                result = remove_ctrl_mutating_it(s);
            }
        }

        {
            // 缓存一下终止迭代器, 这个迭代器优化之后，也只能少 1-2ms，少不了多少
            StopWatch sw("remove_ctrl_mutating_it_end()");
            for(counter_t i=0; i<iterations; ++i) {
                result = remove_ctrl_mutating_it_end(s);
            }
        }
        break;
        case 4: {
            // 先预先分配内存再做
            StopWatch sw("remove_ctrl_reserve()");
            for(counter_t i=0; i<iterations; ++i) {
                result = remove_ctrl_reserve(s);
            }
        }

        break;
    }

    return rc? 1 : 0;
}

int main(int argc, char* argv[]) {
    test_driver(test_strings, argc, argv);
    return EXIT_SUCCESS;
}