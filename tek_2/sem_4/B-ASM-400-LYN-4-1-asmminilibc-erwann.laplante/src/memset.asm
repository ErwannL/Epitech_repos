
BITS 64
SECTION .text

GLOBAL memset
memset:
    MOV RAX, RDI                ; set res value to input string
    MOV RCX, 0                  ; set count to 0

    loop:
        CMP RDX, RCX            ; compare len to set to count
        JE end                  ; quit loop if all len is set
        MOV [RAX + RCX], SIL    ; put int parametres in res
        INC RCX                 ; add 1 to count
        JMP loop                ; go at start of loop

    end:
        RET                     ; quit fonction
