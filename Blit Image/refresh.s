!take pointer, width and height as inputs.
.global _refresh
.align 2
_refresh:
sts.l PR, @-r15
mov.l datareg, r1 !serial screen data register (Its a parallel bus, I think, why did I name it that?)
mov r5, r2
yloop:
xloop:
    mov.w @r4+, r0
    mov.w r0, @r1
    synco
    dt r5
    bf xloop
    mov r2, r5
    dt r6
    bf yloop
    lds.l @r15+, PR
    rts
    nop

.align 4
datareg:
    .long 0xb4000000
