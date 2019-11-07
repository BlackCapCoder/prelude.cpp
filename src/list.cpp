// cons an element onto a list
// cons (1) (2,3) == (1,2,3)
#define cons cons_0 join2
#define cons_0(x,xs) (copure x,copure xs)

// Separates a list into its head and tail. Dual to cons
// uncons (1,2,3) == (1) (2,3)
// uncons cons == id
#define uncons(x,...) (x) __VA_OPT__((__VA_ARGS__))

// The head of a list
// head (1,2,3) == (1)
// #define head pop swap uncons
#define head(x,...) (x)

// The tail of a list
// tail (1,2,3) == (2,3)
// #define tail pop uncons
#define tail(_,...) (__VA_ARGS__)

// branch on empty
// null (yes) (no) ()  == yes
// null (yes) (no) (1) == no
#define null null_0 join
#define null_0(t,f) null_1 cons (t,f)
#define null_1(t,f,...) copure head tail (__VA_OPT__(,f),t,__VA_ARGS__)


// map a function over a list
// map (f) (1,2,3) == (f (1), f (2), f (3))
#define map map_0 cons
#define map_0(f,...) (exec null (pop) (map_1) (__VA_ARGS__) (f,__VA_ARGS__))
#define map_1(f,x,...) f(x)__VA_OPT__(, map_2 id () (f,__VA_ARGS__))
#define map_2() map_1


