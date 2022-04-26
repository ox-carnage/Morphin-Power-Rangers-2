// System Macros
macro save_registers_to_sp() {
    movem.l #$FFFF,-(a7)
}

macro load_registers_from_sp() {
    movem.l (a7)+,#$FFFF
}

// Control Macros

macro intro_text(TEXT) {
    table "tbl/intro.tbl"
    db {TEXT}
    break_line()
}
macro end() {
    db ENDSTRING
}
macro break_line() {
    dl BREAKLINE
}
macro new_page() {
    db NEWPAGE
}
macro align() {
    db NULL
}