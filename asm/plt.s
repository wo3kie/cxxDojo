
./plt:     file format elf64-x86-64


Disassembly of section .interp:

0000000000400238 <.interp>:
  400238:	2f                   	(bad)  
  400239:	6c                   	ins    BYTE PTR es:[rdi],dx
  40023a:	69 62 36 34 2f 6c 64 	imul   esp,DWORD PTR [rdx+0x36],0x646c2f34
  400241:	2d 6c 69 6e 75       	sub    eax,0x756e696c
  400246:	78 2d                	js     400275 <_init-0x153>
  400248:	78 38                	js     400282 <_init-0x146>
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
  400283:	00 dd                	add    ch,bl
  400285:	12 94 e4 64 b5 06 13 	adc    dl,BYTE PTR [rsp+riz*8+0x1306b564]
  40028c:	a9 de 14 04 30       	test   eax,0x300414de
  400291:	d4                   	(bad)  
  400292:	62                   	(bad)  
  400293:	6d                   	ins    DWORD PTR es:[rdi],dx
  400294:	b6 44                	mov    dh,0x44
  400296:	0b                   	.byte 0xb
  400297:	85                   	.byte 0x85

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
  4002e8:	12 00                	adc    al,BYTE PTR [rax]
  4002ea:	00 00                	add    BYTE PTR [rax],al
  4002ec:	12 00                	adc    al,BYTE PTR [rax]
	...
  4002fe:	00 00                	add    BYTE PTR [rax],al
  400300:	24 00                	and    al,0x0
  400302:	00 00                	add    BYTE PTR [rax],al
  400304:	20 00                	and    BYTE PTR [rax],al
	...

Disassembly of section .dynstr:

0000000000400318 <.dynstr>:
  400318:	00 6c 69 62          	add    BYTE PTR [rcx+rbp*2+0x62],ch
  40031c:	63 2e                	movsxd ebp,DWORD PTR [rsi]
  40031e:	73 6f                	jae    40038f <_init-0x39>
  400320:	2e 36 00 70 72       	cs add BYTE PTR ss:[rax+0x72],dh
  400325:	69 6e 74 66 00 5f 5f 	imul   ebp,DWORD PTR [rsi+0x74],0x5f5f0066
  40032c:	6c                   	ins    BYTE PTR es:[rdi],dx
  40032d:	69 62 63 5f 73 74 61 	imul   esp,DWORD PTR [rdx+0x63],0x6174735f
  400334:	72 74                	jb     4003aa <_init-0x1e>
  400336:	5f                   	pop    rdi
  400337:	6d                   	ins    DWORD PTR es:[rdi],dx
  400338:	61                   	(bad)  
  400339:	69 6e 00 5f 5f 67 6d 	imul   ebp,DWORD PTR [rsi+0x0],0x6d675f5f
  400340:	6f                   	outs   dx,DWORD PTR ds:[rsi]
  400341:	6e                   	outs   dx,BYTE PTR ds:[rsi]
  400342:	5f                   	pop    rdi
  400343:	73 74                	jae    4003b9 <_init-0xf>
  400345:	61                   	(bad)  
  400346:	72 74                	jb     4003bc <_init-0xc>
  400348:	5f                   	pop    rdi
  400349:	5f                   	pop    rdi
  40034a:	00 47 4c             	add    BYTE PTR [rdi+0x4c],al
  40034d:	49                   	rex.WB
  40034e:	42                   	rex.X
  40034f:	43 5f                	rex.XB pop r15
  400351:	32 2e                	xor    ch,BYTE PTR [rsi]
  400353:	32 2e                	xor    ch,BYTE PTR [rsi]
  400355:	35                   	.byte 0x35
	...

Disassembly of section .gnu.version:

0000000000400358 <.gnu.version>:
  400358:	00 00                	add    BYTE PTR [rax],al
  40035a:	02 00                	add    al,BYTE PTR [rax]
  40035c:	02 00                	add    al,BYTE PTR [rax]
	...

Disassembly of section .gnu.version_r:

0000000000400360 <.gnu.version_r>:
  400360:	01 00                	add    DWORD PTR [rax],eax
  400362:	01 00                	add    DWORD PTR [rax],eax
  400364:	01 00                	add    DWORD PTR [rax],eax
  400366:	00 00                	add    BYTE PTR [rax],al
  400368:	10 00                	adc    BYTE PTR [rax],al
  40036a:	00 00                	add    BYTE PTR [rax],al
  40036c:	00 00                	add    BYTE PTR [rax],al
  40036e:	00 00                	add    BYTE PTR [rax],al
  400370:	75 1a                	jne    40038c <_init-0x3c>
  400372:	69 09 00 00 02 00    	imul   ecx,DWORD PTR [rcx],0x20000
  400378:	33 00                	xor    eax,DWORD PTR [rax]
  40037a:	00 00                	add    BYTE PTR [rax],al
  40037c:	00 00                	add    BYTE PTR [rax],al
	...

Disassembly of section .rela.dyn:

0000000000400380 <.rela.dyn>:
  400380:	f8                   	clc    
  400381:	0f 60 00             	punpcklbw mm0,DWORD PTR [rax]
  400384:	00 00                	add    BYTE PTR [rax],al
  400386:	00 00                	add    BYTE PTR [rax],al
  400388:	06                   	(bad)  
  400389:	00 00                	add    BYTE PTR [rax],al
  40038b:	00 03                	add    BYTE PTR [rbx],al
	...

Disassembly of section .rela.plt:

0000000000400398 <.rela.plt>:
  400398:	18 10                	sbb    BYTE PTR [rax],dl
  40039a:	60                   	(bad)  
  40039b:	00 00                	add    BYTE PTR [rax],al
  40039d:	00 00                	add    BYTE PTR [rax],al
  40039f:	00 07                	add    BYTE PTR [rdi],al
  4003a1:	00 00                	add    BYTE PTR [rax],al
  4003a3:	00 01                	add    BYTE PTR [rcx],al
	...
  4003ad:	00 00                	add    BYTE PTR [rax],al
  4003af:	00 20                	add    BYTE PTR [rax],ah
  4003b1:	10 60 00             	adc    BYTE PTR [rax+0x0],ah
  4003b4:	00 00                	add    BYTE PTR [rax],al
  4003b6:	00 00                	add    BYTE PTR [rax],al
  4003b8:	07                   	(bad)  
  4003b9:	00 00                	add    BYTE PTR [rax],al
  4003bb:	00 02                	add    BYTE PTR [rdx],al
	...

Disassembly of section .init:

00000000004003c8 <_init>:
  4003c8:	48 83 ec 08          	sub    rsp,0x8
  4003cc:	48 8b 05 25 0c 20 00 	mov    rax,QWORD PTR [rip+0x200c25]        # 600ff8 <_DYNAMIC+0x1d0>
  4003d3:	48 85 c0             	test   rax,rax
  4003d6:	74 05                	je     4003dd <_init+0x15>
  4003d8:	e8 43 00 00 00       	call   400420 <__libc_start_main@plt+0x10>
  4003dd:	48 83 c4 08          	add    rsp,0x8
  4003e1:	c3                   	ret    

Disassembly of section .plt:

00000000004003f0 <printf@plt-0x10>:
  4003f0:	ff 35 12 0c 20 00    	push   QWORD PTR [rip+0x200c12]        # 601008 <_GLOBAL_OFFSET_TABLE_+0x8>
  4003f6:	ff 25 14 0c 20 00    	jmp    QWORD PTR [rip+0x200c14]        # 601010 <_GLOBAL_OFFSET_TABLE_+0x10>
  4003fc:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]

0000000000400400 <printf@plt>:
  400400:	ff 25 12 0c 20 00    	jmp    QWORD PTR [rip+0x200c12]        # 601018 <_GLOBAL_OFFSET_TABLE_+0x18>
  400406:	68 00 00 00 00       	push   0x0
  40040b:	e9 e0 ff ff ff       	jmp    4003f0 <_init+0x28>

0000000000400410 <__libc_start_main@plt>:
  400410:	ff 25 0a 0c 20 00    	jmp    QWORD PTR [rip+0x200c0a]        # 601020 <_GLOBAL_OFFSET_TABLE_+0x20>
  400416:	68 01 00 00 00       	push   0x1
  40041b:	e9 d0 ff ff ff       	jmp    4003f0 <_init+0x28>

Disassembly of section .plt.got:

0000000000400420 <.plt.got>:
  400420:	ff 25 d2 0b 20 00    	jmp    QWORD PTR [rip+0x200bd2]        # 600ff8 <_DYNAMIC+0x1d0>
  400426:	66 90                	xchg   ax,ax

Disassembly of section .text:

0000000000400430 <_start>:
  400430:	31 ed                	xor    ebp,ebp
  400432:	49 89 d1             	mov    r9,rdx
  400435:	5e                   	pop    rsi
  400436:	48 89 e2             	mov    rdx,rsp
  400439:	48 83 e4 f0          	and    rsp,0xfffffffffffffff0
  40043d:	50                   	push   rax
  40043e:	54                   	push   rsp
  40043f:	49 c7 c0 c0 05 40 00 	mov    r8,0x4005c0
  400446:	48 c7 c1 50 05 40 00 	mov    rcx,0x400550
  40044d:	48 c7 c7 26 05 40 00 	mov    rdi,0x400526
  400454:	e8 b7 ff ff ff       	call   400410 <__libc_start_main@plt>
  400459:	f4                   	hlt    
  40045a:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]

0000000000400460 <deregister_tm_clones>:
  400460:	b8 3f 10 60 00       	mov    eax,0x60103f
  400465:	55                   	push   rbp
  400466:	48 2d 38 10 60 00    	sub    rax,0x601038
  40046c:	48 83 f8 0e          	cmp    rax,0xe
  400470:	48 89 e5             	mov    rbp,rsp
  400473:	76 1b                	jbe    400490 <deregister_tm_clones+0x30>
  400475:	b8 00 00 00 00       	mov    eax,0x0
  40047a:	48 85 c0             	test   rax,rax
  40047d:	74 11                	je     400490 <deregister_tm_clones+0x30>
  40047f:	5d                   	pop    rbp
  400480:	bf 38 10 60 00       	mov    edi,0x601038
  400485:	ff e0                	jmp    rax
  400487:	66 0f 1f 84 00 00 00 	nop    WORD PTR [rax+rax*1+0x0]
  40048e:	00 00 
  400490:	5d                   	pop    rbp
  400491:	c3                   	ret    
  400492:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]
  400496:	66 2e 0f 1f 84 00 00 	nop    WORD PTR cs:[rax+rax*1+0x0]
  40049d:	00 00 00 

00000000004004a0 <register_tm_clones>:
  4004a0:	be 38 10 60 00       	mov    esi,0x601038
  4004a5:	55                   	push   rbp
  4004a6:	48 81 ee 38 10 60 00 	sub    rsi,0x601038
  4004ad:	48 c1 fe 03          	sar    rsi,0x3
  4004b1:	48 89 e5             	mov    rbp,rsp
  4004b4:	48 89 f0             	mov    rax,rsi
  4004b7:	48 c1 e8 3f          	shr    rax,0x3f
  4004bb:	48 01 c6             	add    rsi,rax
  4004be:	48 d1 fe             	sar    rsi,1
  4004c1:	74 15                	je     4004d8 <register_tm_clones+0x38>
  4004c3:	b8 00 00 00 00       	mov    eax,0x0
  4004c8:	48 85 c0             	test   rax,rax
  4004cb:	74 0b                	je     4004d8 <register_tm_clones+0x38>
  4004cd:	5d                   	pop    rbp
  4004ce:	bf 38 10 60 00       	mov    edi,0x601038
  4004d3:	ff e0                	jmp    rax
  4004d5:	0f 1f 00             	nop    DWORD PTR [rax]
  4004d8:	5d                   	pop    rbp
  4004d9:	c3                   	ret    
  4004da:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]

00000000004004e0 <__do_global_dtors_aux>:
  4004e0:	80 3d 51 0b 20 00 00 	cmp    BYTE PTR [rip+0x200b51],0x0        # 601038 <__TMC_END__>
  4004e7:	75 11                	jne    4004fa <__do_global_dtors_aux+0x1a>
  4004e9:	55                   	push   rbp
  4004ea:	48 89 e5             	mov    rbp,rsp
  4004ed:	e8 6e ff ff ff       	call   400460 <deregister_tm_clones>
  4004f2:	5d                   	pop    rbp
  4004f3:	c6 05 3e 0b 20 00 01 	mov    BYTE PTR [rip+0x200b3e],0x1        # 601038 <__TMC_END__>
  4004fa:	f3 c3                	repz ret 
  4004fc:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]

0000000000400500 <frame_dummy>:
  400500:	bf 20 0e 60 00       	mov    edi,0x600e20
  400505:	48 83 3f 00          	cmp    QWORD PTR [rdi],0x0
  400509:	75 05                	jne    400510 <frame_dummy+0x10>
  40050b:	eb 93                	jmp    4004a0 <register_tm_clones>
  40050d:	0f 1f 00             	nop    DWORD PTR [rax]
  400510:	b8 00 00 00 00       	mov    eax,0x0
  400515:	48 85 c0             	test   rax,rax
  400518:	74 f1                	je     40050b <frame_dummy+0xb>
  40051a:	55                   	push   rbp
  40051b:	48 89 e5             	mov    rbp,rsp
  40051e:	ff d0                	call   rax
  400520:	5d                   	pop    rbp
  400521:	e9 7a ff ff ff       	jmp    4004a0 <register_tm_clones>

0000000000400526 <main>:
#include <cstdio>

int main(){
  400526:	55                   	push   rbp
  400527:	48 89 e5             	mov    rbp,rsp
	printf("%d", 42);
  40052a:	be 2a 00 00 00       	mov    esi,0x2a
  40052f:	bf d4 05 40 00       	mov    edi,0x4005d4
  400534:	b8 00 00 00 00       	mov    eax,0x0
  400539:	e8 c2 fe ff ff       	call   400400 <printf@plt>
}
  40053e:	b8 00 00 00 00       	mov    eax,0x0
  400543:	5d                   	pop    rbp
  400544:	c3                   	ret    
  400545:	66 2e 0f 1f 84 00 00 	nop    WORD PTR cs:[rax+rax*1+0x0]
  40054c:	00 00 00 
  40054f:	90                   	nop

0000000000400550 <__libc_csu_init>:
  400550:	41 57                	push   r15
  400552:	41 56                	push   r14
  400554:	41 89 ff             	mov    r15d,edi
  400557:	41 55                	push   r13
  400559:	41 54                	push   r12
  40055b:	4c 8d 25 ae 08 20 00 	lea    r12,[rip+0x2008ae]        # 600e10 <__frame_dummy_init_array_entry>
  400562:	55                   	push   rbp
  400563:	48 8d 2d ae 08 20 00 	lea    rbp,[rip+0x2008ae]        # 600e18 <__init_array_end>
  40056a:	53                   	push   rbx
  40056b:	49 89 f6             	mov    r14,rsi
  40056e:	49 89 d5             	mov    r13,rdx
  400571:	4c 29 e5             	sub    rbp,r12
  400574:	48 83 ec 08          	sub    rsp,0x8
  400578:	48 c1 fd 03          	sar    rbp,0x3
  40057c:	e8 47 fe ff ff       	call   4003c8 <_init>
  400581:	48 85 ed             	test   rbp,rbp
  400584:	74 20                	je     4005a6 <__libc_csu_init+0x56>
  400586:	31 db                	xor    ebx,ebx
  400588:	0f 1f 84 00 00 00 00 	nop    DWORD PTR [rax+rax*1+0x0]
  40058f:	00 
  400590:	4c 89 ea             	mov    rdx,r13
  400593:	4c 89 f6             	mov    rsi,r14
  400596:	44 89 ff             	mov    edi,r15d
  400599:	41 ff 14 dc          	call   QWORD PTR [r12+rbx*8]
  40059d:	48 83 c3 01          	add    rbx,0x1
  4005a1:	48 39 eb             	cmp    rbx,rbp
  4005a4:	75 ea                	jne    400590 <__libc_csu_init+0x40>
  4005a6:	48 83 c4 08          	add    rsp,0x8
  4005aa:	5b                   	pop    rbx
  4005ab:	5d                   	pop    rbp
  4005ac:	41 5c                	pop    r12
  4005ae:	41 5d                	pop    r13
  4005b0:	41 5e                	pop    r14
  4005b2:	41 5f                	pop    r15
  4005b4:	c3                   	ret    
  4005b5:	90                   	nop
  4005b6:	66 2e 0f 1f 84 00 00 	nop    WORD PTR cs:[rax+rax*1+0x0]
  4005bd:	00 00 00 

00000000004005c0 <__libc_csu_fini>:
  4005c0:	f3 c3                	repz ret 

Disassembly of section .fini:

00000000004005c4 <_fini>:
  4005c4:	48 83 ec 08          	sub    rsp,0x8
  4005c8:	48 83 c4 08          	add    rsp,0x8
  4005cc:	c3                   	ret    

Disassembly of section .rodata:

00000000004005d0 <_IO_stdin_used>:
  4005d0:	01 00                	add    DWORD PTR [rax],eax
  4005d2:	02 00                	add    al,BYTE PTR [rax]
  4005d4:	25                   	.byte 0x25
  4005d5:	64                   	fs
	...

Disassembly of section .eh_frame_hdr:

00000000004005d8 <__GNU_EH_FRAME_HDR>:
  4005d8:	01 1b                	add    DWORD PTR [rbx],ebx
  4005da:	03 3b                	add    edi,DWORD PTR [rbx]
  4005dc:	34 00                	xor    al,0x0
  4005de:	00 00                	add    BYTE PTR [rax],al
  4005e0:	05 00 00 00 18       	add    eax,0x18000000
  4005e5:	fe                   	(bad)  
  4005e6:	ff                   	(bad)  
  4005e7:	ff 80 00 00 00 58    	inc    DWORD PTR [rax+0x58000000]
  4005ed:	fe                   	(bad)  
  4005ee:	ff                   	(bad)  
  4005ef:	ff 50 00             	call   QWORD PTR [rax+0x0]
  4005f2:	00 00                	add    BYTE PTR [rax],al
  4005f4:	4e ff                	rex.WRX (bad) 
  4005f6:	ff                   	(bad)  
  4005f7:	ff a8 00 00 00 78    	jmp    FWORD PTR [rax+0x78000000]
  4005fd:	ff                   	(bad)  
  4005fe:	ff                   	(bad)  
  4005ff:	ff c8                	dec    eax
  400601:	00 00                	add    BYTE PTR [rax],al
  400603:	00 e8                	add    al,ch
  400605:	ff                   	(bad)  
  400606:	ff                   	(bad)  
  400607:	ff 10                	call   QWORD PTR [rax]
  400609:	01 00                	add    DWORD PTR [rax],eax
	...

Disassembly of section .eh_frame:

0000000000400610 <__FRAME_END__-0xf0>:
  400610:	14 00                	adc    al,0x0
  400612:	00 00                	add    BYTE PTR [rax],al
  400614:	00 00                	add    BYTE PTR [rax],al
  400616:	00 00                	add    BYTE PTR [rax],al
  400618:	01 7a 52             	add    DWORD PTR [rdx+0x52],edi
  40061b:	00 01                	add    BYTE PTR [rcx],al
  40061d:	78 10                	js     40062f <__GNU_EH_FRAME_HDR+0x57>
  40061f:	01 1b                	add    DWORD PTR [rbx],ebx
  400621:	0c 07                	or     al,0x7
  400623:	08 90 01 07 10 14    	or     BYTE PTR [rax+0x14100701],dl
  400629:	00 00                	add    BYTE PTR [rax],al
  40062b:	00 1c 00             	add    BYTE PTR [rax+rax*1],bl
  40062e:	00 00                	add    BYTE PTR [rax],al
  400630:	00 fe                	add    dh,bh
  400632:	ff                   	(bad)  
  400633:	ff 2a                	jmp    FWORD PTR [rdx]
	...
  40063d:	00 00                	add    BYTE PTR [rax],al
  40063f:	00 14 00             	add    BYTE PTR [rax+rax*1],dl
  400642:	00 00                	add    BYTE PTR [rax],al
  400644:	00 00                	add    BYTE PTR [rax],al
  400646:	00 00                	add    BYTE PTR [rax],al
  400648:	01 7a 52             	add    DWORD PTR [rdx+0x52],edi
  40064b:	00 01                	add    BYTE PTR [rcx],al
  40064d:	78 10                	js     40065f <__GNU_EH_FRAME_HDR+0x87>
  40064f:	01 1b                	add    DWORD PTR [rbx],ebx
  400651:	0c 07                	or     al,0x7
  400653:	08 90 01 00 00 24    	or     BYTE PTR [rax+0x24000001],dl
  400659:	00 00                	add    BYTE PTR [rax],al
  40065b:	00 1c 00             	add    BYTE PTR [rax+rax*1],bl
  40065e:	00 00                	add    BYTE PTR [rax],al
  400660:	90                   	nop
  400661:	fd                   	std    
  400662:	ff                   	(bad)  
  400663:	ff 30                	push   QWORD PTR [rax]
  400665:	00 00                	add    BYTE PTR [rax],al
  400667:	00 00                	add    BYTE PTR [rax],al
  400669:	0e                   	(bad)  
  40066a:	10 46 0e             	adc    BYTE PTR [rsi+0xe],al
  40066d:	18 4a 0f             	sbb    BYTE PTR [rdx+0xf],cl
  400670:	0b 77 08             	or     esi,DWORD PTR [rdi+0x8]
  400673:	80 00 3f             	add    BYTE PTR [rax],0x3f
  400676:	1a 3b                	sbb    bh,BYTE PTR [rbx]
  400678:	2a 33                	sub    dh,BYTE PTR [rbx]
  40067a:	24 22                	and    al,0x22
  40067c:	00 00                	add    BYTE PTR [rax],al
  40067e:	00 00                	add    BYTE PTR [rax],al
  400680:	1c 00                	sbb    al,0x0
  400682:	00 00                	add    BYTE PTR [rax],al
  400684:	44 00 00             	add    BYTE PTR [rax],r8b
  400687:	00 9e fe ff ff 1f    	add    BYTE PTR [rsi+0x1ffffffe],bl
  40068d:	00 00                	add    BYTE PTR [rax],al
  40068f:	00 00                	add    BYTE PTR [rax],al
  400691:	41 0e                	rex.B (bad) 
  400693:	10 86 02 43 0d 06    	adc    BYTE PTR [rsi+0x60d4302],al
  400699:	5a                   	pop    rdx
  40069a:	0c 07                	or     al,0x7
  40069c:	08 00                	or     BYTE PTR [rax],al
  40069e:	00 00                	add    BYTE PTR [rax],al
  4006a0:	44 00 00             	add    BYTE PTR [rax],r8b
  4006a3:	00 64 00 00          	add    BYTE PTR [rax+rax*1+0x0],ah
  4006a7:	00 a8 fe ff ff 65    	add    BYTE PTR [rax+0x65fffffe],ch
  4006ad:	00 00                	add    BYTE PTR [rax],al
  4006af:	00 00                	add    BYTE PTR [rax],al
  4006b1:	42 0e                	rex.X (bad) 
  4006b3:	10 8f 02 42 0e 18    	adc    BYTE PTR [rdi+0x180e4202],cl
  4006b9:	8e 03                	mov    es,WORD PTR [rbx]
  4006bb:	45 0e                	rex.RB (bad) 
  4006bd:	20 8d 04 42 0e 28    	and    BYTE PTR [rbp+0x280e4204],cl
  4006c3:	8c 05 48 0e 30 86    	mov    WORD PTR [rip+0xffffffff86300e48],es        # ffffffff86701511 <_end+0xffffffff861004d1>
  4006c9:	06                   	(bad)  
  4006ca:	48 0e                	rex.W (bad) 
  4006cc:	38 83 07 4d 0e 40    	cmp    BYTE PTR [rbx+0x400e4d07],al
  4006d2:	72 0e                	jb     4006e2 <__GNU_EH_FRAME_HDR+0x10a>
  4006d4:	38 41 0e             	cmp    BYTE PTR [rcx+0xe],al
  4006d7:	30 41 0e             	xor    BYTE PTR [rcx+0xe],al
  4006da:	28 42 0e             	sub    BYTE PTR [rdx+0xe],al
  4006dd:	20 42 0e             	and    BYTE PTR [rdx+0xe],al
  4006e0:	18 42 0e             	sbb    BYTE PTR [rdx+0xe],al
  4006e3:	10 42 0e             	adc    BYTE PTR [rdx+0xe],al
  4006e6:	08 00                	or     BYTE PTR [rax],al
  4006e8:	14 00                	adc    al,0x0
  4006ea:	00 00                	add    BYTE PTR [rax],al
  4006ec:	ac                   	lods   al,BYTE PTR ds:[rsi]
  4006ed:	00 00                	add    BYTE PTR [rax],al
  4006ef:	00 d0                	add    al,dl
  4006f1:	fe                   	(bad)  
  4006f2:	ff                   	(bad)  
  4006f3:	ff 02                	inc    DWORD PTR [rdx]
	...

0000000000400700 <__FRAME_END__>:
  400700:	00 00                	add    BYTE PTR [rax],al
	...

Disassembly of section .init_array:

0000000000600e10 <__frame_dummy_init_array_entry>:
  600e10:	00 05 40 00 00 00    	add    BYTE PTR [rip+0x40],al        # 600e56 <_DYNAMIC+0x2e>
	...

Disassembly of section .fini_array:

0000000000600e18 <__do_global_dtors_aux_fini_array_entry>:
  600e18:	e0 04                	loopne 600e1e <__do_global_dtors_aux_fini_array_entry+0x6>
  600e1a:	40 00 00             	add    BYTE PTR [rax],al
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
  600e40:	c8 03 40 00          	enter  0x4003,0x0
  600e44:	00 00                	add    BYTE PTR [rax],al
  600e46:	00 00                	add    BYTE PTR [rax],al
  600e48:	0d 00 00 00 00       	or     eax,0x0
  600e4d:	00 00                	add    BYTE PTR [rax],al
  600e4f:	00 c4                	add    ah,al
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
  600eaf:	00 18                	add    BYTE PTR [rax],bl
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
  600ecf:	00 3f                	add    BYTE PTR [rdi],bh
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
  600f10:	30 00                	xor    BYTE PTR [rax],al
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
  600f2f:	00 98 03 40 00 00    	add    BYTE PTR [rax+0x4003],bl
  600f35:	00 00                	add    BYTE PTR [rax],al
  600f37:	00 07                	add    BYTE PTR [rdi],al
  600f39:	00 00                	add    BYTE PTR [rax],al
  600f3b:	00 00                	add    BYTE PTR [rax],al
  600f3d:	00 00                	add    BYTE PTR [rax],al
  600f3f:	00 80 03 40 00 00    	add    BYTE PTR [rax+0x4003],al
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
  600f6f:	00 60 03             	add    BYTE PTR [rax+0x3],ah
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
  600f8f:	00 58 03             	add    BYTE PTR [rax+0x3],bl
  600f92:	40 00 00             	add    BYTE PTR [rax],al
	...

Disassembly of section .got:

0000000000600ff8 <.got>:
	...

Disassembly of section .got.plt:

0000000000601000 <_GLOBAL_OFFSET_TABLE_>:
  601000:	28 0e                	sub    BYTE PTR [rsi],cl
  601002:	60                   	(bad)  
	...
  601017:	00 06                	add    BYTE PTR [rsi],al
  601019:	04 40                	add    al,0x40
  60101b:	00 00                	add    BYTE PTR [rax],al
  60101d:	00 00                	add    BYTE PTR [rax],al
  60101f:	00 16                	add    BYTE PTR [rsi],dl
  601021:	04 40                	add    al,0x40
  601023:	00 00                	add    BYTE PTR [rax],al
  601025:	00 00                	add    BYTE PTR [rax],al
	...

Disassembly of section .data:

0000000000601028 <__data_start>:
	...

0000000000601030 <__dso_handle>:
	...

Disassembly of section .bss:

0000000000601038 <__bss_start>:
	...

Disassembly of section .comment:

0000000000000000 <.comment>:
   0:	47                   	rex.RXB
   1:	43                   	rex.XB
   2:	43 3a 20             	rex.XB cmp spl,BYTE PTR [r8]
   5:	28 55 62             	sub    BYTE PTR [rbp+0x62],dl
   8:	75 6e                	jne    78 <_init-0x400350>
   a:	74 75                	je     81 <_init-0x400347>
   c:	20 35 2e 34 2e 30    	and    BYTE PTR [rip+0x302e342e],dh        # 302e3440 <_end+0x2fce2400>
  12:	2d 36 75 62 75       	sub    eax,0x75627536
  17:	6e                   	outs   dx,BYTE PTR ds:[rsi]
  18:	74 75                	je     8f <_init-0x400339>
  1a:	31 7e 31             	xor    DWORD PTR [rsi+0x31],edi
  1d:	36 2e 30 34 2e       	ss xor BYTE PTR cs:[rsi+rbp*1],dh
  22:	32 29                	xor    ch,BYTE PTR [rcx]
  24:	20 35 2e 34 2e 30    	and    BYTE PTR [rip+0x302e342e],dh        # 302e3458 <_end+0x2fce2418>
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
  10:	26 05 40 00 00 00    	es add eax,0x40
  16:	00 00                	add    BYTE PTR [rax],al
  18:	1f                   	(bad)  
	...

Disassembly of section .debug_info:

0000000000000000 <.debug_info>:
   0:	ab                   	stos   DWORD PTR es:[rdi],eax
   1:	06                   	(bad)  
   2:	00 00                	add    BYTE PTR [rax],al
   4:	04 00                	add    al,0x0
   6:	00 00                	add    BYTE PTR [rax],al
   8:	00 00                	add    BYTE PTR [rax],al
   a:	08 01                	or     BYTE PTR [rcx],al
   c:	de 02                	fiadd  WORD PTR [rdx]
   e:	00 00                	add    BYTE PTR [rax],al
  10:	04 25                	add    al,0x25
  12:	00 00                	add    BYTE PTR [rax],al
  14:	00 26                	add    BYTE PTR [rsi],ah
  16:	02 00                	add    al,BYTE PTR [rax]
  18:	00 26                	add    BYTE PTR [rsi],ah
  1a:	05 40 00 00 00       	add    eax,0x40
  1f:	00 00                	add    BYTE PTR [rax],al
  21:	1f                   	(bad)  
	...
  2a:	00 00                	add    BYTE PTR [rax],al
  2c:	00 02                	add    BYTE PTR [rdx],al
  2e:	73 74                	jae    a4 <_init-0x400324>
  30:	64 00 0a             	add    BYTE PTR fs:[rdx],cl
  33:	00 04 01             	add    BYTE PTR [rcx+rax*1],al
  36:	00 00                	add    BYTE PTR [rax],al
  38:	03 9e 01 00 00 03    	add    ebx,DWORD PTR [rsi+0x3000001]
  3e:	da 04 03             	fiadd  DWORD PTR [rbx+rax*1]
  41:	da 38                	fidivr DWORD PTR [rax]
  43:	00 00                	add    BYTE PTR [rax],al
  45:	00 05 02 62 8d 01    	add    BYTE PTR [rip+0x18d6202],al        # 18d624d <_end+0x12d520d>
  4b:	00 00                	add    BYTE PTR [rax],al
  4d:	05 02 63 19 04       	add    eax,0x4196302
  52:	00 00                	add    BYTE PTR [rax],al
  54:	05 02 65 24 04       	add    eax,0x4246502
  59:	00 00                	add    BYTE PTR [rax],al
  5b:	05 02 66 3c 04       	add    eax,0x43c6602
  60:	00 00                	add    BYTE PTR [rax],al
  62:	05 02 67 51 04       	add    eax,0x4516702
  67:	00 00                	add    BYTE PTR [rax],al
  69:	05 02 68 67 04       	add    eax,0x4676802
  6e:	00 00                	add    BYTE PTR [rax],al
  70:	05 02 69 7d 04       	add    eax,0x47d6902
  75:	00 00                	add    BYTE PTR [rax],al
  77:	05 02 6a 92 04       	add    eax,0x4926a02
  7c:	00 00                	add    BYTE PTR [rax],al
  7e:	05 02 6b a8 04       	add    eax,0x4a86b02
  83:	00 00                	add    BYTE PTR [rax],al
  85:	05 02 6c c9 04       	add    eax,0x4c96c02
  8a:	00 00                	add    BYTE PTR [rax],al
  8c:	05 02 6d e9 04       	add    eax,0x4e96d02
  91:	00 00                	add    BYTE PTR [rax],al
  93:	05 02 71 04 05       	add    eax,0x5047102
  98:	00 00                	add    BYTE PTR [rax],al
  9a:	05 02 72 29 05       	add    eax,0x5297202
  9f:	00 00                	add    BYTE PTR [rax],al
  a1:	05 02 74 49 05       	add    eax,0x5497402
  a6:	00 00                	add    BYTE PTR [rax],al
  a8:	05 02 75 69 05       	add    eax,0x5697502
  ad:	00 00                	add    BYTE PTR [rax],al
  af:	05 02 76 8f 05       	add    eax,0x58f7602
  b4:	00 00                	add    BYTE PTR [rax],al
  b6:	05 02 78 a5 05       	add    eax,0x5a57802
  bb:	00 00                	add    BYTE PTR [rax],al
  bd:	05 02 79 bb 05       	add    eax,0x5bb7902
  c2:	00 00                	add    BYTE PTR [rax],al
  c4:	05 02 7e c7 05       	add    eax,0x5c77e02
  c9:	00 00                	add    BYTE PTR [rax],al
  cb:	05 02 83 d9 05       	add    eax,0x5d98302
  d0:	00 00                	add    BYTE PTR [rax],al
  d2:	05 02 84 ee 05       	add    eax,0x5ee8402
  d7:	00 00                	add    BYTE PTR [rax],al
  d9:	05 02 85 08 06       	add    eax,0x6088502
  de:	00 00                	add    BYTE PTR [rax],al
  e0:	05 02 87 1a 06       	add    eax,0x61a8702
  e5:	00 00                	add    BYTE PTR [rax],al
  e7:	05 02 88 31 06       	add    eax,0x6318802
  ec:	00 00                	add    BYTE PTR [rax],al
  ee:	05 02 8b 56 06       	add    eax,0x6568b02
  f3:	00 00                	add    BYTE PTR [rax],al
  f5:	05 02 8d 61 06       	add    eax,0x6618d02
  fa:	00 00                	add    BYTE PTR [rax],al
  fc:	05 02 8f 76 06       	add    eax,0x6768f02
 101:	00 00                	add    BYTE PTR [rax],al
 103:	00 06                	add    BYTE PTR [rsi],al
 105:	47 01 00             	rex.RXB add DWORD PTR [r8],r8d
 108:	00 03                	add    BYTE PTR [rbx],al
 10a:	dd 1e                	fstp   QWORD PTR [rsi]
 10c:	01 00                	add    DWORD PTR [rax],eax
 10e:	00 03                	add    BYTE PTR [rbx],al
 110:	9e                   	sahf   
 111:	01 00                	add    DWORD PTR [rax],eax
 113:	00 03                	add    BYTE PTR [rbx],al
 115:	de 04 03             	fiadd  WORD PTR [rbx+rax*1]
 118:	de 0f                	fimul  WORD PTR [rdi]
 11a:	01 00                	add    DWORD PTR [rax],eax
 11c:	00 00                	add    BYTE PTR [rax],al
 11e:	07                   	(bad)  
 11f:	52                   	push   rdx
 120:	00 00                	add    BYTE PTR [rax],al
 122:	00 04 d8             	add    BYTE PTR [rax+rbx*8],al
 125:	29 01                	sub    DWORD PTR [rcx],eax
 127:	00 00                	add    BYTE PTR [rax],al
 129:	08 08                	or     BYTE PTR [rax],cl
 12b:	07                   	(bad)  
 12c:	df 01                	fild   WORD PTR [rcx]
 12e:	00 00                	add    BYTE PTR [rax],al
 130:	08 01                	or     BYTE PTR [rcx],al
 132:	08 39                	or     BYTE PTR [rcx],bh
 134:	01 00                	add    DWORD PTR [rax],eax
 136:	00 08                	add    BYTE PTR [rax],cl
 138:	02 07                	add    al,BYTE PTR [rdi]
 13a:	8b 01                	mov    eax,DWORD PTR [rcx]
 13c:	00 00                	add    BYTE PTR [rax],al
 13e:	08 04 07             	or     BYTE PTR [rdi+rax*1],al
 141:	e4 01                	in     al,0x1
 143:	00 00                	add    BYTE PTR [rax],al
 145:	08 01                	or     BYTE PTR [rcx],al
 147:	06                   	(bad)  
 148:	3b 01                	cmp    eax,DWORD PTR [rcx]
 14a:	00 00                	add    BYTE PTR [rax],al
 14c:	08 02                	or     BYTE PTR [rdx],al
 14e:	05 48 00 00 00       	add    eax,0x48
 153:	09 04 05 69 6e 74 00 	or     DWORD PTR [rax*1+0x746e69],eax
 15a:	08 08                	or     BYTE PTR [rax],cl
 15c:	05 fa 00 00 00       	add    eax,0xfa
 161:	07                   	(bad)  
 162:	09 02                	or     DWORD PTR [rdx],eax
 164:	00 00                	add    BYTE PTR [rax],al
 166:	05 83 5a 01 00       	add    eax,0x15a83
 16b:	00 07                	add    BYTE PTR [rdi],al
 16d:	ff 01                	inc    DWORD PTR [rcx]
 16f:	00 00                	add    BYTE PTR [rax],al
 171:	05 84 5a 01 00       	add    eax,0x15a84
 176:	00 08                	add    BYTE PTR [rax],cl
 178:	08 07                	or     BYTE PTR [rdi],al
 17a:	5f                   	pop    rdi
 17b:	00 00                	add    BYTE PTR [rax],al
 17d:	00 0a                	add    BYTE PTR [rdx],cl
 17f:	08 0b                	or     BYTE PTR [rbx],cl
 181:	08 86 01 00 00 08    	or     BYTE PTR [rsi+0x8000001],al
 187:	01 06                	add    DWORD PTR [rsi],eax
 189:	42 01 00             	rex.X add DWORD PTR [rax],eax
 18c:	00 07                	add    BYTE PTR [rdi],al
 18e:	2b 01                	sub    eax,DWORD PTR [rcx]
 190:	00 00                	add    BYTE PTR [rax],al
 192:	06                   	(bad)  
 193:	30 98 01 00 00 0c    	xor    BYTE PTR [rax+0xc000001],bl
 199:	27                   	(bad)  
 19a:	01 00                	add    DWORD PTR [rax],eax
 19c:	00 d8                	add    al,bl
 19e:	07                   	(bad)  
 19f:	f1                   	icebp  
 1a0:	15 03 00 00 0d       	adc    eax,0xd000003
 1a5:	7b 00                	jnp    1a7 <_init-0x400221>
 1a7:	00 00                	add    BYTE PTR [rax],al
 1a9:	07                   	(bad)  
 1aa:	f2 53                	repnz push rbx
 1ac:	01 00                	add    DWORD PTR [rax],eax
 1ae:	00 00                	add    BYTE PTR [rax],al
 1b0:	0d 7e 01 00 00       	or     eax,0x17e
 1b5:	07                   	(bad)  
 1b6:	f7 80 01 00 00 08 0d 	test   DWORD PTR [rax+0x8000001],0xa60d
 1bd:	a6 00 00 
 1c0:	00 07                	add    BYTE PTR [rdi],al
 1c2:	f8                   	clc    
 1c3:	80 01 00             	add    BYTE PTR [rcx],0x0
 1c6:	00 10                	add    BYTE PTR [rax],dl
 1c8:	0d 6f 02 00 00       	or     eax,0x26f
 1cd:	07                   	(bad)  
 1ce:	f9                   	stc    
 1cf:	80 01 00             	add    BYTE PTR [rcx],0x0
 1d2:	00 18                	add    BYTE PTR [rax],bl
 1d4:	0d 66 01 00 00       	or     eax,0x166
 1d9:	07                   	(bad)  
 1da:	fa                   	cli    
 1db:	80 01 00             	add    BYTE PTR [rcx],0x0
 1de:	00 20                	add    BYTE PTR [rax],ah
 1e0:	0d 6d 00 00 00       	or     eax,0x6d
 1e5:	07                   	(bad)  
 1e6:	fb                   	sti    
 1e7:	80 01 00             	add    BYTE PTR [rcx],0x0
 1ea:	00 28                	add    BYTE PTR [rax],ch
 1ec:	0d f1 01 00 00       	or     eax,0x1f1
 1f1:	07                   	(bad)  
 1f2:	fc                   	cld    
 1f3:	80 01 00             	add    BYTE PTR [rcx],0x0
 1f6:	00 30                	add    BYTE PTR [rax],dh
 1f8:	0d 88 00 00 00       	or     eax,0x88
 1fd:	07                   	(bad)  
 1fe:	fd                   	std    
 1ff:	80 01 00             	add    BYTE PTR [rcx],0x0
 202:	00 38                	add    BYTE PTR [rax],bh
 204:	0d 00 00 00 00       	or     eax,0x0
 209:	07                   	(bad)  
 20a:	fe 80 01 00 00 40    	inc    BYTE PTR [rax+0x40000001]
 210:	0e                   	(bad)  
 211:	93                   	xchg   ebx,eax
 212:	02 00                	add    al,BYTE PTR [rax]
 214:	00 07                	add    BYTE PTR [rdi],al
 216:	00 01                	add    BYTE PTR [rcx],al
 218:	80 01 00             	add    BYTE PTR [rcx],0x0
 21b:	00 48 0e             	add    BYTE PTR [rax+0xe],cl
 21e:	3f                   	(bad)  
 21f:	02 00                	add    al,BYTE PTR [rax]
 221:	00 07                	add    BYTE PTR [rdi],al
 223:	01 01                	add    DWORD PTR [rcx],eax
 225:	80 01 00             	add    BYTE PTR [rcx],0x0
 228:	00 50 0e             	add    BYTE PTR [rax+0xe],dl
 22b:	3b 00                	cmp    eax,DWORD PTR [rax]
 22d:	00 00                	add    BYTE PTR [rax],al
 22f:	07                   	(bad)  
 230:	02 01                	add    al,BYTE PTR [rcx]
 232:	80 01 00             	add    BYTE PTR [rcx],0x0
 235:	00 58 0e             	add    BYTE PTR [rax+0xe],bl
 238:	9d                   	popf   
 239:	00 00                	add    BYTE PTR [rax],al
 23b:	00 07                	add    BYTE PTR [rdi],al
 23d:	04 01                	add    al,0x1
 23f:	dc 03                	fadd   QWORD PTR [rbx]
 241:	00 00                	add    BYTE PTR [rax],al
 243:	60                   	(bad)  
 244:	0e                   	(bad)  
 245:	11 02                	adc    DWORD PTR [rdx],eax
 247:	00 00                	add    BYTE PTR [rax],al
 249:	07                   	(bad)  
 24a:	06                   	(bad)  
 24b:	01 e2                	add    edx,esp
 24d:	03 00                	add    eax,DWORD PTR [rax]
 24f:	00 68 0e             	add    BYTE PTR [rax+0xe],ch
 252:	a8 02                	test   al,0x2
 254:	00 00                	add    BYTE PTR [rax],al
 256:	07                   	(bad)  
 257:	08 01                	or     BYTE PTR [rcx],al
 259:	53                   	push   rbx
 25a:	01 00                	add    DWORD PTR [rax],eax
 25c:	00 70 0e             	add    BYTE PTR [rax+0xe],dh
 25f:	61                   	(bad)  
 260:	02 00                	add    al,BYTE PTR [rax]
 262:	00 07                	add    BYTE PTR [rdi],al
 264:	0c 01                	or     al,0x1
 266:	53                   	push   rbx
 267:	01 00                	add    DWORD PTR [rax],eax
 269:	00 74 0e 12          	add    BYTE PTR [rsi+rcx*1+0x12],dh
 26d:	00 00                	add    BYTE PTR [rax],al
 26f:	00 07                	add    BYTE PTR [rdi],al
 271:	0e                   	(bad)  
 272:	01 61 01             	add    DWORD PTR [rcx+0x1],esp
 275:	00 00                	add    BYTE PTR [rax],al
 277:	78 0e                	js     287 <_init-0x400141>
 279:	03 01                	add    eax,DWORD PTR [rcx]
 27b:	00 00                	add    BYTE PTR [rax],al
 27d:	07                   	(bad)  
 27e:	12 01                	adc    al,BYTE PTR [rcx]
 280:	37                   	(bad)  
 281:	01 00                	add    DWORD PTR [rax],eax
 283:	00 80 0e 84 02 00    	add    BYTE PTR [rax+0x2840e],al
 289:	00 07                	add    BYTE PTR [rdi],al
 28b:	13 01                	adc    eax,DWORD PTR [rcx]
 28d:	45 01 00             	add    DWORD PTR [r8],r8d
 290:	00 82 0e 5c 01 00    	add    BYTE PTR [rdx+0x15c0e],al
 296:	00 07                	add    BYTE PTR [rdi],al
 298:	14 01                	adc    al,0x1
 29a:	e8 03 00 00 83       	call   ffffffff830002a2 <_end+0xffffffff829ff262>
 29f:	0e                   	(bad)  
 2a0:	f4                   	hlt    
 2a1:	00 00                	add    BYTE PTR [rax],al
 2a3:	00 07                	add    BYTE PTR [rdi],al
 2a5:	18 01                	sbb    BYTE PTR [rcx],al
 2a7:	f8                   	clc    
 2a8:	03 00                	add    eax,DWORD PTR [rax]
 2aa:	00 88 0e 16 00 00    	add    BYTE PTR [rax+0x160e],cl
 2b0:	00 07                	add    BYTE PTR [rdi],al
 2b2:	21 01                	and    DWORD PTR [rcx],eax
 2b4:	6c                   	ins    BYTE PTR es:[rdi],dx
 2b5:	01 00                	add    DWORD PTR [rax],eax
 2b7:	00 90 0e b4 01 00    	add    BYTE PTR [rax+0x1b40e],dl
 2bd:	00 07                	add    BYTE PTR [rdi],al
 2bf:	29 01                	sub    DWORD PTR [rcx],eax
 2c1:	7e 01                	jle    2c4 <_init-0x400104>
 2c3:	00 00                	add    BYTE PTR [rax],al
 2c5:	98                   	cwde   
 2c6:	0e                   	(bad)  
 2c7:	bb 01 00 00 07       	mov    ebx,0x7000001
 2cc:	2a 01                	sub    al,BYTE PTR [rcx]
 2ce:	7e 01                	jle    2d1 <_init-0x4000f7>
 2d0:	00 00                	add    BYTE PTR [rax],al
 2d2:	a0 0e c2 01 00 00 07 	movabs al,ds:0x12b07000001c20e
 2d9:	2b 01 
 2db:	7e 01                	jle    2de <_init-0x4000ea>
 2dd:	00 00                	add    BYTE PTR [rax],al
 2df:	a8 0e                	test   al,0xe
 2e1:	c9                   	leave  
 2e2:	01 00                	add    DWORD PTR [rax],eax
 2e4:	00 07                	add    BYTE PTR [rdi],al
 2e6:	2c 01                	sub    al,0x1
 2e8:	7e 01                	jle    2eb <_init-0x4000dd>
 2ea:	00 00                	add    BYTE PTR [rax],al
 2ec:	b0 0e                	mov    al,0xe
 2ee:	d0 01                	rol    BYTE PTR [rcx],1
 2f0:	00 00                	add    BYTE PTR [rax],al
 2f2:	07                   	(bad)  
 2f3:	2e 01 1e             	add    DWORD PTR cs:[rsi],ebx
 2f6:	01 00                	add    DWORD PTR [rax],eax
 2f8:	00 b8 0e 69 02 00    	add    BYTE PTR [rax+0x2690e],bh
 2fe:	00 07                	add    BYTE PTR [rdi],al
 300:	2f                   	(bad)  
 301:	01 53 01             	add    DWORD PTR [rbx+0x1],edx
 304:	00 00                	add    BYTE PTR [rax],al
 306:	c0 0e 75             	ror    BYTE PTR [rsi],0x75
 309:	01 00                	add    DWORD PTR [rax],eax
 30b:	00 07                	add    BYTE PTR [rdi],al
 30d:	31 01                	xor    DWORD PTR [rcx],eax
 30f:	fe 03                	inc    BYTE PTR [rbx]
 311:	00 00                	add    BYTE PTR [rax],al
 313:	c4                   	(bad)  
 314:	00 0f                	add    BYTE PTR [rdi],cl
 316:	08 08                	or     BYTE PTR [rax],cl
 318:	53                   	push   rbx
 319:	18 02                	sbb    BYTE PTR [rdx],al
 31b:	00 00                	add    BYTE PTR [rax],al
 31d:	59                   	pop    rcx
 31e:	03 00                	add    eax,DWORD PTR [rax]
 320:	00 10                	add    BYTE PTR [rax],dl
 322:	04 08                	add    al,0x8
 324:	56                   	push   rsi
 325:	40 03 00             	rex add eax,DWORD PTR [rax]
 328:	00 11                	add    BYTE PTR [rcx],dl
 32a:	2d 00 00 00 08       	sub    eax,0x8000000
 32f:	58                   	pop    rax
 330:	3e 01 00             	add    DWORD PTR ds:[rax],eax
 333:	00 11                	add    BYTE PTR [rcx],dl
 335:	b0 02                	mov    al,0x2
 337:	00 00                	add    BYTE PTR [rax],al
 339:	08 5c 59 03          	or     BYTE PTR [rcx+rbx*2+0x3],bl
 33d:	00 00                	add    BYTE PTR [rax],al
 33f:	00 0d b9 00 00 00    	add    BYTE PTR [rip+0xb9],cl        # 3fe <_init-0x3fffca>
 345:	08 54 53 01          	or     BYTE PTR [rbx+rdx*2+0x1],dl
 349:	00 00                	add    BYTE PTR [rax],al
 34b:	00 0d 33 00 00 00    	add    BYTE PTR [rip+0x33],cl        # 384 <_init-0x400044>
 351:	08 5d 21             	or     BYTE PTR [rbp+0x21],bl
 354:	03 00                	add    eax,DWORD PTR [rax]
 356:	00 04 00             	add    BYTE PTR [rax+rax*1],al
 359:	12 86 01 00 00 69    	adc    al,BYTE PTR [rsi+0x69000001]
 35f:	03 00                	add    eax,DWORD PTR [rax]
 361:	00 13                	add    BYTE PTR [rbx],dl
 363:	77 01                	ja     366 <_init-0x400062>
 365:	00 00                	add    BYTE PTR [rax],al
 367:	03 00                	add    eax,DWORD PTR [rax]
 369:	07                   	(bad)  
 36a:	1a 02                	sbb    al,BYTE PTR [rdx]
 36c:	00 00                	add    BYTE PTR [rax],al
 36e:	08 5e 15             	or     BYTE PTR [rsi+0x15],bl
 371:	03 00                	add    eax,DWORD PTR [rax]
 373:	00 0f                	add    BYTE PTR [rdi],cl
 375:	10 09                	adc    BYTE PTR [rcx],cl
 377:	16                   	(bad)  
 378:	56                   	push   rsi
 379:	02 00                	add    al,BYTE PTR [rax]
 37b:	00 99 03 00 00 0d    	add    BYTE PTR [rcx+0xd000003],bl
 381:	59                   	pop    rcx
 382:	00 00                	add    BYTE PTR [rax],al
 384:	00 09                	add    BYTE PTR [rcx],cl
 386:	17                   	(bad)  
 387:	61                   	(bad)  
 388:	01 00                	add    DWORD PTR [rax],eax
 38a:	00 00                	add    BYTE PTR [rax],al
 38c:	0d b7 02 00 00       	or     eax,0x2b7
 391:	09 18                	or     DWORD PTR [rax],ebx
 393:	69 03 00 00 08 00    	imul   eax,DWORD PTR [rbx],0x80000
 399:	07                   	(bad)  
 39a:	57                   	push   rdi
 39b:	02 00                	add    al,BYTE PTR [rax]
 39d:	00 09                	add    BYTE PTR [rcx],cl
 39f:	19 74 03 00          	sbb    DWORD PTR [rbx+rax*1+0x0],esi
 3a3:	00 14 d3             	add    BYTE PTR [rbx+rdx*8],dl
 3a6:	02 00                	add    al,BYTE PTR [rax]
 3a8:	00 07                	add    BYTE PTR [rdi],al
 3aa:	96                   	xchg   esi,eax
 3ab:	0c 51                	or     al,0x51
 3ad:	01 00                	add    DWORD PTR [rax],eax
 3af:	00 18                	add    BYTE PTR [rax],bl
 3b1:	07                   	(bad)  
 3b2:	9c                   	pushf  
 3b3:	dc 03                	fadd   QWORD PTR [rbx]
 3b5:	00 00                	add    BYTE PTR [rax],al
 3b7:	0d ae 01 00 00       	or     eax,0x1ae
 3bc:	07                   	(bad)  
 3bd:	9d                   	popf   
 3be:	dc 03                	fadd   QWORD PTR [rbx]
 3c0:	00 00                	add    BYTE PTR [rax],al
 3c2:	00 0d 21 01 00 00    	add    BYTE PTR [rip+0x121],cl        # 4e9 <_init-0x3ffedf>
 3c8:	07                   	(bad)  
 3c9:	9e                   	sahf   
 3ca:	e2 03                	loop   3cf <_init-0x3ffff9>
 3cc:	00 00                	add    BYTE PTR [rax],al
 3ce:	08 0d 5a 00 00 00    	or     BYTE PTR [rip+0x5a],cl        # 42e <_init-0x3fff9a>
 3d4:	07                   	(bad)  
 3d5:	a2 53 01 00 00 10 00 	movabs ds:0x80b001000000153,al
 3dc:	0b 08 
 3de:	ab                   	stos   DWORD PTR es:[rdi],eax
 3df:	03 00                	add    eax,DWORD PTR [rax]
 3e1:	00 0b                	add    BYTE PTR [rbx],cl
 3e3:	08 98 01 00 00 12    	or     BYTE PTR [rax+0x12000001],bl
 3e9:	86 01                	xchg   BYTE PTR [rcx],al
 3eb:	00 00                	add    BYTE PTR [rax],al
 3ed:	f8                   	clc    
 3ee:	03 00                	add    eax,DWORD PTR [rax]
 3f0:	00 13                	add    BYTE PTR [rbx],dl
 3f2:	77 01                	ja     3f5 <_init-0x3fffd3>
 3f4:	00 00                	add    BYTE PTR [rax],al
 3f6:	00 00                	add    BYTE PTR [rax],al
 3f8:	0b 08                	or     ecx,DWORD PTR [rax]
 3fa:	a4                   	movs   BYTE PTR es:[rdi],BYTE PTR ds:[rsi]
 3fb:	03 00                	add    eax,DWORD PTR [rax]
 3fd:	00 12                	add    BYTE PTR [rdx],dl
 3ff:	86 01                	xchg   BYTE PTR [rcx],al
 401:	00 00                	add    BYTE PTR [rax],al
 403:	0e                   	(bad)  
 404:	04 00                	add    al,0x0
 406:	00 13                	add    BYTE PTR [rbx],dl
 408:	77 01                	ja     40b <_init-0x3fffbd>
 40a:	00 00                	add    BYTE PTR [rax],al
 40c:	13 00                	adc    eax,DWORD PTR [rax]
 40e:	0b 08                	or     ecx,DWORD PTR [rax]
 410:	14 04                	adc    al,0x4
 412:	00 00                	add    BYTE PTR [rax],al
 414:	15 86 01 00 00       	adc    eax,0x186
 419:	07                   	(bad)  
 41a:	5a                   	pop    rdx
 41b:	02 00                	add    al,BYTE PTR [rax]
 41d:	00 06                	add    BYTE PTR [rsi],al
 41f:	6e                   	outs   dx,BYTE PTR ds:[rsi]
 420:	99                   	cdq    
 421:	03 00                	add    eax,DWORD PTR [rax]
 423:	00 16                	add    BYTE PTR [rsi],dl
 425:	30 01                	xor    BYTE PTR [rcx],al
 427:	00 00                	add    BYTE PTR [rax],al
 429:	06                   	(bad)  
 42a:	3a 03                	cmp    al,BYTE PTR [rbx]
 42c:	36 04 00             	ss add al,0x0
 42f:	00 17                	add    BYTE PTR [rdi],dl
 431:	36 04 00             	ss add al,0x0
 434:	00 00                	add    BYTE PTR [rax],al
 436:	0b 08                	or     ecx,DWORD PTR [rax]
 438:	8d 01                	lea    eax,[rcx]
 43a:	00 00                	add    BYTE PTR [rax],al
 43c:	18 d1                	sbb    cl,dl
 43e:	00 00                	add    BYTE PTR [rax],al
 440:	00 06                	add    BYTE PTR [rsi],al
 442:	ed                   	in     eax,dx
 443:	53                   	push   rbx
 444:	01 00                	add    DWORD PTR [rax],eax
 446:	00 51 04             	add    BYTE PTR [rcx+0x4],dl
 449:	00 00                	add    BYTE PTR [rax],al
 44b:	17                   	(bad)  
 44c:	36 04 00             	ss add al,0x0
 44f:	00 00                	add    BYTE PTR [rax],al
 451:	19 1c 01             	sbb    DWORD PTR [rcx+rax*1],ebx
 454:	00 00                	add    BYTE PTR [rax],al
 456:	06                   	(bad)  
 457:	3c 03                	cmp    al,0x3
 459:	53                   	push   rbx
 45a:	01 00                	add    DWORD PTR [rax],eax
 45c:	00 67 04             	add    BYTE PTR [rdi+0x4],ah
 45f:	00 00                	add    BYTE PTR [rax],al
 461:	17                   	(bad)  
 462:	36 04 00             	ss add al,0x0
 465:	00 00                	add    BYTE PTR [rax],al
 467:	19 cc                	sbb    esp,ecx
 469:	02 00                	add    al,BYTE PTR [rax]
 46b:	00 06                	add    BYTE PTR [rsi],al
 46d:	3e 03 53 01          	add    edx,DWORD PTR ds:[rbx+0x1]
 471:	00 00                	add    BYTE PTR [rax],al
 473:	7d 04                	jge    479 <_init-0x3fff4f>
 475:	00 00                	add    BYTE PTR [rax],al
 477:	17                   	(bad)  
 478:	36 04 00             	ss add al,0x0
 47b:	00 00                	add    BYTE PTR [rax],al
 47d:	18 1e                	sbb    BYTE PTR [rsi],bl
 47f:	00 00                	add    BYTE PTR [rax],al
 481:	00 06                	add    BYTE PTR [rsi],al
 483:	f2 53                	repnz push rbx
 485:	01 00                	add    DWORD PTR [rax],eax
 487:	00 92 04 00 00 17    	add    BYTE PTR [rdx+0x17000004],dl
 48d:	36 04 00             	ss add al,0x0
 490:	00 00                	add    BYTE PTR [rax],al
 492:	19 82 00 00 00 06    	sbb    DWORD PTR [rdx+0x6000000],eax
 498:	13 02                	adc    eax,DWORD PTR [rdx]
 49a:	53                   	push   rbx
 49b:	01 00                	add    DWORD PTR [rax],eax
 49d:	00 a8 04 00 00 17    	add    BYTE PTR [rax+0x17000004],ch
 4a3:	36 04 00             	ss add al,0x0
 4a6:	00 00                	add    BYTE PTR [rax],al
 4a8:	19 c1                	sbb    ecx,eax
 4aa:	00 00                	add    BYTE PTR [rax],al
 4ac:	00 06                	add    BYTE PTR [rsi],al
 4ae:	1e                   	(bad)  
 4af:	03 53 01             	add    edx,DWORD PTR [rbx+0x1]
 4b2:	00 00                	add    BYTE PTR [rax],al
 4b4:	c3                   	ret    
 4b5:	04 00                	add    al,0x0
 4b7:	00 17                	add    BYTE PTR [rdi],dl
 4b9:	36 04 00             	ss add al,0x0
 4bc:	00 17                	add    BYTE PTR [rdi],dl
 4be:	c3                   	ret    
 4bf:	04 00                	add    al,0x0
 4c1:	00 00                	add    BYTE PTR [rax],al
 4c3:	0b 08                	or     ecx,DWORD PTR [rax]
 4c5:	19 04 00             	sbb    DWORD PTR [rax+rax*1],eax
 4c8:	00 19                	add    BYTE PTR [rcx],bl
 4ca:	b3 00                	mov    bl,0x0
 4cc:	00 00                	add    BYTE PTR [rax],al
 4ce:	06                   	(bad)  
 4cf:	6e                   	outs   dx,BYTE PTR ds:[rsi]
 4d0:	02 80 01 00 00 e9    	add    al,BYTE PTR [rax-0x16ffffff]
 4d6:	04 00                	add    al,0x0
 4d8:	00 17                	add    BYTE PTR [rdi],dl
 4da:	80 01 00             	add    BYTE PTR [rcx],0x0
 4dd:	00 17                	add    BYTE PTR [rdi],dl
 4df:	53                   	push   rbx
 4e0:	01 00                	add    DWORD PTR [rax],eax
 4e2:	00 17                	add    BYTE PTR [rdi],dl
 4e4:	36 04 00             	ss add al,0x0
 4e7:	00 00                	add    BYTE PTR [rax],al
 4e9:	19 0c 00             	sbb    DWORD PTR [rax+rax*1],ecx
 4ec:	00 00                	add    BYTE PTR [rax],al
 4ee:	06                   	(bad)  
 4ef:	10 01                	adc    BYTE PTR [rcx],al
 4f1:	36 04 00             	ss add al,0x0
 4f4:	00 04 05 00 00 17 0e 	add    BYTE PTR [rax*1+0xe170000],al
 4fb:	04 00                	add    al,0x0
 4fd:	00 17                	add    BYTE PTR [rdi],dl
 4ff:	0e                   	(bad)  
 500:	04 00                	add    al,0x0
 502:	00 00                	add    BYTE PTR [rax],al
 504:	19 bf 02 00 00 06    	sbb    DWORD PTR [rdi+0x6000002],edi
 50a:	c5 02 1e             	(bad)  
 50d:	01 00                	add    DWORD PTR [rax],eax
 50f:	00 29                	add    BYTE PTR [rcx],ch
 511:	05 00 00 17 7e       	add    eax,0x7e170000
 516:	01 00                	add    DWORD PTR [rax],eax
 518:	00 17                	add    BYTE PTR [rdi],dl
 51a:	1e                   	(bad)  
 51b:	01 00                	add    DWORD PTR [rax],eax
 51d:	00 17                	add    BYTE PTR [rdi],dl
 51f:	1e                   	(bad)  
 520:	01 00                	add    DWORD PTR [rax],eax
 522:	00 17                	add    BYTE PTR [rdi],dl
 524:	36 04 00             	ss add al,0x0
 527:	00 00                	add    BYTE PTR [rax],al
 529:	19 95 00 00 00 06    	sbb    DWORD PTR [rbp+0x6000000],edx
 52f:	16                   	(bad)  
 530:	01 36                	add    DWORD PTR [rsi],esi
 532:	04 00                	add    al,0x0
 534:	00 49 05             	add    BYTE PTR [rcx+0x5],cl
 537:	00 00                	add    BYTE PTR [rax],al
 539:	17                   	(bad)  
 53a:	0e                   	(bad)  
 53b:	04 00                	add    al,0x0
 53d:	00 17                	add    BYTE PTR [rdi],dl
 53f:	0e                   	(bad)  
 540:	04 00                	add    al,0x0
 542:	00 17                	add    BYTE PTR [rdi],dl
 544:	36 04 00             	ss add al,0x0
 547:	00 00                	add    BYTE PTR [rax],al
 549:	19 e6                	sbb    esi,esp
 54b:	00 00                	add    BYTE PTR [rax],al
 54d:	00 06                	add    BYTE PTR [rsi],al
 54f:	ed                   	in     eax,dx
 550:	02 53 01             	add    dl,BYTE PTR [rbx+0x1]
 553:	00 00                	add    BYTE PTR [rax],al
 555:	69 05 00 00 17 36 04 	imul   eax,DWORD PTR [rip+0x36170000],0x17000004        # 3617055f <_end+0x35b6f51f>
 55c:	00 00 17 
 55f:	5a                   	pop    rdx
 560:	01 00                	add    DWORD PTR [rax],eax
 562:	00 17                	add    BYTE PTR [rdi],dl
 564:	53                   	push   rbx
 565:	01 00                	add    DWORD PTR [rax],eax
 567:	00 00                	add    BYTE PTR [rax],al
 569:	19 d7                	sbb    edi,edx
 56b:	01 00                	add    DWORD PTR [rax],eax
 56d:	00 06                	add    BYTE PTR [rsi],al
 56f:	23 03                	and    eax,DWORD PTR [rbx]
 571:	53                   	push   rbx
 572:	01 00                	add    DWORD PTR [rax],eax
 574:	00 84 05 00 00 17 36 	add    BYTE PTR [rbp+rax*1+0x36170000],al
 57b:	04 00                	add    al,0x0
 57d:	00 17                	add    BYTE PTR [rdi],dl
 57f:	84 05 00 00 00 0b    	test   BYTE PTR [rip+0xb000000],al        # b000585 <_end+0xa9ff545>
 585:	08 8a 05 00 00 15    	or     BYTE PTR [rdx+0x15000005],cl
 58b:	19 04 00             	sbb    DWORD PTR [rax+rax*1],eax
 58e:	00 19                	add    BYTE PTR [rcx],bl
 590:	16                   	(bad)  
 591:	01 00                	add    DWORD PTR [rax],eax
 593:	00 06                	add    BYTE PTR [rsi],al
 595:	f2 02 5a 01          	repnz add bl,BYTE PTR [rdx+0x1]
 599:	00 00                	add    BYTE PTR [rax],al
 59b:	a5                   	movs   DWORD PTR es:[rdi],DWORD PTR ds:[rsi]
 59c:	05 00 00 17 36       	add    eax,0x36170000
 5a1:	04 00                	add    al,0x0
 5a3:	00 00                	add    BYTE PTR [rax],al
 5a5:	19 83 00 00 00 06    	sbb    DWORD PTR [rbx+0x6000000],eax
 5ab:	14 02                	adc    al,0x2
 5ad:	53                   	push   rbx
 5ae:	01 00                	add    DWORD PTR [rax],eax
 5b0:	00 bb 05 00 00 17    	add    BYTE PTR [rbx+0x17000005],bh
 5b6:	36 04 00             	ss add al,0x0
 5b9:	00 00                	add    BYTE PTR [rax],al
 5bb:	1a ec                	sbb    ch,ah
 5bd:	00 00                	add    BYTE PTR [rax],al
 5bf:	00 06                	add    BYTE PTR [rsi],al
 5c1:	1a 02                	sbb    al,BYTE PTR [rdx]
 5c3:	53                   	push   rbx
 5c4:	01 00                	add    DWORD PTR [rax],eax
 5c6:	00 16                	add    BYTE PTR [rsi],dl
 5c8:	0f 01 00             	sgdt   [rax]
 5cb:	00 06                	add    BYTE PTR [rsi],al
 5cd:	4e 03 d9             	rex.WRX add r11,rcx
 5d0:	05 00 00 17 0e       	add    eax,0xe170000
 5d5:	04 00                	add    al,0x0
 5d7:	00 00                	add    BYTE PTR [rax],al
 5d9:	18 d8                	sbb    al,bl
 5db:	00 00                	add    BYTE PTR [rax],al
 5dd:	00 06                	add    BYTE PTR [rsi],al
 5df:	b2 53                	mov    dl,0x53
 5e1:	01 00                	add    DWORD PTR [rax],eax
 5e3:	00 ee                	add    dh,ch
 5e5:	05 00 00 17 0e       	add    eax,0xe170000
 5ea:	04 00                	add    al,0x0
 5ec:	00 00                	add    BYTE PTR [rax],al
 5ee:	18 4f 02             	sbb    BYTE PTR [rdi+0x2],cl
 5f1:	00 00                	add    BYTE PTR [rax],al
 5f3:	06                   	(bad)  
 5f4:	b4 53                	mov    ah,0x53
 5f6:	01 00                	add    DWORD PTR [rax],eax
 5f8:	00 08                	add    BYTE PTR [rax],cl
 5fa:	06                   	(bad)  
 5fb:	00 00                	add    BYTE PTR [rax],al
 5fd:	17                   	(bad)  
 5fe:	0e                   	(bad)  
 5ff:	04 00                	add    al,0x0
 601:	00 17                	add    BYTE PTR [rdi],dl
 603:	0e                   	(bad)  
 604:	04 00                	add    al,0x0
 606:	00 00                	add    BYTE PTR [rax],al
 608:	16                   	(bad)  
 609:	a1 02 00 00 06 f7 02 	movabs eax,ds:0x61a02f706000002
 610:	1a 06 
 612:	00 00                	add    BYTE PTR [rax],al
 614:	17                   	(bad)  
 615:	36 04 00             	ss add al,0x0
 618:	00 00                	add    BYTE PTR [rax],al
 61a:	16                   	(bad)  
 61b:	df 00                	fild   WORD PTR [rax]
 61d:	00 00                	add    BYTE PTR [rax],al
 61f:	06                   	(bad)  
 620:	4c 01 31             	add    QWORD PTR [rcx],r14
 623:	06                   	(bad)  
 624:	00 00                	add    BYTE PTR [rax],al
 626:	17                   	(bad)  
 627:	36 04 00             	ss add al,0x0
 62a:	00 17                	add    BYTE PTR [rdi],dl
 62c:	80 01 00             	add    BYTE PTR [rcx],0x0
 62f:	00 00                	add    BYTE PTR [rax],al
 631:	19 c9                	sbb    ecx,ecx
 633:	00 00                	add    BYTE PTR [rax],al
 635:	00 06                	add    BYTE PTR [rsi],al
 637:	50                   	push   rax
 638:	01 53 01             	add    DWORD PTR [rbx+0x1],edx
 63b:	00 00                	add    BYTE PTR [rax],al
 63d:	56                   	push   rsi
 63e:	06                   	(bad)  
 63f:	00 00                	add    BYTE PTR [rax],al
 641:	17                   	(bad)  
 642:	36 04 00             	ss add al,0x0
 645:	00 17                	add    BYTE PTR [rdi],dl
 647:	80 01 00             	add    BYTE PTR [rcx],0x0
 64a:	00 17                	add    BYTE PTR [rdi],dl
 64c:	53                   	push   rbx
 64d:	01 00                	add    DWORD PTR [rax],eax
 64f:	00 17                	add    BYTE PTR [rdi],dl
 651:	1e                   	(bad)  
 652:	01 00                	add    DWORD PTR [rax],eax
 654:	00 00                	add    BYTE PTR [rax],al
 656:	1b a6 01 00 00 06    	sbb    esp,DWORD PTR [rsi+0x6000001]
 65c:	c3                   	ret    
 65d:	36 04 00             	ss add al,0x0
 660:	00 18                	add    BYTE PTR [rax],bl
 662:	7d 02                	jge    666 <_init-0x3ffd62>
 664:	00 00                	add    BYTE PTR [rax],al
 666:	06                   	(bad)  
 667:	d1 80 01 00 00 76    	rol    DWORD PTR [rax+0x76000001],1
 66d:	06                   	(bad)  
 66e:	00 00                	add    BYTE PTR [rax],al
 670:	17                   	(bad)  
 671:	80 01 00             	add    BYTE PTR [rcx],0x0
 674:	00 00                	add    BYTE PTR [rax],al
 676:	19 c5                	sbb    ebp,eax
 678:	02 00                	add    al,BYTE PTR [rax]
 67a:	00 06                	add    BYTE PTR [rsi],al
 67c:	be 02 53 01 00       	mov    esi,0x15302
 681:	00 91 06 00 00 17    	add    BYTE PTR [rcx+0x17000006],dl
 687:	53                   	push   rbx
 688:	01 00                	add    DWORD PTR [rax],eax
 68a:	00 17                	add    BYTE PTR [rdi],dl
 68c:	36 04 00             	ss add al,0x0
 68f:	00 00                	add    BYTE PTR [rax],al
 691:	1c 68                	sbb    al,0x68
 693:	00 00                	add    BYTE PTR [rax],al
 695:	00 01                	add    BYTE PTR [rcx],al
 697:	03 53 01             	add    edx,DWORD PTR [rbx+0x1]
 69a:	00 00                	add    BYTE PTR [rax],al
 69c:	26 05 40 00 00 00    	es add eax,0x40
 6a2:	00 00                	add    BYTE PTR [rax],al
 6a4:	1f                   	(bad)  
 6a5:	00 00                	add    BYTE PTR [rax],al
 6a7:	00 00                	add    BYTE PTR [rax],al
 6a9:	00 00                	add    BYTE PTR [rax],al
 6ab:	00 01                	add    BYTE PTR [rcx],al
 6ad:	9c                   	pushf  
	...

Disassembly of section .debug_abbrev:

0000000000000000 <.debug_abbrev>:
   0:	01 11                	add    DWORD PTR [rcx],edx
   2:	01 25 0e 13 0b 03    	add    DWORD PTR [rip+0x30b130e],esp        # 30b1316 <_end+0x2ab02d6>
   8:	0e                   	(bad)  
   9:	1b 0e                	sbb    ecx,DWORD PTR [rsi]
   b:	11 01                	adc    DWORD PTR [rcx],eax
   d:	12 07                	adc    al,BYTE PTR [rdi]
   f:	10 17                	adc    BYTE PTR [rdi],dl
  11:	00 00                	add    BYTE PTR [rax],al
  13:	02 39                	add    bh,BYTE PTR [rcx]
  15:	01 03                	add    DWORD PTR [rbx],eax
  17:	08 3a                	or     BYTE PTR [rdx],bh
  19:	0b 3b                	or     edi,DWORD PTR [rbx]
  1b:	0b 01                	or     eax,DWORD PTR [rcx]
  1d:	13 00                	adc    eax,DWORD PTR [rax]
  1f:	00 03                	add    BYTE PTR [rbx],al
  21:	39 00                	cmp    DWORD PTR [rax],eax
  23:	03 0e                	add    ecx,DWORD PTR [rsi]
  25:	3a 0b                	cmp    cl,BYTE PTR [rbx]
  27:	3b 0b                	cmp    ecx,DWORD PTR [rbx]
  29:	00 00                	add    BYTE PTR [rax],al
  2b:	04 3a                	add    al,0x3a
  2d:	00 3a                	add    BYTE PTR [rdx],bh
  2f:	0b 3b                	or     edi,DWORD PTR [rbx]
  31:	0b 18                	or     ebx,DWORD PTR [rax]
  33:	13 00                	adc    eax,DWORD PTR [rax]
  35:	00 05 08 00 3a 0b    	add    BYTE PTR [rip+0xb3a0008],al        # b3a0043 <_end+0xad9f003>
  3b:	3b 0b                	cmp    ecx,DWORD PTR [rbx]
  3d:	18 13                	sbb    BYTE PTR [rbx],dl
  3f:	00 00                	add    BYTE PTR [rax],al
  41:	06                   	(bad)  
  42:	39 01                	cmp    DWORD PTR [rcx],eax
  44:	03 0e                	add    ecx,DWORD PTR [rsi]
  46:	3a 0b                	cmp    cl,BYTE PTR [rbx]
  48:	3b 0b                	cmp    ecx,DWORD PTR [rbx]
  4a:	01 13                	add    DWORD PTR [rbx],edx
  4c:	00 00                	add    BYTE PTR [rax],al
  4e:	07                   	(bad)  
  4f:	16                   	(bad)  
  50:	00 03                	add    BYTE PTR [rbx],al
  52:	0e                   	(bad)  
  53:	3a 0b                	cmp    cl,BYTE PTR [rbx]
  55:	3b 0b                	cmp    ecx,DWORD PTR [rbx]
  57:	49 13 00             	adc    rax,QWORD PTR [r8]
  5a:	00 08                	add    BYTE PTR [rax],cl
  5c:	24 00                	and    al,0x0
  5e:	0b 0b                	or     ecx,DWORD PTR [rbx]
  60:	3e 0b 03             	or     eax,DWORD PTR ds:[rbx]
  63:	0e                   	(bad)  
  64:	00 00                	add    BYTE PTR [rax],al
  66:	09 24 00             	or     DWORD PTR [rax+rax*1],esp
  69:	0b 0b                	or     ecx,DWORD PTR [rbx]
  6b:	3e 0b 03             	or     eax,DWORD PTR ds:[rbx]
  6e:	08 00                	or     BYTE PTR [rax],al
  70:	00 0a                	add    BYTE PTR [rdx],cl
  72:	0f 00 0b             	str    WORD PTR [rbx]
  75:	0b 00                	or     eax,DWORD PTR [rax]
  77:	00 0b                	add    BYTE PTR [rbx],cl
  79:	0f 00 0b             	str    WORD PTR [rbx]
  7c:	0b 49 13             	or     ecx,DWORD PTR [rcx+0x13]
  7f:	00 00                	add    BYTE PTR [rax],al
  81:	0c 13                	or     al,0x13
  83:	01 03                	add    DWORD PTR [rbx],eax
  85:	0e                   	(bad)  
  86:	0b 0b                	or     ecx,DWORD PTR [rbx]
  88:	3a 0b                	cmp    cl,BYTE PTR [rbx]
  8a:	3b 0b                	cmp    ecx,DWORD PTR [rbx]
  8c:	01 13                	add    DWORD PTR [rbx],edx
  8e:	00 00                	add    BYTE PTR [rax],al
  90:	0d 0d 00 03 0e       	or     eax,0xe03000d
  95:	3a 0b                	cmp    cl,BYTE PTR [rbx]
  97:	3b 0b                	cmp    ecx,DWORD PTR [rbx]
  99:	49 13 38             	adc    rdi,QWORD PTR [r8]
  9c:	0b 00                	or     eax,DWORD PTR [rax]
  9e:	00 0e                	add    BYTE PTR [rsi],cl
  a0:	0d 00 03 0e 3a       	or     eax,0x3a0e0300
  a5:	0b 3b                	or     edi,DWORD PTR [rbx]
  a7:	05 49 13 38 0b       	add    eax,0xb381349
  ac:	00 00                	add    BYTE PTR [rax],al
  ae:	0f 13 01             	movlps QWORD PTR [rcx],xmm0
  b1:	0b 0b                	or     ecx,DWORD PTR [rbx]
  b3:	3a 0b                	cmp    cl,BYTE PTR [rbx]
  b5:	3b 0b                	cmp    ecx,DWORD PTR [rbx]
  b7:	6e                   	outs   dx,BYTE PTR ds:[rsi]
  b8:	0e                   	(bad)  
  b9:	01 13                	add    DWORD PTR [rbx],edx
  bb:	00 00                	add    BYTE PTR [rax],al
  bd:	10 17                	adc    BYTE PTR [rdi],dl
  bf:	01 0b                	add    DWORD PTR [rbx],ecx
  c1:	0b 3a                	or     edi,DWORD PTR [rdx]
  c3:	0b 3b                	or     edi,DWORD PTR [rbx]
  c5:	0b 01                	or     eax,DWORD PTR [rcx]
  c7:	13 00                	adc    eax,DWORD PTR [rax]
  c9:	00 11                	add    BYTE PTR [rcx],dl
  cb:	0d 00 03 0e 3a       	or     eax,0x3a0e0300
  d0:	0b 3b                	or     edi,DWORD PTR [rbx]
  d2:	0b 49 13             	or     ecx,DWORD PTR [rcx+0x13]
  d5:	00 00                	add    BYTE PTR [rax],al
  d7:	12 01                	adc    al,BYTE PTR [rcx]
  d9:	01 49 13             	add    DWORD PTR [rcx+0x13],ecx
  dc:	01 13                	add    DWORD PTR [rbx],edx
  de:	00 00                	add    BYTE PTR [rax],al
  e0:	13 21                	adc    esp,DWORD PTR [rcx]
  e2:	00 49 13             	add    BYTE PTR [rcx+0x13],cl
  e5:	2f                   	(bad)  
  e6:	0b 00                	or     eax,DWORD PTR [rax]
  e8:	00 14 16             	add    BYTE PTR [rsi+rdx*1],dl
  eb:	00 03                	add    BYTE PTR [rbx],al
  ed:	0e                   	(bad)  
  ee:	3a 0b                	cmp    cl,BYTE PTR [rbx]
  f0:	3b 0b                	cmp    ecx,DWORD PTR [rbx]
  f2:	00 00                	add    BYTE PTR [rax],al
  f4:	15 26 00 49 13       	adc    eax,0x13490026
  f9:	00 00                	add    BYTE PTR [rax],al
  fb:	16                   	(bad)  
  fc:	2e 01 3f             	add    DWORD PTR cs:[rdi],edi
  ff:	19 03                	sbb    DWORD PTR [rbx],eax
 101:	0e                   	(bad)  
 102:	3a 0b                	cmp    cl,BYTE PTR [rbx]
 104:	3b 05 3c 19 01 13    	cmp    eax,DWORD PTR [rip+0x1301193c]        # 13011a46 <_end+0x12a10a06>
 10a:	00 00                	add    BYTE PTR [rax],al
 10c:	17                   	(bad)  
 10d:	05 00 49 13 00       	add    eax,0x134900
 112:	00 18                	add    BYTE PTR [rax],bl
 114:	2e 01 3f             	add    DWORD PTR cs:[rdi],edi
 117:	19 03                	sbb    DWORD PTR [rbx],eax
 119:	0e                   	(bad)  
 11a:	3a 0b                	cmp    cl,BYTE PTR [rbx]
 11c:	3b 0b                	cmp    ecx,DWORD PTR [rbx]
 11e:	49 13 3c 19          	adc    rdi,QWORD PTR [r9+rbx*1]
 122:	01 13                	add    DWORD PTR [rbx],edx
 124:	00 00                	add    BYTE PTR [rax],al
 126:	19 2e                	sbb    DWORD PTR [rsi],ebp
 128:	01 3f                	add    DWORD PTR [rdi],edi
 12a:	19 03                	sbb    DWORD PTR [rbx],eax
 12c:	0e                   	(bad)  
 12d:	3a 0b                	cmp    cl,BYTE PTR [rbx]
 12f:	3b 05 49 13 3c 19    	cmp    eax,DWORD PTR [rip+0x193c1349]        # 193c147e <_end+0x18dc043e>
 135:	01 13                	add    DWORD PTR [rbx],edx
 137:	00 00                	add    BYTE PTR [rax],al
 139:	1a 2e                	sbb    ch,BYTE PTR [rsi]
 13b:	00 3f                	add    BYTE PTR [rdi],bh
 13d:	19 03                	sbb    DWORD PTR [rbx],eax
 13f:	0e                   	(bad)  
 140:	3a 0b                	cmp    cl,BYTE PTR [rbx]
 142:	3b 05 49 13 3c 19    	cmp    eax,DWORD PTR [rip+0x193c1349]        # 193c1491 <_end+0x18dc0451>
 148:	00 00                	add    BYTE PTR [rax],al
 14a:	1b 2e                	sbb    ebp,DWORD PTR [rsi]
 14c:	00 3f                	add    BYTE PTR [rdi],bh
 14e:	19 03                	sbb    DWORD PTR [rbx],eax
 150:	0e                   	(bad)  
 151:	3a 0b                	cmp    cl,BYTE PTR [rbx]
 153:	3b 0b                	cmp    ecx,DWORD PTR [rbx]
 155:	49 13 3c 19          	adc    rdi,QWORD PTR [r9+rbx*1]
 159:	00 00                	add    BYTE PTR [rax],al
 15b:	1c 2e                	sbb    al,0x2e
 15d:	00 3f                	add    BYTE PTR [rdi],bh
 15f:	19 03                	sbb    DWORD PTR [rbx],eax
 161:	0e                   	(bad)  
 162:	3a 0b                	cmp    cl,BYTE PTR [rbx]
 164:	3b 0b                	cmp    ecx,DWORD PTR [rbx]
 166:	49 13 11             	adc    rdx,QWORD PTR [r9]
 169:	01 12                	add    DWORD PTR [rdx],edx
 16b:	07                   	(bad)  
 16c:	40 18 96 42 19 00 00 	sbb    BYTE PTR [rsi+0x1942],dl
	...

Disassembly of section .debug_line:

0000000000000000 <.debug_line>:
   0:	3a 01                	cmp    al,BYTE PTR [rcx]
   2:	00 00                	add    BYTE PTR [rax],al
   4:	02 00                	add    al,BYTE PTR [rax]
   6:	20 01                	and    BYTE PTR [rcx],al
   8:	00 00                	add    BYTE PTR [rax],al
   a:	01 01                	add    DWORD PTR [rcx],eax
   c:	fb                   	sti    
   d:	0e                   	(bad)  
   e:	0d 00 01 01 01       	or     eax,0x1010100
  13:	01 00                	add    DWORD PTR [rax],eax
  15:	00 00                	add    BYTE PTR [rax],al
  17:	01 00                	add    DWORD PTR [rax],eax
  19:	00 01                	add    BYTE PTR [rcx],al
  1b:	2f                   	(bad)  
  1c:	75 73                	jne    91 <_init-0x400337>
  1e:	72 2f                	jb     4f <_init-0x400379>
  20:	69 6e 63 6c 75 64 65 	imul   ebp,DWORD PTR [rsi+0x63],0x6564756c
  27:	2f                   	(bad)  
  28:	63 2b                	movsxd ebp,DWORD PTR [rbx]
  2a:	2b 2f                	sub    ebp,DWORD PTR [rdi]
  2c:	35 00 2f 75 73       	xor    eax,0x73752f00
  31:	72 2f                	jb     62 <_init-0x400366>
  33:	69 6e 63 6c 75 64 65 	imul   ebp,DWORD PTR [rsi+0x63],0x6564756c
  3a:	2f                   	(bad)  
  3b:	78 38                	js     75 <_init-0x400353>
  3d:	36 5f                	ss pop rdi
  3f:	36 34 2d             	ss xor al,0x2d
  42:	6c                   	ins    BYTE PTR es:[rdi],dx
  43:	69 6e 75 78 2d 67 6e 	imul   ebp,DWORD PTR [rsi+0x75],0x6e672d78
  4a:	75 2f                	jne    7b <_init-0x40034d>
  4c:	63 2b                	movsxd ebp,DWORD PTR [rbx]
  4e:	2b 2f                	sub    ebp,DWORD PTR [rdi]
  50:	35 2f 62 69 74       	xor    eax,0x7469622f
  55:	73 00                	jae    57 <_init-0x400371>
  57:	2f                   	(bad)  
  58:	75 73                	jne    cd <_init-0x4002fb>
  5a:	72 2f                	jb     8b <_init-0x40033d>
  5c:	6c                   	ins    BYTE PTR es:[rdi],dx
  5d:	69 62 2f 67 63 63 2f 	imul   esp,DWORD PTR [rdx+0x2f],0x2f636367
  64:	78 38                	js     9e <_init-0x40032a>
  66:	36 5f                	ss pop rdi
  68:	36 34 2d             	ss xor al,0x2d
  6b:	6c                   	ins    BYTE PTR es:[rdi],dx
  6c:	69 6e 75 78 2d 67 6e 	imul   ebp,DWORD PTR [rsi+0x75],0x6e672d78
  73:	75 2f                	jne    a4 <_init-0x400324>
  75:	35 2f 69 6e 63       	xor    eax,0x636e692f
  7a:	6c                   	ins    BYTE PTR es:[rdi],dx
  7b:	75 64                	jne    e1 <_init-0x4002e7>
  7d:	65 00 2f             	add    BYTE PTR gs:[rdi],ch
  80:	75 73                	jne    f5 <_init-0x4002d3>
  82:	72 2f                	jb     b3 <_init-0x400315>
  84:	69 6e 63 6c 75 64 65 	imul   ebp,DWORD PTR [rsi+0x63],0x6564756c
  8b:	2f                   	(bad)  
  8c:	78 38                	js     c6 <_init-0x400302>
  8e:	36 5f                	ss pop rdi
  90:	36 34 2d             	ss xor al,0x2d
  93:	6c                   	ins    BYTE PTR es:[rdi],dx
  94:	69 6e 75 78 2d 67 6e 	imul   ebp,DWORD PTR [rsi+0x75],0x6e672d78
  9b:	75 2f                	jne    cc <_init-0x4002fc>
  9d:	62                   	(bad)  
  9e:	69 74 73 00 2f 75 73 	imul   esi,DWORD PTR [rbx+rsi*2+0x0],0x7273752f
  a5:	72 
  a6:	2f                   	(bad)  
  a7:	69 6e 63 6c 75 64 65 	imul   ebp,DWORD PTR [rsi+0x63],0x6564756c
  ae:	00 00                	add    BYTE PTR [rax],al
  b0:	70 6c                	jo     11e <_init-0x4002aa>
  b2:	74 2e                	je     e2 <_init-0x4002e6>
  b4:	63 70 70             	movsxd esi,DWORD PTR [rax+0x70]
  b7:	00 00                	add    BYTE PTR [rax],al
  b9:	00 00                	add    BYTE PTR [rax],al
  bb:	63 73 74             	movsxd esi,DWORD PTR [rbx+0x74]
  be:	64 69 6f 00 01 00 00 	imul   ebp,DWORD PTR fs:[rdi+0x0],0x63000001
  c5:	63 
  c6:	2b 2b                	sub    ebp,DWORD PTR [rbx]
  c8:	63 6f 6e             	movsxd ebp,DWORD PTR [rdi+0x6e]
  cb:	66 69 67 2e 68 00    	imul   sp,WORD PTR [rdi+0x2e],0x68
  d1:	02 00                	add    al,BYTE PTR [rax]
  d3:	00 73 74             	add    BYTE PTR [rbx+0x74],dh
  d6:	64 64 65 66 2e 68 00 	fs fs gs cs pushw 0x300
  dd:	03 
  de:	00 00                	add    BYTE PTR [rax],al
  e0:	74 79                	je     15b <_init-0x40026d>
  e2:	70 65                	jo     149 <_init-0x40027f>
  e4:	73 2e                	jae    114 <_init-0x4002b4>
  e6:	68 00 04 00 00       	push   0x400
  eb:	73 74                	jae    161 <_init-0x400267>
  ed:	64 69 6f 2e 68 00 05 	imul   ebp,DWORD PTR fs:[rdi+0x2e],0x50068
  f4:	00 
  f5:	00 6c 69 62          	add    BYTE PTR [rcx+rbp*2+0x62],ch
  f9:	69 6f 2e 68 00 05 00 	imul   ebp,DWORD PTR [rdi+0x2e],0x50068
 100:	00 77 63             	add    BYTE PTR [rdi+0x63],dh
 103:	68 61 72 2e 68       	push   0x682e7261
 108:	00 05 00 00 5f 47    	add    BYTE PTR [rip+0x475f0000],al        # 475f010e <_end+0x46fef0ce>
 10e:	5f                   	pop    rdi
 10f:	63 6f 6e             	movsxd ebp,DWORD PTR [rdi+0x6e]
 112:	66 69 67 2e 68 00    	imul   sp,WORD PTR [rdi+0x2e],0x68
 118:	05 00 00 3c 62       	add    eax,0x623c0000
 11d:	75 69                	jne    188 <_init-0x400240>
 11f:	6c                   	ins    BYTE PTR es:[rdi],dx
 120:	74 2d                	je     14f <_init-0x400279>
 122:	69 6e 3e 00 00 00 00 	imul   ebp,DWORD PTR [rsi+0x3e],0x0
 129:	00 00                	add    BYTE PTR [rax],al
 12b:	09 02                	or     DWORD PTR [rdx],eax
 12d:	26 05 40 00 00 00    	es add eax,0x40
 133:	00 00                	add    BYTE PTR [rax],al
 135:	14 4b                	adc    al,0x4b
 137:	08 3d 02 07 00 01    	or     BYTE PTR [rip+0x1000702],bh        # 100083f <_end+0x9ff7ff>
 13d:	01                   	.byte 0x1

Disassembly of section .debug_str:

0000000000000000 <.debug_str>:
   0:	5f                   	pop    rdi
   1:	49                   	rex.WB
   2:	4f 5f                	rex.WRXB pop r15
   4:	62                   	(bad)  
   5:	75 66                	jne    6d <_init-0x40035b>
   7:	5f                   	pop    rdi
   8:	65 6e                	outs   dx,BYTE PTR gs:[rsi]
   a:	64 00 66 6f          	add    BYTE PTR fs:[rsi+0x6f],ah
   e:	70 65                	jo     75 <_init-0x400353>
  10:	6e                   	outs   dx,BYTE PTR ds:[rsi]
  11:	00 5f 6f             	add    BYTE PTR [rdi+0x6f],bl
  14:	6c                   	ins    BYTE PTR es:[rdi],dx
  15:	64 5f                	fs pop rdi
  17:	6f                   	outs   dx,DWORD PTR ds:[rsi]
  18:	66 66 73 65          	data16 data16 jae 81 <_init-0x400347>
  1c:	74 00                	je     1e <_init-0x4003aa>
  1e:	66 66 6c             	data16 data16 ins BYTE PTR es:[rdi],dx
  21:	75 73                	jne    96 <_init-0x400332>
  23:	68 00 70 6c 74       	push   0x746c7000
  28:	2e 63 70 70          	movsxd esi,DWORD PTR cs:[rax+0x70]
  2c:	00 5f 5f             	add    BYTE PTR [rdi+0x5f],bl
  2f:	77 63                	ja     94 <_init-0x400334>
  31:	68 00 5f 5f 76       	push   0x765f5f00
  36:	61                   	(bad)  
  37:	6c                   	ins    BYTE PTR es:[rdi],dx
  38:	75 65                	jne    9f <_init-0x400329>
  3a:	00 5f 49             	add    BYTE PTR [rdi+0x49],bl
  3d:	4f 5f                	rex.WRXB pop r15
  3f:	73 61                	jae    a2 <_init-0x400326>
  41:	76 65                	jbe    a8 <_init-0x400320>
  43:	5f                   	pop    rdi
  44:	65 6e                	outs   dx,BYTE PTR gs:[rsi]
  46:	64 00 73 68          	add    BYTE PTR fs:[rbx+0x68],dh
  4a:	6f                   	outs   dx,DWORD PTR ds:[rsi]
  4b:	72 74                	jb     c1 <_init-0x400307>
  4d:	20 69 6e             	and    BYTE PTR [rcx+0x6e],ch
  50:	74 00                	je     52 <_init-0x400376>
  52:	73 69                	jae    bd <_init-0x40030b>
  54:	7a 65                	jp     bb <_init-0x40030d>
  56:	5f                   	pop    rdi
  57:	74 00                	je     59 <_init-0x40036f>
  59:	5f                   	pop    rdi
  5a:	5f                   	pop    rdi
  5b:	70 6f                	jo     cc <_init-0x4002fc>
  5d:	73 00                	jae    5f <_init-0x400369>
  5f:	73 69                	jae    ca <_init-0x4002fe>
  61:	7a 65                	jp     c8 <_init-0x400300>
  63:	74 79                	je     de <_init-0x4002ea>
  65:	70 65                	jo     cc <_init-0x4002fc>
  67:	00 6d 61             	add    BYTE PTR [rbp+0x61],ch
  6a:	69 6e 00 5f 49 4f 5f 	imul   ebp,DWORD PTR [rsi+0x0],0x5f4f495f
  71:	77 72                	ja     e5 <_init-0x4002e3>
  73:	69 74 65 5f 70 74 72 	imul   esi,DWORD PTR [rbp+riz*2+0x5f],0x727470
  7a:	00 
  7b:	5f                   	pop    rdi
  7c:	66 6c                	data16 ins BYTE PTR es:[rdi],dx
  7e:	61                   	(bad)  
  7f:	67 73 00             	addr32 jae 82 <_init-0x400346>
  82:	66 67 65 74 63       	data16 addr32 gs je ea <_init-0x4002de>
  87:	00 5f 49             	add    BYTE PTR [rdi+0x49],bl
  8a:	4f 5f                	rex.WRXB pop r15
  8c:	62                   	(bad)  
  8d:	75 66                	jne    f5 <_init-0x4002d3>
  8f:	5f                   	pop    rdi
  90:	62 61                	(bad)  
  92:	73 65                	jae    f9 <_init-0x4002cf>
  94:	00 66 72             	add    BYTE PTR [rsi+0x72],ah
  97:	65 6f                	outs   dx,DWORD PTR gs:[rsi]
  99:	70 65                	jo     100 <_init-0x4002c8>
  9b:	6e                   	outs   dx,BYTE PTR ds:[rsi]
  9c:	00 5f 6d             	add    BYTE PTR [rdi+0x6d],bl
  9f:	61                   	(bad)  
  a0:	72 6b                	jb     10d <_init-0x4002bb>
  a2:	65 72 73             	gs jb  118 <_init-0x4002b0>
  a5:	00 5f 49             	add    BYTE PTR [rdi+0x49],bl
  a8:	4f 5f                	rex.WRXB pop r15
  aa:	72 65                	jb     111 <_init-0x4002b7>
  ac:	61                   	(bad)  
  ad:	64 5f                	fs pop rdi
  af:	65 6e                	outs   dx,BYTE PTR gs:[rsi]
  b1:	64 00 66 67          	add    BYTE PTR fs:[rsi+0x67],ah
  b5:	65 74 73             	gs je  12b <_init-0x40029d>
  b8:	00 5f 5f             	add    BYTE PTR [rdi+0x5f],bl
  bb:	63 6f 75             	movsxd ebp,DWORD PTR [rdi+0x75]
  be:	6e                   	outs   dx,BYTE PTR ds:[rsi]
  bf:	74 00                	je     c1 <_init-0x400307>
  c1:	66 67 65 74 70       	data16 addr32 gs je 136 <_init-0x400292>
  c6:	6f                   	outs   dx,DWORD PTR ds:[rsi]
  c7:	73 00                	jae    c9 <_init-0x4002ff>
  c9:	73 65                	jae    130 <_init-0x400298>
  cb:	74 76                	je     143 <_init-0x400285>
  cd:	62                   	(bad)  
  ce:	75 66                	jne    136 <_init-0x400292>
  d0:	00 66 63             	add    BYTE PTR [rsi+0x63],ah
  d3:	6c                   	ins    BYTE PTR es:[rdi],dx
  d4:	6f                   	outs   dx,DWORD PTR ds:[rsi]
  d5:	73 65                	jae    13c <_init-0x40028c>
  d7:	00 72 65             	add    BYTE PTR [rdx+0x65],dh
  da:	6d                   	ins    DWORD PTR es:[rdi],dx
  db:	6f                   	outs   dx,DWORD PTR ds:[rsi]
  dc:	76 65                	jbe    143 <_init-0x400285>
  de:	00 73 65             	add    BYTE PTR [rbx+0x65],dh
  e1:	74 62                	je     145 <_init-0x400283>
  e3:	75 66                	jne    14b <_init-0x40027d>
  e5:	00 66 73             	add    BYTE PTR [rsi+0x73],ah
  e8:	65 65 6b 00 67       	gs imul eax,DWORD PTR gs:[rax],0x67
  ed:	65 74 63             	gs je  153 <_init-0x400275>
  f0:	68 61 72 00 5f       	push   0x5f007261
  f5:	6c                   	ins    BYTE PTR es:[rdi],dx
  f6:	6f                   	outs   dx,DWORD PTR ds:[rsi]
  f7:	63 6b 00             	movsxd ebp,DWORD PTR [rbx+0x0]
  fa:	6c                   	ins    BYTE PTR es:[rdi],dx
  fb:	6f                   	outs   dx,DWORD PTR ds:[rsi]
  fc:	6e                   	outs   dx,BYTE PTR ds:[rsi]
  fd:	67 20 69 6e          	and    BYTE PTR [ecx+0x6e],ch
 101:	74 00                	je     103 <_init-0x4002c5>
 103:	5f                   	pop    rdi
 104:	63 75 72             	movsxd esi,DWORD PTR [rbp+0x72]
 107:	5f                   	pop    rdi
 108:	63 6f 6c             	movsxd ebp,DWORD PTR [rdi+0x6c]
 10b:	75 6d                	jne    17a <_init-0x40024e>
 10d:	6e                   	outs   dx,BYTE PTR ds:[rsi]
 10e:	00 70 65             	add    BYTE PTR [rax+0x65],dh
 111:	72 72                	jb     185 <_init-0x400243>
 113:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 114:	72 00                	jb     116 <_init-0x4002b2>
 116:	66 74 65             	data16 je 17e <_init-0x40024a>
 119:	6c                   	ins    BYTE PTR es:[rdi],dx
 11a:	6c                   	ins    BYTE PTR es:[rdi],dx
 11b:	00 66 65             	add    BYTE PTR [rsi+0x65],ah
 11e:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 11f:	66 00 5f 73          	data16 add BYTE PTR [rdi+0x73],bl
 123:	62                   	(bad)  
 124:	75 66                	jne    18c <_init-0x40023c>
 126:	00 5f 49             	add    BYTE PTR [rdi+0x49],bl
 129:	4f 5f                	rex.WRXB pop r15
 12b:	46                   	rex.RX
 12c:	49                   	rex.WB
 12d:	4c                   	rex.WR
 12e:	45 00 63 6c          	add    BYTE PTR [r11+0x6c],r12b
 132:	65 61                	gs (bad) 
 134:	72 65                	jb     19b <_init-0x40022d>
 136:	72 72                	jb     1aa <_init-0x40021e>
 138:	00 75 6e             	add    BYTE PTR [rbp+0x6e],dh
 13b:	73 69                	jae    1a6 <_init-0x400222>
 13d:	67 6e                	outs   dx,BYTE PTR ds:[esi]
 13f:	65 64 20 63 68       	gs and BYTE PTR fs:[rbx+0x68],ah
 144:	61                   	(bad)  
 145:	72 00                	jb     147 <_init-0x400281>
 147:	5f                   	pop    rdi
 148:	5f                   	pop    rdi
 149:	67 6e                	outs   dx,BYTE PTR ds:[esi]
 14b:	75 5f                	jne    1ac <_init-0x40021c>
 14d:	63 78 78             	movsxd edi,DWORD PTR [rax+0x78]
 150:	00 5f 49             	add    BYTE PTR [rdi+0x49],bl
 153:	4f 5f                	rex.WRXB pop r15
 155:	6d                   	ins    DWORD PTR es:[rdi],dx
 156:	61                   	(bad)  
 157:	72 6b                	jb     1c4 <_init-0x400204>
 159:	65 72 00             	gs jb  15c <_init-0x40026c>
 15c:	5f                   	pop    rdi
 15d:	73 68                	jae    1c7 <_init-0x400201>
 15f:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 160:	72 74                	jb     1d6 <_init-0x4001f2>
 162:	62                   	(bad)  
 163:	75 66                	jne    1cb <_init-0x4001fd>
 165:	00 5f 49             	add    BYTE PTR [rdi+0x49],bl
 168:	4f 5f                	rex.WRXB pop r15
 16a:	77 72                	ja     1de <_init-0x4001ea>
 16c:	69 74 65 5f 62 61 73 	imul   esi,DWORD PTR [rbp+riz*2+0x5f],0x65736162
 173:	65 
 174:	00 5f 75             	add    BYTE PTR [rdi+0x75],bl
 177:	6e                   	outs   dx,BYTE PTR ds:[rsi]
 178:	75 73                	jne    1ed <_init-0x4001db>
 17a:	65 64 32 00          	gs xor al,BYTE PTR fs:[rax]
 17e:	5f                   	pop    rdi
 17f:	49                   	rex.WB
 180:	4f 5f                	rex.WRXB pop r15
 182:	72 65                	jb     1e9 <_init-0x4001df>
 184:	61                   	(bad)  
 185:	64 5f                	fs pop rdi
 187:	70 74                	jo     1fd <_init-0x4001cb>
 189:	72 00                	jb     18b <_init-0x40023d>
 18b:	73 68                	jae    1f5 <_init-0x4001d3>
 18d:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 18e:	72 74                	jb     204 <_init-0x4001c4>
 190:	20 75 6e             	and    BYTE PTR [rbp+0x6e],dh
 193:	73 69                	jae    1fe <_init-0x4001ca>
 195:	67 6e                	outs   dx,BYTE PTR ds:[esi]
 197:	65 64 20 69 6e       	gs and BYTE PTR fs:[rcx+0x6e],ch
 19c:	74 00                	je     19e <_init-0x40022a>
 19e:	5f                   	pop    rdi
 19f:	5f                   	pop    rdi
 1a0:	63 78 78             	movsxd edi,DWORD PTR [rax+0x78]
 1a3:	31 31                	xor    DWORD PTR [rcx],esi
 1a5:	00 74 6d 70          	add    BYTE PTR [rbp+rbp*2+0x70],dh
 1a9:	66 69 6c 65 00 5f 6e 	imul   bp,WORD PTR [rbp+riz*2+0x0],0x6e5f
 1b0:	65 78 74             	gs js  227 <_init-0x4001a1>
 1b3:	00 5f 5f             	add    BYTE PTR [rdi+0x5f],bl
 1b6:	70 61                	jo     219 <_init-0x4001af>
 1b8:	64 31 00             	xor    DWORD PTR fs:[rax],eax
 1bb:	5f                   	pop    rdi
 1bc:	5f                   	pop    rdi
 1bd:	70 61                	jo     220 <_init-0x4001a8>
 1bf:	64 32 00             	xor    al,BYTE PTR fs:[rax]
 1c2:	5f                   	pop    rdi
 1c3:	5f                   	pop    rdi
 1c4:	70 61                	jo     227 <_init-0x4001a1>
 1c6:	64 33 00             	xor    eax,DWORD PTR fs:[rax]
 1c9:	5f                   	pop    rdi
 1ca:	5f                   	pop    rdi
 1cb:	70 61                	jo     22e <_init-0x40019a>
 1cd:	64 34 00             	fs xor al,0x0
 1d0:	5f                   	pop    rdi
 1d1:	5f                   	pop    rdi
 1d2:	70 61                	jo     235 <_init-0x400193>
 1d4:	64 35 00 66 73 65    	fs xor eax,0x65736600
 1da:	74 70                	je     24c <_init-0x40017c>
 1dc:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 1dd:	73 00                	jae    1df <_init-0x4001e9>
 1df:	6c                   	ins    BYTE PTR es:[rdi],dx
 1e0:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 1e1:	6e                   	outs   dx,BYTE PTR ds:[rsi]
 1e2:	67 20 75 6e          	and    BYTE PTR [ebp+0x6e],dh
 1e6:	73 69                	jae    251 <_init-0x400177>
 1e8:	67 6e                	outs   dx,BYTE PTR ds:[esi]
 1ea:	65 64 20 69 6e       	gs and BYTE PTR fs:[rcx+0x6e],ch
 1ef:	74 00                	je     1f1 <_init-0x4001d7>
 1f1:	5f                   	pop    rdi
 1f2:	49                   	rex.WB
 1f3:	4f 5f                	rex.WRXB pop r15
 1f5:	77 72                	ja     269 <_init-0x40015f>
 1f7:	69 74 65 5f 65 6e 64 	imul   esi,DWORD PTR [rbp+riz*2+0x5f],0x646e65
 1fe:	00 
 1ff:	5f                   	pop    rdi
 200:	5f                   	pop    rdi
 201:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 202:	66 66 36 34 5f       	data16 data16 ss xor al,0x5f
 207:	74 00                	je     209 <_init-0x4001bf>
 209:	5f                   	pop    rdi
 20a:	5f                   	pop    rdi
 20b:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 20c:	66 66 5f             	data16 pop di
 20f:	74 00                	je     211 <_init-0x4001b7>
 211:	5f                   	pop    rdi
 212:	63 68 61             	movsxd ebp,DWORD PTR [rax+0x61]
 215:	69 6e 00 31 31 5f 5f 	imul   ebp,DWORD PTR [rsi+0x0],0x5f5f3131
 21c:	6d                   	ins    DWORD PTR es:[rdi],dx
 21d:	62 73 74 61 74       	(bad)  {k1}
 222:	65 5f                	gs pop rdi
 224:	74 00                	je     226 <_init-0x4001a2>
 226:	2f                   	(bad)  
 227:	68 6f 6d 65 2f       	push   0x2f656d6f
 22c:	77 6f                	ja     29d <_init-0x40012b>
 22e:	33 6b 69             	xor    ebp,DWORD PTR [rbx+0x69]
 231:	65 2f                	gs (bad) 
 233:	63 78 78             	movsxd edi,DWORD PTR [rax+0x78]
 236:	44 6f                	rex.R outs dx,DWORD PTR ds:[rsi]
 238:	6a 6f                	push   0x6f
 23a:	2f                   	(bad)  
 23b:	61                   	(bad)  
 23c:	73 6d                	jae    2ab <_init-0x40011d>
 23e:	00 5f 49             	add    BYTE PTR [rdi+0x49],bl
 241:	4f 5f                	rex.WRXB pop r15
 243:	62 61                	(bad)  {k1}
 245:	63 6b 75             	movsxd ebp,DWORD PTR [rbx+0x75]
 248:	70 5f                	jo     2a9 <_init-0x40011f>
 24a:	62 61                	(bad)  {k1}
 24c:	73 65                	jae    2b3 <_init-0x400115>
 24e:	00 72 65             	add    BYTE PTR [rdx+0x65],dh
 251:	6e                   	outs   dx,BYTE PTR ds:[rsi]
 252:	61                   	(bad)  
 253:	6d                   	ins    DWORD PTR es:[rdi],dx
 254:	65 00 39             	add    BYTE PTR gs:[rcx],bh
 257:	5f                   	pop    rdi
 258:	47 5f                	rex.RXB pop r15
 25a:	66 70 6f             	data16 jo 2cc <_init-0x4000fc>
 25d:	73 5f                	jae    2be <_init-0x40010a>
 25f:	74 00                	je     261 <_init-0x400167>
 261:	5f                   	pop    rdi
 262:	66 6c                	data16 ins BYTE PTR es:[rdi],dx
 264:	61                   	(bad)  
 265:	67 73 32             	addr32 jae 29a <_init-0x40012e>
 268:	00 5f 6d             	add    BYTE PTR [rdi+0x6d],bl
 26b:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 26c:	64 65 00 5f 49       	fs add BYTE PTR gs:[rdi+0x49],bl
 271:	4f 5f                	rex.WRXB pop r15
 273:	72 65                	jb     2da <_init-0x4000ee>
 275:	61                   	(bad)  
 276:	64 5f                	fs pop rdi
 278:	62 61                	(bad)  {k1}
 27a:	73 65                	jae    2e1 <_init-0x4000e7>
 27c:	00 74 6d 70          	add    BYTE PTR [rbp+rbp*2+0x70],dh
 280:	6e                   	outs   dx,BYTE PTR ds:[rsi]
 281:	61                   	(bad)  
 282:	6d                   	ins    DWORD PTR es:[rdi],dx
 283:	00 5f 76             	add    BYTE PTR [rdi+0x76],bl
 286:	74 61                	je     2e9 <_init-0x4000df>
 288:	62                   	(bad)  {k1}
 289:	6c                   	ins    BYTE PTR es:[rdi],dx
 28a:	65 5f                	gs pop rdi
 28c:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 28d:	66 66 73 65          	data16 data16 jae 2f6 <_init-0x4000d2>
 291:	74 00                	je     293 <_init-0x400135>
 293:	5f                   	pop    rdi
 294:	49                   	rex.WB
 295:	4f 5f                	rex.WRXB pop r15
 297:	73 61                	jae    2fa <_init-0x4000ce>
 299:	76 65                	jbe    300 <_init-0x4000c8>
 29b:	5f                   	pop    rdi
 29c:	62 61                	(bad)  {k1}
 29e:	73 65                	jae    305 <_init-0x4000c3>
 2a0:	00 72 65             	add    BYTE PTR [rdx+0x65],dh
 2a3:	77 69                	ja     30e <_init-0x4000ba>
 2a5:	6e                   	outs   dx,BYTE PTR ds:[rsi]
 2a6:	64 00 5f 66          	add    BYTE PTR fs:[rdi+0x66],bl
 2aa:	69 6c 65 6e 6f 00 5f 	imul   ebp,DWORD PTR [rbp+riz*2+0x6e],0x5f5f006f
 2b1:	5f 
 2b2:	77 63                	ja     317 <_init-0x4000b1>
 2b4:	68 62 00 5f 5f       	push   0x5f5f0062
 2b9:	73 74                	jae    32f <_init-0x400099>
 2bb:	61                   	(bad)  
 2bc:	74 65                	je     323 <_init-0x4000a5>
 2be:	00 66 72             	add    BYTE PTR [rsi+0x72],ah
 2c1:	65 61                	gs (bad) 
 2c3:	64 00 75 6e          	add    BYTE PTR fs:[rbp+0x6e],dh
 2c7:	67 65 74 63          	addr32 gs je 32e <_init-0x40009a>
 2cb:	00 66 65             	add    BYTE PTR [rsi+0x65],ah
 2ce:	72 72                	jb     342 <_init-0x400086>
 2d0:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 2d1:	72 00                	jb     2d3 <_init-0x4000f5>
 2d3:	5f                   	pop    rdi
 2d4:	49                   	rex.WB
 2d5:	4f 5f                	rex.WRXB pop r15
 2d7:	6c                   	ins    BYTE PTR es:[rdi],dx
 2d8:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 2d9:	63 6b 5f             	movsxd ebp,DWORD PTR [rbx+0x5f]
 2dc:	74 00                	je     2de <_init-0x4000ea>
 2de:	47                   	rex.RXB
 2df:	4e 55                	rex.WRX push rbp
 2e1:	20 43 2b             	and    BYTE PTR [rbx+0x2b],al
 2e4:	2b 31                	sub    esi,DWORD PTR [rcx]
 2e6:	34 20                	xor    al,0x20
 2e8:	35 2e 34 2e 30       	xor    eax,0x302e342e
 2ed:	20 32                	and    BYTE PTR [rdx],dh
 2ef:	30 31                	xor    BYTE PTR [rcx],dh
 2f1:	36 30 36             	xor    BYTE PTR ss:[rsi],dh
 2f4:	30 39                	xor    BYTE PTR [rcx],bh
 2f6:	20 2d 6d 74 75 6e    	and    BYTE PTR [rip+0x6e75746d],ch        # 6e757769 <_end+0x6e156729>
 2fc:	65 3d 67 65 6e 65    	gs cmp eax,0x656e6567
 302:	72 69                	jb     36d <_init-0x40005b>
 304:	63 20                	movsxd esp,DWORD PTR [rax]
 306:	2d 6d 61 72 63       	sub    eax,0x6372616d
 30b:	68 3d 78 38 36       	push   0x3638783d
 310:	2d 36 34 20 2d       	sub    eax,0x2d203436
 315:	67 20 2d 4f 30 20 2d 	and    BYTE PTR [eip+0x2d20304f],ch        # 2d20336b <_end+0x2cc0232b>
 31c:	73 74                	jae    392 <_init-0x400036>
 31e:	64 3d 63 2b 2b 31    	fs cmp eax,0x312b2b63
 324:	34 20                	xor    al,0x20
 326:	2d 66 73 74 61       	sub    eax,0x61747366
 32b:	63 6b 2d             	movsxd ebp,DWORD PTR [rbx+0x2d]
 32e:	70 72                	jo     3a2 <_init-0x400026>
 330:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 331:	74 65                	je     398 <_init-0x400030>
 333:	63 74 6f 72          	movsxd esi,DWORD PTR [rdi+rbp*2+0x72]
 337:	2d 73 74 72 6f       	sub    eax,0x6f727473
 33c:	6e                   	outs   dx,BYTE PTR ds:[rsi]
 33d:	67                   	addr32
	...
