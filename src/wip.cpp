#define ap ap_impl join3
#define ap_impl(f,g,x) exec f x (exec g x)

#define join3 join3_impl join_ join_
#define join3_impl(f,xs) (exec f, xs)

#define group(x...)((x)group_end
#define group_end(x...),##x)

#define delay(p1,p2) delay_0 id (p1,p2)
#define delay_0(p1,p2) p1##p2

#define collect collect_1
#define collect_1(x...) collect_2 group (x)
#define collect_2(a,...) collect_##__VA_OPT__(3)(a,__VA_ARGS__)
#define collect_3(a,b) (exec (a,(b)))
#define collect_(a,b) collect_1 id a b

#define join_(xs...) collect_2 ((xs)) () memo_1
#define memo_1(...) first (__VA_OPT__((__VA_ARGS__),)(memo_2))
#define memo_2(...) first (__VA_OPT__((__VA_ARGS__),)(memo_3))
#define memo_3(...) first (__VA_OPT__((__VA_ARGS__),)(memo_1))

#define first(x,...) x
