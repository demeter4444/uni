%include 'mio.inc'
%include 'strings.inc'
%include 'iostr.inc'
%include 'ionum.inc'

global main

section .text
main:

mov esi,bea
call WriteStr
call ReadHex
mov [a],eax
call NewLine

mov esi,beb
call WriteStr
call ReadHex
mov [b],eax
call NewLine

mov eax,[a]
mov esi,bea
call WriteStr
call WriteBin
call NewLine

mov eax,[b]
mov esi,beb
call WriteStr
call WriteBin
call NewLine

mov eax,[a]
shl eax,16
shr eax,16
mov ebx,[b]
shr ebx,16
xor ecx,ecx
xor edx,edx
xor esi,esi
mov edi,8

mov ecx,eax
mov edx,ebx


.ciklus:
mov ecx,eax
mov edx,ebx
and ecx,00000000000000000000000000000011b
and edx,00000000000000000000000000000011b
shl edx,2
add ecx,edx
add esi,ecx

mov ecx,eax
mov edx,ebx
and ecx,00000000000000000000000000001100b
and edx,00000000000000000000000000001100b
shl ecx,2
shl edx,4
add ecx,edx
add esi,ecx

mov ecx,eax
mov edx,ebx
and ecx,00000000000000000000000000110000b
and edx,00000000000000000000000000110000b
shl ecx,4
shl edx,6
add ecx,edx
add esi,ecx

mov ecx,eax
mov edx,ebx
and ecx,00000000000000000000000011000000b
and edx,00000000000000000000000011000000b
shl ecx,6
shl edx,8
add ecx,edx
add esi,ecx

mov ecx,eax
mov edx,ebx
and ecx,00000000000000000000001100000000b
and edx,00000000000000000000001100000000b
shl ecx,8
shl edx,10
add ecx,edx
add esi,ecx

mov ecx,eax
mov edx,ebx
and ecx,00000000000000000000110000000000b
and edx,00000000000000000000110000000000b
shl ecx,10
shl edx,12
add ecx,edx
add esi,ecx

mov ecx,eax
mov edx,ebx
and ecx,00000000000000000011000000000000b
and edx,00000000000000000011000000000000b
shl ecx,12
shl edx,14
add ecx,edx
add esi,ecx

mov ecx,eax
mov edx,ebx
and ecx,00000000000000001100000000000000b
and edx,00000000000000001100000000000000b
shl ecx,14
shl edx,16
add ecx,edx
add esi,ecx



;jne .ciklus

mov eax,esi
call NewLine
call WriteBin


ret

section .data

bea db 'A = ',0
beb db 'B = ',0

section .bss

a resd 1
b resd 1