#ifndef _RUST_RESULT
#define _RUST_RESULT

// Result<X, Y> does only support the first type because i don't care enough to make it better, sue me
#define Result(X,Y) X
#define Err(X) return X;
#define Ok(X) return X;

#endif

