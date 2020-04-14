%include 'mio.inc'
%include 'STRINGS.inc'
%include 'IONUM.inc'
%include 'IOSTR.inc'

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
mov ebx,[b]
mov edx,0xF0000000
mov ecx,8
xor edi,edi


.ciklus:
mov eax,[a]
mov ebx,[b]
and eax,edx
and ebx,edx
sub eax,ebx
and eax,edx
add edi,eax
shr edx,4

loop .ciklus

call NewLine
mov eax,[a]
mov esi,bea
call WriteLnStr
call WriteBin
call NewLine

mov eax,[b]
mov esi,beb
call WriteLnStr
call WriteBin
call NewLine

mov eax,edi
mov esi,erh
call WriteLnStr
call WriteHex
call NewLine

mov eax,edi
mov esi,erb
call WriteLnStr
call WriteBin
call NewLine

ret

section .data
bea db 'A = ',0
beb db 'B = ',0
erh db 'Eredmeny hexa =',0
erb db 'Eredmeny binaris =',0



section .bss
a resd 1
b resd 1
a1 resd 1
a2 resd 1
a3 resd 1
a4 resd 1
a5 resd 1
a6 resd 1
a7 resd 1
a8 resd 1
b1 resd 1
b2 resd 1
b3 resd 1
b4 resd 1
b5 resd 1
b6 resd 1
b7 resd 1
b8 resd 1