/// All types which want to use `std::fmt` formatting `traits` require an implementation
/// to be printable. Automatic implementations are only provided for types such as in the
/// `std` library. All others must be manually implemented somehow.
/// The `fmt::Debug` `trait` makes this very straightforward. All types can `derive` (that's
/// automatically create) the `fmt::Debug` implementation so that they can be automatically 
/// printable with `{:?}`.

#[derive(Debug)]
struct Structure(i32);

#[derive(Debug)]
struct Deep(Structure);

#[derive(Debug)]
struct Person<'a> {
    name: &'a str,
    age: u8
}

fn main() {
    println!("Now {:?} will print!", Structure(3));
    println!("Now {:?} will print!", Deep(Structure(7)));

    let peter = Person { name: "Peter", age: 27 };
    println!("{:?}", peter);
    // more elegant
    println!("{:#?}", peter);
}