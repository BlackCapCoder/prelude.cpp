// The identity function
// id x == x
#define id(...) (__VA_ARGS__)


// Delete the topmost element on the stack
#define pop(...)

// Duplicate the topmost element on the stack. Dual to pop
// pop dup == id
#define dup(...) (__VA_ARGS__) (__VA_ARGS__)


// Wrap an element in a singleton array
#define pure(...) ((__VA_ARGS__))

// Unpacks an array onto the stack. Dual to pure
// copure pure == id
#define copure(...) __VA_ARGS__

// Handy alias for copure
// exec == step1
#define exec copure


// Concatenate the two topmost elements on the stack
// join (1,2) (3,4) == ((1,2),(3,4))
#define join join_0
#define join_0(...) ((__VA_ARGS__),join_1
#define join_1(...) (__VA_ARGS__))

// Dual to join
// cojoin join == id
#define cojoin(x,...) x __VA_OPT__ (cojoin_0 id () (__VA_ARGS__))
#define cojoin_0() cojoin


// Pop an array and unpack it after the next element on the stack
// dip (pop) (1) (2) (3) == (1) (3)
// dip (dup) (1) (2) (3) == (1) (2) (2) (3)
#define dip dip_0 join
#define dip_0(f,x) x copure f

// swap the two topmost elements on the stack
// swap (1) (2) (3) == (2) (1) (3)
// swap swap == id
#define swap dip pure


// Returns its first argument
// const (1) (2) == (1)
#define const(...) (__VA_ARGS__) pop

// Flips the arguments of a function
// exec flip (f) (1) (2) == exec (f) (2) (1)
#define flip(f) (f swap)
