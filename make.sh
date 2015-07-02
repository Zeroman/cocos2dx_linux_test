#!/bin/bash - 


build()
{
    waf configure build
}

run()
{
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
        build && run
        ;;
esac
