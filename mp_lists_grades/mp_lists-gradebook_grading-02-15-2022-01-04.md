---

This report was generated for **shubhg3** using **42e31d50b7a2b92307069f338d9a145e68d2c1b3** (latest commit as of **February 14th 2022, 11:59 pm**)

---




## Score: 3/52 (5.77%)


### ✓ - [0/0] - Output from `make`

- **Points**: 0 / 0


```
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/HSLAPixel.cpp -o .objs/cs225/HSLAPixel.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/PNG.cpp -o .objs/cs225/PNG.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/lodepng/lodepng.cpp -o .objs/cs225/lodepng/lodepng.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c tests/tests_part1.cpp -o .objs/tests/tests_part1.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c tests/tests_part2.cpp -o .objs/tests/tests_part2.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c tests/tests_part1_extra.cpp -o .objs/tests/tests_part1_extra.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/catch/catchmain.cpp -o .objs/cs225/catch/catchmain.o
clang++ .objs/cs225/HSLAPixel.o .objs/cs225/PNG.o .objs/cs225/lodepng/lodepng.o .objs/tests/tests_part1.o .objs/tests/tests_part2.o .objs/tests/tests_part1_extra.o .objs/cs225/catch/catchmain.o  -std=c++1y -stdlib=libc++ -lc++abi -o test

```


### ✗ - [0/1] - List::insertFront size

- **Points**: 0 / 1

```
==72== Memcheck, a memory error detector
==72== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==72== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==72== Command: ./test -r xml "List::insertFront\ size"
==72== 
==72== Conditional jump or move depends on uninitialised value(s)
==72==    at 0x42832C: List<int>::insertFront(int const&) (List.hpp:78)
==72==    by 0x422007: ____C_A_T_C_H____T_E_S_T____0() (tests_part1.cpp:23)
==72==    by 0x461F72: Catch::TestInvokerAsFunction::invoke() const (catch.hpp:10892)
==72==    by 0x4526C6: Catch::TestCase::invoke() const (catch.hpp:10793)
==72==    by 0x4525FC: Catch::RunContext::invokeActiveTestCase() (catch.hpp:9658)
==72==    by 0x44EB56: Catch::RunContext::runCurrentTest(std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&, std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&) (catch.hpp:9622)
==72==    by 0x44D12E: Catch::RunContext::runTest(Catch::TestCase const&) (catch.hpp:9408)
==72==    by 0x4564C6: Catch::(anonymous namespace)::runTests(std::__1::shared_ptr<Catch::Config> const&) (catch.hpp:9948)
==72==    by 0x455162: Catch::Session::runInternal() (catch.hpp:10149)
==72==    by 0x454E2A: Catch::Session::run() (catch.hpp:10106)
==72==    by 0x454DA9: Catch::Session::run(int, char**) (catch.hpp:10074)
==72==    by 0x481E21: main (catch.hpp:13613)
==72== 
==72== Conditional jump or move depends on uninitialised value(s)
==72==    at 0x428366: List<int>::insertFront(int const&) (List.hpp:81)
==72==    by 0x422007: ____C_A_T_C_H____T_E_S_T____0() (tests_part1.cpp:23)
==72==    by 0x461F72: Catch::TestInvokerAsFunction::invoke() const (catch.hpp:10892)
==72==    by 0x4526C6: Catch::TestCase::invoke() const (catch.hpp:10793)
==72==    by 0x4525FC: Catch::RunContext::invokeActiveTestCase() (catch.hpp:9658)
==72==    by 0x44EB56: Catch::RunContext::runCurrentTest(std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&, std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&) (catch.hpp:9622)
==72==    by 0x44D12E: Catch::RunContext::runTest(Catch::TestCase const&) (catch.hpp:9408)
==72==    by 0x4564C6: Catch::(anonymous namespace)::runTests(std::__1::shared_ptr<Catch::Config> const&) (catch.hpp:9948)
==72==    by 0x455162: Catch::Session::runInternal() (catch.hpp:10149)
==72==    by 0x454E2A: Catch::Session::run() (catch.hpp:10106)
==72==    by 0x454DA9: Catch::Session::run(int, char**) (catch.hpp:10074)
==72==    by 0x481E21: main (catch.hpp:13613)
==72== 
==72== Conditional jump or move depends on uninitialised value(s)
==72==    at 0x452770: Catch::RunContext::handleExpr(Catch::AssertionInfo const&, Catch::ITransientExpression const&, Catch::AssertionReaction&) (catch.hpp:9683)
==72==    by 0x43064B: Catch::AssertionHandler::handleExpr(Catch::ITransientExpression const&) (catch.hpp:5467)
==72==    by 0x422164: ____C_A_T_C_H____T_E_S_T____0() (tests_part1.cpp:25)
==72==    by 0x461F72: Catch::TestInvokerAsFunction::invoke() const (catch.hpp:10892)
==72==    by 0x4526C6: Catch::TestCase::invoke() const (catch.hpp:10793)
==72==    by 0x4525FC: Catch::RunContext::invokeActiveTestCase() (catch.hpp:9658)
==72==    by 0x44EB56: Catch::RunContext::runCurrentTest(std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&, std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&) (catch.hpp:9622)
==72==    by 0x44D12E: Catch::RunContext::runTest(Catch::TestCase const&) (catch.hpp:9408)
==72==    by 0x4564C6: Catch::(anonymous namespace)::runTests(std::__1::shared_ptr<Catch::Config> const&) (catch.hpp:9948)
==72==    by 0x455162: Catch::Session::runInternal() (catch.hpp:10149)
==72==    by 0x454E2A: Catch::Session::run() (catch.hpp:10106)
==72==    by 0x454DA9: Catch::Session::run(int, char**) (catch.hpp:10074)
==72== 
==72== 
==72== HEAP SUMMARY:
==72==     in use at exit: 240 bytes in 10 blocks
==72==   total heap usage: 2,132 allocs, 2,122 frees, 252,400 bytes allocated
==72== 
==72== 240 bytes in 10 blocks are definitely lost in loss record 1 of 1
==72==    at 0x4C29EA3: malloc (vg_replace_malloc.c:309)
==72==    by 0x40475CB: operator new(unsigned long) (in /usr/local/lib/libc++abi.so.1.0)
==72==    by 0x4282E3: List<int>::insertFront(int const&) (List.hpp:74)
==72==    by 0x422007: ____C_A_T_C_H____T_E_S_T____0() (tests_part1.cpp:23)
==72==    by 0x461F72: Catch::TestInvokerAsFunction::invoke() const (catch.hpp:10892)
==72==    by 0x4526C6: Catch::TestCase::invoke() const (catch.hpp:10793)
==72==    by 0x4525FC: Catch::RunContext::invokeActiveTestCase() (catch.hpp:9658)
==72==    by 0x44EB56: Catch::RunContext::runCurrentTest(std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&, std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&) (catch.hpp:9622)
==72==    by 0x44D12E: Catch::RunContext::runTest(Catch::TestCase const&) (catch.hpp:9408)
==72==    by 0x4564C6: Catch::(anonymous namespace)::runTests(std::__1::shared_ptr<Catch::Config> const&) (catch.hpp:9948)
==72==    by 0x455162: Catch::Session::runInternal() (catch.hpp:10149)
==72==    by 0x454E2A: Catch::Session::run() (catch.hpp:10106)
==72== 
==72== LEAK SUMMARY:
==72==    definitely lost: 240 bytes in 10 blocks
==72==    indirectly lost: 0 bytes in 0 blocks
==72==      possibly lost: 0 bytes in 0 blocks
==72==    still reachable: 0 bytes in 0 blocks
==72==         suppressed: 0 bytes in 0 blocks
==72== 
==72== For counts of detected and suppressed errors, rerun with: -v
==72== Use --track-origins=yes to see where uninitialised values come from
==72== ERROR SUMMARY: 13 errors from 4 contexts (suppressed: 0 from 0)

```



### ✗ - [0/2] - List::insertBack size

- **Points**: 0 / 2


```
Original: 10 == list.size()
Expanded: 10 == 0
```


### ✗ - [0/4] - List::insert contents

- **Points**: 0 / 4


```
Original: "< 1 2 3 3 2 1 >" == s.str()
Expanded: "< 1 2 3 3 2 1 >" == "< >"
```


### ✗ - [0/5] - List::triplerotate basic

- **Points**: 0 / 5


```
Original: "< 1 2 >" == s.str()
Expanded: "< 1 2 >" == "< >"
```


### ✗ - [0/10] - List::triplerotate simple

- **Points**: 0 / 10


```
Original: "< 2 3 1 5 6 4 >" == s.str()
Expanded: "< 2 3 1 5 6 4 >" == "< >"
```


### ✗ - [0/5] - List::split simple

- **Points**: 0 / 5


```
Fatal Error: SIGSEGV - Segmentation violation signal
```


### ✗ - [0/5] - List::split images

- **Points**: 0 / 5


```
Original: out1 == expected_1
Expanded: PNG(w=400, h=240, hash=0)
==
PNG(w=400, h=240, hash=7f399ca10baeec7f)
```


### ✓ - [3/3] - List::_destroy empty list

- **Points**: 3 / 3

```
==80== Memcheck, a memory error detector
==80== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==80== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==80== Command: ./test -r xml "List::_destroy\ empty\ list"
==80== 
==80== 
==80== HEAP SUMMARY:
==80==     in use at exit: 0 bytes in 0 blocks
==80==   total heap usage: 2,140 allocs, 2,140 frees, 253,232 bytes allocated
==80== 
==80== All heap blocks were freed -- no leaks are possible
==80== 
==80== For counts of detected and suppressed errors, rerun with: -v
==80== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✗ - [0/1] - List::begin() returns an iterator to the front of the list

- **Points**: 0 / 1


```
Fatal Error: SIGSEGV - Segmentation violation signal
```


### ✗ - [0/1] - List::ListIterator::operator++ advances the iterator (pre-increment)

- **Points**: 0 / 1


```
Fatal Error: SIGSEGV - Segmentation violation signal
```


### ✗ - [0/1] - List::ListIterator::operator++ advances the iterator (post-increment)

- **Points**: 0 / 1


```
Fatal Error: SIGSEGV - Segmentation violation signal
```


### ✗ - [0/1] - List::ListIterator::operator++ (post-increment) returns an un-incremented iterator

- **Points**: 0 / 1


```
Fatal Error: SIGSEGV - Segmentation violation signal
```


### ✗ - [0/1] - List::ListIterator::operator-- moves the iterator backwards

- **Points**: 0 / 1


```
Fatal Error: SIGSEGV - Segmentation violation signal
```


### ✗ - [0/1] - List::ListIterator::operator-- (post-increment) returns an un-incremented iterator

- **Points**: 0 / 1


```
Fatal Error: SIGSEGV - Segmentation violation signal
```


### ✗ - [0/1] - List::ListIterator::end is reached

- **Points**: 0 / 1


```
Fatal Error: SIGSEGV - Segmentation violation signal
```


### ✗ - [0/1] - List::ListIterator::end is not ::begin in a non-empty list

- **Points**: 0 / 1


```
Original: (bool)(list.begin() != list.end())
Expanded: false
```


### ✗ - [0/4] - List::insert contents #2

- **Points**: 0 / 4


```
Original: "< 1 2 3 1 2 3 >" == s.str()
Expanded: "< 1 2 3 1 2 3 >" == "< >"
```


### ✗ - [0/5] - List::split edge cases

- **Points**: 0 / 5


```
Fatal Error: SIGSEGV - Segmentation violation signal
```


---