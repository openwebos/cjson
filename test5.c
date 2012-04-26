/*
 * Copyright (c) 2009 Hewlett-Packard Development Company, L.P.
 *
 * This library is free software; you can redistribute it and/or modify
 * it under the terms of the MIT license. See COPYING for details.
 *
 */

#include <string.h>
#include <assert.h>

#include "json.h"

#include <stdio.h>

int main()
{
	const char *obj1 = "{ }";
	const char *obj2 = "{ 'a' : 'b' }";
	const char *obj3 = "{ 'c' : 'd', 'e' : 5 }";
	const char *obj4 = "{ 'f' : 60.7, 'g' : null }";

	struct json_object *root, *value;
	struct json_object_iterator i, e;

	/* validate obj1 */
	root = json_tokener_parse(obj1);
	e = json_object_iter_end(root);
	i = json_object_iter_begin(root);
	assert (json_object_iter_equal(&i, &e));
	json_object_put(root);

	/* validate obj2 */
	root = json_tokener_parse(obj2);
	e = json_object_iter_end(root);
	i = json_object_iter_begin(root);

	assert (!json_object_iter_equal(&i, &e));
	value = json_object_iter_peek_value(&i);
	assert (0 == memcmp("a", json_object_iter_peek_name(&i), 2));
	assert (json_object_is_type(value, json_type_string));
	assert (0 == memcmp("b", json_object_get_string(value), 2));
	json_object_iter_next(&i);

	assert (json_object_iter_equal(&i, &e));
	json_object_put(root);
	
	/* validate obj3 */
	root = json_tokener_parse(obj3);
	e = json_object_iter_end(root);
	i = json_object_iter_begin(root);

	assert (!json_object_iter_equal(&i, &e));
	value = json_object_iter_peek_value(&i);
	assert (0 == memcmp("c", json_object_iter_peek_name(&i), 2));
	assert (json_object_is_type(value, json_type_string));
	assert (0 == memcmp("d", json_object_get_string(value), 2));
	json_object_iter_next(&i);

	assert (!json_object_iter_equal(&i, &e));
	value = json_object_iter_peek_value(&i);
	assert (0 == memcmp("e", json_object_iter_peek_name(&i), 2));
	assert (json_object_is_type(value, json_type_int));
	assert (5 == json_object_get_int(value));
	assert (0 == memcmp("5", json_object_get_string(value), 2));
	json_object_iter_next(&i);

	assert (json_object_iter_equal(&i, &e));
	json_object_put(root);

	/* validate obj4 */
	root = json_tokener_parse(obj4);
	e = json_object_iter_end(root);
	i = json_object_iter_begin(root);

	assert (!json_object_iter_equal(&i, &e));
	value = json_object_iter_peek_value(&i);
	assert (0 == memcmp("f", json_object_iter_peek_name(&i), 2));
	assert (json_object_is_type(value, json_type_double));
	assert (60.7 == json_object_get_double(value));
	json_object_iter_next(&i);

	assert (!json_object_iter_equal(&i, &e));
	value = json_object_iter_peek_value(&i);
	assert (0 == memcmp("g", json_object_iter_peek_name(&i), 2));
	assert (value == NULL);
	json_object_iter_next(&i);

	assert (json_object_iter_equal(&i, &e));
	json_object_put(root);

	printf("No assertions -- test passed.\n");

	return 0;
}

