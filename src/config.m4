PHP_ARG_WITH(cityhash, for CityHash library support,
  [  --with-cityhash       Include "CityHash" extension support])

if test $PHP_CITYHASH != "no"; then
  PHP_REQUIRE_CXX()
  PHP_NEW_EXTENSION(cityhash, cityhash.cpp, $ext_shared)
  PHP_SUBST(CITYHASH_SHARED_LIBADD)
  PHP_ADD_LIBRARY_WITH_PATH(stdc++, /usr/lib/, CITYHASH_SHARED_LIBADD)
  PHP_ADD_LIBPATH(/usr/local/lib, CITYHASH_SHARED_LIBADD)
  PHP_ADD_LIBRARY(cityhash,, CITYHASH_SHARED_LIBADD)
  PHP_ADD_INCLUDE(/usr/local/include)
fi