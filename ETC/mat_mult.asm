	.data
matA:	.word	3, 4, 5, 6, 2, 1, 3, 0, 7, 8, 7, 2, 0, 1, 9, 5, 8, 3, 6, 1
	.align	2
matB:	.word	1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3
	.align	2
matC:	.space	60	# 3*5*4
	.text
	
	# for (int i = 0; i < 5; i++) {
	li	$t0, 0	# i
loop1:	bge	$t0, 5, loop1e
	#   for (int j = 0; j < 3; j++) {
	li	$t1, 0	# j
loop2:	bge	$t1, 3, loop2e
	#     int r = 0;
	li	$t2, 0	# r
	#     for (int k = 0; k < 4; k++) {
	li	$t3, 0	# k
loop3:	bge	$t3, 4, loop3e
	#       r = r + matA[i][k] * matB[k][j];
	mul	$t4, $t0, 4
	add	$t4, $t4, $t3
	mul	$t4, $t4, 4		# ((4*i) + k) * 4
	lw	$t5, matA($t4)		# matA[i][k]
	
	mul	$t4, $t3, 3
	add	$t4, $t4, $t1		
	mul	$t4, $t4, 4		# ((3*k) + j) * 4
	lw	$t6, matB($t4)		# matB[k][j]
	
	mul	$t7, $t5, $t6		# matA[i][k] * matB[k][j]
	add	$t2, $t2, $t7		# r += matA[i][k] * matB[k][j];
	#     }
	add	$t3, $t3, 1
	j	loop3
loop3e:
	#   matC[i][j] = r;
	mul	$t4, $t0, 4
	add	$t4, $t4, $t1
	sw	$t2, matC+4($t4)
	#   }
	add	$t1, $t1, 1
	j	loop2
loop2e:
	# }
	add	$t0, $t0, 1
	j	loop1
loop1e: