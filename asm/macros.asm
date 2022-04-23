// System Macros
macro save_registers_to_sp() {
    movem.l #$FFFF,-(a7)
}

macro load_registers_from_sp() {
    movem.l (a7)+,#$FFFF
}

// Control Macros
macro text(TEXT) {
    table "tbl/global.tbl"
    db {TEXT}
    end()
}
macro intro_text(TEXT) {
    table "tbl/global.tbl"
    db {TEXT}
    break_line()
}
macro menu_text(TEXT) {
    table "tbl/menus.tbl"
    db {TEXT}
    break_line()
}
macro menu_textspeed(TEXT) {
    table "tbl/menus.tbl"
    db {TEXT}
}
macro dialogue_text(TEXT) {
    table "tbl/global.tbl"
    db {TEXT}
    break_line()
}
macro end() {
    db ENDSTRING
}
macro break_line() {
    db BREAKLINE
}
macro new_page() {
    db NEWPAGE
}
macro align() {
    db NULL
}