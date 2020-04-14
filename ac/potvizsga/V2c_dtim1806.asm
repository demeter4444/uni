%include 'mio.inc'
%include 'STRINGS.inc'
%include 'IONUM.inc'
%include 'IOSTR.inc'

global main

section .text
main:
mov ecx,256
mov esi,be
call WriteLnStr
mov esi,szo
call ReadLnStr
call StrLower
mov edi,szo
call StrLen
mov [hossz],eax

mov ebx,2
.mainciklus:
xor eax,eax
mov esi,sor
call ReadLnStr
cmp [esi],byte 0
je .vege
mov edi,temp
call StrCompact
;mov esi,temp mov 
	mov esi,sor
mov edi,szo
call StrLower
dec esi

je .vege

	.sideciklus:
	inc esi
	cmp [esi],byte 0
	je .sidevege
	mov dl,[edi]
	cmp dl,[esi]
	jne .elment
	inc edi
	mov ebx,1
	
		push edi
		sub edi,szo
		cmp edi,[hossz]
		jne .nincskesz
		cmp ebx,1
		jne .nincskesz
		
		inc eax
		mov edi,szo
		mov ebx,1
		dec esi
		.nincskesz:
		pop edi
	jmp .sideciklus
	
	.elment:
	mov ebx,0
	mov edi,szo
	jmp .sideciklus
	
	.sidevege:
	call NewLine
	call WriteInt
	call NewLine
	mov ebx,2
	mov edi,szo
	jmp .mainciklus


.vege:
ret

section .data
be db 'Olvasson be egy szot, majd utana a sorokat! Minden sor utan kiirom az elofordulasait!',0

section .bss
szo resb 256
sor resb 256
temp resb 256
hossz resd 1
