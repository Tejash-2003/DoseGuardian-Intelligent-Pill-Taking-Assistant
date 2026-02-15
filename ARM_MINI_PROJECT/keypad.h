// ===================== KEYPAD FUNCTION DECLARATIONS =====================

// Initialize keypad GPIO pins
// Configures rows as output and columns as input (or vice versa)
// Enables pull-up/down resistors if required
void KeypadInit(void);

// Read pressed key value
// Returns ASCII value of pressed key (e.g., '1', '2', 'A', etc.)
char Readkeyval(void);

// Check column status
// Returns non-zero if no key is pressed
// Returns 0 when a key press is detected
int ColStat(void);
