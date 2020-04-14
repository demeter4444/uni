;Demeter Tamás, dtim1806, 511/2
;6. labor 7. feladatsor (sse2)
;olvassuk be 2 vektor hosszat (oszthato 4el), majd az elemeket. vegezzuk el a kovetkezo muveletet sse vektorizalassal:
;E(a,b) = (b^3 - a) / (a + b) - (a - b^2 + 1) / 4


%include 'io.inc'

global main

section .text
main:
mov eax,esz
call io_writestr
call io_writeln
call io_readint
call io_writeln ;elemszam beolvasasa

push eax
cdq
mov ebx,4
idiv ebx
cmp edx,0
jne .error  ;ha nem oszthato 4el, hiba
mov eax,eek
call io_writestr
call io_writeln
pop eax

mov ecx,eax
mov ebx,eax
xor edi,edi ;elemszamot elmentjuk par helyen, edi-vel memoriat tologatunk

	.beolvas1:
	;az elso beolvasasa, loop segitsegevel
	call io_readflt
	call io_writeln
	movss [A+edi],xmm0
	add edi,4
	loop .beolvas1
	
	mov ecx,eax
	xor edi,edi
	
	.beolvas2:
	;a masodik beolvasasa, ugyancsak loop segitsegevel
	call io_readflt
	call io_writeln
	movss [B+edi],xmm0
	add edi,4
	loop .beolvas2
	
	push ebx
	mov ebx,4
	xor edi,edi
	cdq
	idiv ebx
	pop ebx
	mov ecx,eax ;elosztjuk az elemszamot 4-el, annyi lepest vegzunk el vektorizalassal.
	
	call io_writeln
	push eax
	mov eax,er
	call io_writestr
	call io_writeln
	pop eax

	.muveletloop:
		movaps xmm1,[A+edi]
		movaps xmm2,[B+edi]
		movaps xmm3,xmm1
		movaps xmm4,xmm2 ;elmentjuk tobb helyen a kiindulo erteket, ne irjuk sehol felul
		movaps xmm5,xmm2
		
		mulps xmm2,xmm2
		mulps xmm2,xmm5
		subps xmm2,xmm1   ;xmm2-be elso zarojel
		
		addps xmm1,xmm4 ; xmm1-be masodik zarojel
		
		divps xmm2,xmm1 ;xmm2-be elso tort
		
		mulps xmm4,xmm4
		subps xmm3,xmm4
		movups xmm7,[egy]
		movups xmm6,[negy] ;a konstantsokat nem mozgathatjuk aligned-kent
		
		addps xmm3,xmm7
		divps xmm3,xmm6 ;xmm4-ba masodik tort
		
		subps xmm2,xmm3 ;xmm2-be az eredmeny
		
		movaps [temp],xmm2 ;minden iteracional ki is irathatjuk egybol
		mov edx,0
		xor esi,esi
		.kiloop:
			movss xmm0,[temp+esi]
			call io_writeflt
			call io_writeln
			add esi,4 
			inc edx
			cmp edx,4
			jne .kiloop
		
		add edi,16 ;mert 4essevel lepunk a cimeken
		loop .muveletloop
ret

.error:
mov eax,err
call io_writestr
ret

section .data
err db 'Hiba: nem oszthato 4el az elemszam',0
esz db 'Olvassa be az elemszamot',0
eek db 'Olvassa be az elemeket',0
er db 'Az eredmenyvektor (E(a,b) = (b^3 - a) / (a + b) - (a - b^2 + 1) / 4) = ',0
egy dd 1.0,1.0,1.0,1.0
negy dd 4.0,4.0,4.0,4.0

section .bss
A resd 256
B resd 256
temp resd 4