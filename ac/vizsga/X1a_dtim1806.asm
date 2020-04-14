%include 'mio.inc'
%include 'strings.inc'
%include 'iostr.inc'
%include 'ionum.inc'

global main

section .text
main:
mov esi,bea
call WriteStr
call ReadInt
mov [a],eax
call NewLine

mov esi,beb
call WriteStr
call ReadInt
mov [b],eax
call NewLine

mov esi,bec
call WriteStr
call ReadInt
mov [c],eax
call NewLine

mov esi,bed
call WriteStr
call ReadInt
mov [d],eax
call NewLine

mov esi,bee
call WriteStr
call ReadInt
mov [e],eax
call NewLine

mov esi,bef
call WriteStr
call ReadInt
mov [f],eax
call NewLine

mov esi,beg
call WriteStr
call ReadInt
mov [g],eax
call NewLine

mov esi,kif
call WriteLnStr

mov eax,[c]
mov ebx,[a]
imul ebx,ebx
imul ebx,[a]
sub eax,ebx ;elso kicsi zarojel eax-ban

mov ebx,[b]
cdq
idiv ebx ;tort eax-ban

mov ebx,[d]
sub eax,ebx
mov ebx,[e]
imul ebx,4
add eax,ebx 
xchg eax,ebx;elso nagy zarojel ebx-ben
;ne hasznaljunk ebxet innen
mov eax, [d]
mov ecx,13
cdq
idiv ecx ;masodik kicsizarojel edx-ben
imul ebx,edx ;elso ket resz ebx-ben


mov eax,[e]
mov ecx,[f]
sub ecx,2
imul eax,ecx 
xchg eax,ecx ;ecx-be utolso elotti

mov eax,[g]
inc eax
push ecx
mov ecx,3
cdq
idiv ecx
pop ecx
sub ecx,eax

add ebx,ecx
mov eax,ebx ;vegeredmeny
call WriteInt





ret

section .data
bea db 'A = ',0
beb db 'B = ',0
bec db 'C = ',0
bed db 'D = ',0
bee db 'E = ',0
bef db 'F = ',0
beg db 'G = ',0
kif db '((C-A^3)/B-D+4*E)*(D mod 13)+E*(F-2)-(G+1)/3 = ',0

section .bss

a resd 1
b resd 1
c resd 1
d resd 1
e resd 1
f resd 1
g resd 1