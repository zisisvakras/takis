use std::io;

fn main() {

    /* Creating variable */
    let mut stairs = String::new();
    let mut temp: u128;
    let mut a: u128 = 0;
    let mut b: u128 = 1;

    /* Getting user input */
    println!("\nNumber of stairs: ");
    io::stdin().read_line(&mut stairs).expect("Couldn't read line!");
    
    /* Shadowing to integer */
    let stairs: usize = stairs.trim().parse().expect("Please input an integer!");
    
    /* 
    * Calculating the n + 2 number of the
    * fibonacci sequence as described in solution.
    */
    for _i in 0..stairs {
        temp = a + b;
        a = b;
        b = temp;
    }

    /* Printing result */
    println!("\nAnswer: {b} ways");
}
