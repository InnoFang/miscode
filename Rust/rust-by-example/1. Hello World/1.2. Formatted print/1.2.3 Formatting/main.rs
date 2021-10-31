use std::fmt::{self, Formatter, Display};

#[derive(Debug)]
struct Color {
    red: u8,
    green: u8,
    blue: u8,
}

impl Display for Color {
    fn fmt(&self, f: &mut Formatter) -> fmt::Result {
        write!(f, "RGB ({0}, {1}, {2}) 0x{0:02X}{1:02X}{2:02X}", self.red, self.green, self.blue)
    }
}

fn main() {
    for color in [
        Color { red: 128, green: 255, blue:  90 },
        Color { red:   0, green:   3, blue: 254 },
        Color { red:   0, green:   0, blue:   0 },
    ].iter() {
        println!("{}", *color);
    }
}