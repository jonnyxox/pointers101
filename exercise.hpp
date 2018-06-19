

// Exercise 1
//   -- Add a member variable named p of type pointer-to-int to this struct
//   -- Ensure that p has an appropriate default value
struct example1 {
    int* p = 0;
};

// Exercise 2
//  -- Modify this function to return the value of the int that p points to
inline int return_value(int* p)
{
    return *p;
}

// Exercise 3
//   Here you are given a reference to an int, i
//   -- Modify this function to return the *address* of i
inline int* return_address(int& i)
{
    return &i;
}

// Exercise 4
//   -- Modify this function so that it sets the value of p's target to 12
inline void set_to_twelve(int* p)
{
    *p=12;
}

// Exercise 5
//    -- Modify this function so that it checks whether p is a valid pointer,
//       and if so, set its target to 12
//    Be careful, the test may crash if you get this wrong!
inline void maybe_set_to_twelve(int* p)
{
    if (p) {
        *p=12;
    }
}

// Exercise 6
// Now things are getting tricky!
//  -- what are the types of p1 and p2 here?
//  -- implement this function so that it swaps the pointers p1 and p2
//     (NOT their target values!)
inline void ptr_swap(int*& p1, int*& p2)
{
    int*temp = p1;
    p1 = p2;
    p2 = temp;
}
