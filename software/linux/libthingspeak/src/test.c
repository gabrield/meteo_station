#include <thingspeak.h>
#include <ts_http.h>


int main(int argc, char **argv)
{
	ts_context_t *ctx = ts_create_context(argv[1], 16258);
	ts_datapoint_t data;
	ts_set_value_i32(&data, 31);
	//ts_http_post(ctx, HOST_API, "/update", "field1=0&field2=36&field3=21324");
	//printf("%s\n", ts_http_get(HOST_API, "/channels/16258/feed.json"));

	ts_datastream_update(ctx, 0, "field2", &data);

	ts_delete_context(ctx);
	return 0;
}