#ifdef __GNUC__
#  define UNUSED(x) UNUSED_ ## x __attribute__((__unused__))
#else
#  define UNUSED(x) UNUSED_ ## x
#endif

#include <string.h>
#include <sqlite3ext.h>
SQLITE_EXTENSION_INIT1

static void hunupper(sqlite3_context *ctx, int argc, sqlite3_value **argv)
{
	const unsigned char *input;
	int length, pos = 0;
	unsigned char *result;

	if (argc != 1) {
		sqlite3_result_error(ctx, "invalid number of arguments", -1);
		return;
	}

	input = (const unsigned char *) sqlite3_value_text(argv[0]);
	if (!input) {
		sqlite3_result_error(ctx, "no input specified", -1);
		return;
	}

	length = strlen((const char*) input);
	result = (unsigned char *)sqlite3_malloc(length);
	if (!result) {
		sqlite3_result_error(ctx, "cannot allocate result", -1);
		return;
	}

	while (pos < length) {
		result[pos] = input[pos] >= 'a' && input[pos] <= 'z' ? 0xDF & input[pos] : input[pos];
		switch (input[pos++]) {
			case 0xc3: /* á-a1>81 é-a9>89 í-ad>8d ó-b3>93 ö-b6>96 ú-ba>9a ü-bc>9c */
				result[pos] = input[pos] & 0xdf;
				pos++;
				break;
			case 0xc5: /* ő-91>90 ű-b1>b0 */
				result[pos] = input[pos] & 0xfe;
				pos++;
				break;
		}
	}

	sqlite3_result_text(ctx, (char *)result, length, sqlite3_free);
	return;
}

int sqlite3_extension_init(sqlite3 *db, char** UNUSED(err), const sqlite3_api_routines *api)
{
	SQLITE_EXTENSION_INIT2(api)
	sqlite3_create_function(db, "HUNUPPER", 1, SQLITE_UTF8, NULL, hunupper, NULL, NULL);
	return 0;
}
