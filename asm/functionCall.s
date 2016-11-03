
./functionCall:     file format elf64-x86-64


Disassembly of section .init:

0000000000400390 <_init>:
  400390:	48 83 ec 08          	sub    rsp,0x8
  400394:	48 8b 05 5d 0c 20 00 	mov    rax,QWORD PTR [rip+0x200c5d]        # 600ff8 <_DYNAMIC+0x1d0>
  40039b:	48 85 c0             	test   rax,rax
  40039e:	74 05                	je     4003a5 <_init+0x15>
  4003a0:	e8 2b 00 00 00       	call   4003d0 <__libc_start_main@plt+0x10>
  4003a5:	48 83 c4 08          	add    rsp,0x8
  4003a9:	c3                   	ret    

Disassembly of section .plt:

00000000004003b0 <__libc_start_main@plt-0x10>:
  4003b0:	ff 35 52 0c 20 00    	push   QWORD PTR [rip+0x200c52]        # 601008 <_GLOBAL_OFFSET_TABLE_+0x8>
  4003b6:	ff 25 54 0c 20 00    	jmp    QWORD PTR [rip+0x200c54]        # 601010 <_GLOBAL_OFFSET_TABLE_+0x10>
  4003bc:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]

00000000004003c0 <__libc_start_main@plt>:
  4003c0:	ff 25 52 0c 20 00    	jmp    QWORD PTR [rip+0x200c52]        # 601018 <_GLOBAL_OFFSET_TABLE_+0x18>
  4003c6:	68 00 00 00 00       	push   0x0
  4003cb:	e9 e0 ff ff ff       	jmp    4003b0 <_init+0x20>

Disassembly of section .plt.got:

00000000004003d0 <.plt.got>:
  4003d0:	ff 25 22 0c 20 00    	jmp    QWORD PTR [rip+0x200c22]        # 600ff8 <_DYNAMIC+0x1d0>
  4003d6:	66 90                	xchg   ax,ax

Disassembly of section .text:

00000000004003e0 <_start>:
  4003e0:	31 ed                	xor    ebp,ebp
  4003e2:	49 89 d1             	mov    r9,rdx
  4003e5:	5e                   	pop    rsi
  4003e6:	48 89 e2             	mov    rdx,rsp
  4003e9:	48 83 e4 f0          	and    rsp,0xfffffffffffffff0
  4003ed:	50                   	push   rax
  4003ee:	54                   	push   rsp
  4003ef:	49 c7 c0 d0 05 40 00 	mov    r8,0x4005d0
  4003f6:	48 c7 c1 60 05 40 00 	mov    rcx,0x400560
  4003fd:	48 c7 c7 2a 05 40 00 	mov    rdi,0x40052a
  400404:	e8 b7 ff ff ff       	call   4003c0 <__libc_start_main@plt>
  400409:	f4                   	hlt    
  40040a:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]

0000000000400410 <deregister_tm_clones>:
  400410:	b8 37 10 60 00       	mov    eax,0x601037
  400415:	55                   	push   rbp
  400416:	48 2d 30 10 60 00    	sub    rax,0x601030
  40041c:	48 83 f8 0e          	cmp    rax,0xe
  400420:	48 89 e5             	mov    rbp,rsp
  400423:	76 1b                	jbe    400440 <deregister_tm_clones+0x30>
  400425:	b8 00 00 00 00       	mov    eax,0x0
  40042a:	48 85 c0             	test   rax,rax
  40042d:	74 11                	je     400440 <deregister_tm_clones+0x30>
  40042f:	5d                   	pop    rbp
  400430:	bf 30 10 60 00       	mov    edi,0x601030
  400435:	ff e0                	jmp    rax
  400437:	66 0f 1f 84 00 00 00 	nop    WORD PTR [rax+rax*1+0x0]
  40043e:	00 00 
  400440:	5d                   	pop    rbp
  400441:	c3                   	ret    
  400442:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]
  400446:	66 2e 0f 1f 84 00 00 	nop    WORD PTR cs:[rax+rax*1+0x0]
  40044d:	00 00 00 

0000000000400450 <register_tm_clones>:
  400450:	be 30 10 60 00       	mov    esi,0x601030
  400455:	55                   	push   rbp
  400456:	48 81 ee 30 10 60 00 	sub    rsi,0x601030
  40045d:	48 c1 fe 03          	sar    rsi,0x3
  400461:	48 89 e5             	mov    rbp,rsp
  400464:	48 89 f0             	mov    rax,rsi
  400467:	48 c1 e8 3f          	shr    rax,0x3f
  40046b:	48 01 c6             	add    rsi,rax
  40046e:	48 d1 fe             	sar    rsi,1
  400471:	74 15                	je     400488 <register_tm_clones+0x38>
  400473:	b8 00 00 00 00       	mov    eax,0x0
  400478:	48 85 c0             	test   rax,rax
  40047b:	74 0b                	je     400488 <register_tm_clones+0x38>
  40047d:	5d                   	pop    rbp
  40047e:	bf 30 10 60 00       	mov    edi,0x601030
  400483:	ff e0                	jmp    rax
  400485:	0f 1f 00             	nop    DWORD PTR [rax]
  400488:	5d                   	pop    rbp
  400489:	c3                   	ret    
  40048a:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]

0000000000400490 <__do_global_dtors_aux>:
  400490:	80 3d 99 0b 20 00 00 	cmp    BYTE PTR [rip+0x200b99],0x0        # 601030 <__TMC_END__>
  400497:	75 11                	jne    4004aa <__do_global_dtors_aux+0x1a>
  400499:	55                   	push   rbp
  40049a:	48 89 e5             	mov    rbp,rsp
  40049d:	e8 6e ff ff ff       	call   400410 <deregister_tm_clones>
  4004a2:	5d                   	pop    rbp
  4004a3:	c6 05 86 0b 20 00 01 	mov    BYTE PTR [rip+0x200b86],0x1        # 601030 <__TMC_END__>
  4004aa:	f3 c3                	repz ret 
  4004ac:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]

00000000004004b0 <frame_dummy>:
  4004b0:	bf 20 0e 60 00       	mov    edi,0x600e20
  4004b5:	48 83 3f 00          	cmp    QWORD PTR [rdi],0x0
  4004b9:	75 05                	jne    4004c0 <frame_dummy+0x10>
  4004bb:	eb 93                	jmp    400450 <register_tm_clones>
  4004bd:	0f 1f 00             	nop    DWORD PTR [rax]
  4004c0:	b8 00 00 00 00       	mov    eax,0x0
  4004c5:	48 85 c0             	test   rax,rax
  4004c8:	74 f1                	je     4004bb <frame_dummy+0xb>
  4004ca:	55                   	push   rbp
  4004cb:	48 89 e5             	mov    rbp,rsp
  4004ce:	ff d0                	call   rax
  4004d0:	5d                   	pop    rbp
  4004d1:	e9 7a ff ff ff       	jmp    400450 <register_tm_clones>

00000000004004d6 <function(int, int, int, int, int, int, int)>:
	int i3,
	int i4,
	int i5,
	int i6,
	int i7
){
  4004d6:	55                   	push   rbp
  4004d7:	48 89 e5             	mov    rbp,rsp
  4004da:	89 7d ec             	mov    DWORD PTR [rbp-0x14],edi
  4004dd:	89 75 e8             	mov    DWORD PTR [rbp-0x18],esi
  4004e0:	89 55 e4             	mov    DWORD PTR [rbp-0x1c],edx
  4004e3:	89 4d e0             	mov    DWORD PTR [rbp-0x20],ecx
  4004e6:	44 89 45 dc          	mov    DWORD PTR [rbp-0x24],r8d
  4004ea:	44 89 4d d8          	mov    DWORD PTR [rbp-0x28],r9d
	int local = 0;
  4004ee:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [rbp-0x4],0x0

	local += i1;
  4004f5:	8b 45 ec             	mov    eax,DWORD PTR [rbp-0x14]
  4004f8:	01 45 fc             	add    DWORD PTR [rbp-0x4],eax

	local -= i2;
  4004fb:	8b 45 e8             	mov    eax,DWORD PTR [rbp-0x18]
  4004fe:	29 45 fc             	sub    DWORD PTR [rbp-0x4],eax

	local *= i3;
  400501:	8b 45 fc             	mov    eax,DWORD PTR [rbp-0x4]
  400504:	0f af 45 e4          	imul   eax,DWORD PTR [rbp-0x1c]
  400508:	89 45 fc             	mov    DWORD PTR [rbp-0x4],eax

	local /= i4;
  40050b:	8b 45 fc             	mov    eax,DWORD PTR [rbp-0x4]
  40050e:	99                   	cdq    
  40050f:	f7 7d e0             	idiv   DWORD PTR [rbp-0x20]
  400512:	89 45 fc             	mov    DWORD PTR [rbp-0x4],eax

	local <<= i5;
  400515:	8b 45 dc             	mov    eax,DWORD PTR [rbp-0x24]
  400518:	89 c1                	mov    ecx,eax
  40051a:	d3 65 fc             	shl    DWORD PTR [rbp-0x4],cl

	local >>= i6;
  40051d:	8b 45 d8             	mov    eax,DWORD PTR [rbp-0x28]
  400520:	89 c1                	mov    ecx,eax
  400522:	d3 7d fc             	sar    DWORD PTR [rbp-0x4],cl

	return local;
  400525:	8b 45 fc             	mov    eax,DWORD PTR [rbp-0x4]
}
  400528:	5d                   	pop    rbp
  400529:	c3                   	ret    

000000000040052a <main>:

int main(){
  40052a:	55                   	push   rbp
  40052b:	48 89 e5             	mov    rbp,rsp
	function(1, 2, 3, 4, 5, 6, 7);
  40052e:	6a 07                	push   0x7
  400530:	41 b9 06 00 00 00    	mov    r9d,0x6
  400536:	41 b8 05 00 00 00    	mov    r8d,0x5
  40053c:	b9 04 00 00 00       	mov    ecx,0x4
  400541:	ba 03 00 00 00       	mov    edx,0x3
  400546:	be 02 00 00 00       	mov    esi,0x2
  40054b:	bf 01 00 00 00       	mov    edi,0x1
  400550:	e8 81 ff ff ff       	call   4004d6 <function(int, int, int, int, int, int, int)>
  400555:	48 83 c4 08          	add    rsp,0x8
}
  400559:	b8 00 00 00 00       	mov    eax,0x0
  40055e:	c9                   	leave  
  40055f:	c3                   	ret    

0000000000400560 <__libc_csu_init>:
  400560:	41 57                	push   r15
  400562:	41 56                	push   r14
  400564:	41 89 ff             	mov    r15d,edi
  400567:	41 55                	push   r13
  400569:	41 54                	push   r12
  40056b:	4c 8d 25 9e 08 20 00 	lea    r12,[rip+0x20089e]        # 600e10 <__frame_dummy_init_array_entry>
  400572:	55                   	push   rbp
  400573:	48 8d 2d 9e 08 20 00 	lea    rbp,[rip+0x20089e]        # 600e18 <__init_array_end>
  40057a:	53                   	push   rbx
  40057b:	49 89 f6             	mov    r14,rsi
  40057e:	49 89 d5             	mov    r13,rdx
  400581:	4c 29 e5             	sub    rbp,r12
  400584:	48 83 ec 08          	sub    rsp,0x8
  400588:	48 c1 fd 03          	sar    rbp,0x3
  40058c:	e8 ff fd ff ff       	call   400390 <_init>
  400591:	48 85 ed             	test   rbp,rbp
  400594:	74 20                	je     4005b6 <__libc_csu_init+0x56>
  400596:	31 db                	xor    ebx,ebx
  400598:	0f 1f 84 00 00 00 00 	nop    DWORD PTR [rax+rax*1+0x0]
  40059f:	00 
  4005a0:	4c 89 ea             	mov    rdx,r13
  4005a3:	4c 89 f6             	mov    rsi,r14
  4005a6:	44 89 ff             	mov    edi,r15d
  4005a9:	41 ff 14 dc          	call   QWORD PTR [r12+rbx*8]
  4005ad:	48 83 c3 01          	add    rbx,0x1
  4005b1:	48 39 eb             	cmp    rbx,rbp
  4005b4:	75 ea                	jne    4005a0 <__libc_csu_init+0x40>
  4005b6:	48 83 c4 08          	add    rsp,0x8
  4005ba:	5b                   	pop    rbx
  4005bb:	5d                   	pop    rbp
  4005bc:	41 5c                	pop    r12
  4005be:	41 5d                	pop    r13
  4005c0:	41 5e                	pop    r14
  4005c2:	41 5f                	pop    r15
  4005c4:	c3                   	ret    
  4005c5:	90                   	nop
  4005c6:	66 2e 0f 1f 84 00 00 	nop    WORD PTR cs:[rax+rax*1+0x0]
  4005cd:	00 00 00 

00000000004005d0 <__libc_csu_fini>:
  4005d0:	f3 c3                	repz ret 

Disassembly of section .fini:

00000000004005d4 <_fini>:
  4005d4:	48 83 ec 08          	sub    rsp,0x8
  4005d8:	48 83 c4 08          	add    rsp,0x8
  4005dc:	c3                   	ret    
