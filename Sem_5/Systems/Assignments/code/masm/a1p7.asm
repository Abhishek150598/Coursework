.MODEL SMALL
.STACK 100H

.DATA
	PROMPT1 DB 'Enter first number: $'
    PROMPT2 DB 'Enter second number: $'
	MSG1 DB 13D, 10D, 'First number is greater $'
	MSG2 DB 13D, 10D, 'Second number is greater $'
    MSG3 DB 13D, 10D, 'Both numbers are equal $'
	FIRST DW ?
    SECOND DW ?

.CODE
	START:
        MOV AX, @DATA
        MOV DS, AX

        LEA DX, PROMPT1
        MOV AH, 9
        INT 21H

        MOV FIRST, 0			; Taking input for first number
    L1: MOV AH, 1				; Taking character input
        INT 21H

        CMP AL, 13				; Checking for enter key
        JE L3

        SUB AL, '0'				; Converting ASCII value to numeric value
       
       	PUSH AX
        MOV AX, FIRST 				
        MOV CX, 10
        MUL CX 					; Multiplying the previous input by 10
        MOV FIRST, AX
        POP AX

        MOV AH, 0
        ADD FIRST, AX 			; Adding the current character input to the number
        JMP L1

    L3: LEA DX, PROMPT2
        MOV AH, 9
        INT 21H

        MOV SECOND, 0           ; Taking input for second number
    L2: MOV AH, 1               ; Taking character input
        INT 21H

        CMP AL, 13              ; Checking for enter key
        JE L4

        SUB AL, '0'             ; Converting ASCII value to numeric value
       
        PUSH AX
        MOV AX, SECOND               
        MOV CX, 10
        MUL CX                  ; Multiplying the previous input by 10
        MOV SECOND, AX
        POP AX

        MOV AH, 0
        ADD SECOND, AX          ; Adding the current character input to the number
        JMP L2
        

    L4: MOV AX, SECOND
        MOV BX, FIRST
        CMP BX, AX
        JLE EQUAL

        LEA DX, MSG1
        JMP L5

    EQUAL: 
        JL LESS
        LEA DX, MSG3
        JMP L5

    LESS: 
        LEA DX, MSG2
        JMP L5

    L5: MOV AH, 9
        INT 21H

        MOV AH, 4CH
        INT 21H

	
	END START
