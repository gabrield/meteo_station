#include <thingspeak.h>
#include <ts_http.h>


int main()
{
	ts_context_t *ctx = ts_create_context("VSENWUK8C3YI1JTL", 16258);

	ts_http_post(ctx, HOST_API, "/update", "field1=1&field2=31&field3=31223");
	ts_delete_context(ctx);
	return 0;
}