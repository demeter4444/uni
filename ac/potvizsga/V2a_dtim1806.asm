%include 'mio.inc'
%include 'STRINGS.inc'
%include 'IONUM.inc'
%include 'IOSTR.inc'

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

mov eax,[c]
mov ebx,[a]
mov ecx,[a]
imul ebx,ebx
imul ebx,ecx
sub eax,ebx

mov ebx,[b]

cdq
idiv ebx

mov ecx,[d]
mov edx,[e]
sub eax,ecx
imul edx,4
add eax,edx



push eax
mov eax,[d]
mov ebx,13
cdq
idiv ebx

pop eax
imul eax,edx

mov ebx,[e]
mov ecx,[f]
sub ecx,2
imul ebx,ecx
add eax,ebx

push eax
mov eax,[g]
add eax,1
mov ebx,3
cdq
idiv ebx
pop ebx
sub ebx,eax

xchg eax,ebx
mov esi,er
call WriteStr
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
er db 'Eredmeny = ',0

section .bss
a resd 1
b resd 1
c resd 1
d resd 1
e resd 1
f resd 1
g resd 1

