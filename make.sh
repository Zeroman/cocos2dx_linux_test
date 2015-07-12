#!/bin/bash - 

cur_path=$(readlink -f $0)
cur_dir=${cur_path%/*}


cocos_src_dir=/work/src/game/cocos2d-x/src
cocos_build_dir=/work/src/game/cocos2d-x/build_linux

build()
{
    waf configure build
    # waf configure build -v
    # waf configure build -vv
    # waf configure build -vvv
}

run()
{
    export LD_LIBRARY_PATH=$(readlink -f libs)
    ln -snf ../Resources build/Resources
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
execute "cscope add ../src/cscope.out"
endif
    ' > .exrc
}

gen_tags()
{
    FIND='/usr/bin/find'
    CTAGS='/usr/bin/ctags --c++-kinds=+p --c-kinds=+px-n --fields=+iatfS --extra=+q -I __wur,__THROW,__nonnull+'
    CSCOPE='/usr/bin/cscope -bkq' 

    temp_list=$(mktemp)
    $FIND $cur_dir -type f -name '*.h' >> $temp_list
    $FIND $cur_dir -type f -name '*.c' >> $temp_list
    $FIND $cur_dir -type f -name '*.cpp' >> $temp_list
    if [ $# == 0 ];then
        tags_target=tags
        cscope_target=cscope.out
    else
        tag_name=$1
        tags_target=${tag_name}.tags
        cscope_target=${tag_name}.out
    fi

    echo "generate $tags_target..."
    $CTAGS -L $temp_list -f $tags_target
    echo "generate $cscope_target"
    $CSCOPE -i$temp_list -f${cscope_target}
    rm -f $temp_list
}

update_tags()
{
    if git diff --name-only . | grep -E '\.cpp|\.c|\.h';then
        gen_tags
    fi
}

update_libs()
{
    mkdir -p $cur_dir/libs

    cd $cur_dir/libs

    rm -fv *.a *.so

    cp -fv $cocos_build_dir/lib/*.a .

    external_libs=$(find $cocos_src_dir/external -name '*.a' | grep linux/64-bit | xargs)
    cp -fv $external_libs .
    external_libs=$(find $cocos_src_dir/external/linux-specific -name '*.so' | grep 64-bit | xargs)
    cp -fv $external_libs .

}

cd $cur_dir

case $1 in
    b|build)
        build
        ;;
    r|run)
        build && run
        ;;
    libs)
        update_libs
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


