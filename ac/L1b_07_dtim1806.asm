;Demeter Tamás, dtim1806, 511/2
;Labor 1, B feladatsor, 7. feladat
;a OR ((b XOR c) AND ((NOT a) XOR d))
;irassuk ki a kiertekelendo kifejezest, olvassuk be a,b,c,d ertekeit, majd irjuk ki binaris formaban az ertekeket es az eredmenyt

; nasm -f win32 iodemo.asm
; nlink iodemo.obj -lio -o iodemo.exe

%include 'io.inc'

global main

section .text
main:

mov eax,str_kif
call io_writestr
call io_writeln

mov eax,str_a
call io_writestr
call io_readint
mov edx,eax

mov eax,str_b
call io_writestr
call io_readint
mov ebx,eax

mov eax,str_c
call io_writestr
call io_readint
mov ecx,eax

mov eax,str_d
call io_writestr
call io_readint
xchg eax,edx

;a,b,c,d -> eax,ebx,ecx,edx

push eax
mov eax, str_a
call io_writestr
pop eax
call io_writebin
call io_writeln

xchg eax,ebx
push eax
mov eax,str_b
call io_writestr
pop eax
call io_writebin
call io_writeln
xchg eax,ebx

xchg eax,ecx
push eax
mov eax,str_c
call io_writestr
pop eax
call io_writebin
call io_writeln
xchg eax,ecx

xchg eax,edx
push eax
mov eax,str_d
call io_writestr
pop eax
call io_writebin
call io_writeln
xchg eax,edx

push eax
not eax
xor eax,edx
xor ebx,ecx
and eax,ebx
pop ecx
or eax,ecx
call io_writebin

ret

section .data
str_a db 'A = ',0
str_b db 'B = ',0
str_c db 'C = ',0
str_d db 'D = ',0
str_kif db 'a OR ((b XOR c) AND ((NOT a) XOR d))',0

section .bss