;Demeter Tamás, 511/2, dtim1806
;Labor 3(bit,string), C feladat, 7. sorszam, cstring
;irjunk alprogramot stringek beolvasasara es kiiratasara. olvassunk be 2 stringet, irassuk ki a szabalyt, a 2beolvasott stringet kulon sorokba, majd az eloallitott erteket. ebbe a programba c-sen.
;."abcde" + [A-ból azok a karakterek, amelyek "" jelek között vannak (minden második " jel után az a szakasz befejeződik és egy újabb " kell ahhoz, hogy újabb szakasz nyíljon, valamint be is kell fejeződjön "-al, hogy érvényes legyen)] + "edcba" + [B, minden kisbetűt a rákövetkező betűvel helyettesítjük (kivéve a z-t, az marad)]


%include 'mio.inc'

global main

section .text
main:

mov eax,string1 ;inicializaljuk a ket konstant stringunket (az osszefuzo alprogramom nem szereti ha az elso parameteret a .data-ban inicializalom,s itt ezzel kezdodik a vegeredmeny)
mov [eax], byte 'a'
inc eax
mov [eax], byte 'b'
inc eax
mov [eax], byte 'c'
inc eax
mov [eax], byte 'd'
inc eax
mov [eax], byte 'e'
inc eax
mov [eax], byte 0


mov eax,string2
mov [eax], byte 'e'
inc eax
mov [eax], byte 'd'
inc eax
mov [eax], byte 'c'
inc eax
mov [eax], byte 'b'
inc eax
mov [eax], byte 'a'
inc eax
mov [eax], byte 0

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
push edi
mov edi,eax

.loop:
	call mio_readchar
	cmp al,13
	je .end
	stosb
	call mio_writechar
jmp .loop

.end:
inc edi
mov [edi], byte 0
pop edi
pop eax
ret

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
kiir: ;kiir eaxbol egy stringet
push eax
push esi
mov esi,eax

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
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
concat: ;osszefuz 1 stringet eax-bol es ebx-bol
push esi
push edi
push eax

mov esi,ebx
mov edi,eax

mov al, byte 0
.ciklus1:
	scasb ;esetleg lehet repne-vel?
	je .ki
jmp .ciklus1
	
	.ki:	;scasb-vel megkerestuk azt a poziciot ahol van a binaris 0. innen kezdjuk a fuzest
	dec edi
	
	.ciklus2:
		cmp [esi],byte 0
		je .vege
		movsb
	jmp .ciklus2
	
.vege:	
mov [edi],byte 0 ;vegere kell egy binaris 0
pop eax
pop edi
pop esi

ret

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
idezojelez:  ;eax-beli stringbol atteszi stringidez-be csak az idezojelek kozotti karaktereket
push edx
push eax
push esi
push edi
xor edx,edx
mov [eleje],dword -1  ;az idezojelek lehetseges pozicioit 2 memoriavaltozoban fogom tarolni. inicializaljuk -1el (nincs idezojel)
mov [vege],dword -1
mov esi,eax
mov edi,stringidez

push esi
.szamol:
	lodsb
	cmp al,0
	je .szamolvege
	cmp al,'"'
	jne .szamol	; megszamoljuk hogy van-e legalabb 2 idezojel. ha nincs automatikusan abbahagyjuk.
	inc edx
	jmp .szamol
		.szamolvege:
		pop esi
		cmp edx,2
	jl .vege


.loop:
cmp [eleje],byte -1
	je .tovabb
	cmp [vege], byte -1	;a loop elejen megnezzuk, ha van e erteke mindket indexnek. ha igen, akkor hozzatesszuk eddigi eredmenyunkhoz  a reszletet. a .kiirreszlet cimkenel
	je .tovabb			;ha valamely index ures (-1) folytatjuk a loopot
	jmp .kiirreszlet
	
.tovabb:
	lodsb
	cmp al,0 ;csak a megalasi feltetel kulonbozik pascal es c kozott (c az egyszerubb)
	je .vege
	cmp al,'"' ;ha idezojelet toltunk be, megnezzuk hogy melyik indexre kell tegyuk (eleje v vege)
	jne .loop

	cmp [eleje], byte -1
	jne .masodik
	mov [eleje],esi ;itt az esi mar lepett 1-et az idezojel utanra, es ez nekunk jo, mert attol a karaktertol kezdve akarunk masolni
	jmp .loop
	
		.masodik:
		dec esi
		dec esi
		mov [vege],esi ;itt az esi szinten atlepte az idezojelt, s az a karakter ameddig akarunk masolni, 2vel hatrebb van
		inc esi
		inc esi
		jmp .loop

		
.kiirreszlet: ;elozoleg itt volt a pascalos feltetel, a cimke elott. osszehasonlitva a 2 programba csak ezt a reszt lathato, hogy ezt sokkal egyszerubb c stringekkel megvalositani.
; megj: itt nem letezik az a szelsoseges eset,hogy az " az utolso pozicion van, mert ott mindig binaris 0 lesz.
push ecx
push esi
mov esi,[eleje]
mov ecx,[vege]
sub ecx,esi
inc ecx
rep movsb	;kivesszuk a kezdopoziciot, a vegpozicio segitsegevel meghatarozzuk hanyat kell masoljunk a kezdopoziciotol, s atmasolunk
mov [eleje],byte-1 ;egy reszlet atmasolasa utan az indexeket ujrainicializaljuk
mov [vege],byte-1
pop esi
pop ecx

jmp .loop
	




.vege:
inc edi
mov [edi],byte 0 ;vegere binaris0
pop edi
pop esi
pop eax
pop edx
ret
;;;;;;;;;;;;;;;;;;;;;;;;;;;
cserel: ;alprogram amely eax-beli stringbol atmasol minden kisbetu karakter rakovetkezojet (kiveve z) stringcserel-be
push eax
push esi
push edi
mov esi,eax
mov edi,stringcserel

.loop:
lodsb
cmp al, byte 0
je .vege

cmp al,'a'
jl .attesz
cmp al,'y'
jg .attesz
inc al		;ugyanaz az elv, mint a pascalosba. 
.attesz:
mov [edi],al
inc edi
jmp .loop

.vege:
mov [edi], byte 0
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