.include "p33FJMC202.inc"

.section    .text
.global     _start

_start:
; Initialize W0 with the first prime number
mov #2, W0
; Initialize the file register address
mov #0x800, W1

find_prime:
; Check if W0 is a prime number
call is_prime
; If W0 is prime, store it in the file register
bra NZ, next_number
mov W0, [W1]
; Increment the file register address
inc2 W1, W1

next_number:
; Increment the number to check
inc2 W0, W0
; Check if W0 exceeds 16-bit limit
cp #0xFFFF, W0
bra LE, find_prime

end:
; End of program
bra end

is_prime:
; Initialize W2 with 2 (first divisor)
mov #2, W2
; Initialize W3 with the square root of W0
sqrt W0, W3

check_divisor:
; Check if W0 is divisible by W2
mov W0, W4
div W2, W4
; If W0 is divisible by W2, it is not a prime number
cp #0, W5
bra Z, not_prime
; Increment the divisor
inc2 W2, W2
; Check if W2 exceeds the square root of W0
cp W3, W2
bra LE, check_divisor

; W0 is a prime number
return

not_prime:
; W0 is not a prime number
return NZ