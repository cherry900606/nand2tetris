// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Fill.asm

// Runs an infinite loop that listens to the keyboard input.
// When a key is pressed (any key), the program blackens the screen,
// i.e. writes "black" in every pixel;
// the screen should remain fully black as long as the key is pressed. 
// When no key is pressed, the program clears the screen, i.e. writes
// "white" in every pixel;
// the screen should remain fully clear as long as no key is pressed.

// Put your code here.

	@8192
	D=A
	@size
	M=D // size=8192
	
(Loop)
	@SCREEN
	D=A
	@addr
	M=D // addr=screen base
	
	@i
	M=0
	
	@KBD
	D=M
	
	@WHITE
	D;JEQ
	@BLACK
	D;JNE
	
(WHITE)
	@i
	D=M
	@size
	D=D-M
	@Loop
	D;JEQ // i==size
	
	@addr
	A=M
	M=0
	
	@addr
	M=M+1 // next
	
	@i
	M=M+1 // i++
	
	@WHITE
	0;JMP
	
(BLACK)
	@i
	D=M
	@size
	D=D-M
	@Loop
	D;JEQ // i==size
	
	@addr
	A=M
	M=-1
	
	@addr
	M=M+1 // next
	
	@i
	M=M+1 // i++
	
	@BLACK
	0;JMP
	