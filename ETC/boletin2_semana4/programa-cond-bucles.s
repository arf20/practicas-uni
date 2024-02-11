	.data
	# const char *bimsg = "...";
bimsg:	.asciiz	"Introduce base> "
	# const char *eimsg = "...";
eimsg:	.asciiz "Introduce hasta que potencia calcular> "

	.text
	.globl main
main:	# int main() {
	#   printf(bimsg);
	li $v0, 4
	la $a0, bimsg
	syscall
	#   scanf("%d", $t0);
	li $v0, 5
	syscall
	move $t0, $v0
	#   printf(eimsg);
	li $v0, 4
	la $a0, eimsg
	syscall
	#   scanf("%d", $t1);
	li $v0, 5
	syscall
	move $t1, $v0
	#   compute_powers($t0, $t1);
	move $a0, $t0
	move $a1, $t1
	jal compute_powers
	# }
	li $v0, 10
        syscall

compute_powers:		# void compute_powers($a0 /* base */, $a1 /* end_power */) {
	move $t0, $a0
	move $t1, $a1
	li $t2, 0	# /* t2 iterator */
	li $t3, 1	# /* t3 current power */
loop:	# while (1) {
	#   printf("$t2 $t3\n");
	li $v0, 1
	move $a0, $t2
	syscall
	li $v0, 11
	li $a0, ' '
	syscall
	li $v0, 1
	move $a0, $t3
	syscall
	li $v0, 11
	li $a0, '\n'
	syscall
	#   if (iterator == end_power) return;
	beq $t2, $t1, end
	#   else { $t3 = $t3 * $t0; $t2++; }
	mul $t3, $t3, $t0
	add $t2, $t2, 1
	#   } 
	j loop
	# }
end:
	jr $ra
