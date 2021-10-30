fn main() {
    // In general, the `{}` will be automatically replaced with any arguments.
    println!("{} days", 31);

    // Without a suffix, 31 becomes an i32, 
    // but you can change it's type by providing a suffix, e.g. 31i64
    println!("{} days", 31i64);

    // There are various  optional patterns this works with.
    println!("My name is {0}, {1} {0}", "Bond", "James");

    // As can named arguments
    println!("{subject} {verb} {object}", 
                object="the lazy dog", 
                subject="the quick brown fox",
                verb="jumps over");

    // Special formatting can be specified after a `:`
    println!("{} of {:b} people know binary, the other half doesn't.", 1, 2);

    // you can right-align text with a specified width.
    println!("{number:>width$}", number=1, width=6); // `     1`
    println!("{number:0>width$}", number=1, width=6);// `000001`

    let pi = 3.141592;
    println!("Pi is roughly {:.2}", pi);
}