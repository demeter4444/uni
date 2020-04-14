;Demeter Tamás
;dtim1806
;511/2

;IONUM modult tesztelo program.
;Olvassunk be 1-1 decimalis,hexa,binaris szamot
;irassuk ki oket mindharom szamrendszerben
;az osszeguket szinten
;ezt 32, illetve 64 biten.
%include 'IOSTR.inc'
%include 'STRINGS.inc'
%include 'IONUM.inc'
%include 'mio.inc'

global main

section .text

main:
.dec:
;32 bites decimalis beolvasasa
push esi
mov esi, ri
call WriteStr
pop esi
call ReadInt
jc .hibai
mov ebx,eax
call NewLine

;kiirasa decimalisban
push esi
mov esi, wi
call WriteStr
pop esi
call WriteInt
call NewLine

;kiirasa hexaban
push esi
mov esi, wh
call WriteStr
pop esi
call WriteHex
call NewLine

;kiirasa binarisban
push esi
mov esi, wb
call WriteStr
pop esi
call WriteBin
call NewLine

.hex:
;32 bites hexa beolvasasa
push esi
mov esi, rh
call WriteStr
pop esi
call ReadHex
jc .hibah
mov ecx,eax
call NewLine

;kiirasa decimalisban
push esi
mov esi, wi
call WriteStr
pop esi
call WriteInt
call NewLine

;kiirasa hexaban
push esi
mov esi, wh
call WriteStr
pop esi
call WriteHex
call NewLine

;kiirasa binarisban
push esi
mov esi, wb
call WriteStr
pop esi
call WriteBin
call NewLine

.bin:
;32 bites binaris beolvasasa
push esi
mov esi, rb
call WriteStr
pop esi
call ReadBin
jc .hibab
call NewLine

;kiirasa decimalisban
push esi
mov esi, wi
call WriteStr
pop esi
call WriteInt
call NewLine

;kiirasa hexaban
push esi
mov esi, wh
call WriteStr
pop esi
call WriteHex
call NewLine

;kiirasa binarisban
push esi
mov esi, wb
call WriteStr
pop esi
call WriteBin
call NewLine

;osszeguk
call NewLine
add eax,ebx ;ha a 3 beolvasott szam osszege tulcsordult nem ker ujra semmit. remelem nem gond
jo .hibas
add eax,ecx
jo .hibas
push esi
mov esi, sum
call WriteStr
pop esi

;kiirasa decimalisban
call NewLine
push esi
mov esi, wi
call WriteStr
pop esi
call WriteInt
call NewLine

;kiirasa hexaban
push esi
mov esi, wh
call WriteStr
pop esi
call WriteHex
call NewLine

;kiirasa binarisban
push esi
mov esi, wb
call WriteStr
pop esi
call WriteBin
call NewLine
call NewLine


.dec64:
;64 bites decimalis beolvasasa
push esi
mov esi, ri64
call WriteStr
pop esi
call ReadInt64
jc .hibai64
push edx
push eax
call NewLine

;kiirasa decimalisban
push esi
mov esi, wi
call WriteStr
pop esi
call WriteInt64
call NewLine

;kiirasa hexaban
push esi
mov esi, wh
call WriteStr
pop esi
call WriteHex64
call NewLine

;kiirasa binarisban
push esi
mov esi, wb
call WriteStr
pop esi
call WriteBin64
call NewLine

.hex64:
;64 bites hexa beolvasasa
push esi
mov esi, rh64
call WriteStr
pop esi
call ReadHex64
jc .hibah64
push edx
push eax
call NewLine

;kiirasa decimalisban
push esi
mov esi, wi
call WriteStr
pop esi
call WriteInt64
call NewLine

;kiirasa hexaban
push esi
mov esi, wh
call WriteStr
pop esi
call WriteHex64
call NewLine

;kiirasa binarisban
push esi
mov esi, wb
call WriteStr
pop esi
call WriteBin64
call NewLine

.bin64:
;64 bites binaris beolvasasa
push esi
mov esi, rb64
call WriteStr
pop esi
call ReadBin64
jc .hibab64
call NewLine

;kiirasa decimalisban
push esi
mov esi, wi
call WriteStr
pop esi
call WriteInt64
call NewLine

;kiirasa hexaban
push esi
mov esi, wh
call WriteStr
pop esi
call WriteHex64
call NewLine

;kiirasa binarisban
push esi
mov esi, wb
call WriteStr
pop esi
call WriteBin64
call NewLine

;osszeguk
;ha az osszeg tulcsordult nem kerek ujra semmit, remelem nem gond.
pop ebx
pop ecx
add eax,ebx
adc edx,0
add edx,ecx
jo .hibas
pop ebx
pop ecx
add eax,ebx
adc edx,0
add edx,ecx
jo .hibas

;kiirasa decimalisban
call NewLine
push esi
mov esi, sum
call WriteStr
pop esi
call NewLine
push esi
mov esi, wi
call WriteStr
pop esi
call WriteInt64
call NewLine

;kiirasa hexaban
push esi
mov esi, wh
call WriteStr
pop esi
call WriteHex64
call NewLine

;kiirasa binarisban
push esi
mov esi, wb
call WriteStr
pop esi
call WriteBin64
call NewLine

ret

;hibakezelesek a megfelelo ugrasokkal, hogy visszakerjen adatokat
.hibas:
mov esi,hiba
call NewLine
call WriteLnStr
ret

.hibai:
mov esi,hiba
call NewLine
call WriteLnStr
jmp .dec

.hibah:
mov esi,hiba
call NewLine
call WriteLnStr
jmp .hex

.hibab:
mov esi,hiba
call NewLine
call WriteLnStr
jmp .bin

.hibai64:
mov esi,hiba
call NewLine
call WriteLnStr
jmp .dec64

.hibah64:
mov esi,hiba
call NewLine
call WriteLnStr
jmp .hex64

.hibab64:
mov esi,hiba
call NewLine
call WriteLnStr
jmp .bin64

section .data
ri db 'Olvasson be egy decimalis szamot(32): ',0
rb db 'Olvasson be egy binaris szamot(32):',0
rh db 'Olvasson be egy hexa szamot(32):',0
ri64 db 'Olvasson be egy decimalis szamot(64): ',0
rb64 db 'Olvasson be egy binaris szamot(64):',0
rh64 db 'Olvasson be egy hexa szamot(64):',0
wi db 'Decimalisan: ',0
wb db'Binarisban: ',0
wh db 'Hexaban: 0x',0
sum db 'Osszeguk: ',0
hiba db 'Hiba: Invalid karakter vagy tulcsordulas',0

section .bss