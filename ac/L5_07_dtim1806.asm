;Demeter Tamás, dtim1806, 511/2
;5. Labor 7. sorszam (sse1)
;irjunk fuggvenyeket float szamok irasara, olvasasara (hagyomanyosan, exponencialisan, 4 ill. 6 tizedes pontossaggal)
;a fuggvenyeket felhasznalva olvassunk be 4 szamot: a,b,c,d - a,c hagyomanyos, b,d exponencialis formaban
;ertekeljuk ki a kovetkezo kifejezest, az eredmenyt irjuk ki mindket formaban
;E(a,b,c,d) = (a^2 - b + c) / d + (a - b^3 + d) / c - 2.7

%include 'mio.inc'

global main

section .text
main:
;a beolvasasa
mov esi,bea
call WriteStr
call ReadFltH
jc .hiba
call NewLine
movss [a],xmm0

;b beolvasasa
mov esi,beb
call WriteStr
call ReadFltE
jc .hiba
call NewLine
movss [b],xmm0

;c beolvasasa
mov esi,bec
call WriteStr
call ReadFltH
jc .hiba
call NewLine
movss [c],xmm0

;d beolvasasa
mov esi,bed
call WriteStr
call ReadFltE
jc .hiba
call NewLine
movss [d],xmm0

;a muveletsor elvegzese
movss xmm0,[a]
mulss xmm0,xmm0
subss xmm0,[b]
addss xmm0,[c]
divss xmm0,[d]

movss xmm2,[b]
mulss xmm2,[b]
mulss xmm2,[b]
movss xmm1,[a]
subss xmm1,xmm2
addss xmm1,[d]
divss xmm1,[c]

addss xmm0,xmm1
subss xmm0,[kutya]

;a muvelet eredmenyenek kiiratasa
mov esi,kif
call WriteStr
call NewLine
mov esi,kih
call WriteStr
call WriteFltH
call NewLine
mov esi,kie
call WriteStr
call WriteFltE

ret

.hiba:
mov esi,hiba
call WriteStr
ret

ReadFltH:;():(XMM0) 
;beolvas xmm0-ba egy float erteket hagyomanyos modon
;elobb beolvassuk stringkent
;az egeszreszt xmm1-be epitjuk
;a tortreszt xmm0-ba epitjuk, a vegen osszeadjuk
push ecx
mov ecx, 256
mov esi,szam
call ReadStr
push esi
push ebx
push edi
mov edi, 1 ;elojel alapbol +
xor ebx,ebx
xorps xmm1,xmm1
mov  bl,[esi]
cmp bl,'-'
jne .ciklus
inc esi
mov edi, -1 ;ha a string -al kezdodik akkor az elojel - lesz

.ciklus: ;fo szamfeldolgozo ciklus szorzassal, egeszresznek
	mov bl,[esi]
	inc esi
	cmp bl,0
	je .vege
	cmp bl,'.'
	je .tortresz
	sub bl, '0'
	cmp bl,9
	jg .error
	cmp bl,0
	jl .error
	
	cvtsi2ss xmm2,ebx ; a feldolgozott szamjegyeket floatta alakitjuk, es igy epitjuk tovabb
	mulss xmm1,[tiz]
	addss xmm1,xmm2
	jmp .ciklus
	
.tortresz: ;a tortresz eseteben ugyanazt vegezzuk el, mint egeszresznel, csak osztunk 10el szorzas helyett.
	xorps xmm0,xmm0
	xorps xmm7,xmm7
	movss xmm6,[h]
	.ciklust:
	mov bl,[esi]
	inc esi
	cmp bl,0
	je .vege
	sub bl, '0'
	cmp bl,9
	jg .error
	cmp bl,0
	jl .error
	cvtsi2ss xmm7,ebx
	mulss xmm7,xmm6
	addss xmm0,xmm7
	mulss xmm6,[h]
	jmp .ciklust

.error: 
pop edi
pop ebx
pop esi
pop ecx
stc
ret

.vege: 
addss xmm0,xmm1 ;vegso szam kialakitasa
cvtsi2ss xmm3,edi
mulss xmm0,xmm3 ;elojel beallitasa (szorzunk 1el vagy -1el)
pop edi
pop ebx
pop esi
pop ecx
clc
ret

WriteFltH:;():(XMM0) 
;kiirat xmm0-bol egy float erteket hagyomanyos modon
push eax
push ecx
push edi
mov ecx,6 ;a tizedes pontossag. egyszeruseg kedveert ugyanaz hagyomanyosan is, exponencialisan is.
mov edi,1

comiss xmm0,[null] ;ha a szam negativ, ezt megjegyezzuk, kiirjuk a minuszt.
jae .next
mulss xmm0,[min]
mov edi,-1
mov al,'-'
call mio_writechar

.next:
cvttss2si eax,xmm0
cvtsi2ss xmm1,eax
movss xmm2,xmm0 ;ne veszlodjon el az xmm0
call WriteInt ;az egeszreszt attettuk a cvtt-vel eax-be, es a writeintel siman kiirhatjuk.

mov al,'.' ;kiirjuk a tizedespontot
call mio_writechar
subss xmm2,xmm1
comiss xmm2,[null] ;ha a tortresz 0 akkor vege
je .vegeegesz
.ciklus:
	;a ciklus elott megkaptuk a tortreszt ugy, hogy kivontuk a teljes szambol az egeszreszt. ezt kovetoen ezt szorozgatjuk 10el es irjuk kifele a szamjegyeket.
	comiss xmm2,[null]
	je .vege
	cmp ecx,0
	je .vege
	dec ecx
	mulss xmm2,[tiz]
	cvttss2si eax,xmm2
	cvtsi2ss xmm3,eax
	subss xmm2,xmm3
	add eax,'0'
	call mio_writechar
	jmp .ciklus

.vegeegesz: ;kiteszunk egy .0-at a vegere ha nem olvastunk be tortreszt a szamnak, vagy ha egyszeruen annyi.
mov al,'0'
call mio_writechar

.vege:
cmp edi,-1
jne .vegevege
mulss xmm0,[min] ;ha az elojel - volt, akkor ezt visszaallitjuk
.vegevege:
pop edi
pop ecx
pop eax
ret

ReadFltE:;():(XMM0) 
;beolvas xmm0-ba egy float erteket exponencialis formaban
;elobb beolvassuk stringkent
;az egeszreszt xmm1-be epitjuk
;a tortreszt xmm0-ba epitjuk, a vegen osszeadjuk es exponaljuk
push ecx
mov ecx, 256
mov esi,szam
call ReadStr
push esi
push ebx
push edi
push eax
push edx
mov edi, 1 ;elojel alapbol +
xor ebx,ebx
xor edx,edx
xorps xmm0,xmm0
xorps xmm1,xmm1
mov  bl,[esi]
cmp bl,'-'
jne .ciklus
inc esi
mov edi, -1 ;ha a string -al kezdodik akkor az elojel - lesz
mov eax,1

.ciklus: ;fo szamfeldolgozo ciklus szorzassal egeszresznek. ugyanaz mint hagyomanyosnal.
	mov bl,[esi]
	inc esi
	cmp bl,0
	je .vege
	cmp bl,'.'
	je .tortresz
	cmp bl,'E'
	je .exponens
	cmp bl,'e'
	je .exponens
	sub bl, '0'
	cmp bl,9
	jg .error
	cmp bl,0
	jl .error
	
	cvtsi2ss xmm2,ebx
	mulss xmm1,[tiz]
	addss xmm1,xmm2 
	jmp .ciklus
	
.tortresz: 
	xorps xmm0,xmm0
	xorps xmm7,xmm7
	movss xmm6,[h]
	.ciklust: ;szamfeldolgozo ciklus tortresznek. ugyanaz mint hagyomanyosnal.
	mov bl,[esi]
	inc esi
	cmp bl,0
	je .vege
	cmp bl,'E'
	je .exponens
	cmp bl,'e'
	je .exponens
	sub bl, '0'
	cmp bl,9
	jg .error
	cmp bl,0
	jl .error
	cvtsi2ss xmm7,ebx
	mulss xmm7,xmm6
	addss xmm0,xmm7
	mulss xmm6,[h]
	jmp .ciklust
	
.exponens: ;exponenset feldolgozo ciklus. az E utani szamot edx-be menti el.
	mov bl,[esi]
	cmp bl, '-'
	jne .cikluse
	mov eax,-1
	inc esi
	.cikluse:
	mov bl,[esi]
	inc esi
	cmp bl,0
	je .vege
	sub bl, '0'
	cmp bl,9
	jg .error
	cmp bl,0
	jl .error
	
	imul edx,10
	add edx,ebx
	jmp .cikluse
	
.error:
pop edx
pop eax
pop edi
pop ebx
pop esi
pop ecx
stc
ret

.vege:
addss xmm0,xmm1 ;a tortreszt es egeszreszt osszeadjuk
mov ecx,edx
cmp ecx,0
je .ide ;ez az ugras akkor tortenik meg, ha az E utan 0 van(nem kell exponalni)
cmp eax,-1
jne .exponal ;ha az exponens negativ, akkor osztunk, kulonben szorzunk.

	.exponalminusz:
	divss xmm0,[tiz]
	loop .exponalminusz
	jmp .ide
	
	.exponal:
	mulss xmm0,[tiz]
	loop .exponal
	
.ide: ;ez a cimke az exponalas befejezesere szolgal.
cvtsi2ss xmm3,edi
mulss xmm0,xmm3 ;az elojelt beallitjuk (ha - volt, szorzunk -1el)

pop edx
pop eax
pop edi
pop ebx
pop esi
pop ecx
clc
ret

WriteFltE:;(XMM0):() 
;kiirat xmm0-bol egy float erteket exponencialis alakba
push eax
push edx
push ecx
push edi
push esi
xor edx,edx
movss xmm1,xmm0 ;xmm0-at attesszuk, hogy ne veszlodjon el. (nemtudom hogy kell ezeket pusholni/popolni)
comiss xmm1,[null]
jae .next ;ha a szam negativ, ezt megjegyezzuk, kiirjuk a minuszt
mulss xmm1,[min]
mov edi,-1
mov al,'-'
call mio_writechar


.next:
;a szamot osszehasonlitjuk 1el es 10el. ha kisebb mint 1, akkor kicsi, ha nagyobb vagy egyenlo 10el akkor nagy. ha jo, akkor bemegy a "nagy" agba, de furgen ki is lep.
comiss xmm1,[egy]
jb .kicsi
comiss xmm1,[tiz]
jae .nagy

 .nagy: ;ha a szam nagy, akkor osztjuk 10el amig jo
 mov esi,1
 comiss xmm1,[tiz]
 jb .kesz
 inc edx
 divss xmm1,[tiz]
 jmp .nagy

 .kicsi: ;ha a szam kicsi, szorozzuk 10el amig jo
 mov esi,-1
 comiss xmm1,[egy]
 jae .kesz
 inc edx
 mulss xmm1,[tiz]
 jmp .kicsi
 
 .kesz: ;a szorzasok/osztasok szamat edx-be mentettuk. ez lesz az E utani szam.
 push edx ;nelkule felulirja egy misztikus ero, nem volt kedvem debugolni.
 movss xmm7,xmm0
 movss xmm0,xmm1
 call WriteFltH ;a szam elejet kiirjuk hagyomanyos modon
 movss xmm0,xmm7
 mov al,'E' ;kiirjuk az E betut
 call mio_writechar
 cmp esi,1
 je .pozexp
 mov al,'-' ;ha kicsi volt a szam kiirjuk a minuszt
 call mio_writechar
 .pozexp:
 pop edx
 mov eax,edx
 call WriteInt ;kiirjuk az exponenst
 
.vege:
cmp edi,-1 ;ha a szam negativ volt, visszaalitjuk
jne .vegevege 
mulss xmm0,[min]
.vegevege:
pop esi
pop edi
pop ecx
pop edx
pop eax
ret

;--------
;a kovetkezo fuggvenyek a modulos hazibol lettek kimasolva. ha mar megirtam oket, igenybe veszem minnel tobbet.
;--------

WriteInt: ;(EAX):()
;kiir eax-bol egy 32 bites egesz szamot
push eax
push ebx
push ecx

mov ebx,10
xor ecx, ecx

cmp eax,0
jge .next ;ha negativ kiirjuk a minuszt

neg eax
push eax
mov eax, '-'
call mio_writechar
pop eax

.next: ;osztassal es veremmel dolgozunk
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

.end:
pop ecx
pop ebx
pop eax
ret

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

NewLine: ;():()  
;ujsorba lep
push eax
mov al,13
call mio_writechar
mov al,10
call mio_writechar
pop eax
ret

section .data
null dd 0.0
tiz dd 10.0
h dd 0.1
min dd -1.0
egy dd 1.0
kutya dd 2.7 ;kreativ kerativ
hiba db 'Hiba:Invalid karakter.',0
bea db '(hagyomanyos) A = ',0 
beb db '(exponencialis) B = ',0
bec db '(hagyomanyos) C = ',0
bed db '(exponencialis) D = ',0
kih db 'Hagyomanyosan: ',0
kie db 'Exponencialisan: ',0
kif db 'A kiertekelendo kifejezes: (a^2 - b + c) / d + (a - b^3 + d) / c - 2.7 = ',0

section .bss
szam resb 256
a resd 1
b resd 1
c resd 1
d resd 1