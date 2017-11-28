
// Add member variables to the following struct, with the correct names and types

struct example2 {

    // Example: Add a member variable named pi of type "pointer to int"
    int* pi = nullptr;

    // Add a member variable named pci of type "pointer to const int"


    // Add a member variable named cpi of type "const pointer to int"


    // Add a member variable named cpci of type "const pointer to const int"


    // Add a member variable named ppf of type "pointer to pointer to float"


    // Add a member variable named pcpf of type "pointer to const pointer to float"


    // Add a member variable named rcppcpd of type
    // "reference to const pointer to pointer to const pointer to double"



    // ...and for experts, a real challenge involving function pointers!
    // Add a member variable named cpfunc of type
    // "const pointer to function
    //    -- taking a const pointer to a function
    //           -- taking a pointer to an int
    //           -- returning a pointer to a const int
    //    -- returning a pointer to a function
    //           -- taking a pointer to an int
    //           -- returning a pointer to a const int
    // See if you can do it without an intermediate typedef!


};