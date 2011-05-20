#ifndef PHP_CITYHASH_H
/* Prevent double inclusion */
#define PHP_CITYHASH_H

/* Define Extension Properties */
#define PHP_CITYHASH_EXTNAME "CityHash"
#define PHP_CITYHASH_EXTVER  "1.0.1"

/* Import configure options
   when building outside of
   the PHP source tree */
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

/* Include PHP Standard Header */
#include "php.h"

/* Define the entry point symbol
   Zend will use when loading this module
*/
extern zend_module_entry cityhash_module_entry;
#define phpext_sample_ptr &cityhash_module_entry

#endif
