.THUMB				@ turn on thumb
.ALIGN  2			@ no idea why we do this
.GLOBL  swapani		@ name of function goes here



.THUMB_FUNC			@ we are about to declare a thumb function
swapani:				@ function start

push { r4-r7, lr }	@ push r4-r7 and link register onto stack. Your function might use these
					@ registers, so we need to preserve the values just in case!
					@ we don't need to worry about r0-r3 as it is assumed they will be regularly messed up anyway
	

@ the magic happens here!

ldrb r4, [r0]		@ dereference it into r4 - use square brackets when dealing with addresses!
cmp r4, #1		
beq true
bal false

true:
mov r4, #0
bal skip

false:
mov r4, #1

skip:
strb r4, [r0]

pop { r4-r7 }		@ pop first 4 values from stack back into r4-r7, and also
pop { r3 }			@ pop the next value from stack (stored value for lr) into some unused register, e.g. r3 -
					@ we cannot overwrite lr so we have to do it via a normal register
bx r3				@ "branch and exchange" (return) back to C, using the previous value for lr stored in r3