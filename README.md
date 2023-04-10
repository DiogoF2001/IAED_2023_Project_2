# Projecto 2 - IAED 2022/2023

## Enunciado

O enunciado do projecto está disponível em [enunciado.md](enunciado.md). 

## Data de entrega: 14 de abril de 2023, às 19h59

Informações detalhadas sobre o processo de submissão estão disponíveis em [informacoes.md](informacoes.md).



# Evaluation

2023-04-10T17:40:34

## Test 1: [+ Accepted+].
## Test 2: [+ Accepted+].
## Test 3: [+ Accepted+].
## Test 4: [+ Accepted+].
## Test 5: [+ Accepted+].
## Test 6: [+ Accepted+].
## Test 7: [+ Accepted+].
## Test 8: [+ Accepted+].
## Test 9: [+ Accepted+].
## Test 10: [+ Accepted+].
## Test 11: [+ Accepted+].
## Test 12: [+ Accepted+].
## Test 13: [+ Accepted+].
## Test 14: [+ Accepted+].
## Test 15: [+ Accepted+].
## Test 16: [+ Accepted+].
## Test 17: [+ Accepted+].
## Test 18: [- Wrong Answer-].


## Test 19: [- Wrong Answer-].


## Test 20: [- Wrong Answer-].


## Test 21: [- Command terminated by signal (11: SIGSEGV)-].

## Test 22: [+ Accepted+].
## Test 23: [+ Accepted+].
## Test 24: [- Command terminated by signal (11: SIGSEGV)-].

## Test 25: [- Wrong Answer-].


## Test 26: [- Command terminated by signal (11: SIGSEGV)-].

## Test 27: [+ Accepted+].
## Test 28: [+ Accepted+].
## Test 29: [+ Accepted+].
## Test 30: [+ Accepted+].
## Test 31: [- Command terminated by signal (11: SIGSEGV)-].

## Test 32: [+ Accepted+].


## Number of passed tests: 24/32


## Valgrind Output:


```
==22429== Memcheck, a memory error detector
==22429== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==22429== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==22429== Command: ./proj.out
==22429== 
==22429== Invalid read of size 8
==22429==    at 0x1099AB: Print_Car (functions.c:240)
==22429==    by 0x10A036: Modo_C (modes.c:27)
==22429==    by 0x10930F: main (project2.c:70)
==22429==  Address 0x4be46f0 is 0 bytes inside a block of size 40 free'd
==22429==    at 0x48369AB: free (vg_replace_malloc.c:530)
==22429==    by 0x10ACCF: Modo_E (modes.c:484)
==22429==    by 0x1092F0: main (project2.c:90)
==22429==  Block was alloc'd at
==22429==    at 0x483577F: malloc (vg_replace_malloc.c:299)
==22429==    by 0x10952D: Init_Par (functions.c:53)
==22429==    by 0x10A447: Modo_P (modes.c:152)
==22429==    by 0x10926E: main (project2.c:74)
==22429== 
==22429== Invalid read of size 1
==22429==    at 0x4838CC2: __strlen_sse2 (vg_replace_strmem.c:462)
==22429==    by 0x4A21B1E: vfprintf (vfprintf.c:1638)
==22429==    by 0x4A28735: printf (printf.c:33)
==22429==    by 0x1099B4: Print_Car (functions.c:240)
==22429==    by 0x10A036: Modo_C (modes.c:27)
==22429==    by 0x10930F: main (project2.c:70)
==22429==  Address 0x4be4760 is 0 bytes inside a block of size 9 free'd
==22429==    at 0x48369AB: free (vg_replace_malloc.c:530)
==22429==    by 0x109D38: Free_Par (functions.c:365)
==22429==    by 0x10ACCF: Modo_E (modes.c:484)
==22429==    by 0x1092F0: main (project2.c:90)
==22429==  Block was alloc'd at
==22429==    at 0x483577F: malloc (vg_replace_malloc.c:299)
==22429==    by 0x10A4CF: Modo_P (modes.c:159)
==22429==    by 0x10926E: main (project2.c:74)
==22429== 
==22429== Invalid read of size 1
==22429==    at 0x4838CD4: __strlen_sse2 (vg_replace_strmem.c:462)
==22429==    by 0x4A21B1E: vfprintf (vfprintf.c:1638)
==22429==    by 0x4A28735: printf (printf.c:33)
==22429==    by 0x1099B4: Print_Car (functions.c:240)
==22429==    by 0x10A036: Modo_C (modes.c:27)
==22429==    by 0x10930F: main (project2.c:70)
==22429==  Address 0x4be4761 is 1 bytes inside a block of size 9 free'd
==22429==    at 0x48369AB: free (vg_replace_malloc.c:530)
==22429==    by 0x109D38: Free_Par (functions.c:365)
==22429==    by 0x10ACCF: Modo_E (modes.c:484)
==22429==    by 0x1092F0: main (project2.c:90)
==22429==  Block was alloc'd at
==22429==    at 0x483577F: malloc (vg_replace_malloc.c:299)
==22429==    by 0x10A4CF: Modo_P (modes.c:159)
==22429==    by 0x10926E: main (project2.c:74)
==22429== 
==22429== Invalid read of size 1
==22429==    at 0x483D4E0: mempcpy (vg_replace_strmem.c:1536)
==22429==    by 0x4A4BB24: _IO_new_file_xsputn (fileops.c:1243)
==22429==    by 0x4A4BB24: _IO_file_xsputn@@GLIBC_2.2.5 (fileops.c:1204)
==22429==    by 0x4A2032A: vfprintf (vfprintf.c:1638)
==22429==    by 0x4A28735: printf (printf.c:33)
==22429==    by 0x1099B4: Print_Car (functions.c:240)
==22429==    by 0x10A036: Modo_C (modes.c:27)
==22429==    by 0x10930F: main (project2.c:70)
==22429==  Address 0x4be4767 is 7 bytes inside a block of size 9 free'd
==22429==    at 0x48369AB: free (vg_replace_malloc.c:530)
==22429==    by 0x109D38: Free_Par (functions.c:365)
==22429==    by 0x10ACCF: Modo_E (modes.c:484)
==22429==    by 0x1092F0: main (project2.c:90)
==22429==  Block was alloc'd at
==22429==    at 0x483577F: malloc (vg_replace_malloc.c:299)
==22429==    by 0x10A4CF: Modo_P (modes.c:159)
==22429==    by 0x10926E: main (project2.c:74)
==22429== 
==22429== Invalid read of size 1
==22429==    at 0x483D4F1: mempcpy (vg_replace_strmem.c:1536)
==22429==    by 0x4A4BB24: _IO_new_file_xsputn (fileops.c:1243)
==22429==    by 0x4A4BB24: _IO_file_xsputn@@GLIBC_2.2.5 (fileops.c:1204)
==22429==    by 0x4A2032A: vfprintf (vfprintf.c:1638)
==22429==    by 0x4A28735: printf (printf.c:33)
==22429==    by 0x1099B4: Print_Car (functions.c:240)
==22429==    by 0x10A036: Modo_C (modes.c:27)
==22429==    by 0x10930F: main (project2.c:70)
==22429==  Address 0x4be4765 is 5 bytes inside a block of size 9 free'd
==22429==    at 0x48369AB: free (vg_replace_malloc.c:530)
==22429==    by 0x109D38: Free_Par (functions.c:365)
==22429==    by 0x10ACCF: Modo_E (modes.c:484)
==22429==    by 0x1092F0: main (project2.c:90)
==22429==  Block was alloc'd at
==22429==    at 0x483577F: malloc (vg_replace_malloc.c:299)
==22429==    by 0x10A4CF: Modo_P (modes.c:159)
==22429==    by 0x10926E: main (project2.c:74)
==22429== 
==22429== Invalid read of size 8
==22429==    at 0x109994: Print_Car (functions.c:239)
==22429==    by 0x10A036: Modo_C (modes.c:27)
==22429==    by 0x10930F: main (project2.c:70)
==22429==  Address 0x4bb41f0 is 0 bytes inside a block of size 40 free'd
==22429==    at 0x48369AB: free (vg_replace_malloc.c:530)
==22429==    by 0x10ACCF: Modo_E (modes.c:484)
==22429==    by 0x1092F0: main (project2.c:90)
==22429==  Block was alloc'd at
==22429==    at 0x483577F: malloc (vg_replace_malloc.c:299)
==22429==    by 0x10952D: Init_Par (functions.c:53)
==22429==    by 0x10A447: Modo_P (modes.c:152)
==22429==    by 0x10926E: main (project2.c:74)
==22429== 
==22429== Invalid read of size 1
==22429==    at 0x4838CC2: __strlen_sse2 (vg_replace_strmem.c:462)
==22429==    by 0x4A21B1E: vfprintf (vfprintf.c:1638)
==22429==    by 0x4A28735: printf (printf.c:33)
==22429==    by 0x10999D: Print_Car (functions.c:239)
==22429==    by 0x10A036: Modo_C (modes.c:27)
==22429==    by 0x10930F: main (project2.c:70)
==22429==  Address 0x4bb4260 is 0 bytes inside a block of size 9 free'd
==22429==    at 0x48369AB: free (vg_replace_malloc.c:530)
==22429==    by 0x109D38: Free_Par (functions.c:365)
==22429==    by 0x10ACCF: Modo_E (modes.c:484)
==22429==    by 0x1092F0: main (project2.c:90)
==22429==  Block was alloc'd at
==22429==    at 0x483577F: malloc (vg_replace_malloc.c:299)
==22429==    by 0x10A4CF: Modo_P (modes.c:159)
==22429==    by 0x10926E: main (project2.c:74)
==22429== 
==22429== Invalid read of size 1
==22429==    at 0x4838CD4: __strlen_sse2 (vg_replace_strmem.c:462)
==22429==    by 0x4A21B1E: vfprintf (vfprintf.c:1638)
==22429==    by 0x4A28735: printf (printf.c:33)
==22429==    by 0x10999D: Print_Car (functions.c:239)
==22429==    by 0x10A036: Modo_C (modes.c:27)
==22429==    by 0x10930F: main (project2.c:70)
==22429==  Address 0x4bb4261 is 1 bytes inside a block of size 9 free'd
==22429==    at 0x48369AB: free (vg_replace_malloc.c:530)
==22429==    by 0x109D38: Free_Par (functions.c:365)
==22429==    by 0x10ACCF: Modo_E (modes.c:484)
==22429==    by 0x1092F0: main (project2.c:90)
==22429==  Block was alloc'd at
==22429==    at 0x483577F: malloc (vg_replace_malloc.c:299)
==22429==    by 0x10A4CF: Modo_P (modes.c:159)
==22429==    by 0x10926E: main (project2.c:74)
==22429== 
==22429== Invalid read of size 8
==22429==    at 0x10AAA3: Modo_R (modes.c:407)
==22429==    by 0x109329: main (project2.c:86)
==22429==  Address 0x4bb4210 is 32 bytes inside a block of size 40 free'd
==22429==    at 0x48369AB: free (vg_replace_malloc.c:530)
==22429==    by 0x10ACCF: Modo_E (modes.c:484)
==22429==    by 0x1092F0: main (project2.c:90)
==22429==  Block was alloc'd at
==22429==    at 0x483577F: malloc (vg_replace_malloc.c:299)
==22429==    by 0x10952D: Init_Par (functions.c:53)
==22429==    by 0x10A447: Modo_P (modes.c:152)
==22429==    by 0x10926E: main (project2.c:74)
==22429== 
==22429== Invalid read of size 8
==22429==    at 0x10AAB3: Modo_R (modes.c:408)
==22429==    by 0x109329: main (project2.c:86)
==22429==  Address 0x4f87f98 is 8 bytes inside a block of size 16 free'd
==22429==    at 0x48369AB: free (vg_replace_malloc.c:530)
==22429==    by 0x109D2F: Free_Par (functions.c:363)
==22429==    by 0x10ACCF: Modo_E (modes.c:484)
==22429==    by 0x1092F0: main (project2.c:90)
==22429==  Block was alloc'd at
==22429==    at 0x483577F: malloc (vg_replace_malloc.c:299)
==22429==    by 0x109611: Init_lis_car_cell (functions.c:67)
==22429==    by 0x109611: Add_to_Car_lis (functions.c:107)
==22429==    by 0x10A71F: Modo_L (modes.c:353)
==22429==    by 0x1092B2: main (project2.c:78)
==22429== 
==22429== Invalid read of size 8
==22429==    at 0x10AAB7: Modo_R (modes.c:408)
==22429==    by 0x109329: main (project2.c:86)
==22429==  Address 0x4f87f90 is 0 bytes inside a block of size 16 free'd
==22429==    at 0x48369AB: free (vg_replace_malloc.c:530)
==22429==    by 0x109D2F: Free_Par (functions.c:363)
==22429==    by 0x10ACCF: Modo_E (modes.c:484)
==22429==    by 0x1092F0: main (project2.c:90)
==22429==  Block was alloc'd at
==22429==    at 0x483577F: malloc (vg_replace_malloc.c:299)
==22429==    by 0x109611: Init_lis_car_cell (functions.c:67)
==22429==    by 0x109611: Add_to_Car_lis (functions.c:107)
==22429==    by 0x10A71F: Modo_L (modes.c:353)
==22429==    by 0x1092B2: main (project2.c:78)
==22429== 
==22429== Invalid read of size 8
==22429==    at 0x109110: Modo_R.cold.0 (modes.c:414)
==22429==    by 0x109329: main (project2.c:86)
==22429==  Address 0x8 is not stack'd, malloc'd or (recently) free'd
==22429== 
==22429== 
==22429== Process terminating with default action of signal 11 (SIGSEGV)
==22429==  Access not within mapped region at address 0x8
==22429==    at 0x109110: Modo_R.cold.0 (modes.c:414)
==22429==    by 0x109329: main (project2.c:86)
==22429==  If you believe this happened as a result of a stack
==22429==  overflow in your program's main thread (unlikely but
==22429==  possible), you can try to increase the size of the
==22429==  main thread stack using the --main-stacksize= flag.
==22429==  The main thread stack size used in this run was 8388608.
==22429== 
==22429== HEAP SUMMARY:
==22429==     in use at exit: 66,472 bytes in 27 blocks
==22429==   total heap usage: 279 allocs, 252 frees, 6,762,075 bytes allocated
==22429== 
==22429== LEAK SUMMARY:
==22429==    definitely lost: 0 bytes in 0 blocks
==22429==    indirectly lost: 0 bytes in 0 blocks
==22429==      possibly lost: 0 bytes in 0 blocks
==22429==    still reachable: 66,472 bytes in 27 blocks
==22429==         suppressed: 0 bytes in 0 blocks
==22429== Rerun with --leak-check=full to see details of leaked memory
==22429== 
==22429== For counts of detected and suppressed errors, rerun with: -v
==22429== ERROR SUMMARY: 292 errors from 12 contexts (suppressed: 0 from 0)

```


Your code will not be reevaluated if you submit before 2023-04-10 17:50:34 @ Lisbon, Portugal. You need to wait 10 minute(s).

