# C utils 

C utilities to make C more accessible modern software developers and ship :rocket:

## :star: Features :star:

This library provides simple quality of life improvements, such as:

- Golang-like error handling (with the "goerr.h" header file) :star_struck: 
- Rust\* inspired Result type and integer types (with the "rust_result.h" and "rust_inttypes.h" header files) :crab: 
- COBOL-type EVALUATE statement (with the "COBOL_EVALUATE.h" header file) :card_file_box: 
- Kotlin `Unit` and `Any` types (with the "kotlinUnitAny.h" header file) :seedling:
- Java inspired `new` statement (with the "JavaNew.h" header file) :technologist:
- For our python users, use drop instead of free (with the "DropForFree.h" header file) :snake:
- most used Javascript console functions, such as `console.log`, `console.error` and many more! (with the "JavaScript_console.h" header file) :desktop_computer:

## :chains: Install and linking :chains:

To install this library, you can simply run these commands:

```bash
git clone git@github.com:EcklerOChokola/C-Utils.git
./install
```

The install script will put all the header files in the `/usr/local/include/c_utils` directory (this will necessitate super user permissions)

If you want to install them elsewhere, simply edit the `locatio` variable at the top of the script, or you can copy the files to the desired location

## :wrench: Use :wrench:

Obviously, all these libraries can be used either separately, or by including the "c_utils/libs.h" header file, which includes everything you'll need to code :zap: blazingly fast :zap: 

## Special cases :bangbang:

### The Javascript console

To use the Javascript console commands, you first need to initialise our custom Javascript runtime

To do this, you first need to write the following statement at the top of your file (before including the header files):
```c
#define _CONSOLE_IMPLEMENTATION
```

You then have to initialise the runtime to use the console. You can do this by using the `init_console` function

After using the console, you need to drop the runtime to avoid multiple Javascript runtimes. Just use the `destroy_console` function to achieve this

**Example**

```c
#ifndef _CONSOLE_IMPLEMENTATION
#define _CONSOLE_IMPLEMENTATION
#endif

#include<c_utils/libs.h>

Result(Unit, Any) main(Unit)
{
    init_console(); // Creates the Javascript runtime

    console.log("Hello, World!\n"); 
    // Hello, World!

    int test = 8;
    console.warn("%d\n", test);
    // [WARNING] - 8

    destroy_console(); // Destroys the Javascript runtime
    Ok()
}
```

\*the use of the "Rust" name in this project was not endorsed by the Rust foundation, and will never be because this is an obvious shitpost, please don't sue me rustaceans
