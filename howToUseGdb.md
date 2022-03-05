gdb <programPath>
set exec-wrapper env "LD_PRELOAD=$PWD/libmy_malloc.so"
r <ARGS...> //(pour run )


bt (stack)
disassemble (donne l'asm)
info registers (donne les registres)
b <functionName> (rajoute un breakpoint qui met en pause quand le programme atteint functionName)