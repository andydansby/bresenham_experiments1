PUBLIC _gfx_xy
_gfx_xy:
defw 0000

;;;
X_PositionBits: defb 128,64,32,16,8,4,2,1
;;;

PUBLIC _FTFPlot
_FTFPlot:
    LD DE, (_gfx_xy)        ;20 T
;;total 20T

; calculate H
    LD A, D                 ;04 T

    RRA                     ;04 T   ; 0xxxxxxx
    SCF                     ;04 T   ; set carry flag
    RRA                     ;04 T   ; 10xxxxxx
    AND A                   ;04 T   ; clear carry flag
    RRA                     ;04 T   ; 010xxxxx

    XOR D                   ;04 T
    AND 11111000b           ;07 T   ; keep the top 5 bits 11111000b = $F8
    XOR D                   ;04 T   ; 010xxbbb
    LD H,A                  ;04 transfer high byte to H.
    ;;finished with H
    ;43 T total

    ; calculate L
    ; the low byte is derived from both X and Y.
    LD A, E                 ;04 T
    RLCA                    ;04 T
    RLCA                    ;04 T
    RLCA                    ;04 T
    XOR D                   ;04 T
    AND 11000111b           ;07 T     11000111b = 199
    XOR D                   ;04 T
    RLCA                    ;04 T
    RLCA                    ;04 T
    LD L, A                 ;04 T
    ;;finished with L
    ;;43T total

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; screen address is now in HL
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

    LD A, E                 ;04 T
    AND 00000111b           ;07 T
    ;;11T total

    LD DE, X_PositionBits  ;10T
    ADD A, E  ;4 T
    LD E, A  ;4 T
    LD A, (DE)  ;7 T

    ;output to screen
    OR (HL)  ;7 T
    LD (HL), A  ;7 T
RET


PUBLIC _POINT
_POINT:

_default_pixel_flag:
    ;make sure the _pixel_on_off variable is turned off
    ld hl, _pixel_on_off    ;10T
    xor a                   ;4T
    ld (hl), a              ;7T
    ;make sure the _pixel_on_off variable is turned off
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;xx = 128 = $80;
;yy = 96  = $60;
;de = $6080
_Pixel_Address:  ;$AD8F

    LD DE, (_gfx_xy)        ;20T
    LD      B, $07          ;7T frequently used mask (#07)
    LD      A,D             ;4T take Y-coordinate
    RRA                     ;4T divide it by 8
    SCF                     ;4T and start forming
    RRA                     ;4T high byte
    RRA                     ;4T pixel addresses
    AND     $5F             ;7T in the screen (register H):
    LD      H,A             ;4T %010yyyyy
    XOR     E               ;4T next we form
    AND     B               ;4T low byte
    XOR     E               ;4T addresses
    RRCA                    ;4T pixel
    RRCA                    ;4T on the screen
    RRCA                    ;4T (register L):
    LD      L,A             ;4T %yyyxxxxx
    LD      A,D             ;4T finish
    XOR     H               ;4T formation
    AND     B               ;4T high byte
    XOR     H               ;4T pixel addresses
    LD      H,A             ;4T in the screen (register H)
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; screen address is now in HL
; 139 t STATES
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

_POINTLP:
    LD      A,E             ;4T begin to form
    AND     B               ;4T pixel mask in byte
    LD      B,A             ;4T images (corresponding
    LD      A,10000000b           ;7T bit is on). Turn on the 7th bit
    JR      Z, _LP_PNT    ;12T if this is just what you need,

_LP_PNT:
  	RRCA                    ;4T then we jump over the shift
    DJNZ _LP_PNT     ;8T bit on right

_GO_PNT:
    LD      C,A             ;4T save the mask on. bit in reg. C
    AND     (HL)            ;7T check the pixel on the screen

_endPoint:
    jp z, _noPixel   ;10T
    ;jp nz, Kolotov_yesPixel ;10T
;;if Z is not set, fall thru
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; if Z flag is OFF, Pixel is at that location 1 4
; if Z flag is ON, there is not a pixel at that location 2 3

_yesPixel:
    ld a, 1                 ;7T
    ld hl, _pixel_on_off    ;10T
    ld (hl), a              ;7T
    ret                     ;10T

_noPixel:
    ld a, 0                 ;7T
    ld hl, _pixel_on_off    ;10T
    ld (hl), a              ;7T
    ret                     ;10T

;;220-223 T




PUBLIC _pixel_on_off
_pixel_on_off:
defb 0
