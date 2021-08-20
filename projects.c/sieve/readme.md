Summary of 'C' compilers                passes    milliseconds
Windows Microsoft 	VS2019		11186  in 5000.3278     IDE
Windows NIVDIA    	nvcc             9160  in 5000.4766     nmake
Windows clang 11.0      clang	         6351  in 5000.4000     nmake
Ubuntu  gcc 9.3		gcc		 7650  in 5000.5020     make
Ubuntu  clang 10.0	clang		 7269  in 5000.3320     make

notes
1) all timing runs were made in LINUX (WLA)
2) all run times are typical of what is be expectedd( at least on my hardware
3) the GCC and clang 10 outpus are ELF files  and will nor execute in power shell

compiler used micosoft (cl) VS2019
keith@BRK-NJMVRB1:/mnt/d/myProjects/projects.c/sieve$ ./x64/release/primesieve.exe
--n1000000
--t5000
passes  11186 elapsed time  5000.3278 mS  avg/pass   0.4470 mS limit 1000000 counted 78498 validated 1


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
keith@BRK-NJMVRB1:/mnt/d/myProjects/projects.c/sieve$ ./clang/primeSieve.exe
--n1000000
--t5000
passes   6351 elapsed time  5000.4000 mS  avg/pass   0.7873 mS limit 1000000 counted 78498 validated 1


#### USE LINUX BASH (WLA) ANC MAKE TO COMPILE #####
gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
keith@BRK-NJMVRB1:/mnt/d/myProjects/projects.c/sieve$ ./gcc/primeSieve
--n1000000
--t5000
passes   7650 elapsed time  5000.5920 mS  avg/pass   0.6537 mS limit 1000000 counted 78498 validated 1

clang version 10.0.0-4ubuntu1
Target: x86_64-pc-linux-gnu
Thread model: posix
InstalledDir: /usr/bin
clang -O2   -flto -I../headers ../src/primeSieve.c  ../src/sieve.c  ../src/tbitarray.c -oCLANGprimeSieve
keith@BRK-NJMVRB1:/mnt/d/myProjects/projects.c/sieve/gcc$ ./CLANGprimeSieve
--n1000000
--t5000
passes   7269 elapsed time  5000.3320 mS  avg/pass   0.6879 mS limit 1000000 counted 78498 validated 1
