use prompted::input;

fn main() {
    let name: String = input!("Enter your name: ");
    println!("Hello, {}!", name);
}