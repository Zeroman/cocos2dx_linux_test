#!/bin/bash - 


build()
{
    waf configure build
}

run()
{
    export LD_LIBRARY_PATH=$(readlink -f ../lib)
    ln -sf ../Resources build/Resources
    ./build/main
}

clean()
{
    rm -rf build
}

gen_exrc()
{
    echo '
if filereadable("../src/tags")
set tags+=../src/tags
endif
if filereadable("../src/cscope.out")
execute 'cscope add ../src/cscope.out'
endif
    ' > .exrc
}

update_tags()
{
    if git diff --name-only . | grep -E '\.cpp|\.c|\.h';then
        ~/bin/gen_tags
    fi
}

case $1 in
    b|build)
        build
        ;;
    r|run)
        build && run
        ;;
    c|clean)
        clean
        ;;
    exrc)
        gen_exrc
        ;;
    *)
        update_tags
        build && run
        ;;
esac


