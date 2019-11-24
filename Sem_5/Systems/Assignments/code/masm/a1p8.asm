.MODEL SMALL
.STACK 100H

.DATA
	PROMPT1 DB 'Enter the elements of the array: $'
	MSG1 DB 13D, 10D, 'Maximum element is: $'
	MSG2 db 13D, 10D, 'Minimum element is is: $'
	MAX DW ?
	MIN DW ? 

.CODE
	START:
        MOV AX, @DATA
        MOV DS, AX

        MOV MAX, 0
        MOV MIN, 9999

        LEA DX, PROMPT1
        MOV AH, 9
        INT 21H

    L0: MOV BX, 0				; Storing the elements in BX
    L1: MOV AH, 1				; Taking character input
        INT 21H

        CMP AL, 13				; Checking for enter key
        JE L3

        CMP AL, 32				; Checking for space
        JE L2

        SUB AL, '0'				; Converting ASCII value to numeric value
       
       	PUSH AX
        MOV AX, BX 				
        MOV CX, 10
        MUL CX 					; Multiplying the previous input by 10
        MOV BX, AX
        POP AX

        MOV AH, 0
        ADD BX, AX 				; Adding the current character input to the number
        JMP L1

    L2: CMP MAX, BX 			; Comparing the number with max
        JNL LB2

        MOV MAX, BX     		; If BX > max, moving value of BX to max
        JMP LB2
    
    LB2:CMP MIN, BX 			; Comparing the number with min
        JNG L0

        MOV MIN, BX 			; If BX < min, moving value of BX to min
        JMP L0

    L3: LEA DX, MSG1 			; Displaying message for maximum element
        MOV AH, 9
        INT 21H

        MOV AX, MAX 			; Displaying maximum element
        CALL PUTN

        LEA DX, MSG2 			; Displaying message for minimum element
        MOV AH, 9
        INT 21H
        
        MOV AX, MIN 			; Displaying minimum element
       	CALL PUTN

        MOV AH, 4CH
        INT 21H

	PUTN:               		; Display number in ax
                				; ax contains number (and also div C in above)
                				; dx contains remainder (rem in C above)
                				; cx contains 10 for division
	    PUSH BX
	    PUSH CX
	    PUSH DX
	 
	    MOV DX, 0           	; dx = 0
	    PUSH DX          		; push 0 as sentinel
	    MOV CX, 10      		; cx = 10
	 
	    CMP AX, 0
	    JGE CALC_DIGITS     	; number is non-negative
	    NEG AX          		; ax = -ax; ax is now positive
	    PUSH AX          		; save ax
	    MOV AL, '-'     		; display - sign
	    CALL PUTC
	    POP AX         			; restore ax
 
	CALC_DIGITS:
	    DIV CX         			; ax = ax / cx
	                    		; ax = result, dx = remainder
	    ADD DX, '0'     		; convert dx to digit
	    CMP DX,57
	    JLE L33
	    ADD DX, 7

	L33:PUSH DX          		; save digit on stack
	    MOV DX, 0      			; dx = 0
	    CMP AX, 0           	; finished ?
	    JNE CALC_DIGITS     	; if no, repeat process
 
;   all digits now on stack, display them in reverse
 
	DISP_LOOP:
	    POP DX          	; get last digit from stack
	    CMP DX, 0           ; is it sentinel
	    JE  END_DISP_LOOP   ; if yes, we are finished 
	    MOV AL, DL     		; al = dl
	    CALL PUTC           ; otherwise display digit
	    JMP DISP_LOOP
	 
	END_DISP_LOOP:
	    POP DX          	; restore registers
	    POP CX
	    POP BX
	    RET
 
	PUTC: 					; Display character in AL
 
        PUSH AX 			; save ax
        PUSH BX				; save bx 
        PUSH CX				; save cx
        PUSH DX				; save dx
 
        MOV DL, AL
        MOV AH, 2
        INT 21H
 
        POP DX				; restore dx
        POP CX 				; restore cx
        POP BX				; restore bx
        POP AX 				; restore ax
        RET
	
	END START
