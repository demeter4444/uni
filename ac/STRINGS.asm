;Demeter Tamás
;dtim 1806
;511/2
;String-fuggvenyeket tartalmazo modul.

%include 'mio.inc'

global StrLen,StrUpper,StrLower,StrCompact,StrCat
section .text
StrLen: ;(ESI):(EAX) 
;eax-ba visszateriti az esi-ben levo string hosszat
push ecx
push esi
xor ecx, ecx
.loop: ;vegigmegyunk, megszamoljuk.
	cmp [esi],byte 0
	je .end
	inc esi
	inc ecx
	jmp .loop
.end:
mov eax,ecx
pop esi
pop ecx
ret

StrUpper: ;(ESI):() 
;nagybetusse konvertalja esi-t
push esi
.loop: ;vegigmegyunk, a kisbetuket nagybetusse konvertaljuk az ascii-kodbeli kulonbseg kivonasaval
cmp [esi],byte 0
je .vege
cmp [esi],byte 'a'
jl .step
cmp [esi],byte 'z'
jg .step
sub [esi], byte 32
.step:
	inc esi
	jmp .loop
.vege:
pop esi
ret

StrLower: ;(ESI):() 
;kisbetusse konvertalja esi-t
push esi
.loop: ;strupper forditottja
cmp [esi],byte 0
je .vege
cmp [esi],byte 'A'
jl .step
cmp [esi],byte 'Z'
jg .step
add [esi], byte 32
.step:
	inc esi
	jmp .loop
.vege:
pop esi
ret

StrCompact: ;(ESI):(EDI)
;edi-be atmasolja esi-t kiveve a 32,9,10,13 karaktereket (space,tab,linefeed,carriagereturn(enter))
push esi
push edi
push eax
.ciklus:	;vegigmegyunk, atmasoljuk amit kell, amit nem nem.
lodsb
cmp al, byte 0
je .vege
cmp al,byte 32
je .ciklus
cmp al,byte 9
je .ciklus
cmp al,byte 10
je .ciklus
cmp al,byte 13
je .ciklus

mov [edi],al
inc edi
jmp .ciklus

.vege:
mov [edi],byte 0
pop eax
pop edi
pop esi
ret

StrCat: ;(EDI, ESI):()            
; osszefuzi az ESI es EDI altal jelolt stringeket (azaz az ESI altal jeloltet az EDI után másolja)
push esi
push edi
push eax

mov al, byte 0
.ciklus1: ;az elso vegere leptetjuk az edi-t
	scasb 
	je .ki
jmp .ciklus1
	
	.ki:	
	dec edi
	
	.ciklus2: ;a masodikat elkezdjuk fuzni az elso vegehez
		cmp [esi],byte 0
		je .vege
		movsb
	jmp .ciklus2
	
.vege:	
mov [edi],byte 0 
pop eax
pop edi
pop esi
ret


