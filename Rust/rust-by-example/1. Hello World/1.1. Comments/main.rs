/// Doc comments which are parsed into HTML library documentation
/// + `///` Generate library docs for the **following** item.
/// + `//!` Generate library docs for the **enclosing** item.
/// NOTE rustdoc does not generate documentation for statements
fn main() {
    // Line comments which go to the end of the line.
    /* block comments which go to the closing delimiter */

    let x = 5 + /* 90 + */ 5;
    println!("Is `x` 10 or 100? x = {}", x);
}