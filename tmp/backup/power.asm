
// ; Definitions
arch    md.cpu
endian  msb

// ; Patched Output
output  "bin/Mighty Morphin Power Rangers - BR.bin",create

// ; Configuration
constant CONFIG_LANGUAGE(PORTUGUESE)

define   CONFIG_ROM_NAME("POWER RANGERS 2                                 ")
define   CONFIG_ROM_REGION("U")
define   CONFIG_ROM_SIZE(eof)


origin ROM_START
    // ; Original File
    insert "bin/Mighty Morphin Power Rangers - The Movie (U) [!].bin"
    
    // ; Includes
    include "asm/macros.asm"
    include "asm/constants.asm"

if (CONFIG_LANGUAGE == ENGLISH) {

    include "text/en/intro.asm"
   
}


if (CONFIG_LANGUAGE == PORTUGUESE) {

    define   CONFIG_ROM_NAME("TESTE 2")
    define   CONFIG_ROM_REGION("U")

    
    include "text/br/intro.asm"
    
   
}

include "asm/pointers.asm"

origin $00000150
    db {CONFIG_ROM_NAME}

origin $000001A4
    dl {CONFIG_ROM_SIZE}

origin $000001F0
    db {CONFIG_ROM_REGION}

    define CONFIG_ROM_SIZE(pc())


eof:
