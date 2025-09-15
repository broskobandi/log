/* Include the library. */
#include <log.h>

int divide(int a, int b, float *result) {
	LOG("Entering function.");
	LOG("Validating input...");
	if (b == 0) {
		LOG("b cannot be 0.");
		return 1;
	}
	LOG("Executing function logic...");
	*result = (float)a / (float)b;
	LOG("Task finished successfully.");
	return 0;
}

int main(void) {
	LOG("Entering function.");
	float result = 0.0f;
	LOG("Calling vidide().");
	if (divide(10, 0, &result)) {
		LOG("divide() failed.");
		return 1;
	}
	LOG("Exiting main().");
	return 0;
}

/* */
