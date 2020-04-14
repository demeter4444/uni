;Demeter Tamás, 511/2, dtim1806
;Labor 3 A.feladat
;irjunk alprogramot egy 32 bites, elojel nelkuli egesz szam kiiratasara binaris formaban. (mindig 32 bit, 4essevel space)
;keszitsunk peldaprogramot, ami beolvas (elozo labor fuggvenyevel) 2 pozitiv hexa szamot, majd kiirja a beolvasott szamokat binarisban, s az osszeguket

%include 'mio.inc'

global main

section .text
main:
mov eax, str_behex
call mio_writestr ;beolvas1
call readhex
jc .hiba

mov ebx, eax

mov eax,str_behex
call mio_writestr	;beolvas2
call readhex
jc .hiba

xchg eax,ebx

push eax
mov eax, str_kibin
call mio_writestr
pop eax

call mio_writeln
call kibin	;ki1

xchg eax,ebx
call mio_writeln
call kibin	;ki2

add eax,ebx
call mio_writeln
push eax
mov eax, str_sum
call mio_writestr
pop eax
call mio_writeln
call kibin	;kiosszeg

ret

	.hiba:
	mov eax, str_e
	call mio_writestr
	ret

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
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

.bincik:
cmp esi,4
je .space
mov edx, ebx
cmp ecx, 32 ;32 szamjegyet fogunk kiirni
je .vege


shr edx, 31
add esi,1	;szamjegyenkent muvelodunk
jmp .szam


.szam:
	add edx, '0'
	mov eax,edx
	call mio_writechar ;kiiratjuk a szamjegyet
	shl ebx,1
	add ecx,1
	jmp .bincik

.space:
	xor esi,esi
	xchg eax,edi
	mov eax, ' '	;az esi-vel nezzuk hogy mikor kell spacet is tegyunk
	call mio_writechar
	xchg eax,edi
	jmp .bincik


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
str_kibin db 'binarisban a ket szam: ',0
str_sum db 'Osszeguk: ',0

section .bss

aux resd 1
n resd 1
