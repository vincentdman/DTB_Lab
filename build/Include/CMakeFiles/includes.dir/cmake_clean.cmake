file(REMOVE_RECURSE
  "libincludes.a"
  "libincludes.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/includes.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
