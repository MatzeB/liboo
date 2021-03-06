#ifndef LIBOO_RT_H
#define LIBOO_RT_H

#include <stdbool.h>
#include "liboo/rts_types.h"
#include "types.h"

/* declarations for runtime interface. (Though most users probably won't use
 * this from a C-Compiler... */

void oo_rt_abstract_method_error(void);
bool oo_rt_instanceof(const class_info_t *objclass,
                      const class_info_t *refclass);
void *oo_rt_lookup_interface_method(const class_info_t *klass,
                                    const string_const_t *method_name);
void *oo_searched_itable_method(const object_t *obj, void *interface_id,
                                int32_t offset);
void *oo_searched_itable_method_m2f(const object_t *obj, void *interface_id,
                                    int32_t offset);
#endif
