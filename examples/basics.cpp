#include "src/eval.cpp"

#define example(...)

// 'make test' to run the examples
// Replace instances of 'example' with 'eval' to see the output


// ----------------------


// cpp is a concatative language with shared memory/code space.
// There are 2 datatypes in cpp:

example (

  // Arrays:
  (This, is, an, array)

  // Strings:
  This is a string

)


// All functions take exactly one array as their only argument,
// and you can pattern match on the array:

example (

  #define fun(x,y,...)\
    first: x, second: y, rest: __VA_ARGS__

  fun (1,2, 3,4) // first: 1, second: 2, rest: 3,4
)


// ----------------------
// Evaluation

#define pop(...)


// Fully evaluated so produces no output
pop () pop () pop ()
pop () pop () pop ()


example (

  // Only the rightmost pop is evaluated
  pop pop () () // ()

  step0 (
    pop pop () () // ()
  )

  // Both pops are evaluated
  step1 (
    pop pop () () // no output
  )
)


// ----------------------

#include "src/function.cpp"
#include "src/stack.cpp"


example (
  id (1) // (1)
)


example (
  pop (1) (2) (3) // (2) (3)
)

example (
  dup (1) (2) (3) // (1) (1) (2) (3)
)

// pop dup == id
example (
  pop dup (1) (2) (3) // (1) (2) (3)
)


example (
  pure (1, 2) (3) // ((1, 2)) (3)
)

example (
  copure ((1, 2)) (3) // (1, 2) (3)
)

// copure pure == id
example (
  copure pure (1, 2) (3) // (1, 2) (3)
)


// NOTE: copure join != id
example (
  join (1,2) (3,4) (5) // ((1,2),(3,4)) (5)
)

example (
  cojoin join (1,2) (3,4) (5) // (1,2) (3,4) (5)
)

// swap swap == id
example (
  swap (1) (2) (3) // (2) (1) (3)
)

