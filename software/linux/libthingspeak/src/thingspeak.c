#include <thingspeak.h>


ts_context_t *ts_create_context(char *api_key, ts_feed_id_t feed_id)
{
	ts_context_t *ctx = (ts_context_t*)malloc(sizeof(ts_context_t));

	ctx->api_key = api_key;
	ctx->feed_id = feed_id;

	return ctx;
}


void ts_delete_context(ts_context_t *ctx)
{
	if(ctx)
		free(ctx);
}



ts_datapoint_t *ts_set_value_i32(ts_datapoint_t *datapoint, int32_t val)
{
	datapoint->value_type = TS_VALUE_TYPE_I32;
	datapoint->value.i32_value = val;
	return datapoint;
}


int32_t ts_get_value_i32(ts_datapoint_t *datapoint)
{
	return datapoint->value.i32_value;
}


ts_datapoint_t *ts_set_value_f32(ts_datapoint_t *datapoint, float val)
{
	datapoint->value_type = TS_VALUE_TYPE_F32;
	datapoint->value.f32_value = val;
	return datapoint;
}

float ts_get_value_f32(ts_datapoint_t *datapoint)
{
	return datapoint->value.f32_value;
}





