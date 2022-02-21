


## Score: 58/109 (53.21%)


### ✓ - [0/0] - Output from `make`

- **Points**: 0 / 0


```
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/HSLAPixel.cpp -o .objs/cs225/HSLAPixel.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/PNG.cpp -o .objs/cs225/PNG.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/lodepng/lodepng.cpp -o .objs/cs225/lodepng/lodepng.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c tests/tests_part1.cpp -o .objs/tests/tests_part1.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c tests/tests_part2.cpp -o .objs/tests/tests_part2.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c tests/test_part2_extra.cpp -o .objs/tests/test_part2_extra.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c tests/tests_part1_extra.cpp -o .objs/tests/tests_part1_extra.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/catch/catchmain.cpp -o .objs/cs225/catch/catchmain.o
clang++ .objs/cs225/HSLAPixel.o .objs/cs225/PNG.o .objs/cs225/lodepng/lodepng.o .objs/tests/tests_part1.o .objs/tests/tests_part2.o .objs/tests/test_part2_extra.o .objs/tests/tests_part1_extra.o .objs/cs225/catch/catchmain.o  -std=c++1y -stdlib=libc++ -lc++abi -o test

```


### ✓ - [1/1] - List::insertFront size

- **Points**: 1 / 1

```
==86== Memcheck, a memory error detector
==86== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==86== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==86== Command: ./test -r xml "List::insertFront\ size"
==86== 
==86== 
==86== HEAP SUMMARY:
==86==     in use at exit: 0 bytes in 0 blocks
==86==   total heap usage: 2,347 allocs, 2,347 frees, 268,272 bytes allocated
==86== 
==86== All heap blocks were freed -- no leaks are possible
==86== 
==86== For counts of detected and suppressed errors, rerun with: -v
==86== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [2/2] - List::insertBack size

- **Points**: 2 / 2

```
==88== Memcheck, a memory error detector
==88== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==88== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==88== Command: ./test -r xml "List::insertBack\ size"
==88== 
==88== 
==88== HEAP SUMMARY:
==88==     in use at exit: 0 bytes in 0 blocks
==88==   total heap usage: 2,347 allocs, 2,347 frees, 268,272 bytes allocated
==88== 
==88== All heap blocks were freed -- no leaks are possible
==88== 
==88== For counts of detected and suppressed errors, rerun with: -v
==88== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [4/4] - List::insert contents

- **Points**: 4 / 4

```
==90== Memcheck, a memory error detector
==90== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==90== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==90== Command: ./test -r xml "List::insert\ contents"
==90== 
==90== 
==90== HEAP SUMMARY:
==90==     in use at exit: 0 bytes in 0 blocks
==90==   total heap usage: 2,343 allocs, 2,343 frees, 268,176 bytes allocated
==90== 
==90== All heap blocks were freed -- no leaks are possible
==90== 
==90== For counts of detected and suppressed errors, rerun with: -v
==90== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [5/5] - List::triplerotate basic

- **Points**: 5 / 5

```
==92== Memcheck, a memory error detector
==92== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==92== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==92== Command: ./test -r xml "List::triplerotate\ basic"
==92== 
==92== 
==92== HEAP SUMMARY:
==92==     in use at exit: 0 bytes in 0 blocks
==92==   total heap usage: 2,351 allocs, 2,351 frees, 268,464 bytes allocated
==92== 
==92== All heap blocks were freed -- no leaks are possible
==92== 
==92== For counts of detected and suppressed errors, rerun with: -v
==92== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [10/10] - List::triplerotate simple

- **Points**: 10 / 10

```
==94== Memcheck, a memory error detector
==94== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==94== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==94== Command: ./test -r xml "List::triplerotate\ simple"
==94== 
==94== 
==94== HEAP SUMMARY:
==94==     in use at exit: 0 bytes in 0 blocks
==94==   total heap usage: 2,355 allocs, 2,355 frees, 268,560 bytes allocated
==94== 
==94== All heap blocks were freed -- no leaks are possible
==94== 
==94== For counts of detected and suppressed errors, rerun with: -v
==94== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [5/5] - List::split simple

- **Points**: 5 / 5

```
==96== Memcheck, a memory error detector
==96== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==96== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==96== Command: ./test -r xml "List::split\ simple"
==96== 
==96== 
==96== HEAP SUMMARY:
==96==     in use at exit: 0 bytes in 0 blocks
==96==   total heap usage: 2,205 allocs, 2,205 frees, 263,744 bytes allocated
==96== 
==96== All heap blocks were freed -- no leaks are possible
==96== 
==96== For counts of detected and suppressed errors, rerun with: -v
==96== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [5/5] - List::split images

- **Points**: 5 / 5





### ✓ - [3/3] - List::_destroy empty list

- **Points**: 3 / 3

```
==99== Memcheck, a memory error detector
==99== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==99== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==99== Command: ./test -r xml "List::_destroy\ empty\ list"
==99== 
==99== 
==99== HEAP SUMMARY:
==99==     in use at exit: 0 bytes in 0 blocks
==99==   total heap usage: 2,355 allocs, 2,355 frees, 269,104 bytes allocated
==99== 
==99== All heap blocks were freed -- no leaks are possible
==99== 
==99== For counts of detected and suppressed errors, rerun with: -v
==99== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [1/1] - List::begin() returns an iterator to the front of the list

- **Points**: 1 / 1

```
==101== Memcheck, a memory error detector
==101== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==101== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==101== Command: ./test -r xml "List::begin()\ returns\ an\ iterator\ to\ the\ front\ of\ the\ list"
==101== 
==101== 
==101== HEAP SUMMARY:
==101==     in use at exit: 0 bytes in 0 blocks
==101==   total heap usage: 2,359 allocs, 2,359 frees, 273,440 bytes allocated
==101== 
==101== All heap blocks were freed -- no leaks are possible
==101== 
==101== For counts of detected and suppressed errors, rerun with: -v
==101== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [1/1] - List::ListIterator::operator++ advances the iterator (pre-increment)

- **Points**: 1 / 1

```
==103== Memcheck, a memory error detector
==103== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==103== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==103== Command: ./test -r xml "List::ListIterator::operator++\ advances\ the\ iterator\ (pre-increment)"
==103== 
==103== 
==103== HEAP SUMMARY:
==103==     in use at exit: 0 bytes in 0 blocks
==103==   total heap usage: 2,359 allocs, 2,359 frees, 275,840 bytes allocated
==103== 
==103== All heap blocks were freed -- no leaks are possible
==103== 
==103== For counts of detected and suppressed errors, rerun with: -v
==103== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [1/1] - List::ListIterator::operator++ advances the iterator (post-increment)

- **Points**: 1 / 1

```
==105== Memcheck, a memory error detector
==105== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==105== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==105== Command: ./test -r xml "List::ListIterator::operator++\ advances\ the\ iterator\ (post-increment)"
==105== 
==105== 
==105== HEAP SUMMARY:
==105==     in use at exit: 0 bytes in 0 blocks
==105==   total heap usage: 2,359 allocs, 2,359 frees, 275,840 bytes allocated
==105== 
==105== All heap blocks were freed -- no leaks are possible
==105== 
==105== For counts of detected and suppressed errors, rerun with: -v
==105== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [1/1] - List::ListIterator::operator++ (post-increment) returns an un-incremented iterator

- **Points**: 1 / 1

```
==107== Memcheck, a memory error detector
==107== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==107== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==107== Command: ./test -r xml "List::ListIterator::operator++\ (post-increment)\ returns\ an\ un-incremented\ iterator"
==107== 
==107== 
==107== HEAP SUMMARY:
==107==     in use at exit: 0 bytes in 0 blocks
==107==   total heap usage: 2,359 allocs, 2,359 frees, 278,240 bytes allocated
==107== 
==107== All heap blocks were freed -- no leaks are possible
==107== 
==107== For counts of detected and suppressed errors, rerun with: -v
==107== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [1/1] - List::ListIterator::operator-- moves the iterator backwards

- **Points**: 1 / 1

```
==109== Memcheck, a memory error detector
==109== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==109== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==109== Command: ./test -r xml "List::ListIterator::operator--\ moves\ the\ iterator\ backwards"
==109== 
==109== 
==109== HEAP SUMMARY:
==109==     in use at exit: 0 bytes in 0 blocks
==109==   total heap usage: 2,359 allocs, 2,359 frees, 273,440 bytes allocated
==109== 
==109== All heap blocks were freed -- no leaks are possible
==109== 
==109== For counts of detected and suppressed errors, rerun with: -v
==109== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [1/1] - List::ListIterator::operator-- (post-increment) returns an un-incremented iterator

- **Points**: 1 / 1

```
==111== Memcheck, a memory error detector
==111== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==111== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==111== Command: ./test -r xml "List::ListIterator::operator--\ (post-increment)\ returns\ an\ un-incremented\ iterator"
==111== 
==111== 
==111== HEAP SUMMARY:
==111==     in use at exit: 0 bytes in 0 blocks
==111==   total heap usage: 2,359 allocs, 2,359 frees, 278,240 bytes allocated
==111== 
==111== All heap blocks were freed -- no leaks are possible
==111== 
==111== For counts of detected and suppressed errors, rerun with: -v
==111== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [1/1] - List::ListIterator::end is reached

- **Points**: 1 / 1

```
==113== Memcheck, a memory error detector
==113== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==113== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==113== Command: ./test -r xml "List::ListIterator::end\ is\ reached"
==113== 
==113== 
==113== HEAP SUMMARY:
==113==     in use at exit: 0 bytes in 0 blocks
==113==   total heap usage: 2,352 allocs, 2,352 frees, 270,872 bytes allocated
==113== 
==113== All heap blocks were freed -- no leaks are possible
==113== 
==113== For counts of detected and suppressed errors, rerun with: -v
==113== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [1/1] - List::ListIterator::end is not ::begin in a non-empty list

- **Points**: 1 / 1

```
==115== Memcheck, a memory error detector
==115== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==115== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==115== Command: ./test -r xml "List::ListIterator::end\ is\ not\ ::begin\ in\ a\ non-empty\ list"
==115== 
==115== 
==115== HEAP SUMMARY:
==115==     in use at exit: 0 bytes in 0 blocks
==115==   total heap usage: 2,352 allocs, 2,352 frees, 273,272 bytes allocated
==115== 
==115== All heap blocks were freed -- no leaks are possible
==115== 
==115== For counts of detected and suppressed errors, rerun with: -v
==115== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✗ - [0/5] - List::reverse

- **Points**: 0 / 5

```
[Process timed out]
```
```
Unable to Grade (ENOBUFS): Your code had over 1 MB of output, exceeding the allowed buffer space.
```


### ✗ - [0/5] - List::reverseNth #1

- **Points**: 0 / 5


```
Original: out == expected
Expanded: PNG(w=900, h=600, hash=3fa66744920ffb90)
==
PNG(w=900, h=600, hash=3fa66744920ffb90)
```


### ✗ - [0/5] - List::reverseNth #2

- **Points**: 0 / 5


```
Original: out == expected
Expanded: PNG(w=900, h=600, hash=3fa66744920ffb90)
==
PNG(w=900, h=600, hash=3fa66744920ffb90)
```


### ✗ - [0/10] - List::merge

- **Points**: 0 / 10


```
Original: out == expected
Expanded: PNG(w=600, h=400, hash=0)
==
PNG(w=600, h=400, hash=0)
```


### ✗ - [0/2] - List::sort simple #1

- **Points**: 0 / 2


```
Fatal Error: SIGSEGV - Segmentation violation signal
```


### ✗ - [0/2] - List::sort simple #2

- **Points**: 0 / 2


```
Fatal Error: SIGSEGV - Segmentation violation signal
```


### ✗ - [0/5] - List::sort #1

- **Points**: 0 / 5


```
Fatal Error: SIGSEGV - Segmentation violation signal
```


### ✗ - [0/5] - List::sort #2

- **Points**: 0 / 5


```
Fatal Error: SIGSEGV - Segmentation violation signal
```


### ✓ - [4/4] - List::reverse simple

- **Points**: 4 / 4

```
==125== Memcheck, a memory error detector
==125== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==125== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==125== Command: ./test -r xml "List::reverse\ simple"
==125== 
==125== 
==125== HEAP SUMMARY:
==125==     in use at exit: 0 bytes in 0 blocks
==125==   total heap usage: 2,209 allocs, 2,209 frees, 264,044 bytes allocated
==125== 
==125== All heap blocks were freed -- no leaks are possible
==125== 
==125== For counts of detected and suppressed errors, rerun with: -v
==125== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [2/2] - List::reverse edge cases

- **Points**: 2 / 2

```
==127== Memcheck, a memory error detector
==127== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==127== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==127== Command: ./test -r xml "List::reverse\ edge\ cases"
==127== 
==127== 
==127== HEAP SUMMARY:
==127==     in use at exit: 0 bytes in 0 blocks
==127==   total heap usage: 2,354 allocs, 2,354 frees, 268,744 bytes allocated
==127== 
==127== All heap blocks were freed -- no leaks are possible
==127== 
==127== For counts of detected and suppressed errors, rerun with: -v
==127== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✗ - [0/5] - List::reverseNth #3

- **Points**: 0 / 5


```
Original: "< 4 3 2 1 8 7 6 5 10 9 >" == s.str()
Expanded: "< 4 3 2 1 8 7 6 5 10 9 >"
==
"< 1 4 3 2 7 6 5 8 9 10 >"
```


### ✗ - [0/5] - List::merge #2

- **Points**: 0 / 5


```
Original: "< 1 2 10 15 20 30 35 40 45 50 55 65 75 100 200 300 400 500 >" == s1.str()
Expanded: "< 1 2 10 15 20 30 35 40 45 50 55 65 75 100 200 300 400 500 >"
==
"< >"
```


### ✗ - [0/2] - List::sort simple #3

- **Points**: 0 / 2


```
Fatal Error: SIGSEGV - Segmentation violation signal
```


### ✓ - [4/4] - List::insert contents #2

- **Points**: 4 / 4

```
==132== Memcheck, a memory error detector
==132== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==132== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==132== Command: ./test -r xml "List::insert\ contents\ #2"
==132== 
==132== 
==132== HEAP SUMMARY:
==132==     in use at exit: 0 bytes in 0 blocks
==132==   total heap usage: 2,358 allocs, 2,358 frees, 268,672 bytes allocated
==132== 
==132== All heap blocks were freed -- no leaks are possible
==132== 
==132== For counts of detected and suppressed errors, rerun with: -v
==132== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [5/5] - List::split edge cases

- **Points**: 5 / 5

```
==134== Memcheck, a memory error detector
==134== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==134== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==134== Command: ./test -r xml "List::split\ edge\ cases"
==134== 
==134== 
==134== HEAP SUMMARY:
==134==     in use at exit: 0 bytes in 0 blocks
==134==   total heap usage: 2,348 allocs, 2,348 frees, 268,336 bytes allocated
==134== 
==134== All heap blocks were freed -- no leaks are possible
==134== 
==134== For counts of detected and suppressed errors, rerun with: -v
==134== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



---

This report was generated for **shubhg3** using **b561d8488d021a14abe9feaebf0b525250f3bcfd** (latest commit as of **February 20th 2022, 11:53 pm**)
