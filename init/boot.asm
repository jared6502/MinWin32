[bits 16]

[org 0x7C00]
jmp start

;
; start of boot code
;
start:
cli

;set segment registers and stack pointer
mov ds, ax
mov es, ax
mov ss, ax
xor ax, ax
dec ax
mov sp, ax

;set active display page to 0
call setdisppage

mov si, statstring1
call puts

sti

;
; attempt to load program into memory
;
loadprg:

push dx
push es

;assume a very specific drive layout
;first 32k of disk after bootloader contains secondary bootloader/kernel
;load the kernel at 0x2000:0x0000 and jump to offset 0x0300

;assume DL already contains the correct drive number
mov ax, 0x2000

mov es, ax		;segment address = 0x2000
xor ax, ax
mov bx, ax		;offset address = 0x0000
mov ah, 0x02	;read sectors
mov al, 0x40	;64 sectors = 32k bytes
mov ch, 0x00
mov cl, 0x01	;cyl 0, sector 1
mov dh, 0x00	;head 0
int 0x13

pop es
pop dx

;check for any errors
cmp ah, 0x00
jne retry

cmp al, 0x40
jne retry

jc retry

runsystem:
mov si, statstring2
call puts
;jump to loaded program
jmp 0x2000:0x0200
jmp hangsystem

;
; increment retry counter
;

retry:
mov ax, [retrycount]
inc ax
mov [retrycount], ax
cmp ax, 0x04
je hangsystem

mov si, errstring1
call puts

jmp loadprg

%include "io16.asm"

retrycount dw 0x0000

;
; status messages
;
statstring1 db 'Boot',13,10,0
statstring2 db 'System loaded.',13,10,0

;
; error messages
;
errstring1 db 'Retrying...',13,10,0
errstring2 db 'Failed to boot.',13,10,0

;eat up any remaining space
times 510 - ($-$$) db 0

bootsig dw 0xAA55

