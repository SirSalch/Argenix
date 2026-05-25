
/home/slach/ARGENTIX/Argentix-Public-Version/Project/build/firmware.elf:     file format elf32-littleriscv


Disassembly of section .text:

01000000 <_start>:
 1000000:	02004137          	lui	sp,0x2004
 1000004:	00010113          	mv	sp,sp
 1000008:	000507b7          	lui	a5,0x50
 100000c:	00400713          	li	a4,4
 1000010:	00e7aa23          	sw	a4,20(a5) # 50014 <_start-0xfaffec>
 1000014:	004000ef          	jal	1000018 <main>

01000018 <main>:
 1000018:	0000006f          	j	1000018 <main>
