# Projecto 2 - IAED 2022/2023

## Enunciado

O enunciado do projecto está disponível em [enunciado.md](enunciado.md). 

## Data de entrega: 14 de abril de 2023, às 19h59

Informações detalhadas sobre o processo de submissão estão disponíveis em [informacoes.md](informacoes.md).



# Evaluation

2023-04-14T16:01:33

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
## Test 20: [+ Accepted+].
## Test 21: [+ Accepted+].
## Test 22: [+ Accepted+].
## Test 23: [+ Accepted+].
## Test 24: [+ Accepted+].
## Test 25: [- Command terminated by signal (11: SIGSEGV)-].

## Test 26: [- Command terminated by signal (11: SIGSEGV)-].

## Test 27: [+ Accepted+].
## Test 28: [+ Accepted+].
## Test 29: [+ Accepted+].
## Test 30: [+ Accepted+].
## Test 31: [- Command terminated by signal (6: SIGABRT)-].

## Test 32: [+ Accepted+].


## Number of passed tests: 29/32


## Valgrind Output:


```
==24729== Memcheck, a memory error detector
==24729== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==24729== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==24729== Command: ./proj.out
==24729== 
==24729== Invalid read of size 8
==24729==    at 0x10ACC5: Modo_E (modes.c:461)
==24729==    by 0x1092D8: main (project2.c:68)
==24729==  Address 0x4c853a0 is 0 bytes inside a block of size 16 free'd
==24729==    at 0x48369AB: free (vg_replace_malloc.c:530)
==24729==    by 0x109F83: Free_Car_in_Par (functions.c:421)
==24729==    by 0x10ADF3: Modo_E (modes.c:458)
==24729==    by 0x1092D8: main (project2.c:68)
==24729==  Block was alloc'd at
==24729==    at 0x483577F: malloc (vg_replace_malloc.c:299)
==24729==    by 0x109611: Init_lis_car_cell (functions.c:67)
==24729==    by 0x109611: Add_to_Car_lis (functions.c:107)
==24729==    by 0x10A942: Modo_L (modes.c:357)
==24729==    by 0x1092A2: main (project2.c:56)
==24729== 
==24729== Invalid read of size 8
==24729==    at 0x10ACD1: Modo_E (modes.c:462)
==24729==    by 0x1092D8: main (project2.c:68)
==24729==  Address 0x4c853a0 is 0 bytes inside a block of size 16 free'd
==24729==    at 0x48369AB: free (vg_replace_malloc.c:530)
==24729==    by 0x109F83: Free_Car_in_Par (functions.c:421)
==24729==    by 0x10ADF3: Modo_E (modes.c:458)
==24729==    by 0x1092D8: main (project2.c:68)
==24729==  Block was alloc'd at
==24729==    at 0x483577F: malloc (vg_replace_malloc.c:299)
==24729==    by 0x109611: Init_lis_car_cell (functions.c:67)
==24729==    by 0x109611: Add_to_Car_lis (functions.c:107)
==24729==    by 0x10A942: Modo_L (modes.c:357)
==24729==    by 0x1092A2: main (project2.c:56)
==24729== 
==24729== Invalid free() / delete / delete[] / realloc()
==24729==    at 0x48369AB: free (vg_replace_malloc.c:530)
==24729==    by 0x10ACDC: Modo_E (modes.c:462)
==24729==    by 0x1092D8: main (project2.c:68)
==24729==  Address 0x4c85330 is 0 bytes inside a block of size 40 free'd
==24729==    at 0x48369AB: free (vg_replace_malloc.c:530)
==24729==    by 0x10ACD0: Modo_E (modes.c:461)
==24729==    by 0x1092D8: main (project2.c:68)
==24729==  Block was alloc'd at
==24729==    at 0x483577F: malloc (vg_replace_malloc.c:299)
==24729==    by 0x1096BD: Init_lis_par_cell (functions.c:142)
==24729==    by 0x10A7FF: Modo_L (modes.c:311)
==24729==    by 0x1092A2: main (project2.c:56)
==24729== 
==24729== Invalid read of size 8
==24729==    at 0x10ACDD: Modo_E (modes.c:463)
==24729==    by 0x1092D8: main (project2.c:68)
==24729==  Address 0x4c853a0 is 0 bytes inside a block of size 16 free'd
==24729==    at 0x48369AB: free (vg_replace_malloc.c:530)
==24729==    by 0x109F83: Free_Car_in_Par (functions.c:421)
==24729==    by 0x10ADF3: Modo_E (modes.c:458)
==24729==    by 0x1092D8: main (project2.c:68)
==24729==  Block was alloc'd at
==24729==    at 0x483577F: malloc (vg_replace_malloc.c:299)
==24729==    by 0x109611: Init_lis_car_cell (functions.c:67)
==24729==    by 0x109611: Add_to_Car_lis (functions.c:107)
==24729==    by 0x10A942: Modo_L (modes.c:357)
==24729==    by 0x1092A2: main (project2.c:56)
==24729== 
==24729== Invalid read of size 8
==24729==    at 0x10ACFA: Modo_E (modes.c:454)
==24729==    by 0x1092D8: main (project2.c:68)
==24729==  Address 0x4c853a8 is 8 bytes inside a block of size 16 free'd
==24729==    at 0x48369AB: free (vg_replace_malloc.c:530)
==24729==    by 0x109F83: Free_Car_in_Par (functions.c:421)
==24729==    by 0x10ADF3: Modo_E (modes.c:458)
==24729==    by 0x1092D8: main (project2.c:68)
==24729==  Block was alloc'd at
==24729==    at 0x483577F: malloc (vg_replace_malloc.c:299)
==24729==    by 0x109611: Init_lis_car_cell (functions.c:67)
==24729==    by 0x109611: Add_to_Car_lis (functions.c:107)
==24729==    by 0x10A942: Modo_L (modes.c:357)
==24729==    by 0x1092A2: main (project2.c:56)
==24729== 
==24729== 
==24729== HEAP SUMMARY:
==24729==     in use at exit: 160 bytes in 4 blocks
==24729==   total heap usage: 290 allocs, 290 frees, 7,220,856 bytes allocated
==24729== 
==24729== LEAK SUMMARY:
==24729==    definitely lost: 160 bytes in 4 blocks
==24729==    indirectly lost: 0 bytes in 0 blocks
==24729==      possibly lost: 0 bytes in 0 blocks
==24729==    still reachable: 0 bytes in 0 blocks
==24729==         suppressed: 0 bytes in 0 blocks
==24729== Rerun with --leak-check=full to see details of leaked memory
==24729== 
==24729== For counts of detected and suppressed errors, rerun with: -v
==24729== ERROR SUMMARY: 20 errors from 5 contexts (suppressed: 0 from 0)

```


Your code will not be reevaluated if you submit before 2023-04-14 16:11:33 @ Lisbon, Portugal. You need to wait 10 minute(s).

