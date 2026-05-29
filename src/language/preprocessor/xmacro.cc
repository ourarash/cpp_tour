enum Tokens {
#define TOKEN(a, b, c) a,
#include "tokens.h"
#undef TOKEN
};

static const char* Names_data[] = {
#define TOKEN(a, b, c) #a,
#include "tokens.h"
#undef TOKEN
};

static const char* Values_data[] = {
#define TOKEN(a, b, c) b,
#include "tokens.h"
#undef TOKEN
};

static const int Lengths_data[] = {
#define TOKEN(a, b, c) c,
#include "tokens.h"
#undef TOKEN
};
