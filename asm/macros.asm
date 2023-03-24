// Control Macros

macro intro_text(TEXT) {
    table "tbl/intro.tbl"
    db {TEXT}
    db $00
    break_line()
}

macro end() {
    db ENDSTRING
}
macro break_line() {
    dw BREAKLINE
}
macro new_page() {
    db NEWPAGE
}
macro align() {
    db NULL
}