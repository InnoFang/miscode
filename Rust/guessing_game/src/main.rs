use std::io;
use std::cmp::Ordering;
use rand::Rng;


fn main() {
    println!("Guess Game!");
    println!("input your guess");
    let answer = rand::thread_rng().gen_range(1, 101);

    loop {
        let mut guess = String::new();
        io::stdin().read_line(&mut guess).expect("cannot read line properly!");
        
        let guess: u32 = match guess.trim().parse() {
            Ok(num) => num,
            Err(_) => continue,
        };

        match guess.cmp(&answer) {
            Ordering::Less => println!("Too low"),
            Ordering::Greater => println!("Too high"),
            Ordering::Equal => {
                println!("Correct!");
                break;
            }
        }
    }
}
