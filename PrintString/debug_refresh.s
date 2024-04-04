.align 2
.global _PrintStringCustomRefresh
_PrintStringCustomRefresh:
!r4: char* String
!r5: x location (in pixels, not cursor steps)
!r6: y location
mov.l r8, @-r15
mov.l r9, @-r15
mov.l r10, @-r15
sts.l pr, @-r15

mov r4, r8
mov r5, r9
mov r6, r10 

terminatornotfound:
mov.b @r8+, r4
tst r4,r4
bt/s PrintString_end
mov r9, r5
bsr _PrintCharCustomRefresh
mov r10, r6
bra terminatornotfound
add #16, r9

PrintString_end:
lds.l @r15+, pr
mov.l @r15+, r10
mov.l @r15+, r9
mov.l @r15+, r8
rts
nop





.align 2
.global _PrintCharCustomRefresh
_PrintCharCustomRefresh:
!r4: char
!r5: x location (in pixels, not cursor steps)
!r6: y location

mov.l r10, @-r15 ! r5 backup
mov.l r11, @-r15 ! r6 backup
sts.l PR, @-r15

mov r5, r10
mov r6, r11

PrintStringCustomRefresh_terminatornotfound:
mov.l GetFontPtr, r3
jsr @r3
nop


!prepare lcd
mov.l misteryfunctionOne, r3
!Calculate the starting x pos
mov r10, r4

mov #0xf, r5	!width - 1
add r4, r5

mov r11, r6		!start y
mov r0, r11
mov r6, r7
jsr @r3
add #11, r7		!height - 1 


mov.l misteryfunctionTwo, r3
jsr @r3
mov #0x2c, r4


! Now I just have to provide the character as pixel data
mov.l ScreenBusPtr, r4
mov #12, r1
copypixelsloopy:
	mov #16, r0
	copypixelsloopx:
		mov.b @r11+, r3
		mov.w r3, @r4 
    synco
		dt r0
		bf copypixelsloopx
	dt r1
	bf copypixelsloopy

lds.l @r15+, pr
mov.l @r15+, r11
mov.l @r15+, r10

rts
nop

!Data:
.align 2
GetFontPtr:
.long 0x8002e464 
misteryfunctionOne:
.long 0x80038068
misteryfunctionTwo:
.long 0x80038040
ScreenBusPtr:
.long 0xb4000000
