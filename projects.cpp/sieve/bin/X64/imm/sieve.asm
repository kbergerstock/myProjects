; Listing generated by Microsoft (R) Optimizing Compiler Version 19.29.30040.0 

include listing.inc

INCLUDELIB OLDNAMES

PUBLIC	??_C@_01IHBHIGKO@?0@				; `string'
;	COMDAT ??_C@_01IHBHIGKO@?0@
CONST	SEGMENT
??_C@_01IHBHIGKO@?0@ DB ',', 00H			; `string'
?_Fake_alloc@std@@3U_Fake_allocator@1@B	ORG $+1		; std::_Fake_alloc
PUBLIC	?itor@Sieve@@AEAAII@Z				; Sieve::itor
PUBLIC	?find@Map@Sieve@@QEAAII@Z			; Sieve::Map::find
PUBLIC	?set@tBitArray@@QEAAXI@Z			; tBitArray::set
PUBLIC	?get@tBitArray@@QEAA_NI@Z			; tBitArray::get
PUBLIC	?mask@tBitArray@@AEAAEI@Z			; tBitArray::mask
PUBLIC	?idx@tBitArray@@AEAAII@Z			; tBitArray::idx
PUBLIC	??6@YAAEAV?$basic_ostream@DU?$char_traits@D@std@@@std@@AEAV01@AEAVSieve@@@Z ; operator<<
PUBLIC	?validate@Sieve@@QEAA_NXZ			; Sieve::validate
PUBLIC	?counted@Sieve@@QEAAIXZ				; Sieve::counted
PUBLIC	?sieve2@Sieve@@QEAAXXZ				; Sieve::sieve2
PUBLIC	?empty@Sieve@@QEAAXXZ				; Sieve::empty
PUBLIC	?init@Sieve@@QEAAXI@Z				; Sieve::init
PUBLIC	??0Sieve@@QEAA@XZ				; Sieve::Sieve
;	COMDAT pdata
pdata	SEGMENT
$pdata$?find@Map@Sieve@@QEAAII@Z DD imagerel $LN13
	DD	imagerel $LN13+178
	DD	imagerel $unwind$?find@Map@Sieve@@QEAAII@Z
pdata	ENDS
;	COMDAT pdata
pdata	SEGMENT
$pdata$??6@YAAEAV?$basic_ostream@DU?$char_traits@D@std@@@std@@AEAV01@AEAVSieve@@@Z DD imagerel $LN32
	DD	imagerel $LN32+194
	DD	imagerel $unwind$??6@YAAEAV?$basic_ostream@DU?$char_traits@D@std@@@std@@AEAV01@AEAVSieve@@@Z
pdata	ENDS
;	COMDAT pdata
pdata	SEGMENT
$pdata$?validate@Sieve@@QEAA_NXZ DD imagerel $LN31
	DD	imagerel $LN31+249
	DD	imagerel $unwind$?validate@Sieve@@QEAA_NXZ
pdata	ENDS
;	COMDAT pdata
pdata	SEGMENT
$pdata$?sieve2@Sieve@@QEAAXXZ DD imagerel $LN40
	DD	imagerel $LN40+151
	DD	imagerel $unwind$?sieve2@Sieve@@QEAAXXZ
pdata	ENDS
;	COMDAT pdata
pdata	SEGMENT
$pdata$?empty@Sieve@@QEAAXXZ DD imagerel $LN9
	DD	imagerel $LN9+52
	DD	imagerel $unwind$?empty@Sieve@@QEAAXXZ
;	COMDAT xdata
xdata	SEGMENT
$unwind$?empty@Sieve@@QEAAXXZ DD 020601H
	DD	030023206H
xdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$unwind$?sieve2@Sieve@@QEAAXXZ DD 020501H
	DD	013405H
xdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$unwind$?validate@Sieve@@QEAA_NXZ DD 010701H
	DD	0a207H
xdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$unwind$??6@YAAEAV?$basic_ostream@DU?$char_traits@D@std@@@std@@AEAV01@AEAVSieve@@@Z DD 081401H
	DD	086414H
	DD	075414H
	DD	063414H
	DD	070103214H
xdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$unwind$?find@Map@Sieve@@QEAAII@Z DD 010401H
	DD	0a204H
; Function compile flags: /Ogtpy
;	COMDAT ??0Sieve@@QEAA@XZ
_TEXT	SEGMENT
this$ = 8
??0Sieve@@QEAA@XZ PROC					; Sieve::Sieve, COMDAT
; File D:\myProjects\projects.cpp\sieve\src\sieve.cpp
; Line 34
	xor	eax, eax
	mov	QWORD PTR [rcx], rax
; File D:\myProjects\projects.cpp\sieve\src\tbitarray.cpp
; Line 10
	mov	DWORD PTR [rcx+16], eax
; Line 11
	mov	QWORD PTR [rcx+24], rax
; File D:\myProjects\projects.cpp\sieve\src\sieve.cpp
; Line 39
	mov	rax, rcx
	ret	0
??0Sieve@@QEAA@XZ ENDP					; Sieve::Sieve
_TEXT	ENDS
; Function compile flags: /Ogtpy
;	COMDAT ?init@Sieve@@QEAAXI@Z
_TEXT	SEGMENT
this$ = 8
_prime_limit$ = 16
?init@Sieve@@QEAAXI@Z PROC				; Sieve::init, COMDAT
; File D:\myProjects\projects.cpp\sieve\src\sieve.cpp
; Line 46
	mov	DWORD PTR [rcx], edx
; Line 47
	shr	edx, 1
	mov	DWORD PTR [rcx+4], edx
; Line 48
	add	rcx, 16
	jmp	?init@tBitArray@@QEAAXI@Z		; tBitArray::init
?init@Sieve@@QEAAXI@Z ENDP				; Sieve::init
_TEXT	ENDS
; Function compile flags: /Ogtpy
;	COMDAT ?empty@Sieve@@QEAAXXZ
_TEXT	SEGMENT
this$ = 48
?empty@Sieve@@QEAAXXZ PROC				; Sieve::empty, COMDAT
; File D:\myProjects\projects.cpp\sieve\src\sieve.cpp
; Line 53
$LN9:
	push	rbx
	sub	rsp, 32					; 00000020H
	mov	rbx, rcx
; File D:\myProjects\projects.cpp\sieve\src\tbitarray.cpp
; Line 32
	mov	rcx, QWORD PTR [rcx+24]
	test	rcx, rcx
	je	SHORT $LN6@empty
; Line 33
	call	??_V@YAXPEAX@Z				; operator delete[]
; Line 34
	xor	eax, eax
	mov	QWORD PTR [rbx+24], rax
; Line 35
	mov	DWORD PTR [rbx+16], eax
; File D:\myProjects\projects.cpp\sieve\src\sieve.cpp
; Line 57
	mov	QWORD PTR [rbx], rax
	add	rsp, 32					; 00000020H
	pop	rbx
	ret	0
$LN6@empty:
; Line 55
	xor	eax, eax
; Line 57
	mov	QWORD PTR [rbx], rax
	add	rsp, 32					; 00000020H
	pop	rbx
	ret	0
?empty@Sieve@@QEAAXXZ ENDP				; Sieve::empty
_TEXT	ENDS
; Function compile flags: /Ogtpy
;	COMDAT ?sieve2@Sieve@@QEAAXXZ
_TEXT	SEGMENT
this$ = 8
?sieve2@Sieve@@QEAAXXZ PROC				; Sieve::sieve2, COMDAT
; File D:\myProjects\projects.cpp\sieve\src\sieve.cpp
; Line 60
$LN40:
	mov	QWORD PTR [rsp+8], rbx
; File D:\myProjects\projects.cpp\sieve\headers\tBitArray.h
; Line 32
	mov	rax, QWORD PTR [rcx+24]
; File D:\myProjects\projects.cpp\sieve\src\sieve.cpp
; Line 64
	mov	r11d, 1
	mov	r9, rcx
; File D:\myProjects\projects.cpp\sieve\headers\tBitArray.h
; Line 32
	or	BYTE PTR [rax], 1
; File D:\myProjects\projects.cpp\sieve\src\sieve.cpp
; Line 64
	mov	ebx, DWORD PTR [rcx+4]
	cmp	ebx, r11d
	jbe	SHORT $LN38@sieve2
	npad	3
$LL4@sieve2:
; File D:\myProjects\projects.cpp\sieve\headers\tBitArray.h
; Line 31
	mov	rax, QWORD PTR [r9+24]
; Line 22
	mov	ecx, r11d
	and	ecx, 7
	mov	edx, 1
	shl	dl, cl
; Line 31
	mov	r8d, ebx
; Line 20
	mov	ecx, r11d
	shr	rcx, 3
; Line 31
	test	dl, BYTE PTR [rcx+rax]
; File D:\myProjects\projects.cpp\sieve\src\sieve.cpp
; Line 65
	jne	SHORT $LN2@sieve2
; Line 68
	lea	r10d, DWORD PTR [r11*2+1]
; Line 69
	mov	eax, r10d
	imul	eax, r10d
; Line 73
	cmp	eax, DWORD PTR [r9]
	jae	SHORT $LN38@sieve2
; Line 76
	dec	eax
	shr	eax, 1
	cmp	eax, ebx
	jae	SHORT $LN2@sieve2
	npad	4
$LL7@sieve2:
; File D:\myProjects\projects.cpp\sieve\headers\tBitArray.h
; Line 20
	mov	r8d, eax
; Line 22
	mov	ecx, eax
; Line 20
	shr	r8, 3
; Line 22
	and	ecx, 7
; Line 32
	add	r8, QWORD PTR [r9+24]
; File D:\myProjects\projects.cpp\sieve\src\sieve.cpp
; Line 76
	add	eax, r10d
; File D:\myProjects\projects.cpp\sieve\headers\tBitArray.h
; Line 32
	movzx	edx, BYTE PTR [r8]
	bts	edx, ecx
	mov	BYTE PTR [r8], dl
; File D:\myProjects\projects.cpp\sieve\src\sieve.cpp
; Line 76
	mov	r8d, DWORD PTR [r9+4]
	cmp	eax, r8d
	jb	SHORT $LL7@sieve2
$LN2@sieve2:
; Line 64
	inc	r11d
	mov	ebx, r8d
	cmp	r11d, r8d
	jb	SHORT $LL4@sieve2
$LN38@sieve2:
; Line 86
	mov	rbx, QWORD PTR [rsp+8]
	ret	0
?sieve2@Sieve@@QEAAXXZ ENDP				; Sieve::sieve2
_TEXT	ENDS
; Function compile flags: /Ogtpy
;	COMDAT ?counted@Sieve@@QEAAIXZ
_TEXT	SEGMENT
this$ = 8
?counted@Sieve@@QEAAIXZ PROC				; Sieve::counted, COMDAT
; File D:\myProjects\projects.cpp\sieve\src\sieve.cpp
; Line 90
	mov	eax, DWORD PTR [rcx+4]
	mov	edx, 1
	cmp	eax, edx
	jbe	SHORT $LN17@counted
; File D:\myProjects\projects.cpp\sieve\headers\tBitArray.h
; Line 31
	mov	r10, QWORD PTR [rcx+24]
	lea	r9d, DWORD PTR [rax-1]
	mov	cl, 2
	mov	r8d, edx
	npad	7
$LL4@counted:
; Line 20
	mov	rax, r8
	shr	rax, 3
; Line 31
	test	BYTE PTR [rax+r10], cl
; File D:\myProjects\projects.cpp\sieve\src\sieve.cpp
; Line 90
	lea	eax, DWORD PTR [rdx+1]
	cmovne	eax, edx
	inc	r8
	rol	cl, 1
	mov	edx, eax
	sub	r9, 1
	jne	SHORT $LL4@counted
; Line 95
	ret	0
$LN17@counted:
; Line 94
	mov	eax, edx
; Line 95
	ret	0
?counted@Sieve@@QEAAIXZ ENDP				; Sieve::counted
_TEXT	ENDS
; Function compile flags: /Ogtpy
;	COMDAT ?validate@Sieve@@QEAA_NXZ
_TEXT	SEGMENT
_map_$1 = 0
this$ = 96
?validate@Sieve@@QEAA_NXZ PROC				; Sieve::validate, COMDAT
; File D:\myProjects\projects.cpp\sieve\src\sieve.cpp
; Line 98
$LN31:
	mov	rax, rsp
	sub	rsp, 88					; 00000058H
; Line 99
	mov	edx, DWORD PTR [rcx]
; Line 12
	xor	r8d, r8d
; Line 14
	mov	DWORD PTR _map_$1[rsp], 10
; Line 98
	mov	r9, rcx
; Line 22
	mov	DWORD PTR [rax-20], r8d
; Line 24
	mov	ecx, r8d
	mov	DWORD PTR [rax-84], 4
	mov	DWORD PTR [rax-80], 100			; 00000064H
	mov	DWORD PTR [rax-76], 25
	mov	DWORD PTR [rax-72], 1000		; 000003e8H
	mov	DWORD PTR [rax-68], 168			; 000000a8H
	mov	DWORD PTR [rax-64], 10000		; 00002710H
	mov	DWORD PTR [rax-60], 1229		; 000004cdH
	mov	DWORD PTR [rax-56], 100000		; 000186a0H
	mov	DWORD PTR [rax-52], 9592		; 00002578H
	mov	DWORD PTR [rax-48], 1000000		; 000f4240H
	mov	DWORD PTR [rax-44], 78498		; 000132a2H
	mov	DWORD PTR [rax-40], 10000000		; 00989680H
	mov	DWORD PTR [rax-36], 684579		; 000a7223H
	mov	DWORD PTR [rax-32], 100000000		; 05f5e100H
	mov	QWORD PTR [rax-28], 5761455		; 0057e9afH
	mov	eax, r8d
	npad	6
$LL6@validate:
; Line 25
	cmp	DWORD PTR _map_$1[rsp+rax*8], edx
	je	SHORT $LN23@validate
; Line 24
	inc	ecx
	inc	rax
	cmp	rax, 9
	jl	SHORT $LL6@validate
; Line 25
	jmp	SHORT $LN5@validate
$LN23@validate:
; Line 26
	mov	eax, ecx
	mov	r8d, DWORD PTR _map_$1[rsp+rax*8+4]
$LN5@validate:
; Line 90
	mov	eax, DWORD PTR [r9+4]
	mov	ecx, 1
	cmp	eax, ecx
	jbe	SHORT $LN11@validate
; File D:\myProjects\projects.cpp\sieve\headers\tBitArray.h
; Line 31
	mov	r11, QWORD PTR [r9+24]
	lea	r10d, DWORD PTR [rax-1]
	mov	r9d, ecx
	mov	dl, 2
	npad	13
$LL12@validate:
; Line 20
	mov	rax, r9
	shr	rax, 3
; Line 31
	test	BYTE PTR [rax+r11], dl
; File D:\myProjects\projects.cpp\sieve\src\sieve.cpp
; Line 90
	lea	eax, DWORD PTR [rcx+1]
	cmovne	eax, ecx
	inc	r9
	rol	dl, 1
	mov	ecx, eax
	sub	r10, 1
	jne	SHORT $LL12@validate
$LN11@validate:
; Line 101
	cmp	r8d, ecx
	sete	al
; Line 102
	add	rsp, 88					; 00000058H
	ret	0
?validate@Sieve@@QEAA_NXZ ENDP				; Sieve::validate
_TEXT	ENDS
; Function compile flags: /Ogtpy
;	COMDAT ??6@YAAEAV?$basic_ostream@DU?$char_traits@D@std@@@std@@AEAV01@AEAVSieve@@@Z
_TEXT	SEGMENT
os$ = 48
P$ = 56
??6@YAAEAV?$basic_ostream@DU?$char_traits@D@std@@@std@@AEAV01@AEAVSieve@@@Z PROC ; operator<<, COMDAT
; File D:\myProjects\projects.cpp\sieve\src\sieve.cpp
; Line 118
$LN32:
	mov	QWORD PTR [rsp+8], rbx
	mov	QWORD PTR [rsp+16], rbp
	mov	QWORD PTR [rsp+24], rsi
	push	rdi
	sub	rsp, 32					; 00000020H
; Line 120
	mov	rax, QWORD PTR [rcx]
	xor	esi, esi
; Line 121
	xor	ebx, ebx
	mov	rbp, rdx
	mov	rdi, rcx
	movsxd	r8, DWORD PTR [rax+4]
; File C:\myPrograms\vs2019\VC\Tools\MSVC\14.29.30037\include\xiosbase
; Line 368
	mov	QWORD PTR [r8+rcx+40], 6
; File D:\myProjects\projects.cpp\sieve\src\sieve.cpp
; Line 121
	cmp	DWORD PTR [rdx+4], ebx
	jbe	SHORT $LN30@operator
$LL4@operator:
; Line 106
	test	ebx, ebx
	je	SHORT $LN13@operator
; File D:\myProjects\projects.cpp\sieve\headers\tBitArray.h
; Line 31
	mov	r8, QWORD PTR [rbp+24]
; Line 22
	mov	ecx, ebx
	and	ecx, 7
; Line 20
	mov	r9d, ebx
	shr	r9, 3
; Line 22
	mov	edx, 1
	shl	dl, cl
; Line 31
	test	BYTE PTR [r9+r8], dl
; File D:\myProjects\projects.cpp\sieve\src\sieve.cpp
; Line 111
	jne	SHORT $LN2@operator
; Line 112
	lea	edx, DWORD PTR [rbx*2+1]
	jmp	SHORT $LN29@operator
$LN13@operator:
; Line 108
	mov	edx, 2
$LN29@operator:
; Line 124
	mov	rax, QWORD PTR [rdi]
	movsxd	rcx, DWORD PTR [rax+4]
; File C:\myPrograms\vs2019\VC\Tools\MSVC\14.29.30037\include\xiosbase
; Line 368
	mov	QWORD PTR [rcx+rdi+40], 6
; File D:\myProjects\projects.cpp\sieve\src\sieve.cpp
; Line 125
	mov	rcx, rdi
	call	QWORD PTR __imp_??6?$basic_ostream@DU?$char_traits@D@std@@@std@@QEAAAEAV01@I@Z
	mov	rcx, rax
	lea	rdx, OFFSET FLAT:??_C@_01IHBHIGKO@?0@
	call	??$?6U?$char_traits@D@std@@@std@@YAAEAV?$basic_ostream@DU?$char_traits@D@std@@@0@AEAV10@PEBD@Z ; std::operator<<<std::char_traits<char> >
; Line 126
	inc	esi
; Line 127
	cmp	esi, 12
	jle	SHORT $LN2@operator
; Line 128
	xor	esi, esi
; Line 129
	lea	rdx, OFFSET FLAT:??$endl@DU?$char_traits@D@std@@@std@@YAAEAV?$basic_ostream@DU?$char_traits@D@std@@@0@AEAV10@@Z ; std::endl<char,std::char_traits<char> >
	mov	rcx, rdi
	call	QWORD PTR __imp_??6?$basic_ostream@DU?$char_traits@D@std@@@std@@QEAAAEAV01@P6AAEAV01@AEAV01@@Z@Z
$LN2@operator:
; Line 121
	inc	ebx
	cmp	ebx, DWORD PTR [rbp+4]
	jb	SHORT $LL4@operator
$LN30@operator:
; Line 134
	mov	rbx, QWORD PTR [rsp+48]
	mov	rax, rdi
	mov	rbp, QWORD PTR [rsp+56]
	mov	rsi, QWORD PTR [rsp+64]
	add	rsp, 32					; 00000020H
	pop	rdi
	ret	0
??6@YAAEAV?$basic_ostream@DU?$char_traits@D@std@@@std@@AEAV01@AEAVSieve@@@Z ENDP ; operator<<
_TEXT	ENDS
; Function compile flags: /Ogtpy
;	COMDAT ?idx@tBitArray@@AEAAII@Z
_TEXT	SEGMENT
this$dead$ = 8
i$ = 16
?idx@tBitArray@@AEAAII@Z PROC				; tBitArray::idx, COMDAT
; File D:\myProjects\projects.cpp\sieve\headers\tBitArray.h
; Line 20
	shr	edx, 3
	mov	eax, edx
	ret	0
?idx@tBitArray@@AEAAII@Z ENDP				; tBitArray::idx
_TEXT	ENDS
; Function compile flags: /Ogtpy
;	COMDAT ?mask@tBitArray@@AEAAEI@Z
_TEXT	SEGMENT
this$dead$ = 8
i$ = 16
?mask@tBitArray@@AEAAEI@Z PROC				; tBitArray::mask, COMDAT
; File D:\myProjects\projects.cpp\sieve\headers\tBitArray.h
; Line 22
	and	edx, 7
	mov	eax, 1
	movzx	ecx, dl
	shl	al, cl
	ret	0
?mask@tBitArray@@AEAAEI@Z ENDP				; tBitArray::mask
_TEXT	ENDS
; Function compile flags: /Ogtpy
;	COMDAT ?get@tBitArray@@QEAA_NI@Z
_TEXT	SEGMENT
this$ = 8
i$ = 16
?get@tBitArray@@QEAA_NI@Z PROC				; tBitArray::get, COMDAT
; File D:\myProjects\projects.cpp\sieve\headers\tBitArray.h
; Line 31
	mov	r8, QWORD PTR [rcx+8]
; Line 22
	mov	eax, 1
; Line 20
	mov	r9d, edx
; Line 22
	and	edx, 7
; Line 20
	shr	r9, 3
; Line 22
	movzx	ecx, dl
	shl	al, cl
; Line 31
	test	BYTE PTR [r9+r8], al
	setne	al
	ret	0
?get@tBitArray@@QEAA_NI@Z ENDP				; tBitArray::get
_TEXT	ENDS
; Function compile flags: /Ogtpy
;	COMDAT ?set@tBitArray@@QEAAXI@Z
_TEXT	SEGMENT
this$ = 8
i$ = 16
?set@tBitArray@@QEAAXI@Z PROC				; tBitArray::set, COMDAT
; File D:\myProjects\projects.cpp\sieve\headers\tBitArray.h
; Line 32
	mov	rcx, QWORD PTR [rcx+8]
; Line 20
	mov	r8d, edx
; Line 22
	and	edx, 7
; Line 20
	shr	r8, 3
; Line 32
	movzx	eax, BYTE PTR [rcx+r8]
	bts	eax, edx
	mov	BYTE PTR [rcx+r8], al
	ret	0
?set@tBitArray@@QEAAXI@Z ENDP				; tBitArray::set
_TEXT	ENDS
; Function compile flags: /Ogtpy
;	COMDAT ?find@Map@Sieve@@QEAAII@Z
_TEXT	SEGMENT
_map_$ = 0
this$dead$ = 96
prime_limit$ = 104
?find@Map@Sieve@@QEAAII@Z PROC				; Sieve::Map::find, COMDAT
; File D:\myProjects\projects.cpp\sieve\src\sieve.cpp
; Line 11
$LN13:
	sub	rsp, 88					; 00000058H
; Line 12
	xor	eax, eax
; Line 14
	mov	DWORD PTR _map_$[rsp], 10
	mov	r8d, edx
; Line 22
	mov	DWORD PTR _map_$[rsp+68], eax
; Line 24
	mov	edx, eax
	mov	DWORD PTR _map_$[rsp+4], 4
	mov	ecx, eax
	mov	DWORD PTR _map_$[rsp+8], 100		; 00000064H
	mov	DWORD PTR _map_$[rsp+12], 25
	mov	DWORD PTR _map_$[rsp+16], 1000		; 000003e8H
	mov	DWORD PTR _map_$[rsp+20], 168		; 000000a8H
	mov	DWORD PTR _map_$[rsp+24], 10000		; 00002710H
	mov	DWORD PTR _map_$[rsp+28], 1229		; 000004cdH
	mov	DWORD PTR _map_$[rsp+32], 100000	; 000186a0H
	mov	DWORD PTR _map_$[rsp+36], 9592		; 00002578H
	mov	DWORD PTR _map_$[rsp+40], 1000000	; 000f4240H
	mov	DWORD PTR _map_$[rsp+44], 78498		; 000132a2H
	mov	DWORD PTR _map_$[rsp+48], 10000000	; 00989680H
	mov	DWORD PTR _map_$[rsp+52], 684579	; 000a7223H
	mov	DWORD PTR _map_$[rsp+56], 100000000	; 05f5e100H
	mov	QWORD PTR _map_$[rsp+60], 5761455	; 0057e9afH
$LL4@find:
; Line 25
	cmp	DWORD PTR _map_$[rsp+rcx*8], r8d
	je	SHORT $LN8@find
; Line 24
	inc	edx
	inc	rcx
	cmp	rcx, 9
	jl	SHORT $LL4@find
; Line 31
	add	rsp, 88					; 00000058H
	ret	0
$LN8@find:
; Line 26
	mov	eax, edx
; Line 30
	mov	eax, DWORD PTR _map_$[rsp+rax*8+4]
; Line 31
	add	rsp, 88					; 00000058H
	ret	0
?find@Map@Sieve@@QEAAII@Z ENDP				; Sieve::Map::find
_TEXT	ENDS
; Function compile flags: /Ogtpy
;	COMDAT ?itor@Sieve@@AEAAII@Z
_TEXT	SEGMENT
this$ = 8
i$ = 16
?itor@Sieve@@AEAAII@Z PROC				; Sieve::itor, COMDAT
; File D:\myProjects\projects.cpp\sieve\src\sieve.cpp
; Line 106
	test	edx, edx
	je	SHORT $LN4@itor
; File D:\myProjects\projects.cpp\sieve\headers\tBitArray.h
; Line 31
	mov	r9, QWORD PTR [rcx+24]
; Line 22
	mov	r8d, 1
; Line 20
	mov	r10d, edx
; Line 22
	mov	ecx, edx
	and	ecx, 7
; Line 20
	shr	r10, 3
; Line 22
	shl	r8b, cl
; Line 31
	test	BYTE PTR [r10+r9], r8b
; File D:\myProjects\projects.cpp\sieve\src\sieve.cpp
; Line 111
	jne	SHORT $LN14@itor
; Line 112
	lea	eax, DWORD PTR [rdx*2+1]
; Line 115
	ret	0
$LN14@itor:
; Line 114
	xor	eax, eax
; Line 115
	ret	0
$LN4@itor:
; Line 114
	mov	eax, 2
; Line 115
	ret	0
?itor@Sieve@@AEAAII@Z ENDP				; Sieve::itor
_TEXT	ENDS
END
