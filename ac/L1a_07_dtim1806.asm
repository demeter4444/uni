;Demeter Tamás, dtim1806, 511/2
;Labor 1, A feladatsor, 7. feladatsor
;olvassuk be  a,b,c,d,e,f,g ertekeit, majd irassuk ki az alabbi kifejezes erteket
;((a - (b * c)) div (a - b)) + ((b - e) div c) - ((f + g - 10) mod (g div 5)) - d

; nasm -f win32 iodemo.asm
; nlink iodemo.obj -lio -o iodemo.exe

;7. ((a - (b * c)) div (a - b)) + ((b - e) div c) - ((f + g - 10) mod (g div 5)) - d
;E(34,40,49,24,24,18,7) = 297

%include 'io.inc'

global main

section .text
main:

mov eax,str_test
call io_writestr
call io_writeln

mov eax,str_a
call io_writestr
call io_readint
mov edx,eax  ;edx -> a

mov eax,str_b
call io_writestr
call io_readint
mov ebx,eax   ;ebx -> b

mov eax,str_c
call io_writestr
call io_readint
mov [cc],eax ;  cc -> c

mov eax,str_d
call io_writestr
call io_readint
push eax  ; verem -> d

mov eax,str_e
call io_writestr
call io_readint
mov [e],eax ;e -> e

mov eax,str_f
call io_writestr
call io_readint
mov [f],eax ;f -> f

mov eax,str_g
call io_writestr
call io_readint
mov [g], eax ; g-> g		;((a - (b * c)) div (a + b))

mov eax, edx 	;		a,b,c,d,e,f.g -------> eax,ebx,cc,verem1,e,f,g
xor edx,edx
add edx,eax ; a -> eax,edx
sub edx, ebx ; edx -> a-b

push ebx  ; kesobb kell meg a b

imul ebx,[cc]
sub eax, ebx	;  eax -> a - (b * c) osztani kell: eax-et edx-el. ecx meg szabad.

mov ecx,edx
cdq
idiv ecx	; eax -> ((a - (b * c)) div (a - b))

;eddig yo
;eax - (a - (b * c)) div (a + b))   ebx - b    ecx-szabad edx-szabad

pop ebx
push eax	;jelenlegi verem: (a - (b * c)) div (a + b)) , d

sub ebx,[e]
mov eax,  ebx
cdq
mov ecx,[cc]
idiv ecx	; eax -> ((b - e) div c) 
	
;eddig yo

push eax

;eax -> ures  ebx -> ures(b mar nemkell) ecx,edx ures  verem: masodikzarojel,elsozarojel,d

mov ebx,[f]
add ebx,[g]
sub ebx, 10

mov eax, [g]
mov ecx, 5
cdq
idiv ecx	; eax -> g div 3
		;mostkell ebx mod eax
mov ecx,eax														
mov eax,ebx
cdq
idiv ecx ;ami kell az most edx-ben van(mod)

pop ebx ; ebx -> masodikzarojel
pop ecx ; ecx -> elsozarojel 
		; edx -> harmadikzarojel
pop eax ; eax -> d
add ecx,ebx
sub ecx,edx
sub ecx,eax

mov eax,str_test
call io_writestr
mov eax,ecx
call io_writeint

ret

section .data

str_a db 'A = ', 0
str_b db 'B = ', 0
str_c db 'C = ', 0
str_d db 'D = ', 0
str_e db 'E = ', 0
str_f db 'F = ', 0
str_g db 'G = ', 0
str_test db '((a - (b * c)) div (a + b)) - ((b + e) div c) - ((f + g - 10) mod (g div 3)) + d = ', 0

section .bss
e resd 1
f resd 1
g resd 1
cc resd 1