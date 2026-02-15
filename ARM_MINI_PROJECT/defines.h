#ifndef DEFINES_H
#define DEFINES_H

// Macros for bit and byte level operations
// Used for register manipulation in embedded systems

/*---------------- SET A SINGLE BIT ----------------*/
// Sets (makes 1) the bit at position BP in WORD
#define SETBIT(WORD,BP)               WORD |= (1<<BP)

/*---------------- CLEAR A SINGLE BIT ----------------*/
// Clears (makes 0) the bit at position BP in WORD
#define CLEARBIT(WORD,BP)             WORD &= (~(1<<BP))

/*---------------- TOGGLE A SINGLE BIT ----------------*/
// Toggles (complements) the bit at position BP
#define CPLBIT(WORD,BP)               WORD ^= (1<<BP)

/*---------------- TEST A BIT ----------------*/
// Extracts bit at position BP and stores result (0 or 1) in WORD
// WARNING: This macro modifies WORD
#define TESTBIT(WORD,BP)              WORD = ((WORD>>BP) & 1)

/*---------------- WRITE A SINGLE BIT ----------------*/
// Writes BIT value (0 or 1) into bit position BP
#define WRITEBIT(WORD,BP,BIT)         WORD = ((WORD & ~(1<<BP)) | (BIT<<BP))

/*---------------- WRITE 4-BIT NIBBLE ----------------*/
// Writes 4-bit value (NIBBLE) starting from SBP (Starting Bit Position)
#define WRITENIBBLE(WORD,SBP,NIBBLE)  WORD = ((WORD & ~(0xF<<SBP)) | (NIBBLE<<SBP))

/*---------------- WRITE 8-BIT BYTE ----------------*/
// Writes 8-bit value (BYTE) starting from SBP
#define WRITEBYTE(WORD,SBP,BYTE)      WORD = ((WORD & ~(0xFF<<SBP)) | (BYTE<<SBP))

/*---------------- WRITE 16-BIT HALF WORD ----------------*/
// Writes 16-bit value (HWORD) starting from SBP
#define WRITEHWORD(WORD,SBP,HWORD)    WORD = ((WORD & ~(0xFFFF<<SBP)) | (HWORD<<SBP))

/*---------------- READ A BIT ----------------*/
// Reads bit at position BIT and stores result (0 or 1) in WORD
// WARNING: This macro also modifies WORD
#define READBIT(WORD,BIT)             WORD = ((WORD>>BIT) & 1)

#endif
