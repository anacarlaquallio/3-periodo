	.data  # 0x10010000
X:	.word 3
Y:	.word 2
Z:	.word 4
							
	.text  # 0x00400000
	.globl main 
	
main:	la $t0,X	   # carrega o endereço (load address) do rotulo X para o registrador $t0
	la $t1,Y	   # carrega o endereço (load address) do rotulo Y para o registrador $t1
	la $t2,Z	   # carrega o endereço (load address) do rotulo Y para o registrador $t2
	
	# Agora, podemos usar esse endereço para carregar da memoria (load word) X para um registrador
	lw $s0, 0($t0)	# registrador temporario $s0 = X
	
	# Agora, podemos usar esse endereço para carregar da memoria (load word) Y para um registrador
	lw $s1, 0($t1)	# registrador temporario $s1 = Y
	
	# Agora, podemos usar esse endereço para carregar da memoria (load word) Z para um registrador
	lw $s2, 0($t2)	# registrador temporario $s2 = Z
	
	add $s3,$s0,$s1	# registrador temporario $s3 = $s0+$s1 (X+Y)
	sub $s1,$s3,$s2 # registrador temporario $s1 = $s3+$s2 [Y=(X+Y)-Z]
	
	# Agora, podemos armazenar na memoria (store word) o registrador Y
	sw $s1, 0($t1)	# endereco de memoria Y = $s1
Exit:
	
