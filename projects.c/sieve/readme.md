Summary of 'C' compilers                passes    milliseconds
Windows Microsoft 	VS2019		11186  in 5000.3278     IDE
Windows NIVDIA    	nvcc             9160  in 5000.4766     nmake
Windows clang 11.0      clang	         6351  in 5000.4000     nmake
Ubuntu  gcc 9.3		gcc		 7650  in 5000.5020     make
Ubuntu  clang 10.0	clang		 7269  in 5000.3320     make

notes
1) all timing runs were made in LINUX (WLA) (ubuntu 20.04)
2) all run times are typical of what is be expectedd( at least on my hardware)
3) the GCC and clang 10 outputs are ELF files  and will not execute in power shell

compiler used micosoft (cl) VS2019
sieve$ ./x64/release/primesieve.exe
--n1000000
--t5000
passes  10969 elapsed time  5000.2757 mS  avg/pass   0.4559 mS limit 1000000 counted 78498 validated 1
sieve$ ./x64/release/primesieve.exe
--n1000000
--t5000
passes  11075 elapsed time  5000.4519 mS  avg/pass   0.4515 mS limit 1000000 counted 78498 validated 1


##### use POWER SHELL AND NMAKE TO COMPILE #####
nvcc: NVIDIA (R) Cuda compiler driver
Copyright (c) 2005-2021 NVIDIA Corporation
Built on Wed_Jul_14_19:47:52_Pacific_Daylight_Time_2021
Cuda compilation tools, release 11.4, V11.4.100
Build cuda_11.4.r11.4/compiler.30188945_0
keith@BRK-NJMVRB1:/mnt/d/myProjects/projects.c/sieve$ ./a.exe
--n1000000
--t5000
passes   9160 elapsed time  5000.4766 mS  avg/pass   0.5459 mS limit 1000000 counted 78498 validated 1

clang version 11.0.0
Target: x86_64-pc-windows-msvc
Thread model: posix
InstalledDir: C:\myPrograms\vs2019\VC\Tools\Llvm\x64\bin
sieve$ ./clang/primesieve.exe
--n1000000
--t5000
passes   6214 elapsed time  5000.7590 mS  avg/pass   0.8048 mS limit 1000000 counted 78498 validated 1
sieve$ ./clang/primesieve.exe
--n1000000
--t5000
passes   6253 elapsed time  5000.5378 mS  avg/pass   0.7997 mS limit 1000000 counted 78498 validated 1


#### USE LINUX BASH (WLA) AND MAKE TO COMPILE #####
gcc --version
gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
Copyright (C) 2019 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
gcc -O2  -flto -I../headers ../src/primeSieve.c  ../src/sieve.c  ../src/tbitarray.c -oGCCprimeSieve
sieve/gcc$ ./GCCprimesieve
--n1000000
--t5000
passes   7453 elapsed time  5000.4255 mS  avg/pass   0.6709 mS limit 1000000 counted 78498 validated 1


clang --version
clang version 10.0.0-4ubuntu1
Target: x86_64-pc-linux-gnu
Thread model: posix
InstalledDir: /usr/bin
clang -O2   -flto -I../headers ../src/primeSieve.c  ../src/sieve.c  ../src/tbitarray.c -oCLANGprimeSieve
sieve/gcc$ ./CLANGprimesieve
--n1000000
--t5000
passes   7162 elapsed time  5000.4411 mS  avg/pass   0.6982 mS limit 1000000 counted 78498 validated 1
