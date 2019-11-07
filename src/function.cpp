// The identity function
// id (x) == (x)
#define id(...) (__VA_ARGS__)

// Returns its first argument
// const (1) (2) == (1)
#define const(...) (__VA_ARGS__) pop

// Flips the arguments of a function
// exec flip (f) (1) (2) == exec (f) (2) (1)
#define flip(f) (f swap)

// Finds the fixed point of a function
#define fix(f) f (fix_0 id () (f))
#define fix_0(f) fix

#define delay(f) f id ()
