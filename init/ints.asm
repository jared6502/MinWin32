;
; interrupt handler assembly code
;

%include "c:\os\intnums.inc"

_int0:
	push eax
	mov eax, VAL_INT0
	mov [_Interrupt], eax
	pop eax
	call _InterruptHandler
	iret
	
_int1:
	push eax
	mov eax, VAL_INT1
	mov [_Interrupt], eax
	pop eax
	call _InterruptHandler
	iret
	
_int2:
	push eax
	mov eax, VAL_INT2
	mov [_Interrupt], eax
	pop eax
	call _InterruptHandler
	iret
	
_int3:
	push eax
	mov eax, VAL_INT3
	mov [_Interrupt], eax
	pop eax
	call _InterruptHandler
	iret
	
_int4:
	push eax
	mov eax, VAL_INT4
	mov [_Interrupt], eax
	pop eax
	call _InterruptHandler
	iret
	
_int5:
	push eax
	mov eax, VAL_INT5
	mov [_Interrupt], eax
	pop eax
	call _InterruptHandler
	iret
	
_int6:
	push eax
	mov eax, VAL_INT6
	mov [_Interrupt], eax
	pop eax
	call _InterruptHandler
	iret
	
_int7:
	push eax
	mov eax, VAL_INT7
	mov [_Interrupt], eax
	pop eax
	call _InterruptHandler
	iret
	
_int8:
	push eax
	mov eax, VAL_INT8
	mov [_Interrupt], eax
	pop eax
	call _InterruptHandler
	iret
	
_int9:
	push eax
	mov eax, VAL_INT9
	mov [_Interrupt], eax
	pop eax
	call _InterruptHandler
	iret
	
_int10:
	push eax
	mov eax, VAL_INT10
	mov [_Interrupt], eax
	pop eax
	call _InterruptHandler
	iret
	
_int11:
	push eax
	mov eax, VAL_INT11
	mov [_Interrupt], eax
	pop eax
	call _InterruptHandler
	iret
	
_int12:
	push eax
	mov eax, VAL_INT12
	mov [_Interrupt], eax
	pop eax
	call _InterruptHandler
	iret
	
_int13:
	push eax
	mov eax, VAL_INT13
	mov [_Interrupt], eax
	pop eax
	call _InterruptHandler
	iret
	
_int14:
	push eax
	mov eax, VAL_INT14
	mov [_Interrupt], eax
	pop eax
	call _InterruptHandler
	iret
	
_int15:
	push eax
	mov eax, VAL_INT15
	mov [_Interrupt], eax
	pop eax
	call _InterruptHandler
	iret
	
_int16:
	push eax
	mov eax, VAL_INT16
	mov [_Interrupt], eax
	pop eax
	call _InterruptHandler
	iret
	
_int17:
	push eax
	mov eax, VAL_INT17
	mov [_Interrupt], eax
	pop eax
	call _InterruptHandler
	iret
	
_int18:
	push eax
	mov eax, VAL_INT18
	mov [_Interrupt], eax
	pop eax
	call _InterruptHandler
	iret
	
_int19:
	push eax
	mov eax, VAL_INT19
	mov [_Interrupt], eax
	pop eax
	call _InterruptHandler
	iret
	
_int20:
	push eax
	mov eax, VAL_INT20
	mov [_Interrupt], eax
	pop eax
	call _InterruptHandler
	iret
	
_int21:
	push eax
	mov eax, VAL_INT21
	mov [_Interrupt], eax
	pop eax
	call _InterruptHandler
	iret
	
_int22:
	push eax
	mov eax, VAL_INT22
	mov [_Interrupt], eax
	pop eax
	call _InterruptHandler
	iret
	
_int23:
	push eax
	mov eax, VAL_INT23
	mov [_Interrupt], eax
	pop eax
	call _InterruptHandler
	iret
	
_int24:
	push eax
	mov eax, VAL_INT24
	mov [_Interrupt], eax
	pop eax
	call _InterruptHandler
	iret
	
_int25:
	push eax
	mov eax, VAL_INT25
	mov [_Interrupt], eax
	pop eax
	call _InterruptHandler
	iret
	
_int26:
	push eax
	mov eax, VAL_INT26
	mov [_Interrupt], eax
	pop eax
	call _InterruptHandler
	iret
	
_int27:
	push eax
	mov eax, VAL_INT27
	mov [_Interrupt], eax
	pop eax
	call _InterruptHandler
	iret
	
_int28:
	push eax
	mov eax, VAL_INT28
	mov [_Interrupt], eax
	pop eax
	call _InterruptHandler
	iret
	
_int29:
	push eax
	mov eax, VAL_INT29
	mov [_Interrupt], eax
	pop eax
	call _InterruptHandler
	iret
	
_int30:
	push eax
	mov eax, VAL_INT30
	mov [_Interrupt], eax
	pop eax
	call _InterruptHandler
	iret
	
_int31:
	;int 0x20 (windows/dos)
	push eax
	mov eax, VAL_INT31
	mov [_Interrupt], eax
	pop eax
	call _InterruptHandler
	iret
	
_int32:
	;int 0x21 (windows/dos)
	push eax
	mov eax, VAL_INT32
	mov [_Interrupt], eax
	pop eax
	call _InterruptHandler
	iret
	
_int128:
	;int 0x80 (*nix)
	push eax
	mov eax, VAL_INT128
	mov [_Interrupt], eax
	pop eax
	call _InterruptHandler
	iret
	
_wincallgate:
	push eax
	mov eax, VAL_WINCALLGATE
	mov [_Interrupt], eax
	pop eax
	call _InterruptHandler
	iret
	
_nixcallgate:
	push eax
	mov eax, VAL_NIXCALLGATE
	mov [_Interrupt], eax
	pop eax
	call _InterruptHandler
	iret

_Interrupt dd 0xFFFFFFFF

_InterruptHandler:
ret
