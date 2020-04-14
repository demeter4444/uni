%include 'mio.inc'
%include 'strings.inc'
%include 'iostr.inc'
%include 'ionum.inc'

global main

section .text
main:
mov esi,szo
call ReadLnStr


.mainciklus:
mov esi,sor
call ReadLnStr
cmp [esi],byte 0
je .end
mov [bool],dword 1
xor edx,edx

	.subciklus:
		cmp [esi],byte ' '
		je .space
		cmp [esi],byte '	'
		je .space
		cmp [esi],byte '.'
		je .space
		cmp [esi],byte ','
		je .space
		
		mov cl, [szo+edx]
		cmp cl, [esi]
		je .ide
		mov [bool],dword 0
		.ide:
		inc esi
		
		.space:
		mov eax,dword [bool]
		call WriteInt
		
		mov [bool],dword 1
		
		xor edx,edx
		cmp [esi],byte 0
		je .mainciklus
		inc esi
		jmp .subciklus
		
		
	jmp .subciklus
	.subciklusend:


jmp .mainciklus
.end:


ret

section .data


section .bss
aktszo resb 256
szo resb 256
sor resb 256
a resd 100
bool resd 1