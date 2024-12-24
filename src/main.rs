use prompted::input;

fn main() {
    while let true = true {
        let command: String = input!("> ");

        if let "quit" = command.as_str() {
            break;
        } else if let "help" = command.as_str() {
            println!("Commands: quit, help");
        } else {
            println!("Unknown command: {}", command);
        }
    }
}