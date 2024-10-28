# This line is a comment
  .text
  .globl entry
entry:
  li t0, 1
  jal ra, recipe
  j .

recipe:
  addi t0, t0, 1
  jr ra
