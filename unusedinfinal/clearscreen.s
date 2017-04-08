.THUMB				
.ALIGN  2			
.GLOBL  clearscreenasm		


.THUMB_FUNC			
clearscreenasm:				

push { r4-r7, lr }	
										
					
	mov r6, #0
	mov r7, #0

Loop:
	mov r4, r0
	add r7, #4
	add r4, r7

	strb r6, [r4]
	
	cmp  r7, #32
	
	ble  Loop
	
pop { r4-r7 }		
pop { r3 }			
					
bx r3				
