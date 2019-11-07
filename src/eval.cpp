// eval forces macro expansion
#define eval eval_0
#define eval_0(...) eval_1(eval_1(eval_1(__VA_ARGS__)))
#define eval_1(...) eval_2(eval_2(eval_2(__VA_ARGS__)))
#define eval_2(...) eval_3(eval_3(eval_3(__VA_ARGS__)))
#define eval_3(...) eval_4(eval_4(eval_4(__VA_ARGS__)))
#define eval_4(...) eval_5(eval_5(eval_5(__VA_ARGS__)))
#define eval_5(...) eval_6(eval_6(eval_6(__VA_ARGS__)))
#define eval_6(...) eval_7(eval_7(eval_7(__VA_ARGS__)))
#define eval_7(...) eval_8(eval_8(eval_8(__VA_ARGS__)))
#define eval_8(...) eval_9(eval_9(eval_9(__VA_ARGS__)))
#define eval_9(...) __VA_ARGS__


// stepN expands its argument N times
#define step0
#define step1(...) step0  __VA_ARGS__
#define step2(...) step1 (__VA_ARGS__)
#define step3(...) step2 (__VA_ARGS__)
#define step4(...) step3 (__VA_ARGS__)
#define step5(...) step4 (__VA_ARGS__)
#define step6(...) step5 (__VA_ARGS__)
#define step7(...) step6 (__VA_ARGS__)
#define step8(...) step7 (__VA_ARGS__)
#define step9(...) step8 (__VA_ARGS__)
#define step10(...) step9 (__VA_ARGS__)
#define step11(...) step10 (__VA_ARGS__)
#define step12(...) step11 (__VA_ARGS__)
#define step13(...) step12 (__VA_ARGS__)
#define step14(...) step13 (__VA_ARGS__)
#define step15(...) step14 (__VA_ARGS__)
#define step16(...) step15 (__VA_ARGS__)
