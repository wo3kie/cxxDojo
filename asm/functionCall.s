
./functionCall:     file format elf64-x86-64


Disassembly of section .interp:

0000000000400238 <.interp>:
  400238:	2f                   	(bad)  
  400239:	6c                   	ins    BYTE PTR es:[rdi],dx
  40023a:	69 62 36 34 2f 6c 64 	imul   esp,DWORD PTR [rdx+0x36],0x646c2f34
  400241:	2d 6c 69 6e 75       	sub    eax,0x756e696c
  400246:	78 2d                	js     400275 <_init-0x11b>
  400248:	78 38                	js     400282 <_init-0x10e>
  40024a:	36 2d 36 34 2e 73    	ss sub eax,0x732e3436
  400250:	6f                   	outs   dx,DWORD PTR ds:[rsi]
  400251:	2e 32 00             	xor    al,BYTE PTR cs:[rax]

Disassembly of section .note.ABI-tag:

0000000000400254 <.note.ABI-tag>:
  400254:	04 00                	add    al,0x0
  400256:	00 00                	add    BYTE PTR [rax],al
  400258:	10 00                	adc    BYTE PTR [rax],al
  40025a:	00 00                	add    BYTE PTR [rax],al
  40025c:	01 00                	add    DWORD PTR [rax],eax
  40025e:	00 00                	add    BYTE PTR [rax],al
  400260:	47                   	rex.RXB
  400261:	4e 55                	rex.WRX push rbp
  400263:	00 00                	add    BYTE PTR [rax],al
  400265:	00 00                	add    BYTE PTR [rax],al
  400267:	00 02                	add    BYTE PTR [rdx],al
  400269:	00 00                	add    BYTE PTR [rax],al
  40026b:	00 06                	add    BYTE PTR [rsi],al
  40026d:	00 00                	add    BYTE PTR [rax],al
  40026f:	00 20                	add    BYTE PTR [rax],ah
  400271:	00 00                	add    BYTE PTR [rax],al
	...

Disassembly of section .note.gnu.build-id:

0000000000400274 <.note.gnu.build-id>:
  400274:	04 00                	add    al,0x0
  400276:	00 00                	add    BYTE PTR [rax],al
  400278:	14 00                	adc    al,0x0
  40027a:	00 00                	add    BYTE PTR [rax],al
  40027c:	03 00                	add    eax,DWORD PTR [rax]
  40027e:	00 00                	add    BYTE PTR [rax],al
  400280:	47                   	rex.RXB
  400281:	4e 55                	rex.WRX push rbp
  400283:	00 b1 e1 ce 1c 38    	add    BYTE PTR [rcx+0x381ccee1],dh
  400289:	79 43                	jns    4002ce <_init-0xc2>
  40028b:	0e                   	(bad)  
  40028c:	7f a7                	jg     400235 <_init-0x15b>
  40028e:	ae                   	scas   al,BYTE PTR es:[rdi]
  40028f:	ea                   	(bad)  
  400290:	08 fd                	or     ch,bh
  400292:	e7 bb                	out    0xbb,eax
  400294:	19 c7                	sbb    edi,eax
  400296:	7d 82                	jge    40021a <_init-0x176>

Disassembly of section .gnu.hash:

0000000000400298 <.gnu.hash>:
  400298:	01 00                	add    DWORD PTR [rax],eax
  40029a:	00 00                	add    BYTE PTR [rax],al
  40029c:	01 00                	add    DWORD PTR [rax],eax
  40029e:	00 00                	add    BYTE PTR [rax],al
  4002a0:	01 00                	add    DWORD PTR [rax],eax
	...

Disassembly of section .dynsym:

00000000004002b8 <.dynsym>:
	...
  4002d0:	0b 00                	or     eax,DWORD PTR [rax]
  4002d2:	00 00                	add    BYTE PTR [rax],al
  4002d4:	12 00                	adc    al,BYTE PTR [rax]
	...
  4002e6:	00 00                	add    BYTE PTR [rax],al
  4002e8:	1d 00 00 00 20       	sbb    eax,0x20000000
	...

Disassembly of section .dynstr:

0000000000400300 <.dynstr>:
  400300:	00 6c 69 62          	add    BYTE PTR [rcx+rbp*2+0x62],ch
  400304:	63 2e                	movsxd ebp,DWORD PTR [rsi]
  400306:	73 6f                	jae    400377 <_init-0x19>
  400308:	2e 36 00 5f 5f       	cs add BYTE PTR ss:[rdi+0x5f],bl
  40030d:	6c                   	ins    BYTE PTR es:[rdi],dx
  40030e:	69 62 63 5f 73 74 61 	imul   esp,DWORD PTR [rdx+0x63],0x6174735f
  400315:	72 74                	jb     40038b <_init-0x5>
  400317:	5f                   	pop    rdi
  400318:	6d                   	ins    DWORD PTR es:[rdi],dx
  400319:	61                   	(bad)  
  40031a:	69 6e 00 5f 5f 67 6d 	imul   ebp,DWORD PTR [rsi+0x0],0x6d675f5f
  400321:	6f                   	outs   dx,DWORD PTR ds:[rsi]
  400322:	6e                   	outs   dx,BYTE PTR ds:[rsi]
  400323:	5f                   	pop    rdi
  400324:	73 74                	jae    40039a <_init+0xa>
  400326:	61                   	(bad)  
  400327:	72 74                	jb     40039d <_init+0xd>
  400329:	5f                   	pop    rdi
  40032a:	5f                   	pop    rdi
  40032b:	00 47 4c             	add    BYTE PTR [rdi+0x4c],al
  40032e:	49                   	rex.WB
  40032f:	42                   	rex.X
  400330:	43 5f                	rex.XB pop r15
  400332:	32 2e                	xor    ch,BYTE PTR [rsi]
  400334:	32 2e                	xor    ch,BYTE PTR [rsi]
  400336:	35                   	.byte 0x35
	...

Disassembly of section .gnu.version:

0000000000400338 <.gnu.version>:
  400338:	00 00                	add    BYTE PTR [rax],al
  40033a:	02 00                	add    al,BYTE PTR [rax]
	...

Disassembly of section .gnu.version_r:

0000000000400340 <.gnu.version_r>:
  400340:	01 00                	add    DWORD PTR [rax],eax
  400342:	01 00                	add    DWORD PTR [rax],eax
  400344:	01 00                	add    DWORD PTR [rax],eax
  400346:	00 00                	add    BYTE PTR [rax],al
  400348:	10 00                	adc    BYTE PTR [rax],al
  40034a:	00 00                	add    BYTE PTR [rax],al
  40034c:	00 00                	add    BYTE PTR [rax],al
  40034e:	00 00                	add    BYTE PTR [rax],al
  400350:	75 1a                	jne    40036c <_init-0x24>
  400352:	69 09 00 00 02 00    	imul   ecx,DWORD PTR [rcx],0x20000
  400358:	2c 00                	sub    al,0x0
  40035a:	00 00                	add    BYTE PTR [rax],al
  40035c:	00 00                	add    BYTE PTR [rax],al
	...

Disassembly of section .rela.dyn:

0000000000400360 <.rela.dyn>:
  400360:	f8                   	clc    
  400361:	0f 60 00             	punpcklbw mm0,DWORD PTR [rax]
  400364:	00 00                	add    BYTE PTR [rax],al
  400366:	00 00                	add    BYTE PTR [rax],al
  400368:	06                   	(bad)  
  400369:	00 00                	add    BYTE PTR [rax],al
  40036b:	00 02                	add    BYTE PTR [rdx],al
	...

Disassembly of section .rela.plt:

0000000000400378 <.rela.plt>:
  400378:	18 10                	sbb    BYTE PTR [rax],dl
  40037a:	60                   	(bad)  
  40037b:	00 00                	add    BYTE PTR [rax],al
  40037d:	00 00                	add    BYTE PTR [rax],al
  40037f:	00 07                	add    BYTE PTR [rdi],al
  400381:	00 00                	add    BYTE PTR [rax],al
  400383:	00 01                	add    BYTE PTR [rcx],al
	...

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

Disassembly of section .rodata:

00000000004005e0 <_IO_stdin_used>:
  4005e0:	01 00                	add    DWORD PTR [rax],eax
  4005e2:	02 00                	add    al,BYTE PTR [rax]

Disassembly of section .eh_frame_hdr:

00000000004005e4 <__GNU_EH_FRAME_HDR>:
  4005e4:	01 1b                	add    DWORD PTR [rbx],ebx
  4005e6:	03 3b                	add    edi,DWORD PTR [rbx]
  4005e8:	38 00                	cmp    BYTE PTR [rax],al
  4005ea:	00 00                	add    BYTE PTR [rax],al
  4005ec:	06                   	(bad)  
  4005ed:	00 00                	add    BYTE PTR [rax],al
  4005ef:	00 cc                	add    ah,cl
  4005f1:	fd                   	std    
  4005f2:	ff                   	(bad)  
  4005f3:	ff 84 00 00 00 fc fd 	inc    DWORD PTR [rax+rax*1-0x2040000]
  4005fa:	ff                   	(bad)  
  4005fb:	ff 54 00 00          	call   QWORD PTR [rax+rax*1+0x0]
  4005ff:	00 f2                	add    dl,dh
  400601:	fe                   	(bad)  
  400602:	ff                   	(bad)  
  400603:	ff ac 00 00 00 46 ff 	jmp    FWORD PTR [rax+rax*1-0xba0000]
  40060a:	ff                   	(bad)  
  40060b:	ff cc                	dec    esp
  40060d:	00 00                	add    BYTE PTR [rax],al
  40060f:	00 7c ff ff          	add    BYTE PTR [rdi+rdi*8-0x1],bh
  400613:	ff                   	(bad)  
  400614:	ec                   	in     al,dx
  400615:	00 00                	add    BYTE PTR [rax],al
  400617:	00 ec                	add    ah,ch
  400619:	ff                   	(bad)  
  40061a:	ff                   	(bad)  
  40061b:	ff 34 01             	push   QWORD PTR [rcx+rax*1]
	...

Disassembly of section .eh_frame:

0000000000400620 <__FRAME_END__-0x110>:
  400620:	14 00                	adc    al,0x0
  400622:	00 00                	add    BYTE PTR [rax],al
  400624:	00 00                	add    BYTE PTR [rax],al
  400626:	00 00                	add    BYTE PTR [rax],al
  400628:	01 7a 52             	add    DWORD PTR [rdx+0x52],edi
  40062b:	00 01                	add    BYTE PTR [rcx],al
  40062d:	78 10                	js     40063f <__GNU_EH_FRAME_HDR+0x5b>
  40062f:	01 1b                	add    DWORD PTR [rbx],ebx
  400631:	0c 07                	or     al,0x7
  400633:	08 90 01 07 10 14    	or     BYTE PTR [rax+0x14100701],dl
  400639:	00 00                	add    BYTE PTR [rax],al
  40063b:	00 1c 00             	add    BYTE PTR [rax+rax*1],bl
  40063e:	00 00                	add    BYTE PTR [rax],al
  400640:	a0 fd ff ff 2a 00 00 	movabs al,ds:0x2afffffd
  400647:	00 00 
  400649:	00 00                	add    BYTE PTR [rax],al
  40064b:	00 00                	add    BYTE PTR [rax],al
  40064d:	00 00                	add    BYTE PTR [rax],al
  40064f:	00 14 00             	add    BYTE PTR [rax+rax*1],dl
  400652:	00 00                	add    BYTE PTR [rax],al
  400654:	00 00                	add    BYTE PTR [rax],al
  400656:	00 00                	add    BYTE PTR [rax],al
  400658:	01 7a 52             	add    DWORD PTR [rdx+0x52],edi
  40065b:	00 01                	add    BYTE PTR [rcx],al
  40065d:	78 10                	js     40066f <__GNU_EH_FRAME_HDR+0x8b>
  40065f:	01 1b                	add    DWORD PTR [rbx],ebx
  400661:	0c 07                	or     al,0x7
  400663:	08 90 01 00 00 24    	or     BYTE PTR [rax+0x24000001],dl
  400669:	00 00                	add    BYTE PTR [rax],al
  40066b:	00 1c 00             	add    BYTE PTR [rax+rax*1],bl
  40066e:	00 00                	add    BYTE PTR [rax],al
  400670:	40 fd                	rex std 
  400672:	ff                   	(bad)  
  400673:	ff 20                	jmp    QWORD PTR [rax]
  400675:	00 00                	add    BYTE PTR [rax],al
  400677:	00 00                	add    BYTE PTR [rax],al
  400679:	0e                   	(bad)  
  40067a:	10 46 0e             	adc    BYTE PTR [rsi+0xe],al
  40067d:	18 4a 0f             	sbb    BYTE PTR [rdx+0xf],cl
  400680:	0b 77 08             	or     esi,DWORD PTR [rdi+0x8]
  400683:	80 00 3f             	add    BYTE PTR [rax],0x3f
  400686:	1a 3b                	sbb    bh,BYTE PTR [rbx]
  400688:	2a 33                	sub    dh,BYTE PTR [rbx]
  40068a:	24 22                	and    al,0x22
  40068c:	00 00                	add    BYTE PTR [rax],al
  40068e:	00 00                	add    BYTE PTR [rax],al
  400690:	1c 00                	sbb    al,0x0
  400692:	00 00                	add    BYTE PTR [rax],al
  400694:	44 00 00             	add    BYTE PTR [rax],r8b
  400697:	00 3e                	add    BYTE PTR [rsi],bh
  400699:	fe                   	(bad)  
  40069a:	ff                   	(bad)  
  40069b:	ff 54 00 00          	call   QWORD PTR [rax+rax*1+0x0]
  40069f:	00 00                	add    BYTE PTR [rax],al
  4006a1:	41 0e                	rex.B (bad) 
  4006a3:	10 86 02 43 0d 06    	adc    BYTE PTR [rsi+0x60d4302],al
  4006a9:	02 4f 0c             	add    cl,BYTE PTR [rdi+0xc]
  4006ac:	07                   	(bad)  
  4006ad:	08 00                	or     BYTE PTR [rax],al
  4006af:	00 1c 00             	add    BYTE PTR [rax+rax*1],bl
  4006b2:	00 00                	add    BYTE PTR [rax],al
  4006b4:	64 00 00             	add    BYTE PTR fs:[rax],al
  4006b7:	00 72 fe             	add    BYTE PTR [rdx-0x2],dh
  4006ba:	ff                   	(bad)  
  4006bb:	ff 36                	push   QWORD PTR [rsi]
  4006bd:	00 00                	add    BYTE PTR [rax],al
  4006bf:	00 00                	add    BYTE PTR [rax],al
  4006c1:	41 0e                	rex.B (bad) 
  4006c3:	10 86 02 43 0d 06    	adc    BYTE PTR [rsi+0x60d4302],al
  4006c9:	71 0c                	jno    4006d7 <__GNU_EH_FRAME_HDR+0xf3>
  4006cb:	07                   	(bad)  
  4006cc:	08 00                	or     BYTE PTR [rax],al
  4006ce:	00 00                	add    BYTE PTR [rax],al
  4006d0:	44 00 00             	add    BYTE PTR [rax],r8b
  4006d3:	00 84 00 00 00 88 fe 	add    BYTE PTR [rax+rax*1-0x1780000],al
  4006da:	ff                   	(bad)  
  4006db:	ff 65 00             	jmp    QWORD PTR [rbp+0x0]
  4006de:	00 00                	add    BYTE PTR [rax],al
  4006e0:	00 42 0e             	add    BYTE PTR [rdx+0xe],al
  4006e3:	10 8f 02 42 0e 18    	adc    BYTE PTR [rdi+0x180e4202],cl
  4006e9:	8e 03                	mov    es,WORD PTR [rbx]
  4006eb:	45 0e                	rex.RB (bad) 
  4006ed:	20 8d 04 42 0e 28    	and    BYTE PTR [rbp+0x280e4204],cl
  4006f3:	8c 05 48 0e 30 86    	mov    WORD PTR [rip+0xffffffff86300e48],es        # ffffffff86701541 <_end+0xffffffff86100509>
  4006f9:	06                   	(bad)  
  4006fa:	48 0e                	rex.W (bad) 
  4006fc:	38 83 07 4d 0e 40    	cmp    BYTE PTR [rbx+0x400e4d07],al
  400702:	72 0e                	jb     400712 <__GNU_EH_FRAME_HDR+0x12e>
  400704:	38 41 0e             	cmp    BYTE PTR [rcx+0xe],al
  400707:	30 41 0e             	xor    BYTE PTR [rcx+0xe],al
  40070a:	28 42 0e             	sub    BYTE PTR [rdx+0xe],al
  40070d:	20 42 0e             	and    BYTE PTR [rdx+0xe],al
  400710:	18 42 0e             	sbb    BYTE PTR [rdx+0xe],al
  400713:	10 42 0e             	adc    BYTE PTR [rdx+0xe],al
  400716:	08 00                	or     BYTE PTR [rax],al
  400718:	14 00                	adc    al,0x0
  40071a:	00 00                	add    BYTE PTR [rax],al
  40071c:	cc                   	int3   
  40071d:	00 00                	add    BYTE PTR [rax],al
  40071f:	00 b0 fe ff ff 02    	add    BYTE PTR [rax+0x2fffffe],dh
	...

0000000000400730 <__FRAME_END__>:
  400730:	00 00                	add    BYTE PTR [rax],al
	...

Disassembly of section .init_array:

0000000000600e10 <__frame_dummy_init_array_entry>:
  600e10:	b0 04                	mov    al,0x4
  600e12:	40 00 00             	add    BYTE PTR [rax],al
  600e15:	00 00                	add    BYTE PTR [rax],al
	...

Disassembly of section .fini_array:

0000000000600e18 <__do_global_dtors_aux_fini_array_entry>:
  600e18:	90                   	nop
  600e19:	04 40                	add    al,0x40
  600e1b:	00 00                	add    BYTE PTR [rax],al
  600e1d:	00 00                	add    BYTE PTR [rax],al
	...

Disassembly of section .jcr:

0000000000600e20 <__JCR_END__>:
	...

Disassembly of section .dynamic:

0000000000600e28 <_DYNAMIC>:
  600e28:	01 00                	add    DWORD PTR [rax],eax
  600e2a:	00 00                	add    BYTE PTR [rax],al
  600e2c:	00 00                	add    BYTE PTR [rax],al
  600e2e:	00 00                	add    BYTE PTR [rax],al
  600e30:	01 00                	add    DWORD PTR [rax],eax
  600e32:	00 00                	add    BYTE PTR [rax],al
  600e34:	00 00                	add    BYTE PTR [rax],al
  600e36:	00 00                	add    BYTE PTR [rax],al
  600e38:	0c 00                	or     al,0x0
  600e3a:	00 00                	add    BYTE PTR [rax],al
  600e3c:	00 00                	add    BYTE PTR [rax],al
  600e3e:	00 00                	add    BYTE PTR [rax],al
  600e40:	90                   	nop
  600e41:	03 40 00             	add    eax,DWORD PTR [rax+0x0]
  600e44:	00 00                	add    BYTE PTR [rax],al
  600e46:	00 00                	add    BYTE PTR [rax],al
  600e48:	0d 00 00 00 00       	or     eax,0x0
  600e4d:	00 00                	add    BYTE PTR [rax],al
  600e4f:	00 d4                	add    ah,dl
  600e51:	05 40 00 00 00       	add    eax,0x40
  600e56:	00 00                	add    BYTE PTR [rax],al
  600e58:	19 00                	sbb    DWORD PTR [rax],eax
  600e5a:	00 00                	add    BYTE PTR [rax],al
  600e5c:	00 00                	add    BYTE PTR [rax],al
  600e5e:	00 00                	add    BYTE PTR [rax],al
  600e60:	10 0e                	adc    BYTE PTR [rsi],cl
  600e62:	60                   	(bad)  
  600e63:	00 00                	add    BYTE PTR [rax],al
  600e65:	00 00                	add    BYTE PTR [rax],al
  600e67:	00 1b                	add    BYTE PTR [rbx],bl
  600e69:	00 00                	add    BYTE PTR [rax],al
  600e6b:	00 00                	add    BYTE PTR [rax],al
  600e6d:	00 00                	add    BYTE PTR [rax],al
  600e6f:	00 08                	add    BYTE PTR [rax],cl
  600e71:	00 00                	add    BYTE PTR [rax],al
  600e73:	00 00                	add    BYTE PTR [rax],al
  600e75:	00 00                	add    BYTE PTR [rax],al
  600e77:	00 1a                	add    BYTE PTR [rdx],bl
  600e79:	00 00                	add    BYTE PTR [rax],al
  600e7b:	00 00                	add    BYTE PTR [rax],al
  600e7d:	00 00                	add    BYTE PTR [rax],al
  600e7f:	00 18                	add    BYTE PTR [rax],bl
  600e81:	0e                   	(bad)  
  600e82:	60                   	(bad)  
  600e83:	00 00                	add    BYTE PTR [rax],al
  600e85:	00 00                	add    BYTE PTR [rax],al
  600e87:	00 1c 00             	add    BYTE PTR [rax+rax*1],bl
  600e8a:	00 00                	add    BYTE PTR [rax],al
  600e8c:	00 00                	add    BYTE PTR [rax],al
  600e8e:	00 00                	add    BYTE PTR [rax],al
  600e90:	08 00                	or     BYTE PTR [rax],al
  600e92:	00 00                	add    BYTE PTR [rax],al
  600e94:	00 00                	add    BYTE PTR [rax],al
  600e96:	00 00                	add    BYTE PTR [rax],al
  600e98:	f5                   	cmc    
  600e99:	fe                   	(bad)  
  600e9a:	ff 6f 00             	jmp    FWORD PTR [rdi+0x0]
  600e9d:	00 00                	add    BYTE PTR [rax],al
  600e9f:	00 98 02 40 00 00    	add    BYTE PTR [rax+0x4002],bl
  600ea5:	00 00                	add    BYTE PTR [rax],al
  600ea7:	00 05 00 00 00 00    	add    BYTE PTR [rip+0x0],al        # 600ead <_DYNAMIC+0x85>
  600ead:	00 00                	add    BYTE PTR [rax],al
  600eaf:	00 00                	add    BYTE PTR [rax],al
  600eb1:	03 40 00             	add    eax,DWORD PTR [rax+0x0]
  600eb4:	00 00                	add    BYTE PTR [rax],al
  600eb6:	00 00                	add    BYTE PTR [rax],al
  600eb8:	06                   	(bad)  
  600eb9:	00 00                	add    BYTE PTR [rax],al
  600ebb:	00 00                	add    BYTE PTR [rax],al
  600ebd:	00 00                	add    BYTE PTR [rax],al
  600ebf:	00 b8 02 40 00 00    	add    BYTE PTR [rax+0x4002],bh
  600ec5:	00 00                	add    BYTE PTR [rax],al
  600ec7:	00 0a                	add    BYTE PTR [rdx],cl
  600ec9:	00 00                	add    BYTE PTR [rax],al
  600ecb:	00 00                	add    BYTE PTR [rax],al
  600ecd:	00 00                	add    BYTE PTR [rax],al
  600ecf:	00 38                	add    BYTE PTR [rax],bh
  600ed1:	00 00                	add    BYTE PTR [rax],al
  600ed3:	00 00                	add    BYTE PTR [rax],al
  600ed5:	00 00                	add    BYTE PTR [rax],al
  600ed7:	00 0b                	add    BYTE PTR [rbx],cl
  600ed9:	00 00                	add    BYTE PTR [rax],al
  600edb:	00 00                	add    BYTE PTR [rax],al
  600edd:	00 00                	add    BYTE PTR [rax],al
  600edf:	00 18                	add    BYTE PTR [rax],bl
  600ee1:	00 00                	add    BYTE PTR [rax],al
  600ee3:	00 00                	add    BYTE PTR [rax],al
  600ee5:	00 00                	add    BYTE PTR [rax],al
  600ee7:	00 15 00 00 00 00    	add    BYTE PTR [rip+0x0],dl        # 600eed <_DYNAMIC+0xc5>
	...
  600ef5:	00 00                	add    BYTE PTR [rax],al
  600ef7:	00 03                	add    BYTE PTR [rbx],al
	...
  600f01:	10 60 00             	adc    BYTE PTR [rax+0x0],ah
  600f04:	00 00                	add    BYTE PTR [rax],al
  600f06:	00 00                	add    BYTE PTR [rax],al
  600f08:	02 00                	add    al,BYTE PTR [rax]
  600f0a:	00 00                	add    BYTE PTR [rax],al
  600f0c:	00 00                	add    BYTE PTR [rax],al
  600f0e:	00 00                	add    BYTE PTR [rax],al
  600f10:	18 00                	sbb    BYTE PTR [rax],al
  600f12:	00 00                	add    BYTE PTR [rax],al
  600f14:	00 00                	add    BYTE PTR [rax],al
  600f16:	00 00                	add    BYTE PTR [rax],al
  600f18:	14 00                	adc    al,0x0
  600f1a:	00 00                	add    BYTE PTR [rax],al
  600f1c:	00 00                	add    BYTE PTR [rax],al
  600f1e:	00 00                	add    BYTE PTR [rax],al
  600f20:	07                   	(bad)  
  600f21:	00 00                	add    BYTE PTR [rax],al
  600f23:	00 00                	add    BYTE PTR [rax],al
  600f25:	00 00                	add    BYTE PTR [rax],al
  600f27:	00 17                	add    BYTE PTR [rdi],dl
  600f29:	00 00                	add    BYTE PTR [rax],al
  600f2b:	00 00                	add    BYTE PTR [rax],al
  600f2d:	00 00                	add    BYTE PTR [rax],al
  600f2f:	00 78 03             	add    BYTE PTR [rax+0x3],bh
  600f32:	40 00 00             	add    BYTE PTR [rax],al
  600f35:	00 00                	add    BYTE PTR [rax],al
  600f37:	00 07                	add    BYTE PTR [rdi],al
  600f39:	00 00                	add    BYTE PTR [rax],al
  600f3b:	00 00                	add    BYTE PTR [rax],al
  600f3d:	00 00                	add    BYTE PTR [rax],al
  600f3f:	00 60 03             	add    BYTE PTR [rax+0x3],ah
  600f42:	40 00 00             	add    BYTE PTR [rax],al
  600f45:	00 00                	add    BYTE PTR [rax],al
  600f47:	00 08                	add    BYTE PTR [rax],cl
  600f49:	00 00                	add    BYTE PTR [rax],al
  600f4b:	00 00                	add    BYTE PTR [rax],al
  600f4d:	00 00                	add    BYTE PTR [rax],al
  600f4f:	00 18                	add    BYTE PTR [rax],bl
  600f51:	00 00                	add    BYTE PTR [rax],al
  600f53:	00 00                	add    BYTE PTR [rax],al
  600f55:	00 00                	add    BYTE PTR [rax],al
  600f57:	00 09                	add    BYTE PTR [rcx],cl
  600f59:	00 00                	add    BYTE PTR [rax],al
  600f5b:	00 00                	add    BYTE PTR [rax],al
  600f5d:	00 00                	add    BYTE PTR [rax],al
  600f5f:	00 18                	add    BYTE PTR [rax],bl
  600f61:	00 00                	add    BYTE PTR [rax],al
  600f63:	00 00                	add    BYTE PTR [rax],al
  600f65:	00 00                	add    BYTE PTR [rax],al
  600f67:	00 fe                	add    dh,bh
  600f69:	ff                   	(bad)  
  600f6a:	ff 6f 00             	jmp    FWORD PTR [rdi+0x0]
  600f6d:	00 00                	add    BYTE PTR [rax],al
  600f6f:	00 40 03             	add    BYTE PTR [rax+0x3],al
  600f72:	40 00 00             	add    BYTE PTR [rax],al
  600f75:	00 00                	add    BYTE PTR [rax],al
  600f77:	00 ff                	add    bh,bh
  600f79:	ff                   	(bad)  
  600f7a:	ff 6f 00             	jmp    FWORD PTR [rdi+0x0]
  600f7d:	00 00                	add    BYTE PTR [rax],al
  600f7f:	00 01                	add    BYTE PTR [rcx],al
  600f81:	00 00                	add    BYTE PTR [rax],al
  600f83:	00 00                	add    BYTE PTR [rax],al
  600f85:	00 00                	add    BYTE PTR [rax],al
  600f87:	00 f0                	add    al,dh
  600f89:	ff                   	(bad)  
  600f8a:	ff 6f 00             	jmp    FWORD PTR [rdi+0x0]
  600f8d:	00 00                	add    BYTE PTR [rax],al
  600f8f:	00 38                	add    BYTE PTR [rax],bh
  600f91:	03 40 00             	add    eax,DWORD PTR [rax+0x0]
	...

Disassembly of section .got:

0000000000600ff8 <.got>:
	...

Disassembly of section .got.plt:

0000000000601000 <_GLOBAL_OFFSET_TABLE_>:
  601000:	28 0e                	sub    BYTE PTR [rsi],cl
  601002:	60                   	(bad)  
	...
  601017:	00 c6                	add    dh,al
  601019:	03 40 00             	add    eax,DWORD PTR [rax+0x0]
  60101c:	00 00                	add    BYTE PTR [rax],al
	...

Disassembly of section .data:

0000000000601020 <__data_start>:
	...

0000000000601028 <__dso_handle>:
	...

Disassembly of section .bss:

0000000000601030 <__bss_start>:
	...

Disassembly of section .comment:

0000000000000000 <.comment>:
   0:	47                   	rex.RXB
   1:	43                   	rex.XB
   2:	43 3a 20             	rex.XB cmp spl,BYTE PTR [r8]
   5:	28 55 62             	sub    BYTE PTR [rbp+0x62],dl
   8:	75 6e                	jne    78 <_init-0x400318>
   a:	74 75                	je     81 <_init-0x40030f>
   c:	20 35 2e 34 2e 30    	and    BYTE PTR [rip+0x302e342e],dh        # 302e3440 <_end+0x2fce2408>
  12:	2d 36 75 62 75       	sub    eax,0x75627536
  17:	6e                   	outs   dx,BYTE PTR ds:[rsi]
  18:	74 75                	je     8f <_init-0x400301>
  1a:	31 7e 31             	xor    DWORD PTR [rsi+0x31],edi
  1d:	36 2e 30 34 2e       	ss xor BYTE PTR cs:[rsi+rbp*1],dh
  22:	32 29                	xor    ch,BYTE PTR [rcx]
  24:	20 35 2e 34 2e 30    	and    BYTE PTR [rip+0x302e342e],dh        # 302e3458 <_end+0x2fce2420>
  2a:	20 32                	and    BYTE PTR [rdx],dh
  2c:	30 31                	xor    BYTE PTR [rcx],dh
  2e:	36 30 36             	xor    BYTE PTR ss:[rsi],dh
  31:	30 39                	xor    BYTE PTR [rcx],bh
	...

Disassembly of section .debug_aranges:

0000000000000000 <.debug_aranges>:
   0:	2c 00                	sub    al,0x0
   2:	00 00                	add    BYTE PTR [rax],al
   4:	02 00                	add    al,BYTE PTR [rax]
   6:	00 00                	add    BYTE PTR [rax],al
   8:	00 00                	add    BYTE PTR [rax],al
   a:	08 00                	or     BYTE PTR [rax],al
   c:	00 00                	add    BYTE PTR [rax],al
   e:	00 00                	add    BYTE PTR [rax],al
  10:	d6                   	(bad)  
  11:	04 40                	add    al,0x40
  13:	00 00                	add    BYTE PTR [rax],al
  15:	00 00                	add    BYTE PTR [rax],al
  17:	00 8a 00 00 00 00    	add    BYTE PTR [rdx+0x0],cl
	...

Disassembly of section .debug_info:

0000000000000000 <.debug_info>:
   0:	dd 00                	fld    QWORD PTR [rax]
   2:	00 00                	add    BYTE PTR [rax],al
   4:	04 00                	add    al,0x0
   6:	00 00                	add    BYTE PTR [rax],al
   8:	00 00                	add    BYTE PTR [rax],al
   a:	08 01                	or     BYTE PTR [rcx],al
   c:	4c 00 00             	rex.WR add BYTE PTR [rax],r8b
   f:	00 04 3b             	add    BYTE PTR [rbx+rdi*1],al
  12:	00 00                	add    BYTE PTR [rax],al
  14:	00 19                	add    BYTE PTR [rcx],bl
  16:	00 00                	add    BYTE PTR [rax],al
  18:	00 d6                	add    dh,dl
  1a:	04 40                	add    al,0x40
  1c:	00 00                	add    BYTE PTR [rax],al
  1e:	00 00                	add    BYTE PTR [rax],al
  20:	00 8a 00 00 00 00    	add    BYTE PTR [rdx+0x0],cl
  26:	00 00                	add    BYTE PTR [rax],al
  28:	00 00                	add    BYTE PTR [rax],al
  2a:	00 00                	add    BYTE PTR [rax],al
  2c:	00 02                	add    BYTE PTR [rdx],al
  2e:	32 00                	xor    al,BYTE PTR [rax]
  30:	00 00                	add    BYTE PTR [rax],al
  32:	01 03                	add    DWORD PTR [rbx],eax
  34:	00 00                	add    BYTE PTR [rax],al
  36:	00 00                	add    BYTE PTR [rax],al
  38:	bc 00 00 00 d6       	mov    esp,0xd6000000
  3d:	04 40                	add    al,0x40
  3f:	00 00                	add    BYTE PTR [rax],al
  41:	00 00                	add    BYTE PTR [rax],al
  43:	00 54 00 00          	add    BYTE PTR [rax+rax*1+0x0],dl
  47:	00 00                	add    BYTE PTR [rax],al
  49:	00 00                	add    BYTE PTR [rax],al
  4b:	00 01                	add    BYTE PTR [rcx],al
  4d:	9c                   	pushf  
  4e:	bc 00 00 00 03       	mov    esp,0x3000000
  53:	69 31 00 01 04 bc    	imul   esi,DWORD PTR [rcx],0xbc040100
  59:	00 00                	add    BYTE PTR [rax],al
  5b:	00 02                	add    BYTE PTR [rdx],al
  5d:	91                   	xchg   ecx,eax
  5e:	5c                   	pop    rsp
  5f:	03 69 32             	add    ebp,DWORD PTR [rcx+0x32]
  62:	00 01                	add    BYTE PTR [rcx],al
  64:	05 bc 00 00 00       	add    eax,0xbc
  69:	02 91 58 03 69 33    	add    dl,BYTE PTR [rcx+0x33690358]
  6f:	00 01                	add    BYTE PTR [rcx],al
  71:	06                   	(bad)  
  72:	bc 00 00 00 02       	mov    esp,0x2000000
  77:	91                   	xchg   ecx,eax
  78:	54                   	push   rsp
  79:	03 69 34             	add    ebp,DWORD PTR [rcx+0x34]
  7c:	00 01                	add    BYTE PTR [rcx],al
  7e:	07                   	(bad)  
  7f:	bc 00 00 00 02       	mov    esp,0x2000000
  84:	91                   	xchg   ecx,eax
  85:	50                   	push   rax
  86:	03 69 35             	add    ebp,DWORD PTR [rcx+0x35]
  89:	00 01                	add    BYTE PTR [rcx],al
  8b:	08 bc 00 00 00 02 91 	or     BYTE PTR [rax+rax*1-0x6efe0000],bh
  92:	4c 03 69 36          	add    r13,QWORD PTR [rcx+0x36]
  96:	00 01                	add    BYTE PTR [rcx],al
  98:	09 bc 00 00 00 02 91 	or     DWORD PTR [rax+rax*1-0x6efe0000],edi
  9f:	48 03 69 37          	add    rbp,QWORD PTR [rcx+0x37]
  a3:	00 01                	add    BYTE PTR [rcx],al
  a5:	0a bc 00 00 00 02 91 	or     bh,BYTE PTR [rax+rax*1-0x6efe0000]
  ac:	00 04 13             	add    BYTE PTR [rbx+rdx*1],al
  af:	00 00                	add    BYTE PTR [rax],al
  b1:	00 01                	add    BYTE PTR [rcx],al
  b3:	0c bc                	or     al,0xbc
  b5:	00 00                	add    BYTE PTR [rax],al
  b7:	00 02                	add    BYTE PTR [rdx],al
  b9:	91                   	xchg   ecx,eax
  ba:	6c                   	ins    BYTE PTR es:[rdi],dx
  bb:	00 05 04 05 69 6e    	add    BYTE PTR [rip+0x6e690504],al        # 6e6905c5 <_end+0x6e08f58d>
  c1:	74 00                	je     c3 <_init-0x4002cd>
  c3:	06                   	(bad)  
  c4:	ad                   	lods   eax,DWORD PTR ds:[rsi]
  c5:	00 00                	add    BYTE PTR [rax],al
  c7:	00 01                	add    BYTE PTR [rcx],al
  c9:	1d bc 00 00 00       	sbb    eax,0xbc
  ce:	2a 05 40 00 00 00    	sub    al,BYTE PTR [rip+0x40]        # 114 <_init-0x40027c>
  d4:	00 00                	add    BYTE PTR [rax],al
  d6:	36 00 00             	add    BYTE PTR ss:[rax],al
  d9:	00 00                	add    BYTE PTR [rax],al
  db:	00 00                	add    BYTE PTR [rax],al
  dd:	00 01                	add    BYTE PTR [rcx],al
  df:	9c                   	pushf  
	...

Disassembly of section .debug_abbrev:

0000000000000000 <.debug_abbrev>:
   0:	01 11                	add    DWORD PTR [rcx],edx
   2:	01 25 0e 13 0b 03    	add    DWORD PTR [rip+0x30b130e],esp        # 30b1316 <_end+0x2ab02de>
   8:	0e                   	(bad)  
   9:	1b 0e                	sbb    ecx,DWORD PTR [rsi]
   b:	11 01                	adc    DWORD PTR [rcx],eax
   d:	12 07                	adc    al,BYTE PTR [rdi]
   f:	10 17                	adc    BYTE PTR [rdi],dl
  11:	00 00                	add    BYTE PTR [rax],al
  13:	02 2e                	add    ch,BYTE PTR [rsi]
  15:	01 3f                	add    DWORD PTR [rdi],edi
  17:	19 03                	sbb    DWORD PTR [rbx],eax
  19:	0e                   	(bad)  
  1a:	3a 0b                	cmp    cl,BYTE PTR [rbx]
  1c:	3b 0b                	cmp    ecx,DWORD PTR [rbx]
  1e:	6e                   	outs   dx,BYTE PTR ds:[rsi]
  1f:	0e                   	(bad)  
  20:	49 13 11             	adc    rdx,QWORD PTR [r9]
  23:	01 12                	add    DWORD PTR [rdx],edx
  25:	07                   	(bad)  
  26:	40 18 97 42 19 01 13 	sbb    BYTE PTR [rdi+0x13011942],dl
  2d:	00 00                	add    BYTE PTR [rax],al
  2f:	03 05 00 03 08 3a    	add    eax,DWORD PTR [rip+0x3a080300]        # 3a080335 <_end+0x39a7f2fd>
  35:	0b 3b                	or     edi,DWORD PTR [rbx]
  37:	0b 49 13             	or     ecx,DWORD PTR [rcx+0x13]
  3a:	02 18                	add    bl,BYTE PTR [rax]
  3c:	00 00                	add    BYTE PTR [rax],al
  3e:	04 34                	add    al,0x34
  40:	00 03                	add    BYTE PTR [rbx],al
  42:	0e                   	(bad)  
  43:	3a 0b                	cmp    cl,BYTE PTR [rbx]
  45:	3b 0b                	cmp    ecx,DWORD PTR [rbx]
  47:	49 13 02             	adc    rax,QWORD PTR [r10]
  4a:	18 00                	sbb    BYTE PTR [rax],al
  4c:	00 05 24 00 0b 0b    	add    BYTE PTR [rip+0xb0b0024],al        # b0b0076 <_end+0xaaaf03e>
  52:	3e 0b 03             	or     eax,DWORD PTR ds:[rbx]
  55:	08 00                	or     BYTE PTR [rax],al
  57:	00 06                	add    BYTE PTR [rsi],al
  59:	2e 00 3f             	add    BYTE PTR cs:[rdi],bh
  5c:	19 03                	sbb    DWORD PTR [rbx],eax
  5e:	0e                   	(bad)  
  5f:	3a 0b                	cmp    cl,BYTE PTR [rbx]
  61:	3b 0b                	cmp    ecx,DWORD PTR [rbx]
  63:	49 13 11             	adc    rdx,QWORD PTR [r9]
  66:	01 12                	add    DWORD PTR [rdx],edx
  68:	07                   	(bad)  
  69:	40 18 96 42 19 00 00 	sbb    BYTE PTR [rsi+0x1942],dl
	...

Disassembly of section .debug_line:

0000000000000000 <.debug_line>:
   0:	4f 00 00             	rex.WRXB add BYTE PTR [r8],r8b
   3:	00 02                	add    BYTE PTR [rdx],al
   5:	00 27                	add    BYTE PTR [rdi],ah
   7:	00 00                	add    BYTE PTR [rax],al
   9:	00 01                	add    BYTE PTR [rcx],al
   b:	01 fb                	add    ebx,edi
   d:	0e                   	(bad)  
   e:	0d 00 01 01 01       	or     eax,0x1010100
  13:	01 00                	add    DWORD PTR [rax],eax
  15:	00 00                	add    BYTE PTR [rax],al
  17:	01 00                	add    DWORD PTR [rax],eax
  19:	00 01                	add    BYTE PTR [rcx],al
  1b:	00 66 75             	add    BYTE PTR [rsi+0x75],ah
  1e:	6e                   	outs   dx,BYTE PTR ds:[rsi]
  1f:	63 74 69 6f          	movsxd esi,DWORD PTR [rcx+rbp*2+0x6f]
  23:	6e                   	outs   dx,BYTE PTR ds:[rsi]
  24:	43 61                	rex.XB (bad) 
  26:	6c                   	ins    BYTE PTR es:[rdi],dx
  27:	6c                   	ins    BYTE PTR es:[rdi],dx
  28:	2e 63 70 70          	movsxd esi,DWORD PTR cs:[rax+0x70]
  2c:	00 00                	add    BYTE PTR [rax],al
  2e:	00 00                	add    BYTE PTR [rax],al
  30:	00 00                	add    BYTE PTR [rax],al
  32:	09 02                	or     DWORD PTR [rdx],eax
  34:	d6                   	(bad)  
  35:	04 40                	add    al,0x40
  37:	00 00                	add    BYTE PTR [rax],al
  39:	00 00                	add    BYTE PTR [rax],al
  3b:	00 03                	add    BYTE PTR [rbx],al
  3d:	0a 01                	or     al,BYTE PTR [rcx]
  3f:	08 75 76             	or     BYTE PTR [rbp+0x76],dh
  42:	68 68 a0 a0 84       	push   0xffffffff84a0a068
  47:	84 3d 30 4b 02 2b    	test   BYTE PTR [rip+0x2b024b30],bh        # 2b024b7d <_end+0x2aa23b45>
  4d:	13 02                	adc    eax,DWORD PTR [rdx]
  4f:	07                   	(bad)  
  50:	00 01                	add    BYTE PTR [rcx],al
  52:	01                   	.byte 0x1

Disassembly of section .debug_str:

0000000000000000 <.debug_str>:
   0:	5f                   	pop    rdi
   1:	5a                   	pop    rdx
   2:	38 66 75             	cmp    BYTE PTR [rsi+0x75],ah
   5:	6e                   	outs   dx,BYTE PTR ds:[rsi]
   6:	63 74 69 6f          	movsxd esi,DWORD PTR [rcx+rbp*2+0x6f]
   a:	6e                   	outs   dx,BYTE PTR ds:[rsi]
   b:	69 69 69 69 69 69 69 	imul   ebp,DWORD PTR [rcx+0x69],0x69696969
  12:	00 6c 6f 63          	add    BYTE PTR [rdi+rbp*2+0x63],ch
  16:	61                   	(bad)  
  17:	6c                   	ins    BYTE PTR es:[rdi],dx
  18:	00 2f                	add    BYTE PTR [rdi],ch
  1a:	68 6f 6d 65 2f       	push   0x2f656d6f
  1f:	77 6f                	ja     90 <_init-0x400300>
  21:	33 6b 69             	xor    ebp,DWORD PTR [rbx+0x69]
  24:	65 2f                	gs (bad) 
  26:	63 78 78             	movsxd edi,DWORD PTR [rax+0x78]
  29:	44 6f                	rex.R outs dx,DWORD PTR ds:[rsi]
  2b:	6a 6f                	push   0x6f
  2d:	2f                   	(bad)  
  2e:	61                   	(bad)  
  2f:	73 6d                	jae    9e <_init-0x4002f2>
  31:	00 66 75             	add    BYTE PTR [rsi+0x75],ah
  34:	6e                   	outs   dx,BYTE PTR ds:[rsi]
  35:	63 74 69 6f          	movsxd esi,DWORD PTR [rcx+rbp*2+0x6f]
  39:	6e                   	outs   dx,BYTE PTR ds:[rsi]
  3a:	00 66 75             	add    BYTE PTR [rsi+0x75],ah
  3d:	6e                   	outs   dx,BYTE PTR ds:[rsi]
  3e:	63 74 69 6f          	movsxd esi,DWORD PTR [rcx+rbp*2+0x6f]
  42:	6e                   	outs   dx,BYTE PTR ds:[rsi]
  43:	43 61                	rex.XB (bad) 
  45:	6c                   	ins    BYTE PTR es:[rdi],dx
  46:	6c                   	ins    BYTE PTR es:[rdi],dx
  47:	2e 63 70 70          	movsxd esi,DWORD PTR cs:[rax+0x70]
  4b:	00 47 4e             	add    BYTE PTR [rdi+0x4e],al
  4e:	55                   	push   rbp
  4f:	20 43 2b             	and    BYTE PTR [rbx+0x2b],al
  52:	2b 31                	sub    esi,DWORD PTR [rcx]
  54:	34 20                	xor    al,0x20
  56:	35 2e 34 2e 30       	xor    eax,0x302e342e
  5b:	20 32                	and    BYTE PTR [rdx],dh
  5d:	30 31                	xor    BYTE PTR [rcx],dh
  5f:	36 30 36             	xor    BYTE PTR ss:[rsi],dh
  62:	30 39                	xor    BYTE PTR [rcx],bh
  64:	20 2d 6d 74 75 6e    	and    BYTE PTR [rip+0x6e75746d],ch        # 6e7574d7 <_end+0x6e15649f>
  6a:	65 3d 67 65 6e 65    	gs cmp eax,0x656e6567
  70:	72 69                	jb     db <_init-0x4002b5>
  72:	63 20                	movsxd esp,DWORD PTR [rax]
  74:	2d 6d 61 72 63       	sub    eax,0x6372616d
  79:	68 3d 78 38 36       	push   0x3638783d
  7e:	2d 36 34 20 2d       	sub    eax,0x2d203436
  83:	67 20 2d 4f 30 20 2d 	and    BYTE PTR [eip+0x2d20304f],ch        # 2d2030d9 <_end+0x2cc020a1>
  8a:	73 74                	jae    100 <_init-0x400290>
  8c:	64 3d 63 2b 2b 31    	fs cmp eax,0x312b2b63
  92:	34 20                	xor    al,0x20
  94:	2d 66 73 74 61       	sub    eax,0x61747366
  99:	63 6b 2d             	movsxd ebp,DWORD PTR [rbx+0x2d]
  9c:	70 72                	jo     110 <_init-0x400280>
  9e:	6f                   	outs   dx,DWORD PTR ds:[rsi]
  9f:	74 65                	je     106 <_init-0x40028a>
  a1:	63 74 6f 72          	movsxd esi,DWORD PTR [rdi+rbp*2+0x72]
  a5:	2d 73 74 72 6f       	sub    eax,0x6f727473
  aa:	6e                   	outs   dx,BYTE PTR ds:[rsi]
  ab:	67 00 6d 61          	add    BYTE PTR [ebp+0x61],ch
  af:	69                   	.byte 0x69
  b0:	6e                   	outs   dx,BYTE PTR ds:[rsi]
	...
