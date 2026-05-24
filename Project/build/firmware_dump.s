
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
 1000018:	000507b7          	lui	a5,0x50
 100001c:	04000713          	li	a4,64
 1000020:	00e7ae23          	sw	a4,28(a5) # 5001c <_start-0xfaffe4>
 1000024:	000837b7          	lui	a5,0x83
 1000028:	3e800713          	li	a4,1000
 100002c:	80e7a223          	sw	a4,-2044(a5) # 82804 <_start-0xf7d7fc>
 1000030:	8007a423          	sw	zero,-2040(a5)
 1000034:	00100713          	li	a4,1
 1000038:	80e7a823          	sw	a4,-2032(a5)
 100003c:	000517b7          	lui	a5,0x51
 1000040:	c007a703          	lw	a4,-1024(a5) # 50c00 <_start-0xfaf400>
 1000044:	00276713          	ori	a4,a4,2
 1000048:	c0e7a023          	sw	a4,-1024(a5)
 100004c:	000837b7          	lui	a5,0x83
 1000050:	0e000713          	li	a4,224
 1000054:	88e7a023          	sw	a4,-1920(a5) # 82880 <_start-0xf7d780>
 1000058:	000837b7          	lui	a5,0x83
 100005c:	06400713          	li	a4,100
 1000060:	88e7a223          	sw	a4,-1916(a5) # 82884 <_start-0xf7d77c>
 1000064:	0000006f          	j	1000064 <main+0x4c>
