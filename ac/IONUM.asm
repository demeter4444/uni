;Demeter Tamás
;dtim1806
;511/2
;Szamokat beolvaso/kiirato modul
;32 bit + 64 bit, decimalis,binaris,hexadecimalis 

%include 'mio.inc'
%include 'io.inc'
%include 'IOSTR.inc'

global ReadInt, ReadBin, ReadHex, ReadInt64, ReadBin64, ReadHex64, WriteInt, WriteBin, WriteHex, WriteInt64, WriteBin64, WriteHex64

section .text


ReadInt: ;():(EAX) 
;beolvas eax-ba egy 32 bites egesz szamot
;elobb feldolgozzuk string-kent a szamot.
push ecx
push esi
push ebx
push edi
mov ecx,256
mov esi,szam
call ReadStr
mov edi, 1 ;elojel alapbol +
xor eax,eax
xor ebx,ebx

mov  bl,[esi]
cmp bl,'-'
jne .ciklus
inc esi
mov edi, -1 ;ha a string -al kezdodik akkor az elojel - lesz

.ciklus: ;fo szamfeldolgozo ciklus szorzassal
	mov bl,[esi]
	inc esi
	cmp bl,0
	je .vege

	sub bl, '0'
	cmp bl,9
	jg .error
	cmp bl,0
	jl .error

	imul eax,10
	jo .error
	add eax,ebx
	jo .error
	jmp .ciklus

.error:
pop edi
pop ebx
pop esi
pop ecx
stc
ret

.vege:
imul eax,edi ;elojel beallitasa
pop edi
pop ebx
pop esi
pop ecx
clc
ret

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

ReadBin:;():(EAX) 
;beolvas eax-ba egy 32bites pozitiv binaris egeszt
;elobb feldolgozzuk string-kent
push ecx
push esi
push ebx

mov ecx,256
mov esi,szam
call ReadStr
xor eax,eax
xor ebx,ebx

.ciklus:
	mov bl, [esi]
	inc esi
	cmp bl,0
	je .vege

	sub bl,'0'
	cmp bl,0
	jl .error
	cmp bl,1
	jg .error

;ez az algoritmus magja. lepesenkent forgatjuk eax-ba a feldolgozott szamjegyeket carry-vel. ha a carry barmely pontban 1 lesz, tulcsordultunk.
	clc
	rcl eax, 1
	jc .error
	add eax,ebx
	jmp .ciklus

.error:
pop ebx
pop esi
pop ecx
stc
ret
.vege:
pop ebx
pop esi
pop ecx
clc
ret

WriteBin:;(EAX):() 
;32 bites pozitiv egesz binaris szam kiiratasa eax-bol
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
	
ReadHex:;():(EAX) 
;beolvas eax-ba egy 32bites pozitiv hexat
;elobb feldolgozzuk stringkent a szamot
push ecx
push esi
push ebx

mov ecx,256
mov esi,szam
call ReadStr
xor eax,eax
xor ebx,ebx

.ciklus:
mov bl, [esi]
inc esi
cmp bl,0
je .vege

cmp bl,'0'
jl .error
cmp bl,'9'
jle .szam
cmp bl,'A'
jl .error
cmp bl,'F'
jle .nagybetu
cmp bl,'a'
jl .error
cmp bl,'f'
jle .kisbetu
jg .error

	.szam:
	sub bl,'0'
	jmp .next

	.nagybetu:
	sub bl,'A'
	add bl,10
	jmp .next

	.kisbetu:
	sub bl,'a'
	add bl,10

		.next:
;ugyanazt az algoritmust alkalmazzuk, mint a binaris beolvasasnal, csak most 4essevel forgatunk, es minden lepesbe ellenorizzuk a carry-t
		clc
		rcl eax, 1
		jc .error
		rcl eax, 1
		jc .error
		rcl eax, 1
		jc .error
		rcl eax, 1
		jc .error

		add eax,ebx
	jmp .ciklus

.error:
pop ebx
pop esi
pop ecx
stc
ret

.vege:
pop ebx
pop esi
pop ecx
clc
ret

WriteHex:;(EAX):() 
;kiir eax-bol egy 32 bites pozitiv hexat
push eax
push ebx
push ecx
push edx

xor edx, edx
xor ecx, ecx
mov ebx,eax

.hexaciklus:
mov edx, ebx
cmp ecx, 8 ;8 szamjegyet fogunk kiiratni
je .vege

shr edx, 28
cmp edx, 9 ;kulon kiiratasi procedura szamra es beture
jle .szam
jg .betu


	.szam:
	add edx, '0'
	mov eax,edx
	call mio_writechar
	shl ebx,4
	add ecx,1
	jmp .hexaciklus

	.betu:
	add edx, 'A'
	sub edx, 10
	mov eax, edx
	call mio_writechar
	shl ebx,4
	add ecx,1
	jmp .hexaciklus

.vege:
pop edx
pop ecx
pop ebx
pop eax
ret

ReadInt64:;():(EDX:EAX)
;64 bites előjeles egész beolvasása
;elobb feldolgozzuk stringkent a szamot

push edi
push ebx
push esi
push ecx

mov ecx,256
mov esi,szam
call ReadStr

mov edi,10
xor eax,eax
xor edx,edx
xor ebx,ebx
xor ecx,ecx
mov [min],dword 1 ;a min valtozot elojel ellenorzesere hasznalom. utolag rajottem, hogy meg lehet elegansabban oldani nelkule, de mar szorit a hatarido.

mov  bl,[esi]
cmp bl,'-'
jne .ciklus
inc esi
mov [min], dword -1

.ciklus:

	mov bl,[esi] ;lodsb csak ebx-be, mert kell az eax
	test ebx,ebx
	jz .vege
	inc esi
	sub bl,'0' 
	cmp bl,byte 9
	jg .hiba
	cmp bl,byte 0
	jl .hiba

	mov ecx,edx ;egyszerre dolgozunk edx-el es eax-al
	mul edi 
	imul ecx,edi
	jo .hiba
	add edx,ecx
	jo .hiba
	add eax,ebx
	jo .hiba
	adc edx,0
	jo .hiba
	jmp .ciklus

.hiba:
pop ecx
pop esi
pop ebx
pop edi
stc
ret

.vege:
;elojel beallitasa
cmp [min], dword -1 
jne .ide
cmp edx,0
je .idee
not edx 
.idee:
not eax
add eax,1
.ide:
pop ecx
pop esi
pop ebx
pop edi
clc
ret

WriteInt64: ;(EDX:EAX):()
;64 bites előjeles egész kiírása
;ugyanazt az algoritmust hasznaljuk, mint a sima osztasnal.
;akkor er veget a bonto ciklus ha MINDKET regiszter 0

push eax
push edx
push edi
push ecx
push esi

cmp edx,0
jne .folytasd
call WriteInt ;ha elfer 32 biten a szam, eleg a 32 bites kiiras
jmp .vege

.folytasd:
xor esi,esi
mov edi,10 

cmp edx,0
jge .ciklus
not eax		;ha a szam negativ, ennek megfeleloen iratjuk ki. (komplementer)
not edx
add eax,1


push eax
mov eax, '-'
call mio_writechar ;minusz kiirasa negativ szam eseten
pop eax


.ciklus:
	mov ecx,eax ;elmentjuk az also 32 bitet, mert eloszor a felsovel dolgozunk
	mov eax,edx
	xor edx,edx 
	div edi
	mov ebx,eax ;el kell mentsuk a hanyadost
	mov eax,ecx
	div edi
	push edx ;a verembe tesszuk a szamjegyeket
	inc esi
	mov edx,ebx

	test edx,edx
	jnz .ciklus
	test eax,eax
	jnz .ciklus

.ciklus2: ;az elmentett szamjegyeket kiiratjuk
	pop eax
	dec esi
	add al,'0'
	call mio_writechar
	cmp esi,0
	jne .ciklus2


.vege: 
pop esi
pop ecx
pop edi
pop edx
pop eax
ret

ReadBin64:;():EDX:(EAX) 
;beolvas edx:eax-ba egy 64bites pozitiv binaris egeszt
;elobb feldolgozzuk stringkent a szamot
push ecx
push esi
push ebx

mov ecx,256
mov esi,szam
call ReadStr
xor eax,eax
xor ebx,ebx
xor edx,edx

.ciklus:
	mov bl, [esi]
	inc esi
	cmp bl,0
	je .vege

	sub bl,'0'
	cmp bl,0
	jl .error
	cmp bl,1
	jg .error

	;a 32 bites algoritmust kibovitettuk 64 bitre, ugy hogy a stringbol eax-ba forgatunk, eaxbol pedig edx-be. akkor lep fel tulcsordulas ha az edx forgatasa utan a carry 1.
	clc
	rcl edx,1
	jc .error
	rcl eax, 1
	adc edx,0
	add eax,ebx
	jmp .ciklus

.error:
pop ebx
pop esi
pop ecx
stc
ret

.vege:
 ;elojel beallitasa
cmp edx,0
jge .ide
mov [min],dword -1
jmp .idee
.ide:
mov [min],dword 1
.idee:
pop ebx
pop esi
pop ecx
clc
ret

WriteBin64:;(EDX:EAX):()
;64 bites binaris egesz kiiratasa edx:eax-bol
push edx
push eax
push eax
mov eax,edx
cmp eax,0
je .ide
call WriteBin ;ha elfer 32 biten
.ide: ;kulonben
pop eax
call WriteBin
pop eax
pop edx
ret

ReadHex64:;():(EDX:EAX) 
;beolvas edx:eax-ba egy 32bites pozitiv hexat
;elobb feldolgozzuk stringkent a szamot
push ecx
push esi
push ebx

mov ecx,256
mov esi,szam
call ReadStr
xor eax,eax
xor ebx,ebx
xor edx,edx

.ciklus:
mov bl, [esi]
inc esi
cmp bl,0
je .vege

;okos sorrendben felirt validalasa procedura
cmp bl,'0'
jl .error
cmp bl,'9'
jle .szam
cmp bl,'A'
jl .error
cmp bl,'F'
jle .nagybetu
cmp bl,'a'
jl .error
cmp bl,'f'
jle .kisbetu
jg .error

.szam:
sub bl,'0'
jmp .next

.nagybetu:
sub bl,'A'
add bl,10
jmp .next

.kisbetu:
sub bl,'a'
add bl,10


.next:
;kibovitettuk a 32bites algoritmust 64 bitre, akarcsak a binaris beolvasas eseten
;igen, ez lenyegeben a binaris beolvasas 4szer copy-pastelve
;stringbol forgatunk eax-ba, eax-bol edx-be, 4essevel. minden lepesben ellenorizzuk ha edx-bol van e kifutobit. ha van, tulcsordult.
clc
rcl edx,1
jc .error
rcl eax, 1
adc edx,0

clc
rcl edx,1
jc .error
rcl eax, 1
adc edx,0

clc
rcl edx,1
jc .error
rcl eax, 1
adc edx,0

clc
rcl edx,1
jc .error
rcl eax, 1
adc edx,0

add eax,ebx
jmp .ciklus

.error:
pop ebx
pop esi
pop ecx
stc
ret
.vege:
;elojel beallitasa
cmp edx,0
jge .ide
mov [min],dword -1
jmp .idee
.ide:
mov [min],dword 1
.idee:
pop ebx
pop esi
pop ecx
clc
ret

WriteHex64:;(EDX:EAX):()
;64 bites hexa egesz kiiratasa edx:eax-bol
push edx
push eax
push eax
mov eax,edx
cmp eax,0
je .ide
call WriteHex ;ha elfer 32 biten ...
.ide:
;ha nem...
pop eax
call WriteHex
pop eax
pop edx
ret

section .data

section .bss
szam resb 256
min resd 1 ;a min valtozot elojel ellenorzesere hasznalom. utolag rajottem, hogy meg lehet elegansabban oldani nelkule, de mar szorit a hatarido.