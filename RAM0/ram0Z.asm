;; RAM0


;;RAM0 memory from 49152 to 65535
;;16383 bytes total

;;The ULA bug which causes snow when I is set to point to contended memory still occurs, and also appears to crash the machine shortly after I is set to point to contended memory.
;;This means ISR CANNOT BE IN CONTENDED MEMORY!!!

;;__fastcall__ fastcall
;; Fastcall linkage allows one parameter
;; to be passed by register in a subset of DEHL.
;; So if the parameter is 8-bit, the value will
;; be in L.  If the parameter is 16-bit,
;; the value is in HL and if it is
;; 32-bit the value is in DEHL.

;; On the Spectrum 128, interrupt vectors may only
;; be placed between $80ff and $beff inclusive.
;; An interrupt routing itself must exist wholly
;; between 4000 and $BFFF.
;; This is because address $c000 to $ffff are pageabe
;; and should an interrupt occur while the
;; wrong 16k RAM is paged in, you will get a crash.

SECTION BANK_00

include "plot.asm"

	PUBLIC _Variable_in_RAM0
	_Variable_in_RAM0:
    defb 0


PLOT_X_PositionBits: defb $80,$40,$20,$10,$08,$04,$02,$01

PUBLIC _gfx_xy
_gfx_xy:
defw 0

PUBLIC _gfx_x
_gfx_x:
defb 00

PUBLIC _gfx_y
_gfx_y:
defb 00


;http://www.overtakenbyevents.com/lets-talk-about-the-zx-specrum-screen-layout/
;David Black
;need to improve
PUBLIC _set_attributes
_set_attributes:
;$5800 - $5AFF  $2FF long
    ld a, %00001110         ;FBPPPIII  %00110001  %00 110 001
    ld hl, $5800
    ld (hl), a

    ld de, $5801
    ld bc, $2ff
    ldir
ret


PUBLIC _rtunes_pixel
_rtunes_pixel:

    ;ld de, (_gfx_xy)  ;20 T
    ld a, (_gfx_y)
    ld d, a
    ld a, (_gfx_x)
    ld e, a



    ;;;;;;

    ld a, d  ;4 T
    and a  ;4 T
    rra  ;4 T
    scf  ;4 T
    rra  ;4 T
    and a  ;4 T
    rra  ;4 T
    xor d  ;4 T
    and 11111000b  ;7 T

    xor d  ;4 T
    ld h, a  ;4 T
    ld a, e  ;4 T
    rlca  ;4 T
    rlca  ;4 T
    rlca  ;4 T
    xor d  ;4 T
    and 11000111b  ;7 T
    xor d  ;4 T
    rlca  ;4 T
    rlca  ;4 T
    ld l, a  ;4 T

    ld a, e  ;4 T
    and $07

    ;LD D, A				;4 T

    ld de, PLOT_X_PositionBits  ;10T
    add a, e  ;4 T
    ld e, a  ;4 T
    ld a, (de)  ;7 T

    ;output to screen
    or (hl)  ;7 T
    ld (hl), a  ;7 T
ret						;10 T



PUBLIC _rtunes_pixel2
_rtunes_pixel2:

    ld de, (_gfx_xy)  ;20 T

    ld a, d  ;4 T
    and a  ;4 T
    rra  ;4 T
    scf  ;4 T
    rra  ;4 T
    and a  ;4 T
    rra  ;4 T
    xor d  ;4 T
    and 11111000b  ;7 T

    xor d  ;4 T
    ld h, a  ;4 T
    ld a, e  ;4 T
    rlca  ;4 T
    rlca  ;4 T
    rlca  ;4 T
    xor d  ;4 T
    and 11000111b  ;7 T
    xor d  ;4 T
    rlca  ;4 T
    rlca  ;4 T
    ld l, a  ;4 T

    ld a, e  ;4 T
    and $07

    ;LD D, A				;4 T

    ld de, PLOT_X_PositionBits  ;10T
    add a, e  ;4 T
    ld e, a  ;4 T
    ld a, (de)  ;7 T

    ;output to screen
    or (hl)  ;7 T
    ld (hl), a  ;7 T
ret						;10 T









