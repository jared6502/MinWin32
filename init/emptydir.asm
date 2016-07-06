[org 0x0000]

;empty root directory
filenumber dq 2
filechunk dq 0
filename db '.               '
filedata times 4096 - ($-$$) db 0xFF
