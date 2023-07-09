//TODO EDIT

use std::io;

fn main() {
    
    /* Creating variables */
    let mut rows = String::new();
    let mut cols = String::new();

    /* Getting user input */
    println!("\nEnter the number of rows: ");
    io::stdin().read_line(&mut rows).expect("Couldn't read line!");
    println!("Enter the number of columns: ");
    io::stdin().read_line(&mut cols).expect("Couldn't read line!");
    
    /* Shadowing to integers */
    let rows: usize = rows.trim().parse().expect("Please input numbers!");
    let cols: usize = cols.trim().parse().expect("Please input numbers!");

    /* Creating the matrix */
    let mut grid: [[u128; &rows]; &cols];
    
    /* Executing the algorithm described by solution */
    for i in 0..(rows - 1) {
        for j in 0..(cols - 1) {
            if i == 0 || j == 1 {
                grid[i][j] = 1;
            }
            else {
                grid[i][j] = grid[i - 1][j] + grid[i][j - 1];
            }
        }
    }

    /* Printing solution */
    println!("\nThe different paths are: {}", grid[-1][-1]);
}
