
/*******************************************************************************
 *
 * 	[File Name]		common_macros.h
 *
 * 	[Description]	File containing commonly used macros.
 *
 *	[Author]		Michael Magdy
 *
 ******************************************************************************/

#ifndef COMMON_MACROS_H_
#define COMMON_MACROS_H_


/* Sets BIT in REG */
#define SET_BIT(REG, BIT) (REG |= (1u << BIT))

/* Clears BIT in REG */
#define CLEAR_BIT(REG, BIT) (REG &= ~(1u << BIT))

/* Toggles BIT in REG */
#define TOGGLE_BIT(REG, BIT) (REG ^= (1u << BIT))

/* Circular Right Shift */
#define ROR(REG, SHIFT) REG = ((REG >> SHIFT) | (REG << (8u - SHIFT)))

/* Circular Left Shift */
#define ROL(REG, SHIFT) REG = ((REG << SHIFT) | (REG >> (8u - SHIFT)))

/* Checks if BIT in REG == 1 */
#define BIT_IS_SET(REG, BIT) (REG & (1u << BIT))

/* Checks if BIT in REG == 0 */
#define BIT_IS_CLEARED(REG, BIT) (!(REG & (1u << BIT)))


#endif /* COMMON_MACROS_H_ */
