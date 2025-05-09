
BITS 64
SECTION .text

GLOBAL strlen
strlen:
    MOV RAX, 0              ; set count to 0

    loop:
        CMP BYTE [RDI], 0   ; compare Byte with NULL byte
        JE end              ; quit loop if end string
        INC RDI             ; got to next element in string
        INC RAX             ; add 1 to count
        JMP loop            ; go at start of loop

    end:
        RET                 ; quit fonction
