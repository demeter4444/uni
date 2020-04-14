;Demeter Tamás
;dtim1806
;511/2
;Stringeket beolvaso-kiirato modul

%include 'mio.inc'

global ReadStr,ReadLnStr,WriteStr,WriteLnStr,NewLine

section .text
ReadStr: ;ReadStr(ESI , ECX max. hossz):()
;beolvas esi-be egy stringet, ecx-ben a maxhosszat kapja
push esi
push ecx
push edx
push eax
xor edx,edx

.ciklus:  ;fo feldolgozo ciklus
	call mio_readchar
	cmp al, 13
	je .vege
	cmp al, 8
	je .back
	call mio_writechar
	inc edx
	cmp edx,ecx
	jg .ciklus
	mov [esi],al
	inc esi
	jmp .ciklus
	
	.back: ;backspace esete
	cmp edx,0
	je .ciklus
	cmp edx,ecx
	jg .csaktorol
	dec esi
	
	.csaktorol: ;backspace esete tul sok karakternel
	dec edx
	call mio_writechar
	mov al,' '
	call mio_writechar
	mov al,8
	call mio_writechar
	jmp .ciklus

.vege:

mov [esi],byte 0
pop eax
pop edx
pop ecx
pop esi
ret



WriteStr: ;(ESI):()
;kiir esi-bol egy stringet
push eax
push esi

.loop:
	lodsb
	cmp al, byte 0
	je .vege
	call mio_writechar
jmp .loop

.vege:
pop esi
pop eax
ret

ReadLnStr: ;ReadStr(ESI , ECX max. hossz):()
;beolvas esi-be egy stringet, ecx-ben a maxhosszat kapja
;ujsorba lep
call ReadStr
call NewLine
ret

WriteLnStr: ;(ESI):()
;kiir esi-bol egy stringet
;ujsorba lep
call WriteStr
call NewLine
ret

NewLine: ;():()  
;ujsorba lep
push eax
mov al,13
call mio_writechar
mov al,10
call mio_writechar
pop eax
ret