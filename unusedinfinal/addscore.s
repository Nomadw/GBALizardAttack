.THUMB				@ turn on thumb
.ALIGN  2			@ no idea why we do this
.GLOBL  addscore		@ name of function goes here



.THUMB_FUNC			@ we are about to declare a thumb function
addscore:				@ function start

push { r4-r7, lr }

ldr r4, [r0]

add r4, #1
str r4, [r0]

pop { r4-r7 }
pop { r3 }
bx r3