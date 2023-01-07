	.file	"liftbf.c"
	.text
	.globl	cost
	.type	cost, @function
cost:
.LFB6:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -40(%rbp)
	movl	%esi, -44(%rbp)
	movq	%rdx, -56(%rbp)
	movl	%ecx, -48(%rbp)
	movl	$0, -24(%rbp)
	movl	$0, -20(%rbp)
	jmp	.L2
.L3:
	addl	$1, -20(%rbp)
.L2:
	movl	-20(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-40(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	testl	%eax, %eax
	je	.L3
	movl	$0, -16(%rbp)
	jmp	.L4
.L14:
	movl	-16(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-56(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %edx
	movl	-44(%rbp), %eax
	cltq
	salq	$2, %rax
	leaq	-4(%rax), %rcx
	movq	-40(%rbp), %rax
	addq	%rcx, %rax
	movl	(%rax), %eax
	subl	%eax, %edx
	movl	%edx, -4(%rbp)
	cmpl	$0, -4(%rbp)
	js	.L5
	movl	-4(%rbp), %eax
	addl	%eax, -24(%rbp)
	jmp	.L6
.L5:
	movl	-16(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-56(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	movl	%eax, -12(%rbp)
	movq	-40(%rbp), %rax
	movl	(%rax), %edx
	movl	-16(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rcx
	movq	-56(%rbp), %rax
	addq	%rcx, %rax
	movl	(%rax), %eax
	subl	%eax, %edx
	movl	%edx, -4(%rbp)
	cmpl	$0, -4(%rbp)
	js	.L7
	movl	-4(%rbp), %eax
	cmpl	-12(%rbp), %eax
	jge	.L8
	movl	-4(%rbp), %eax
	movl	%eax, -12(%rbp)
.L8:
	movl	-12(%rbp), %eax
	addl	%eax, -24(%rbp)
	jmp	.L6
.L7:
	movl	-20(%rbp), %eax
	movl	%eax, -8(%rbp)
	jmp	.L9
.L13:
	movl	-16(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-56(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %edx
	movl	-8(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rcx
	movq	-40(%rbp), %rax
	addq	%rcx, %rax
	movl	(%rax), %eax
	cmpl	%eax, %edx
	jg	.L10
	movl	-16(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-56(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %edx
	movl	-8(%rbp), %eax
	cltq
	salq	$2, %rax
	leaq	-4(%rax), %rcx
	movq	-40(%rbp), %rax
	addq	%rcx, %rax
	movl	(%rax), %eax
	subl	%eax, %edx
	movl	-8(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rcx
	movq	-40(%rbp), %rax
	addq	%rcx, %rax
	movl	(%rax), %eax
	movl	-16(%rbp), %ecx
	movslq	%ecx, %rcx
	leaq	0(,%rcx,4), %rsi
	movq	-56(%rbp), %rcx
	addq	%rsi, %rcx
	movl	(%rcx), %ecx
	subl	%ecx, %eax
	cmpl	%eax, %edx
	cmovle	%edx, %eax
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	cmpl	-12(%rbp), %eax
	jge	.L16
	movl	-4(%rbp), %eax
	movl	%eax, -12(%rbp)
	jmp	.L16
.L10:
	addl	$1, -8(%rbp)
.L9:
	movl	-8(%rbp), %eax
	cmpl	-44(%rbp), %eax
	jl	.L13
	jmp	.L12
.L16:
	nop
.L12:
	movl	-12(%rbp), %eax
	addl	%eax, -24(%rbp)
.L6:
	addl	$1, -16(%rbp)
.L4:
	movl	-16(%rbp), %eax
	cmpl	-48(%rbp), %eax
	jl	.L14
	movl	-24(%rbp), %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	cost, .-cost
	.globl	generate_next
	.type	generate_next, @function
generate_next:
.LFB7:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
	movl	%edx, -32(%rbp)
	movl	-28(%rbp), %eax
	subl	$1, %eax
	movl	%eax, -8(%rbp)
	jmp	.L18
.L23:
	movl	-8(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %edx
	movl	-32(%rbp), %ecx
	movl	-8(%rbp), %eax
	addl	%ecx, %eax
	subl	-28(%rbp), %eax
	addl	$1, %eax
	cmpl	%eax, %edx
	je	.L19
	movl	-8(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %edx
	addl	$1, %edx
	movl	%edx, (%rax)
	movl	-8(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -4(%rbp)
	jmp	.L20
.L21:
	movl	-4(%rbp), %eax
	cltq
	salq	$2, %rax
	leaq	-4(%rax), %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %edx
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rcx
	movq	-24(%rbp), %rax
	addq	%rcx, %rax
	addl	$1, %edx
	movl	%edx, (%rax)
	addl	$1, -4(%rbp)
.L20:
	movl	-4(%rbp), %eax
	cmpl	-28(%rbp), %eax
	jl	.L21
	movl	$1, %eax
	jmp	.L22
.L19:
	subl	$1, -8(%rbp)
.L18:
	cmpl	$0, -8(%rbp)
	jns	.L23
	movl	$0, %eax
.L22:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	generate_next, .-generate_next
	.section	.rodata
.LC0:
	.string	"No lift stops"
.LC1:
	.string	"Lift stops are:"
.LC2:
	.string	" %d"
.LC3:
	.string	" %d\n"
	.text
	.globl	solve
	.type	solve, @function
solve:
.LFB8:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	movl	%edi, -52(%rbp)
	movl	%esi, -56(%rbp)
	movq	%rdx, -64(%rbp)
	movl	-56(%rbp), %eax
	cltq
	salq	$2, %rax
	movq	%rax, %rdi
	call	malloc@PLT
	movq	%rax, -16(%rbp)
	movl	-56(%rbp), %eax
	cltq
	salq	$2, %rax
	movq	%rax, %rdi
	call	malloc@PLT
	movq	%rax, -8(%rbp)
	movl	$0, -44(%rbp)
	jmp	.L25
.L26:
	movl	-44(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-16(%rbp), %rax
	addq	%rdx, %rax
	movl	$0, (%rax)
	movl	-44(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-8(%rbp), %rax
	addq	%rdx, %rax
	movl	$0, (%rax)
	addl	$1, -44(%rbp)
.L25:
	movl	-44(%rbp), %eax
	cmpl	-56(%rbp), %eax
	jl	.L26
	movl	$0, -40(%rbp)
	movl	$0, -36(%rbp)
	jmp	.L27
.L29:
	movl	-36(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-64(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	cmpl	%eax, -40(%rbp)
	jge	.L28
	movl	-36(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-64(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	movl	%eax, -40(%rbp)
.L28:
	addl	$1, -36(%rbp)
.L27:
	movl	-36(%rbp), %eax
	cmpl	-52(%rbp), %eax
	jl	.L29
	movl	-52(%rbp), %ecx
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %esi
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	cost
	movl	%eax, -32(%rbp)
	jmp	.L31
.L34:
	movl	-52(%rbp), %ecx
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %esi
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	cost
	movl	%eax, -20(%rbp)
	movl	-20(%rbp), %eax
	cmpl	-32(%rbp), %eax
	jge	.L31
	movl	-20(%rbp), %eax
	movl	%eax, -32(%rbp)
	movl	$0, -28(%rbp)
	jmp	.L32
.L33:
	movl	-28(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-16(%rbp), %rax
	addq	%rdx, %rax
	movl	-28(%rbp), %edx
	movslq	%edx, %rdx
	leaq	0(,%rdx,4), %rcx
	movq	-8(%rbp), %rdx
	addq	%rcx, %rdx
	movl	(%rax), %eax
	movl	%eax, (%rdx)
	addl	$1, -28(%rbp)
.L32:
	movl	-28(%rbp), %eax
	cmpl	-56(%rbp), %eax
	jl	.L33
.L31:
	movl	-40(%rbp), %edx
	movl	-56(%rbp), %ecx
	movq	-16(%rbp), %rax
	movl	%ecx, %esi
	movq	%rax, %rdi
	call	generate_next
	testl	%eax, %eax
	jne	.L34
	movl	-56(%rbp), %eax
	cltq
	salq	$2, %rax
	leaq	-4(%rax), %rdx
	movq	-8(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	testl	%eax, %eax
	jne	.L35
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	jmp	.L36
.L35:
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, -24(%rbp)
	jmp	.L37
.L39:
	movl	-24(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-8(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	testl	%eax, %eax
	je	.L38
	movl	-24(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-8(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	movl	%eax, %esi
	leaq	.LC2(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
.L38:
	addl	$1, -24(%rbp)
.L37:
	movl	-56(%rbp), %eax
	subl	$1, %eax
	cmpl	%eax, -24(%rbp)
	jl	.L39
	movl	-56(%rbp), %eax
	cltq
	salq	$2, %rax
	leaq	-4(%rax), %rdx
	movq	-8(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	movl	%eax, %esi
	leaq	.LC3(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
.L36:
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	free@PLT
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	free@PLT
	movl	-32(%rbp), %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8:
	.size	solve, .-solve
	.ident	"GCC: (GNU) 12.2.0"
	.section	.note.GNU-stack,"",@progbits
