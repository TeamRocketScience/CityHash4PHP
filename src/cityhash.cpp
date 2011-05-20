#include "php_cityhash.h"
#include "city.h"

PHP_FUNCTION(CityHash64)
{
  char *str;
  int len;
  if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", 
                   &str, &len) == FAILURE) 
  {
    RETURN_NULL();
  }

  uint64 hash = CityHash64(str, len);
  char *hash_str = (char *)emalloc(21);
  sprintf(hash_str, "%llu", hash);
  RETVAL_STRING(hash_str, 0);
}

PHP_FUNCTION(CityHash128)
{
  char *str;
  int len;
  if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", 
                   &str, &len) == FAILURE) 
  {
    RETURN_NULL();
  }

  uint128 hash = CityHash128(str, len);
  char *hash_str = (char *)emalloc(43);
  sprintf(hash_str, "%llu%llu", hash.first, hash.second);
  RETVAL_STRING(hash_str, 0);
}

/* TODO:
	uint64 CityHash64WithSeed(const char *buf, size_t len, uint64 seed);
	uint64 CityHash64WithSeeds(const char *buf, size_t len, uint64 seed0, uint64 seed1);
	uint128 CityHash128(const char *s, size_t len);
	uint128 CityHash128WithSeed(const char *s, size_t len, uint128 seed);
*/

static function_entry php_cityhash_functions[] = {
  PHP_FE(CityHash64, NULL)
  PHP_FE(CityHash128, NULL) 
  { NULL, NULL, NULL }
};

zend_module_entry cityhash_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
     STANDARD_MODULE_HEADER,
#endif

     PHP_CITYHASH_EXTNAME,
     php_cityhash_functions, /* Functions */
     NULL, /* MINIT */
     NULL, /* MSHUTDOWN */
     NULL, /* RINIT */
     NULL, /* RSHUTDOWN */
     NULL, /* MINFO */
#if ZEND_MODULE_API_NO >= 20010901
     PHP_CITYHASH_EXTVER,
#endif
     STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_CITYHASH
ZEND_GET_MODULE(cityhash)
#endif

