[org 0x0000]

;empty cluster (still contains header data)
filenumber dq -1
filechunk dq -1
filedata times 1433600 - ($-$$) db 0xFF
