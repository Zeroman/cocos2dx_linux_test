
if filereadable("../src/tags")
set tags+=../src/tags
endif
if filereadable("../src/cscope.out")
execute "cscope add ../src/cscope.out"
endif
    
