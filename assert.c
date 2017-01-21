#include <stdio.h>
#include <stdlib.h>

#define static_assert(condition, message) \
{\
    __attribute__((error("\e[33;40;1m"message"\e[0m"))) void static_assert_error();\
    if (!(condition))\
        static_assert_error();\
}

#define assert_constant(expression) \
({\
    __attribute__((error("\e[33;40;1m""\""#expression"\" is not a constant expression""\e[0m"))) void assert_constant_error();\
    if (!(__builtin_constant_p(expression)))\
        assert_constant_error();\
    expression;\
})

int main (void)
{
    int r = 5;
    scanf("%d", &r); /* this causes the assert constant error */
    int d = assert_constant(r);
    printf("%d\n", d);

    return 0;
}
