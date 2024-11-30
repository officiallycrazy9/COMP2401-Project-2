#include "defs.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* Resource functions */

/**
 * Creates a new `Resource` object.
 *
 * Allocates memory for a new `Resource` and initializes its fields.
 * The `name` is dynamically allocated.
 *
 * @param[out] resource      Pointer to the `Resource*` to be allocated and initialized.
 * @param[in]  name          Name of the resource (the string is copied).
 * @param[in]  amount        Initial amount of the resource.
 * @param[in]  max_capacity  Maximum capacity of the resource.
 */
void resource_create(Resource **resource, const char *name, int amount, int max_capacity) {
	if (!resource || !name) return;//check if either are null

    *resource = (Resource *)malloc(sizeof(Resource));//malloc the new resource object
    if (!*resource) return;//exit if malloc fails

    (*resource)->name = strdup(name);//duiplicate the resource name and set
    if (!(*resource)->name) {
        free(*resource);//free the malloc for the resource if duplication fails
        *resource = NULL;
        return;
    }

    (*resource)->amount = amount;//initilize the resources amount and max capacity
    (*resource)->max_capacity = max_capacity;
}

/**
 * Destroys a `Resource` object.
 *
 * Frees all memory associated with the `Resource`.
 *
 * @param[in,out] resource  Pointer to the `Resource` to be destroyed.
 */
void resource_destroy(Resource *resource) {
	if (!resource) return;//check null
    free(resource->name);//free malloc for the resources name
    free(resource);//same for the resource object
}

/* ResourceAmount functions */

/**
 * Initializes a `ResourceAmount` structure.
 *
 * Associates a `Resource` with a specific `amount`.
 *
 * @param[out] resource_amount  Pointer to the `ResourceAmount` to initialize.
 * @param[in]  resource         Pointer to the `Resource`.
 * @param[in]  amount           The amount associated with the `Resource`.
 */
void resource_amount_init(ResourceAmount *resource_amount, Resource *resource, int amount) {
    resource_amount->resource = resource;
    resource_amount->amount = amount;
}

/**
 * Initializes the `ResourceArray`.
 *
 * Allocates memory for the array of `Resource*` pointers and sets initial values.
 *
 * @param[out] array  Pointer to the `ResourceArray` to initialize.
 */
void resource_array_init(ResourceArray *array) {
	if (!array) return;//check null

    array->resources = (Resource **)malloc(sizeof(Resource *));//malloc for the array resource pointers
    if (!array->resources) return;

    array->size = 0;
    array->capacity = 1;

}

/**
 * Cleans up the `ResourceArray` by destroying all resources and freeing memory.
 *
 * Iterates through the array, calls `resource_destroy` on each `Resource`,
 * and frees the array memory.
 *
 * @param[in,out] array  Pointer to the `ResourceArray` to clean.
 */
void resource_array_clean(ResourceArray *array) {
	if (!array) return;//check for null

    for (int i = 0; i < array->size; ++i) {//go through each resource and destroy it
        resource_destroy(array->resources[i]);
    }

    free(array->resources);//free array
    array->resources = NULL;
    array->size = 0;
    array->capacity = 0;

}

/**
 * Adds a `Resource` to the `ResourceArray`, resizing if necessary (doubling the size).
 *
 * Resizes the array when the capacity is reached and adds the new `Resource`.
 * Use of realloc is NOT permitted.
 * 
 * @param[in,out] array     Pointer to the `ResourceArray`.
 * @param[in]     resource  Pointer to the `Resource` to add.
 */
void resource_array_add(ResourceArray *array, Resource *resource) {
	if (!array || !resource) return;//check if either are null

    if (array->size >= array->capacity) {
        int new_capacity = array->capacity * 2;//double if full array and malloc the new array
        Resource **new_resources = (Resource **)malloc(new_capacity * sizeof(Resource *));
        if (!new_resources) return;

        for (int i = 0; i < array->size; ++i) {//copy exisiting resources to new array
            new_resources[i] = array->resources[i];
        }

        free(array->resources);//free old array and update the array pointer the the new one
        array->resources = new_resources;
        array->capacity = new_capacity;
    }

    array->resources[array->size++] = resource;//add new resource to the array

}
