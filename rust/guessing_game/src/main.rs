use std::io; // use io from std (including stdin, stdout...)
use std::cmp::Ordering;
use rand::Rng;

fn main() {
    println!("Guess the number");
    let secret_number = rand::thread_rng().gen_range(1..=100);
    loop {
     	println!("Please input your guess");
     	
    	let mut guess = String::new(); // mut = mutable var
    	// immutabmle would be : let guess = ...
    	
    	io::stdin()
    		.read_line(&mut guess)
    		.expect("Failed to read line"); // catching error
    		// read_line returns the string we pass to it 
    		// but also Result -> Ok or Err
    		
    	// u32: 32-bit unsigned integer type
    	// let guess -> shadowing previous var
    	// shadowing means allowing Rust to use this var again
    	// let guess: u32 = guess.trim().parse().expect("Please type a number!");
    	let guess: u32 = match guess.trim().parse() {
            Ok(num) => num,
            Err(_) => continue,
        };
    	
    	println!("You guess {guess}"); // {} is a placeholder
    
    	match guess.cmp(&secret_number) {
        	Ordering::Less => println!("Too small!"),
        	Ordering::Greater => println!("Too big!"),
        	Ordering::Equal => {
                println!("You win!");
                break;
            }
    	}   	
    }

}
