
BITS 64
SECTION .text

GLOBAL memcpy
memcpy:
    MOV RAX, RDI                    ; set res value to dest value
    MOV RCX, 0                      ; set count value to 0
    CMP RSI, 0                      ; comp if src is null
    JE end                          ; quit fonction if src is empty

    loop:
        CMP RDX, RCX                ; comp element max and cont
        JE end                      ; quit loop if all elements are copied
        MOV BL, BYTE [RSI + RCX]    ; put actual element of src in temp (8bits val because str is 8bits) value
        MOV BYTE [RAX + RCX], BL    ; put temp val in res value
        INC RCX                     ; add 1 to count
        JMP loop                    ; go at start of loop

    end:
        RET                         ; quit fonction
