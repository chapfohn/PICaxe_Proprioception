main:	readadc 0,b1		; read value into b1
	if b1 > 50 then flsh	; jump to flsh if b1 > 50
	goto main			; else loop back to start

flsh:	high B.1			; switch on output B.1
	pause 1000			; wait 1 second
	low B.1			; switch off output B.1
	pause 1000			; wait 1 second
	goto main			; loop back to start