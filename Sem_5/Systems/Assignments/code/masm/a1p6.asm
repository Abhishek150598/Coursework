.MODEL SMALL
.STACK 100H
 
.DATA
    PROMPT_1  DB  "Enter the Letter : $"
    PROMPT_2  DB  0DH,0AH,"The Letter is : $"
 
.CODE
    MAIN PROC
        MOV AX, @DATA                ; initialize DS
        MOV DS, AX

        LEA DX, PROMPT_1             ; load and print PROMPT_1
        MOV AH, 9
        INT 21H

        MOV AH, 1                    ; read a letter
        INT 21H

        MOV BL, AL                   ; save the letter in BL 

        LEA DX, PROMPT_2             ; load and print PROMPT_2
        MOV AH, 9
        INT 21H


        MOV AH, 2                    ; print the letter
        MOV DL, BL
        INT 21H

        MOV AH, 4CH                  ; return control to DOS
        INT 21H
    MAIN ENDP 
    END MAIN