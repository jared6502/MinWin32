;
; real-mode startup support functions
;

;
; set active display page
;
setdisppage:
mov ah, 0x05
mov al, 0x00
int 0x10
ret

;
; simple putc function (character passed in al)
;
putc:
push bx
push cx

mov ah, 0x0E
mov bh, 0x00
mov bl, 0x70
mov cx, 0x0001
int 0x10

pop cx
pop bx
ret

;
; simple puts function (string address located in ds:si)
;
puts:
push ds
push si
push ax

puts_loop:
lodsb
cmp al, 0x00
je puts_end
call putc
jmp puts_loop

puts_end:
pop ax
pop si
pop ds
ret

;
; trap the system here on failure
;
hangsystem:
cli
hlt
jmp hangsystem