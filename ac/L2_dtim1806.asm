;Demeter Tamás, dtim1806, 511/2
;Labor 2
;hexa es decimalis szamok beolvasasa, kiirasa.


%include 'mio.inc'

global main

section .text
main:

		
mov eax,str_bedec
call mio_writestr	;elso decimalis beolvasasa
call readint
jc .hiba

push eax
mov eax,str_kidec
call mio_writestr 
pop eax				;elso decimalis kiiratasa
call writeint
call mio_writeln

push eax
mov eax, str_kihex
call mio_writestr
pop eax			;elso hexa kiiratasa
call writehex
push eax
call mio_writeln

call mio_writeln
mov eax, str_behex	;masodik hexa beolvasasa
call mio_writestr
call readhex
jc .hiba

push eax
mov eax,str_kidec
call mio_writestr
pop eax				;masodik decimalis kiiratasa
call writeint
call mio_writeln

push eax
mov eax,str_kihex
call mio_writestr
pop eax				;masodik hexa kiiratasa
call writehex
call mio_writeln
	
pop ebx
add eax,ebx
	
push eax
call mio_writeln
mov eax,str_sum	
call mio_writestr
pop eax

call mio_writeln
push eax
mov eax,str_kidec	;osszeg decimalis kiiratasa
call mio_writestr
pop eax
call writeint

call mio_writeln
push eax			;osszeg hexa kiiratasa
mov eax,str_kihex
call mio_writestr
pop eax
call writehex
	
ret

.hiba:
mov eax, str_e
call mio_writestr

ret

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

readint:
push esi
push ebx
mov esi, 1   ;esi-ben nezem az elojelt

xor ebx,ebx
	
.next: ;"beolvasas" ciklus
xor eax,eax
call mio_readchar

cmp al,13
je .end

cmp al,8
je .back

cmp al,45
je .negative

cmp al,'0'
jl .error
cmp al,'9'
jg .error

call mio_writechar


imul ebx,10
sub eax, '0' ;a szam felepitese
add ebx,eax
	
jmp .next

.back: ;backspace esete

cmp ebx,0 ;minusz beirasara es kitorlesere jol reagal
je .neg2

mov eax,ebx
mov ecx,10
cdq			;backspace eseten bontja a szamot
idiv ecx
mov ebx,eax
xor eax,eax
	
.cont:
	
mov al,8
call mio_writechar
mov al,' '
call mio_writechar
mov al,8
call mio_writechar
jmp .next

.negative: ;neg ha talal '-'-t
call mio_writechar
neg esi
jmp .next

.error: ;hibas karakter eseten hibakodot ad
call mio_writechar
call mio_writeln
stc
jmp .endd

.end:  ;a vegso szamot eax-ba teszi
call mio_writeln
mov eax,ebx
imul eax,esi
xor ebx,ebx
jmp .endd

.neg2:
neg esi
jmp .cont

.endd:
pop ebx
pop esi
ret


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
readhex:
push ebx
push esi	
push ecx	
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

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
writeint: ;osztas es verem segitsegevel bontjuk a szamot
		
push eax
mov ebx,10
xor ecx, ecx

cmp eax,0
jl .negativ

.next:

cdq
idiv ebx
push edx
add ecx,1
cmp eax, 0
jne .next

.ki:
pop eax
add eax, '0'
sub ecx, 1
call mio_writechar
cmp ecx,0
jg .ki

jmp .end

.negativ:
neg eax
push eax
mov eax, '-'
call mio_writechar
pop eax
jmp .next

.end:
pop eax
ret

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

writehex: ;az aux memoriacimet verem helyeben hasznaltam, mert ekkor meg nem tudtam/ertettem a verem hasznalatat s nem merek belenyulni
push eax
mov eax,0
mov [n],eax	 ;az n memoriacimen neztem a ket esetet: ha negativ decimalis szamot ir ki hexaba, vagy nem
mov eax, '0' 
call mio_writechar
mov eax, 'x'
call mio_writechar
pop eax
mov [aux],eax
mov ebx,16
xor ecx, ecx

	cmp eax,0
	jl .negativ ;tobb "negativ" cimke van, ezek a komplementerkod felepitesehez szolgalnak

.next:

cdq
idiv ebx
push edx
add ecx,1	;osztassal, veremmel bontunk
cmp eax, 0
jne .next

	mov edx,7
	sub edx,ecx
	
	push ecx
	mov ecx,[n]
	cmp ecx,1
	pop ecx
	je .fesek
	
	.nullasok: ;kisebb szam eseten kitolti az elejet 0-val 
	cmp edx,0
	jl .ki
	push eax
	mov eax, '0'
	call mio_writechar
	pop eax
	sub edx,1
	cmp edx,0
	jge .nullasok
	
	.fesek:  ;nagyobb negativ szam eseten kitolti az elejet f-esekkel
	cmp edx,0
	jl .ki
	push eax
	mov eax, 'F'
	call mio_writechar
	pop eax
	sub edx,1
	cmp edx,0
	jge .fesek
	
.ki: 	;kiirataskor kulon eset letezik ha a maradek 0-9 kozott van, vagy 10-15 (szam,betu)
pop eax
push ebx
mov ebx,[n]
cmp ebx,1
pop ebx
je .negativ2
.negativ2cont:
cmp eax,  0
jge .szamjegy1

	.szamjegy1:
	cmp eax, 9
	jle .szamjegy
	
cmp eax, 10
jge .betu

.szamjegy:
add eax, '0'
sub ecx, 1
call mio_writechar
cmp ecx,0
jg .ki
cmp ecx,0
je .end

.betu:
add eax, 'A'
sub eax, 10
sub ecx, 1
call mio_writechar
cmp ecx,0
jg .ki
cmp ecx,0
je .end

.negativ:
neg eax
push eax
mov eax,1
mov [n],eax
pop eax
sub eax,1
jmp .next

.negativ2:
push ebx
mov ebx,eax
mov eax,15
sub eax,ebx
pop ebx

jmp .negativ2cont

.end:
mov eax,[aux] 
ret

section .data

str_e db 'Hiba : invalid character',0
str_bedec db 'Olvasson be egy decimalis szamot: ',0
str_behex db 'Olvasson be egy hexa szamot: ',0
str_kidec db 'Decimalisban: ',0
str_kihex db 'Hexaban: ',0
str_sum db 'Osszeguk: ',0

section .bss

aux resd 1
n resd 1