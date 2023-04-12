# Projecto 2 - IAED 2022/2023

## Enunciado

O enunciado do projecto está disponível em [enunciado.md](enunciado.md). 

## Data de entrega: 14 de abril de 2023, às 19h59

Informações detalhadas sobre o processo de submissão estão disponíveis em [informacoes.md](informacoes.md).



# Evaluation

2023-04-12T04:02:59

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
==737== Memcheck, a memory error detector
==737== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==737== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==737== Command: ./proj.out
==737== 
==737== Invalid read of size 8
==737==    at 0x10ACD1: Modo_E (modes.c:458)
==737==    by 0x1092E8: main (project2.c:68)
==737==  Address 0x4c853a0 is 0 bytes inside a block of size 16 free'd
==737==    at 0x48369AB: free (vg_replace_malloc.c:530)
==737==    by 0x109F77: Free_Car_in_Par (functions.c:418)
==737==    by 0x10AE03: Modo_E (modes.c:455)
==737==    by 0x1092E8: main (project2.c:68)
==737==  Block was alloc'd at
==737==    at 0x483577F: malloc (vg_replace_malloc.c:299)
==737==    by 0x109621: Init_lis_car_cell (functions.c:67)
==737==    by 0x109621: Add_to_Car_lis (functions.c:107)
==737==    by 0x10A942: Modo_L (modes.c:356)
==737==    by 0x1092B2: main (project2.c:56)
==737== 
==737== Invalid read of size 8
==737==    at 0x10ACDD: Modo_E (modes.c:459)
==737==    by 0x1092E8: main (project2.c:68)
==737==  Address 0x4c853a0 is 0 bytes inside a block of size 16 free'd
==737==    at 0x48369AB: free (vg_replace_malloc.c:530)
==737==    by 0x109F77: Free_Car_in_Par (functions.c:418)
==737==    by 0x10AE03: Modo_E (modes.c:455)
==737==    by 0x1092E8: main (project2.c:68)
==737==  Block was alloc'd at
==737==    at 0x483577F: malloc (vg_replace_malloc.c:299)
==737==    by 0x109621: Init_lis_car_cell (functions.c:67)
==737==    by 0x109621: Add_to_Car_lis (functions.c:107)
==737==    by 0x10A942: Modo_L (modes.c:356)
==737==    by 0x1092B2: main (project2.c:56)
==737== 
==737== Invalid read of size 8
==737==    at 0x10ACE9: Modo_E (modes.c:460)
==737==    by 0x1092E8: main (project2.c:68)
==737==  Address 0x4c853a0 is 0 bytes inside a block of size 16 free'd
==737==    at 0x48369AB: free (vg_replace_malloc.c:530)
==737==    by 0x109F77: Free_Car_in_Par (functions.c:418)
==737==    by 0x10AE03: Modo_E (modes.c:455)
==737==    by 0x1092E8: main (project2.c:68)
==737==  Block was alloc'd at
==737==    at 0x483577F: malloc (vg_replace_malloc.c:299)
==737==    by 0x109621: Init_lis_car_cell (functions.c:67)
==737==    by 0x109621: Add_to_Car_lis (functions.c:107)
==737==    by 0x10A942: Modo_L (modes.c:356)
==737==    by 0x1092B2: main (project2.c:56)
==737== 
==737== Invalid read of size 8
==737==    at 0x10AD06: Modo_E (modes.c:451)
==737==    by 0x1092E8: main (project2.c:68)
==737==  Address 0x4c853a8 is 8 bytes inside a block of size 16 free'd
==737==    at 0x48369AB: free (vg_replace_malloc.c:530)
==737==    by 0x109F77: Free_Car_in_Par (functions.c:418)
==737==    by 0x10AE03: Modo_E (modes.c:455)
==737==    by 0x1092E8: main (project2.c:68)
==737==  Block was alloc'd at
==737==    at 0x483577F: malloc (vg_replace_malloc.c:299)
==737==    by 0x109621: Init_lis_car_cell (functions.c:67)
==737==    by 0x109621: Add_to_Car_lis (functions.c:107)
==737==    by 0x10A942: Modo_L (modes.c:356)
==737==    by 0x1092B2: main (project2.c:56)
==737== 
==737== 
==737== HEAP SUMMARY:
==737==     in use at exit: 0 bytes in 0 blocks
==737==   total heap usage: 290 allocs, 290 frees, 7,220,856 bytes allocated
==737== 
==737== All heap blocks were freed -- no leaks are possible
==737== 
==737== For counts of detected and suppressed errors, rerun with: -v
==737== ERROR SUMMARY: 16 errors from 4 contexts (suppressed: 0 from 0)

```


Your code will not be reevaluated if you submit before 2023-04-12 04:12:59 @ Lisbon, Portugal. You need to wait 10 minute(s).

