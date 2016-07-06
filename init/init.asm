[bits 16]

[org 0x0200]

;
; entry point for startup code
;

init:
;set up segment registers
cli
mov ax, 0x2000
mov es, ax
mov ds, ax

;set up stack segment
mov ax, 0x1000
mov ss, ax
xor ax, ax
mov sp, ax

;set active display page to 0
call setdisppage

sti

mov si, startmsg
call puts

;jump to compiled C code
;call _main

mov si, haltmsg
call puts

jmp hangsystem

startmsg db 'Running init...',13,10,0
haltmsg db 'System halted.',13,10,0

;include required BIOS-based support functions
%include "c:\init\io16.asm"

;------------------------------------------------------------------
; start of pmode code
;

%ifdef __BITS_64__
[bits 64]
%else
[bits 32]
%endif

%include "c:\init\ints.asm"

;pad resulting image to 32k - 512
times 32256 - ($-$$) db 0
