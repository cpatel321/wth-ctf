void _init()
{
    if (__gmon_start__ != 0)
        __gmon_start__();
}

int64_t sub_1020()
{
    int64_t var_8 = data_3ff0;
    /* jump -> data_3ff8 */
}

int32_t puts(char const* str)
{
    /* tailcall */
    return puts(str);
}

int64_t sub_1036()
{
    int64_t var_8 = 0;
    /* tailcall */
    return sub_1020();
}

void __stack_chk_fail() __noreturn
{
    /* tailcall */
    return __stack_chk_fail();
}

int64_t sub_1046()
{
    int64_t var_8 = 1;
    /* tailcall */
    return sub_1020();
}

int32_t printf(char const* format, ...)
{
    /* tailcall */
    return printf();
}

int64_t sub_1056()
{
    int64_t var_8 = 2;
    /* tailcall */
    return sub_1020();
}

ssize_t read(int32_t fd, void* buf, uint64_t nbytes)
{
    /* tailcall */
    return read(fd, buf, nbytes);
}

int64_t sub_1066()
{
    int64_t var_8 = 3;
    /* tailcall */
    return sub_1020();
}

void srand(uint32_t x)
{
    /* tailcall */
    return srand(x);
}

int64_t sub_1076()
{
    int64_t var_8 = 4;
    /* tailcall */
    return sub_1020();
}

int32_t __isoc99_scanf(char const* format, ...)
{
    /* tailcall */
    return __isoc99_scanf();
}

int64_t sub_1086()
{
    int64_t var_8 = 5;
    /* tailcall */
    return sub_1020();
}

int32_t rand()
{
    /* tailcall */
    return rand();
}

int64_t sub_1096()
{
    int64_t var_8 = 6;
    /* tailcall */
    return sub_1020();
}

void _start(int64_t arg1, int64_t arg2, void (* arg3)()) __noreturn
{
    int64_t stack_end_1;
    int64_t stack_end = stack_end_1;
    __libc_start_main(main, __return_addr, &ubp_av, nullptr, nullptr, arg3, &stack_end);
    /* no return */
}

void deregister_tm_clones()
{
    return;
}

void sub_1100()
{
    return;
}

void _FINI_0()
{
    if (__TMC_END__ != 0)
        return;
    
    if (__cxa_finalize != 0)
        __cxa_finalize(__dso_handle);
    
    deregister_tm_clones();
    __TMC_END__ = 1;
}

void _INIT_0()
{
    /* tailcall */
    return sub_1100();
}

int64_t xor_obfuscate(void* arg1, int32_t arg2)
{
    int32_t i;
    
    for (i = 0; i < arg2; i += 1)
        *(arg1 + i) ^= 0x11;
    
    return i;
}

int32_t main(int32_t argc, char** argv, char** envp)
{
    void* fsbase;
    int64_t rax = *(fsbase + 0x28);
    uint32_t x = -0x74524111;
    int64_t var_58;
    __builtin_memset(&var_58, 0, 0x40);
    puts("waiting for your input...");
    read(0, &var_58, 0x40);
    printf("Hello ");
    printf(&var_58);
    srand(x);
    puts("\nLet's play a guessing game!");
    puts("You need to guess three consecut…");
    int64_t var_98;
    __builtin_strncpy(&var_98, "feyjetryNr~d\x7frx}N~al", 0x14);
    int64_t s;
    __builtin_memset(&s, 0, 0x14);
    
    for (int32_t i = 0; i <= 0x13; i += 1)
        *(&s + i) = (*(&var_98 + i) ^ 0x11);
    
    for (int32_t i_1 = 0; i_1 != 3; )
    {
        int32_t rax_10 = rand();
        printf("Guess number: ");
        int32_t var_b0;
        __isoc99_scanf(&data_2095, &var_b0);
        
        if (rax_10 != var_b0)
        {
            i_1 = 0;
            puts("Incorrect");
        }
        else
        {
            printf("Correct! %d to go\n", (2 - i_1));
            i_1 += 1;
        }
    }
    
    printf("YOU FOUND THE FLAG: %s\n", &s);
    *(fsbase + 0x28);
    
    if (rax == *(fsbase + 0x28))
        return 0;
    
    __stack_chk_fail();
    /* no return */
}

int64_t _fini() __pure
{
    return;
}
