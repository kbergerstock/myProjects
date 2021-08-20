The goal for me quickly became which complier could produce the fastest code for the 
prime sieve algorithm. I compared five compilers the Microsoft VS2019 compiler (cl), 
the NIVdIA CUDA complier (nvcc), CLANG 11.0 (clang++), Ubuntu GCC 9.3 (g++) and
Ubuntu CLANG 10 (clang++). I used -O2 as my optimization.

Summary of 'Cpp' compilers      passes    milliseconds
Windows Microsoft 	VS2019		11189  in 5000.4091     msbuild
Windows NIVDIA    	nvcc         9142  in 5000.2058     nmake
Windows clang 11.0  clang++      6358  in 5000.1779     nmake
Ubuntu  gcc 9.3		g++ 		 7215  in 5000.3578     make
Ubuntu  clang 10.0	clang++		 6332  in 5000.5639     make

notes
1) all timing runs were made in LINUX Ubuntu 20.04 (WLA)
2) all run times are typical of what is be expected( at least on my hardware)
3) the GCC and clang 10 outputs are ELF files and will not execute in power shell

use X64 native tools command prompt for VS2019
msbuild sieve2.SLN -p:configuration=Release
keith@BRK-NJMVRB1:/mnt/d/myprojects/projects.cpp/sieve$ ./bin/x64/primesieve.exe
primesieve.exe
--n1000000
--t5000
passes: 11189 elapsed time  5000.4091 mS avg/pass     0.4469 mS limit 1000000 count 78498 valid 1
keith@BRK-NJMVRB1:/mnt/d/myprojects/projects.cpp/sieve$ ./bin/x64/primesieve.exe
primesieve.exe
--n1000000
--t5000
passes: 11153 elapsed time  5000.2334 mS avg/pass     0.4483 mS limit 1000000 count 78498 valid 1


nvidia nvcc
use power shell
nmake clean
nmake
keith@BRK-NJMVRB1:/mnt/d/myprojects/projects.cpp/sieve$ ./bin/nvcc/primesieve.exe
primesieve.exe
--n1000000
--t5000
passes: 9152 elapsed time  5000.2058 mS avg/pass     0.5464 mS limit 1000000 count 78498 valid 1
keith@BRK-NJMVRB1:/mnt/d/myprojects/projects.cpp/sieve$ ./bin/nvcc/primesieve.exe
primesieve.exe
--n1000000
--t5000
passes: 9113 elapsed time  5000.1511 mS avg/pass     0.5487 mS limit 1000000 count 78498 valid 1


clang_11 clang++
use power shell
nmake clean
nmake
keith@BRK-NJMVRB1:/mnt/d/myprojects/projects.cpp/sieve$ ./bin/clang_11/primesieve.exe
primesieve.exe
--n1000000
--t5000
passes: 6358 elapsed time  5000.1779 mS avg/pass     0.7864 mS limit 1000000 count 78498 valid 1
keith@BRK-NJMVRB1:/mnt/d/myprojects/projects.cpp/sieve$ ./bin/clang_11/primesieve.exe
primesieve.exe
--n1000000
--t5000
passes: 6344 elapsed time  5000.8166 mS avg/pass     0.7883 mS limit 1000000 count 78498 valid 1
keith@BRK-NJMVRB1:/mnt/d/myprojects/projects.cpp/sieve$

clang_10 clang++
use ubunto (wla)
make clean
make
keith@BRK-NJMVRB1:/mnt/d/myprojects/projects.cpp/sieve$ ./bin/clang_10/primesieve
./bin/clang_10/primesieve
--n1000000
--t5000
passes: 6332 elapsed time  5000.5639 mS avg/pass     0.7897 mS limit 1000000 count 78498 valid 1
keith@BRK-NJMVRB1:/mnt/d/myprojects/projects.cpp/sieve$ ./bin/clang_10/primesieve
./bin/clang_10/primesieve
--n1000000
--t5000
passes: 6339 elapsed time  5000.6761 mS avg/pass     0.7889 mS limit 1000000 count 78498 valid 1
keith@BRK-NJMVRB1:/mnt/d/myprojects/projects.cpp/sieve$

gcc g++
use ubunto (wla)
make clean
make
keith@BRK-NJMVRB1:/mnt/d/myprojects/projects.cpp/sieve$ ./bin/gcc/primesieve
./bin/gcc/primesieve
--n1000000
--t5000
passes: 7215 elapsed time  5000.3578 mS avg/pass     0.6931 mS limit 1000000 count 78498 valid 1
keith@BRK-NJMVRB1:/mnt/d/myprojects/projects.cpp/sieve$ ./bin/gcc/primesieve
./bin/gcc/primesieve
--n1000000
--t5000
passes: 7206 elapsed time  5000.4900 mS avg/pass     0.6939 mS limit 1000000 count 78498 valid 1
keith@BRK-NJMVRB1:/mnt/d/myprojects/projects.cpp/sieve$
