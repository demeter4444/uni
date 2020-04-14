;Demeter Tamás
;dtim1806
;511/2
;Stringes modulokat bemutato peldaprogram.
;olvassunk be 2 stringet
;Mindkét stringnek kiírjuk a hosszát, kompaktált formáját, majd a kompaktált formát kis betűkre alakítva és nagy betűkre alakítva. 
;Végül hozzáfűzzük az első string nagybetűs verziójához a második string kisbetűs verzióját és kiírjuk a hosszával együtt.


%include 'IOSTR.inc'
%include 'STRINGS.inc'
%include 'IONUM.inc'
%include 'mio.inc'

global main
section .text
main:
;elso beolvasasa
mov esi,uzenet
call WriteLnStr
mov esi,string1 
call ReadLnStr

;elso hossza
push esi
mov esi,uh
call WriteLnStr
pop esi
call StrLen
call WriteInt
call NewLine

;elso kompaktalasa
push esi
mov esi,uc
call WriteLnStr
pop esi
mov edi,stringc
call StrCompact
mov esi,stringc
call WriteLnStr

;elso kisbetusitese
push esi
mov esi,ul
call WriteLnStr
pop esi
call StrLower
call WriteLnStr

;masodik beolvasasa
mov esi,uzenet
call WriteLnStr
mov esi,string2
call ReadLnStr

;masodik hossza
push esi
mov esi,uh
call WriteLnStr
pop esi
call StrLen
call WriteInt
call NewLine

;masodik kompaktalasa
push esi
mov esi,uc
call WriteLnStr
pop esi
mov edi,stringc2
call StrCompact
mov esi,stringc2
call WriteLnStr

;masodik nagybetusitese
push esi
mov esi,up
call WriteLnStr
pop esi
call StrUpper
call WriteLnStr

;elso nagybetusitese, masodik kisbetusitese, ezek osszefuzese
mov esi,string1
call StrUpper
mov edi,stringnew
call StrCompact 
mov edi,stringnew
mov esi,stringc2
call StrLower
call StrCat
push esi
mov esi,ucat
call WriteLnStr
pop esi
mov esi,stringnew
call WriteLnStr

;osszefuzott hossza
push esi
mov esi,uh
call WriteLnStr
pop esi
call StrLen
call WriteInt


ret



section .data
uzenet db 'Kerek egy stringet: ',0
uh db 'Hossza:',0
uc db 'Kompaktalva:',0
ul db 'Kisbetusitve:',0
up db 'Nagybetusitve:',0
ucat db 'Az elso nagybetusitve + a masodik kisbetusitve:',0


section .bss

string1 resb 256
string2 resb 256
stringc resb 256
stringc2 resb 256
stringnew resb 256

