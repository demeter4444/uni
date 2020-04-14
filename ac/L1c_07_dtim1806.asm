;Demeter Tamás , dtim1806, 511/2
;Labor 1, C feladatsor, 7. feladatsor
;felteteles kifejezes
	;7.
	;ha d mod 4 = 0 : (b - a) * 2
	;ha d mod 4 = 1 : 13 - c
	;ha d mod 4 = 2 : (9 - b) div a
	;ha d mod 4 = 3 : c * (a - c)

;cmp = compare valami,valami
;je = jump if equal valami(cim)

; nasm -f win32 iodemo.asm
; nlink iodemo.obj -lio -o iodemo.exe

%include 'io.inc'

global main

section .text
main:
mov eax, str_fel
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
mov [d],eax
; eax -> ures ebx -> b ecx -> c edx -> a [d] -> data

push ebx
push edx
mov eax,[d]	;verem -> b,a
cdq
mov ebx, 4
idiv ebx

;ami szamit -> edx.  eax -> semmi fontos
;eax -> szemet ebx -> szemet ecx -> c edx -> d mod 4

mov eax,str_dmod
call io_writestr
mov eax,edx
call io_writeint
call io_writeln
pop eax
pop ebx ;eax -> a, ebx-> b, ecx -> c


cmp edx,0
je A1

cmp edx,1
je A2

cmp edx,2
je A3

cmp edx,3
je A4

	A1:

sub ebx, eax
imul ebx, 2
mov eax,str_er
call io_writestr
mov eax,ebx
call io_writeint
ret

	A2:

mov edx,13
sub edx,ecx
mov eax,str_er
call io_writestr
mov eax,edx
call io_writeint
ret

	A3:
	
mov ecx,eax
mov edx,9
sub edx,ebx
mov eax,edx
cdq
idiv ecx
mov edx,eax
mov eax, str_er
call io_writestr
mov eax,edx
call io_writeint
ret

	A4:
	
sub eax,ecx
imul eax,ecx
mov edx,eax
mov eax,str_er
call io_writestr
mov eax,edx
call io_writeint
ret

section .data
str_fel db 'ha d mod 4 = 0 : (b - a) * 2 ,ha d mod 4 = 1 : 13 - c, ha d mod 4 = 2 : (9 - b) div a ,ha d mod 4 = 3 : c * (a - c)',0
str_a db 'A = ',0
str_b db 'B = ',0
str_c db 'C = ',0
str_d db 'D = ',0
str_dmod db 'D mod 4 = ',0
str_er db 'Eredmeny = ',0

section .bss
d resd 1