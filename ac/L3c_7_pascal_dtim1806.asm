;Demeter Tamás, 511/2, dtim1806
;Labor 3(bit,string), C feladat, 7. sorszam, pascalstring
;irjunk alprogramot stringek beolvasasara es kiiratasara. olvassunk be 2 stringet, irassuk ki a szabalyt, a 2beolvasott stringet kulon sorokba, majd az eloallitott erteket. ebbe a programba pascalosan.
;."abcde" + [A-ból azok a karakterek, amelyek "" jelek között vannak (minden második " jel után az a szakasz befejeződik és egy újabb " kell ahhoz, hogy újabb szakasz nyíljon, valamint be is kell fejeződjön "-al, hogy érvényes legyen)] + "edcba" + [B, minden kisbetűt a rákövetkező betűvel helyettesítjük (kivéve a z-t, az marad)]


%include 'mio.inc'

global main

section .text
main:


mov eax,string1 ;inicializaljuk a ket konstant stringunket (az osszefuzo alprogramom nem szereti ha az elso parameteret a .data-ban inicializalom,s itt ezzel kezdodik a vegeredmeny)
mov [eax], byte 5
inc eax
mov [eax], byte 'a'
inc eax
mov [eax], byte 'b'
inc eax
mov [eax], byte 'c'
inc eax
mov [eax], byte 'd'
inc eax
mov [eax], byte 'e'

mov eax,string2
mov [eax], byte 5
inc eax
mov [eax], byte 'e'
inc eax
mov [eax], byte 'd'
inc eax
mov [eax], byte 'c'
inc eax
mov [eax], byte 'b'
inc eax
mov [eax], byte 'a'

mov eax,str_be
call mio_writestr

mov eax,stringa
call readstr
call mio_writeln	;be1
mov ebx,eax

mov eax,str_be
call mio_writestr

mov eax,stringb
call readstr	;be2
call mio_writeln
mov ecx,eax

call mio_writeln

mov eax,str_e
call mio_writestr
call mio_writeln
call mio_writeln 
mov eax,str_ki
call mio_writestr
call mio_writeln

mov eax,ebx
call kiir ;ki1
call mio_writeln
mov eax,ecx
call kiir ;ki2

call mio_writeln
call mio_writeln
mov eax,str_er
call mio_writestr


mov eax,ebx
mov ebx,ecx



call idezojelez
mov eax,stringidez	;eloallitjuk az elso kerest (idezojeles)


xchg eax,ebx 
call cserel
mov eax,stringcserel ;eloallitjuk a masodik kerest (rakovetkezos csere)


;sorba osszefuzzuk a kapott dolgokat. az eredmeny a string1-be lesz, mert innen kezdtuk fuzni. 
mov ebx,stringidez
mov eax,string1
call concat
mov eax,string1
mov ebx,string2
call concat
mov ebx,stringcserel
call concat
call mio_writeln
call kiir


ret

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
readstr: ;beolvas eax-ba egy stringet
push eax
push ecx
push edi
mov edi,eax
mov ecx,eax
inc edi

.loop:
	call mio_readchar
	cmp al,13
	je .end
	stosb
	call mio_writechar
jmp .loop

.end:
sub edi,ecx
dec edi
mov eax,edi
mov [ecx], al
pop edi
pop ecx
pop eax
ret

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
kiir: ;kiir eaxbol egy stringet
push eax
push ecx
push esi
mov esi,eax
movzx ecx, byte [esi]

cmp [esi],byte 0	;ne is probalkozzunk 0 hosszu stringek kiirasaval. lehet ertelmetlen, lehet elrontja a loopot, nem kockaztatok
je .vege

inc esi

.loop:
	lodsb
	call mio_writechar
loop .loop

.vege:
pop esi
pop ecx
pop eax
ret
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
concat: ;osszefuz 1 stringet eax-bol es ebx-bol. az osszefuzott string az eax-beli lesz.
push esi
push edi
push ecx
push edx

mov esi,ebx
mov edi,eax
cmp [esi],byte 0
jle .vege			; ne is probalkozzunk 0 hosszu stringek osszefuzesevel. lehet ertelmetlen, lehet elrontja a loopot, nem kockaztatok.
cmp [edi],byte 0
jle .vege

movzx ecx, byte [esi]
movzx edx, byte [edi]
push edx
add edx,ecx
movzx ecx, byte[esi]
mov [edi],dl
pop edx
inc esi
inc edi

add edi,edx

.loop:
	movsb
loop .loop

.vege:

pop edx
pop ecx
pop edi
pop esi

ret

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
idezojelez:  ;eax-beli stringbol atteszi stringidez-be csak az idezojelek kozotti karaktereket
push eax
push ecx
push esi
push edi
push edx
push ebx

xor edx,edx
mov esi,eax
mov edi,stringidez
mov ebx,edi
mov [ebx], byte 0
movzx ecx, byte [esi]
inc edi
inc esi
mov [eleje],byte -1	;az idezojelek lehetseges pozicioit 2 memoriavaltozoban fogom tarolni. inicializaljuk -1el (nincs idezojel)
mov [vege], byte -1

push esi
push ecx

.szamol:	; megszamoljuk hogy van-e legalabb 2 idezojel. ha nincs automatikusan abbahagyjuk.
	lodsb
	cmp al,'"'
	jne .szamoll
	inc edx
	.szamoll:
		loop .szamol
	pop ecx
	pop esi

cmp edx,2
jl .vegeee

.loop:

cmp [eleje],byte -1
	je .tovabb	
	cmp [vege], byte -1	;a loop elejen megnezzuk, ha van e erteke mindket indexnek. ha igen, akkor hozzatesszuk eddigi eredmenyunkhoz  a reszletet. a .kiirreszlet cimkenel
	je .tovabb		;ha valamely index ures (-1) folytatjuk a loopot
	jmp .kiirreszlet
	

.tovabb:
lodsb	
cmp al, '"'	;ha idezojelet toltunk be, megnezzuk hogy melyik indexre kell tegyuk (eleje v vege)
jne .loopol

	cmp [eleje], byte -1
	jne .masodik
	mov [eleje],esi	;itt az esi mar lepett 1-et az idezojel utanra, es ez nekunk jo, mert attol a karaktertol kezdve akarunk masolni
	jmp .loopol
	
		.masodik:
		dec esi
		dec esi
		mov [vege],esi	;itt az esi szinten atlepte az idezojelt, s az a karakter ameddig akarunk masolni, 2vel hatrebb van
		inc esi
		inc esi
		jmp .loopol
	
	


.loopol:
cmp ecx,0 ;itt van "elrejtve" az a feltetel hogy akkor is alljon meg ha a string veget ert. persze, meg megvizsgaljuk hogy van e atmasolando reszletunk. (pl. ha az utolso karakter " volt)
je .kiirreszlet
loop .loop

.kiirreszlet:
	cmp [eleje],byte-1
	je .vege
	cmp [vege],byte -1	;ha megsincs atmasolando ertek, vege. kulonben kivesszuk a kezdopoziciot, a vegpozicio segitsegevel meghatarozzuk hanyat kell masoljunk a kezdopoziciotol, s atmasolunk
	je .vege
	push ecx
	push esi
	mov esi,[eleje]
	mov ecx,[vege]
	sub ecx,[eleje]
	inc ecx
	add [ebx],cl
	rep movsb
	mov [eleje],byte-1 ;egy reszlet atmasolasa utan az indexeket ujrainicializaljuk
	mov [vege],byte-1
	pop esi
	pop ecx
jmp .loop


.vegeee:
mov [ebx],byte 0 ;ha nem masoltunk semmit (nincs legalabb 2 idezojel, akkor a stringunk 0 hossz lesz(kiir,concat nem fog meghalni)

.vege:
.tenylegvege: ;ezzel a feladattal szerencsetlenkedtem jo sokat, es itt tenyleg vege lett :)
pop ebx
pop edx
pop edi
pop esi
pop ecx
pop eax
ret

;;;;;;;;;;;;;;;;;;;;;;;;;;;
cserel: ;alprogram amely eax-beli stringbol atmasol minden kisbetu karakter rakovetkezojet (kiveve z) stringcserel-be
push eax
push esi
push edi
push ecx
mov esi,eax
mov edi,stringcserel
movzx ecx, byte [esi]
mov [edi], ecx
inc esi
inc edi

.loop:
lodsb
cmp al,'a'
jl .attesz
cmp al,'y'
jg .attesz
inc al ;ha a-y kozott van akkor noveljuk es utana tesszuk at, kulonben siman attesszuk
.attesz:
mov [edi],al
inc edi
loop .loop

.vege:
pop ecx
pop edi
pop esi
pop eax
ret


section .data
str_be db 'Olvasson be egy stringet: ',0
str_ki db 'A stringek:',0
str_e db '"abcde" + [A-bol azok a karakterek, amelyek "" jelek kozott vannak (minden masodik " jel utan az a szakasz befejezodik es egy ujabb " kell ahhoz, hogy ujabb szakasz nyiljon, valamint be is kell fejezodjon "-al, hogy ervenyes legyen)] + "edcba" + [B, minden kisbetut a rakovetkezo betuvel helyettesitjuk (kiveve a z-t, az marad)]',0
str_er db 'Az eredmeny: ',0

section .bss
string1 resb 256
string2 resb 256
stringa resb 256
stringb resb 256
stringidez resb 256
stringcserel resb 256
eleje resd 1
vege resd 1