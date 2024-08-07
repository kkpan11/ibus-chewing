#include "MakerDialogUtil.h"
#include "test-util.h"
#include <glib.h>
#define TEST_RUN_THIS(f) add_test_case("MakerDialogUtil", f)

/**************************************
 * String Utility Macros
 */

void QUOTE_ME_test() {
#define PRJ_TEST MKDG
    g_assert_cmpstr("MKDG", ==, QUOTE_ME(PRJ_TEST));
#undef PRJ_TEST
}

void STRING_IS_EMPTY_test() {
    gchar *nulStr = NULL;

    g_assert(STRING_IS_EMPTY(nulStr));
    g_assert(STRING_IS_EMPTY(""));
    g_assert(!STRING_IS_EMPTY("NULL"));
}

void STRING_EQUALS_test() {
    gchar *nulStr = NULL;

    g_assert(STRING_EQUALS("", ""));
    g_assert(!STRING_EQUALS("", nulStr));
    g_assert(STRING_EQUALS(nulStr, nulStr));
    g_assert(!STRING_EQUALS("HI", "Hi"));
    g_assert(STRING_EQUALS("YO\"", "YO\""));
}

gint main(gint argc, gchar **argv) {
    g_test_init(&argc, &argv, NULL);
    TEST_RUN_THIS(QUOTE_ME_test);
    TEST_RUN_THIS(STRING_IS_EMPTY_test);
#if 0
    TEST_RUN_THIS(STRING_EQUALS_test);
#endif
    return g_test_run();
}
