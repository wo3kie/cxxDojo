
./atomic:     file format elf64-x86-64


Disassembly of section .interp:

0000000000400238 <.interp>:
  400238:	2f                   	(bad)  
  400239:	6c                   	ins    BYTE PTR es:[rdi],dx
  40023a:	69 62 36 34 2f 6c 64 	imul   esp,DWORD PTR [rdx+0x36],0x646c2f34
  400241:	2d 6c 69 6e 75       	sub    eax,0x756e696c
  400246:	78 2d                	js     400275 <_init-0x17b>
  400248:	78 38                	js     400282 <_init-0x16e>
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
  400283:	00 d1                	add    cl,dl
  400285:	16                   	(bad)  
  400286:	3f                   	(bad)  
  400287:	a8 71                	test   al,0x71
  400289:	ad                   	lods   eax,DWORD PTR ds:[rsi]
  40028a:	3b e6                	cmp    esp,esi
  40028c:	04 0e                	add    al,0xe
  40028e:	d3 ba 72 a8 6e 9a    	sar    DWORD PTR [rdx-0x6591578e],cl
  400294:	0e                   	(bad)  
  400295:	11 03                	adc    DWORD PTR [rbx],eax
  400297:	50                   	push   rax

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
  4002e8:	1c 00                	sbb    al,0x0
  4002ea:	00 00                	add    BYTE PTR [rax],al
  4002ec:	12 00                	adc    al,BYTE PTR [rax]
	...
  4002fe:	00 00                	add    BYTE PTR [rax],al
  400300:	2e 00 00             	add    BYTE PTR cs:[rax],al
  400303:	00 20                	add    BYTE PTR [rax],ah
	...

Disassembly of section .dynstr:

0000000000400318 <.dynstr>:
  400318:	00 6c 69 62          	add    BYTE PTR [rcx+rbp*2+0x62],ch
  40031c:	63 2e                	movsxd ebp,DWORD PTR [rsi]
  40031e:	73 6f                	jae    40038f <_init-0x61>
  400320:	2e 36 00 5f 5f       	cs add BYTE PTR ss:[rdi+0x5f],bl
  400325:	73 74                	jae    40039b <_init-0x55>
  400327:	61                   	(bad)  
  400328:	63 6b 5f             	movsxd ebp,DWORD PTR [rbx+0x5f]
  40032b:	63 68 6b             	movsxd ebp,DWORD PTR [rax+0x6b]
  40032e:	5f                   	pop    rdi
  40032f:	66 61                	data16 (bad) 
  400331:	69 6c 00 5f 5f 6c 69 	imul   ebp,DWORD PTR [rax+rax*1+0x5f],0x62696c5f
  400338:	62 
  400339:	63 5f 73             	movsxd ebx,DWORD PTR [rdi+0x73]
  40033c:	74 61                	je     40039f <_init-0x51>
  40033e:	72 74                	jb     4003b4 <_init-0x3c>
  400340:	5f                   	pop    rdi
  400341:	6d                   	ins    DWORD PTR es:[rdi],dx
  400342:	61                   	(bad)  
  400343:	69 6e 00 5f 5f 67 6d 	imul   ebp,DWORD PTR [rsi+0x0],0x6d675f5f
  40034a:	6f                   	outs   dx,DWORD PTR ds:[rsi]
  40034b:	6e                   	outs   dx,BYTE PTR ds:[rsi]
  40034c:	5f                   	pop    rdi
  40034d:	73 74                	jae    4003c3 <_init-0x2d>
  40034f:	61                   	(bad)  
  400350:	72 74                	jb     4003c6 <_init-0x2a>
  400352:	5f                   	pop    rdi
  400353:	5f                   	pop    rdi
  400354:	00 47 4c             	add    BYTE PTR [rdi+0x4c],al
  400357:	49                   	rex.WB
  400358:	42                   	rex.X
  400359:	43 5f                	rex.XB pop r15
  40035b:	32 2e                	xor    ch,BYTE PTR [rsi]
  40035d:	32 2e                	xor    ch,BYTE PTR [rsi]
  40035f:	35 00 47 4c 49       	xor    eax,0x494c4700
  400364:	42                   	rex.X
  400365:	43 5f                	rex.XB pop r15
  400367:	32 2e                	xor    ch,BYTE PTR [rsi]
  400369:	34 00                	xor    al,0x0

Disassembly of section .gnu.version:

000000000040036c <.gnu.version>:
  40036c:	00 00                	add    BYTE PTR [rax],al
  40036e:	02 00                	add    al,BYTE PTR [rax]
  400370:	03 00                	add    eax,DWORD PTR [rax]
	...

Disassembly of section .gnu.version_r:

0000000000400378 <.gnu.version_r>:
  400378:	01 00                	add    DWORD PTR [rax],eax
  40037a:	02 00                	add    al,BYTE PTR [rax]
  40037c:	01 00                	add    DWORD PTR [rax],eax
  40037e:	00 00                	add    BYTE PTR [rax],al
  400380:	10 00                	adc    BYTE PTR [rax],al
  400382:	00 00                	add    BYTE PTR [rax],al
  400384:	00 00                	add    BYTE PTR [rax],al
  400386:	00 00                	add    BYTE PTR [rax],al
  400388:	75 1a                	jne    4003a4 <_init-0x4c>
  40038a:	69 09 00 00 03 00    	imul   ecx,DWORD PTR [rcx],0x30000
  400390:	3d 00 00 00 10       	cmp    eax,0x10000000
  400395:	00 00                	add    BYTE PTR [rax],al
  400397:	00 14 69             	add    BYTE PTR [rcx+rbp*2],dl
  40039a:	69 0d 00 00 02 00 49 	imul   ecx,DWORD PTR [rip+0x20000],0x49        # 4203a4 <__FRAME_END__+0x1fa24>
  4003a1:	00 00 00 
  4003a4:	00 00                	add    BYTE PTR [rax],al
	...

Disassembly of section .rela.dyn:

00000000004003a8 <.rela.dyn>:
  4003a8:	f8                   	clc    
  4003a9:	0f 60 00             	punpcklbw mm0,DWORD PTR [rax]
  4003ac:	00 00                	add    BYTE PTR [rax],al
  4003ae:	00 00                	add    BYTE PTR [rax],al
  4003b0:	06                   	(bad)  
  4003b1:	00 00                	add    BYTE PTR [rax],al
  4003b3:	00 03                	add    BYTE PTR [rbx],al
	...

Disassembly of section .rela.plt:

00000000004003c0 <.rela.plt>:
  4003c0:	18 10                	sbb    BYTE PTR [rax],dl
  4003c2:	60                   	(bad)  
  4003c3:	00 00                	add    BYTE PTR [rax],al
  4003c5:	00 00                	add    BYTE PTR [rax],al
  4003c7:	00 07                	add    BYTE PTR [rdi],al
  4003c9:	00 00                	add    BYTE PTR [rax],al
  4003cb:	00 01                	add    BYTE PTR [rcx],al
	...
  4003d5:	00 00                	add    BYTE PTR [rax],al
  4003d7:	00 20                	add    BYTE PTR [rax],ah
  4003d9:	10 60 00             	adc    BYTE PTR [rax+0x0],ah
  4003dc:	00 00                	add    BYTE PTR [rax],al
  4003de:	00 00                	add    BYTE PTR [rax],al
  4003e0:	07                   	(bad)  
  4003e1:	00 00                	add    BYTE PTR [rax],al
  4003e3:	00 02                	add    BYTE PTR [rdx],al
	...

Disassembly of section .init:

00000000004003f0 <_init>:
  4003f0:	48 83 ec 08          	sub    rsp,0x8
  4003f4:	48 8b 05 fd 0b 20 00 	mov    rax,QWORD PTR [rip+0x200bfd]        # 600ff8 <_DYNAMIC+0x1d0>
  4003fb:	48 85 c0             	test   rax,rax
  4003fe:	74 05                	je     400405 <_init+0x15>
  400400:	e8 3b 00 00 00       	call   400440 <__libc_start_main@plt+0x10>
  400405:	48 83 c4 08          	add    rsp,0x8
  400409:	c3                   	ret    

Disassembly of section .plt:

0000000000400410 <__stack_chk_fail@plt-0x10>:
  400410:	ff 35 f2 0b 20 00    	push   QWORD PTR [rip+0x200bf2]        # 601008 <_GLOBAL_OFFSET_TABLE_+0x8>
  400416:	ff 25 f4 0b 20 00    	jmp    QWORD PTR [rip+0x200bf4]        # 601010 <_GLOBAL_OFFSET_TABLE_+0x10>
  40041c:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]

0000000000400420 <__stack_chk_fail@plt>:
  400420:	ff 25 f2 0b 20 00    	jmp    QWORD PTR [rip+0x200bf2]        # 601018 <_GLOBAL_OFFSET_TABLE_+0x18>
  400426:	68 00 00 00 00       	push   0x0
  40042b:	e9 e0 ff ff ff       	jmp    400410 <_init+0x20>

0000000000400430 <__libc_start_main@plt>:
  400430:	ff 25 ea 0b 20 00    	jmp    QWORD PTR [rip+0x200bea]        # 601020 <_GLOBAL_OFFSET_TABLE_+0x20>
  400436:	68 01 00 00 00       	push   0x1
  40043b:	e9 d0 ff ff ff       	jmp    400410 <_init+0x20>

Disassembly of section .plt.got:

0000000000400440 <.plt.got>:
  400440:	ff 25 b2 0b 20 00    	jmp    QWORD PTR [rip+0x200bb2]        # 600ff8 <_DYNAMIC+0x1d0>
  400446:	66 90                	xchg   ax,ax

Disassembly of section .text:

0000000000400450 <_start>:
  400450:	31 ed                	xor    ebp,ebp
  400452:	49 89 d1             	mov    r9,rdx
  400455:	5e                   	pop    rsi
  400456:	48 89 e2             	mov    rdx,rsp
  400459:	48 83 e4 f0          	and    rsp,0xfffffffffffffff0
  40045d:	50                   	push   rax
  40045e:	54                   	push   rsp
  40045f:	49 c7 c0 80 07 40 00 	mov    r8,0x400780
  400466:	48 c7 c1 10 07 40 00 	mov    rcx,0x400710
  40046d:	48 c7 c7 46 05 40 00 	mov    rdi,0x400546
  400474:	e8 b7 ff ff ff       	call   400430 <__libc_start_main@plt>
  400479:	f4                   	hlt    
  40047a:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]

0000000000400480 <deregister_tm_clones>:
  400480:	b8 3f 10 60 00       	mov    eax,0x60103f
  400485:	55                   	push   rbp
  400486:	48 2d 38 10 60 00    	sub    rax,0x601038
  40048c:	48 83 f8 0e          	cmp    rax,0xe
  400490:	48 89 e5             	mov    rbp,rsp
  400493:	76 1b                	jbe    4004b0 <deregister_tm_clones+0x30>
  400495:	b8 00 00 00 00       	mov    eax,0x0
  40049a:	48 85 c0             	test   rax,rax
  40049d:	74 11                	je     4004b0 <deregister_tm_clones+0x30>
  40049f:	5d                   	pop    rbp
  4004a0:	bf 38 10 60 00       	mov    edi,0x601038
  4004a5:	ff e0                	jmp    rax
  4004a7:	66 0f 1f 84 00 00 00 	nop    WORD PTR [rax+rax*1+0x0]
  4004ae:	00 00 
  4004b0:	5d                   	pop    rbp
  4004b1:	c3                   	ret    
  4004b2:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]
  4004b6:	66 2e 0f 1f 84 00 00 	nop    WORD PTR cs:[rax+rax*1+0x0]
  4004bd:	00 00 00 

00000000004004c0 <register_tm_clones>:
  4004c0:	be 38 10 60 00       	mov    esi,0x601038
  4004c5:	55                   	push   rbp
  4004c6:	48 81 ee 38 10 60 00 	sub    rsi,0x601038
  4004cd:	48 c1 fe 03          	sar    rsi,0x3
  4004d1:	48 89 e5             	mov    rbp,rsp
  4004d4:	48 89 f0             	mov    rax,rsi
  4004d7:	48 c1 e8 3f          	shr    rax,0x3f
  4004db:	48 01 c6             	add    rsi,rax
  4004de:	48 d1 fe             	sar    rsi,1
  4004e1:	74 15                	je     4004f8 <register_tm_clones+0x38>
  4004e3:	b8 00 00 00 00       	mov    eax,0x0
  4004e8:	48 85 c0             	test   rax,rax
  4004eb:	74 0b                	je     4004f8 <register_tm_clones+0x38>
  4004ed:	5d                   	pop    rbp
  4004ee:	bf 38 10 60 00       	mov    edi,0x601038
  4004f3:	ff e0                	jmp    rax
  4004f5:	0f 1f 00             	nop    DWORD PTR [rax]
  4004f8:	5d                   	pop    rbp
  4004f9:	c3                   	ret    
  4004fa:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]

0000000000400500 <__do_global_dtors_aux>:
  400500:	80 3d 31 0b 20 00 00 	cmp    BYTE PTR [rip+0x200b31],0x0        # 601038 <__TMC_END__>
  400507:	75 11                	jne    40051a <__do_global_dtors_aux+0x1a>
  400509:	55                   	push   rbp
  40050a:	48 89 e5             	mov    rbp,rsp
  40050d:	e8 6e ff ff ff       	call   400480 <deregister_tm_clones>
  400512:	5d                   	pop    rbp
  400513:	c6 05 1e 0b 20 00 01 	mov    BYTE PTR [rip+0x200b1e],0x1        # 601038 <__TMC_END__>
  40051a:	f3 c3                	repz ret 
  40051c:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]

0000000000400520 <frame_dummy>:
  400520:	bf 20 0e 60 00       	mov    edi,0x600e20
  400525:	48 83 3f 00          	cmp    QWORD PTR [rdi],0x0
  400529:	75 05                	jne    400530 <frame_dummy+0x10>
  40052b:	eb 93                	jmp    4004c0 <register_tm_clones>
  40052d:	0f 1f 00             	nop    DWORD PTR [rax]
  400530:	b8 00 00 00 00       	mov    eax,0x0
  400535:	48 85 c0             	test   rax,rax
  400538:	74 f1                	je     40052b <frame_dummy+0xb>
  40053a:	55                   	push   rbp
  40053b:	48 89 e5             	mov    rbp,rsp
  40053e:	ff d0                	call   rax
  400540:	5d                   	pop    rbp
  400541:	e9 7a ff ff ff       	jmp    4004c0 <register_tm_clones>

0000000000400546 <main>:
#include <atomic>

int main(int rand, char * argv[]){
  400546:	55                   	push   rbp
  400547:	48 89 e5             	mov    rbp,rsp
  40054a:	48 83 ec 70          	sub    rsp,0x70
  40054e:	89 7d 9c             	mov    DWORD PTR [rbp-0x64],edi
  400551:	48 89 75 90          	mov    QWORD PTR [rbp-0x70],rsi
  400555:	64 48 8b 04 25 28 00 	mov    rax,QWORD PTR fs:0x28
  40055c:	00 00 
  40055e:	48 89 45 f8          	mov    QWORD PTR [rbp-0x8],rax
  400562:	31 c0                	xor    eax,eax
	std::atomic<int> atomic;
  400564:	48 8d 45 a0          	lea    rax,[rbp-0x60]
  400568:	48 89 c7             	mov    rdi,rax
  40056b:	e8 7a 01 00 00       	call   4006ea <std::atomic<int>::atomic()>
  400570:	8b 45 9c             	mov    eax,DWORD PTR [rbp-0x64]
  400573:	89 45 b0             	mov    DWORD PTR [rbp-0x50],eax
  400576:	c7 45 e0 05 00 00 00 	mov    DWORD PTR [rbp-0x20],0x5
      }

      _GLIBCXX_ALWAYS_INLINE void
      store(__int_type __i, memory_order __m = memory_order_seq_cst) noexcept
      {
        memory_order __b = __m & __memory_order_mask;
  40057d:	8b 45 e0             	mov    eax,DWORD PTR [rbp-0x20]
  400580:	be ff ff 00 00       	mov    esi,0xffff
  400585:	89 c7                	mov    edi,eax
  400587:	e8 db 00 00 00       	call   400667 <std::operator&(std::memory_order, std::__memory_order_modifier)>
  40058c:	89 45 e4             	mov    DWORD PTR [rbp-0x1c],eax
	__glibcxx_assert(__b != memory_order_acquire);
	__glibcxx_assert(__b != memory_order_acq_rel);
	__glibcxx_assert(__b != memory_order_consume);

	__atomic_store_n(&_M_i, __i, __m);
  40058f:	8b 55 b0             	mov    edx,DWORD PTR [rbp-0x50]
  400592:	48 8d 45 a0          	lea    rax,[rbp-0x60]
  400596:	89 10                	mov    DWORD PTR [rax],edx
  400598:	0f ae f0             	mfence 
  40059b:	c7 45 b4 18 00 00 00 	mov    DWORD PTR [rbp-0x4c],0x18
  4005a2:	c7 45 dc 05 00 00 00 	mov    DWORD PTR [rbp-0x24],0x5
      }

      _GLIBCXX_ALWAYS_INLINE __int_type
      fetch_add(__int_type __i,
		memory_order __m = memory_order_seq_cst) noexcept
      { return __atomic_fetch_add(&_M_i, __i, __m); }
  4005a9:	8b 55 b4             	mov    edx,DWORD PTR [rbp-0x4c]
  4005ac:	48 8d 45 a0          	lea    rax,[rbp-0x60]
  4005b0:	f0 0f c1 10          	lock xadd DWORD PTR [rax],edx

	atomic.store(rand);

	atomic.fetch_add(24);

	int i = 1 + 24;
  4005b4:	c7 45 ac 19 00 00 00 	mov    DWORD PTR [rbp-0x54],0x19
  4005bb:	c7 45 b8 00 00 00 00 	mov    DWORD PTR [rbp-0x48],0x0
  4005c2:	c7 45 c4 05 00 00 00 	mov    DWORD PTR [rbp-0x3c],0x5

      _GLIBCXX_ALWAYS_INLINE bool
      compare_exchange_strong(__int_type& __i1, __int_type __i2,
			      memory_order __m = memory_order_seq_cst) noexcept
      {
	return compare_exchange_strong(__i1, __i2, __m,
  4005c9:	8b 45 c4             	mov    eax,DWORD PTR [rbp-0x3c]
  4005cc:	89 c7                	mov    edi,eax
  4005ce:	e8 ce 00 00 00       	call   4006a1 <std::__cmpexch_failure_order(std::memory_order)>
  4005d3:	89 c2                	mov    edx,eax
  4005d5:	48 8d 45 a0          	lea    rax,[rbp-0x60]
  4005d9:	48 89 45 e8          	mov    QWORD PTR [rbp-0x18],rax
  4005dd:	48 8d 45 ac          	lea    rax,[rbp-0x54]
  4005e1:	48 89 45 f0          	mov    QWORD PTR [rbp-0x10],rax
  4005e5:	8b 45 b8             	mov    eax,DWORD PTR [rbp-0x48]
  4005e8:	89 45 c8             	mov    DWORD PTR [rbp-0x38],eax
  4005eb:	8b 45 c4             	mov    eax,DWORD PTR [rbp-0x3c]
  4005ee:	89 45 cc             	mov    DWORD PTR [rbp-0x34],eax
  4005f1:	89 55 d0             	mov    DWORD PTR [rbp-0x30],edx

      _GLIBCXX_ALWAYS_INLINE bool
      compare_exchange_strong(__int_type& __i1, __int_type __i2,
			      memory_order __m1, memory_order __m2) noexcept
      {
        memory_order __b2 = __m2 & __memory_order_mask;
  4005f4:	8b 45 d0             	mov    eax,DWORD PTR [rbp-0x30]
  4005f7:	be ff ff 00 00       	mov    esi,0xffff
  4005fc:	89 c7                	mov    edi,eax
  4005fe:	e8 64 00 00 00       	call   400667 <std::operator&(std::memory_order, std::__memory_order_modifier)>
  400603:	89 45 d4             	mov    DWORD PTR [rbp-0x2c],eax
        memory_order __b1 = __m1 & __memory_order_mask;
  400606:	8b 45 cc             	mov    eax,DWORD PTR [rbp-0x34]
  400609:	be ff ff 00 00       	mov    esi,0xffff
  40060e:	89 c7                	mov    edi,eax
  400610:	e8 52 00 00 00       	call   400667 <std::operator&(std::memory_order, std::__memory_order_modifier)>
  400615:	89 45 d8             	mov    DWORD PTR [rbp-0x28],eax
	__glibcxx_assert(__b2 != memory_order_release);
	__glibcxx_assert(__b2 != memory_order_acq_rel);
	__glibcxx_assert(__b2 <= __b1);

	return __atomic_compare_exchange_n(&_M_i, &__i1, __i2, 0, __m1, __m2);
  400618:	8b 75 c8             	mov    esi,DWORD PTR [rbp-0x38]
  40061b:	48 8b 4d e8          	mov    rcx,QWORD PTR [rbp-0x18]
  40061f:	48 8b 55 f0          	mov    rdx,QWORD PTR [rbp-0x10]
  400623:	8b 02                	mov    eax,DWORD PTR [rdx]
  400625:	f0 0f b1 31          	lock cmpxchg DWORD PTR [rcx],esi
  400629:	0f 94 c1             	sete   cl
  40062c:	84 c9                	test   cl,cl
  40062e:	75 02                	jne    400632 <main+0xec>
  400630:	89 02                	mov    DWORD PTR [rdx],eax
  400632:	c7 45 bc 05 00 00 00 	mov    DWORD PTR [rbp-0x44],0x5
      }

      _GLIBCXX_ALWAYS_INLINE __int_type
      load(memory_order __m = memory_order_seq_cst) const noexcept
      {
       memory_order __b = __m & __memory_order_mask;
  400639:	8b 45 bc             	mov    eax,DWORD PTR [rbp-0x44]
  40063c:	be ff ff 00 00       	mov    esi,0xffff
  400641:	89 c7                	mov    edi,eax
  400643:	e8 1f 00 00 00       	call   400667 <std::operator&(std::memory_order, std::__memory_order_modifier)>
  400648:	89 45 c0             	mov    DWORD PTR [rbp-0x40],eax
	__glibcxx_assert(__b != memory_order_release);
	__glibcxx_assert(__b != memory_order_acq_rel);

	return __atomic_load_n(&_M_i, __m);
  40064b:	48 8d 45 a0          	lea    rax,[rbp-0x60]
  40064f:	8b 00                	mov    eax,DWORD PTR [rax]
	atomic.compare_exchange_strong(i, 0);

	return atomic.load();
}
  400651:	48 8b 4d f8          	mov    rcx,QWORD PTR [rbp-0x8]
  400655:	64 48 33 0c 25 28 00 	xor    rcx,QWORD PTR fs:0x28
  40065c:	00 00 
  40065e:	74 05                	je     400665 <main+0x11f>
  400660:	e8 bb fd ff ff       	call   400420 <__stack_chk_fail@plt>
  400665:	c9                   	leave  
  400666:	c3                   	ret    

0000000000400667 <std::operator&(std::memory_order, std::__memory_order_modifier)>:
    return memory_order(__m | int(__mod));
  }

  constexpr memory_order
  operator&(memory_order __m, __memory_order_modifier __mod)
  {
  400667:	55                   	push   rbp
  400668:	48 89 e5             	mov    rbp,rsp
  40066b:	89 7d fc             	mov    DWORD PTR [rbp-0x4],edi
  40066e:	89 75 f8             	mov    DWORD PTR [rbp-0x8],esi
    return memory_order(__m & int(__mod));
  400671:	8b 55 fc             	mov    edx,DWORD PTR [rbp-0x4]
  400674:	8b 45 f8             	mov    eax,DWORD PTR [rbp-0x8]
  400677:	21 d0                	and    eax,edx
  }
  400679:	5d                   	pop    rbp
  40067a:	c3                   	ret    

000000000040067b <std::__cmpexch_failure_order2(std::memory_order)>:

  // Drop release ordering as per [atomics.types.operations.req]/21
  constexpr memory_order
  __cmpexch_failure_order2(memory_order __m) noexcept
  {
  40067b:	55                   	push   rbp
  40067c:	48 89 e5             	mov    rbp,rsp
  40067f:	89 7d fc             	mov    DWORD PTR [rbp-0x4],edi
    return __m == memory_order_acq_rel ? memory_order_acquire
      : __m == memory_order_release ? memory_order_relaxed : __m;
  400682:	83 7d fc 04          	cmp    DWORD PTR [rbp-0x4],0x4
  400686:	74 12                	je     40069a <std::__cmpexch_failure_order2(std::memory_order)+0x1f>
  400688:	83 7d fc 03          	cmp    DWORD PTR [rbp-0x4],0x3
  40068c:	74 05                	je     400693 <std::__cmpexch_failure_order2(std::memory_order)+0x18>
  40068e:	8b 45 fc             	mov    eax,DWORD PTR [rbp-0x4]
  400691:	eb 0c                	jmp    40069f <std::__cmpexch_failure_order2(std::memory_order)+0x24>
  400693:	b8 00 00 00 00       	mov    eax,0x0
  400698:	eb 05                	jmp    40069f <std::__cmpexch_failure_order2(std::memory_order)+0x24>
  40069a:	b8 02 00 00 00       	mov    eax,0x2
  }
  40069f:	5d                   	pop    rbp
  4006a0:	c3                   	ret    

00000000004006a1 <std::__cmpexch_failure_order(std::memory_order)>:

  constexpr memory_order
  __cmpexch_failure_order(memory_order __m) noexcept
  {
  4006a1:	55                   	push   rbp
  4006a2:	48 89 e5             	mov    rbp,rsp
  4006a5:	53                   	push   rbx
  4006a6:	48 83 ec 18          	sub    rsp,0x18
  4006aa:	89 7d ec             	mov    DWORD PTR [rbp-0x14],edi
    return memory_order(__cmpexch_failure_order2(__m & __memory_order_mask)
  4006ad:	8b 45 ec             	mov    eax,DWORD PTR [rbp-0x14]
  4006b0:	be ff ff 00 00       	mov    esi,0xffff
  4006b5:	89 c7                	mov    edi,eax
  4006b7:	e8 ab ff ff ff       	call   400667 <std::operator&(std::memory_order, std::__memory_order_modifier)>
  4006bc:	89 c7                	mov    edi,eax
  4006be:	e8 b8 ff ff ff       	call   40067b <std::__cmpexch_failure_order2(std::memory_order)>
      | (__m & __memory_order_modifier_mask));
  4006c3:	89 c3                	mov    ebx,eax
  4006c5:	8b 45 ec             	mov    eax,DWORD PTR [rbp-0x14]
  4006c8:	be 00 00 ff ff       	mov    esi,0xffff0000
  4006cd:	89 c7                	mov    edi,eax
  4006cf:	e8 93 ff ff ff       	call   400667 <std::operator&(std::memory_order, std::__memory_order_modifier)>
  4006d4:	09 d8                	or     eax,ebx
  }
  4006d6:	48 83 c4 18          	add    rsp,0x18
  4006da:	5b                   	pop    rbx
  4006db:	5d                   	pop    rbp
  4006dc:	c3                   	ret    
  4006dd:	90                   	nop

00000000004006de <std::__atomic_base<int>::__atomic_base()>:
	sizeof(_ITp) > alignof(_ITp) ? sizeof(_ITp) : alignof(_ITp);

      alignas(_S_alignment) __int_type _M_i;

    public:
      __atomic_base() noexcept = default;
  4006de:	55                   	push   rbp
  4006df:	48 89 e5             	mov    rbp,rsp
  4006e2:	48 89 7d f8          	mov    QWORD PTR [rbp-0x8],rdi
  4006e6:	90                   	nop
  4006e7:	5d                   	pop    rbp
  4006e8:	c3                   	ret    
  4006e9:	90                   	nop

00000000004006ea <std::atomic<int>::atomic()>:
    struct atomic<int> : __atomic_base<int>
    {
      typedef int 			__integral_type;
      typedef __atomic_base<int> 		__base_type;

      atomic() noexcept = default;
  4006ea:	55                   	push   rbp
  4006eb:	48 89 e5             	mov    rbp,rsp
  4006ee:	48 83 ec 10          	sub    rsp,0x10
  4006f2:	48 89 7d f8          	mov    QWORD PTR [rbp-0x8],rdi
  4006f6:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
  4006fa:	48 89 c7             	mov    rdi,rax
  4006fd:	e8 dc ff ff ff       	call   4006de <std::__atomic_base<int>::__atomic_base()>
  400702:	90                   	nop
  400703:	c9                   	leave  
  400704:	c3                   	ret    
  400705:	66 2e 0f 1f 84 00 00 	nop    WORD PTR cs:[rax+rax*1+0x0]
  40070c:	00 00 00 
  40070f:	90                   	nop

0000000000400710 <__libc_csu_init>:
  400710:	41 57                	push   r15
  400712:	41 56                	push   r14
  400714:	41 89 ff             	mov    r15d,edi
  400717:	41 55                	push   r13
  400719:	41 54                	push   r12
  40071b:	4c 8d 25 ee 06 20 00 	lea    r12,[rip+0x2006ee]        # 600e10 <__frame_dummy_init_array_entry>
  400722:	55                   	push   rbp
  400723:	48 8d 2d ee 06 20 00 	lea    rbp,[rip+0x2006ee]        # 600e18 <__init_array_end>
  40072a:	53                   	push   rbx
  40072b:	49 89 f6             	mov    r14,rsi
  40072e:	49 89 d5             	mov    r13,rdx
  400731:	4c 29 e5             	sub    rbp,r12
  400734:	48 83 ec 08          	sub    rsp,0x8
  400738:	48 c1 fd 03          	sar    rbp,0x3
  40073c:	e8 af fc ff ff       	call   4003f0 <_init>
  400741:	48 85 ed             	test   rbp,rbp
  400744:	74 20                	je     400766 <__libc_csu_init+0x56>
  400746:	31 db                	xor    ebx,ebx
  400748:	0f 1f 84 00 00 00 00 	nop    DWORD PTR [rax+rax*1+0x0]
  40074f:	00 
  400750:	4c 89 ea             	mov    rdx,r13
  400753:	4c 89 f6             	mov    rsi,r14
  400756:	44 89 ff             	mov    edi,r15d
  400759:	41 ff 14 dc          	call   QWORD PTR [r12+rbx*8]
  40075d:	48 83 c3 01          	add    rbx,0x1
  400761:	48 39 eb             	cmp    rbx,rbp
  400764:	75 ea                	jne    400750 <__libc_csu_init+0x40>
  400766:	48 83 c4 08          	add    rsp,0x8
  40076a:	5b                   	pop    rbx
  40076b:	5d                   	pop    rbp
  40076c:	41 5c                	pop    r12
  40076e:	41 5d                	pop    r13
  400770:	41 5e                	pop    r14
  400772:	41 5f                	pop    r15
  400774:	c3                   	ret    
  400775:	90                   	nop
  400776:	66 2e 0f 1f 84 00 00 	nop    WORD PTR cs:[rax+rax*1+0x0]
  40077d:	00 00 00 

0000000000400780 <__libc_csu_fini>:
  400780:	f3 c3                	repz ret 

Disassembly of section .fini:

0000000000400784 <_fini>:
  400784:	48 83 ec 08          	sub    rsp,0x8
  400788:	48 83 c4 08          	add    rsp,0x8
  40078c:	c3                   	ret    

Disassembly of section .rodata:

0000000000400790 <_IO_stdin_used>:
  400790:	01 00                	add    DWORD PTR [rax],eax
  400792:	02 00                	add    al,BYTE PTR [rax]

Disassembly of section .eh_frame_hdr:

0000000000400794 <__GNU_EH_FRAME_HDR>:
  400794:	01 1b                	add    DWORD PTR [rbx],ebx
  400796:	03 3b                	add    edi,DWORD PTR [rbx]
  400798:	58                   	pop    rax
  400799:	00 00                	add    BYTE PTR [rax],al
  40079b:	00 0a                	add    BYTE PTR [rdx],cl
  40079d:	00 00                	add    BYTE PTR [rax],al
  40079f:	00 7c fc ff          	add    BYTE PTR [rsp+rdi*8-0x1],bh
  4007a3:	ff a4 00 00 00 bc fc 	jmp    QWORD PTR [rax+rax*1-0x3440000]
  4007aa:	ff                   	(bad)  
  4007ab:	ff 74 00 00          	push   QWORD PTR [rax+rax*1+0x0]
  4007af:	00 b2 fd ff ff 6c    	add    BYTE PTR [rdx+0x6cfffffd],dh
  4007b5:	01 00                	add    DWORD PTR [rax],eax
  4007b7:	00 d3                	add    bl,dl
  4007b9:	fe                   	(bad)  
  4007ba:	ff                   	(bad)  
  4007bb:	ff cc                	dec    esp
  4007bd:	00 00                	add    BYTE PTR [rax],al
  4007bf:	00 e7                	add    bh,ah
  4007c1:	fe                   	(bad)  
  4007c2:	ff                   	(bad)  
  4007c3:	ff                   	(bad)  
  4007c4:	ec                   	in     al,dx
  4007c5:	00 00                	add    BYTE PTR [rax],al
  4007c7:	00 0d ff ff ff 0c    	add    BYTE PTR [rip+0xcffffff],cl        # d4007cc <_end+0xcdff78c>
  4007cd:	01 00                	add    DWORD PTR [rax],eax
  4007cf:	00 4a ff             	add    BYTE PTR [rdx-0x1],cl
  4007d2:	ff                   	(bad)  
  4007d3:	ff 2c 01             	jmp    FWORD PTR [rcx+rax*1]
  4007d6:	00 00                	add    BYTE PTR [rax],al
  4007d8:	56                   	push   rsi
  4007d9:	ff                   	(bad)  
  4007da:	ff                   	(bad)  
  4007db:	ff 4c 01 00          	dec    DWORD PTR [rcx+rax*1+0x0]
  4007df:	00 7c ff ff          	add    BYTE PTR [rdi+rdi*8-0x1],bh
  4007e3:	ff 8c 01 00 00 ec ff 	dec    DWORD PTR [rcx+rax*1-0x140000]
  4007ea:	ff                   	(bad)  
  4007eb:	ff d4                	call   rsp
  4007ed:	01 00                	add    DWORD PTR [rax],eax
	...

Disassembly of section .eh_frame:

00000000004007f0 <__FRAME_END__-0x190>:
  4007f0:	14 00                	adc    al,0x0
  4007f2:	00 00                	add    BYTE PTR [rax],al
  4007f4:	00 00                	add    BYTE PTR [rax],al
  4007f6:	00 00                	add    BYTE PTR [rax],al
  4007f8:	01 7a 52             	add    DWORD PTR [rdx+0x52],edi
  4007fb:	00 01                	add    BYTE PTR [rcx],al
  4007fd:	78 10                	js     40080f <__GNU_EH_FRAME_HDR+0x7b>
  4007ff:	01 1b                	add    DWORD PTR [rbx],ebx
  400801:	0c 07                	or     al,0x7
  400803:	08 90 01 07 10 14    	or     BYTE PTR [rax+0x14100701],dl
  400809:	00 00                	add    BYTE PTR [rax],al
  40080b:	00 1c 00             	add    BYTE PTR [rax+rax*1],bl
  40080e:	00 00                	add    BYTE PTR [rax],al
  400810:	40 fc                	rex cld 
  400812:	ff                   	(bad)  
  400813:	ff 2a                	jmp    FWORD PTR [rdx]
	...
  40081d:	00 00                	add    BYTE PTR [rax],al
  40081f:	00 14 00             	add    BYTE PTR [rax+rax*1],dl
  400822:	00 00                	add    BYTE PTR [rax],al
  400824:	00 00                	add    BYTE PTR [rax],al
  400826:	00 00                	add    BYTE PTR [rax],al
  400828:	01 7a 52             	add    DWORD PTR [rdx+0x52],edi
  40082b:	00 01                	add    BYTE PTR [rcx],al
  40082d:	78 10                	js     40083f <__GNU_EH_FRAME_HDR+0xab>
  40082f:	01 1b                	add    DWORD PTR [rbx],ebx
  400831:	0c 07                	or     al,0x7
  400833:	08 90 01 00 00 24    	or     BYTE PTR [rax+0x24000001],dl
  400839:	00 00                	add    BYTE PTR [rax],al
  40083b:	00 1c 00             	add    BYTE PTR [rax+rax*1],bl
  40083e:	00 00                	add    BYTE PTR [rax],al
  400840:	d0 fb                	sar    bl,1
  400842:	ff                   	(bad)  
  400843:	ff 30                	push   QWORD PTR [rax]
  400845:	00 00                	add    BYTE PTR [rax],al
  400847:	00 00                	add    BYTE PTR [rax],al
  400849:	0e                   	(bad)  
  40084a:	10 46 0e             	adc    BYTE PTR [rsi+0xe],al
  40084d:	18 4a 0f             	sbb    BYTE PTR [rdx+0xf],cl
  400850:	0b 77 08             	or     esi,DWORD PTR [rdi+0x8]
  400853:	80 00 3f             	add    BYTE PTR [rax],0x3f
  400856:	1a 3b                	sbb    bh,BYTE PTR [rbx]
  400858:	2a 33                	sub    dh,BYTE PTR [rbx]
  40085a:	24 22                	and    al,0x22
  40085c:	00 00                	add    BYTE PTR [rax],al
  40085e:	00 00                	add    BYTE PTR [rax],al
  400860:	1c 00                	sbb    al,0x0
  400862:	00 00                	add    BYTE PTR [rax],al
  400864:	44 00 00             	add    BYTE PTR [rax],r8b
  400867:	00 ff                	add    bh,bh
  400869:	fd                   	std    
  40086a:	ff                   	(bad)  
  40086b:	ff 14 00             	call   QWORD PTR [rax+rax*1]
  40086e:	00 00                	add    BYTE PTR [rax],al
  400870:	00 41 0e             	add    BYTE PTR [rcx+0xe],al
  400873:	10 86 02 43 0d 06    	adc    BYTE PTR [rsi+0x60d4302],al
  400879:	4f 0c 07             	rex.WRXB or al,0x7
  40087c:	08 00                	or     BYTE PTR [rax],al
  40087e:	00 00                	add    BYTE PTR [rax],al
  400880:	1c 00                	sbb    al,0x0
  400882:	00 00                	add    BYTE PTR [rax],al
  400884:	64 00 00             	add    BYTE PTR fs:[rax],al
  400887:	00 f3                	add    bl,dh
  400889:	fd                   	std    
  40088a:	ff                   	(bad)  
  40088b:	ff 26                	jmp    QWORD PTR [rsi]
  40088d:	00 00                	add    BYTE PTR [rax],al
  40088f:	00 00                	add    BYTE PTR [rax],al
  400891:	41 0e                	rex.B (bad) 
  400893:	10 86 02 43 0d 06    	adc    BYTE PTR [rsi+0x60d4302],al
  400899:	61                   	(bad)  
  40089a:	0c 07                	or     al,0x7
  40089c:	08 00                	or     BYTE PTR [rax],al
  40089e:	00 00                	add    BYTE PTR [rax],al
  4008a0:	1c 00                	sbb    al,0x0
  4008a2:	00 00                	add    BYTE PTR [rax],al
  4008a4:	84 00                	test   BYTE PTR [rax],al
  4008a6:	00 00                	add    BYTE PTR [rax],al
  4008a8:	f9                   	stc    
  4008a9:	fd                   	std    
  4008aa:	ff                   	(bad)  
  4008ab:	ff                   	(bad)  
  4008ac:	3c 00                	cmp    al,0x0
  4008ae:	00 00                	add    BYTE PTR [rax],al
  4008b0:	00 41 0e             	add    BYTE PTR [rcx+0xe],al
  4008b3:	10 86 02 43 0d 06    	adc    BYTE PTR [rsi+0x60d4302],al
  4008b9:	45 83 03 72          	rex.RB add DWORD PTR [r11],0x72
  4008bd:	0c 07                	or     al,0x7
  4008bf:	08 1c 00             	or     BYTE PTR [rax+rax*1],bl
  4008c2:	00 00                	add    BYTE PTR [rax],al
  4008c4:	a4                   	movs   BYTE PTR es:[rdi],BYTE PTR ds:[rsi]
  4008c5:	00 00                	add    BYTE PTR [rax],al
  4008c7:	00 16                	add    BYTE PTR [rsi],dl
  4008c9:	fe                   	(bad)  
  4008ca:	ff                   	(bad)  
  4008cb:	ff 0b                	dec    DWORD PTR [rbx]
  4008cd:	00 00                	add    BYTE PTR [rax],al
  4008cf:	00 00                	add    BYTE PTR [rax],al
  4008d1:	41 0e                	rex.B (bad) 
  4008d3:	10 86 02 43 0d 06    	adc    BYTE PTR [rsi+0x60d4302],al
  4008d9:	46 0c 07             	rex.RX or al,0x7
  4008dc:	08 00                	or     BYTE PTR [rax],al
  4008de:	00 00                	add    BYTE PTR [rax],al
  4008e0:	1c 00                	sbb    al,0x0
  4008e2:	00 00                	add    BYTE PTR [rax],al
  4008e4:	c4                   	(bad)  
  4008e5:	00 00                	add    BYTE PTR [rax],al
  4008e7:	00 02                	add    BYTE PTR [rdx],al
  4008e9:	fe                   	(bad)  
  4008ea:	ff                   	(bad)  
  4008eb:	ff 1b                	call   FWORD PTR [rbx]
  4008ed:	00 00                	add    BYTE PTR [rax],al
  4008ef:	00 00                	add    BYTE PTR [rax],al
  4008f1:	41 0e                	rex.B (bad) 
  4008f3:	10 86 02 43 0d 06    	adc    BYTE PTR [rsi+0x60d4302],al
  4008f9:	56                   	push   rsi
  4008fa:	0c 07                	or     al,0x7
  4008fc:	08 00                	or     BYTE PTR [rax],al
  4008fe:	00 00                	add    BYTE PTR [rax],al
  400900:	1c 00                	sbb    al,0x0
  400902:	00 00                	add    BYTE PTR [rax],al
  400904:	e4 00                	in     al,0x0
  400906:	00 00                	add    BYTE PTR [rax],al
  400908:	3e fc                	ds cld 
  40090a:	ff                   	(bad)  
  40090b:	ff 21                	jmp    QWORD PTR [rcx]
  40090d:	01 00                	add    DWORD PTR [rax],eax
  40090f:	00 00                	add    BYTE PTR [rax],al
  400911:	41 0e                	rex.B (bad) 
  400913:	10 86 02 43 0d 06    	adc    BYTE PTR [rsi+0x60d4302],al
  400919:	03 1c 01             	add    ebx,DWORD PTR [rcx+rax*1]
  40091c:	0c 07                	or     al,0x7
  40091e:	08 00                	or     BYTE PTR [rax],al
  400920:	44 00 00             	add    BYTE PTR [rax],r8b
  400923:	00 04 01             	add    BYTE PTR [rcx+rax*1],al
  400926:	00 00                	add    BYTE PTR [rax],al
  400928:	e8 fd ff ff 65       	call   6640092a <_end+0x65dff8ea>
  40092d:	00 00                	add    BYTE PTR [rax],al
  40092f:	00 00                	add    BYTE PTR [rax],al
  400931:	42 0e                	rex.X (bad) 
  400933:	10 8f 02 42 0e 18    	adc    BYTE PTR [rdi+0x180e4202],cl
  400939:	8e 03                	mov    es,WORD PTR [rbx]
  40093b:	45 0e                	rex.RB (bad) 
  40093d:	20 8d 04 42 0e 28    	and    BYTE PTR [rbp+0x280e4204],cl
  400943:	8c 05 48 0e 30 86    	mov    WORD PTR [rip+0xffffffff86300e48],es        # ffffffff86701791 <_end+0xffffffff86100751>
  400949:	06                   	(bad)  
  40094a:	48 0e                	rex.W (bad) 
  40094c:	38 83 07 4d 0e 40    	cmp    BYTE PTR [rbx+0x400e4d07],al
  400952:	72 0e                	jb     400962 <__GNU_EH_FRAME_HDR+0x1ce>
  400954:	38 41 0e             	cmp    BYTE PTR [rcx+0xe],al
  400957:	30 41 0e             	xor    BYTE PTR [rcx+0xe],al
  40095a:	28 42 0e             	sub    BYTE PTR [rdx+0xe],al
  40095d:	20 42 0e             	and    BYTE PTR [rdx+0xe],al
  400960:	18 42 0e             	sbb    BYTE PTR [rdx+0xe],al
  400963:	10 42 0e             	adc    BYTE PTR [rdx+0xe],al
  400966:	08 00                	or     BYTE PTR [rax],al
  400968:	14 00                	adc    al,0x0
  40096a:	00 00                	add    BYTE PTR [rax],al
  40096c:	4c 01 00             	add    QWORD PTR [rax],r8
  40096f:	00 10                	add    BYTE PTR [rax],dl
  400971:	fe                   	(bad)  
  400972:	ff                   	(bad)  
  400973:	ff 02                	inc    DWORD PTR [rdx]
	...

0000000000400980 <__FRAME_END__>:
  400980:	00 00                	add    BYTE PTR [rax],al
	...

Disassembly of section .init_array:

0000000000600e10 <__frame_dummy_init_array_entry>:
  600e10:	20 05 40 00 00 00    	and    BYTE PTR [rip+0x40],al        # 600e56 <_DYNAMIC+0x2e>
	...

Disassembly of section .fini_array:

0000000000600e18 <__do_global_dtors_aux_fini_array_entry>:
  600e18:	00 05 40 00 00 00    	add    BYTE PTR [rip+0x40],al        # 600e5e <_DYNAMIC+0x36>
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
  600e40:	f0 03 40 00          	lock add eax,DWORD PTR [rax+0x0]
  600e44:	00 00                	add    BYTE PTR [rax],al
  600e46:	00 00                	add    BYTE PTR [rax],al
  600e48:	0d 00 00 00 00       	or     eax,0x0
  600e4d:	00 00                	add    BYTE PTR [rax],al
  600e4f:	00 84 07 40 00 00 00 	add    BYTE PTR [rdi+rax*1+0x40],al
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
  600ecf:	00 53 00             	add    BYTE PTR [rbx+0x0],dl
  600ed2:	00 00                	add    BYTE PTR [rax],al
  600ed4:	00 00                	add    BYTE PTR [rax],al
  600ed6:	00 00                	add    BYTE PTR [rax],al
  600ed8:	0b 00                	or     eax,DWORD PTR [rax]
  600eda:	00 00                	add    BYTE PTR [rax],al
  600edc:	00 00                	add    BYTE PTR [rax],al
  600ede:	00 00                	add    BYTE PTR [rax],al
  600ee0:	18 00                	sbb    BYTE PTR [rax],al
  600ee2:	00 00                	add    BYTE PTR [rax],al
  600ee4:	00 00                	add    BYTE PTR [rax],al
  600ee6:	00 00                	add    BYTE PTR [rax],al
  600ee8:	15 00 00 00 00       	adc    eax,0x0
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
  600f2f:	00 c0                	add    al,al
  600f31:	03 40 00             	add    eax,DWORD PTR [rax+0x0]
  600f34:	00 00                	add    BYTE PTR [rax],al
  600f36:	00 00                	add    BYTE PTR [rax],al
  600f38:	07                   	(bad)  
  600f39:	00 00                	add    BYTE PTR [rax],al
  600f3b:	00 00                	add    BYTE PTR [rax],al
  600f3d:	00 00                	add    BYTE PTR [rax],al
  600f3f:	00 a8 03 40 00 00    	add    BYTE PTR [rax+0x4003],ch
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
  600f6f:	00 78 03             	add    BYTE PTR [rax+0x3],bh
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
  600f8f:	00 6c 03 40          	add    BYTE PTR [rbx+rax*1+0x40],ch
	...

Disassembly of section .got:

0000000000600ff8 <.got>:
	...

Disassembly of section .got.plt:

0000000000601000 <_GLOBAL_OFFSET_TABLE_>:
  601000:	28 0e                	sub    BYTE PTR [rsi],cl
  601002:	60                   	(bad)  
	...
  601017:	00 26                	add    BYTE PTR [rsi],ah
  601019:	04 40                	add    al,0x40
  60101b:	00 00                	add    BYTE PTR [rax],al
  60101d:	00 00                	add    BYTE PTR [rax],al
  60101f:	00 36                	add    BYTE PTR [rsi],dh
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
   8:	75 6e                	jne    78 <_init-0x400378>
   a:	74 75                	je     81 <_init-0x40036f>
   c:	20 35 2e 34 2e 30    	and    BYTE PTR [rip+0x302e342e],dh        # 302e3440 <_end+0x2fce2400>
  12:	2d 36 75 62 75       	sub    eax,0x75627536
  17:	6e                   	outs   dx,BYTE PTR ds:[rsi]
  18:	74 75                	je     8f <_init-0x400361>
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
   0:	7c 00                	jl     2 <_init-0x4003ee>
   2:	00 00                	add    BYTE PTR [rax],al
   4:	02 00                	add    al,BYTE PTR [rax]
   6:	00 00                	add    BYTE PTR [rax],al
   8:	00 00                	add    BYTE PTR [rax],al
   a:	08 00                	or     BYTE PTR [rax],al
   c:	00 00                	add    BYTE PTR [rax],al
   e:	00 00                	add    BYTE PTR [rax],al
  10:	46 05 40 00 00 00    	rex.RX add eax,0x40
  16:	00 00                	add    BYTE PTR [rax],al
  18:	21 01                	and    DWORD PTR [rcx],eax
  1a:	00 00                	add    BYTE PTR [rax],al
  1c:	00 00                	add    BYTE PTR [rax],al
  1e:	00 00                	add    BYTE PTR [rax],al
  20:	67 06                	addr32 (bad) 
  22:	40 00 00             	add    BYTE PTR [rax],al
  25:	00 00                	add    BYTE PTR [rax],al
  27:	00 14 00             	add    BYTE PTR [rax+rax*1],dl
  2a:	00 00                	add    BYTE PTR [rax],al
  2c:	00 00                	add    BYTE PTR [rax],al
  2e:	00 00                	add    BYTE PTR [rax],al
  30:	7b 06                	jnp    38 <_init-0x4003b8>
  32:	40 00 00             	add    BYTE PTR [rax],al
  35:	00 00                	add    BYTE PTR [rax],al
  37:	00 26                	add    BYTE PTR [rsi],ah
  39:	00 00                	add    BYTE PTR [rax],al
  3b:	00 00                	add    BYTE PTR [rax],al
  3d:	00 00                	add    BYTE PTR [rax],al
  3f:	00 a1 06 40 00 00    	add    BYTE PTR [rcx+0x4006],ah
  45:	00 00                	add    BYTE PTR [rax],al
  47:	00 3c 00             	add    BYTE PTR [rax+rax*1],bh
  4a:	00 00                	add    BYTE PTR [rax],al
  4c:	00 00                	add    BYTE PTR [rax],al
  4e:	00 00                	add    BYTE PTR [rax],al
  50:	de 06                	fiadd  WORD PTR [rsi]
  52:	40 00 00             	add    BYTE PTR [rax],al
  55:	00 00                	add    BYTE PTR [rax],al
  57:	00 0b                	add    BYTE PTR [rbx],cl
  59:	00 00                	add    BYTE PTR [rax],al
  5b:	00 00                	add    BYTE PTR [rax],al
  5d:	00 00                	add    BYTE PTR [rax],al
  5f:	00 ea                	add    dl,ch
  61:	06                   	(bad)  
  62:	40 00 00             	add    BYTE PTR [rax],al
  65:	00 00                	add    BYTE PTR [rax],al
  67:	00 1b                	add    BYTE PTR [rbx],bl
	...

Disassembly of section .debug_info:

0000000000000000 <.debug_info>:
   0:	f2 0e                	repnz (bad) 
   2:	00 00                	add    BYTE PTR [rax],al
   4:	04 00                	add    al,0x0
   6:	00 00                	add    BYTE PTR [rax],al
   8:	00 00                	add    BYTE PTR [rax],al
   a:	08 01                	or     BYTE PTR [rcx],al
   c:	0c 00                	or     al,0x0
   e:	00 00                	add    BYTE PTR [rax],al
  10:	04 72                	add    al,0x72
  12:	04 00                	add    al,0x0
  14:	00 aa 04 00 00 00    	add    BYTE PTR [rdx+0x4],ch
	...
  26:	00 00                	add    BYTE PTR [rax],al
  28:	00 02                	add    BYTE PTR [rdx],al
  2a:	73 74                	jae    a0 <_init-0x400350>
  2c:	64 00 05 00 02 0a 00 	add    BYTE PTR fs:[rip+0xa0200],al        # a0233 <_init-0x3601bd>
  33:	00 03                	add    BYTE PTR [rbx],al
  35:	ec                   	in     al,dx
  36:	00 00                	add    BYTE PTR [rax],al
  38:	00 04 da             	add    BYTE PTR [rdx+rbx*8],al
  3b:	04 04                	add    al,0x4
  3d:	da 34 00             	fidiv  DWORD PTR [rax+rax*1]
  40:	00 00                	add    BYTE PTR [rax],al
  42:	05 c2 0d 00 00       	add    eax,0xdc2
  47:	04 46                	add    al,0x46
  49:	0a 00                	or     al,BYTE PTR [rax]
  4b:	00 01                	add    BYTE PTR [rcx],al
  4d:	37                   	(bad)  
  4e:	77 00                	ja     50 <_init-0x4003a0>
  50:	00 00                	add    BYTE PTR [rax],al
  52:	06                   	(bad)  
  53:	ba 06 00 00 00       	mov    edx,0x6
  58:	06                   	(bad)  
  59:	dc 0a                	fmul   QWORD PTR [rdx]
  5b:	00 00                	add    BYTE PTR [rax],al
  5d:	01 06                	add    DWORD PTR [rsi],eax
  5f:	b3 08                	mov    bl,0x8
  61:	00 00                	add    BYTE PTR [rax],al
  63:	02 06                	add    al,BYTE PTR [rsi]
  65:	92                   	xchg   edx,eax
  66:	00 00                	add    BYTE PTR [rax],al
  68:	00 03                	add    BYTE PTR [rbx],al
  6a:	06                   	(bad)  
  6b:	89 09                	mov    DWORD PTR [rcx],ecx
  6d:	00 00                	add    BYTE PTR [rax],al
  6f:	04 06                	add    al,0x6
  71:	2b 04 00             	sub    eax,DWORD PTR [rax+rax*1]
  74:	00 05 00 05 8d 0a    	add    BYTE PTR [rip+0xa8d0500],al        # a8d057a <_end+0xa2cf53a>
  7a:	00 00                	add    BYTE PTR [rax],al
  7c:	04 46                	add    al,0x46
  7e:	0a 00                	or     al,BYTE PTR [rax]
  80:	00 01                	add    BYTE PTR [rcx],al
  82:	41 aa                	rex.B stos BYTE PTR es:[rdi],al
  84:	00 00                	add    BYTE PTR [rax],al
  86:	00 07                	add    BYTE PTR [rdi],al
  88:	3e 0c 00             	ds or  al,0x0
  8b:	00 ff                	add    bh,bh
  8d:	ff 08                	dec    DWORD PTR [rax]
  8f:	42 09 00             	rex.X or DWORD PTR [rax],eax
  92:	00 00                	add    BYTE PTR [rax],al
  94:	00 ff                	add    bh,bh
  96:	ff 08                	dec    DWORD PTR [rax]
  98:	f1                   	icebp  
  99:	0a 00                	or     al,BYTE PTR [rax]
  9b:	00 00                	add    BYTE PTR [rax],al
  9d:	00 01                	add    BYTE PTR [rcx],al
  9f:	00 08                	add    BYTE PTR [rax],cl
  a1:	27                   	(bad)  
  a2:	09 00                	or     DWORD PTR [rax],eax
  a4:	00 00                	add    BYTE PTR [rax],al
  a6:	00 02                	add    BYTE PTR [rdx],al
  a8:	00 00                	add    BYTE PTR [rax],al
  aa:	09 c2                	or     edx,eax
  ac:	0d 00 00 01 3f       	or     eax,0x3f010000
  b1:	42 00 00             	rex.X add BYTE PTR [rax],al
  b4:	00 0a                	add    BYTE PTR [rdx],cl
  b6:	29 01                	sub    DWORD PTR [rcx],eax
  b8:	00 00                	add    BYTE PTR [rax],al
  ba:	04 01                	add    al,0x1
  bc:	ee                   	out    dx,al
  bd:	b3 08                	mov    bl,0x8
  bf:	00 00                	add    BYTE PTR [rax],al
  c1:	0b c3                	or     eax,ebx
  c3:	02 00                	add    al,BYTE PTR [rax]
  c5:	00 01                	add    BYTE PTR [rcx],al
  c7:	f3 5b                	repz pop rbx
  c9:	0a 00                	or     al,BYTE PTR [rax]
  cb:	00 03                	add    BYTE PTR [rbx],al
  cd:	04 0c                	add    al,0xc
  cf:	9f                   	lahf   
  d0:	04 00                	add    al,0x0
  d2:	00 01                	add    BYTE PTR [rcx],al
  d4:	f1                   	icebp  
  d5:	2a 0a                	sub    cl,BYTE PTR [rdx]
  d7:	00 00                	add    BYTE PTR [rax],al
  d9:	03 0d e6 0b 00 00    	add    ecx,DWORD PTR [rip+0xbe6]        # cc5 <_init-0x3ff72b>
  df:	01 f6                	add    esi,esi
  e1:	ce                   	(bad)  
  e2:	00 00                	add    BYTE PTR [rax],al
  e4:	00 00                	add    BYTE PTR [rax],al
  e6:	03 0e                	add    ecx,DWORD PTR [rsi]
  e8:	01 03                	add    DWORD PTR [rbx],eax
  ea:	00 00                	add    BYTE PTR [rax],al
  ec:	01 f9                	add    ecx,edi
  ee:	cf                   	iret   
  ef:	06                   	(bad)  
  f0:	00 00                	add    BYTE PTR [rax],al
  f2:	fa                   	cli    
  f3:	00 00                	add    BYTE PTR [rax],al
  f5:	00 00                	add    BYTE PTR [rax],al
  f7:	01 00                	add    DWORD PTR [rax],eax
  f9:	00 0f                	add    BYTE PTR [rdi],cl
  fb:	67 0a 00             	or     al,BYTE PTR [eax]
  fe:	00 00                	add    BYTE PTR [rax],al
 100:	0e                   	(bad)  
 101:	00 03                	add    BYTE PTR [rbx],al
 103:	00 00                	add    BYTE PTR [rax],al
 105:	01 fa                	add    edx,edi
 107:	20 05 00 00 13 01    	and    BYTE PTR [rip+0x1130000],al        # 113010d <_end+0xb2f0cd>
 10d:	00 00                	add    BYTE PTR [rax],al
 10f:	1e                   	(bad)  
 110:	01 00                	add    DWORD PTR [rax],eax
 112:	00 0f                	add    BYTE PTR [rdi],cl
 114:	67 0a 00             	or     al,BYTE PTR [eax]
 117:	00 0f                	add    BYTE PTR [rdi],cl
 119:	2a 0a                	sub    cl,BYTE PTR [rdx]
 11b:	00 00                	add    BYTE PTR [rax],al
 11d:	00 10                	add    BYTE PTR [rax],dl
 11f:	01 03                	add    DWORD PTR [rbx],eax
 121:	00 00                	add    BYTE PTR [rax],al
 123:	01 fb                	add    ebx,edi
 125:	a3 02 00 00 31 01 00 	movabs ds:0x3c00000131000002,eax
 12c:	00 3c 
 12e:	01 00                	add    DWORD PTR [rax],eax
 130:	00 0f                	add    BYTE PTR [rdi],cl
 132:	67 0a 00             	or     al,BYTE PTR [eax]
 135:	00 11                	add    BYTE PTR [rcx],dl
 137:	6d                   	ins    DWORD PTR es:[rdi],dx
 138:	0a 00                	or     al,BYTE PTR [rax]
 13a:	00 00                	add    BYTE PTR [rax],al
 13c:	12 c8                	adc    cl,al
 13e:	09 00                	or     DWORD PTR [rax],eax
 140:	00 01                	add    BYTE PTR [rcx],al
 142:	fc                   	cld    
 143:	5f                   	pop    rdi
 144:	09 00                	or     DWORD PTR [rax],eax
 146:	00 73 0a             	add    BYTE PTR [rbx+0xa],dh
 149:	00 00                	add    BYTE PTR [rax],al
 14b:	53                   	push   rbx
 14c:	01 00                	add    DWORD PTR [rax],eax
 14e:	00 5e 01             	add    BYTE PTR [rsi+0x1],bl
 151:	00 00                	add    BYTE PTR [rax],al
 153:	0f 67 0a             	packuswb mm1,QWORD PTR [rdx]
 156:	00 00                	add    BYTE PTR [rax],al
 158:	11 6d 0a             	adc    DWORD PTR [rbp+0xa],ebp
 15b:	00 00                	add    BYTE PTR [rax],al
 15d:	00 12                	add    BYTE PTR [rdx],dl
 15f:	c8 09 00 00          	enter  0x9,0x0
 163:	01 fd                	add    ebp,edi
 165:	0f 03 00             	lsl    eax,WORD PTR [rax]
 168:	00 73 0a             	add    BYTE PTR [rbx+0xa],dh
 16b:	00 00                	add    BYTE PTR [rax],al
 16d:	75 01                	jne    170 <_init-0x400280>
 16f:	00 00                	add    BYTE PTR [rax],al
 171:	80 01 00             	add    BYTE PTR [rcx],0x0
 174:	00 0f                	add    BYTE PTR [rdi],cl
 176:	79 0a                	jns    182 <_init-0x40026e>
 178:	00 00                	add    BYTE PTR [rax],al
 17a:	11 6d 0a             	adc    DWORD PTR [rbp+0xa],ebp
 17d:	00 00                	add    BYTE PTR [rax],al
 17f:	00 13                	add    BYTE PTR [rbx],dl
 181:	01 03                	add    DWORD PTR [rbx],eax
 183:	00 00                	add    BYTE PTR [rax],al
 185:	01 00                	add    DWORD PTR [rax],eax
 187:	01 66 06             	add    DWORD PTR [rsi+0x6],esp
 18a:	00 00                	add    BYTE PTR [rax],al
 18c:	94                   	xchg   esp,eax
 18d:	01 00                	add    DWORD PTR [rax],eax
 18f:	00 9f 01 00 00 0f    	add    BYTE PTR [rdi+0xf000001],bl
 195:	67 0a 00             	or     al,BYTE PTR [eax]
 198:	00 11                	add    BYTE PTR [rcx],dl
 19a:	ce                   	(bad)  
 19b:	00 00                	add    BYTE PTR [rax],al
 19d:	00 00                	add    BYTE PTR [rax],al
 19f:	14 7d                	adc    al,0x7d
 1a1:	04 00                	add    al,0x0
 1a3:	00 01                	add    BYTE PTR [rcx],al
 1a5:	02 01                	add    al,BYTE PTR [rcx]
 1a7:	54                   	push   rsp
 1a8:	04 00                	add    al,0x0
 1aa:	00 ce                	add    dh,cl
 1ac:	00 00                	add    BYTE PTR [rax],al
 1ae:	00 b7 01 00 00 bd    	add    BYTE PTR [rdi-0x42ffffff],dh
 1b4:	01 00                	add    DWORD PTR [rax],eax
 1b6:	00 0f                	add    BYTE PTR [rdi],cl
 1b8:	7f 0a                	jg     1c4 <_init-0x40022c>
 1ba:	00 00                	add    BYTE PTR [rax],al
 1bc:	00 14 7d 04 00 00 01 	add    BYTE PTR [rdi*2+0x1000004],dl
 1c3:	05 01 53 02 00       	add    eax,0x25301
 1c8:	00 ce                	add    dh,cl
 1ca:	00 00                	add    BYTE PTR [rax],al
 1cc:	00 d5                	add    ch,dl
 1ce:	01 00                	add    DWORD PTR [rax],eax
 1d0:	00 db                	add    bl,bl
 1d2:	01 00                	add    DWORD PTR [rax],eax
 1d4:	00 0f                	add    BYTE PTR [rdi],cl
 1d6:	85 0a                	test   DWORD PTR [rdx],ecx
 1d8:	00 00                	add    BYTE PTR [rax],al
 1da:	00 14 c8             	add    BYTE PTR [rax+rcx*8],dl
 1dd:	09 00                	or     DWORD PTR [rax],eax
 1df:	00 01                	add    BYTE PTR [rcx],al
 1e1:	09 01                	or     DWORD PTR [rcx],eax
 1e3:	c8 08 00 00          	enter  0x8,0x0
 1e7:	ce                   	(bad)  
 1e8:	00 00                	add    BYTE PTR [rax],al
 1ea:	00 f3                	add    bl,dh
 1ec:	01 00                	add    DWORD PTR [rax],eax
 1ee:	00 fe                	add    dh,bh
 1f0:	01 00                	add    DWORD PTR [rax],eax
 1f2:	00 0f                	add    BYTE PTR [rdi],cl
 1f4:	67 0a 00             	or     al,BYTE PTR [eax]
 1f7:	00 11                	add    BYTE PTR [rcx],dl
 1f9:	ce                   	(bad)  
 1fa:	00 00                	add    BYTE PTR [rax],al
 1fc:	00 00                	add    BYTE PTR [rax],al
 1fe:	14 c8                	adc    al,0xc8
 200:	09 00                	or     DWORD PTR [rax],eax
 202:	00 01                	add    BYTE PTR [rcx],al
 204:	10 01                	adc    BYTE PTR [rcx],al
 206:	39 0b                	cmp    DWORD PTR [rbx],ecx
 208:	00 00                	add    BYTE PTR [rax],al
 20a:	ce                   	(bad)  
 20b:	00 00                	add    BYTE PTR [rax],al
 20d:	00 16                	add    BYTE PTR [rsi],dl
 20f:	02 00                	add    al,BYTE PTR [rax]
 211:	00 21                	add    BYTE PTR [rcx],ah
 213:	02 00                	add    al,BYTE PTR [rax]
 215:	00 0f                	add    BYTE PTR [rdi],cl
 217:	79 0a                	jns    223 <_init-0x4001cd>
 219:	00 00                	add    BYTE PTR [rax],al
 21b:	11 ce                	adc    esi,ecx
 21d:	00 00                	add    BYTE PTR [rax],al
 21f:	00 00                	add    BYTE PTR [rax],al
 221:	14 22                	adc    al,0x22
 223:	08 00                	or     BYTE PTR [rax],al
 225:	00 01                	add    BYTE PTR [rcx],al
 227:	17                   	(bad)  
 228:	01 9e 09 00 00 ce    	add    DWORD PTR [rsi-0x31fffff7],ebx
 22e:	00 00                	add    BYTE PTR [rax],al
 230:	00 39                	add    BYTE PTR [rcx],bh
 232:	02 00                	add    al,BYTE PTR [rax]
 234:	00 44 02 00          	add    BYTE PTR [rdx+rax*1+0x0],al
 238:	00 0f                	add    BYTE PTR [rdi],cl
 23a:	67 0a 00             	or     al,BYTE PTR [eax]
 23d:	00 11                	add    BYTE PTR [rcx],dl
 23f:	2a 0a                	sub    cl,BYTE PTR [rdx]
 241:	00 00                	add    BYTE PTR [rax],al
 243:	00 14 22             	add    BYTE PTR [rdx+riz*1],dl
 246:	08 00                	or     BYTE PTR [rax],al
 248:	00 01                	add    BYTE PTR [rcx],al
 24a:	1b 01                	sbb    eax,DWORD PTR [rcx]
 24c:	b4 0c                	mov    ah,0xc
 24e:	00 00                	add    BYTE PTR [rax],al
 250:	ce                   	(bad)  
 251:	00 00                	add    BYTE PTR [rax],al
 253:	00 5c 02 00          	add    BYTE PTR [rdx+rax*1+0x0],bl
 257:	00 67 02             	add    BYTE PTR [rdi+0x2],ah
 25a:	00 00                	add    BYTE PTR [rax],al
 25c:	0f 79 0a             	vmwrite rcx,QWORD PTR [rdx]
 25f:	00 00                	add    BYTE PTR [rax],al
 261:	11 2a                	adc    DWORD PTR [rdx],ebp
 263:	0a 00                	or     al,BYTE PTR [rax]
 265:	00 00                	add    BYTE PTR [rax],al
 267:	14 2e                	adc    al,0x2e
 269:	0b 00                	or     eax,DWORD PTR [rax]
 26b:	00 01                	add    BYTE PTR [rcx],al
 26d:	1f                   	(bad)  
 26e:	01 62 08             	add    DWORD PTR [rdx+0x8],esp
 271:	00 00                	add    BYTE PTR [rax],al
 273:	ce                   	(bad)  
 274:	00 00                	add    BYTE PTR [rax],al
 276:	00 7f 02             	add    BYTE PTR [rdi+0x2],bh
 279:	00 00                	add    BYTE PTR [rax],al
 27b:	8a 02                	mov    al,BYTE PTR [rdx]
 27d:	00 00                	add    BYTE PTR [rax],al
 27f:	0f 67 0a             	packuswb mm1,QWORD PTR [rdx]
 282:	00 00                	add    BYTE PTR [rax],al
 284:	11 2a                	adc    DWORD PTR [rdx],ebp
 286:	0a 00                	or     al,BYTE PTR [rax]
 288:	00 00                	add    BYTE PTR [rax],al
 28a:	14 2e                	adc    al,0x2e
 28c:	0b 00                	or     eax,DWORD PTR [rax]
 28e:	00 01                	add    BYTE PTR [rcx],al
 290:	23 01                	and    eax,DWORD PTR [rcx]
 292:	5c                   	pop    rsp
 293:	01 00                	add    DWORD PTR [rax],eax
 295:	00 ce                	add    dh,cl
 297:	00 00                	add    BYTE PTR [rax],al
 299:	00 a2 02 00 00 ad    	add    BYTE PTR [rdx-0x52fffffe],ah
 29f:	02 00                	add    al,BYTE PTR [rax]
 2a1:	00 0f                	add    BYTE PTR [rdi],cl
 2a3:	79 0a                	jns    2af <_init-0x400141>
 2a5:	00 00                	add    BYTE PTR [rax],al
 2a7:	11 2a                	adc    DWORD PTR [rdx],ebp
 2a9:	0a 00                	or     al,BYTE PTR [rax]
 2ab:	00 00                	add    BYTE PTR [rax],al
 2ad:	14 22                	adc    al,0x22
 2af:	08 00                	or     BYTE PTR [rax],al
 2b1:	00 01                	add    BYTE PTR [rcx],al
 2b3:	27                   	(bad)  
 2b4:	01 d2                	add    edx,edx
 2b6:	09 00                	or     DWORD PTR [rax],eax
 2b8:	00 ce                	add    dh,cl
 2ba:	00 00                	add    BYTE PTR [rax],al
 2bc:	00 c5                	add    ch,al
 2be:	02 00                	add    al,BYTE PTR [rax]
 2c0:	00 cb                	add    bl,cl
 2c2:	02 00                	add    al,BYTE PTR [rax]
 2c4:	00 0f                	add    BYTE PTR [rdi],cl
 2c6:	67 0a 00             	or     al,BYTE PTR [eax]
 2c9:	00 00                	add    BYTE PTR [rax],al
 2cb:	14 22                	adc    al,0x22
 2cd:	08 00                	or     BYTE PTR [rax],al
 2cf:	00 01                	add    BYTE PTR [rcx],al
 2d1:	2b 01                	sub    eax,DWORD PTR [rcx]
 2d3:	d1 0c 00             	ror    DWORD PTR [rax+rax*1],1
 2d6:	00 ce                	add    dh,cl
 2d8:	00 00                	add    BYTE PTR [rax],al
 2da:	00 e3                	add    bl,ah
 2dc:	02 00                	add    al,BYTE PTR [rax]
 2de:	00 e9                	add    cl,ch
 2e0:	02 00                	add    al,BYTE PTR [rax]
 2e2:	00 0f                	add    BYTE PTR [rdi],cl
 2e4:	79 0a                	jns    2f0 <_init-0x400100>
 2e6:	00 00                	add    BYTE PTR [rax],al
 2e8:	00 14 2e             	add    BYTE PTR [rsi+rbp*1],dl
 2eb:	0b 00                	or     eax,DWORD PTR [rax]
 2ed:	00 01                	add    BYTE PTR [rcx],al
 2ef:	2f                   	(bad)  
 2f0:	01 ef                	add    edi,ebp
 2f2:	08 00                	or     BYTE PTR [rax],al
 2f4:	00 ce                	add    dh,cl
 2f6:	00 00                	add    BYTE PTR [rax],al
 2f8:	00 01                	add    BYTE PTR [rcx],al
 2fa:	03 00                	add    eax,DWORD PTR [rax]
 2fc:	00 07                	add    BYTE PTR [rdi],al
 2fe:	03 00                	add    eax,DWORD PTR [rax]
 300:	00 0f                	add    BYTE PTR [rdi],cl
 302:	67 0a 00             	or     al,BYTE PTR [eax]
 305:	00 00                	add    BYTE PTR [rax],al
 307:	14 2e                	adc    al,0x2e
 309:	0b 00                	or     eax,DWORD PTR [rax]
 30b:	00 01                	add    BYTE PTR [rcx],al
 30d:	33 01                	xor    eax,DWORD PTR [rcx]
 30f:	86 02                	xchg   BYTE PTR [rdx],al
 311:	00 00                	add    BYTE PTR [rax],al
 313:	ce                   	(bad)  
 314:	00 00                	add    BYTE PTR [rax],al
 316:	00 1f                	add    BYTE PTR [rdi],bl
 318:	03 00                	add    eax,DWORD PTR [rax]
 31a:	00 25 03 00 00 0f    	add    BYTE PTR [rip+0xf000003],ah        # f000323 <_end+0xe9ff2e3>
 320:	79 0a                	jns    32c <_init-0x4000c4>
 322:	00 00                	add    BYTE PTR [rax],al
 324:	00 14 e4             	add    BYTE PTR [rsp+riz*8],dl
 327:	08 00                	or     BYTE PTR [rax],al
 329:	00 01                	add    BYTE PTR [rcx],al
 32b:	37                   	(bad)  
 32c:	01 c1                	add    ecx,eax
 32e:	01 00                	add    DWORD PTR [rax],eax
 330:	00 ce                	add    dh,cl
 332:	00 00                	add    BYTE PTR [rax],al
 334:	00 3d 03 00 00 48    	add    BYTE PTR [rip+0x48000003],bh        # 4800033d <_end+0x479ff2fd>
 33a:	03 00                	add    eax,DWORD PTR [rax]
 33c:	00 0f                	add    BYTE PTR [rdi],cl
 33e:	67 0a 00             	or     al,BYTE PTR [eax]
 341:	00 11                	add    BYTE PTR [rcx],dl
 343:	ce                   	(bad)  
 344:	00 00                	add    BYTE PTR [rax],al
 346:	00 00                	add    BYTE PTR [rax],al
 348:	14 e4                	adc    al,0xe4
 34a:	08 00                	or     BYTE PTR [rax],al
 34c:	00 01                	add    BYTE PTR [rcx],al
 34e:	3b 01                	cmp    eax,DWORD PTR [rcx]
 350:	c7 05 00 00 ce 00 00 	mov    DWORD PTR [rip+0xce0000],0x3600000        # ce035a <_end+0x6df31a>
 357:	00 60 03 
 35a:	00 00                	add    BYTE PTR [rax],al
 35c:	6b 03 00             	imul   eax,DWORD PTR [rbx],0x0
 35f:	00 0f                	add    BYTE PTR [rdi],cl
 361:	79 0a                	jns    36d <_init-0x400083>
 363:	00 00                	add    BYTE PTR [rax],al
 365:	11 ce                	adc    esi,ecx
 367:	00 00                	add    BYTE PTR [rax],al
 369:	00 00                	add    BYTE PTR [rax],al
 36b:	14 d5                	adc    al,0xd5
 36d:	0b 00                	or     eax,DWORD PTR [rax]
 36f:	00 01                	add    BYTE PTR [rcx],al
 371:	3f                   	(bad)  
 372:	01 6d 00             	add    DWORD PTR [rbp+0x0],ebp
 375:	00 00                	add    BYTE PTR [rax],al
 377:	ce                   	(bad)  
 378:	00 00                	add    BYTE PTR [rax],al
 37a:	00 83 03 00 00 8e    	add    BYTE PTR [rbx-0x71fffffd],al
 380:	03 00                	add    eax,DWORD PTR [rax]
 382:	00 0f                	add    BYTE PTR [rdi],cl
 384:	67 0a 00             	or     al,BYTE PTR [eax]
 387:	00 11                	add    BYTE PTR [rcx],dl
 389:	ce                   	(bad)  
 38a:	00 00                	add    BYTE PTR [rax],al
 38c:	00 00                	add    BYTE PTR [rax],al
 38e:	14 d5                	adc    al,0xd5
 390:	0b 00                	or     eax,DWORD PTR [rax]
 392:	00 01                	add    BYTE PTR [rcx],al
 394:	43 01 40 03          	rex.XB add DWORD PTR [r8+0x3],eax
 398:	00 00                	add    BYTE PTR [rax],al
 39a:	ce                   	(bad)  
 39b:	00 00                	add    BYTE PTR [rax],al
 39d:	00 a6 03 00 00 b1    	add    BYTE PTR [rsi-0x4efffffd],ah
 3a3:	03 00                	add    eax,DWORD PTR [rax]
 3a5:	00 0f                	add    BYTE PTR [rdi],cl
 3a7:	79 0a                	jns    3b3 <_init-0x40003d>
 3a9:	00 00                	add    BYTE PTR [rax],al
 3ab:	11 ce                	adc    esi,ecx
 3ad:	00 00                	add    BYTE PTR [rax],al
 3af:	00 00                	add    BYTE PTR [rax],al
 3b1:	14 a9                	adc    al,0xa9
 3b3:	0c 00                	or     al,0x0
 3b5:	00 01                	add    BYTE PTR [rcx],al
 3b7:	47 01 0b             	rex.RXB add DWORD PTR [r11],r9d
 3ba:	09 00                	or     DWORD PTR [rax],eax
 3bc:	00 ce                	add    dh,cl
 3be:	00 00                	add    BYTE PTR [rax],al
 3c0:	00 c9                	add    cl,cl
 3c2:	03 00                	add    eax,DWORD PTR [rax]
 3c4:	00 d4                	add    ah,dl
 3c6:	03 00                	add    eax,DWORD PTR [rax]
 3c8:	00 0f                	add    BYTE PTR [rdi],cl
 3ca:	67 0a 00             	or     al,BYTE PTR [eax]
 3cd:	00 11                	add    BYTE PTR [rcx],dl
 3cf:	ce                   	(bad)  
 3d0:	00 00                	add    BYTE PTR [rax],al
 3d2:	00 00                	add    BYTE PTR [rax],al
 3d4:	14 a9                	adc    al,0xa9
 3d6:	0c 00                	or     al,0x0
 3d8:	00 01                	add    BYTE PTR [rcx],al
 3da:	4b 01 56 0a          	rex.WXB add QWORD PTR [r14+0xa],rdx
 3de:	00 00                	add    BYTE PTR [rax],al
 3e0:	ce                   	(bad)  
 3e1:	00 00                	add    BYTE PTR [rax],al
 3e3:	00 ec                	add    ah,ch
 3e5:	03 00                	add    eax,DWORD PTR [rax]
 3e7:	00 f7                	add    bh,dh
 3e9:	03 00                	add    eax,DWORD PTR [rax]
 3eb:	00 0f                	add    BYTE PTR [rdi],cl
 3ed:	79 0a                	jns    3f9 <_init-0x3ffff7>
 3ef:	00 00                	add    BYTE PTR [rax],al
 3f1:	11 ce                	adc    esi,ecx
 3f3:	00 00                	add    BYTE PTR [rax],al
 3f5:	00 00                	add    BYTE PTR [rax],al
 3f7:	14 72                	adc    al,0x72
 3f9:	02 00                	add    al,BYTE PTR [rax]
 3fb:	00 01                	add    BYTE PTR [rcx],al
 3fd:	4f 01 b9 0b 00 00 ce 	rex.WRXB add QWORD PTR [r9-0x31fffff5],r15
 404:	00 00                	add    BYTE PTR [rax],al
 406:	00 0f                	add    BYTE PTR [rdi],cl
 408:	04 00                	add    al,0x0
 40a:	00 1a                	add    BYTE PTR [rdx],bl
 40c:	04 00                	add    al,0x0
 40e:	00 0f                	add    BYTE PTR [rdi],cl
 410:	67 0a 00             	or     al,BYTE PTR [eax]
 413:	00 11                	add    BYTE PTR [rcx],dl
 415:	ce                   	(bad)  
 416:	00 00                	add    BYTE PTR [rax],al
 418:	00 00                	add    BYTE PTR [rax],al
 41a:	14 72                	adc    al,0x72
 41c:	02 00                	add    al,BYTE PTR [rax]
 41e:	00 01                	add    BYTE PTR [rcx],al
 420:	53                   	push   rbx
 421:	01 41 06             	add    DWORD PTR [rcx+0x6],eax
 424:	00 00                	add    BYTE PTR [rax],al
 426:	ce                   	(bad)  
 427:	00 00                	add    BYTE PTR [rax],al
 429:	00 32                	add    BYTE PTR [rdx],dh
 42b:	04 00                	add    al,0x0
 42d:	00 3d 04 00 00 0f    	add    BYTE PTR [rip+0xf000004],bh        # f000437 <_end+0xe9ff3f7>
 433:	79 0a                	jns    43f <_init-0x3fffb1>
 435:	00 00                	add    BYTE PTR [rax],al
 437:	11 ce                	adc    esi,ecx
 439:	00 00                	add    BYTE PTR [rax],al
 43b:	00 00                	add    BYTE PTR [rax],al
 43d:	14 30                	adc    al,0x30
 43f:	03 00                	add    eax,DWORD PTR [rax]
 441:	00 01                	add    BYTE PTR [rcx],al
 443:	57                   	push   rdi
 444:	01 ff                	add    edi,edi
 446:	0b 00                	or     eax,DWORD PTR [rax]
 448:	00 ce                	add    dh,cl
 44a:	00 00                	add    BYTE PTR [rax],al
 44c:	00 55 04             	add    BYTE PTR [rbp+0x4],dl
 44f:	00 00                	add    BYTE PTR [rax],al
 451:	60                   	(bad)  
 452:	04 00                	add    al,0x0
 454:	00 0f                	add    BYTE PTR [rdi],cl
 456:	67 0a 00             	or     al,BYTE PTR [eax]
 459:	00 11                	add    BYTE PTR [rcx],dl
 45b:	ce                   	(bad)  
 45c:	00 00                	add    BYTE PTR [rax],al
 45e:	00 00                	add    BYTE PTR [rax],al
 460:	14 30                	adc    al,0x30
 462:	03 00                	add    eax,DWORD PTR [rax]
 464:	00 01                	add    BYTE PTR [rcx],al
 466:	5b                   	pop    rbx
 467:	01 f4                	add    esp,esi
 469:	00 00                	add    BYTE PTR [rax],al
 46b:	00 ce                	add    dh,cl
 46d:	00 00                	add    BYTE PTR [rax],al
 46f:	00 78 04             	add    BYTE PTR [rax+0x4],bh
 472:	00 00                	add    BYTE PTR [rax],al
 474:	83 04 00 00          	add    DWORD PTR [rax+rax*1],0x0
 478:	0f 79 0a             	vmwrite rcx,QWORD PTR [rdx]
 47b:	00 00                	add    BYTE PTR [rax],al
 47d:	11 ce                	adc    esi,ecx
 47f:	00 00                	add    BYTE PTR [rax],al
 481:	00 00                	add    BYTE PTR [rax],al
 483:	14 4b                	adc    al,0x4b
 485:	0d 00 00 01 5f       	or     eax,0x5f010000
 48a:	01 87 06 00 00 54    	add    DWORD PTR [rdi+0x54000006],eax
 490:	0a 00                	or     al,BYTE PTR [rax]
 492:	00 9b 04 00 00 a1    	add    BYTE PTR [rbx-0x5efffffc],bl
 498:	04 00                	add    al,0x0
 49a:	00 0f                	add    BYTE PTR [rdi],cl
 49c:	7f 0a                	jg     4a8 <_init-0x3fff48>
 49e:	00 00                	add    BYTE PTR [rax],al
 4a0:	00 14 4b             	add    BYTE PTR [rbx+rcx*2],dl
 4a3:	0d 00 00 01 67       	or     eax,0x67010000
 4a8:	01 55 05             	add    DWORD PTR [rbp+0x5],edx
 4ab:	00 00                	add    BYTE PTR [rax],al
 4ad:	54                   	push   rsp
 4ae:	0a 00                	or     al,BYTE PTR [rax]
 4b0:	00 b9 04 00 00 bf    	add    BYTE PTR [rcx-0x40fffffc],bh
 4b6:	04 00                	add    al,0x0
 4b8:	00 0f                	add    BYTE PTR [rdi],cl
 4ba:	85 0a                	test   DWORD PTR [rdx],ecx
 4bc:	00 00                	add    BYTE PTR [rax],al
 4be:	00 13                	add    BYTE PTR [rbx],dl
 4c0:	3b 06                	cmp    eax,DWORD PTR [rsi]
 4c2:	00 00                	add    BYTE PTR [rax],al
 4c4:	01 6f 01             	add    DWORD PTR [rdi+0x1],ebp
 4c7:	d0 02                	rol    BYTE PTR [rdx],1
 4c9:	00 00                	add    BYTE PTR [rax],al
 4cb:	d3 04 00             	rol    DWORD PTR [rax+rax*1],cl
 4ce:	00 e3                	add    bl,ah
 4d0:	04 00                	add    al,0x0
 4d2:	00 0f                	add    BYTE PTR [rdi],cl
 4d4:	67 0a 00             	or     al,BYTE PTR [eax]
 4d7:	00 11                	add    BYTE PTR [rcx],dl
 4d9:	ce                   	(bad)  
 4da:	00 00                	add    BYTE PTR [rax],al
 4dc:	00 11                	add    BYTE PTR [rcx],dl
 4de:	aa                   	stos   BYTE PTR es:[rdi],al
 4df:	00 00                	add    BYTE PTR [rax],al
 4e1:	00 00                	add    BYTE PTR [rax],al
 4e3:	13 3b                	adc    edi,DWORD PTR [rbx]
 4e5:	06                   	(bad)  
 4e6:	00 00                	add    BYTE PTR [rax],al
 4e8:	01 7a 01             	add    DWORD PTR [rdx+0x1],edi
 4eb:	91                   	xchg   ecx,eax
 4ec:	03 00                	add    eax,DWORD PTR [rax]
 4ee:	00 f7                	add    bh,dh
 4f0:	04 00                	add    al,0x0
 4f2:	00 07                	add    BYTE PTR [rdi],al
 4f4:	05 00 00 0f 79       	add    eax,0x790f0000
 4f9:	0a 00                	or     al,BYTE PTR [rax]
 4fb:	00 11                	add    BYTE PTR [rcx],dl
 4fd:	ce                   	(bad)  
 4fe:	00 00                	add    BYTE PTR [rax],al
 500:	00 11                	add    BYTE PTR [rcx],dl
 502:	aa                   	stos   BYTE PTR es:[rdi],al
 503:	00 00                	add    BYTE PTR [rax],al
 505:	00 00                	add    BYTE PTR [rax],al
 507:	14 fa                	adc    al,0xfa
 509:	07                   	(bad)  
 50a:	00 00                	add    BYTE PTR [rax],al
 50c:	01 86 01 82 07 00    	add    DWORD PTR [rsi+0x78201],eax
 512:	00 ce                	add    dh,cl
 514:	00 00                	add    BYTE PTR [rax],al
 516:	00 1f                	add    BYTE PTR [rdi],bl
 518:	05 00 00 2a 05       	add    eax,0x52a0000
 51d:	00 00                	add    BYTE PTR [rax],al
 51f:	0f 7f 0a             	movq   QWORD PTR [rdx],mm1
 522:	00 00                	add    BYTE PTR [rax],al
 524:	11 aa 00 00 00 00    	adc    DWORD PTR [rdx+0x0],ebp
 52a:	14 fa                	adc    al,0xfa
 52c:	07                   	(bad)  
 52d:	00 00                	add    BYTE PTR [rax],al
 52f:	01 90 01 89 0b 00    	add    DWORD PTR [rax+0xb8901],edx
 535:	00 ce                	add    dh,cl
 537:	00 00                	add    BYTE PTR [rax],al
 539:	00 42 05             	add    BYTE PTR [rdx+0x5],al
 53c:	00 00                	add    BYTE PTR [rax],al
 53e:	4d 05 00 00 0f 85    	rex.WRB add rax,0xffffffff850f0000
 544:	0a 00                	or     al,BYTE PTR [rax]
 546:	00 11                	add    BYTE PTR [rcx],dl
 548:	aa                   	stos   BYTE PTR es:[rdi],al
 549:	00 00                	add    BYTE PTR [rax],al
 54b:	00 00                	add    BYTE PTR [rax],al
 54d:	14 89                	adc    al,0x89
 54f:	00 00                	add    BYTE PTR [rax],al
 551:	00 01                	add    BYTE PTR [rcx],al
 553:	9a                   	(bad)  
 554:	01 ee                	add    esi,ebp
 556:	0c 00                	or     al,0x0
 558:	00 ce                	add    dh,cl
 55a:	00 00                	add    BYTE PTR [rax],al
 55c:	00 65 05             	add    BYTE PTR [rbp+0x5],ah
 55f:	00 00                	add    BYTE PTR [rax],al
 561:	75 05                	jne    568 <_init-0x3ffe88>
 563:	00 00                	add    BYTE PTR [rax],al
 565:	0f 67 0a             	packuswb mm1,QWORD PTR [rdx]
 568:	00 00                	add    BYTE PTR [rax],al
 56a:	11 ce                	adc    esi,ecx
 56c:	00 00                	add    BYTE PTR [rax],al
 56e:	00 11                	add    BYTE PTR [rcx],dl
 570:	aa                   	stos   BYTE PTR es:[rdi],al
 571:	00 00                	add    BYTE PTR [rax],al
 573:	00 00                	add    BYTE PTR [rax],al
 575:	14 89                	adc    al,0x89
 577:	00 00                	add    BYTE PTR [rax],al
 579:	00 01                	add    BYTE PTR [rcx],al
 57b:	a2 01 22 0a 00 00 ce 	movabs ds:0xce00000a2201,al
 582:	00 00 
 584:	00 8d 05 00 00 9d    	add    BYTE PTR [rbp-0x62fffffb],cl
 58a:	05 00 00 0f 79       	add    eax,0x790f0000
 58f:	0a 00                	or     al,BYTE PTR [rax]
 591:	00 11                	add    BYTE PTR [rcx],dl
 593:	ce                   	(bad)  
 594:	00 00                	add    BYTE PTR [rax],al
 596:	00 11                	add    BYTE PTR [rcx],dl
 598:	aa                   	stos   BYTE PTR es:[rdi],al
 599:	00 00                	add    BYTE PTR [rax],al
 59b:	00 00                	add    BYTE PTR [rax],al
 59d:	14 21                	adc    al,0x21
 59f:	0d 00 00 01 a9       	or     eax,0xa9010000
 5a4:	01 03                	add    DWORD PTR [rbx],eax
 5a6:	02 00                	add    al,BYTE PTR [rax]
 5a8:	00 54 0a 00          	add    BYTE PTR [rdx+rcx*1+0x0],dl
 5ac:	00 b5 05 00 00 cf    	add    BYTE PTR [rbp-0x30fffffb],dh
 5b2:	05 00 00 0f 67       	add    eax,0x670f0000
 5b7:	0a 00                	or     al,BYTE PTR [rax]
 5b9:	00 11                	add    BYTE PTR [rcx],dl
 5bb:	8b 0a                	mov    ecx,DWORD PTR [rdx]
 5bd:	00 00                	add    BYTE PTR [rax],al
 5bf:	11 ce                	adc    esi,ecx
 5c1:	00 00                	add    BYTE PTR [rax],al
 5c3:	00 11                	add    BYTE PTR [rcx],dl
 5c5:	aa                   	stos   BYTE PTR es:[rdi],al
 5c6:	00 00                	add    BYTE PTR [rax],al
 5c8:	00 11                	add    BYTE PTR [rcx],dl
 5ca:	aa                   	stos   BYTE PTR es:[rdi],al
 5cb:	00 00                	add    BYTE PTR [rax],al
 5cd:	00 00                	add    BYTE PTR [rax],al
 5cf:	14 21                	adc    al,0x21
 5d1:	0d 00 00 01 b6       	or     eax,0xb6010000
 5d6:	01 31                	add    DWORD PTR [rcx],esi
 5d8:	07                   	(bad)  
 5d9:	00 00                	add    BYTE PTR [rax],al
 5db:	54                   	push   rsp
 5dc:	0a 00                	or     al,BYTE PTR [rax]
 5de:	00 e7                	add    bh,ah
 5e0:	05 00 00 01 06       	add    eax,0x6010000
 5e5:	00 00                	add    BYTE PTR [rax],al
 5e7:	0f 79 0a             	vmwrite rcx,QWORD PTR [rdx]
 5ea:	00 00                	add    BYTE PTR [rax],al
 5ec:	11 8b 0a 00 00 11    	adc    DWORD PTR [rbx+0x1100000a],ecx
 5f2:	ce                   	(bad)  
 5f3:	00 00                	add    BYTE PTR [rax],al
 5f5:	00 11                	add    BYTE PTR [rcx],dl
 5f7:	aa                   	stos   BYTE PTR es:[rdi],al
 5f8:	00 00                	add    BYTE PTR [rax],al
 5fa:	00 11                	add    BYTE PTR [rcx],dl
 5fc:	aa                   	stos   BYTE PTR es:[rdi],al
 5fd:	00 00                	add    BYTE PTR [rax],al
 5ff:	00 00                	add    BYTE PTR [rax],al
 601:	14 21                	adc    al,0x21
 603:	0d 00 00 01 c4       	or     eax,0xc4010000
 608:	01 84 05 00 00 54 0a 	add    DWORD PTR [rbp+rax*1+0xa540000],eax
 60f:	00 00                	add    BYTE PTR [rax],al
 611:	19 06                	sbb    DWORD PTR [rsi],eax
 613:	00 00                	add    BYTE PTR [rax],al
 615:	2e 06                	cs (bad) 
 617:	00 00                	add    BYTE PTR [rax],al
 619:	0f 67 0a             	packuswb mm1,QWORD PTR [rdx]
 61c:	00 00                	add    BYTE PTR [rax],al
 61e:	11 8b 0a 00 00 11    	adc    DWORD PTR [rbx+0x1100000a],ecx
 624:	ce                   	(bad)  
 625:	00 00                	add    BYTE PTR [rax],al
 627:	00 11                	add    BYTE PTR [rcx],dl
 629:	aa                   	stos   BYTE PTR es:[rdi],al
 62a:	00 00                	add    BYTE PTR [rax],al
 62c:	00 00                	add    BYTE PTR [rax],al
 62e:	14 21                	adc    al,0x21
 630:	0d 00 00 01 cc       	or     eax,0xcc010000
 635:	01 f7                	add    edi,esi
 637:	05 00 00 54 0a       	add    eax,0xa540000
 63c:	00 00                	add    BYTE PTR [rax],al
 63e:	46 06                	rex.RX (bad) 
 640:	00 00                	add    BYTE PTR [rax],al
 642:	5b                   	pop    rbx
 643:	06                   	(bad)  
 644:	00 00                	add    BYTE PTR [rax],al
 646:	0f 79 0a             	vmwrite rcx,QWORD PTR [rdx]
 649:	00 00                	add    BYTE PTR [rax],al
 64b:	11 8b 0a 00 00 11    	adc    DWORD PTR [rbx+0x1100000a],ecx
 651:	ce                   	(bad)  
 652:	00 00                	add    BYTE PTR [rax],al
 654:	00 11                	add    BYTE PTR [rcx],dl
 656:	aa                   	stos   BYTE PTR es:[rdi],al
 657:	00 00                	add    BYTE PTR [rax],al
 659:	00 00                	add    BYTE PTR [rax],al
 65b:	14 c3                	adc    al,0xc3
 65d:	04 00                	add    al,0x0
 65f:	00 01                	add    BYTE PTR [rcx],al
 661:	d4                   	(bad)  
 662:	01 79 01             	add    DWORD PTR [rcx+0x1],edi
 665:	00 00                	add    BYTE PTR [rax],al
 667:	54                   	push   rsp
 668:	0a 00                	or     al,BYTE PTR [rax]
 66a:	00 73 06             	add    BYTE PTR [rbx+0x6],dh
 66d:	00 00                	add    BYTE PTR [rax],al
 66f:	8d 06                	lea    eax,[rsi]
 671:	00 00                	add    BYTE PTR [rax],al
 673:	0f 67 0a             	packuswb mm1,QWORD PTR [rdx]
 676:	00 00                	add    BYTE PTR [rax],al
 678:	11 8b 0a 00 00 11    	adc    DWORD PTR [rbx+0x1100000a],ecx
 67e:	ce                   	(bad)  
 67f:	00 00                	add    BYTE PTR [rax],al
 681:	00 11                	add    BYTE PTR [rcx],dl
 683:	aa                   	stos   BYTE PTR es:[rdi],al
 684:	00 00                	add    BYTE PTR [rax],al
 686:	00 11                	add    BYTE PTR [rcx],dl
 688:	aa                   	stos   BYTE PTR es:[rdi],al
 689:	00 00                	add    BYTE PTR [rax],al
 68b:	00 00                	add    BYTE PTR [rax],al
 68d:	14 c3                	adc    al,0xc3
 68f:	04 00                	add    al,0x0
 691:	00 01                	add    BYTE PTR [rcx],al
 693:	e1 01                	loope  696 <_init-0x3ffd5a>
 695:	b1 07                	mov    cl,0x7
 697:	00 00                	add    BYTE PTR [rax],al
 699:	54                   	push   rsp
 69a:	0a 00                	or     al,BYTE PTR [rax]
 69c:	00 a5 06 00 00 bf    	add    BYTE PTR [rbp-0x40fffffa],ah
 6a2:	06                   	(bad)  
 6a3:	00 00                	add    BYTE PTR [rax],al
 6a5:	0f 79 0a             	vmwrite rcx,QWORD PTR [rdx]
 6a8:	00 00                	add    BYTE PTR [rax],al
 6aa:	11 8b 0a 00 00 11    	adc    DWORD PTR [rbx+0x1100000a],ecx
 6b0:	ce                   	(bad)  
 6b1:	00 00                	add    BYTE PTR [rax],al
 6b3:	00 11                	add    BYTE PTR [rcx],dl
 6b5:	aa                   	stos   BYTE PTR es:[rdi],al
 6b6:	00 00                	add    BYTE PTR [rax],al
 6b8:	00 11                	add    BYTE PTR [rcx],dl
 6ba:	aa                   	stos   BYTE PTR es:[rdi],al
 6bb:	00 00                	add    BYTE PTR [rax],al
 6bd:	00 00                	add    BYTE PTR [rax],al
 6bf:	14 c3                	adc    al,0xc3
 6c1:	04 00                	add    al,0x0
 6c3:	00 01                	add    BYTE PTR [rcx],al
 6c5:	f0 01 db             	lock add ebx,ebx
 6c8:	04 00                	add    al,0x0
 6ca:	00 54 0a 00          	add    BYTE PTR [rdx+rcx*1+0x0],dl
 6ce:	00 d7                	add    bh,dl
 6d0:	06                   	(bad)  
 6d1:	00 00                	add    BYTE PTR [rax],al
 6d3:	ec                   	in     al,dx
 6d4:	06                   	(bad)  
 6d5:	00 00                	add    BYTE PTR [rax],al
 6d7:	0f 67 0a             	packuswb mm1,QWORD PTR [rdx]
 6da:	00 00                	add    BYTE PTR [rax],al
 6dc:	11 8b 0a 00 00 11    	adc    DWORD PTR [rbx+0x1100000a],ecx
 6e2:	ce                   	(bad)  
 6e3:	00 00                	add    BYTE PTR [rax],al
 6e5:	00 11                	add    BYTE PTR [rcx],dl
 6e7:	aa                   	stos   BYTE PTR es:[rdi],al
 6e8:	00 00                	add    BYTE PTR [rax],al
 6ea:	00 00                	add    BYTE PTR [rax],al
 6ec:	14 c3                	adc    al,0xc3
 6ee:	04 00                	add    al,0x0
 6f0:	00 01                	add    BYTE PTR [rcx],al
 6f2:	f8                   	clc    
 6f3:	01 eb                	add    ebx,ebp
 6f5:	06                   	(bad)  
 6f6:	00 00                	add    BYTE PTR [rax],al
 6f8:	54                   	push   rsp
 6f9:	0a 00                	or     al,BYTE PTR [rax]
 6fb:	00 04 07             	add    BYTE PTR [rdi+rax*1],al
 6fe:	00 00                	add    BYTE PTR [rax],al
 700:	19 07                	sbb    DWORD PTR [rdi],eax
 702:	00 00                	add    BYTE PTR [rax],al
 704:	0f 79 0a             	vmwrite rcx,QWORD PTR [rdx]
 707:	00 00                	add    BYTE PTR [rax],al
 709:	11 8b 0a 00 00 11    	adc    DWORD PTR [rbx+0x1100000a],ecx
 70f:	ce                   	(bad)  
 710:	00 00                	add    BYTE PTR [rax],al
 712:	00 11                	add    BYTE PTR [rcx],dl
 714:	aa                   	stos   BYTE PTR es:[rdi],al
 715:	00 00                	add    BYTE PTR [rax],al
 717:	00 00                	add    BYTE PTR [rax],al
 719:	14 ff                	adc    al,0xff
 71b:	07                   	(bad)  
 71c:	00 00                	add    BYTE PTR [rax],al
 71e:	01 00                	add    DWORD PTR [rax],eax
 720:	02 5d 03             	add    bl,BYTE PTR [rbp+0x3]
 723:	00 00                	add    BYTE PTR [rax],al
 725:	ce                   	(bad)  
 726:	00 00                	add    BYTE PTR [rax],al
 728:	00 31                	add    BYTE PTR [rcx],dh
 72a:	07                   	(bad)  
 72b:	00 00                	add    BYTE PTR [rax],al
 72d:	41 07                	rex.B (bad) 
 72f:	00 00                	add    BYTE PTR [rax],al
 731:	0f 67 0a             	packuswb mm1,QWORD PTR [rdx]
 734:	00 00                	add    BYTE PTR [rax],al
 736:	11 ce                	adc    esi,ecx
 738:	00 00                	add    BYTE PTR [rax],al
 73a:	00 11                	add    BYTE PTR [rcx],dl
 73c:	aa                   	stos   BYTE PTR es:[rdi],al
 73d:	00 00                	add    BYTE PTR [rax],al
 73f:	00 00                	add    BYTE PTR [rax],al
 741:	14 ff                	adc    al,0xff
 743:	07                   	(bad)  
 744:	00 00                	add    BYTE PTR [rax],al
 746:	01 05 02 2d 08 00    	add    DWORD PTR [rip+0x82d02],eax        # 8344e <_init-0x37cfa2>
 74c:	00 ce                	add    dh,cl
 74e:	00 00                	add    BYTE PTR [rax],al
 750:	00 59 07             	add    BYTE PTR [rcx+0x7],bl
 753:	00 00                	add    BYTE PTR [rax],al
 755:	69 07 00 00 0f 79    	imul   eax,DWORD PTR [rdi],0x790f0000
 75b:	0a 00                	or     al,BYTE PTR [rax]
 75d:	00 11                	add    BYTE PTR [rcx],dl
 75f:	ce                   	(bad)  
 760:	00 00                	add    BYTE PTR [rax],al
 762:	00 11                	add    BYTE PTR [rcx],dl
 764:	aa                   	stos   BYTE PTR es:[rdi],al
 765:	00 00                	add    BYTE PTR [rax],al
 767:	00 00                	add    BYTE PTR [rax],al
 769:	14 78                	adc    al,0x78
 76b:	07                   	(bad)  
 76c:	00 00                	add    BYTE PTR [rax],al
 76e:	01 0a                	add    DWORD PTR [rdx],ecx
 770:	02 f7                	add    dh,bh
 772:	03 00                	add    eax,DWORD PTR [rax]
 774:	00 ce                	add    dh,cl
 776:	00 00                	add    BYTE PTR [rax],al
 778:	00 81 07 00 00 91    	add    BYTE PTR [rcx-0x6efffff9],al
 77e:	07                   	(bad)  
 77f:	00 00                	add    BYTE PTR [rax],al
 781:	0f 67 0a             	packuswb mm1,QWORD PTR [rdx]
 784:	00 00                	add    BYTE PTR [rax],al
 786:	11 ce                	adc    esi,ecx
 788:	00 00                	add    BYTE PTR [rax],al
 78a:	00 11                	add    BYTE PTR [rcx],dl
 78c:	aa                   	stos   BYTE PTR es:[rdi],al
 78d:	00 00                	add    BYTE PTR [rax],al
 78f:	00 00                	add    BYTE PTR [rax],al
 791:	14 78                	adc    al,0x78
 793:	07                   	(bad)  
 794:	00 00                	add    BYTE PTR [rax],al
 796:	01 0f                	add    DWORD PTR [rdi],ecx
 798:	02 b7 00 00 00 ce    	add    dh,BYTE PTR [rdi-0x32000000]
 79e:	00 00                	add    BYTE PTR [rax],al
 7a0:	00 a9 07 00 00 b9    	add    BYTE PTR [rcx-0x46fffff9],ch
 7a6:	07                   	(bad)  
 7a7:	00 00                	add    BYTE PTR [rax],al
 7a9:	0f 79 0a             	vmwrite rcx,QWORD PTR [rdx]
 7ac:	00 00                	add    BYTE PTR [rax],al
 7ae:	11 ce                	adc    esi,ecx
 7b0:	00 00                	add    BYTE PTR [rax],al
 7b2:	00 11                	add    BYTE PTR [rcx],dl
 7b4:	aa                   	stos   BYTE PTR es:[rdi],al
 7b5:	00 00                	add    BYTE PTR [rax],al
 7b7:	00 00                	add    BYTE PTR [rax],al
 7b9:	14 eb                	adc    al,0xeb
 7bb:	0b 00                	or     eax,DWORD PTR [rax]
 7bd:	00 01                	add    BYTE PTR [rcx],al
 7bf:	14 02                	adc    al,0x2
 7c1:	58                   	pop    rax
 7c2:	0d 00 00 ce 00       	or     eax,0xce0000
 7c7:	00 00                	add    BYTE PTR [rax],al
 7c9:	d1 07                	rol    DWORD PTR [rdi],1
 7cb:	00 00                	add    BYTE PTR [rax],al
 7cd:	e1 07                	loope  7d6 <_init-0x3ffc1a>
 7cf:	00 00                	add    BYTE PTR [rax],al
 7d1:	0f 67 0a             	packuswb mm1,QWORD PTR [rdx]
 7d4:	00 00                	add    BYTE PTR [rax],al
 7d6:	11 ce                	adc    esi,ecx
 7d8:	00 00                	add    BYTE PTR [rax],al
 7da:	00 11                	add    BYTE PTR [rcx],dl
 7dc:	aa                   	stos   BYTE PTR es:[rdi],al
 7dd:	00 00                	add    BYTE PTR [rax],al
 7df:	00 00                	add    BYTE PTR [rax],al
 7e1:	14 eb                	adc    al,0xeb
 7e3:	0b 00                	or     eax,DWORD PTR [rax]
 7e5:	00 01                	add    BYTE PTR [rcx],al
 7e7:	19 02                	sbb    DWORD PTR [rdx],eax
 7e9:	c2 03 00             	ret    0x3
 7ec:	00 ce                	add    dh,cl
 7ee:	00 00                	add    BYTE PTR [rax],al
 7f0:	00 f9                	add    cl,bh
 7f2:	07                   	(bad)  
 7f3:	00 00                	add    BYTE PTR [rax],al
 7f5:	09 08                	or     DWORD PTR [rax],ecx
 7f7:	00 00                	add    BYTE PTR [rax],al
 7f9:	0f 79 0a             	vmwrite rcx,QWORD PTR [rdx]
 7fc:	00 00                	add    BYTE PTR [rax],al
 7fe:	11 ce                	adc    esi,ecx
 800:	00 00                	add    BYTE PTR [rax],al
 802:	00 11                	add    BYTE PTR [rcx],dl
 804:	aa                   	stos   BYTE PTR es:[rdi],al
 805:	00 00                	add    BYTE PTR [rax],al
 807:	00 00                	add    BYTE PTR [rax],al
 809:	14 53                	adc    al,0x53
 80b:	01 00                	add    DWORD PTR [rax],eax
 80d:	00 01                	add    BYTE PTR [rcx],al
 80f:	1e                   	(bad)  
 810:	02 56 0b             	add    dl,BYTE PTR [rsi+0xb]
 813:	00 00                	add    BYTE PTR [rax],al
 815:	ce                   	(bad)  
 816:	00 00                	add    BYTE PTR [rax],al
 818:	00 21                	add    BYTE PTR [rcx],ah
 81a:	08 00                	or     BYTE PTR [rax],al
 81c:	00 31                	add    BYTE PTR [rcx],dh
 81e:	08 00                	or     BYTE PTR [rax],al
 820:	00 0f                	add    BYTE PTR [rdi],cl
 822:	67 0a 00             	or     al,BYTE PTR [eax]
 825:	00 11                	add    BYTE PTR [rcx],dl
 827:	ce                   	(bad)  
 828:	00 00                	add    BYTE PTR [rax],al
 82a:	00 11                	add    BYTE PTR [rcx],dl
 82c:	aa                   	stos   BYTE PTR es:[rdi],al
 82d:	00 00                	add    BYTE PTR [rax],al
 82f:	00 00                	add    BYTE PTR [rax],al
 831:	14 53                	adc    al,0x53
 833:	01 00                	add    DWORD PTR [rax],eax
 835:	00 01                	add    BYTE PTR [rcx],al
 837:	23 02                	and    eax,DWORD PTR [rdx]
 839:	ee                   	out    dx,al
 83a:	09 00                	or     DWORD PTR [rax],eax
 83c:	00 ce                	add    dh,cl
 83e:	00 00                	add    BYTE PTR [rax],al
 840:	00 49 08             	add    BYTE PTR [rcx+0x8],cl
 843:	00 00                	add    BYTE PTR [rax],al
 845:	59                   	pop    rcx
 846:	08 00                	or     BYTE PTR [rax],al
 848:	00 0f                	add    BYTE PTR [rdi],cl
 84a:	79 0a                	jns    856 <_init-0x3ffb9a>
 84c:	00 00                	add    BYTE PTR [rax],al
 84e:	11 ce                	adc    esi,ecx
 850:	00 00                	add    BYTE PTR [rax],al
 852:	00 11                	add    BYTE PTR [rcx],dl
 854:	aa                   	stos   BYTE PTR es:[rdi],al
 855:	00 00                	add    BYTE PTR [rax],al
 857:	00 00                	add    BYTE PTR [rax],al
 859:	14 f5                	adc    al,0xf5
 85b:	0b 00                	or     eax,DWORD PTR [rax]
 85d:	00 01                	add    BYTE PTR [rcx],al
 85f:	28 02                	sub    BYTE PTR [rdx],al
 861:	70 0c                	jo     86f <_init-0x3ffb81>
 863:	00 00                	add    BYTE PTR [rax],al
 865:	ce                   	(bad)  
 866:	00 00                	add    BYTE PTR [rax],al
 868:	00 71 08             	add    BYTE PTR [rcx+0x8],dh
 86b:	00 00                	add    BYTE PTR [rax],al
 86d:	81 08 00 00 0f 67    	or     DWORD PTR [rax],0x670f0000
 873:	0a 00                	or     al,BYTE PTR [rax]
 875:	00 11                	add    BYTE PTR [rcx],dl
 877:	ce                   	(bad)  
 878:	00 00                	add    BYTE PTR [rax],al
 87a:	00 11                	add    BYTE PTR [rcx],dl
 87c:	aa                   	stos   BYTE PTR es:[rdi],al
 87d:	00 00                	add    BYTE PTR [rax],al
 87f:	00 00                	add    BYTE PTR [rax],al
 881:	14 f5                	adc    al,0xf5
 883:	0b 00                	or     eax,DWORD PTR [rax]
 885:	00 01                	add    BYTE PTR [rcx],al
 887:	2d 02 7e 08 00       	sub    eax,0x87e02
 88c:	00 ce                	add    dh,cl
 88e:	00 00                	add    BYTE PTR [rax],al
 890:	00 99 08 00 00 a9    	add    BYTE PTR [rcx-0x56fffff8],bl
 896:	08 00                	or     BYTE PTR [rax],al
 898:	00 0f                	add    BYTE PTR [rdi],cl
 89a:	79 0a                	jns    8a6 <_init-0x3ffb4a>
 89c:	00 00                	add    BYTE PTR [rax],al
 89e:	11 ce                	adc    esi,ecx
 8a0:	00 00                	add    BYTE PTR [rax],al
 8a2:	00 11                	add    BYTE PTR [rcx],dl
 8a4:	aa                   	stos   BYTE PTR es:[rdi],al
 8a5:	00 00                	add    BYTE PTR [rax],al
 8a7:	00 00                	add    BYTE PTR [rax],al
 8a9:	15 1b 0c 00 00       	adc    eax,0xc1b
 8ae:	2a 0a                	sub    cl,BYTE PTR [rdx]
 8b0:	00 00                	add    BYTE PTR [rax],al
 8b2:	00 16                	add    BYTE PTR [rsi],dl
 8b4:	b5 00                	mov    ch,0x0
 8b6:	00 00                	add    BYTE PTR [rax],al
 8b8:	17                   	(bad)  
 8b9:	b5 00                	mov    ch,0x0
 8bb:	00 00                	add    BYTE PTR [rax],al
 8bd:	16                   	(bad)  
 8be:	b8 08 00 00 18       	mov    eax,0x18000008
 8c3:	00 00                	add    BYTE PTR [rax],al
 8c5:	00 00                	add    BYTE PTR [rax],al
 8c7:	04 02                	add    al,0x2
 8c9:	5d                   	pop    rbp
 8ca:	02 ab 09 00 00 19    	add    ch,BYTE PTR [rbx+0x19000009]
 8d0:	02 5d 02             	add    bl,BYTE PTR [rbp+0x2]
 8d3:	bd 01 00 00 19       	mov    ebp,0x19000001
 8d8:	02 5d 02             	add    bl,BYTE PTR [rbp+0x2]
 8db:	fe 01                	inc    BYTE PTR [rcx]
 8dd:	00 00                	add    BYTE PTR [rax],al
 8df:	1a b5 00 00 00 00    	sbb    dh,BYTE PTR [rbp+0x0]
 8e5:	1b a7 00 00 00 02    	sbb    esp,DWORD PTR [rdi+0x2000000]
 8eb:	5f                   	pop    rdi
 8ec:	02 2a                	add    ch,BYTE PTR [rdx]
 8ee:	0a 00                	or     al,BYTE PTR [rax]
 8f0:	00 13                	add    BYTE PTR [rbx],dl
 8f2:	d5                   	(bad)  
 8f3:	0d 00 00 02 62       	or     eax,0x62020000
 8f8:	02 8c 0d 00 00 05 09 	add    cl,BYTE PTR [rbp+rcx*1+0x9050000]
 8ff:	00 00                	add    BYTE PTR [rax],al
 901:	0b 09                	or     ecx,DWORD PTR [rcx]
 903:	00 00                	add    BYTE PTR [rax],al
 905:	0f 91 0a             	setno  BYTE PTR [rdx]
 908:	00 00                	add    BYTE PTR [rax],al
 90a:	00 13                	add    BYTE PTR [rbx],dl
 90c:	d4                   	(bad)  
 90d:	0d 00 00 02 63       	or     eax,0x63020000
 912:	02 5c 0c 00          	add    bl,BYTE PTR [rsp+rcx*1+0x0]
 916:	00 1f                	add    BYTE PTR [rdi],bl
 918:	09 00                	or     DWORD PTR [rax],eax
 91a:	00 2a                	add    BYTE PTR [rdx],ch
 91c:	09 00                	or     DWORD PTR [rax],eax
 91e:	00 0f                	add    BYTE PTR [rdi],cl
 920:	91                   	xchg   ecx,eax
 921:	0a 00                	or     al,BYTE PTR [rax]
 923:	00 0f                	add    BYTE PTR [rdi],cl
 925:	2a 0a                	sub    cl,BYTE PTR [rdx]
 927:	00 00                	add    BYTE PTR [rax],al
 929:	00 1c d5 0d 00 00 02 	add    BYTE PTR [rdx*8+0x200000d],bl
 930:	64 02 16             	add    dl,BYTE PTR fs:[rsi]
 933:	0b 00                	or     eax,DWORD PTR [rax]
 935:	00 3e                	add    BYTE PTR [rsi],bh
 937:	09 00                	or     DWORD PTR [rax],eax
 939:	00 49 09             	add    BYTE PTR [rcx+0x9],cl
 93c:	00 00                	add    BYTE PTR [rax],al
 93e:	0f 91 0a             	setno  BYTE PTR [rdx]
 941:	00 00                	add    BYTE PTR [rax],al
 943:	11 97 0a 00 00 00    	adc    DWORD PTR [rdi+0xa],edx
 949:	1d c8 09 00 00       	sbb    eax,0x9c8
 94e:	02 65 02             	add    ah,BYTE PTR [rbp+0x2]
 951:	eb 01                	jmp    954 <_init-0x3ffa9c>
 953:	00 00                	add    BYTE PTR [rax],al
 955:	9d                   	popf   
 956:	0a 00                	or     al,BYTE PTR [rax]
 958:	00 61 09             	add    BYTE PTR [rcx+0x9],ah
 95b:	00 00                	add    BYTE PTR [rax],al
 95d:	6c                   	ins    BYTE PTR es:[rdi],dx
 95e:	09 00                	or     DWORD PTR [rax],eax
 960:	00 0f                	add    BYTE PTR [rdi],cl
 962:	91                   	xchg   ecx,eax
 963:	0a 00                	or     al,BYTE PTR [rax]
 965:	00 11                	add    BYTE PTR [rcx],dl
 967:	97                   	xchg   edi,eax
 968:	0a 00                	or     al,BYTE PTR [rax]
 96a:	00 00                	add    BYTE PTR [rax],al
 96c:	1d c8 09 00 00       	sbb    eax,0x9c8
 971:	02 66 02             	add    ah,BYTE PTR [rsi+0x2]
 974:	3c 05                	cmp    al,0x5
 976:	00 00                	add    BYTE PTR [rax],al
 978:	9d                   	popf   
 979:	0a 00                	or     al,BYTE PTR [rax]
 97b:	00 84 09 00 00 8f 09 	add    BYTE PTR [rcx+rcx*1+0x98f0000],al
 982:	00 00                	add    BYTE PTR [rax],al
 984:	0f a3 0a             	bt     DWORD PTR [rdx],ecx
 987:	00 00                	add    BYTE PTR [rax],al
 989:	11 97 0a 00 00 00    	adc    DWORD PTR [rdi+0xa],edx
 98f:	1e                   	(bad)  
 990:	d5                   	(bad)  
 991:	0d 00 00 02 68       	or     eax,0x68020000
 996:	02 37                	add    dh,BYTE PTR [rdi]
 998:	0d 00 00 9f 09       	or     eax,0x99f0000
 99d:	00 00                	add    BYTE PTR [rax],al
 99f:	0f 91 0a             	setno  BYTE PTR [rdx]
 9a2:	00 00                	add    BYTE PTR [rax],al
 9a4:	11 e5                	adc    ebp,esp
 9a6:	08 00                	or     BYTE PTR [rax],al
 9a8:	00 00                	add    BYTE PTR [rax],al
 9aa:	00 16                	add    BYTE PTR [rsi],dl
 9ac:	c2 08 00             	ret    0x8
 9af:	00 17                	add    BYTE PTR [rdi],dl
 9b1:	c2 08 00             	ret    0x8
 9b4:	00 1f                	add    BYTE PTR [rdi],bl
 9b6:	7f 09                	jg     9c1 <_init-0x3ffa2f>
 9b8:	00 00                	add    BYTE PTR [rax],al
 9ba:	01 50 73             	add    DWORD PTR [rax+0x73],edx
 9bd:	0a 00                	or     al,BYTE PTR [rax]
 9bf:	00 aa 00 00 00 d3    	add    BYTE PTR [rdx-0x2d000000],ch
 9c5:	09 00                	or     DWORD PTR [rax],eax
 9c7:	00 11                	add    BYTE PTR [rcx],dl
 9c9:	aa                   	stos   BYTE PTR es:[rdi],al
 9ca:	00 00                	add    BYTE PTR [rax],al
 9cc:	00 11                	add    BYTE PTR [rcx],dl
 9ce:	77 00                	ja     9d0 <_init-0x3ffa20>
 9d0:	00 00                	add    BYTE PTR [rax],al
 9d2:	00 1f                	add    BYTE PTR [rdi],bl
 9d4:	09 08                	or     DWORD PTR [rax],ecx
 9d6:	00 00                	add    BYTE PTR [rax],al
 9d8:	01 57 a0             	add    DWORD PTR [rdi-0x60],edx
 9db:	0d 00 00 aa 00       	or     eax,0xaa0000
 9e0:	00 00                	add    BYTE PTR [rax],al
 9e2:	ec                   	in     al,dx
 9e3:	09 00                	or     DWORD PTR [rax],eax
 9e5:	00 11                	add    BYTE PTR [rcx],dl
 9e7:	aa                   	stos   BYTE PTR es:[rdi],al
 9e8:	00 00                	add    BYTE PTR [rax],al
 9ea:	00 00                	add    BYTE PTR [rax],al
 9ec:	20 11                	and    BYTE PTR [rcx],dl
 9ee:	01 00                	add    DWORD PTR [rax],eax
 9f0:	00 01                	add    BYTE PTR [rcx],al
 9f2:	5e                   	pop    rsi
 9f3:	a5                   	movs   DWORD PTR es:[rdi],DWORD PTR ds:[rsi]
 9f4:	0a 00                	or     al,BYTE PTR [rax]
 9f6:	00 aa 00 00 00 11    	add    BYTE PTR [rdx+0x11000000],ch
 9fc:	aa                   	stos   BYTE PTR es:[rdi],al
 9fd:	00 00                	add    BYTE PTR [rax],al
 9ff:	00 00                	add    BYTE PTR [rax],al
 a01:	00 21                	add    BYTE PTR [rcx],ah
 a03:	dc 0d 00 00 04 dd    	fmul   QWORD PTR [rip+0xffffffffdd040000]        # ffffffffdd040a09 <_end+0xffffffffdca3f9c9>
 a09:	1c 0a                	sbb    al,0xa
 a0b:	00 00                	add    BYTE PTR [rax],al
 a0d:	03 ec                	add    ebp,esp
 a0f:	00 00                	add    BYTE PTR [rax],al
 a11:	00 04 de             	add    BYTE PTR [rsi+rbx*8],al
 a14:	04 04                	add    al,0x4
 a16:	de 0d 0a 00 00 00    	fimul  WORD PTR [rip+0xa]        # a26 <_init-0x3ff9ca>
 a1c:	22 01                	and    al,BYTE PTR [rcx]
 a1e:	06                   	(bad)  
 a1f:	bc 09 00 00 22       	mov    esp,0x22000009
 a24:	02 05 b0 06 00 00    	add    al,BYTE PTR [rip+0x6b0]        # 10da <_init-0x3ff316>
 a2a:	23 04 05 69 6e 74 00 	and    eax,DWORD PTR [rax*1+0x746e69]
 a31:	22 08                	and    cl,BYTE PTR [rax]
 a33:	05 e2 01 00 00       	add    eax,0x1e2
 a38:	22 01                	and    al,BYTE PTR [rcx]
 a3a:	08 ba 09 00 00 22    	or     BYTE PTR [rdx+0x22000009],bh
 a40:	02 07                	add    al,BYTE PTR [rdi]
 a42:	e4 05                	in     al,0x5
 a44:	00 00                	add    BYTE PTR [rax],al
 a46:	22 04 07             	and    al,BYTE PTR [rdi+rax*1]
 a49:	46 01 00             	rex.RX add DWORD PTR [rax],r8d
 a4c:	00 22                	add    BYTE PTR [rdx],ah
 a4e:	08 07                	or     BYTE PTR [rdi],al
 a50:	41 01 00             	add    DWORD PTR [r8],eax
 a53:	00 22                	add    BYTE PTR [rdx],ah
 a55:	01 02                	add    DWORD PTR [rdx],eax
 a57:	82                   	(bad)  
 a58:	06                   	(bad)  
 a59:	00 00                	add    BYTE PTR [rax],al
 a5b:	16                   	(bad)  
 a5c:	2a 0a                	sub    cl,BYTE PTR [rdx]
 a5e:	00 00                	add    BYTE PTR [rax],al
 a60:	22 01                	and    al,BYTE PTR [rcx]
 a62:	06                   	(bad)  
 a63:	c3                   	ret    
 a64:	09 00                	or     DWORD PTR [rax],eax
 a66:	00 24 08             	add    BYTE PTR [rax+rcx*1],ah
 a69:	b5 00                	mov    ch,0x0
 a6b:	00 00                	add    BYTE PTR [rax],al
 a6d:	25 08 b3 08 00       	and    eax,0x8b308
 a72:	00 25 08 b5 00 00    	add    BYTE PTR [rip+0xb508],ah        # bf80 <_init-0x3f4470>
 a78:	00 24 08             	add    BYTE PTR [rax+rcx*1],ah
 a7b:	b8 08 00 00 24       	mov    eax,0x24000008
 a80:	08 b3 08 00 00 24    	or     BYTE PTR [rbx+0x24000008],dh
 a86:	08 bd 08 00 00 25    	or     BYTE PTR [rbp+0x25000008],bh
 a8c:	08 ce                	or     dh,cl
 a8e:	00 00                	add    BYTE PTR [rax],al
 a90:	00 24 08             	add    BYTE PTR [rax+rcx*1],ah
 a93:	c2 08 00             	ret    0x8
 a96:	00 25 08 ab 09 00    	add    BYTE PTR [rip+0x9ab08],ah        # 9b5a4 <_init-0x364e4c>
 a9c:	00 25 08 c2 08 00    	add    BYTE PTR [rip+0x8c208],ah        # 8ccaa <_init-0x373746>
 aa2:	00 24 08             	add    BYTE PTR [rax+rcx*1],ah
 aa5:	b0 09                	mov    al,0x9
 aa7:	00 00                	add    BYTE PTR [rax],al
 aa9:	22 08                	and    cl,BYTE PTR [rax]
 aab:	05 dd 01 00 00       	add    eax,0x1dd
 ab0:	22 08                	and    cl,BYTE PTR [rax]
 ab2:	07                   	(bad)  
 ab3:	3c 01                	cmp    al,0x1
 ab5:	00 00                	add    BYTE PTR [rax],al
 ab7:	22 04 05 5e 06 00 00 	and    al,BYTE PTR [rax*1+0x65e]
 abe:	22 02                	and    al,BYTE PTR [rdx]
 ac0:	10 7d 02             	adc    BYTE PTR [rbp+0x2],bh
 ac3:	00 00                	add    BYTE PTR [rax],al
 ac5:	22 04 10             	and    al,BYTE PTR [rax+rdx*1]
 ac8:	d3 0a                	ror    DWORD PTR [rdx],cl
 aca:	00 00                	add    BYTE PTR [rax],al
 acc:	26 5b                	es pop rbx
 ace:	06                   	(bad)  
 acf:	00 00                	add    BYTE PTR [rax],al
 ad1:	03 da                	add    ebx,edx
 ad3:	0a 00                	or     al,BYTE PTR [rax]
 ad5:	00 2c 0b             	add    BYTE PTR [rbx+rcx*1],ch
 ad8:	00 00                	add    BYTE PTR [rax],al
 ada:	27                   	(bad)  
 adb:	3b 03                	cmp    eax,DWORD PTR [rbx]
 add:	00 00                	add    BYTE PTR [rax],al
 adf:	2c 0b                	sub    al,0xb
 ae1:	00 00                	add    BYTE PTR [rax],al
 ae3:	28 0c 0b             	sub    BYTE PTR [rbx+rcx*1],cl
 ae6:	00 00                	add    BYTE PTR [rax],al
 ae8:	01 d4                	add    esp,edx
 aea:	01 31                	add    DWORD PTR [rcx],esi
 aec:	0b 00                	or     eax,DWORD PTR [rax]
 aee:	00 28                	add    BYTE PTR [rax],ch
 af0:	11 0b                	adc    DWORD PTR [rbx],ecx
 af2:	00 00                	add    BYTE PTR [rax],al
 af4:	01 d4                	add    esp,edx
 af6:	01 ce                	add    esi,ecx
 af8:	00 00                	add    BYTE PTR [rax],al
 afa:	00 28                	add    BYTE PTR [rax],ch
 afc:	49 02 00             	rex.WB add al,BYTE PTR [r8]
 aff:	00 01                	add    BYTE PTR [rcx],al
 b01:	d5                   	(bad)  
 b02:	01 aa 00 00 00 28    	add    DWORD PTR [rdx+0x28000000],ebp
 b08:	4e 02 00             	rex.WRX add r8b,BYTE PTR [rax]
 b0b:	00 01                	add    BYTE PTR [rcx],al
 b0d:	d5                   	(bad)  
 b0e:	01 aa 00 00 00 29    	add    DWORD PTR [rdx+0x29000000],ebp
 b14:	57                   	push   rdi
 b15:	0c 00                	or     al,0x0
 b17:	00 01                	add    BYTE PTR [rcx],al
 b19:	d7                   	xlat   BYTE PTR ds:[rbx]
 b1a:	01 aa 00 00 00 29    	add    DWORD PTR [rdx+0x29000000],ebp
 b20:	52                   	push   rdx
 b21:	0c 00                	or     al,0x0
 b23:	00 01                	add    BYTE PTR [rcx],al
 b25:	d8 01                	fadd   DWORD PTR [rcx]
 b27:	aa                   	stos   BYTE PTR es:[rdi],al
 b28:	00 00                	add    BYTE PTR [rax],al
 b2a:	00 00                	add    BYTE PTR [rax],al
 b2c:	16                   	(bad)  
 b2d:	67 0a 00             	or     al,BYTE PTR [eax]
 b30:	00 16                	add    BYTE PTR [rsi],dl
 b32:	8b 0a                	mov    ecx,DWORD PTR [rdx]
 b34:	00 00                	add    BYTE PTR [rax],al
 b36:	26 07                	es (bad) 
 b38:	05 00 00 03 44       	add    eax,0x44030000
 b3d:	0b 00                	or     eax,DWORD PTR [rax]
 b3f:	00 66 0b             	add    BYTE PTR [rsi+0xb],ah
 b42:	00 00                	add    BYTE PTR [rax],al
 b44:	27                   	(bad)  
 b45:	3b 03                	cmp    eax,DWORD PTR [rbx]
 b47:	00 00                	add    BYTE PTR [rax],al
 b49:	66 0b 00             	or     ax,WORD PTR [rax]
 b4c:	00 2a                	add    BYTE PTR [rdx],ch
 b4e:	5f                   	pop    rdi
 b4f:	5f                   	pop    rdi
 b50:	6d                   	ins    DWORD PTR es:[rdi],dx
 b51:	00 01                	add    BYTE PTR [rcx],al
 b53:	86 01                	xchg   BYTE PTR [rcx],al
 b55:	aa                   	stos   BYTE PTR es:[rdi],al
 b56:	00 00                	add    BYTE PTR [rax],al
 b58:	00 2b                	add    BYTE PTR [rbx],ch
 b5a:	5f                   	pop    rdi
 b5b:	5f                   	pop    rdi
 b5c:	62                   	(bad)  
 b5d:	00 01                	add    BYTE PTR [rcx],al
 b5f:	88 01                	mov    BYTE PTR [rcx],al
 b61:	aa                   	stos   BYTE PTR es:[rdi],al
 b62:	00 00                	add    BYTE PTR [rax],al
 b64:	00 00                	add    BYTE PTR [rax],al
 b66:	16                   	(bad)  
 b67:	7f 0a                	jg     b73 <_init-0x3ff87d>
 b69:	00 00                	add    BYTE PTR [rax],al
 b6b:	26 bf 06 00 00 03    	es mov edi,0x3000006
 b71:	79 0b                	jns    b7e <_init-0x3ff872>
 b73:	00 00                	add    BYTE PTR [rax],al
 b75:	a7                   	cmps   DWORD PTR ds:[rsi],DWORD PTR es:[rdi]
 b76:	0b 00                	or     eax,DWORD PTR [rax]
 b78:	00 27                	add    BYTE PTR [rdi],ah
 b7a:	3b 03                	cmp    eax,DWORD PTR [rbx]
 b7c:	00 00                	add    BYTE PTR [rax],al
 b7e:	2c 0b                	sub    al,0xb
 b80:	00 00                	add    BYTE PTR [rax],al
 b82:	28 0c 0b             	sub    BYTE PTR [rbx+rcx*1],cl
 b85:	00 00                	add    BYTE PTR [rax],al
 b87:	01 f0                	add    eax,esi
 b89:	01 a7 0b 00 00 28    	add    DWORD PTR [rdi+0x2800000b],esp
 b8f:	11 0b                	adc    DWORD PTR [rbx],ecx
 b91:	00 00                	add    BYTE PTR [rax],al
 b93:	01 f0                	add    eax,esi
 b95:	01 ce                	add    esi,ecx
 b97:	00 00                	add    BYTE PTR [rax],al
 b99:	00 2a                	add    BYTE PTR [rdx],ch
 b9b:	5f                   	pop    rdi
 b9c:	5f                   	pop    rdi
 b9d:	6d                   	ins    DWORD PTR es:[rdi],dx
 b9e:	00 01                	add    BYTE PTR [rcx],al
 ba0:	f1                   	icebp  
 ba1:	01 aa 00 00 00 00    	add    DWORD PTR [rdx+0x0],ebp
 ba7:	16                   	(bad)  
 ba8:	8b 0a                	mov    ecx,DWORD PTR [rdx]
 baa:	00 00                	add    BYTE PTR [rax],al
 bac:	26 19 07             	sbb    DWORD PTR es:[rdi],eax
 baf:	00 00                	add    BYTE PTR [rax],al
 bb1:	03 ba 0b 00 00 dc    	add    edi,DWORD PTR [rdx-0x23fffff5]
 bb7:	0b 00                	or     eax,DWORD PTR [rax]
 bb9:	00 27                	add    BYTE PTR [rdi],ah
 bbb:	3b 03                	cmp    eax,DWORD PTR [rbx]
 bbd:	00 00                	add    BYTE PTR [rax],al
 bbf:	2c 0b                	sub    al,0xb
 bc1:	00 00                	add    BYTE PTR [rax],al
 bc3:	2a 5f 5f             	sub    bl,BYTE PTR [rdi+0x5f]
 bc6:	69 00 01 00 02 ce    	imul   eax,DWORD PTR [rax],0xce020001
 bcc:	00 00                	add    BYTE PTR [rax],al
 bce:	00 2a                	add    BYTE PTR [rdx],ch
 bd0:	5f                   	pop    rdi
 bd1:	5f                   	pop    rdi
 bd2:	6d                   	ins    DWORD PTR es:[rdi],dx
 bd3:	00 01                	add    BYTE PTR [rcx],al
 bd5:	01 02                	add    DWORD PTR [rdx],eax
 bd7:	aa                   	stos   BYTE PTR es:[rdi],al
 bd8:	00 00                	add    BYTE PTR [rax],al
 bda:	00 00                	add    BYTE PTR [rax],al
 bdc:	26 bf 04 00 00 03    	es mov edi,0x3000004
 be2:	ea                   	(bad)  
 be3:	0b 00                	or     eax,DWORD PTR [rax]
 be5:	00 18                	add    BYTE PTR [rax],bl
 be7:	0c 00                	or     al,0x0
 be9:	00 27                	add    BYTE PTR [rdi],ah
 beb:	3b 03                	cmp    eax,DWORD PTR [rbx]
 bed:	00 00                	add    BYTE PTR [rax],al
 bef:	2c 0b                	sub    al,0xb
 bf1:	00 00                	add    BYTE PTR [rax],al
 bf3:	2a 5f 5f             	sub    bl,BYTE PTR [rdi+0x5f]
 bf6:	69 00 01 6f 01 ce    	imul   eax,DWORD PTR [rax],0xce016f01
 bfc:	00 00                	add    BYTE PTR [rax],al
 bfe:	00 2a                	add    BYTE PTR [rdx],ch
 c00:	5f                   	pop    rdi
 c01:	5f                   	pop    rdi
 c02:	6d                   	ins    DWORD PTR es:[rdi],dx
 c03:	00 01                	add    BYTE PTR [rcx],al
 c05:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 c06:	01 aa 00 00 00 2b    	add    DWORD PTR [rdx+0x2b000000],ebp
 c0c:	5f                   	pop    rdi
 c0d:	5f                   	pop    rdi
 c0e:	62                   	(bad)  
 c0f:	00 01                	add    BYTE PTR [rcx],al
 c11:	71 01                	jno    c14 <_init-0x3ff7dc>
 c13:	aa                   	stos   BYTE PTR es:[rdi],al
 c14:	00 00                	add    BYTE PTR [rax],al
 c16:	00 00                	add    BYTE PTR [rax],al
 c18:	2c b5                	sub    al,0xb5
 c1a:	09 00                	or     DWORD PTR [rax],eax
 c1c:	00 67 06             	add    BYTE PTR [rdi+0x6],ah
 c1f:	40 00 00             	add    BYTE PTR [rax],al
 c22:	00 00                	add    BYTE PTR [rax],al
 c24:	00 14 00             	add    BYTE PTR [rax+rax*1],dl
 c27:	00 00                	add    BYTE PTR [rax],al
 c29:	00 00                	add    BYTE PTR [rax],al
 c2b:	00 00                	add    BYTE PTR [rax],al
 c2d:	01 9c 50 0c 00 00 2d 	add    DWORD PTR [rax+rdx*2+0x2d00000c],ebx
 c34:	5f                   	pop    rdi
 c35:	5f                   	pop    rdi
 c36:	6d                   	ins    DWORD PTR es:[rdi],dx
 c37:	00 01                	add    BYTE PTR [rcx],al
 c39:	50                   	push   rax
 c3a:	aa                   	stos   BYTE PTR es:[rdi],al
 c3b:	00 00                	add    BYTE PTR [rax],al
 c3d:	00 02                	add    BYTE PTR [rdx],al
 c3f:	91                   	xchg   ecx,eax
 c40:	6c                   	ins    BYTE PTR es:[rdi],dx
 c41:	2e e0 0b             	cs loopne c4f <_init-0x3ff7a1>
 c44:	00 00                	add    BYTE PTR [rax],al
 c46:	01 50 77             	add    DWORD PTR [rax+0x77],edx
 c49:	00 00                	add    BYTE PTR [rax],al
 c4b:	00 02                	add    BYTE PTR [rdx],al
 c4d:	91                   	xchg   ecx,eax
 c4e:	68 00 2c d3 09       	push   0x9d32c00
 c53:	00 00                	add    BYTE PTR [rax],al
 c55:	7b 06                	jnp    c5d <_init-0x3ff793>
 c57:	40 00 00             	add    BYTE PTR [rax],al
 c5a:	00 00                	add    BYTE PTR [rax],al
 c5c:	00 26                	add    BYTE PTR [rsi],ah
 c5e:	00 00                	add    BYTE PTR [rax],al
 c60:	00 00                	add    BYTE PTR [rax],al
 c62:	00 00                	add    BYTE PTR [rax],al
 c64:	00 01                	add    BYTE PTR [rcx],al
 c66:	9c                   	pushf  
 c67:	7a 0c                	jp     c75 <_init-0x3ff77b>
 c69:	00 00                	add    BYTE PTR [rax],al
 c6b:	2d 5f 5f 6d 00       	sub    eax,0x6d5f5f
 c70:	01 57 aa             	add    DWORD PTR [rdi-0x56],edx
 c73:	00 00                	add    BYTE PTR [rax],al
 c75:	00 02                	add    BYTE PTR [rdx],al
 c77:	91                   	xchg   ecx,eax
 c78:	6c                   	ins    BYTE PTR es:[rdi],dx
 c79:	00 2f                	add    BYTE PTR [rdi],ch
 c7b:	ec                   	in     al,dx
 c7c:	09 00                	or     DWORD PTR [rax],eax
 c7e:	00 a1 06 40 00 00    	add    BYTE PTR [rcx+0x4006],ah
 c84:	00 00                	add    BYTE PTR [rax],al
 c86:	00 3c 00             	add    BYTE PTR [rax+rax*1],bh
 c89:	00 00                	add    BYTE PTR [rax],al
 c8b:	00 00                	add    BYTE PTR [rax],al
 c8d:	00 00                	add    BYTE PTR [rax],al
 c8f:	01 9c a4 0c 00 00 2d 	add    DWORD PTR [rsp+riz*4+0x2d00000c],ebx
 c96:	5f                   	pop    rdi
 c97:	5f                   	pop    rdi
 c98:	6d                   	ins    DWORD PTR es:[rdi],dx
 c99:	00 01                	add    BYTE PTR [rcx],al
 c9b:	5e                   	pop    rsi
 c9c:	aa                   	stos   BYTE PTR es:[rdi],al
 c9d:	00 00                	add    BYTE PTR [rax],al
 c9f:	00 02                	add    BYTE PTR [rdx],al
 ca1:	91                   	xchg   ecx,eax
 ca2:	5c                   	pop    rsp
 ca3:	00 26                	add    BYTE PTR [rsi],ah
 ca5:	e7 00                	out    0x0,eax
 ca7:	00 00                	add    BYTE PTR [rax],al
 ca9:	02 b2 0c 00 00 bc    	add    dh,BYTE PTR [rdx-0x43fffff4]
 caf:	0c 00                	or     al,0x0
 cb1:	00 27                	add    BYTE PTR [rdi],ah
 cb3:	3b 03                	cmp    eax,DWORD PTR [rbx]
 cb5:	00 00                	add    BYTE PTR [rax],al
 cb7:	2c 0b                	sub    al,0xb
 cb9:	00 00                	add    BYTE PTR [rax],al
 cbb:	00 30                	add    BYTE PTR [rax],dh
 cbd:	a4                   	movs   BYTE PTR es:[rdi],BYTE PTR ds:[rsi]
 cbe:	0c 00                	or     al,0x0
 cc0:	00 22                	add    BYTE PTR [rdx],ah
 cc2:	0c 00                	or     al,0x0
 cc4:	00 de                	add    dh,bl
 cc6:	06                   	(bad)  
 cc7:	40 00 00             	add    BYTE PTR [rax],al
 cca:	00 00                	add    BYTE PTR [rax],al
 ccc:	00 0b                	add    BYTE PTR [rbx],cl
 cce:	00 00                	add    BYTE PTR [rax],al
 cd0:	00 00                	add    BYTE PTR [rax],al
 cd2:	00 00                	add    BYTE PTR [rax],al
 cd4:	00 01                	add    BYTE PTR [rcx],al
 cd6:	9c                   	pushf  
 cd7:	df 0c 00             	fisttp WORD PTR [rax+rax*1]
 cda:	00 e8                	add    al,ch
 cdc:	0c 00                	or     al,0x0
 cde:	00 31                	add    BYTE PTR [rcx],dh
 ce0:	b2 0c                	mov    dl,0xc
 ce2:	00 00                	add    BYTE PTR [rax],al
 ce4:	02 91 68 00 26 f1    	add    dl,BYTE PTR [rcx-0xed9ff98]
 cea:	08 00                	or     BYTE PTR [rax],al
 cec:	00 02                	add    BYTE PTR [rdx],al
 cee:	f6                   	(bad)  
 cef:	0c 00                	or     al,0x0
 cf1:	00 00                	add    BYTE PTR [rax],al
 cf3:	0d 00 00 27 3b       	or     eax,0x3b270000
 cf8:	03 00                	add    eax,DWORD PTR [rax]
 cfa:	00 00                	add    BYTE PTR [rax],al
 cfc:	0d 00 00 00 16       	or     eax,0x16000000
 d01:	91                   	xchg   ecx,eax
 d02:	0a 00                	or     al,BYTE PTR [rax]
 d04:	00 32                	add    BYTE PTR [rdx],dh
 d06:	e8 0c 00 00 40       	call   40000d17 <_end+0x3f9ffcd7>
 d0b:	04 00                	add    al,0x0
 d0d:	00 ea                	add    dl,ch
 d0f:	06                   	(bad)  
 d10:	40 00 00             	add    BYTE PTR [rax],al
 d13:	00 00                	add    BYTE PTR [rax],al
 d15:	00 1b                	add    BYTE PTR [rbx],bl
 d17:	00 00                	add    BYTE PTR [rax],al
 d19:	00 00                	add    BYTE PTR [rax],al
 d1b:	00 00                	add    BYTE PTR [rax],al
 d1d:	00 01                	add    BYTE PTR [rcx],al
 d1f:	9c                   	pushf  
 d20:	28 0d 00 00 31 0d    	sub    BYTE PTR [rip+0xd310000],cl        # d310d26 <_end+0xcd0fce6>
 d26:	00 00                	add    BYTE PTR [rax],al
 d28:	31 f6                	xor    esi,esi
 d2a:	0c 00                	or     al,0x0
 d2c:	00 02                	add    BYTE PTR [rdx],al
 d2e:	91                   	xchg   ecx,eax
 d2f:	68 00 33 cf 0d       	push   0xdcf3300
 d34:	00 00                	add    BYTE PTR [rax],al
 d36:	03 03                	add    eax,DWORD PTR [rbx]
 d38:	2a 0a                	sub    cl,BYTE PTR [rdx]
 d3a:	00 00                	add    BYTE PTR [rax],al
 d3c:	46 05 40 00 00 00    	rex.RX add eax,0x40
 d42:	00 00                	add    BYTE PTR [rax],al
 d44:	21 01                	and    DWORD PTR [rcx],eax
 d46:	00 00                	add    BYTE PTR [rax],al
 d48:	00 00                	add    BYTE PTR [rax],al
 d4a:	00 00                	add    BYTE PTR [rax],al
 d4c:	01 9c e9 0e 00 00 2e 	add    DWORD PTR [rcx+rbp*8+0x2e00000e],ebx
 d53:	7f 05                	jg     d5a <_init-0x3ff696>
 d55:	00 00                	add    BYTE PTR [rax],al
 d57:	03 03                	add    eax,DWORD PTR [rbx]
 d59:	2a 0a                	sub    cl,BYTE PTR [rdx]
 d5b:	00 00                	add    BYTE PTR [rax],al
 d5d:	03 91 8c 7f 2e a4    	add    edx,DWORD PTR [rcx-0x5bd18074]
 d63:	0c 00                	or     al,0x0
 d65:	00 03                	add    BYTE PTR [rbx],al
 d67:	03 e9                	add    ebp,ecx
 d69:	0e                   	(bad)  
 d6a:	00 00                	add    BYTE PTR [rax],al
 d6c:	03 91 80 7f 34 d5    	add    edx,DWORD PTR [rcx-0x2acb8080]
 d72:	0d 00 00 03 04       	or     eax,0x4030000
 d77:	c2 08 00             	ret    0x8
 d7a:	00 03                	add    BYTE PTR [rbx],al
 d7c:	91                   	xchg   ecx,eax
 d7d:	90                   	nop
 d7e:	7f 35                	jg     db5 <_init-0x3ff63b>
 d80:	69 00 03 0a 2a 0a    	imul   eax,DWORD PTR [rax],0xa2a0a03
 d86:	00 00                	add    BYTE PTR [rax],al
 d88:	03 91 9c 7f 36 dc    	add    edx,DWORD PTR [rcx-0x23c98064]
 d8e:	0b 00                	or     eax,DWORD PTR [rax]
 d90:	00 7d 05             	add    BYTE PTR [rbp+0x5],bh
 d93:	40 00 00             	add    BYTE PTR [rax],al
 d96:	00 00                	add    BYTE PTR [rax],al
 d98:	00 2c 00             	add    BYTE PTR [rax+rax*1],ch
 d9b:	00 00                	add    BYTE PTR [rax],al
 d9d:	00 00                	add    BYTE PTR [rax],al
 d9f:	00 00                	add    BYTE PTR [rax],al
 da1:	03 06                	add    eax,DWORD PTR [rsi]
 da3:	d8 0d 00 00 31 ff    	fmul   DWORD PTR [rip+0xffffffffff310000]        # ffffffffff310da9 <_end+0xfffffffffed0fd69>
 da9:	0b 00                	or     eax,DWORD PTR [rax]
 dab:	00 02                	add    BYTE PTR [rdx],al
 dad:	91                   	xchg   ecx,eax
 dae:	50                   	push   rax
 daf:	31 f3                	xor    ebx,esi
 db1:	0b 00                	or     eax,DWORD PTR [rax]
 db3:	00 03                	add    BYTE PTR [rbx],al
 db5:	91                   	xchg   ecx,eax
 db6:	a0 7f 37 ea 0b 00 00 	movabs al,ds:0x7d3800000bea377f
 dbd:	38 7d 
 dbf:	05 40 00 00 00       	add    eax,0x40
 dc4:	00 00                	add    BYTE PTR [rax],al
 dc6:	2c 00                	sub    al,0x0
 dc8:	00 00                	add    BYTE PTR [rax],al
 dca:	00 00                	add    BYTE PTR [rax],al
 dcc:	00 00                	add    BYTE PTR [rax],al
 dce:	39 0b                	cmp    DWORD PTR [rbx],ecx
 dd0:	0c 00                	or     al,0x0
 dd2:	00 02                	add    BYTE PTR [rdx],al
 dd4:	91                   	xchg   ecx,eax
 dd5:	54                   	push   rsp
 dd6:	00 00                	add    BYTE PTR [rax],al
 dd8:	36 ac                	lods   al,BYTE PTR ss:[rsi]
 dda:	0b 00                	or     eax,DWORD PTR [rax]
 ddc:	00 a9 05 40 00 00    	add    BYTE PTR [rcx+0x4005],ch
 de2:	00 00                	add    BYTE PTR [rax],al
 de4:	00 0b                	add    BYTE PTR [rbx],cl
 de6:	00 00                	add    BYTE PTR [rax],al
 de8:	00 00                	add    BYTE PTR [rax],al
 dea:	00 00                	add    BYTE PTR [rax],al
 dec:	00 03                	add    BYTE PTR [rbx],al
 dee:	08 0a                	or     BYTE PTR [rdx],cl
 df0:	0e                   	(bad)  
 df1:	00 00                	add    BYTE PTR [rax],al
 df3:	31 cf                	xor    edi,ecx
 df5:	0b 00                	or     eax,DWORD PTR [rax]
 df7:	00 02                	add    BYTE PTR [rdx],al
 df9:	91                   	xchg   ecx,eax
 dfa:	4c 31 c3             	xor    rbx,r8
 dfd:	0b 00                	or     eax,DWORD PTR [rax]
 dff:	00 03                	add    BYTE PTR [rbx],al
 e01:	91                   	xchg   ecx,eax
 e02:	a4                   	movs   BYTE PTR es:[rdi],BYTE PTR ds:[rsi]
 e03:	7f 37                	jg     e3c <_init-0x3ff5b4>
 e05:	ba 0b 00 00 00       	mov    edx,0xb
 e0a:	36 6b 0b 00          	imul   ecx,DWORD PTR ss:[rbx],0x0
 e0e:	00 c9                	add    cl,cl
 e10:	05 40 00 00 00       	add    eax,0x40
 e15:	00 00                	add    BYTE PTR [rax],al
 e17:	70 00                	jo     e19 <_init-0x3ff5d7>
 e19:	00 00                	add    BYTE PTR [rax],al
 e1b:	00 00                	add    BYTE PTR [rax],al
 e1d:	00 00                	add    BYTE PTR [rax],al
 e1f:	03 0b                	add    ecx,DWORD PTR [rbx]
 e21:	a7                   	cmps   DWORD PTR ds:[rsi],DWORD PTR es:[rdi]
 e22:	0e                   	(bad)  
 e23:	00 00                	add    BYTE PTR [rax],al
 e25:	31 9a 0b 00 00 03    	xor    DWORD PTR [rdx+0x300000b],ebx
 e2b:	91                   	xchg   ecx,eax
 e2c:	b4 7f                	mov    ah,0x7f
 e2e:	31 8e 0b 00 00 03    	xor    DWORD PTR [rsi+0x300000b],ecx
 e34:	91                   	xchg   ecx,eax
 e35:	a8 7f                	test   al,0x7f
 e37:	37                   	(bad)  
 e38:	82                   	(bad)  
 e39:	0b 00                	or     eax,DWORD PTR [rax]
 e3b:	00 37                	add    BYTE PTR [rdi],dh
 e3d:	79 0b                	jns    e4a <_init-0x3ff5a6>
 e3f:	00 00                	add    BYTE PTR [rax],al
 e41:	3a cc                	cmp    cl,ah
 e43:	0a 00                	or     al,BYTE PTR [rax]
 e45:	00 f4                	add    ah,dh
 e47:	05 40 00 00 00       	add    eax,0x40
 e4c:	00 00                	add    BYTE PTR [rax],al
 e4e:	45 00 00             	add    BYTE PTR [r8],r8b
 e51:	00 00                	add    BYTE PTR [rax],al
 e53:	00 00                	add    BYTE PTR [rax],al
 e55:	00 01                	add    BYTE PTR [rcx],al
 e57:	f4                   	hlt    
 e58:	01 31                	add    DWORD PTR [rcx],esi
 e5a:	07                   	(bad)  
 e5b:	0b 00                	or     eax,DWORD PTR [rax]
 e5d:	00 02                	add    BYTE PTR [rdx],al
 e5f:	91                   	xchg   ecx,eax
 e60:	40 31 fb             	rex xor ebx,edi
 e63:	0a 00                	or     al,BYTE PTR [rax]
 e65:	00 03                	add    BYTE PTR [rbx],al
 e67:	91                   	xchg   ecx,eax
 e68:	bc 7f 31 ef 0a       	mov    esp,0xaef317f
 e6d:	00 00                	add    BYTE PTR [rax],al
 e6f:	03 91 b8 7f 31 e3    	add    edx,DWORD PTR [rcx-0x1cce8048]
 e75:	0a 00                	or     al,BYTE PTR [rax]
 e77:	00 02                	add    BYTE PTR [rdx],al
 e79:	91                   	xchg   ecx,eax
 e7a:	60                   	(bad)  
 e7b:	31 da                	xor    edx,ebx
 e7d:	0a 00                	or     al,BYTE PTR [rax]
 e7f:	00 02                	add    BYTE PTR [rdx],al
 e81:	91                   	xchg   ecx,eax
 e82:	58                   	pop    rax
 e83:	38 f4                	cmp    ah,dh
 e85:	05 40 00 00 00       	add    eax,0x40
 e8a:	00 00                	add    BYTE PTR [rax],al
 e8c:	45 00 00             	add    BYTE PTR [r8],r8b
 e8f:	00 00                	add    BYTE PTR [rax],al
 e91:	00 00                	add    BYTE PTR [rax],al
 e93:	00 39                	add    BYTE PTR [rcx],bh
 e95:	13 0b                	adc    ecx,DWORD PTR [rbx]
 e97:	00 00                	add    BYTE PTR [rax],al
 e99:	02 91 44 39 1f 0b    	add    dl,BYTE PTR [rcx+0xb1f3944]
 e9f:	00 00                	add    BYTE PTR [rax],al
 ea1:	02 91 48 00 00 00    	add    dl,BYTE PTR [rcx+0x48]
 ea7:	3b 36                	cmp    esi,DWORD PTR [rsi]
 ea9:	0b 00                	or     eax,DWORD PTR [rax]
 eab:	00 39                	add    BYTE PTR [rcx],bh
 ead:	06                   	(bad)  
 eae:	40 00 00             	add    BYTE PTR [rax],al
 eb1:	00 00                	add    BYTE PTR [rax],al
 eb3:	00 18                	add    BYTE PTR [rax],bl
 eb5:	00 00                	add    BYTE PTR [rax],al
 eb7:	00 00                	add    BYTE PTR [rax],al
 eb9:	00 00                	add    BYTE PTR [rax],al
 ebb:	00 03                	add    BYTE PTR [rbx],al
 ebd:	0d 31 4d 0b 00       	or     eax,0xb4d31
 ec2:	00 03                	add    BYTE PTR [rbx],al
 ec4:	91                   	xchg   ecx,eax
 ec5:	ac                   	lods   al,BYTE PTR ds:[rsi]
 ec6:	7f 37                	jg     eff <_init-0x3ff4f1>
 ec8:	44 0b 00             	or     r8d,DWORD PTR [rax]
 ecb:	00 38                	add    BYTE PTR [rax],bh
 ecd:	39 06                	cmp    DWORD PTR [rsi],eax
 ecf:	40 00 00             	add    BYTE PTR [rax],al
 ed2:	00 00                	add    BYTE PTR [rax],al
 ed4:	00 18                	add    BYTE PTR [rax],bl
 ed6:	00 00                	add    BYTE PTR [rax],al
 ed8:	00 00                	add    BYTE PTR [rax],al
 eda:	00 00                	add    BYTE PTR [rax],al
 edc:	00 39                	add    BYTE PTR [rcx],bh
 ede:	59                   	pop    rcx
 edf:	0b 00                	or     eax,DWORD PTR [rax]
 ee1:	00 03                	add    BYTE PTR [rbx],al
 ee3:	91                   	xchg   ecx,eax
 ee4:	b0 7f                	mov    al,0x7f
 ee6:	00 00                	add    BYTE PTR [rax],al
 ee8:	00 24 08             	add    BYTE PTR [rax+rcx*1],ah
 eeb:	ef                   	out    dx,eax
 eec:	0e                   	(bad)  
 eed:	00 00                	add    BYTE PTR [rax],al
 eef:	24 08                	and    al,0x8
 ef1:	60                   	(bad)  
 ef2:	0a 00                	or     al,BYTE PTR [rax]
	...

Disassembly of section .debug_abbrev:

0000000000000000 <.debug_abbrev>:
   0:	01 11                	add    DWORD PTR [rcx],edx
   2:	01 25 0e 13 0b 03    	add    DWORD PTR [rip+0x30b130e],esp        # 30b1316 <_end+0x2ab02d6>
   8:	0e                   	(bad)  
   9:	1b 0e                	sbb    ecx,DWORD PTR [rsi]
   b:	55                   	push   rbp
   c:	17                   	(bad)  
   d:	11 01                	adc    DWORD PTR [rcx],eax
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
  35:	00 05 04 01 03 0e    	add    BYTE PTR [rip+0xe030104],al        # e03013f <_end+0xda2f0ff>
  3b:	0b 0b                	or     ecx,DWORD PTR [rbx]
  3d:	49 13 3a             	adc    rdi,QWORD PTR [r10]
  40:	0b 3b                	or     edi,DWORD PTR [rbx]
  42:	0b 01                	or     eax,DWORD PTR [rcx]
  44:	13 00                	adc    eax,DWORD PTR [rax]
  46:	00 06                	add    BYTE PTR [rsi],al
  48:	28 00                	sub    BYTE PTR [rax],al
  4a:	03 0e                	add    ecx,DWORD PTR [rsi]
  4c:	1c 0b                	sbb    al,0xb
  4e:	00 00                	add    BYTE PTR [rax],al
  50:	07                   	(bad)  
  51:	28 00                	sub    BYTE PTR [rax],al
  53:	03 0e                	add    ecx,DWORD PTR [rsi]
  55:	1c 05                	sbb    al,0x5
  57:	00 00                	add    BYTE PTR [rax],al
  59:	08 28                	or     BYTE PTR [rax],ch
  5b:	00 03                	add    BYTE PTR [rbx],al
  5d:	0e                   	(bad)  
  5e:	1c 06                	sbb    al,0x6
  60:	00 00                	add    BYTE PTR [rax],al
  62:	09 16                	or     DWORD PTR [rsi],edx
  64:	00 03                	add    BYTE PTR [rbx],al
  66:	0e                   	(bad)  
  67:	3a 0b                	cmp    cl,BYTE PTR [rbx]
  69:	3b 0b                	cmp    ecx,DWORD PTR [rbx]
  6b:	49 13 00             	adc    rax,QWORD PTR [r8]
  6e:	00 0a                	add    BYTE PTR [rdx],cl
  70:	13 01                	adc    eax,DWORD PTR [rcx]
  72:	03 0e                	add    ecx,DWORD PTR [rsi]
  74:	0b 0b                	or     ecx,DWORD PTR [rbx]
  76:	3a 0b                	cmp    cl,BYTE PTR [rbx]
  78:	3b 0b                	cmp    ecx,DWORD PTR [rbx]
  7a:	01 13                	add    DWORD PTR [rbx],edx
  7c:	00 00                	add    BYTE PTR [rax],al
  7e:	0b 0d 00 03 0e 3a    	or     ecx,DWORD PTR [rip+0x3a0e0300]        # 3a0e0384 <_end+0x39adf344>
  84:	0b 3b                	or     edi,DWORD PTR [rbx]
  86:	0b 49 13             	or     ecx,DWORD PTR [rcx+0x13]
  89:	3f                   	(bad)  
  8a:	19 32                	sbb    DWORD PTR [rdx],esi
  8c:	0b 3c 19             	or     edi,DWORD PTR [rcx+rbx*1]
  8f:	1c 0b                	sbb    al,0xb
  91:	00 00                	add    BYTE PTR [rax],al
  93:	0c 16                	or     al,0x16
  95:	00 03                	add    BYTE PTR [rbx],al
  97:	0e                   	(bad)  
  98:	3a 0b                	cmp    cl,BYTE PTR [rbx]
  9a:	3b 0b                	cmp    ecx,DWORD PTR [rbx]
  9c:	49 13 32             	adc    rsi,QWORD PTR [r10]
  9f:	0b 00                	or     eax,DWORD PTR [rax]
  a1:	00 0d 0d 00 03 0e    	add    BYTE PTR [rip+0xe03000d],cl        # e0300b4 <_end+0xda2f074>
  a7:	3a 0b                	cmp    cl,BYTE PTR [rbx]
  a9:	3b 0b                	cmp    ecx,DWORD PTR [rbx]
  ab:	49 13 38             	adc    rdi,QWORD PTR [r8]
  ae:	0b 32                	or     esi,DWORD PTR [rdx]
  b0:	0b 00                	or     eax,DWORD PTR [rax]
  b2:	00 0e                	add    BYTE PTR [rsi],cl
  b4:	2e 01 3f             	add    DWORD PTR cs:[rdi],edi
  b7:	19 03                	sbb    DWORD PTR [rbx],eax
  b9:	0e                   	(bad)  
  ba:	3a 0b                	cmp    cl,BYTE PTR [rbx]
  bc:	3b 0b                	cmp    ecx,DWORD PTR [rbx]
  be:	6e                   	outs   dx,BYTE PTR ds:[rsi]
  bf:	0e                   	(bad)  
  c0:	3c 19                	cmp    al,0x19
  c2:	64 13 01             	adc    eax,DWORD PTR fs:[rcx]
  c5:	13 00                	adc    eax,DWORD PTR [rax]
  c7:	00 0f                	add    BYTE PTR [rdi],cl
  c9:	05 00 49 13 34       	add    eax,0x34134900
  ce:	19 00                	sbb    DWORD PTR [rax],eax
  d0:	00 10                	add    BYTE PTR [rax],dl
  d2:	2e 01 3f             	add    DWORD PTR cs:[rdi],edi
  d5:	19 03                	sbb    DWORD PTR [rbx],eax
  d7:	0e                   	(bad)  
  d8:	3a 0b                	cmp    cl,BYTE PTR [rbx]
  da:	3b 0b                	cmp    ecx,DWORD PTR [rbx]
  dc:	6e                   	outs   dx,BYTE PTR ds:[rsi]
  dd:	0e                   	(bad)  
  de:	3c 19                	cmp    al,0x19
  e0:	9a                   	(bad)  
  e1:	42 19 64 13 01       	sbb    DWORD PTR [rbx+r10*1+0x1],esp
  e6:	13 00                	adc    eax,DWORD PTR [rax]
  e8:	00 11                	add    BYTE PTR [rcx],dl
  ea:	05 00 49 13 00       	add    eax,0x134900
  ef:	00 12                	add    BYTE PTR [rdx],dl
  f1:	2e 01 3f             	add    DWORD PTR cs:[rdi],edi
  f4:	19 03                	sbb    DWORD PTR [rbx],eax
  f6:	0e                   	(bad)  
  f7:	3a 0b                	cmp    cl,BYTE PTR [rbx]
  f9:	3b 0b                	cmp    ecx,DWORD PTR [rbx]
  fb:	6e                   	outs   dx,BYTE PTR ds:[rsi]
  fc:	0e                   	(bad)  
  fd:	49 13 3c 19          	adc    rdi,QWORD PTR [r9+rbx*1]
 101:	9a                   	(bad)  
 102:	42 19 64 13 01       	sbb    DWORD PTR [rbx+r10*1+0x1],esp
 107:	13 00                	adc    eax,DWORD PTR [rax]
 109:	00 13                	add    BYTE PTR [rbx],dl
 10b:	2e 01 3f             	add    DWORD PTR cs:[rdi],edi
 10e:	19 03                	sbb    DWORD PTR [rbx],eax
 110:	0e                   	(bad)  
 111:	3a 0b                	cmp    cl,BYTE PTR [rbx]
 113:	3b 05 6e 0e 3c 19    	cmp    eax,DWORD PTR [rip+0x193c0e6e]        # 193c0f87 <_end+0x18dbff47>
 119:	64 13 01             	adc    eax,DWORD PTR fs:[rcx]
 11c:	13 00                	adc    eax,DWORD PTR [rax]
 11e:	00 14 2e             	add    BYTE PTR [rsi+rbp*1],dl
 121:	01 3f                	add    DWORD PTR [rdi],edi
 123:	19 03                	sbb    DWORD PTR [rbx],eax
 125:	0e                   	(bad)  
 126:	3a 0b                	cmp    cl,BYTE PTR [rbx]
 128:	3b 05 6e 0e 49 13    	cmp    eax,DWORD PTR [rip+0x13490e6e]        # 13490f9c <_end+0x12e8ff5c>
 12e:	3c 19                	cmp    al,0x19
 130:	64 13 01             	adc    eax,DWORD PTR fs:[rcx]
 133:	13 00                	adc    eax,DWORD PTR [rax]
 135:	00 15 2f 00 03 0e    	add    BYTE PTR [rip+0xe03002f],dl        # e03016a <_end+0xda2f12a>
 13b:	49 13 00             	adc    rax,QWORD PTR [r8]
 13e:	00 16                	add    BYTE PTR [rsi],dl
 140:	26 00 49 13          	add    BYTE PTR es:[rcx+0x13],cl
 144:	00 00                	add    BYTE PTR [rax],al
 146:	17                   	(bad)  
 147:	35 00 49 13 00       	xor    eax,0x134900
 14c:	00 18                	add    BYTE PTR [rax],bl
 14e:	13 01                	adc    eax,DWORD PTR [rcx]
 150:	03 0e                	add    ecx,DWORD PTR [rsi]
 152:	0b 0b                	or     ecx,DWORD PTR [rbx]
 154:	3a 0b                	cmp    cl,BYTE PTR [rbx]
 156:	3b 05 01 13 00 00    	cmp    eax,DWORD PTR [rip+0x1301]        # 145d <_init-0x3fef93>
 15c:	19 08                	sbb    DWORD PTR [rax],ecx
 15e:	00 3a                	add    BYTE PTR [rdx],bh
 160:	0b 3b                	or     edi,DWORD PTR [rbx]
 162:	05 18 13 00 00       	add    eax,0x1318
 167:	1a 1c 00             	sbb    bl,BYTE PTR [rax+rax*1]
 16a:	49 13 38             	adc    rdi,QWORD PTR [r8]
 16d:	0b 00                	or     eax,DWORD PTR [rax]
 16f:	00 1b                	add    BYTE PTR [rbx],bl
 171:	16                   	(bad)  
 172:	00 03                	add    BYTE PTR [rbx],al
 174:	0e                   	(bad)  
 175:	3a 0b                	cmp    cl,BYTE PTR [rbx]
 177:	3b 05 49 13 00 00    	cmp    eax,DWORD PTR [rip+0x1349]        # 14c6 <_init-0x3fef2a>
 17d:	1c 2e                	sbb    al,0x2e
 17f:	01 3f                	add    DWORD PTR [rdi],edi
 181:	19 03                	sbb    DWORD PTR [rbx],eax
 183:	0e                   	(bad)  
 184:	3a 0b                	cmp    cl,BYTE PTR [rbx]
 186:	3b 05 6e 0e 3c 19    	cmp    eax,DWORD PTR [rip+0x193c0e6e]        # 193c0ffa <_end+0x18dbffba>
 18c:	9a                   	(bad)  
 18d:	42 19 64 13 01       	sbb    DWORD PTR [rbx+r10*1+0x1],esp
 192:	13 00                	adc    eax,DWORD PTR [rax]
 194:	00 1d 2e 01 3f 19    	add    BYTE PTR [rip+0x193f012e],bl        # 193f02c8 <_end+0x18def288>
 19a:	03 0e                	add    ecx,DWORD PTR [rsi]
 19c:	3a 0b                	cmp    cl,BYTE PTR [rbx]
 19e:	3b 05 6e 0e 49 13    	cmp    eax,DWORD PTR [rip+0x13490e6e]        # 13491012 <_end+0x12e8ffd2>
 1a4:	3c 19                	cmp    al,0x19
 1a6:	9a                   	(bad)  
 1a7:	42 19 64 13 01       	sbb    DWORD PTR [rbx+r10*1+0x1],esp
 1ac:	13 00                	adc    eax,DWORD PTR [rax]
 1ae:	00 1e                	add    BYTE PTR [rsi],bl
 1b0:	2e 01 3f             	add    DWORD PTR cs:[rdi],edi
 1b3:	19 03                	sbb    DWORD PTR [rbx],eax
 1b5:	0e                   	(bad)  
 1b6:	3a 0b                	cmp    cl,BYTE PTR [rbx]
 1b8:	3b 05 6e 0e 3c 19    	cmp    eax,DWORD PTR [rip+0x193c0e6e]        # 193c102c <_end+0x18dbffec>
 1be:	64 13 00             	adc    eax,DWORD PTR fs:[rax]
 1c1:	00 1f                	add    BYTE PTR [rdi],bl
 1c3:	2e 01 3f             	add    DWORD PTR cs:[rdi],edi
 1c6:	19 03                	sbb    DWORD PTR [rbx],eax
 1c8:	0e                   	(bad)  
 1c9:	3a 0b                	cmp    cl,BYTE PTR [rbx]
 1cb:	3b 0b                	cmp    ecx,DWORD PTR [rbx]
 1cd:	6e                   	outs   dx,BYTE PTR ds:[rsi]
 1ce:	0e                   	(bad)  
 1cf:	49 13 3c 19          	adc    rdi,QWORD PTR [r9+rbx*1]
 1d3:	01 13                	add    DWORD PTR [rbx],edx
 1d5:	00 00                	add    BYTE PTR [rax],al
 1d7:	20 2e                	and    BYTE PTR [rsi],ch
 1d9:	01 3f                	add    DWORD PTR [rdi],edi
 1db:	19 03                	sbb    DWORD PTR [rbx],eax
 1dd:	0e                   	(bad)  
 1de:	3a 0b                	cmp    cl,BYTE PTR [rbx]
 1e0:	3b 0b                	cmp    ecx,DWORD PTR [rbx]
 1e2:	6e                   	outs   dx,BYTE PTR ds:[rsi]
 1e3:	0e                   	(bad)  
 1e4:	49 13 3c 19          	adc    rdi,QWORD PTR [r9+rbx*1]
 1e8:	00 00                	add    BYTE PTR [rax],al
 1ea:	21 39                	and    DWORD PTR [rcx],edi
 1ec:	01 03                	add    DWORD PTR [rbx],eax
 1ee:	0e                   	(bad)  
 1ef:	3a 0b                	cmp    cl,BYTE PTR [rbx]
 1f1:	3b 0b                	cmp    ecx,DWORD PTR [rbx]
 1f3:	01 13                	add    DWORD PTR [rbx],edx
 1f5:	00 00                	add    BYTE PTR [rax],al
 1f7:	22 24 00             	and    ah,BYTE PTR [rax+rax*1]
 1fa:	0b 0b                	or     ecx,DWORD PTR [rbx]
 1fc:	3e 0b 03             	or     eax,DWORD PTR ds:[rbx]
 1ff:	0e                   	(bad)  
 200:	00 00                	add    BYTE PTR [rax],al
 202:	23 24 00             	and    esp,DWORD PTR [rax+rax*1]
 205:	0b 0b                	or     ecx,DWORD PTR [rbx]
 207:	3e 0b 03             	or     eax,DWORD PTR ds:[rbx]
 20a:	08 00                	or     BYTE PTR [rax],al
 20c:	00 24 0f             	add    BYTE PTR [rdi+rcx*1],ah
 20f:	00 0b                	add    BYTE PTR [rbx],cl
 211:	0b 49 13             	or     ecx,DWORD PTR [rcx+0x13]
 214:	00 00                	add    BYTE PTR [rax],al
 216:	25 10 00 0b 0b       	and    eax,0xb0b0010
 21b:	49 13 00             	adc    rax,QWORD PTR [r8]
 21e:	00 26                	add    BYTE PTR [rsi],ah
 220:	2e 01 47 13          	add    DWORD PTR cs:[rdi+0x13],eax
 224:	20 0b                	and    BYTE PTR [rbx],cl
 226:	64 13 01             	adc    eax,DWORD PTR fs:[rcx]
 229:	13 00                	adc    eax,DWORD PTR [rax]
 22b:	00 27                	add    BYTE PTR [rdi],ah
 22d:	05 00 03 0e 49       	add    eax,0x490e0300
 232:	13 34 19             	adc    esi,DWORD PTR [rcx+rbx*1]
 235:	00 00                	add    BYTE PTR [rax],al
 237:	28 05 00 03 0e 3a    	sub    BYTE PTR [rip+0x3a0e0300],al        # 3a0e053d <_end+0x39adf4fd>
 23d:	0b 3b                	or     edi,DWORD PTR [rbx]
 23f:	05 49 13 00 00       	add    eax,0x1349
 244:	29 34 00             	sub    DWORD PTR [rax+rax*1],esi
 247:	03 0e                	add    ecx,DWORD PTR [rsi]
 249:	3a 0b                	cmp    cl,BYTE PTR [rbx]
 24b:	3b 05 49 13 00 00    	cmp    eax,DWORD PTR [rip+0x1349]        # 159a <_init-0x3fee56>
 251:	2a 05 00 03 08 3a    	sub    al,BYTE PTR [rip+0x3a080300]        # 3a080557 <_end+0x39a7f517>
 257:	0b 3b                	or     edi,DWORD PTR [rbx]
 259:	05 49 13 00 00       	add    eax,0x1349
 25e:	2b 34 00             	sub    esi,DWORD PTR [rax+rax*1]
 261:	03 08                	add    ecx,DWORD PTR [rax]
 263:	3a 0b                	cmp    cl,BYTE PTR [rbx]
 265:	3b 05 49 13 00 00    	cmp    eax,DWORD PTR [rip+0x1349]        # 15b4 <_init-0x3fee3c>
 26b:	2c 2e                	sub    al,0x2e
 26d:	01 47 13             	add    DWORD PTR [rdi+0x13],eax
 270:	11 01                	adc    DWORD PTR [rcx],eax
 272:	12 07                	adc    al,BYTE PTR [rdi]
 274:	40 18 97 42 19 01 13 	sbb    BYTE PTR [rdi+0x13011942],dl
 27b:	00 00                	add    BYTE PTR [rax],al
 27d:	2d 05 00 03 08       	sub    eax,0x8030005
 282:	3a 0b                	cmp    cl,BYTE PTR [rbx]
 284:	3b 0b                	cmp    ecx,DWORD PTR [rbx]
 286:	49 13 02             	adc    rax,QWORD PTR [r10]
 289:	18 00                	sbb    BYTE PTR [rax],al
 28b:	00 2e                	add    BYTE PTR [rsi],ch
 28d:	05 00 03 0e 3a       	add    eax,0x3a0e0300
 292:	0b 3b                	or     edi,DWORD PTR [rbx]
 294:	0b 49 13             	or     ecx,DWORD PTR [rcx+0x13]
 297:	02 18                	add    bl,BYTE PTR [rax]
 299:	00 00                	add    BYTE PTR [rax],al
 29b:	2f                   	(bad)  
 29c:	2e 01 47 13          	add    DWORD PTR cs:[rdi+0x13],eax
 2a0:	11 01                	adc    DWORD PTR [rcx],eax
 2a2:	12 07                	adc    al,BYTE PTR [rdi]
 2a4:	40 18 96 42 19 01 13 	sbb    BYTE PTR [rsi+0x13011942],dl
 2ab:	00 00                	add    BYTE PTR [rax],al
 2ad:	30 2e                	xor    BYTE PTR [rsi],ch
 2af:	01 31                	add    DWORD PTR [rcx],esi
 2b1:	13 6e 0e             	adc    ebp,DWORD PTR [rsi+0xe]
 2b4:	11 01                	adc    DWORD PTR [rcx],eax
 2b6:	12 07                	adc    al,BYTE PTR [rdi]
 2b8:	40 18 64 13 97       	sbb    BYTE PTR [rbx+rdx*1-0x69],spl
 2bd:	42 19 01             	rex.X sbb DWORD PTR [rcx],eax
 2c0:	13 00                	adc    eax,DWORD PTR [rax]
 2c2:	00 31                	add    BYTE PTR [rcx],dh
 2c4:	05 00 31 13 02       	add    eax,0x2133100
 2c9:	18 00                	sbb    BYTE PTR [rax],al
 2cb:	00 32                	add    BYTE PTR [rdx],dh
 2cd:	2e 01 31             	add    DWORD PTR cs:[rcx],esi
 2d0:	13 6e 0e             	adc    ebp,DWORD PTR [rsi+0xe]
 2d3:	11 01                	adc    DWORD PTR [rcx],eax
 2d5:	12 07                	adc    al,BYTE PTR [rdi]
 2d7:	40 18 64 13 96       	sbb    BYTE PTR [rbx+rdx*1-0x6a],spl
 2dc:	42 19 01             	rex.X sbb DWORD PTR [rcx],eax
 2df:	13 00                	adc    eax,DWORD PTR [rax]
 2e1:	00 33                	add    BYTE PTR [rbx],dh
 2e3:	2e 01 3f             	add    DWORD PTR cs:[rdi],edi
 2e6:	19 03                	sbb    DWORD PTR [rbx],eax
 2e8:	0e                   	(bad)  
 2e9:	3a 0b                	cmp    cl,BYTE PTR [rbx]
 2eb:	3b 0b                	cmp    ecx,DWORD PTR [rbx]
 2ed:	49 13 11             	adc    rdx,QWORD PTR [r9]
 2f0:	01 12                	add    DWORD PTR [rdx],edx
 2f2:	07                   	(bad)  
 2f3:	40 18 96 42 19 01 13 	sbb    BYTE PTR [rsi+0x13011942],dl
 2fa:	00 00                	add    BYTE PTR [rax],al
 2fc:	34 34                	xor    al,0x34
 2fe:	00 03                	add    BYTE PTR [rbx],al
 300:	0e                   	(bad)  
 301:	3a 0b                	cmp    cl,BYTE PTR [rbx]
 303:	3b 0b                	cmp    ecx,DWORD PTR [rbx]
 305:	49 13 02             	adc    rax,QWORD PTR [r10]
 308:	18 00                	sbb    BYTE PTR [rax],al
 30a:	00 35 34 00 03 08    	add    BYTE PTR [rip+0x8030034],dh        # 8030344 <_end+0x7a2f304>
 310:	3a 0b                	cmp    cl,BYTE PTR [rbx]
 312:	3b 0b                	cmp    ecx,DWORD PTR [rbx]
 314:	49 13 02             	adc    rax,QWORD PTR [r10]
 317:	18 00                	sbb    BYTE PTR [rax],al
 319:	00 36                	add    BYTE PTR [rsi],dh
 31b:	1d 01 31 13 11       	sbb    eax,0x11133101
 320:	01 12                	add    DWORD PTR [rdx],edx
 322:	07                   	(bad)  
 323:	58                   	pop    rax
 324:	0b 59 0b             	or     ebx,DWORD PTR [rcx+0xb]
 327:	01 13                	add    DWORD PTR [rbx],edx
 329:	00 00                	add    BYTE PTR [rax],al
 32b:	37                   	(bad)  
 32c:	05 00 31 13 00       	add    eax,0x133100
 331:	00 38                	add    BYTE PTR [rax],bh
 333:	0b 01                	or     eax,DWORD PTR [rcx]
 335:	11 01                	adc    DWORD PTR [rcx],eax
 337:	12 07                	adc    al,BYTE PTR [rdi]
 339:	00 00                	add    BYTE PTR [rax],al
 33b:	39 34 00             	cmp    DWORD PTR [rax+rax*1],esi
 33e:	31 13                	xor    DWORD PTR [rbx],edx
 340:	02 18                	add    bl,BYTE PTR [rax]
 342:	00 00                	add    BYTE PTR [rax],al
 344:	3a 1d 01 31 13 11    	cmp    bl,BYTE PTR [rip+0x11133101]        # 1113344b <_end+0x10b3240b>
 34a:	01 12                	add    DWORD PTR [rdx],edx
 34c:	07                   	(bad)  
 34d:	58                   	pop    rax
 34e:	0b 59 05             	or     ebx,DWORD PTR [rcx+0x5]
 351:	00 00                	add    BYTE PTR [rax],al
 353:	3b 1d 01 31 13 11    	cmp    ebx,DWORD PTR [rip+0x11133101]        # 1113345a <_end+0x10b3241a>
 359:	01 12                	add    DWORD PTR [rdx],edx
 35b:	07                   	(bad)  
 35c:	58                   	pop    rax
 35d:	0b 59 0b             	or     ebx,DWORD PTR [rcx+0xb]
 360:	00 00                	add    BYTE PTR [rax],al
	...

Disassembly of section .debug_line:

0000000000000000 <.debug_line>:
   0:	84 01                	test   BYTE PTR [rcx],al
   2:	00 00                	add    BYTE PTR [rax],al
   4:	02 00                	add    al,BYTE PTR [rax]
   6:	ad                   	lods   eax,DWORD PTR ds:[rsi]
   7:	00 00                	add    BYTE PTR [rax],al
   9:	00 01                	add    BYTE PTR [rcx],al
   b:	01 fb                	add    ebx,edi
   d:	0e                   	(bad)  
   e:	0d 00 01 01 01       	or     eax,0x1010100
  13:	01 00                	add    DWORD PTR [rax],eax
  15:	00 00                	add    BYTE PTR [rax],al
  17:	01 00                	add    DWORD PTR [rax],eax
  19:	00 01                	add    BYTE PTR [rcx],al
  1b:	2f                   	(bad)  
  1c:	75 73                	jne    91 <_init-0x40035f>
  1e:	72 2f                	jb     4f <_init-0x4003a1>
  20:	69 6e 63 6c 75 64 65 	imul   ebp,DWORD PTR [rsi+0x63],0x6564756c
  27:	2f                   	(bad)  
  28:	63 2b                	movsxd ebp,DWORD PTR [rbx]
  2a:	2b 2f                	sub    ebp,DWORD PTR [rdi]
  2c:	35 2f 62 69 74       	xor    eax,0x7469622f
  31:	73 00                	jae    33 <_init-0x4003bd>
  33:	2f                   	(bad)  
  34:	75 73                	jne    a9 <_init-0x400347>
  36:	72 2f                	jb     67 <_init-0x400389>
  38:	69 6e 63 6c 75 64 65 	imul   ebp,DWORD PTR [rsi+0x63],0x6564756c
  3f:	2f                   	(bad)  
  40:	63 2b                	movsxd ebp,DWORD PTR [rbx]
  42:	2b 2f                	sub    ebp,DWORD PTR [rdi]
  44:	35 00 2f 75 73       	xor    eax,0x73752f00
  49:	72 2f                	jb     7a <_init-0x400376>
  4b:	69 6e 63 6c 75 64 65 	imul   ebp,DWORD PTR [rsi+0x63],0x6564756c
  52:	2f                   	(bad)  
  53:	78 38                	js     8d <_init-0x400363>
  55:	36 5f                	ss pop rdi
  57:	36 34 2d             	ss xor al,0x2d
  5a:	6c                   	ins    BYTE PTR es:[rdi],dx
  5b:	69 6e 75 78 2d 67 6e 	imul   ebp,DWORD PTR [rsi+0x75],0x6e672d78
  62:	75 2f                	jne    93 <_init-0x40035d>
  64:	63 2b                	movsxd ebp,DWORD PTR [rbx]
  66:	2b 2f                	sub    ebp,DWORD PTR [rdi]
  68:	35 2f 62 69 74       	xor    eax,0x7469622f
  6d:	73 00                	jae    6f <_init-0x400381>
  6f:	00 61 74             	add    BYTE PTR [rcx+0x74],ah
  72:	6f                   	outs   dx,DWORD PTR ds:[rsi]
  73:	6d                   	ins    DWORD PTR es:[rdi],dx
  74:	69 63 5f 62 61 73 65 	imul   esp,DWORD PTR [rbx+0x5f],0x65736162
  7b:	2e 68 00 01 00 00    	cs push 0x100
  81:	61                   	(bad)  
  82:	74 6f                	je     f3 <_init-0x4002fd>
  84:	6d                   	ins    DWORD PTR es:[rdi],dx
  85:	69 63 00 02 00 00 61 	imul   esp,DWORD PTR [rbx+0x0],0x61000002
  8c:	74 6f                	je     fd <_init-0x4002f3>
  8e:	6d                   	ins    DWORD PTR es:[rdi],dx
  8f:	69 63 2e 63 70 70 00 	imul   esp,DWORD PTR [rbx+0x2e],0x707063
  96:	00 00                	add    BYTE PTR [rax],al
  98:	00 63 2b             	add    BYTE PTR [rbx+0x2b],ah
  9b:	2b 63 6f             	sub    esp,DWORD PTR [rbx+0x6f]
  9e:	6e                   	outs   dx,BYTE PTR ds:[rsi]
  9f:	66 69 67 2e 68 00    	imul   sp,WORD PTR [rdi+0x2e],0x68
  a5:	03 00                	add    eax,DWORD PTR [rax]
  a7:	00 3c 62             	add    BYTE PTR [rdx+riz*2],bh
  aa:	75 69                	jne    115 <_init-0x4002db>
  ac:	6c                   	ins    BYTE PTR es:[rdi],dx
  ad:	74 2d                	je     dc <_init-0x400314>
  af:	69 6e 3e 00 00 00 00 	imul   ebp,DWORD PTR [rsi+0x3e],0x0
  b6:	00 00                	add    BYTE PTR [rax],al
  b8:	09 02                	or     DWORD PTR [rdx],eax
  ba:	67 06                	addr32 (bad) 
  bc:	40 00 00             	add    BYTE PTR [rax],al
  bf:	00 00                	add    BYTE PTR [rax],al
  c1:	00 03                	add    BYTE PTR [rbx],al
  c3:	d0 00                	rol    BYTE PTR [rax],1
  c5:	01 9f 83 02 02 00    	add    DWORD PTR [rdi+0x20283],ebx
  cb:	01 01                	add    DWORD PTR [rcx],eax
  cd:	00 09                	add    BYTE PTR [rcx],cl
  cf:	02 7b 06             	add    bh,BYTE PTR [rbx+0x6]
  d2:	40 00 00             	add    BYTE PTR [rax],al
  d5:	00 00                	add    BYTE PTR [rax],al
  d7:	00 03                	add    BYTE PTR [rbx],al
  d9:	d7                   	xlat   BYTE PTR ds:[rbx]
  da:	00 01                	add    BYTE PTR [rcx],al
  dc:	76 00                	jbe    de <_init-0x400312>
  de:	02 04 01             	add    al,BYTE PTR [rcx+rax*1]
  e1:	06                   	(bad)  
  e2:	66 00 02             	data16 add BYTE PTR [rdx],al
  e5:	04 03                	add    al,0x3
  e7:	66 00 02             	data16 add BYTE PTR [rdx],al
  ea:	04 04                	add    al,0x4
  ec:	58                   	pop    rax
  ed:	00 02                	add    BYTE PTR [rdx],al
  ef:	04 02                	add    al,0x2
  f1:	74 00                	je     f3 <_init-0x4002fd>
  f3:	02 04 09             	add    al,BYTE PTR [rcx+rcx*1]
  f6:	06                   	(bad)  
  f7:	59                   	pop    rcx
  f8:	02 02                	add    al,BYTE PTR [rdx]
  fa:	00 01                	add    BYTE PTR [rcx],al
  fc:	01 00                	add    DWORD PTR [rax],eax
  fe:	09 02                	or     DWORD PTR [rdx],eax
 100:	a1 06 40 00 00 00 00 	movabs eax,ds:0x300000000004006
 107:	00 03 
 109:	de 00                	fiadd  WORD PTR [rax]
 10b:	01 bb 08 59 08 2f    	add    DWORD PTR [rbx+0x2f085908],edi
 111:	02 07                	add    al,BYTE PTR [rdi]
 113:	00 01                	add    BYTE PTR [rcx],al
 115:	01 00                	add    DWORD PTR [rax],eax
 117:	09 02                	or     DWORD PTR [rdx],eax
 119:	de 06                	fiadd  WORD PTR [rsi]
 11b:	40 00 00             	add    BYTE PTR [rax],al
 11e:	00 00                	add    BYTE PTR [rax],al
 120:	00 03                	add    BYTE PTR [rbx],al
 122:	f8                   	clc    
 123:	01 01                	add    DWORD PTR [rcx],eax
 125:	82                   	(bad)  
 126:	02 03                	add    al,BYTE PTR [rbx]
 128:	00 01                	add    BYTE PTR [rcx],al
 12a:	01 04 02             	add    DWORD PTR [rdx+rax*1],eax
 12d:	00 09                	add    BYTE PTR [rcx],cl
 12f:	02 ea                	add    ch,dl
 131:	06                   	(bad)  
 132:	40 00 00             	add    BYTE PTR [rax],al
 135:	00 00                	add    BYTE PTR [rax],al
 137:	00 03                	add    BYTE PTR [rbx],al
 139:	e1 04                	loope  13f <_init-0x4002b1>
 13b:	01 ba 02 0f 00 01    	add    DWORD PTR [rdx+0x1000f02],edi
 141:	01 04 03             	add    DWORD PTR [rbx+rax*1],eax
 144:	00 09                	add    BYTE PTR [rcx],cl
 146:	02 46 05             	add    al,BYTE PTR [rsi+0x5]
 149:	40 00 00             	add    BYTE PTR [rax],al
 14c:	00 00                	add    BYTE PTR [rax],al
 14e:	00 14 e4             	add    BYTE PTR [rsp+riz*8],dl
 151:	e5 04                	in     eax,0x4
 153:	01 03                	add    DWORD PTR [rbx],eax
 155:	ed                   	in     eax,dx
 156:	02 08                	add    cl,BYTE PTR [rax]
 158:	82                   	(bad)  
 159:	08 25 03 8c 01 08    	or     BYTE PTR [rip+0x8018c03],ah        # 8018d62 <_end+0x7a17d22>
 15f:	90                   	nop
 160:	04 03                	add    al,0x3
 162:	03 88 7c ac 04 01    	add    ecx,DWORD PTR [rax+0x104ac7c]
 168:	03 e9                	add    ebp,ecx
 16a:	03 08                	add    ecx,DWORD PTR [rax]
 16c:	4a 03 64 02 2b       	add    rsp,QWORD PTR [rdx+r8*1+0x2b]
 171:	01 08                	add    DWORD PTR [rax],ecx
 173:	21 08                	and    DWORD PTR [rax],ecx
 175:	25 03 ab 7f 08       	and    eax,0x87fab03
 17a:	f2 08 24 04          	repnz or BYTE PTR [rsp+rax*1],ah
 17e:	03 03                	add    eax,DWORD PTR [rbx]
 180:	82                   	(bad)  
 181:	7d 66                	jge    1e9 <_init-0x400207>
 183:	02 16                	add    dl,BYTE PTR [rsi]
 185:	00 01                	add    BYTE PTR [rcx],al
 187:	01                   	.byte 0x1

Disassembly of section .debug_str:

0000000000000000 <.debug_str>:
   0:	61                   	(bad)  
   1:	74 6f                	je     72 <_init-0x40037e>
   3:	6d                   	ins    DWORD PTR es:[rdi],dx
   4:	69 63 3c 69 6e 74 3e 	imul   esp,DWORD PTR [rbx+0x3c],0x3e746e69
   b:	00 47 4e             	add    BYTE PTR [rdi+0x4e],al
   e:	55                   	push   rbp
   f:	20 43 2b             	and    BYTE PTR [rbx+0x2b],al
  12:	2b 31                	sub    esi,DWORD PTR [rcx]
  14:	34 20                	xor    al,0x20
  16:	35 2e 34 2e 30       	xor    eax,0x302e342e
  1b:	20 32                	and    BYTE PTR [rdx],dh
  1d:	30 31                	xor    BYTE PTR [rcx],dh
  1f:	36 30 36             	xor    BYTE PTR ss:[rsi],dh
  22:	30 39                	xor    BYTE PTR [rcx],bh
  24:	20 2d 6d 74 75 6e    	and    BYTE PTR [rip+0x6e75746d],ch        # 6e757497 <_end+0x6e156457>
  2a:	65 3d 67 65 6e 65    	gs cmp eax,0x656e6567
  30:	72 69                	jb     9b <_init-0x400355>
  32:	63 20                	movsxd esp,DWORD PTR [rax]
  34:	2d 6d 61 72 63       	sub    eax,0x6372616d
  39:	68 3d 78 38 36       	push   0x3638783d
  3e:	2d 36 34 20 2d       	sub    eax,0x2d203436
  43:	67 20 2d 4f 30 20 2d 	and    BYTE PTR [eip+0x2d20304f],ch        # 2d203099 <_end+0x2cc02059>
  4a:	73 74                	jae    c0 <_init-0x400330>
  4c:	64 3d 63 2b 2b 31    	fs cmp eax,0x312b2b63
  52:	34 20                	xor    al,0x20
  54:	2d 66 73 74 61       	sub    eax,0x61747366
  59:	63 6b 2d             	movsxd ebp,DWORD PTR [rbx+0x2d]
  5c:	70 72                	jo     d0 <_init-0x400320>
  5e:	6f                   	outs   dx,DWORD PTR ds:[rsi]
  5f:	74 65                	je     c6 <_init-0x40032a>
  61:	63 74 6f 72          	movsxd esi,DWORD PTR [rdi+rbp*2+0x72]
  65:	2d 73 74 72 6f       	sub    eax,0x6f727473
  6a:	6e                   	outs   dx,BYTE PTR ds:[rsi]
  6b:	67 00 5f 5a          	add    BYTE PTR [edi+0x5a],bl
  6f:	4e 53                	rex.WRX push rbx
  71:	74 31                	je     a4 <_init-0x40034c>
  73:	33 5f 5f             	xor    ebx,DWORD PTR [rdi+0x5f]
  76:	61                   	(bad)  
  77:	74 6f                	je     e8 <_init-0x400308>
  79:	6d                   	ins    DWORD PTR es:[rdi],dx
  7a:	69 63 5f 62 61 73 65 	imul   esp,DWORD PTR [rbx+0x5f],0x65736162
  81:	49 69 45 6d 49 45 69 	imul   rax,QWORD PTR [r13+0x6d],0x694549
  88:	00 
  89:	65 78 63             	gs js  ef <_init-0x400301>
  8c:	68 61 6e 67 65       	push   0x65676e61
  91:	00 6d 65             	add    BYTE PTR [rbp+0x65],ch
  94:	6d                   	ins    DWORD PTR es:[rdi],dx
  95:	6f                   	outs   dx,DWORD PTR ds:[rsi]
  96:	72 79                	jb     111 <_init-0x4002df>
  98:	5f                   	pop    rdi
  99:	6f                   	outs   dx,DWORD PTR ds:[rsi]
  9a:	72 64                	jb     100 <_init-0x4002f0>
  9c:	65 72 5f             	gs jb  fe <_init-0x4002f2>
  9f:	72 65                	jb     106 <_init-0x4002ea>
  a1:	6c                   	ins    BYTE PTR es:[rdi],dx
  a2:	65 61                	gs (bad) 
  a4:	73 65                	jae    10b <_init-0x4002e5>
  a6:	00 5f 5f             	add    BYTE PTR [rdi+0x5f],bl
  a9:	69 6e 74 65 67 72 61 	imul   ebp,DWORD PTR [rsi+0x74],0x61726765
  b0:	6c                   	ins    BYTE PTR es:[rdi],dx
  b1:	5f                   	pop    rdi
  b2:	74 79                	je     12d <_init-0x4002c3>
  b4:	70 65                	jo     11b <_init-0x4002d5>
  b6:	00 5f 5a             	add    BYTE PTR [rdi+0x5a],bl
  b9:	4e 56                	rex.WRX push rsi
  bb:	53                   	push   rbx
  bc:	74 31                	je     ef <_init-0x400301>
  be:	33 5f 5f             	xor    ebx,DWORD PTR [rdi+0x5f]
  c1:	61                   	(bad)  
  c2:	74 6f                	je     133 <_init-0x4002bd>
  c4:	6d                   	ins    DWORD PTR es:[rdi],dx
  c5:	69 63 5f 62 61 73 65 	imul   esp,DWORD PTR [rbx+0x5f],0x65736162
  cc:	49 69 45 39 66 65 74 	imul   rax,QWORD PTR [r13+0x39],0x63746566
  d3:	63 
  d4:	68 5f 73 75 62       	push   0x6275735f
  d9:	45 69 53 74 31 32 6d 	imul   r10d,DWORD PTR [r11+0x74],0x656d3231
  e0:	65 
  e1:	6d                   	ins    DWORD PTR es:[rdi],dx
  e2:	6f                   	outs   dx,DWORD PTR ds:[rsi]
  e3:	72 79                	jb     15e <_init-0x400292>
  e5:	5f                   	pop    rdi
  e6:	6f                   	outs   dx,DWORD PTR ds:[rsi]
  e7:	72 64                	jb     14d <_init-0x4002a3>
  e9:	65 72 00             	gs jb  ec <_init-0x400304>
  ec:	5f                   	pop    rdi
  ed:	5f                   	pop    rdi
  ee:	63 78 78             	movsxd edi,DWORD PTR [rax+0x78]
  f1:	31 31                	xor    DWORD PTR [rcx],esi
  f3:	00 5f 5a             	add    BYTE PTR [rdi+0x5a],bl
  f6:	4e 56                	rex.WRX push rsi
  f8:	53                   	push   rbx
  f9:	74 31                	je     12c <_init-0x4002c4>
  fb:	33 5f 5f             	xor    ebx,DWORD PTR [rdi+0x5f]
  fe:	61                   	(bad)  
  ff:	74 6f                	je     170 <_init-0x400280>
 101:	6d                   	ins    DWORD PTR es:[rdi],dx
 102:	69 63 5f 62 61 73 65 	imul   esp,DWORD PTR [rbx+0x5f],0x65736162
 109:	49 69 45 65 4f 45 69 	imul   rax,QWORD PTR [r13+0x65],0x69454f
 110:	00 
 111:	5f                   	pop    rdi
 112:	5f                   	pop    rdi
 113:	63 6d 70             	movsxd ebp,DWORD PTR [rbp+0x70]
 116:	65 78 63             	gs js  17c <_init-0x400274>
 119:	68 5f 66 61 69       	push   0x6961665f
 11e:	6c                   	ins    BYTE PTR es:[rdi],dx
 11f:	75 72                	jne    193 <_init-0x40025d>
 121:	65 5f                	gs pop rdi
 123:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 124:	72 64                	jb     18a <_init-0x400266>
 126:	65 72 00             	gs jb  129 <_init-0x4002c7>
 129:	5f                   	pop    rdi
 12a:	5f                   	pop    rdi
 12b:	61                   	(bad)  
 12c:	74 6f                	je     19d <_init-0x400253>
 12e:	6d                   	ins    DWORD PTR es:[rdi],dx
 12f:	69 63 5f 62 61 73 65 	imul   esp,DWORD PTR [rbx+0x5f],0x65736162
 136:	3c 69                	cmp    al,0x69
 138:	6e                   	outs   dx,BYTE PTR ds:[rsi]
 139:	74 3e                	je     179 <_init-0x400277>
 13b:	00 6c 6f 6e          	add    BYTE PTR [rdi+rbp*2+0x6e],ch
 13f:	67 20 6c 6f 6e       	and    BYTE PTR [edi+ebp*2+0x6e],ch
 144:	67 20 75 6e          	and    BYTE PTR [ebp+0x6e],dh
 148:	73 69                	jae    1b3 <_init-0x40023d>
 14a:	67 6e                	outs   dx,BYTE PTR ds:[esi]
 14c:	65 64 20 69 6e       	gs and BYTE PTR fs:[rcx+0x6e],ch
 151:	74 00                	je     153 <_init-0x40029d>
 153:	66 65 74 63          	data16 gs je 1ba <_init-0x400236>
 157:	68 5f 6f 72 00       	push   0x726f5f
 15c:	5f                   	pop    rdi
 15d:	5a                   	pop    rdx
 15e:	4e 56                	rex.WRX push rsi
 160:	53                   	push   rbx
 161:	74 31                	je     194 <_init-0x40025c>
 163:	33 5f 5f             	xor    ebx,DWORD PTR [rdi+0x5f]
 166:	61                   	(bad)  
 167:	74 6f                	je     1d8 <_init-0x400218>
 169:	6d                   	ins    DWORD PTR es:[rdi],dx
 16a:	69 63 5f 62 61 73 65 	imul   esp,DWORD PTR [rbx+0x5f],0x65736162
 171:	49 69 45 6d 6d 45 69 	imul   rax,QWORD PTR [r13+0x6d],0x69456d
 178:	00 
 179:	5f                   	pop    rdi
 17a:	5a                   	pop    rdx
 17b:	4e 53                	rex.WRX push rbx
 17d:	74 31                	je     1b0 <_init-0x400240>
 17f:	33 5f 5f             	xor    ebx,DWORD PTR [rdi+0x5f]
 182:	61                   	(bad)  
 183:	74 6f                	je     1f4 <_init-0x4001fc>
 185:	6d                   	ins    DWORD PTR es:[rdi],dx
 186:	69 63 5f 62 61 73 65 	imul   esp,DWORD PTR [rbx+0x5f],0x65736162
 18d:	49 69 45 32 33 63 6f 	imul   rax,QWORD PTR [r13+0x32],0x6d6f6333
 194:	6d 
 195:	70 61                	jo     1f8 <_init-0x4001f8>
 197:	72 65                	jb     1fe <_init-0x4001f2>
 199:	5f                   	pop    rdi
 19a:	65 78 63             	gs js  200 <_init-0x4001f0>
 19d:	68 61 6e 67 65       	push   0x65676e61
 1a2:	5f                   	pop    rdi
 1a3:	73 74                	jae    219 <_init-0x4001d7>
 1a5:	72 6f                	jb     216 <_init-0x4001da>
 1a7:	6e                   	outs   dx,BYTE PTR ds:[rsi]
 1a8:	67 45 52             	addr32 rex.RB push r10
 1ab:	69 69 53 74 31 32 6d 	imul   ebp,DWORD PTR [rcx+0x53],0x6d323174
 1b2:	65 6d                	gs ins DWORD PTR es:[rdi],dx
 1b4:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 1b5:	72 79                	jb     230 <_init-0x4001c0>
 1b7:	5f                   	pop    rdi
 1b8:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 1b9:	72 64                	jb     21f <_init-0x4001d1>
 1bb:	65 72 53             	gs jb  211 <_init-0x4001df>
 1be:	32 5f 00             	xor    bl,BYTE PTR [rdi+0x0]
 1c1:	5f                   	pop    rdi
 1c2:	5a                   	pop    rdx
 1c3:	4e 53                	rex.WRX push rbx
 1c5:	74 31                	je     1f8 <_init-0x4001f8>
 1c7:	33 5f 5f             	xor    ebx,DWORD PTR [rdi+0x5f]
 1ca:	61                   	(bad)  
 1cb:	74 6f                	je     23c <_init-0x4001b4>
 1cd:	6d                   	ins    DWORD PTR es:[rdi],dx
 1ce:	69 63 5f 62 61 73 65 	imul   esp,DWORD PTR [rbx+0x5f],0x65736162
 1d5:	49 69 45 70 4c 45 69 	imul   rax,QWORD PTR [r13+0x70],0x69454c
 1dc:	00 
 1dd:	6c                   	ins    BYTE PTR es:[rdi],dx
 1de:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 1df:	6e                   	outs   dx,BYTE PTR ds:[rsi]
 1e0:	67 20 6c 6f 6e       	and    BYTE PTR [edi+ebp*2+0x6e],ch
 1e5:	67 20 69 6e          	and    BYTE PTR [ecx+0x6e],ch
 1e9:	74 00                	je     1eb <_init-0x400205>
 1eb:	5f                   	pop    rdi
 1ec:	5a                   	pop    rdx
 1ed:	4e 53                	rex.WRX push rbx
 1ef:	74 36                	je     227 <_init-0x4001c9>
 1f1:	61                   	(bad)  
 1f2:	74 6f                	je     263 <_init-0x40018d>
 1f4:	6d                   	ins    DWORD PTR es:[rdi],dx
 1f5:	69 63 49 69 45 61 53 	imul   esp,DWORD PTR [rbx+0x49],0x53614569
 1fc:	45 52                	rex.RB push r10
 1fe:	4b 53                	rex.WXB push r11
 200:	30 5f 00             	xor    BYTE PTR [rdi+0x0],bl
 203:	5f                   	pop    rdi
 204:	5a                   	pop    rdx
 205:	4e 53                	rex.WRX push rbx
 207:	74 31                	je     23a <_init-0x4001b6>
 209:	33 5f 5f             	xor    ebx,DWORD PTR [rdi+0x5f]
 20c:	61                   	(bad)  
 20d:	74 6f                	je     27e <_init-0x400172>
 20f:	6d                   	ins    DWORD PTR es:[rdi],dx
 210:	69 63 5f 62 61 73 65 	imul   esp,DWORD PTR [rbx+0x5f],0x65736162
 217:	49 69 45 32 31 63 6f 	imul   rax,QWORD PTR [r13+0x32],0x6d6f6331
 21e:	6d 
 21f:	70 61                	jo     282 <_init-0x40016e>
 221:	72 65                	jb     288 <_init-0x400168>
 223:	5f                   	pop    rdi
 224:	65 78 63             	gs js  28a <_init-0x400166>
 227:	68 61 6e 67 65       	push   0x65676e61
 22c:	5f                   	pop    rdi
 22d:	77 65                	ja     294 <_init-0x40015c>
 22f:	61                   	(bad)  
 230:	6b 45 52 69          	imul   eax,DWORD PTR [rbp+0x52],0x69
 234:	69 53 74 31 32 6d 65 	imul   edx,DWORD PTR [rbx+0x74],0x656d3231
 23b:	6d                   	ins    DWORD PTR es:[rdi],dx
 23c:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 23d:	72 79                	jb     2b8 <_init-0x400138>
 23f:	5f                   	pop    rdi
 240:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 241:	72 64                	jb     2a7 <_init-0x400149>
 243:	65 72 53             	gs jb  299 <_init-0x400157>
 246:	32 5f 00             	xor    bl,BYTE PTR [rdi+0x0]
 249:	5f                   	pop    rdi
 24a:	5f                   	pop    rdi
 24b:	6d                   	ins    DWORD PTR es:[rdi],dx
 24c:	31 00                	xor    DWORD PTR [rax],eax
 24e:	5f                   	pop    rdi
 24f:	5f                   	pop    rdi
 250:	6d                   	ins    DWORD PTR es:[rdi],dx
 251:	32 00                	xor    al,BYTE PTR [rax]
 253:	5f                   	pop    rdi
 254:	5a                   	pop    rdx
 255:	4e 56                	rex.WRX push rsi
 257:	4b 53                	rex.WXB push r11
 259:	74 31                	je     28c <_init-0x400164>
 25b:	33 5f 5f             	xor    ebx,DWORD PTR [rdi+0x5f]
 25e:	61                   	(bad)  
 25f:	74 6f                	je     2d0 <_init-0x400120>
 261:	6d                   	ins    DWORD PTR es:[rdi],dx
 262:	69 63 5f 62 61 73 65 	imul   esp,DWORD PTR [rbx+0x5f],0x65736162
 269:	49 69 45 63 76 69 45 	imul   rax,QWORD PTR [r13+0x63],0x76456976
 270:	76 
 271:	00 6f 70             	add    BYTE PTR [rdi+0x70],ch
 274:	65 72 61             	gs jb  2d8 <_init-0x400118>
 277:	74 6f                	je     2e8 <_init-0x400108>
 279:	72 7c                	jb     2f7 <_init-0x4000f9>
 27b:	3d 00 63 68 61       	cmp    eax,0x61686300
 280:	72 31                	jb     2b3 <_init-0x40013d>
 282:	36 5f                	ss pop rdi
 284:	74 00                	je     286 <_init-0x40016a>
 286:	5f                   	pop    rdi
 287:	5a                   	pop    rdx
 288:	4e 56                	rex.WRX push rsi
 28a:	53                   	push   rbx
 28b:	74 31                	je     2be <_init-0x400132>
 28d:	33 5f 5f             	xor    ebx,DWORD PTR [rdi+0x5f]
 290:	61                   	(bad)  
 291:	74 6f                	je     302 <_init-0x4000ee>
 293:	6d                   	ins    DWORD PTR es:[rdi],dx
 294:	69 63 5f 62 61 73 65 	imul   esp,DWORD PTR [rbx+0x5f],0x65736162
 29b:	49 69 45 6d 6d 45 76 	imul   rax,QWORD PTR [r13+0x6d],0x76456d
 2a2:	00 
 2a3:	5f                   	pop    rdi
 2a4:	5a                   	pop    rdx
 2a5:	4e 53                	rex.WRX push rbx
 2a7:	74 31                	je     2da <_init-0x400116>
 2a9:	33 5f 5f             	xor    ebx,DWORD PTR [rdi+0x5f]
 2ac:	61                   	(bad)  
 2ad:	74 6f                	je     31e <_init-0x4000d2>
 2af:	6d                   	ins    DWORD PTR es:[rdi],dx
 2b0:	69 63 5f 62 61 73 65 	imul   esp,DWORD PTR [rbx+0x5f],0x65736162
 2b7:	49 69 45 43 34 45 52 	imul   rax,QWORD PTR [r13+0x43],0x4b524534
 2be:	4b 
 2bf:	53                   	push   rbx
 2c0:	30 5f 00             	xor    BYTE PTR [rdi+0x0],bl
 2c3:	5f                   	pop    rdi
 2c4:	53                   	push   rbx
 2c5:	5f                   	pop    rdi
 2c6:	61                   	(bad)  
 2c7:	6c                   	ins    BYTE PTR es:[rdi],dx
 2c8:	69 67 6e 6d 65 6e 74 	imul   esp,DWORD PTR [rdi+0x6e],0x746e656d
 2cf:	00 5f 5a             	add    BYTE PTR [rdi+0x5a],bl
 2d2:	4e 53                	rex.WRX push rbx
 2d4:	74 31                	je     307 <_init-0x4000e9>
 2d6:	33 5f 5f             	xor    ebx,DWORD PTR [rdi+0x5f]
 2d9:	61                   	(bad)  
 2da:	74 6f                	je     34b <_init-0x4000a5>
 2dc:	6d                   	ins    DWORD PTR es:[rdi],dx
 2dd:	69 63 5f 62 61 73 65 	imul   esp,DWORD PTR [rbx+0x5f],0x65736162
 2e4:	49 69 45 35 73 74 6f 	imul   rax,QWORD PTR [r13+0x35],0x726f7473
 2eb:	72 
 2ec:	65 45 69 53 74 31 32 	imul   r10d,DWORD PTR gs:[r11+0x74],0x656d3231
 2f3:	6d 65 
 2f5:	6d                   	ins    DWORD PTR es:[rdi],dx
 2f6:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 2f7:	72 79                	jb     372 <_init-0x40007e>
 2f9:	5f                   	pop    rdi
 2fa:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 2fb:	72 64                	jb     361 <_init-0x40008f>
 2fd:	65 72 00             	gs jb  300 <_init-0x4000f0>
 300:	7e 5f                	jle    361 <_init-0x40008f>
 302:	5f                   	pop    rdi
 303:	61                   	(bad)  
 304:	74 6f                	je     375 <_init-0x40007b>
 306:	6d                   	ins    DWORD PTR es:[rdi],dx
 307:	69 63 5f 62 61 73 65 	imul   esp,DWORD PTR [rbx+0x5f],0x65736162
 30e:	00 5f 5a             	add    BYTE PTR [rdi+0x5a],bl
 311:	4e 56                	rex.WRX push rsi
 313:	53                   	push   rbx
 314:	74 31                	je     347 <_init-0x4000a9>
 316:	33 5f 5f             	xor    ebx,DWORD PTR [rdi+0x5f]
 319:	61                   	(bad)  
 31a:	74 6f                	je     38b <_init-0x400065>
 31c:	6d                   	ins    DWORD PTR es:[rdi],dx
 31d:	69 63 5f 62 61 73 65 	imul   esp,DWORD PTR [rbx+0x5f],0x65736162
 324:	49 69 45 61 53 45 52 	imul   rax,QWORD PTR [r13+0x61],0x4b524553
 32b:	4b 
 32c:	53                   	push   rbx
 32d:	30 5f 00             	xor    BYTE PTR [rdi+0x0],bl
 330:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 331:	70 65                	jo     398 <_init-0x400058>
 333:	72 61                	jb     396 <_init-0x40005a>
 335:	74 6f                	je     3a6 <_init-0x40004a>
 337:	72 5e                	jb     397 <_init-0x400059>
 339:	3d 00 74 68 69       	cmp    eax,0x69687400
 33e:	73 00                	jae    340 <_init-0x4000b0>
 340:	5f                   	pop    rdi
 341:	5a                   	pop    rdx
 342:	4e 56                	rex.WRX push rsi
 344:	53                   	push   rbx
 345:	74 31                	je     378 <_init-0x400078>
 347:	33 5f 5f             	xor    ebx,DWORD PTR [rdi+0x5f]
 34a:	61                   	(bad)  
 34b:	74 6f                	je     3bc <_init-0x400034>
 34d:	6d                   	ins    DWORD PTR es:[rdi],dx
 34e:	69 63 5f 62 61 73 65 	imul   esp,DWORD PTR [rbx+0x5f],0x65736162
 355:	49 69 45 6d 49 45 69 	imul   rax,QWORD PTR [r13+0x6d],0x694549
 35c:	00 
 35d:	5f                   	pop    rdi
 35e:	5a                   	pop    rdx
 35f:	4e 53                	rex.WRX push rbx
 361:	74 31                	je     394 <_init-0x40005c>
 363:	33 5f 5f             	xor    ebx,DWORD PTR [rdi+0x5f]
 366:	61                   	(bad)  
 367:	74 6f                	je     3d8 <_init-0x400018>
 369:	6d                   	ins    DWORD PTR es:[rdi],dx
 36a:	69 63 5f 62 61 73 65 	imul   esp,DWORD PTR [rbx+0x5f],0x65736162
 371:	49 69 45 39 66 65 74 	imul   rax,QWORD PTR [r13+0x39],0x63746566
 378:	63 
 379:	68 5f 61 64 64       	push   0x6464615f
 37e:	45 69 53 74 31 32 6d 	imul   r10d,DWORD PTR [r11+0x74],0x656d3231
 385:	65 
 386:	6d                   	ins    DWORD PTR es:[rdi],dx
 387:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 388:	72 79                	jb     403 <_init-0x3fffed>
 38a:	5f                   	pop    rdi
 38b:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 38c:	72 64                	jb     3f2 <_init-0x3ffffe>
 38e:	65 72 00             	gs jb  391 <_init-0x40005f>
 391:	5f                   	pop    rdi
 392:	5a                   	pop    rdx
 393:	4e 56                	rex.WRX push rsi
 395:	53                   	push   rbx
 396:	74 31                	je     3c9 <_init-0x400027>
 398:	33 5f 5f             	xor    ebx,DWORD PTR [rdi+0x5f]
 39b:	61                   	(bad)  
 39c:	74 6f                	je     40d <_init-0x3fffe3>
 39e:	6d                   	ins    DWORD PTR es:[rdi],dx
 39f:	69 63 5f 62 61 73 65 	imul   esp,DWORD PTR [rbx+0x5f],0x65736162
 3a6:	49 69 45 35 73 74 6f 	imul   rax,QWORD PTR [r13+0x35],0x726f7473
 3ad:	72 
 3ae:	65 45 69 53 74 31 32 	imul   r10d,DWORD PTR gs:[r11+0x74],0x656d3231
 3b5:	6d 65 
 3b7:	6d                   	ins    DWORD PTR es:[rdi],dx
 3b8:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 3b9:	72 79                	jb     434 <_init-0x3fffbc>
 3bb:	5f                   	pop    rdi
 3bc:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 3bd:	72 64                	jb     423 <_init-0x3fffcd>
 3bf:	65 72 00             	gs jb  3c2 <_init-0x40002e>
 3c2:	5f                   	pop    rdi
 3c3:	5a                   	pop    rdx
 3c4:	4e 56                	rex.WRX push rsi
 3c6:	53                   	push   rbx
 3c7:	74 31                	je     3fa <_init-0x3ffff6>
 3c9:	33 5f 5f             	xor    ebx,DWORD PTR [rdi+0x5f]
 3cc:	61                   	(bad)  
 3cd:	74 6f                	je     43e <_init-0x3fffb2>
 3cf:	6d                   	ins    DWORD PTR es:[rdi],dx
 3d0:	69 63 5f 62 61 73 65 	imul   esp,DWORD PTR [rbx+0x5f],0x65736162
 3d7:	49 69 45 39 66 65 74 	imul   rax,QWORD PTR [r13+0x39],0x63746566
 3de:	63 
 3df:	68 5f 61 6e 64       	push   0x646e615f
 3e4:	45 69 53 74 31 32 6d 	imul   r10d,DWORD PTR [r11+0x74],0x656d3231
 3eb:	65 
 3ec:	6d                   	ins    DWORD PTR es:[rdi],dx
 3ed:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 3ee:	72 79                	jb     469 <_init-0x3fff87>
 3f0:	5f                   	pop    rdi
 3f1:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 3f2:	72 64                	jb     458 <_init-0x3fff98>
 3f4:	65 72 00             	gs jb  3f7 <_init-0x3ffff9>
 3f7:	5f                   	pop    rdi
 3f8:	5a                   	pop    rdx
 3f9:	4e 53                	rex.WRX push rbx
 3fb:	74 31                	je     42e <_init-0x3fffc2>
 3fd:	33 5f 5f             	xor    ebx,DWORD PTR [rdi+0x5f]
 400:	61                   	(bad)  
 401:	74 6f                	je     472 <_init-0x3fff7e>
 403:	6d                   	ins    DWORD PTR es:[rdi],dx
 404:	69 63 5f 62 61 73 65 	imul   esp,DWORD PTR [rbx+0x5f],0x65736162
 40b:	49 69 45 39 66 65 74 	imul   rax,QWORD PTR [r13+0x39],0x63746566
 412:	63 
 413:	68 5f 73 75 62       	push   0x6275735f
 418:	45 69 53 74 31 32 6d 	imul   r10d,DWORD PTR [r11+0x74],0x656d3231
 41f:	65 
 420:	6d                   	ins    DWORD PTR es:[rdi],dx
 421:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 422:	72 79                	jb     49d <_init-0x3fff53>
 424:	5f                   	pop    rdi
 425:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 426:	72 64                	jb     48c <_init-0x3fff64>
 428:	65 72 00             	gs jb  42b <_init-0x3fffc5>
 42b:	6d                   	ins    DWORD PTR es:[rdi],dx
 42c:	65 6d                	gs ins DWORD PTR es:[rdi],dx
 42e:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 42f:	72 79                	jb     4aa <_init-0x3fff46>
 431:	5f                   	pop    rdi
 432:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 433:	72 64                	jb     499 <_init-0x3fff57>
 435:	65 72 5f             	gs jb  497 <_init-0x3fff59>
 438:	73 65                	jae    49f <_init-0x3fff51>
 43a:	71 5f                	jno    49b <_init-0x3fff55>
 43c:	63 73 74             	movsxd esi,DWORD PTR [rbx+0x74]
 43f:	00 5f 5a             	add    BYTE PTR [rdi+0x5a],bl
 442:	4e 53                	rex.WRX push rbx
 444:	74 36                	je     47c <_init-0x3fff74>
 446:	61                   	(bad)  
 447:	74 6f                	je     4b8 <_init-0x3fff38>
 449:	6d                   	ins    DWORD PTR es:[rdi],dx
 44a:	69 63 49 69 45 43 32 	imul   esp,DWORD PTR [rbx+0x49],0x32434569
 451:	45 76 00             	rex.RB jbe 454 <_init-0x3fff9c>
 454:	5f                   	pop    rdi
 455:	5a                   	pop    rdx
 456:	4e                   	rex.WRX
 457:	4b 53                	rex.WXB push r11
 459:	74 31                	je     48c <_init-0x3fff64>
 45b:	33 5f 5f             	xor    ebx,DWORD PTR [rdi+0x5f]
 45e:	61                   	(bad)  
 45f:	74 6f                	je     4d0 <_init-0x3fff20>
 461:	6d                   	ins    DWORD PTR es:[rdi],dx
 462:	69 63 5f 62 61 73 65 	imul   esp,DWORD PTR [rbx+0x5f],0x65736162
 469:	49 69 45 63 76 69 45 	imul   rax,QWORD PTR [r13+0x63],0x76456976
 470:	76 
 471:	00 61 74             	add    BYTE PTR [rcx+0x74],ah
 474:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 475:	6d                   	ins    DWORD PTR es:[rdi],dx
 476:	69 63 2e 63 70 70 00 	imul   esp,DWORD PTR [rbx+0x2e],0x707063
 47d:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 47e:	70 65                	jo     4e5 <_init-0x3fff0b>
 480:	72 61                	jb     4e3 <_init-0x3fff0d>
 482:	74 6f                	je     4f3 <_init-0x3ffefd>
 484:	72 20                	jb     4a6 <_init-0x3fff4a>
 486:	73 74                	jae    4fc <_init-0x3ffef4>
 488:	64 3a 3a             	cmp    bh,BYTE PTR fs:[rdx]
 48b:	5f                   	pop    rdi
 48c:	5f                   	pop    rdi
 48d:	61                   	(bad)  
 48e:	74 6f                	je     4ff <_init-0x3ffef1>
 490:	6d                   	ins    DWORD PTR es:[rdi],dx
 491:	69 63 5f 62 61 73 65 	imul   esp,DWORD PTR [rbx+0x5f],0x65736162
 498:	3c 69                	cmp    al,0x69
 49a:	6e                   	outs   dx,BYTE PTR ds:[rsi]
 49b:	74 3e                	je     4db <_init-0x3fff15>
 49d:	3a 3a                	cmp    bh,BYTE PTR [rdx]
 49f:	5f                   	pop    rdi
 4a0:	5f                   	pop    rdi
 4a1:	69 6e 74 5f 74 79 70 	imul   ebp,DWORD PTR [rsi+0x74],0x7079745f
 4a8:	65 00 2f             	add    BYTE PTR gs:[rdi],ch
 4ab:	68 6f 6d 65 2f       	push   0x2f656d6f
 4b0:	77 6f                	ja     521 <_init-0x3ffecf>
 4b2:	33 6b 69             	xor    ebp,DWORD PTR [rbx+0x69]
 4b5:	65 2f                	gs (bad) 
 4b7:	63 78 78             	movsxd edi,DWORD PTR [rax+0x78]
 4ba:	44 6f                	rex.R outs dx,DWORD PTR ds:[rsi]
 4bc:	6a 6f                	push   0x6f
 4be:	2f                   	(bad)  
 4bf:	61                   	(bad)  
 4c0:	73 6d                	jae    52f <_init-0x3ffec1>
 4c2:	00 63 6f             	add    BYTE PTR [rbx+0x6f],ah
 4c5:	6d                   	ins    DWORD PTR es:[rdi],dx
 4c6:	70 61                	jo     529 <_init-0x3ffec7>
 4c8:	72 65                	jb     52f <_init-0x3ffec1>
 4ca:	5f                   	pop    rdi
 4cb:	65 78 63             	gs js  531 <_init-0x3ffebf>
 4ce:	68 61 6e 67 65       	push   0x65676e61
 4d3:	5f                   	pop    rdi
 4d4:	73 74                	jae    54a <_init-0x3ffea6>
 4d6:	72 6f                	jb     547 <_init-0x3ffea9>
 4d8:	6e                   	outs   dx,BYTE PTR ds:[rsi]
 4d9:	67 00 5f 5a          	add    BYTE PTR [edi+0x5a],bl
 4dd:	4e 53                	rex.WRX push rbx
 4df:	74 31                	je     512 <_init-0x3ffede>
 4e1:	33 5f 5f             	xor    ebx,DWORD PTR [rdi+0x5f]
 4e4:	61                   	(bad)  
 4e5:	74 6f                	je     556 <_init-0x3ffe9a>
 4e7:	6d                   	ins    DWORD PTR es:[rdi],dx
 4e8:	69 63 5f 62 61 73 65 	imul   esp,DWORD PTR [rbx+0x5f],0x65736162
 4ef:	49 69 45 32 33 63 6f 	imul   rax,QWORD PTR [r13+0x32],0x6d6f6333
 4f6:	6d 
 4f7:	70 61                	jo     55a <_init-0x3ffe96>
 4f9:	72 65                	jb     560 <_init-0x3ffe90>
 4fb:	5f                   	pop    rdi
 4fc:	65 78 63             	gs js  562 <_init-0x3ffe8e>
 4ff:	68 61 6e 67 65       	push   0x65676e61
 504:	5f                   	pop    rdi
 505:	73 74                	jae    57b <_init-0x3ffe75>
 507:	72 6f                	jb     578 <_init-0x3ffe78>
 509:	6e                   	outs   dx,BYTE PTR ds:[rsi]
 50a:	67 45 52             	addr32 rex.RB push r10
 50d:	69 69 53 74 31 32 6d 	imul   ebp,DWORD PTR [rcx+0x53],0x6d323174
 514:	65 6d                	gs ins DWORD PTR es:[rdi],dx
 516:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 517:	72 79                	jb     592 <_init-0x3ffe5e>
 519:	5f                   	pop    rdi
 51a:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 51b:	72 64                	jb     581 <_init-0x3ffe6f>
 51d:	65 72 00             	gs jb  520 <_init-0x3ffed0>
 520:	5f                   	pop    rdi
 521:	5a                   	pop    rdx
 522:	4e 53                	rex.WRX push rbx
 524:	74 31                	je     557 <_init-0x3ffe99>
 526:	33 5f 5f             	xor    ebx,DWORD PTR [rdi+0x5f]
 529:	61                   	(bad)  
 52a:	74 6f                	je     59b <_init-0x3ffe55>
 52c:	6d                   	ins    DWORD PTR es:[rdi],dx
 52d:	69 63 5f 62 61 73 65 	imul   esp,DWORD PTR [rbx+0x5f],0x65736162
 534:	49 69 45 44 34 45 76 	imul   rax,QWORD PTR [r13+0x44],0x764534
 53b:	00 
 53c:	5f                   	pop    rdi
 53d:	5a                   	pop    rdx
 53e:	4e 56                	rex.WRX push rsi
 540:	53                   	push   rbx
 541:	74 36                	je     579 <_init-0x3ffe77>
 543:	61                   	(bad)  
 544:	74 6f                	je     5b5 <_init-0x3ffe3b>
 546:	6d                   	ins    DWORD PTR es:[rdi],dx
 547:	69 63 49 69 45 61 53 	imul   esp,DWORD PTR [rbx+0x49],0x53614569
 54e:	45 52                	rex.RB push r10
 550:	4b 53                	rex.WXB push r11
 552:	30 5f 00             	xor    BYTE PTR [rdi+0x0],bl
 555:	5f                   	pop    rdi
 556:	5a                   	pop    rdx
 557:	4e 56                	rex.WRX push rsi
 559:	4b 53                	rex.WXB push r11
 55b:	74 31                	je     58e <_init-0x3ffe62>
 55d:	33 5f 5f             	xor    ebx,DWORD PTR [rdi+0x5f]
 560:	61                   	(bad)  
 561:	74 6f                	je     5d2 <_init-0x3ffe1e>
 563:	6d                   	ins    DWORD PTR es:[rdi],dx
 564:	69 63 5f 62 61 73 65 	imul   esp,DWORD PTR [rbx+0x5f],0x65736162
 56b:	49 69 45 31 32 69 73 	imul   rax,QWORD PTR [r13+0x31],0x5f736932
 572:	5f 
 573:	6c                   	ins    BYTE PTR es:[rdi],dx
 574:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 575:	63 6b 5f             	movsxd ebp,DWORD PTR [rbx+0x5f]
 578:	66 72 65             	data16 jb 5e0 <_init-0x3ffe10>
 57b:	65 45 76 00          	gs rex.RB jbe 57f <_init-0x3ffe71>
 57f:	72 61                	jb     5e2 <_init-0x3ffe0e>
 581:	6e                   	outs   dx,BYTE PTR ds:[rsi]
 582:	64 00 5f 5a          	add    BYTE PTR fs:[rdi+0x5a],bl
 586:	4e 53                	rex.WRX push rbx
 588:	74 31                	je     5bb <_init-0x3ffe35>
 58a:	33 5f 5f             	xor    ebx,DWORD PTR [rdi+0x5f]
 58d:	61                   	(bad)  
 58e:	74 6f                	je     5ff <_init-0x3ffdf1>
 590:	6d                   	ins    DWORD PTR es:[rdi],dx
 591:	69 63 5f 62 61 73 65 	imul   esp,DWORD PTR [rbx+0x5f],0x65736162
 598:	49 69 45 32 31 63 6f 	imul   rax,QWORD PTR [r13+0x32],0x6d6f6331
 59f:	6d 
 5a0:	70 61                	jo     603 <_init-0x3ffded>
 5a2:	72 65                	jb     609 <_init-0x3ffde7>
 5a4:	5f                   	pop    rdi
 5a5:	65 78 63             	gs js  60b <_init-0x3ffde5>
 5a8:	68 61 6e 67 65       	push   0x65676e61
 5ad:	5f                   	pop    rdi
 5ae:	77 65                	ja     615 <_init-0x3ffddb>
 5b0:	61                   	(bad)  
 5b1:	6b 45 52 69          	imul   eax,DWORD PTR [rbp+0x52],0x69
 5b5:	69 53 74 31 32 6d 65 	imul   edx,DWORD PTR [rbx+0x74],0x656d3231
 5bc:	6d                   	ins    DWORD PTR es:[rdi],dx
 5bd:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 5be:	72 79                	jb     639 <_init-0x3ffdb7>
 5c0:	5f                   	pop    rdi
 5c1:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 5c2:	72 64                	jb     628 <_init-0x3ffdc8>
 5c4:	65 72 00             	gs jb  5c7 <_init-0x3ffe29>
 5c7:	5f                   	pop    rdi
 5c8:	5a                   	pop    rdx
 5c9:	4e 56                	rex.WRX push rsi
 5cb:	53                   	push   rbx
 5cc:	74 31                	je     5ff <_init-0x3ffdf1>
 5ce:	33 5f 5f             	xor    ebx,DWORD PTR [rdi+0x5f]
 5d1:	61                   	(bad)  
 5d2:	74 6f                	je     643 <_init-0x3ffdad>
 5d4:	6d                   	ins    DWORD PTR es:[rdi],dx
 5d5:	69 63 5f 62 61 73 65 	imul   esp,DWORD PTR [rbx+0x5f],0x65736162
 5dc:	49 69 45 70 4c 45 69 	imul   rax,QWORD PTR [r13+0x70],0x69454c
 5e3:	00 
 5e4:	73 68                	jae    64e <_init-0x3ffda2>
 5e6:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 5e7:	72 74                	jb     65d <_init-0x3ffd93>
 5e9:	20 75 6e             	and    BYTE PTR [rbp+0x6e],dh
 5ec:	73 69                	jae    657 <_init-0x3ffd99>
 5ee:	67 6e                	outs   dx,BYTE PTR ds:[esi]
 5f0:	65 64 20 69 6e       	gs and BYTE PTR fs:[rcx+0x6e],ch
 5f5:	74 00                	je     5f7 <_init-0x3ffdf9>
 5f7:	5f                   	pop    rdi
 5f8:	5a                   	pop    rdx
 5f9:	4e 56                	rex.WRX push rsi
 5fb:	53                   	push   rbx
 5fc:	74 31                	je     62f <_init-0x3ffdc1>
 5fe:	33 5f 5f             	xor    ebx,DWORD PTR [rdi+0x5f]
 601:	61                   	(bad)  
 602:	74 6f                	je     673 <_init-0x3ffd7d>
 604:	6d                   	ins    DWORD PTR es:[rdi],dx
 605:	69 63 5f 62 61 73 65 	imul   esp,DWORD PTR [rbx+0x5f],0x65736162
 60c:	49 69 45 32 31 63 6f 	imul   rax,QWORD PTR [r13+0x32],0x6d6f6331
 613:	6d 
 614:	70 61                	jo     677 <_init-0x3ffd79>
 616:	72 65                	jb     67d <_init-0x3ffd73>
 618:	5f                   	pop    rdi
 619:	65 78 63             	gs js  67f <_init-0x3ffd71>
 61c:	68 61 6e 67 65       	push   0x65676e61
 621:	5f                   	pop    rdi
 622:	77 65                	ja     689 <_init-0x3ffd67>
 624:	61                   	(bad)  
 625:	6b 45 52 69          	imul   eax,DWORD PTR [rbp+0x52],0x69
 629:	69 53 74 31 32 6d 65 	imul   edx,DWORD PTR [rbx+0x74],0x656d3231
 630:	6d                   	ins    DWORD PTR es:[rdi],dx
 631:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 632:	72 79                	jb     6ad <_init-0x3ffd43>
 634:	5f                   	pop    rdi
 635:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 636:	72 64                	jb     69c <_init-0x3ffd54>
 638:	65 72 00             	gs jb  63b <_init-0x3ffdb5>
 63b:	73 74                	jae    6b1 <_init-0x3ffd3f>
 63d:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 63e:	72 65                	jb     6a5 <_init-0x3ffd4b>
 640:	00 5f 5a             	add    BYTE PTR [rdi+0x5a],bl
 643:	4e 56                	rex.WRX push rsi
 645:	53                   	push   rbx
 646:	74 31                	je     679 <_init-0x3ffd77>
 648:	33 5f 5f             	xor    ebx,DWORD PTR [rdi+0x5f]
 64b:	61                   	(bad)  
 64c:	74 6f                	je     6bd <_init-0x3ffd33>
 64e:	6d                   	ins    DWORD PTR es:[rdi],dx
 64f:	69 63 5f 62 61 73 65 	imul   esp,DWORD PTR [rbx+0x5f],0x65736162
 656:	49 69 45 6f 52 45 69 	imul   rax,QWORD PTR [r13+0x6f],0x694552
 65d:	00 
 65e:	77 63                	ja     6c3 <_init-0x3ffd2d>
 660:	68 61 72 5f 74       	push   0x745f7261
 665:	00 5f 5a             	add    BYTE PTR [rdi+0x5a],bl
 668:	4e 53                	rex.WRX push rbx
 66a:	74 31                	je     69d <_init-0x3ffd53>
 66c:	33 5f 5f             	xor    ebx,DWORD PTR [rdi+0x5f]
 66f:	61                   	(bad)  
 670:	74 6f                	je     6e1 <_init-0x3ffd0f>
 672:	6d                   	ins    DWORD PTR es:[rdi],dx
 673:	69 63 5f 62 61 73 65 	imul   esp,DWORD PTR [rbx+0x5f],0x65736162
 67a:	49 69 45 43 34 45 69 	imul   rax,QWORD PTR [r13+0x43],0x694534
 681:	00 
 682:	62                   	(bad)  
 683:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 684:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 685:	6c                   	ins    BYTE PTR es:[rdi],dx
 686:	00 5f 5a             	add    BYTE PTR [rdi+0x5a],bl
 689:	4e                   	rex.WRX
 68a:	4b 53                	rex.WXB push r11
 68c:	74 31                	je     6bf <_init-0x3ffd31>
 68e:	33 5f 5f             	xor    ebx,DWORD PTR [rdi+0x5f]
 691:	61                   	(bad)  
 692:	74 6f                	je     703 <_init-0x3ffced>
 694:	6d                   	ins    DWORD PTR es:[rdi],dx
 695:	69 63 5f 62 61 73 65 	imul   esp,DWORD PTR [rbx+0x5f],0x65736162
 69c:	49 69 45 31 32 69 73 	imul   rax,QWORD PTR [r13+0x31],0x5f736932
 6a3:	5f 
 6a4:	6c                   	ins    BYTE PTR es:[rdi],dx
 6a5:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 6a6:	63 6b 5f             	movsxd ebp,DWORD PTR [rbx+0x5f]
 6a9:	66 72 65             	data16 jb 711 <_init-0x3ffcdf>
 6ac:	65 45 76 00          	gs rex.RB jbe 6b0 <_init-0x3ffd40>
 6b0:	73 68                	jae    71a <_init-0x3ffcd6>
 6b2:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 6b3:	72 74                	jb     729 <_init-0x3ffcc7>
 6b5:	20 69 6e             	and    BYTE PTR [rcx+0x6e],ch
 6b8:	74 00                	je     6ba <_init-0x3ffd36>
 6ba:	6d                   	ins    DWORD PTR es:[rdi],dx
 6bb:	65 6d                	gs ins DWORD PTR es:[rdi],dx
 6bd:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 6be:	72 79                	jb     739 <_init-0x3ffcb7>
 6c0:	5f                   	pop    rdi
 6c1:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 6c2:	72 64                	jb     728 <_init-0x3ffcc8>
 6c4:	65 72 5f             	gs jb  726 <_init-0x3ffcca>
 6c7:	72 65                	jb     72e <_init-0x3ffcc2>
 6c9:	6c                   	ins    BYTE PTR es:[rdi],dx
 6ca:	61                   	(bad)  
 6cb:	78 65                	js     732 <_init-0x3ffcbe>
 6cd:	64 00 5f 5a          	add    BYTE PTR fs:[rdi+0x5a],bl
 6d1:	4e 53                	rex.WRX push rbx
 6d3:	74 31                	je     706 <_init-0x3ffcea>
 6d5:	33 5f 5f             	xor    ebx,DWORD PTR [rdi+0x5f]
 6d8:	61                   	(bad)  
 6d9:	74 6f                	je     74a <_init-0x3ffca6>
 6db:	6d                   	ins    DWORD PTR es:[rdi],dx
 6dc:	69 63 5f 62 61 73 65 	imul   esp,DWORD PTR [rbx+0x5f],0x65736162
 6e3:	49 69 45 43 34 45 76 	imul   rax,QWORD PTR [r13+0x43],0x764534
 6ea:	00 
 6eb:	5f                   	pop    rdi
 6ec:	5a                   	pop    rdx
 6ed:	4e 56                	rex.WRX push rsi
 6ef:	53                   	push   rbx
 6f0:	74 31                	je     723 <_init-0x3ffccd>
 6f2:	33 5f 5f             	xor    ebx,DWORD PTR [rdi+0x5f]
 6f5:	61                   	(bad)  
 6f6:	74 6f                	je     767 <_init-0x3ffc89>
 6f8:	6d                   	ins    DWORD PTR es:[rdi],dx
 6f9:	69 63 5f 62 61 73 65 	imul   esp,DWORD PTR [rbx+0x5f],0x65736162
 700:	49 69 45 32 33 63 6f 	imul   rax,QWORD PTR [r13+0x32],0x6d6f6333
 707:	6d 
 708:	70 61                	jo     76b <_init-0x3ffc85>
 70a:	72 65                	jb     771 <_init-0x3ffc7f>
 70c:	5f                   	pop    rdi
 70d:	65 78 63             	gs js  773 <_init-0x3ffc7d>
 710:	68 61 6e 67 65       	push   0x65676e61
 715:	5f                   	pop    rdi
 716:	73 74                	jae    78c <_init-0x3ffc64>
 718:	72 6f                	jb     789 <_init-0x3ffc67>
 71a:	6e                   	outs   dx,BYTE PTR ds:[rsi]
 71b:	67 45 52             	addr32 rex.RB push r10
 71e:	69 69 53 74 31 32 6d 	imul   ebp,DWORD PTR [rcx+0x53],0x6d323174
 725:	65 6d                	gs ins DWORD PTR es:[rdi],dx
 727:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 728:	72 79                	jb     7a3 <_init-0x3ffc4d>
 72a:	5f                   	pop    rdi
 72b:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 72c:	72 64                	jb     792 <_init-0x3ffc5e>
 72e:	65 72 00             	gs jb  731 <_init-0x3ffcbf>
 731:	5f                   	pop    rdi
 732:	5a                   	pop    rdx
 733:	4e 56                	rex.WRX push rsi
 735:	53                   	push   rbx
 736:	74 31                	je     769 <_init-0x3ffc87>
 738:	33 5f 5f             	xor    ebx,DWORD PTR [rdi+0x5f]
 73b:	61                   	(bad)  
 73c:	74 6f                	je     7ad <_init-0x3ffc43>
 73e:	6d                   	ins    DWORD PTR es:[rdi],dx
 73f:	69 63 5f 62 61 73 65 	imul   esp,DWORD PTR [rbx+0x5f],0x65736162
 746:	49 69 45 32 31 63 6f 	imul   rax,QWORD PTR [r13+0x32],0x6d6f6331
 74d:	6d 
 74e:	70 61                	jo     7b1 <_init-0x3ffc3f>
 750:	72 65                	jb     7b7 <_init-0x3ffc39>
 752:	5f                   	pop    rdi
 753:	65 78 63             	gs js  7b9 <_init-0x3ffc37>
 756:	68 61 6e 67 65       	push   0x65676e61
 75b:	5f                   	pop    rdi
 75c:	77 65                	ja     7c3 <_init-0x3ffc2d>
 75e:	61                   	(bad)  
 75f:	6b 45 52 69          	imul   eax,DWORD PTR [rbp+0x52],0x69
 763:	69 53 74 31 32 6d 65 	imul   edx,DWORD PTR [rbx+0x74],0x656d3231
 76a:	6d                   	ins    DWORD PTR es:[rdi],dx
 76b:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 76c:	72 79                	jb     7e7 <_init-0x3ffc09>
 76e:	5f                   	pop    rdi
 76f:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 770:	72 64                	jb     7d6 <_init-0x3ffc1a>
 772:	65 72 53             	gs jb  7c8 <_init-0x3ffc28>
 775:	32 5f 00             	xor    bl,BYTE PTR [rdi+0x0]
 778:	66 65 74 63          	data16 gs je 7df <_init-0x3ffc11>
 77c:	68 5f 73 75 62       	push   0x6275735f
 781:	00 5f 5a             	add    BYTE PTR [rdi+0x5a],bl
 784:	4e                   	rex.WRX
 785:	4b 53                	rex.WXB push r11
 787:	74 31                	je     7ba <_init-0x3ffc36>
 789:	33 5f 5f             	xor    ebx,DWORD PTR [rdi+0x5f]
 78c:	61                   	(bad)  
 78d:	74 6f                	je     7fe <_init-0x3ffbf2>
 78f:	6d                   	ins    DWORD PTR es:[rdi],dx
 790:	69 63 5f 62 61 73 65 	imul   esp,DWORD PTR [rbx+0x5f],0x65736162
 797:	49 69 45 34 6c 6f 61 	imul   rax,QWORD PTR [r13+0x34],0x64616f6c
 79e:	64 
 79f:	45 53                	rex.RB push r11
 7a1:	74 31                	je     7d4 <_init-0x3ffc1c>
 7a3:	32 6d 65             	xor    ch,BYTE PTR [rbp+0x65]
 7a6:	6d                   	ins    DWORD PTR es:[rdi],dx
 7a7:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 7a8:	72 79                	jb     823 <_init-0x3ffbcd>
 7aa:	5f                   	pop    rdi
 7ab:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 7ac:	72 64                	jb     812 <_init-0x3ffbde>
 7ae:	65 72 00             	gs jb  7b1 <_init-0x3ffc3f>
 7b1:	5f                   	pop    rdi
 7b2:	5a                   	pop    rdx
 7b3:	4e 56                	rex.WRX push rsi
 7b5:	53                   	push   rbx
 7b6:	74 31                	je     7e9 <_init-0x3ffc07>
 7b8:	33 5f 5f             	xor    ebx,DWORD PTR [rdi+0x5f]
 7bb:	61                   	(bad)  
 7bc:	74 6f                	je     82d <_init-0x3ffbc3>
 7be:	6d                   	ins    DWORD PTR es:[rdi],dx
 7bf:	69 63 5f 62 61 73 65 	imul   esp,DWORD PTR [rbx+0x5f],0x65736162
 7c6:	49 69 45 32 33 63 6f 	imul   rax,QWORD PTR [r13+0x32],0x6d6f6333
 7cd:	6d 
 7ce:	70 61                	jo     831 <_init-0x3ffbbf>
 7d0:	72 65                	jb     837 <_init-0x3ffbb9>
 7d2:	5f                   	pop    rdi
 7d3:	65 78 63             	gs js  839 <_init-0x3ffbb7>
 7d6:	68 61 6e 67 65       	push   0x65676e61
 7db:	5f                   	pop    rdi
 7dc:	73 74                	jae    852 <_init-0x3ffb9e>
 7de:	72 6f                	jb     84f <_init-0x3ffba1>
 7e0:	6e                   	outs   dx,BYTE PTR ds:[rsi]
 7e1:	67 45 52             	addr32 rex.RB push r10
 7e4:	69 69 53 74 31 32 6d 	imul   ebp,DWORD PTR [rcx+0x53],0x6d323174
 7eb:	65 6d                	gs ins DWORD PTR es:[rdi],dx
 7ed:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 7ee:	72 79                	jb     869 <_init-0x3ffb87>
 7f0:	5f                   	pop    rdi
 7f1:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 7f2:	72 64                	jb     858 <_init-0x3ffb98>
 7f4:	65 72 53             	gs jb  84a <_init-0x3ffba6>
 7f7:	32 5f 00             	xor    bl,BYTE PTR [rdi+0x0]
 7fa:	6c                   	ins    BYTE PTR es:[rdi],dx
 7fb:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 7fc:	61                   	(bad)  
 7fd:	64 00 66 65          	add    BYTE PTR fs:[rsi+0x65],ah
 801:	74 63                	je     866 <_init-0x3ffb8a>
 803:	68 5f 61 64 64       	push   0x6464615f
 808:	00 5f 5f             	add    BYTE PTR [rdi+0x5f],bl
 80b:	63 6d 70             	movsxd ebp,DWORD PTR [rbp+0x70]
 80e:	65 78 63             	gs js  874 <_init-0x3ffb7c>
 811:	68 5f 66 61 69       	push   0x6961665f
 816:	6c                   	ins    BYTE PTR es:[rdi],dx
 817:	75 72                	jne    88b <_init-0x3ffb65>
 819:	65 5f                	gs pop rdi
 81b:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 81c:	72 64                	jb     882 <_init-0x3ffb6e>
 81e:	65 72 32             	gs jb  853 <_init-0x3ffb9d>
 821:	00 6f 70             	add    BYTE PTR [rdi+0x70],ch
 824:	65 72 61             	gs jb  888 <_init-0x3ffb68>
 827:	74 6f                	je     898 <_init-0x3ffb58>
 829:	72 2b                	jb     856 <_init-0x3ffb9a>
 82b:	2b 00                	sub    eax,DWORD PTR [rax]
 82d:	5f                   	pop    rdi
 82e:	5a                   	pop    rdx
 82f:	4e 56                	rex.WRX push rsi
 831:	53                   	push   rbx
 832:	74 31                	je     865 <_init-0x3ffb8b>
 834:	33 5f 5f             	xor    ebx,DWORD PTR [rdi+0x5f]
 837:	61                   	(bad)  
 838:	74 6f                	je     8a9 <_init-0x3ffb47>
 83a:	6d                   	ins    DWORD PTR es:[rdi],dx
 83b:	69 63 5f 62 61 73 65 	imul   esp,DWORD PTR [rbx+0x5f],0x65736162
 842:	49 69 45 39 66 65 74 	imul   rax,QWORD PTR [r13+0x39],0x63746566
 849:	63 
 84a:	68 5f 61 64 64       	push   0x6464615f
 84f:	45 69 53 74 31 32 6d 	imul   r10d,DWORD PTR [r11+0x74],0x656d3231
 856:	65 
 857:	6d                   	ins    DWORD PTR es:[rdi],dx
 858:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 859:	72 79                	jb     8d4 <_init-0x3ffb1c>
 85b:	5f                   	pop    rdi
 85c:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 85d:	72 64                	jb     8c3 <_init-0x3ffb2d>
 85f:	65 72 00             	gs jb  862 <_init-0x3ffb8e>
 862:	5f                   	pop    rdi
 863:	5a                   	pop    rdx
 864:	4e 53                	rex.WRX push rbx
 866:	74 31                	je     899 <_init-0x3ffb57>
 868:	33 5f 5f             	xor    ebx,DWORD PTR [rdi+0x5f]
 86b:	61                   	(bad)  
 86c:	74 6f                	je     8dd <_init-0x3ffb13>
 86e:	6d                   	ins    DWORD PTR es:[rdi],dx
 86f:	69 63 5f 62 61 73 65 	imul   esp,DWORD PTR [rbx+0x5f],0x65736162
 876:	49 69 45 6d 6d 45 69 	imul   rax,QWORD PTR [r13+0x6d],0x69456d
 87d:	00 
 87e:	5f                   	pop    rdi
 87f:	5a                   	pop    rdx
 880:	4e 56                	rex.WRX push rsi
 882:	53                   	push   rbx
 883:	74 31                	je     8b6 <_init-0x3ffb3a>
 885:	33 5f 5f             	xor    ebx,DWORD PTR [rdi+0x5f]
 888:	61                   	(bad)  
 889:	74 6f                	je     8fa <_init-0x3ffaf6>
 88b:	6d                   	ins    DWORD PTR es:[rdi],dx
 88c:	69 63 5f 62 61 73 65 	imul   esp,DWORD PTR [rbx+0x5f],0x65736162
 893:	49 69 45 39 66 65 74 	imul   rax,QWORD PTR [r13+0x39],0x63746566
 89a:	63 
 89b:	68 5f 78 6f 72       	push   0x726f785f
 8a0:	45 69 53 74 31 32 6d 	imul   r10d,DWORD PTR [r11+0x74],0x656d3231
 8a7:	65 
 8a8:	6d                   	ins    DWORD PTR es:[rdi],dx
 8a9:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 8aa:	72 79                	jb     925 <_init-0x3ffacb>
 8ac:	5f                   	pop    rdi
 8ad:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 8ae:	72 64                	jb     914 <_init-0x3ffadc>
 8b0:	65 72 00             	gs jb  8b3 <_init-0x3ffb3d>
 8b3:	6d                   	ins    DWORD PTR es:[rdi],dx
 8b4:	65 6d                	gs ins DWORD PTR es:[rdi],dx
 8b6:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 8b7:	72 79                	jb     932 <_init-0x3ffabe>
 8b9:	5f                   	pop    rdi
 8ba:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 8bb:	72 64                	jb     921 <_init-0x3ffacf>
 8bd:	65 72 5f             	gs jb  91f <_init-0x3ffad1>
 8c0:	61                   	(bad)  
 8c1:	63 71 75             	movsxd esi,DWORD PTR [rcx+0x75]
 8c4:	69 72 65 00 5f 5a 4e 	imul   esi,DWORD PTR [rdx+0x65],0x4e5a5f00
 8cb:	53                   	push   rbx
 8cc:	74 31                	je     8ff <_init-0x3ffaf1>
 8ce:	33 5f 5f             	xor    ebx,DWORD PTR [rdi+0x5f]
 8d1:	61                   	(bad)  
 8d2:	74 6f                	je     943 <_init-0x3ffaad>
 8d4:	6d                   	ins    DWORD PTR es:[rdi],dx
 8d5:	69 63 5f 62 61 73 65 	imul   esp,DWORD PTR [rbx+0x5f],0x65736162
 8dc:	49 69 45 61 53 45 69 	imul   rax,QWORD PTR [r13+0x61],0x694553
 8e3:	00 
 8e4:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 8e5:	70 65                	jo     94c <_init-0x3ffaa4>
 8e7:	72 61                	jb     94a <_init-0x3ffaa6>
 8e9:	74 6f                	je     95a <_init-0x3ffa96>
 8eb:	72 2b                	jb     918 <_init-0x3ffad8>
 8ed:	3d 00 5f 5a 4e       	cmp    eax,0x4e5a5f00
 8f2:	53                   	push   rbx
 8f3:	74 31                	je     926 <_init-0x3ffaca>
 8f5:	33 5f 5f             	xor    ebx,DWORD PTR [rdi+0x5f]
 8f8:	61                   	(bad)  
 8f9:	74 6f                	je     96a <_init-0x3ffa86>
 8fb:	6d                   	ins    DWORD PTR es:[rdi],dx
 8fc:	69 63 5f 62 61 73 65 	imul   esp,DWORD PTR [rbx+0x5f],0x65736162
 903:	49 69 45 6d 6d 45 76 	imul   rax,QWORD PTR [r13+0x6d],0x76456d
 90a:	00 
 90b:	5f                   	pop    rdi
 90c:	5a                   	pop    rdx
 90d:	4e 53                	rex.WRX push rbx
 90f:	74 31                	je     942 <_init-0x3ffaae>
 911:	33 5f 5f             	xor    ebx,DWORD PTR [rdi+0x5f]
 914:	61                   	(bad)  
 915:	74 6f                	je     986 <_init-0x3ffa6a>
 917:	6d                   	ins    DWORD PTR es:[rdi],dx
 918:	69 63 5f 62 61 73 65 	imul   esp,DWORD PTR [rbx+0x5f],0x65736162
 91f:	49 69 45 61 4e 45 69 	imul   rax,QWORD PTR [r13+0x61],0x69454e
 926:	00 
 927:	5f                   	pop    rdi
 928:	5f                   	pop    rdi
 929:	6d                   	ins    DWORD PTR es:[rdi],dx
 92a:	65 6d                	gs ins DWORD PTR es:[rdi],dx
 92c:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 92d:	72 79                	jb     9a8 <_init-0x3ffa48>
 92f:	5f                   	pop    rdi
 930:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 931:	72 64                	jb     997 <_init-0x3ffa59>
 933:	65 72 5f             	gs jb  995 <_init-0x3ffa5b>
 936:	68 6c 65 5f 72       	push   0x725f656c
 93b:	65 6c                	gs ins BYTE PTR es:[rdi],dx
 93d:	65 61                	gs (bad) 
 93f:	73 65                	jae    9a6 <_init-0x3ffa4a>
 941:	00 5f 5f             	add    BYTE PTR [rdi+0x5f],bl
 944:	6d                   	ins    DWORD PTR es:[rdi],dx
 945:	65 6d                	gs ins DWORD PTR es:[rdi],dx
 947:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 948:	72 79                	jb     9c3 <_init-0x3ffa2d>
 94a:	5f                   	pop    rdi
 94b:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 94c:	72 64                	jb     9b2 <_init-0x3ffa3e>
 94e:	65 72 5f             	gs jb  9b0 <_init-0x3ffa40>
 951:	6d                   	ins    DWORD PTR es:[rdi],dx
 952:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 953:	64 69 66 69 65 72 5f 	imul   esp,DWORD PTR fs:[rsi+0x69],0x6d5f7265
 95a:	6d 
 95b:	61                   	(bad)  
 95c:	73 6b                	jae    9c9 <_init-0x3ffa27>
 95e:	00 5f 5a             	add    BYTE PTR [rdi+0x5a],bl
 961:	4e 53                	rex.WRX push rbx
 963:	74 31                	je     996 <_init-0x3ffa5a>
 965:	33 5f 5f             	xor    ebx,DWORD PTR [rdi+0x5f]
 968:	61                   	(bad)  
 969:	74 6f                	je     9da <_init-0x3ffa16>
 96b:	6d                   	ins    DWORD PTR es:[rdi],dx
 96c:	69 63 5f 62 61 73 65 	imul   esp,DWORD PTR [rbx+0x5f],0x65736162
 973:	49 69 45 61 53 45 52 	imul   rax,QWORD PTR [r13+0x61],0x4b524553
 97a:	4b 
 97b:	53                   	push   rbx
 97c:	30 5f 00             	xor    BYTE PTR [rdi+0x0],bl
 97f:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 980:	70 65                	jo     9e7 <_init-0x3ffa09>
 982:	72 61                	jb     9e5 <_init-0x3ffa0b>
 984:	74 6f                	je     9f5 <_init-0x3ff9fb>
 986:	72 26                	jb     9ae <_init-0x3ffa42>
 988:	00 6d 65             	add    BYTE PTR [rbp+0x65],ch
 98b:	6d                   	ins    DWORD PTR es:[rdi],dx
 98c:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 98d:	72 79                	jb     a08 <_init-0x3ff9e8>
 98f:	5f                   	pop    rdi
 990:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 991:	72 64                	jb     9f7 <_init-0x3ff9f9>
 993:	65 72 5f             	gs jb  9f5 <_init-0x3ff9fb>
 996:	61                   	(bad)  
 997:	63 71 5f             	movsxd esi,DWORD PTR [rcx+0x5f]
 99a:	72 65                	jb     a01 <_init-0x3ff9ef>
 99c:	6c                   	ins    BYTE PTR es:[rdi],dx
 99d:	00 5f 5a             	add    BYTE PTR [rdi+0x5a],bl
 9a0:	4e 53                	rex.WRX push rbx
 9a2:	74 31                	je     9d5 <_init-0x3ffa1b>
 9a4:	33 5f 5f             	xor    ebx,DWORD PTR [rdi+0x5f]
 9a7:	61                   	(bad)  
 9a8:	74 6f                	je     a19 <_init-0x3ff9d7>
 9aa:	6d                   	ins    DWORD PTR es:[rdi],dx
 9ab:	69 63 5f 62 61 73 65 	imul   esp,DWORD PTR [rbx+0x5f],0x65736162
 9b2:	49 69 45 70 70 45 69 	imul   rax,QWORD PTR [r13+0x70],0x694570
 9b9:	00 
 9ba:	75 6e                	jne    a2a <_init-0x3ff9c6>
 9bc:	73 69                	jae    a27 <_init-0x3ff9c9>
 9be:	67 6e                	outs   dx,BYTE PTR ds:[esi]
 9c0:	65 64 20 63 68       	gs and BYTE PTR fs:[rbx+0x68],ah
 9c5:	61                   	(bad)  
 9c6:	72 00                	jb     9c8 <_init-0x3ffa28>
 9c8:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 9c9:	70 65                	jo     a30 <_init-0x3ff9c0>
 9cb:	72 61                	jb     a2e <_init-0x3ff9c2>
 9cd:	74 6f                	je     a3e <_init-0x3ff9b2>
 9cf:	72 3d                	jb     a0e <_init-0x3ff9e2>
 9d1:	00 5f 5a             	add    BYTE PTR [rdi+0x5a],bl
 9d4:	4e 53                	rex.WRX push rbx
 9d6:	74 31                	je     a09 <_init-0x3ff9e7>
 9d8:	33 5f 5f             	xor    ebx,DWORD PTR [rdi+0x5f]
 9db:	61                   	(bad)  
 9dc:	74 6f                	je     a4d <_init-0x3ff9a3>
 9de:	6d                   	ins    DWORD PTR es:[rdi],dx
 9df:	69 63 5f 62 61 73 65 	imul   esp,DWORD PTR [rbx+0x5f],0x65736162
 9e6:	49 69 45 70 70 45 76 	imul   rax,QWORD PTR [r13+0x70],0x764570
 9ed:	00 
 9ee:	5f                   	pop    rdi
 9ef:	5a                   	pop    rdx
 9f0:	4e 56                	rex.WRX push rsi
 9f2:	53                   	push   rbx
 9f3:	74 31                	je     a26 <_init-0x3ff9ca>
 9f5:	33 5f 5f             	xor    ebx,DWORD PTR [rdi+0x5f]
 9f8:	61                   	(bad)  
 9f9:	74 6f                	je     a6a <_init-0x3ff986>
 9fb:	6d                   	ins    DWORD PTR es:[rdi],dx
 9fc:	69 63 5f 62 61 73 65 	imul   esp,DWORD PTR [rbx+0x5f],0x65736162
 a03:	49 69 45 38 66 65 74 	imul   rax,QWORD PTR [r13+0x38],0x63746566
 a0a:	63 
 a0b:	68 5f 6f 72 45       	push   0x45726f5f
 a10:	69 53 74 31 32 6d 65 	imul   edx,DWORD PTR [rbx+0x74],0x656d3231
 a17:	6d                   	ins    DWORD PTR es:[rdi],dx
 a18:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 a19:	72 79                	jb     a94 <_init-0x3ff95c>
 a1b:	5f                   	pop    rdi
 a1c:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 a1d:	72 64                	jb     a83 <_init-0x3ff96d>
 a1f:	65 72 00             	gs jb  a22 <_init-0x3ff9ce>
 a22:	5f                   	pop    rdi
 a23:	5a                   	pop    rdx
 a24:	4e 56                	rex.WRX push rsi
 a26:	53                   	push   rbx
 a27:	74 31                	je     a5a <_init-0x3ff996>
 a29:	33 5f 5f             	xor    ebx,DWORD PTR [rdi+0x5f]
 a2c:	61                   	(bad)  
 a2d:	74 6f                	je     a9e <_init-0x3ff952>
 a2f:	6d                   	ins    DWORD PTR es:[rdi],dx
 a30:	69 63 5f 62 61 73 65 	imul   esp,DWORD PTR [rbx+0x5f],0x65736162
 a37:	49 69 45 38 65 78 63 	imul   rax,QWORD PTR [r13+0x38],0x68637865
 a3e:	68 
 a3f:	61                   	(bad)  
 a40:	6e                   	outs   dx,BYTE PTR ds:[rsi]
 a41:	67 65 45 69 53 74 31 	imul   r10d,DWORD PTR gs:[r11d+0x74],0x656d3231
 a48:	32 6d 65 
 a4b:	6d                   	ins    DWORD PTR es:[rdi],dx
 a4c:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 a4d:	72 79                	jb     ac8 <_init-0x3ff928>
 a4f:	5f                   	pop    rdi
 a50:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 a51:	72 64                	jb     ab7 <_init-0x3ff939>
 a53:	65 72 00             	gs jb  a56 <_init-0x3ff99a>
 a56:	5f                   	pop    rdi
 a57:	5a                   	pop    rdx
 a58:	4e 56                	rex.WRX push rsi
 a5a:	53                   	push   rbx
 a5b:	74 31                	je     a8e <_init-0x3ff962>
 a5d:	33 5f 5f             	xor    ebx,DWORD PTR [rdi+0x5f]
 a60:	61                   	(bad)  
 a61:	74 6f                	je     ad2 <_init-0x3ff91e>
 a63:	6d                   	ins    DWORD PTR es:[rdi],dx
 a64:	69 63 5f 62 61 73 65 	imul   esp,DWORD PTR [rbx+0x5f],0x65736162
 a6b:	49 69 45 61 4e 45 69 	imul   rax,QWORD PTR [r13+0x61],0x69454e
 a72:	00 
 a73:	5f                   	pop    rdi
 a74:	5a                   	pop    rdx
 a75:	53                   	push   rbx
 a76:	74 61                	je     ad9 <_init-0x3ff917>
 a78:	6e                   	outs   dx,BYTE PTR ds:[rsi]
 a79:	53                   	push   rbx
 a7a:	74 31                	je     aad <_init-0x3ff943>
 a7c:	32 6d 65             	xor    ch,BYTE PTR [rbp+0x65]
 a7f:	6d                   	ins    DWORD PTR es:[rdi],dx
 a80:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 a81:	72 79                	jb     afc <_init-0x3ff8f4>
 a83:	5f                   	pop    rdi
 a84:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 a85:	72 64                	jb     aeb <_init-0x3ff905>
 a87:	65 72 53             	gs jb  add <_init-0x3ff913>
 a8a:	74 32                	je     abe <_init-0x3ff932>
 a8c:	33 5f 5f             	xor    ebx,DWORD PTR [rdi+0x5f]
 a8f:	6d                   	ins    DWORD PTR es:[rdi],dx
 a90:	65 6d                	gs ins DWORD PTR es:[rdi],dx
 a92:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 a93:	72 79                	jb     b0e <_init-0x3ff8e2>
 a95:	5f                   	pop    rdi
 a96:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 a97:	72 64                	jb     afd <_init-0x3ff8f3>
 a99:	65 72 5f             	gs jb  afb <_init-0x3ff8f5>
 a9c:	6d                   	ins    DWORD PTR es:[rdi],dx
 a9d:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 a9e:	64 69 66 69 65 72 00 	imul   esp,DWORD PTR fs:[rsi+0x69],0x5f007265
 aa5:	5f 
 aa6:	5a                   	pop    rdx
 aa7:	53                   	push   rbx
 aa8:	74 32                	je     adc <_init-0x3ff914>
 aaa:	33 5f 5f             	xor    ebx,DWORD PTR [rdi+0x5f]
 aad:	63 6d 70             	movsxd ebp,DWORD PTR [rbp+0x70]
 ab0:	65 78 63             	gs js  b16 <_init-0x3ff8da>
 ab3:	68 5f 66 61 69       	push   0x6961665f
 ab8:	6c                   	ins    BYTE PTR es:[rdi],dx
 ab9:	75 72                	jne    b2d <_init-0x3ff8c3>
 abb:	65 5f                	gs pop rdi
 abd:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 abe:	72 64                	jb     b24 <_init-0x3ff8cc>
 ac0:	65 72 53             	gs jb  b16 <_init-0x3ff8da>
 ac3:	74 31                	je     af6 <_init-0x3ff8fa>
 ac5:	32 6d 65             	xor    ch,BYTE PTR [rbp+0x65]
 ac8:	6d                   	ins    DWORD PTR es:[rdi],dx
 ac9:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 aca:	72 79                	jb     b45 <_init-0x3ff8ab>
 acc:	5f                   	pop    rdi
 acd:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 ace:	72 64                	jb     b34 <_init-0x3ff8bc>
 ad0:	65 72 00             	gs jb  ad3 <_init-0x3ff91d>
 ad3:	63 68 61             	movsxd ebp,DWORD PTR [rax+0x61]
 ad6:	72 33                	jb     b0b <_init-0x3ff8e5>
 ad8:	32 5f 74             	xor    bl,BYTE PTR [rdi+0x74]
 adb:	00 6d 65             	add    BYTE PTR [rbp+0x65],ch
 ade:	6d                   	ins    DWORD PTR es:[rdi],dx
 adf:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 ae0:	72 79                	jb     b5b <_init-0x3ff895>
 ae2:	5f                   	pop    rdi
 ae3:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 ae4:	72 64                	jb     b4a <_init-0x3ff8a6>
 ae6:	65 72 5f             	gs jb  b48 <_init-0x3ff8a8>
 ae9:	63 6f 6e             	movsxd ebp,DWORD PTR [rdi+0x6e]
 aec:	73 75                	jae    b63 <_init-0x3ff88d>
 aee:	6d                   	ins    DWORD PTR es:[rdi],dx
 aef:	65 00 5f 5f          	add    BYTE PTR gs:[rdi+0x5f],bl
 af3:	6d                   	ins    DWORD PTR es:[rdi],dx
 af4:	65 6d                	gs ins DWORD PTR es:[rdi],dx
 af6:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 af7:	72 79                	jb     b72 <_init-0x3ff87e>
 af9:	5f                   	pop    rdi
 afa:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 afb:	72 64                	jb     b61 <_init-0x3ff88f>
 afd:	65 72 5f             	gs jb  b5f <_init-0x3ff891>
 b00:	68 6c 65 5f 61       	push   0x615f656c
 b05:	63 71 75             	movsxd esi,DWORD PTR [rcx+0x75]
 b08:	69 72 65 00 5f 5f 69 	imul   esi,DWORD PTR [rdx+0x65],0x695f5f00
 b0f:	31 00                	xor    DWORD PTR [rax],eax
 b11:	5f                   	pop    rdi
 b12:	5f                   	pop    rdi
 b13:	69 32 00 5f 5a 4e    	imul   esi,DWORD PTR [rdx],0x4e5a5f00
 b19:	53                   	push   rbx
 b1a:	74 36                	je     b52 <_init-0x3ff89e>
 b1c:	61                   	(bad)  
 b1d:	74 6f                	je     b8e <_init-0x3ff862>
 b1f:	6d                   	ins    DWORD PTR es:[rdi],dx
 b20:	69 63 49 69 45 43 34 	imul   esp,DWORD PTR [rbx+0x49],0x34434569
 b27:	45 52                	rex.RB push r10
 b29:	4b 53                	rex.WXB push r11
 b2b:	30 5f 00             	xor    BYTE PTR [rdi+0x0],bl
 b2e:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 b2f:	70 65                	jo     b96 <_init-0x3ff85a>
 b31:	72 61                	jb     b94 <_init-0x3ff85c>
 b33:	74 6f                	je     ba4 <_init-0x3ff84c>
 b35:	72 2d                	jb     b64 <_init-0x3ff88c>
 b37:	2d 00 5f 5a 4e       	sub    eax,0x4e5a5f00
 b3c:	56                   	push   rsi
 b3d:	53                   	push   rbx
 b3e:	74 31                	je     b71 <_init-0x3ff87f>
 b40:	33 5f 5f             	xor    ebx,DWORD PTR [rdi+0x5f]
 b43:	61                   	(bad)  
 b44:	74 6f                	je     bb5 <_init-0x3ff83b>
 b46:	6d                   	ins    DWORD PTR es:[rdi],dx
 b47:	69 63 5f 62 61 73 65 	imul   esp,DWORD PTR [rbx+0x5f],0x65736162
 b4e:	49 69 45 61 53 45 69 	imul   rax,QWORD PTR [r13+0x61],0x694553
 b55:	00 
 b56:	5f                   	pop    rdi
 b57:	5a                   	pop    rdx
 b58:	4e 53                	rex.WRX push rbx
 b5a:	74 31                	je     b8d <_init-0x3ff863>
 b5c:	33 5f 5f             	xor    ebx,DWORD PTR [rdi+0x5f]
 b5f:	61                   	(bad)  
 b60:	74 6f                	je     bd1 <_init-0x3ff81f>
 b62:	6d                   	ins    DWORD PTR es:[rdi],dx
 b63:	69 63 5f 62 61 73 65 	imul   esp,DWORD PTR [rbx+0x5f],0x65736162
 b6a:	49 69 45 38 66 65 74 	imul   rax,QWORD PTR [r13+0x38],0x63746566
 b71:	63 
 b72:	68 5f 6f 72 45       	push   0x45726f5f
 b77:	69 53 74 31 32 6d 65 	imul   edx,DWORD PTR [rbx+0x74],0x656d3231
 b7e:	6d                   	ins    DWORD PTR es:[rdi],dx
 b7f:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 b80:	72 79                	jb     bfb <_init-0x3ff7f5>
 b82:	5f                   	pop    rdi
 b83:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 b84:	72 64                	jb     bea <_init-0x3ff806>
 b86:	65 72 00             	gs jb  b89 <_init-0x3ff867>
 b89:	5f                   	pop    rdi
 b8a:	5a                   	pop    rdx
 b8b:	4e 56                	rex.WRX push rsi
 b8d:	4b 53                	rex.WXB push r11
 b8f:	74 31                	je     bc2 <_init-0x3ff82e>
 b91:	33 5f 5f             	xor    ebx,DWORD PTR [rdi+0x5f]
 b94:	61                   	(bad)  
 b95:	74 6f                	je     c06 <_init-0x3ff7ea>
 b97:	6d                   	ins    DWORD PTR es:[rdi],dx
 b98:	69 63 5f 62 61 73 65 	imul   esp,DWORD PTR [rbx+0x5f],0x65736162
 b9f:	49 69 45 34 6c 6f 61 	imul   rax,QWORD PTR [r13+0x34],0x64616f6c
 ba6:	64 
 ba7:	45 53                	rex.RB push r11
 ba9:	74 31                	je     bdc <_init-0x3ff814>
 bab:	32 6d 65             	xor    ch,BYTE PTR [rbp+0x65]
 bae:	6d                   	ins    DWORD PTR es:[rdi],dx
 baf:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 bb0:	72 79                	jb     c2b <_init-0x3ff7c5>
 bb2:	5f                   	pop    rdi
 bb3:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 bb4:	72 64                	jb     c1a <_init-0x3ff7d6>
 bb6:	65 72 00             	gs jb  bb9 <_init-0x3ff837>
 bb9:	5f                   	pop    rdi
 bba:	5a                   	pop    rdx
 bbb:	4e 53                	rex.WRX push rbx
 bbd:	74 31                	je     bf0 <_init-0x3ff800>
 bbf:	33 5f 5f             	xor    ebx,DWORD PTR [rdi+0x5f]
 bc2:	61                   	(bad)  
 bc3:	74 6f                	je     c34 <_init-0x3ff7bc>
 bc5:	6d                   	ins    DWORD PTR es:[rdi],dx
 bc6:	69 63 5f 62 61 73 65 	imul   esp,DWORD PTR [rbx+0x5f],0x65736162
 bcd:	49 69 45 6f 52 45 69 	imul   rax,QWORD PTR [r13+0x6f],0x694552
 bd4:	00 
 bd5:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 bd6:	70 65                	jo     c3d <_init-0x3ff7b3>
 bd8:	72 61                	jb     c3b <_init-0x3ff7b5>
 bda:	74 6f                	je     c4b <_init-0x3ff7a5>
 bdc:	72 2d                	jb     c0b <_init-0x3ff7e5>
 bde:	3d 00 5f 5f 6d       	cmp    eax,0x6d5f5f00
 be3:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 be4:	64 00 5f 4d          	add    BYTE PTR fs:[rdi+0x4d],bl
 be8:	5f                   	pop    rdi
 be9:	69 00 66 65 74 63    	imul   eax,DWORD PTR [rax],0x63746566
 bef:	68 5f 61 6e 64       	push   0x646e615f
 bf4:	00 66 65             	add    BYTE PTR [rsi+0x65],ah
 bf7:	74 63                	je     c5c <_init-0x3ff794>
 bf9:	68 5f 78 6f 72       	push   0x726f785f
 bfe:	00 5f 5a             	add    BYTE PTR [rdi+0x5a],bl
 c01:	4e 53                	rex.WRX push rbx
 c03:	74 31                	je     c36 <_init-0x3ff7ba>
 c05:	33 5f 5f             	xor    ebx,DWORD PTR [rdi+0x5f]
 c08:	61                   	(bad)  
 c09:	74 6f                	je     c7a <_init-0x3ff776>
 c0b:	6d                   	ins    DWORD PTR es:[rdi],dx
 c0c:	69 63 5f 62 61 73 65 	imul   esp,DWORD PTR [rbx+0x5f],0x65736162
 c13:	49 69 45 65 4f 45 69 	imul   rax,QWORD PTR [r13+0x65],0x69454f
 c1a:	00 
 c1b:	5f                   	pop    rdi
 c1c:	49 6e                	rex.WB outs dx,BYTE PTR ds:[rsi]
 c1e:	74 54                	je     c74 <_init-0x3ff77c>
 c20:	70 00                	jo     c22 <_init-0x3ff7ce>
 c22:	5f                   	pop    rdi
 c23:	5a                   	pop    rdx
 c24:	4e 53                	rex.WRX push rbx
 c26:	74 31                	je     c59 <_init-0x3ff797>
 c28:	33 5f 5f             	xor    ebx,DWORD PTR [rdi+0x5f]
 c2b:	61                   	(bad)  
 c2c:	74 6f                	je     c9d <_init-0x3ff753>
 c2e:	6d                   	ins    DWORD PTR es:[rdi],dx
 c2f:	69 63 5f 62 61 73 65 	imul   esp,DWORD PTR [rbx+0x5f],0x65736162
 c36:	49 69 45 43 32 45 76 	imul   rax,QWORD PTR [r13+0x43],0x764532
 c3d:	00 
 c3e:	5f                   	pop    rdi
 c3f:	5f                   	pop    rdi
 c40:	6d                   	ins    DWORD PTR es:[rdi],dx
 c41:	65 6d                	gs ins DWORD PTR es:[rdi],dx
 c43:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 c44:	72 79                	jb     cbf <_init-0x3ff731>
 c46:	5f                   	pop    rdi
 c47:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 c48:	72 64                	jb     cae <_init-0x3ff742>
 c4a:	65 72 5f             	gs jb  cac <_init-0x3ff744>
 c4d:	6d                   	ins    DWORD PTR es:[rdi],dx
 c4e:	61                   	(bad)  
 c4f:	73 6b                	jae    cbc <_init-0x3ff734>
 c51:	00 5f 5f             	add    BYTE PTR [rdi+0x5f],bl
 c54:	62 31                	(bad)  
 c56:	00 5f 5f             	add    BYTE PTR [rdi+0x5f],bl
 c59:	62 32                	(bad)  
 c5b:	00 5f 5a             	add    BYTE PTR [rdi+0x5a],bl
 c5e:	4e 53                	rex.WRX push rbx
 c60:	74 36                	je     c98 <_init-0x3ff758>
 c62:	61                   	(bad)  
 c63:	74 6f                	je     cd4 <_init-0x3ff71c>
 c65:	6d                   	ins    DWORD PTR es:[rdi],dx
 c66:	69 63 49 69 45 44 34 	imul   esp,DWORD PTR [rbx+0x49],0x34444569
 c6d:	45 76 00             	rex.RB jbe c70 <_init-0x3ff780>
 c70:	5f                   	pop    rdi
 c71:	5a                   	pop    rdx
 c72:	4e 53                	rex.WRX push rbx
 c74:	74 31                	je     ca7 <_init-0x3ff749>
 c76:	33 5f 5f             	xor    ebx,DWORD PTR [rdi+0x5f]
 c79:	61                   	(bad)  
 c7a:	74 6f                	je     ceb <_init-0x3ff705>
 c7c:	6d                   	ins    DWORD PTR es:[rdi],dx
 c7d:	69 63 5f 62 61 73 65 	imul   esp,DWORD PTR [rbx+0x5f],0x65736162
 c84:	49 69 45 39 66 65 74 	imul   rax,QWORD PTR [r13+0x39],0x63746566
 c8b:	63 
 c8c:	68 5f 78 6f 72       	push   0x726f785f
 c91:	45 69 53 74 31 32 6d 	imul   r10d,DWORD PTR [r11+0x74],0x656d3231
 c98:	65 
 c99:	6d                   	ins    DWORD PTR es:[rdi],dx
 c9a:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 c9b:	72 79                	jb     d16 <_init-0x3ff6da>
 c9d:	5f                   	pop    rdi
 c9e:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 c9f:	72 64                	jb     d05 <_init-0x3ff6eb>
 ca1:	65 72 00             	gs jb  ca4 <_init-0x3ff74c>
 ca4:	61                   	(bad)  
 ca5:	72 67                	jb     d0e <_init-0x3ff6e2>
 ca7:	76 00                	jbe    ca9 <_init-0x3ff747>
 ca9:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 caa:	70 65                	jo     d11 <_init-0x3ff6df>
 cac:	72 61                	jb     d0f <_init-0x3ff6e1>
 cae:	74 6f                	je     d1f <_init-0x3ff6d1>
 cb0:	72 26                	jb     cd8 <_init-0x3ff718>
 cb2:	3d 00 5f 5a 4e       	cmp    eax,0x4e5a5f00
 cb7:	56                   	push   rsi
 cb8:	53                   	push   rbx
 cb9:	74 31                	je     cec <_init-0x3ff704>
 cbb:	33 5f 5f             	xor    ebx,DWORD PTR [rdi+0x5f]
 cbe:	61                   	(bad)  
 cbf:	74 6f                	je     d30 <_init-0x3ff6c0>
 cc1:	6d                   	ins    DWORD PTR es:[rdi],dx
 cc2:	69 63 5f 62 61 73 65 	imul   esp,DWORD PTR [rbx+0x5f],0x65736162
 cc9:	49 69 45 70 70 45 69 	imul   rax,QWORD PTR [r13+0x70],0x694570
 cd0:	00 
 cd1:	5f                   	pop    rdi
 cd2:	5a                   	pop    rdx
 cd3:	4e 56                	rex.WRX push rsi
 cd5:	53                   	push   rbx
 cd6:	74 31                	je     d09 <_init-0x3ff6e7>
 cd8:	33 5f 5f             	xor    ebx,DWORD PTR [rdi+0x5f]
 cdb:	61                   	(bad)  
 cdc:	74 6f                	je     d4d <_init-0x3ff6a3>
 cde:	6d                   	ins    DWORD PTR es:[rdi],dx
 cdf:	69 63 5f 62 61 73 65 	imul   esp,DWORD PTR [rbx+0x5f],0x65736162
 ce6:	49 69 45 70 70 45 76 	imul   rax,QWORD PTR [r13+0x70],0x764570
 ced:	00 
 cee:	5f                   	pop    rdi
 cef:	5a                   	pop    rdx
 cf0:	4e 53                	rex.WRX push rbx
 cf2:	74 31                	je     d25 <_init-0x3ff6cb>
 cf4:	33 5f 5f             	xor    ebx,DWORD PTR [rdi+0x5f]
 cf7:	61                   	(bad)  
 cf8:	74 6f                	je     d69 <_init-0x3ff687>
 cfa:	6d                   	ins    DWORD PTR es:[rdi],dx
 cfb:	69 63 5f 62 61 73 65 	imul   esp,DWORD PTR [rbx+0x5f],0x65736162
 d02:	49 69 45 38 65 78 63 	imul   rax,QWORD PTR [r13+0x38],0x68637865
 d09:	68 
 d0a:	61                   	(bad)  
 d0b:	6e                   	outs   dx,BYTE PTR ds:[rsi]
 d0c:	67 65 45 69 53 74 31 	imul   r10d,DWORD PTR gs:[r11d+0x74],0x656d3231
 d13:	32 6d 65 
 d16:	6d                   	ins    DWORD PTR es:[rdi],dx
 d17:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 d18:	72 79                	jb     d93 <_init-0x3ff65d>
 d1a:	5f                   	pop    rdi
 d1b:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 d1c:	72 64                	jb     d82 <_init-0x3ff66e>
 d1e:	65 72 00             	gs jb  d21 <_init-0x3ff6cf>
 d21:	63 6f 6d             	movsxd ebp,DWORD PTR [rdi+0x6d]
 d24:	70 61                	jo     d87 <_init-0x3ff669>
 d26:	72 65                	jb     d8d <_init-0x3ff663>
 d28:	5f                   	pop    rdi
 d29:	65 78 63             	gs js  d8f <_init-0x3ff661>
 d2c:	68 61 6e 67 65       	push   0x65676e61
 d31:	5f                   	pop    rdi
 d32:	77 65                	ja     d99 <_init-0x3ff657>
 d34:	61                   	(bad)  
 d35:	6b 00 5f             	imul   eax,DWORD PTR [rax],0x5f
 d38:	5a                   	pop    rdx
 d39:	4e 53                	rex.WRX push rbx
 d3b:	74 36                	je     d73 <_init-0x3ff67d>
 d3d:	61                   	(bad)  
 d3e:	74 6f                	je     daf <_init-0x3ff641>
 d40:	6d                   	ins    DWORD PTR es:[rdi],dx
 d41:	69 63 49 69 45 43 34 	imul   esp,DWORD PTR [rbx+0x49],0x34434569
 d48:	45 69 00 69 73 5f 6c 	imul   r8d,DWORD PTR [r8],0x6c5f7369
 d4f:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 d50:	63 6b 5f             	movsxd ebp,DWORD PTR [rbx+0x5f]
 d53:	66 72 65             	data16 jb dbb <_init-0x3ff635>
 d56:	65 00 5f 5a          	add    BYTE PTR gs:[rdi+0x5a],bl
 d5a:	4e 53                	rex.WRX push rbx
 d5c:	74 31                	je     d8f <_init-0x3ff661>
 d5e:	33 5f 5f             	xor    ebx,DWORD PTR [rdi+0x5f]
 d61:	61                   	(bad)  
 d62:	74 6f                	je     dd3 <_init-0x3ff61d>
 d64:	6d                   	ins    DWORD PTR es:[rdi],dx
 d65:	69 63 5f 62 61 73 65 	imul   esp,DWORD PTR [rbx+0x5f],0x65736162
 d6c:	49 69 45 39 66 65 74 	imul   rax,QWORD PTR [r13+0x39],0x63746566
 d73:	63 
 d74:	68 5f 61 6e 64       	push   0x646e615f
 d79:	45 69 53 74 31 32 6d 	imul   r10d,DWORD PTR [r11+0x74],0x656d3231
 d80:	65 
 d81:	6d                   	ins    DWORD PTR es:[rdi],dx
 d82:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 d83:	72 79                	jb     dfe <_init-0x3ff5f2>
 d85:	5f                   	pop    rdi
 d86:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 d87:	72 64                	jb     ded <_init-0x3ff603>
 d89:	65 72 00             	gs jb  d8c <_init-0x3ff664>
 d8c:	5f                   	pop    rdi
 d8d:	5a                   	pop    rdx
 d8e:	4e 53                	rex.WRX push rbx
 d90:	74 36                	je     dc8 <_init-0x3ff628>
 d92:	61                   	(bad)  
 d93:	74 6f                	je     e04 <_init-0x3ff5ec>
 d95:	6d                   	ins    DWORD PTR es:[rdi],dx
 d96:	69 63 49 69 45 43 34 	imul   esp,DWORD PTR [rbx+0x49],0x34434569
 d9d:	45 76 00             	rex.RB jbe da0 <_init-0x3ff650>
 da0:	5f                   	pop    rdi
 da1:	5a                   	pop    rdx
 da2:	53                   	push   rbx
 da3:	74 32                	je     dd7 <_init-0x3ff619>
 da5:	34 5f                	xor    al,0x5f
 da7:	5f                   	pop    rdi
 da8:	63 6d 70             	movsxd ebp,DWORD PTR [rbp+0x70]
 dab:	65 78 63             	gs js  e11 <_init-0x3ff5df>
 dae:	68 5f 66 61 69       	push   0x6961665f
 db3:	6c                   	ins    BYTE PTR es:[rdi],dx
 db4:	75 72                	jne    e28 <_init-0x3ff5c8>
 db6:	65 5f                	gs pop rdi
 db8:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 db9:	72 64                	jb     e1f <_init-0x3ff5d1>
 dbb:	65 72 32             	gs jb  df0 <_init-0x3ff600>
 dbe:	53                   	push   rbx
 dbf:	74 31                	je     df2 <_init-0x3ff5fe>
 dc1:	32 6d 65             	xor    ch,BYTE PTR [rbp+0x65]
 dc4:	6d                   	ins    DWORD PTR es:[rdi],dx
 dc5:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 dc6:	72 79                	jb     e41 <_init-0x3ff5af>
 dc8:	5f                   	pop    rdi
 dc9:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 dca:	72 64                	jb     e30 <_init-0x3ff5c0>
 dcc:	65 72 00             	gs jb  dcf <_init-0x3ff621>
 dcf:	6d                   	ins    DWORD PTR es:[rdi],dx
 dd0:	61                   	(bad)  
 dd1:	69 6e 00 7e 61 74 6f 	imul   ebp,DWORD PTR [rsi+0x0],0x6f74617e
 dd8:	6d                   	ins    DWORD PTR es:[rdi],dx
 dd9:	69 63 00 5f 5f 67 6e 	imul   esp,DWORD PTR [rbx+0x0],0x6e675f5f
 de0:	75 5f                	jne    e41 <_init-0x3ff5af>
 de2:	63 78 78             	movsxd edi,DWORD PTR [rax+0x78]
	...

Disassembly of section .debug_ranges:

0000000000000000 <.debug_ranges>:
   0:	46 05 40 00 00 00    	rex.RX add eax,0x40
   6:	00 00                	add    BYTE PTR [rax],al
   8:	67 06                	addr32 (bad) 
   a:	40 00 00             	add    BYTE PTR [rax],al
   d:	00 00                	add    BYTE PTR [rax],al
   f:	00 67 06             	add    BYTE PTR [rdi+0x6],ah
  12:	40 00 00             	add    BYTE PTR [rax],al
  15:	00 00                	add    BYTE PTR [rax],al
  17:	00 7b 06             	add    BYTE PTR [rbx+0x6],bh
  1a:	40 00 00             	add    BYTE PTR [rax],al
  1d:	00 00                	add    BYTE PTR [rax],al
  1f:	00 7b 06             	add    BYTE PTR [rbx+0x6],bh
  22:	40 00 00             	add    BYTE PTR [rax],al
  25:	00 00                	add    BYTE PTR [rax],al
  27:	00 a1 06 40 00 00    	add    BYTE PTR [rcx+0x4006],ah
  2d:	00 00                	add    BYTE PTR [rax],al
  2f:	00 a1 06 40 00 00    	add    BYTE PTR [rcx+0x4006],ah
  35:	00 00                	add    BYTE PTR [rax],al
  37:	00 dd                	add    ch,bl
  39:	06                   	(bad)  
  3a:	40 00 00             	add    BYTE PTR [rax],al
  3d:	00 00                	add    BYTE PTR [rax],al
  3f:	00 de                	add    dh,bl
  41:	06                   	(bad)  
  42:	40 00 00             	add    BYTE PTR [rax],al
  45:	00 00                	add    BYTE PTR [rax],al
  47:	00 e9                	add    cl,ch
  49:	06                   	(bad)  
  4a:	40 00 00             	add    BYTE PTR [rax],al
  4d:	00 00                	add    BYTE PTR [rax],al
  4f:	00 ea                	add    dl,ch
  51:	06                   	(bad)  
  52:	40 00 00             	add    BYTE PTR [rax],al
  55:	00 00                	add    BYTE PTR [rax],al
  57:	00 05 07 40 00 00    	add    BYTE PTR [rip+0x4007],al        # 4064 <_init-0x3fc38c>
	...
