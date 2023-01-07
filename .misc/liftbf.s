	.file	"liftbf.c"
	.text
	.p2align 4
	.globl	cost
	.type	cost, @function
cost:
.LFB22:
	.cfi_startproc
	pushq	%r14
	.cfi_def_cfa_offset 16
	.cfi_offset 14, -16
	pushq	%r13
	.cfi_def_cfa_offset 24
	.cfi_offset 13, -24
	pushq	%r12
	.cfi_def_cfa_offset 32
	.cfi_offset 12, -32
	pushq	%rbp
	.cfi_def_cfa_offset 40
	.cfi_offset 6, -40
	movl	(%rdi), %ebp
	pushq	%rbx
	.cfi_def_cfa_offset 48
	.cfi_offset 3, -48
	movl	%esi, %ebx
	testl	%ebp, %ebp
	jne	.L12
	movl	$1, %eax
	.p2align 4,,10
	.p2align 3
.L3:
	movq	%rax, %r11
	addq	$1, %rax
	movl	-4(%rdi,%rax,4), %esi
	testl	%esi, %esi
	je	.L3
	testl	%ecx, %ecx
	jle	.L13
.L22:
	movslq	%ebx, %rax
	movl	%ebx, %r9d
	movslq	%ecx, %rcx
	xorl	%r8d, %r8d
	movl	-4(%rdi,%rax,4), %r10d
	subl	%r11d, %r9d
	movslq	%r11d, %rax
	leaq	(%rdx,%rcx,4), %r12
	addq	%rax, %r9
	leaq	0(,%rax,4), %r13
	salq	$2, %r9
	jmp	.L11
	.p2align 4,,10
	.p2align 3
.L7:
	cmpl	%ecx, %eax
	cmovle	%eax, %ecx
.L20:
	addq	$4, %rdx
	addl	%ecx, %r8d
	cmpq	%rdx, %r12
	je	.L1
.L11:
	movl	(%rdx), %eax
	movl	%eax, %ecx
	subl	%r10d, %ecx
	jns	.L20
	movl	%ebp, %ecx
	subl	%eax, %ecx
	jns	.L7
	movq	%r13, %rcx
	cmpl	%r11d, %ebx
	jg	.L8
	jmp	.L9
	.p2align 4,,10
	.p2align 3
.L10:
	addq	$4, %rcx
	cmpq	%rcx, %r9
	je	.L9
.L8:
	movl	(%rdi,%rcx), %esi
	cmpl	%esi, %eax
	jg	.L10
	subl	%eax, %esi
	movl	%eax, %r14d
	subl	-4(%rdi,%rcx), %r14d
	cmpl	%eax, %esi
	cmovg	%eax, %esi
	cmpl	%esi, %r14d
	movl	%esi, %eax
	cmovle	%r14d, %eax
.L9:
	addq	$4, %rdx
	addl	%eax, %r8d
	cmpq	%rdx, %r12
	jne	.L11
.L1:
	popq	%rbx
	.cfi_remember_state
	.cfi_def_cfa_offset 40
	movl	%r8d, %eax
	popq	%rbp
	.cfi_def_cfa_offset 32
	popq	%r12
	.cfi_def_cfa_offset 24
	popq	%r13
	.cfi_def_cfa_offset 16
	popq	%r14
	.cfi_def_cfa_offset 8
	ret
.L12:
	.cfi_restore_state
	xorl	%r11d, %r11d
	testl	%ecx, %ecx
	jg	.L22
.L13:
	xorl	%r8d, %r8d
	popq	%rbx
	.cfi_def_cfa_offset 40
	popq	%rbp
	.cfi_def_cfa_offset 32
	movl	%r8d, %eax
	popq	%r12
	.cfi_def_cfa_offset 24
	popq	%r13
	.cfi_def_cfa_offset 16
	popq	%r14
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE22:
	.size	cost, .-cost
	.p2align 4
	.globl	generate_next
	.type	generate_next, @function
generate_next:
.LFB23:
	.cfi_startproc
	movl	%esi, %eax
	movq	%rdi, %r9
	movl	%esi, %r8d
	subl	$1, %eax
	js	.L30
	movslq	%eax, %rcx
	leaq	(%rdi,%rcx,4), %rcx
	leal	1(%rdx), %edi
	subl	%esi, %edi
	jmp	.L29
	.p2align 4,,10
	.p2align 3
.L25:
	subl	$1, %eax
	subq	$4, %rcx
	cmpl	$-1, %eax
	je	.L30
.L29:
	movl	(%rcx), %edx
	leal	(%rdi,%rax), %esi
	cmpl	%esi, %edx
	je	.L25
	addl	$1, %edx
	movl	%edx, (%rcx)
	leal	1(%rax), %edx
	cmpl	%edx, %r8d
	jle	.L28
	cltq
	movl	(%r9,%rax,4), %ecx
	movslq	%edx, %rax
	.p2align 4,,10
	.p2align 3
.L27:
	addl	$1, %ecx
	movl	%ecx, (%r9,%rax,4)
	addq	$1, %rax
	cmpl	%eax, %r8d
	jg	.L27
.L28:
	movl	$1, %eax
	ret
	.p2align 4,,10
	.p2align 3
.L30:
	xorl	%eax, %eax
	ret
	.cfi_endproc
.LFE23:
	.size	generate_next, .-generate_next
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"No lift stops"
.LC1:
	.string	"Lift stops are:"
.LC2:
	.string	" %d"
.LC3:
	.string	" %d\n"
	.text
	.p2align 4
	.globl	solve
	.type	solve, @function
solve:
.LFB24:
	.cfi_startproc
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	movslq	%esi, %rax
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	leaq	0(,%rax,4), %r15
	movq	%rdx, %r14
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	movl	%edi, %r13d
	movq	%r15, %rdi
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	movq	%rax, %rbx
	subq	$40, %rsp
	.cfi_def_cfa_offset 96
	movq	%r15, 16(%rsp)
	call	malloc@PLT
	movq	%r15, %rdi
	movq	%rax, %r12
	call	malloc@PLT
	movq	%rax, 8(%rsp)
	testl	%ebx, %ebx
	jle	.L34
	movl	%ebx, %ebp
	movq	%rax, %r15
	xorl	%esi, %esi
	movq	%r12, %rdi
	salq	$2, %rbp
	movq	%rbp, %rdx
	call	memset@PLT
	movq	%rbp, %rdx
	xorl	%esi, %esi
	movq	%r15, %rdi
	call	memset@PLT
.L34:
	testl	%r13d, %r13d
	jle	.L46
	movslq	%r13d, %rdx
	movq	%r14, %rax
	xorl	%ebp, %ebp
	leaq	(%r14,%rdx,4), %rcx
	.p2align 4,,10
	.p2align 3
.L36:
	movl	(%rax), %edx
	cmpl	%edx, %ebp
	cmovl	%edx, %ebp
	addq	$4, %rax
	cmpq	%rcx, %rax
	jne	.L36
.L35:
	movl	%r13d, %ecx
	movq	%r14, %rdx
	movl	%ebx, %esi
	movq	%r12, %rdi
	call	cost
	movl	%eax, %r15d
	jmp	.L38
	.p2align 4,,10
	.p2align 3
.L40:
	movl	%r13d, %ecx
	movq	%r14, %rdx
	movl	%ebx, %esi
	movq	%r12, %rdi
	call	cost
	movl	%eax, %ecx
	cmpl	%eax, %r15d
	jg	.L54
.L38:
	movl	%ebp, %edx
	movl	%ebx, %esi
	movq	%r12, %rdi
	call	generate_next
	testl	%eax, %eax
	jne	.L40
	movq	8(%rsp), %rax
	movq	16(%rsp), %rdi
	movl	-4(%rax,%rdi), %r13d
	testl	%r13d, %r13d
	jne	.L41
	leaq	.LC0(%rip), %rdi
	call	puts@PLT
.L42:
	movq	%r12, %rdi
	call	free@PLT
	movq	8(%rsp), %rdi
	call	free@PLT
	addq	$40, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	movl	%r15d, %eax
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L54:
	.cfi_restore_state
	testl	%ebx, %ebx
	jle	.L39
	movq	8(%rsp), %rdi
	movl	%ebx, %edx
	movq	%r12, %rsi
	movl	%eax, 28(%rsp)
	salq	$2, %rdx
	call	memcpy@PLT
	movl	28(%rsp), %ecx
.L39:
	movl	%ecx, %r15d
	jmp	.L38
	.p2align 4,,10
	.p2align 3
.L41:
	xorl	%eax, %eax
	leaq	.LC1(%rip), %rdi
	call	printf@PLT
	cmpl	$1, %ebx
	jle	.L43
	movq	8(%rsp), %rsi
	leal	-1(%rbx), %eax
	leaq	.LC2(%rip), %rbx
	movq	%rsi, %rbp
	leaq	(%rsi,%rax,4), %r14
	jmp	.L45
	.p2align 4,,10
	.p2align 3
.L44:
	addq	$4, %rbp
	cmpq	%rbp, %r14
	je	.L43
.L45:
	movl	0(%rbp), %esi
	testl	%esi, %esi
	je	.L44
	movq	%rbx, %rdi
	xorl	%eax, %eax
	addq	$4, %rbp
	call	printf@PLT
	cmpq	%rbp, %r14
	jne	.L45
.L43:
	movl	%r13d, %esi
	leaq	.LC3(%rip), %rdi
	xorl	%eax, %eax
	call	printf@PLT
	jmp	.L42
.L46:
	xorl	%ebp, %ebp
	jmp	.L35
	.cfi_endproc
.LFE24:
	.size	solve, .-solve
	.ident	"GCC: (GNU) 12.2.0"
	.section	.note.GNU-stack,"",@progbits
