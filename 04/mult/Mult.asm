// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Mult.asm

// Multiplies R0 and R1 and stores the result in R2.
// (R0, R1, R2 refer to RAM[0], RAM[1], and RAM[2], respectively.)
//
// This program only needs to handle arguments that satisfy
// R0 >= 0, R1 >= 0, and R0*R1 < 32768.

// Put your code here.

	@sum
	M=0 // sum=0
	
	@i
	M=0 // i=0
	
	@R1
	D=M
	@n
	M=D // n=r1
	
(Loop)
	@i
	D=M
	@n
	D=D-M
	@Stop
	D;JEQ
	
	@sum
	D=M
	@R0
	D=D+M
	@sum
	M=D
	
	@i
	M=M+1
	
	@Loop
	0;JMP

(Stop)
	@sum
	D=M
	@R2
	M=D
	
(END)
	@END
	0;JMP
	