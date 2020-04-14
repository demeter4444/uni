%include 'mio.inc'
%include 'STRINGS.inc'
%include 'IONUM.inc'
%include 'IOSTR.inc'

global main

section .text
main:
mov esi,ben
call WriteStr
call ReadInt
mov [n],eax
call NewLine

xor esi,esi
mov ecx,[n]
imul ecx,ecx
movss xmm2,[null]
.beciklus:
call mio_readflt
movss [a+esi],xmm0
movss [x+esi],xmm2
movss [y+esi],xmm2
add esi,4
loop .beciklus

xor esi,esi
xor edi,edi
mov ecx,[n]
imul ecx,ecx
mov edi,[n]
mov edx,[n]
imul edx,4
imul edi,4
neg edx

movss xmm1,[kilenc]
.mainciklus:

xorps xmm0,xmm0
addss xmm0,[a+esi+edx-4]
addss xmm0,[a+esi+edx]
addss xmm0,[a+esi+edx+4]
addss xmm0,[a+esi-4]
addss xmm0,[a+esi+4]
addss xmm0,[a+esi+edi-4]
addss xmm0,[a+esi+edi]
addss xmm0,[a+esi+edi+4]
addss xmm0,[a+esi]
divss xmm0,xmm1

movss [b+esi],xmm0
add esi,4

loop .mainciklus

xor esi,esi
mov ecx,[n]
imul ecx,ecx

mov esi,matrix
call WriteLnStr

.kiirciklus:
movss xmm0,[b+esi]
call mio_writeflt
call NewLine
add esi,4
loop .kiirciklus

ret

section .data
ben db 'n = ',0
egy dd 1.0
kilenc dd 9.0
null dd 0.0
matrix db 'a matrix:',0


section .bss
;a resd 289
x resd 256
a resd 256
b resd 256
y resd 256
n resd 1