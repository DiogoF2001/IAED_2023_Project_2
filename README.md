# Projecto 2 - IAED 2022/2023

## Enunciado

O enunciado do projecto está disponível em [enunciado.md](enunciado.md). 

## Data de entrega: 14 de abril de 2023, às 19h59

Informações detalhadas sobre o processo de submissão estão disponíveis em [informacoes.md](informacoes.md).



# Evaluation

2023-04-11T17:11:58

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

## Test 25: [- Wrong Answer-].


## Test 26: [- Wrong Answer-].


## Test 27: [+ Accepted+].
## Test 28: [+ Accepted+].
## Test 29: [+ Accepted+].
## Test 30: [+ Accepted+].
## Test 31: [+ Accepted+].
## Test 32: [+ Accepted+].


## Number of passed tests: 27/32


## Valgrind Output:


```
==29856== Memcheck, a memory error detector
==29856== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==29856== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==29856== Command: ./proj.out
==29856== 
==29856== Invalid read of size 8
==29856==    at 0x10AC98: Modo_E (modes.c:487)
==29856==    by 0x1092E8: main (project2.c:68)
==29856==  Address 0x4c55090 is 32 bytes inside a block of size 40 free'd
==29856==    at 0x48369AB: free (vg_replace_malloc.c:530)
==29856==    by 0x10AC94: Modo_E (modes.c:486)
==29856==    by 0x1092E8: main (project2.c:68)
==29856==  Block was alloc'd at
==29856==    at 0x483577F: malloc (vg_replace_malloc.c:299)
==29856==    by 0x1096CD: Init_lis_par_cell (functions.c:142)
==29856==    by 0x10A84D: Modo_L (modes.c:268)
==29856==    by 0x1092B2: main (project2.c:56)
==29856== 
==29856== 
==29856== HEAP SUMMARY:
==29856==     in use at exit: 0 bytes in 0 blocks
==29856==   total heap usage: 290 allocs, 290 frees, 7,220,856 bytes allocated
==29856== 
==29856== All heap blocks were freed -- no leaks are possible
==29856== 
==29856== For counts of detected and suppressed errors, rerun with: -v
==29856== ERROR SUMMARY: 24 errors from 1 contexts (suppressed: 0 from 0)

```


Your code will not be reevaluated if you submit before 2023-04-11 17:21:58 @ Lisbon, Portugal. You need to wait 10 minute(s).

