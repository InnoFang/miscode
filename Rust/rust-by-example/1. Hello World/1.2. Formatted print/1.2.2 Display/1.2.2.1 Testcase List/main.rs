/// implementing `fmt::Display` for a structure where the elements must each be handled 
/// sequentially is tricky. The problem is that each `write!` generates a `fmt::Result`.
/// Proper handling of this requires dealing with all the results. Rust provides the `?`
/// operator for exactly this purpose.

use std::fmt;

// Define a structure named `List` containing a `Vec`
struct List(Vec<i32>); 

impl fmt::Display for List {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        // Extract the value using tuple indexing,
        // and create a reference to `vec`
        let vec = &self.0;

        // if it errors, return the error. Otherwise continue.
        write!(f, "[")?;

        // Iterate over `v` in `vec` while enumerating the iteration
        // count in `count`.
        for (idx, v) in vec.iter().enumerate() {
            // For every element except the first, add a comma.
            // Use the ? operator to return on errors.
            if idx != 0 {
                write!(f, ", ")?;
            }
            write!(f, "{}: {}", idx, v)?;
        }
        write!(f, "]")
    }
}

fn main() {
    let v = List(vec![1, 2, 3]);
    println!("{}", v);
}
