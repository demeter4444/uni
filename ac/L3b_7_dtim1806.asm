;Demeter Tamás, 511/2, dtim1806
;Labor 3(bit,string), B feladat, 7. sorszam
;a hexa beolvasas fuggvennyel (elozo feladat) olvassunk be 3 elojelmentes, 32 bites szamot. ezeknek a bitjeit fogjuk a kovetkezokben manipulalni
;allitsuk ossze a kovetkezo erteket (bitekbol): C[8:7] AND 10, A[7:5] AND 010, 0, B[11:11] AND A[23:23], A[26:6], B[12:9] + A[31:28]
; nasm -f win32 miodemo.asm
; nlink miodemo.obj -lmio -o miodemo.exe


%include 'mio.inc'

global main

section .text
main:
mov eax, str_behex
call mio_writestr	;be1
call readhex
jc .hiba
mov ebx, eax


mov eax,str_behex
call mio_writestr	;be2
call readhex
jc .hiba
mov ecx,eax


mov eax, str_behex
call mio_writestr
call readhex	;be3
jc .hiba
mov edx,eax

mov eax,str_ertek
call mio_writestr

call mio_writeln
mov eax,str_kibin
call mio_writestr
call mio_writeln
mov eax,ebx
call kibin
call mio_writeln
mov eax,ecx
call kibin
call mio_writeln
mov eax,edx
call kibin
call mio_writeln


mov [mem],dword 0 ;mem-be epitjuk a vegso erteket

;megfelelo shiftekkel megkapjuk a kert reszleteket. a logikai muveleteket elvegezzuk, majd okosan eltoljuk, hogy osszeadassal tudjuk epiteni a vegeredmenyt
;C[8:7] and 10(2)
push edx
shl edx,23
shr edx,30
and edx,2
shl edx,30
add [mem],edx
pop edx

;A[7:5] and 010(2)
push ebx
shl ebx,24
shr ebx,29
and ebx,2
shl ebx,27
add [mem],ebx
pop ebx

;0 (egyel kevesebbel shiftelunk a kovetkezonel)

;B[11:11] and A[23:23]
push ecx
push ebx
shl ecx,20
shr ecx,31
shl ebx,8
shr ebx,31
and ecx,ebx
shl ecx,25
add [mem],ecx
pop ebx
pop ecx


;A[26:6]
push ebx
shl ebx,5
shr ebx,11
shl ebx,4
add [mem],ebx
pop ebx

;B[12:9] + A[31:28]
push ecx
push ebx
shl ecx,19
shr ecx,28
shl ebx,0
shr ebx,28
shl ecx,27
shl ebx,27
add ecx,ebx
shl ecx,1	;az osszeadasnal ugy toltuk el a biteket, hogy a vegen a kifutobit eltunjon
shr ecx,28
add [mem],ecx
pop ebx
pop ecx

mov eax,str_er
call mio_writestr

call mio_writeln
mov eax,[mem]
call kibin

ret

	.hiba:
	mov eax, str_e
	call mio_writestr

	ret

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
readhex:
push ecx
push ebx
push esi
mov esi, 1    ;elojel

xor ebx,ebx	
	
.next:
xor eax,eax
call mio_readchar

cmp al,13	;ha enter
je .end

cmp al,8	;ha backspace
je .back

cmp al,45	;ha minusz
je .negative

call mio_writechar
cmp al,'0'
jl .error	;ha invalid karakter vagy hexa
cmp al,'9'
jg .error

imul ebx,16
sub eax, '0'		;itt generaljuk karakterenkent ebx-be a vegso szamot
add ebx,eax
	
jmp .next

.back:

cmp ebx,0	;ha beirunk egy minuszt es kitoroljuk, nem lesz hiba
je .neg2
	
mov eax,ebx
mov ecx,16	;ha beirunk egy szamot es kitoroljuk, akkor a vegso eredmeny is tukrozi ezt
cdq
idiv ecx
mov ebx,eax
xor eax,eax
	
.cont:
	
mov al,8
call mio_writechar
mov al,' '
call mio_writechar	;backspace
mov al,8
call mio_writechar
jmp .next

.negative:
call mio_writechar	;negalas
neg esi
jmp .next

.error:
	cmp al,'A'	
	jge .telso	;ha lehet hexa karakter, itt kezdi nezni. atmegy telsobe.
	.errorr:
	cmp al,'a' ;nem nagy hexa, tehat megnezni kicsire. atmegy tmasodikba
	jge .tmasodik
	
		.errorrr:	; ha a karakter se nem a-f, se nem A-F kozott van, se nem szam, se nem minusz, akkor invalid, es megallitja a programot
		call mio_writeln
		stc
		jmp .endd

.end:
call mio_writeln
mov eax,ebx
imul eax,esi	;a vegen beallitjuk az elojelt
jmp .endd

.neg2:		;negalas
neg esi
jmp .cont

	.telso:		;ha nem nagy hexa, atmegy errorrba, ha nagy hexa akkor szamol.
	cmp al, 'F'
	jg .errorr
	
	imul ebx,16
	sub eax, 'A'
	add eax, 10
	add ebx,eax
	
	jmp .next
	
		.tmasodik:	
		cmp al,'f'	;ez a vegso cmp. ha nem kicsi hexa, atmegy errorrrba, ha kicsi hexa, akkor szamol.
		jg .errorrr
		
		imul ebx,16
		sub eax,'a'
		add eax,10
		add ebx,eax
		
		jmp .next
	
	.endd:
	pop esi
	pop ebx
	pop ecx
	ret
	
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

kibin:
push eax
push ebx
push ecx
push edx
push esi
push edi
xor ebx, ebx
xor ecx, ecx
xor edx, edx
xor esi, esi
xor edi, edi

mov ebx,eax

.binciklus:
cmp esi,4
je .space
mov edx, ebx
cmp ecx, 32
je .vege


shr edx, 31
add esi,1
jmp .szam


.szam:
	add edx, '0'
	mov eax,edx
	call mio_writechar
	shl ebx,1
	add ecx,1
	jmp .binciklus

.space:
	xor esi,esi
	xchg eax,edi
	mov eax, ' '
	call mio_writechar
	xchg eax,edi
	jmp .binciklus


.vege:
pop edi
pop esi
pop edx
pop ecx
pop ebx
pop eax
ret
	
section .data

str_e db 'Hiba : invalid character',0
str_behex db 'Olvasson be egy hexa szamot: ',0
str_kibin db 'A beolvasott ertekek binarisban(A,B,C): ',0
str_ertek db 'C[8:7] AND 10, A[7:5] AND 010, 0, B[11:11] AND A[23:23], A[26:6], B[12:9] + A[31:28]',0
str_er db 'ertek: ',0

section .bss

aux resd 1
n resd 1
mem resd 1
