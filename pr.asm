arch    md.cpu
endian  msb

output  "pr_br.gen",create
insert  "pr.gen"

constant VDP_DATA($C00000)
constant VDP_CTRL($C00004)
constant ORIGINAL_FONT($1B8000)
constant NEMESIS_DECOMPRESSOR($3A1A)
constant PRESS_START_TEXT($1E82D4)

macro save_registers_to_sp() {
    movem.l #$FFFF,-(a7)
}

macro load_registers_from_sp() {
    movem.l (a7)+,#$FFFF
}

origin $026AE8
    jmp     font_16x16_hack

origin $026186
    jmp     revert_font16x16_hack

origin $1FF000
font_16x16_hack:
    save_registers_to_sp()
    move.l  #$6D600002,(VDP_CTRL).l
    lea     (font_16x16).l,a0
    jsr     (NEMESIS_DECOMPRESSOR).l
    load_registers_from_sp()

_load_chars_to_tilemap:
    move.l  d4,(VDP_CTRL).l
    move.w  (a0)+,d6
    cmp     #$E56B,d6
    beq     ++
    cmp     #$E5A0,d6
    bge     +
    cmp     #$E586,d6
    bge     ++
+
    cmp     #$E5B0,d6
    bge     +
    move.w  d6,(VDP_DATA).l
    cmp     #$E5A0,d6
    bge     ++
    add.w   #$1A,d6
+
    swap    d4
    add.w   #$80,d4
    swap    d4
    move.l  d4,(VDP_CTRL).l
    move.w  d6,(VDP_DATA).l
    swap    d4
    sub.w   #$80,d4
    swap    d4
+
    swap    d4
    add.w   #$02,d4
    swap    d4
    dbf     d7,_load_chars_to_tilemap
    clr.l   d6
    jmp     ($026AF2).l

revert_font16x16_hack:
    save_registers_to_sp()
    move.l  #$6D600002,(VDP_CTRL).l
    lea     (ORIGINAL_FONT).l,a0
    jsr     (NEMESIS_DECOMPRESSOR).l
    load_registers_from_sp()
    lea     (PRESS_START_TEXT).l,a6
    jmp     ($02618C).l

origin $1F6840
insert font_16x16,"gfx/fonte_16x16.nemesis.smd"