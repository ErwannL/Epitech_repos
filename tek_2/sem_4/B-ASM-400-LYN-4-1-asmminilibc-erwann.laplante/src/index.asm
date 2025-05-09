
BITS 64
SECTION .text

GLOBAL index
index:
    MOV RAX, 0              ; set res value to 0

    loop:
        CMP BYTE [RDI], SIL ; compare Byte with char
        JE find             ; quit loop if char is find
        CMP BYTE [RDI], 0   ; compare Byte with NULL byte
        JE end              ; quit loop if end str
        INC RDI             ; pop first element of str
        JMP loop            ; go at start of loop

    find:
        MOV RAX, RDI        ; put rest of str in res
        RET                 ; quit fonction

    end:
        RET                 ; quit fonction
