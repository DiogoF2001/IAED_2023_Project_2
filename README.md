# Projecto 2 - IAED 2022/2023

## Enunciado

O enunciado do projecto está disponível em [enunciado.md](enunciado.md). 

## Data de entrega: 14 de abril de 2023, às 19h59

Informações detalhadas sobre o processo de submissão estão disponíveis em [informacoes.md](informacoes.md).



# Evaluation

2023-04-12T17:50:41

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
## Test 18: [+ Accepted+].
## Test 19: [+ Accepted+].
## Test 20: [- Command terminated by signal (11: SIGSEGV)-].

## Test 21: [- Command terminated by signal (11: SIGSEGV)-].

## Test 22: [+ Accepted+].
## Test 23: [+ Accepted+].
## Test 24: [- Command terminated by signal (11: SIGSEGV)-].

## Test 25: [- Command terminated by signal (11: SIGSEGV)-].

## Test 26: [- Command terminated by signal (11: SIGSEGV)-].

## Test 27: [+ Accepted+].
## Test 28: [+ Accepted+].
## Test 29: [+ Accepted+].
## Test 30: [+ Accepted+].
## Test 31: [+ Accepted+].
## Test 32: [+ Accepted+].


## Number of passed tests: 27/32


## Valgrind Output:


```
==1366== Memcheck, a memory error detector
==1366== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==1366== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==1366== Command: ./proj.out
==1366== 
==1366== Invalid read of size 8
==1366==    at 0x10ACE1: Modo_E (modes.c:458)
==1366==    by 0x1092E8: main (project2.c:68)
==1366==  Address 0x4c853a0 is 0 bytes inside a block of size 16 free'd
==1366==    at 0x48369AB: free (vg_replace_malloc.c:530)
==1366==    by 0x109F93: Free_Car_in_Par (functions.c:421)
==1366==    by 0x10AE13: Modo_E (modes.c:455)
==1366==    by 0x1092E8: main (project2.c:68)
==1366==  Block was alloc'd at
==1366==    at 0x483577F: malloc (vg_replace_malloc.c:299)
==1366==    by 0x109621: Init_lis_car_cell (functions.c:67)
==1366==    by 0x109621: Add_to_Car_lis (functions.c:107)
==1366==    by 0x10A952: Modo_L (modes.c:356)
==1366==    by 0x1092B2: main (project2.c:56)
==1366== 
==1366== Invalid read of size 8
==1366==    at 0x10ACED: Modo_E (modes.c:459)
==1366==    by 0x1092E8: main (project2.c:68)
==1366==  Address 0x4c853a0 is 0 bytes inside a block of size 16 free'd
==1366==    at 0x48369AB: free (vg_replace_malloc.c:530)
==1366==    by 0x109F93: Free_Car_in_Par (functions.c:421)
==1366==    by 0x10AE13: Modo_E (modes.c:455)
==1366==    by 0x1092E8: main (project2.c:68)
==1366==  Block was alloc'd at
==1366==    at 0x483577F: malloc (vg_replace_malloc.c:299)
==1366==    by 0x109621: Init_lis_car_cell (functions.c:67)
==1366==    by 0x109621: Add_to_Car_lis (functions.c:107)
==1366==    by 0x10A952: Modo_L (modes.c:356)
==1366==    by 0x1092B2: main (project2.c:56)
==1366== 
==1366== Invalid read of size 8
==1366==    at 0x10ACF9: Modo_E (modes.c:460)
==1366==    by 0x1092E8: main (project2.c:68)
==1366==  Address 0x4c853a0 is 0 bytes inside a block of size 16 free'd
==1366==    at 0x48369AB: free (vg_replace_malloc.c:530)
==1366==    by 0x109F93: Free_Car_in_Par (functions.c:421)
==1366==    by 0x10AE13: Modo_E (modes.c:455)
==1366==    by 0x1092E8: main (project2.c:68)
==1366==  Block was alloc'd at
==1366==    at 0x483577F: malloc (vg_replace_malloc.c:299)
==1366==    by 0x109621: Init_lis_car_cell (functions.c:67)
==1366==    by 0x109621: Add_to_Car_lis (functions.c:107)
==1366==    by 0x10A952: Modo_L (modes.c:356)
==1366==    by 0x1092B2: main (project2.c:56)
==1366== 
==1366== Invalid read of size 8
==1366==    at 0x10AD16: Modo_E (modes.c:451)
==1366==    by 0x1092E8: main (project2.c:68)
==1366==  Address 0x4c853a8 is 8 bytes inside a block of size 16 free'd
==1366==    at 0x48369AB: free (vg_replace_malloc.c:530)
==1366==    by 0x109F93: Free_Car_in_Par (functions.c:421)
==1366==    by 0x10AE13: Modo_E (modes.c:455)
==1366==    by 0x1092E8: main (project2.c:68)
==1366==  Block was alloc'd at
==1366==    at 0x483577F: malloc (vg_replace_malloc.c:299)
==1366==    by 0x109621: Init_lis_car_cell (functions.c:67)
==1366==    by 0x109621: Add_to_Car_lis (functions.c:107)
==1366==    by 0x10A952: Modo_L (modes.c:356)
==1366==    by 0x1092B2: main (project2.c:56)
==1366== 
==1366== 
==1366== HEAP SUMMARY:
==1366==     in use at exit: 0 bytes in 0 blocks
==1366==   total heap usage: 290 allocs, 290 frees, 7,220,856 bytes allocated
==1366== 
==1366== All heap blocks were freed -- no leaks are possible
==1366== 
==1366== For counts of detected and suppressed errors, rerun with: -v
==1366== ERROR SUMMARY: 16 errors from 4 contexts (suppressed: 0 from 0)

```


Your code will not be reevaluated if you submit before 2023-04-12 18:00:41 @ Lisbon, Portugal. You need to wait 10 minute(s).

