
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "json.h"


int main( int argc, char** argv )
{
	char* example = 
		"{\"target\": \"mojava://{\\\"a\\\": 1, \\\"b\\\": \\\"this\\\"}\"}";
		
	printf("example : '%s'\n", example );
                
	
	//struct json_tokener * tok;
	struct json_object* root;
	struct json_object* value;
	
	root = json_tokener_parse( example );
	
	printf("type=%d\n", json_object_get_type(root));
	
	value=json_object_object_get(root,"target");
	if( value )
	{
		printf("target value=%d '%s'\n", json_object_get_type(value),
			json_object_get_string(value));
		json_object_put(value);
	}
	
	json_object_put(root); // free
	return 0;
}
